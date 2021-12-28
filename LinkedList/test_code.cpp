#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>
#include <algorithm>

#include "singly_linked_list.cpp"


using namespace std;


int main()
{
    SinglyLinkedList<int> llist;
    vector<int> alist;

    for (int i = 0; i < 5000; i++)
    {
        int randnum = rand() % 1000;

        if (i % 5 == 0)
        {
            llist.prepend(randnum);
            alist.insert(alist.begin(), randnum);
        }
        else
        {
            llist.append(randnum);
            alist.push_back(randnum);
        }
    }
    
    for (int i = 0; i < 100; i++)
    {
        int randnum = rand() % 1000 + 1;

        llist.remove_at(randnum);
        alist.erase(alist.begin() + (randnum - 1));
    }

    for (int i = 5; i < 10; i++)
    {
        while (llist.contains(i))
        {
            llist.remove_value(i);
        }
        alist.erase(remove(alist.begin(), alist.end(), i), alist.end());
    }

    bool passed = true;

    if (llist.get_size() != alist.size())
    {
        passed = false;
    }
    for (int i = 0; i < llist.get_size(); i++)
    {
        if (llist.get(i + 1) != alist[i])
        {
            passed = false;
            break;
        }
    }

    if (passed)
    {
        cout << "P A S S";
    }
    else
    {
        cout << "F A I L";
    }
    cout << endl;


    return 0;
}
