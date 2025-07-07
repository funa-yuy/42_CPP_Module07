#include"iter.hpp"

void toUpperPrint(char& value) {
	value = static_cast<char>(std::toupper(value));
	std::cout << value << std::endl;
}

void Print(const char& value) {
	std::cout << value << std::endl;
}

int main( void )
{
	char a[] = {'a', 'b', 'c'};
	size_t a_len = 3;

	::iter( a, a_len, toUpperPrint);

	char b[] = {'a', 'b', 'c'};
	size_t b_len = 3;
	::iter( b, b_len, Print);
	return 0;
}
