#include"iter.hpp"

void const_print(const char& value) {
	std::cout << value << std::endl;
}

void non_const_ToUpper(char& value) {
	value = static_cast<char>(std::toupper(value));
	std::cout << value << std::endl;
}

int main( void )
{
	const char b[] = {'a', 'b', 'c'};
	size_t b_len = 3;
	::iter( b, b_len, const_print);

	std::cout << std::endl;

	char a[] = {'a', 'b', 'c'};
	size_t a_len = 3;
	::iter( a, a_len, non_const_ToUpper);

	return 0;
}
