#include <exception>
#include <iostream>

using namespace std;



struct EmptyQueueException : public exception
{
    virtual const char* what() const throw()
    {
        return "Attempted to dequeue an empty queue!";
    }
};




template <typename T>
class LinkedQueue
{
private:

    struct Node
    {
        T val;
        Node* next;

        Node(T val)
        {
            this->val = val;
            this->next = NULL;
        }
    };

    
    int size;

    Node* head;

    Node* tail;


public:


    LinkedQueue();

    ~LinkedQueue();

    void enqueue(T val);

    T peek();

    T dequeue();

    int get_size();

    bool is_empty();
};





template <typename T>
LinkedQueue<T>::LinkedQueue()
{
    size = 0;
    head = NULL;
    tail = NULL;
}




template <typename T>
LinkedQueue<T>::~LinkedQueue()
{
    Node* current = head;

    // free all the nodes
    while (current != NULL)
    {
        Node* next = current->next;

        delete current;

        current = next;
    }
}




template <typename T>
void LinkedQueue<T>::enqueue(T val)
{
    Node* new_node = new Node(val);

    if (is_empty())
    {
        head = new_node;    
        tail = new_node;
    }
    else
    {
        tail->next = new_node;
        tail = new_node;
    }
    size++;
}



template <typename T>
T LinkedQueue<T>::peek()
{
    return head->val;
}



template <typename T>
T LinkedQueue<T>::dequeue()
{
    if (is_empty())
    {
        EmptyQueueException e;
        throw e;
    }

    Node* to_be_removed = head;
    T temp = head->val;

    head = head->next;

    size--;
    delete to_be_removed;

    return temp;
}





template <typename T>
int LinkedQueue<T>::get_size()
{
    return size;
}




template <typename T>
bool LinkedQueue<T>::is_empty()
{
    return size == 0;
}
