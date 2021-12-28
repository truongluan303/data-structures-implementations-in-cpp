#include <iostream>
#include <deque>
#include <ctime>
#include <cstdlib>

#include "linked_queue.cpp"


using namespace std;


int main()
{
    const int size = 1000;
    bool pass = true;

    LinkedQueue<int> lq;
    deque<int> standard_q;

    time_t timer;
    time(&timer);
    srand(unsigned(timer));


    for (int i = 0; i < size; i++)
    {
        int rand_num = rand() % 100 + 1;
        standard_q.push_back(rand_num);
        lq.enqueue(rand_num);
    }

    if (lq.get_size() != standard_q.size())
    {
        pass = false;
    }

    for (int i = 0; i < size; i++)
    {
        int num1 = standard_q.front();
        standard_q.pop_front();
        int num2 = lq.dequeue();

        if (num1 != num2)
        {
            pass = false;
        }
    }

    if (lq.is_empty() == false)
    {
        pass = false;
    }


    if (pass)
    {
        cout << endl << "P A S S" << endl << endl;
    }
    else
    {
        cout << endl << "F A I L" << endl << endl;
    }
    
    return 0;
}
