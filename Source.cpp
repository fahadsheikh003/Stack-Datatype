#include<iostream>
#include"Stack.h"

using namespace std;

int main()
{
	Stack<int> S;

	for (int i=0; i<10; i++)
		S.push(i+1);

	cout << S.Top() << endl << S.Bottom() << endl;

	Stack<int> S2 = S;

	cout << "Stack #2\n";
	for (int i = 0; i < 10; i++)
		cout << S2.pop() << "  ";

	cout << "\nStack #1\n";
	for (int i = 0; i < 10; i++)
		cout << S.pop() << "  ";
}