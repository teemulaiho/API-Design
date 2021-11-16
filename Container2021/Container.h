#pragma once
#include <algorithm>
#include <stdexcept>
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
	using pointer = value_type*;
	using const_pointer = const pointer;

	// Empty Default Constructor
	Container() = default;

	explicit Container(std::initializer_list<T> l) : 
		_data{ new value_type[l.size()] }, _size{ l.size()} {
				std::ranges::copy(l, begin());
	}

	// Constructor
	explicit Container(size_type size, const value_type& val = {}) :
		_data{ new value_type[size] }, _size{ size } {
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
		delete[] _data;
		_size = other._size;
		_data = new value_type[other._size];
		std::copy(other._data, other._data + other._size, _data);
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

	bool empty() const noexcept {
		return _size == 0;
	}

	void clear() noexcept {
		delete[] _data;
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

	size_type size() const noexcept {
		return _size;	
	}

	pointer data() const noexcept {
		return _data;
	}

	iterator end() const noexcept {
		return _data + _size;
	}

	iterator begin() const noexcept {
		return _data;
	}

	// Destructor
	~Container() noexcept {
		delete[] _data;
	}

private:
	pointer _data = nullptr;
	size_type _size = 0;
};