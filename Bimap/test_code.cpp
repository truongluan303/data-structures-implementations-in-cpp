#include <iostream>

#include "bimap.cpp"


using namespace std;


int main()
{
    Bimap<char, int> bimap;

    bimap.add('a', 1);
    bimap.add('b', 2);
    bimap.add('c', 3);
    bimap.add('d', 4);
    bimap.add('e', 5);

    bool passed = true;

    if (bimap.get_corresponding('a') != 1 || bimap.get_corresponding(3) != 'c')
    {
        passed = false;
    }

    bimap.remove(2);
    bimap.remove('e');
    bimap.remove('d');

    if (bimap.contains(2) || bimap.contains(4) || bimap.contains('e'))
    {
        passed = false;
    }
    if (!bimap.contains('a') || !bimap.contains(3))
    {
        passed = false;
    }

    if (passed)
    {
        cout << "P A S S";
    }
    else
    {
        cout << "F A L S E";
    }
    cout << endl;

    return 0;
}
