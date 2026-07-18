#include<iostream>
#include<string>
#include<vector>
#include"mlib.h"
using namespace std ;



int main()
{
	char x;
	cout << "enter what you want type datatype enter : ";
	cin >> x;
	void* ptr;
	if (x == 'i')
	{
		ptr = new int;
		cout << "enter the integer number : ";
		cin >> *(static_cast<int*>(ptr));
		printf("the number is integer =  %d : ", *(static_cast<int*>(ptr)));
		delete ptr;
	}
	else
	{
		ptr = new float;
		cout << "enter the float number : ";
		cin >> *(static_cast<float*>(ptr));
		printf("the number is float = %.2f : ", *(static_cast<float*>(ptr)));
		delete ptr;
	}
}