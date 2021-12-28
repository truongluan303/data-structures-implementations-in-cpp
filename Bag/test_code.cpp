#include <iostream>

#include "bag.cpp"

using namespace std;


int main()
{
    Bag<int> bag;

    bag.add(1);
    bag.add(1, 20);
    bag.remove(1);
    bag.remove(1, 5);
    bag.add(3, 20);
    bag.add(22, 10);
    

    cout << bag.count(1) << endl;
    cout << bag.count(3) << endl;
    cout << bag.count(22) << endl;


    bag.remove_all(3);

    cout << bag.count(3) << endl;

    return 0;
}
