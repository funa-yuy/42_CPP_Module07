#ifndef ITER_HPP
# define ITER_HPP

// ------------------------------------------------
// include
// ------------------------------------------------

#include <iostream>
#include <string>

// ------------------------------------------------
// class
// ------------------------------------------------


// ------------------------------------------------
// function
// ------------------------------------------------

template <typename T, typename U>
void iter(T* address, size_t len, U func) {
	for (size_t i = 0; i < len; i++)
		func(address[i]);
}

#endif
