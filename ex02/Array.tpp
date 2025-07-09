#include"Array.hpp"

/*
 * デフォルトコンストラクタ
 */
template<typename T>
Array<T>::Array() : _arr_size(0), _arr(NULL) {}


/*
 * コンストラクタ
 */
template<typename T>
Array<T>::Array(unsigned int n) : _arr_size(n) {
	_arr = new T[n]();
}

/*
 * コピーコンストラクタ
 * コピー元のオブジェクトは既に有効な状態にあるはずなので、例外は投げない
 */
template<typename T>
Array<T>::Array(const Array& copy) : _arr_size(copy._arr_size) {
	if (copy._arr_size >= 0)
		_arr = new T[copy._arr_size]();
	for (size_t i = 0; i < copy._arr_size; i++)
		_arr[i] = copy._arr[i];

}

/*
 * コピー代入演算子 (A copy assignment operator overload.)
 */
template<typename T>
Array<T>& Array<T>::operator=(const Array& copy) {
	if (this != &copy)
	{
		_arr_size = copy._arr_size;
		delete[] _arr;
		if (copy._arr_size >= 0)
			_arr = new T[copy._arr_size]();
		for (size_t i = 0; i < copy._arr_size; i++)
			_arr[i] = copy._arr[i];
	}
	return (*this);
}

/*
 * デストラクタ
 */
template<typename T>
Array<T>::~Array() {
	if (_arr)
		delete[] _arr;
}


// ↑↑↑ Orthodox Canonical Form --------------------------------------

template<typename T>
unsigned int	Array<T>::size() const {
	return (_arr_size);
}

//  添字演算子のオーバーロード ---------------------------------------------
template<typename T>
T& Array<T>::operator[](unsigned int index) const {
	if (index >= _arr_size)
		throw std::out_of_range("Index out of range");
	return (_arr[index]);
}
