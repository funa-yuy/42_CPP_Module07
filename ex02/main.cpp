#include <iostream>
#include <stdlib.h>
#include "Array.hpp"

// ``bash
// valgrind ./Array
// ```

#define MAX_VAL 750
int main(int, char**)
{
	Array<int> numbers(MAX_VAL);//自作: int型で要素数が　MAX_VALの配列を生成
	int* mirror = new int[MAX_VAL];//比較用のミラー配列
	srand(time(NULL));
	for (int i = 0; i < MAX_VAL; i++)
	{
		const int value = rand();//現在時刻を格納
		numbers[i] = value;// 自作: Array::operator[] による書き込み
		mirror[i] = value;// ミラー: 素の配列への書き込み
	}

	/* 浅いコピーの場合、デストラクタ内のdeleatにより、ダブルフリーになる */
	{
		Array<int> tmp = numbers;// 自作: コピーコンストラクタ
		Array<int> test(tmp);// 自作: コピーコンストラクタ
	}

	/* 一個上のSCOPE内で、numbersオブジェクトまでdeleatされてないか確認 */
	for (int i = 0; i < MAX_VAL; i++)
	{
		if (mirror[i] != numbers[i])
		{
			std::cerr << "didn't save the same value!!" << std::endl;
			return 1;
		}
	}

	/* 範囲外アクセス: 例外が投げられるはず */
	try
	{
		numbers[-2] = 0;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}

	/* 範囲外アクセス: 例外が投げられるはず */
	try
	{
		numbers[MAX_VAL] = 0;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}

	/* 範囲外アクセスで例外を投げても、オブジェクトが壊れていなかいかチェック */
	for (int i = 0; i < MAX_VAL; i++)
	{
		numbers[i] = rand();
	}
	delete [] mirror;
	return 0;
}
