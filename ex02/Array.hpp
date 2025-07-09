#ifndef ARRAY_HPP
# define ARRAY_HPP

// ------------------------------------------------
// include
// ------------------------------------------------

#include <iostream>
#include <string>

// ------------------------------------------------
// class
// ------------------------------------------------

template <typename T> class Array {
	public:
		Array();
		Array(unsigned int n);
		Array& operator=(const Array& copy);
		Array(const Array& copy);
		~Array();

		unsigned int	size() const;
		T& operator[](unsigned int index) const;

	private:
		unsigned int	_arr_size;
		T	*_arr;
};

#include"Array.tpp"

// ------------------------------------------------
// function
// ------------------------------------------------

#endif
