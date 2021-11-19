#pragma once
#include <algorithm>
#include <stdexcept>
#include <memory>
#include <numeric>

template<typename T>
class Container {
public:
	using value_type = T;
	using size_type = std::size_t;
	using iterator = value_type*;
	using const_iterator = const iterator*;
	using reference = value_type&;
	using const_reference = const value_type&;
	//using pointer = std::unique_ptr<T[]>;
	using pointer = value_type*;
	using const_pointer = const pointer;

	// Empty Default Constructor
	Container() = default;

	explicit Container(std::initializer_list<value_type> list) :
		_data{ std::make_unique<value_type[]>(list.size()) }, _size{list.size()}{
		std::ranges::copy(list, begin());
	}

	// Constructor
	explicit Container(size_type size, const value_type& val = {}) :
		_data{ std::make_unique<value_type[]>(size) }, _size{ size } {
		std::fill(begin(), end(), val);
	}

	// Copy Constructor
	Container(const Container& other) : Container(other.size()) {
		std::copy(other.begin(), other.end(), begin());
	}

	// Move Constructor
	Container(Container&& other) noexcept {
		using std::swap;
		swap(_data, other._data);
		swap(_size, other._size);
	}

	// Copy Assignment Operator
	Container& operator=(const Container& other) {
		auto temp = std::make_unique<value_type[]>(other.size());
		std::copy(other.begin(), other.end(), temp.get());
		_data.reset(temp.release());
		//TODO: check the semantics of ownership transfer when resetting using a unique_prt as a pointer.
		// also the aissgment operator
		_size = other.size();
		return *this;
	}

	//  Move Assignment Operator
	Container& operator= (Container&& other) noexcept {
		using std::swap;
		swap(_data, other._data);
		swap(_size, other._size);
		return *this;
	}

	// Array At Access Operator
	reference at(size_type index) {
		if (index >= size()) {
			throw std::runtime_error("Container::at() index out of bounds!");
		}
		return _data[index];
	}

	// Array Access Operator
	reference operator[](size_type index) noexcept {
		assert(index < size() && "operator[] index out of bounds!");
		return _data[index];
	}

	constexpr bool empty() const noexcept {
		return _size == 0;
	}

	constexpr void clear() noexcept {
		_data.reset(nullptr);
		_size = 0;
	}

	// Array First Element Access Operator
	constexpr reference front() {
		return _data[0];
	}

	// Array Last Element Access Operator
	constexpr reference back() {
		assert(size() < size() && "operator[] index out of bounds!");
		return _data[_size - 1];
	}

	constexpr size_type size() const noexcept {
		return _size;	
	}

	constexpr pointer data() const noexcept {
		return _data;
	}

	constexpr iterator begin() const noexcept {
		return _data.get();
	}

	constexpr iterator end() const noexcept {
		[[gsl::suppress(bounds.1, justification:"Container is a spawn.")]]
		return _data.get() + _size;
	}

private:
	std::unique_ptr<value_type[]> _data = nullptr;
	size_type _size = 0;
};