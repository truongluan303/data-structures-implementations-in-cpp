#include <iostream>
#include "stack.cpp"

using namespace std;


int main()
{
	Stack<int> stack;

    for (int i = 0; i < 10; i++)
    {
        stack.push(i);
    }

    while (!stack.is_empty())
    {
        cout << stack.pop() << " ";
    }

    cout << endl << stack.is_empty() << endl;

    stack.push(1);

    cout << stack.is_empty() << endl;
}

