#pragma once
#include <algorithm>
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

	//  Move Assignment Operator
	Container& operator= (Container&& other) noexcept {
		using std::swap;
		swap(_data, other._data);
		swap(_size, other._size);

		return *this;
	}

	// Copy Assignment Operator
	Container& operator=(const Container& other) {
		delete[] _data;
		_size = other._size;
		_data = new value_type[other._size];
		std::copy(other._data, other._data + other._size, _data);

		return *this;
	}

	iterator end() const noexcept {
		return _data + _size;
	}

	iterator begin() const noexcept {
		return _data;
	}

	value_type* data() const noexcept {
		return _data;
	}

	// Destructor
	~Container() noexcept {
		delete[] _data;
	}

private:
	T* _data = nullptr;
	size_type _size = 0;
};