#include <iostream>
#include <array>
using std::cin;
using std::cout;
using std::endl;

#define tab "\t"
#define STL_ARRAY

void main()
{
	setlocale(LC_ALL, "");

#ifdef STL_ARRAY
	throw;
	const int n = 5;
	std::array<int, n> arr;
	for (int i = 0; i < arr.size(); i++)
	{
		arr.at(i) = rand() % 100;
	}
	try
	{
		for (int i = 0; i < arr.size() * 2; i++)
		{
			cout << arr[i] << tab;
		}
		cout << endl;
	}
	catch (const std::exception& e)
	{
		std::cerr << e.what() << endl;
	}
	catch (...)
	{
		std::cout << "Error: Something went wrong " << endl;
	}

	for (int i : arr )
	{
		cout << i << tab;
	}
	cout << endl;
	std::string str;
#endif // STL_ARRAY

}