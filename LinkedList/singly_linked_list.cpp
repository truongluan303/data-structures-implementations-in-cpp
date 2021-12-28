#include "list_exceptions.h"


using namespace std;



template <typename T>
class SinglyLinkedList
{
private:

    struct Node
    {
    private:
        T val;
        Node* next;
    
    public:

        Node(T val)
        {
            this->val = val;
            this->next = NULL;
        }

        Node* get_next() { return this->next; }

        T get_val() { return this->val; }

        void set_next(Node* next) { this->next = next; }

        void set_val(T val) { this->val = val; }
    };


    int size;

    Node* head;

    Node* tail;


public:


    /**
     * Constructor
     */
    SinglyLinkedList()
    {
        size = 0;
        head = NULL;
        tail = NULL;
    }




    /**
     * Destructor
     */
    ~SinglyLinkedList()
    {
        Node* current = head;

        while (current != NULL)
        {
            Node* next = current->get_next();   // save the next node
            delete current;                     // delete current node
            current = next;                     // move on to next node
        }
    }




    /**
     * Add a new value at the beginning of the list
     * @param val the value to be added
     */
    void prepend(T val)
    {
        Node* new_node = new Node(val);

        if (is_empty())
        {
            head = new_node;
            tail = new_node;
        }
        else 
        {
            new_node->set_next(head);   // new node will point to head

            head = new_node;            // head is now the new node
        }
        size++;
    }




    /**
     * Add a new value at the end of the list
     * @param val the new value to be added
     */
    void append(T val)
    {
        Node* new_node = new Node(val);

        if (is_empty())
        {
            head = new_node;
            tail = new_node;
        }
        else 
        {
            tail->set_next(new_node);   // let tail points to new node

            tail = tail->get_next();    // new node is now the tail
        }
        size++;
    }





    /**
     * Add a new value at a position in the list
     * @param val the new value to be added
     * @param position the position where the new value is added
     */
    void insert_at(T val, int position)
    {
        if (position < 1 || position > (size + 1))
        {   
            IndexOutOfRange e;
            throw e;
        }
        if (position == 1)
        {
            prepend(val);
        }
        else if (position == (size + 1))
        {
            append(val);
        }
        else
        {
            Node* current = head;

            Node* new_node = new Node(val);

            // iterate to the node before the position we want to insert
            for (int i = 1; i < position - 1; i++)
            {
                current = current->get_next();
            }
            // insert the new node after the current node
            // create a temporary node to point to current->next
            Node* temp = current->get_next();

            current->set_next(new_node);

            new_node->set_next(temp);

            size++;
        }
    }





    /**
     * Get the value of the node at a postion
     * @param position the position to get the value from
     * @return the value at the position
     */
    T get(int position)
    {
        if (position < 1 || position > size)
        {
            IndexOutOfRange e;
            throw e;
        }
        if (position == 1)
        {
            return head->get_val();
        }
        if (position == size)
        {
            return tail->get_val();
        }
        Node* current = head->get_next();

        // loop to the node at the position
        for (int i = 2; i < position; i++)
        {
            current = current->get_next();
        }
        return current->get_val();
    }





    /**
     * remove the node at a position
     * @param position the position of the node to be removed
     * @return the value of the removed node
     */ 
    T remove_at(int position)
    {
        if (is_empty())
        {
            EmptyListRemoval e;
            throw e;

        }
        if (position < 1 || position > size)
        {
            IndexOutOfRange e;
            throw e;
        }

        T temp;
        Node* to_be_removed;

        if (position == 1)
        {
            to_be_removed = head;
            temp = head->get_val();
            head = head->get_next();
        }
        else
        {   
            Node* current = head->get_next();
            // loop to the node before the position
            for (int i = 2; i < position - 1; i++)
            {
                current = current->get_next();
            }
            to_be_removed = current->get_next();
            temp = current->get_next()->get_val();

            current->set_next(current->get_next()->get_next());
        }

        delete to_be_removed;
        size--;

        return temp;
    }





    /**
     * Remove the first occurence of a value
     * @param val the value to be removed
     * @return whether the value is found and removed
     */
    bool remove_value(T val)
    {
        if (is_empty())
        {   
            EmptyListRemoval e;
            throw e;
        }

        bool result;
        Node* to_be_removed;

        if (head->get_val() == val)
        {
            to_be_removed = head;
            head = head->get_next();
            size--;
            result = true;
        }
        else 
        {
            Node* current = head;

            while (current->get_next() != NULL)
            {
                if (current->get_next()->get_val() == val)
                {
                    to_be_removed = current->get_next();

                    current->set_next(current->get_next()->get_next());
                    size--;

                    result = true;
                }
                current = current->get_next();
            }
        }
        delete to_be_removed;
        
        // return false if there's no such value in the list
        return false;
    }




    /**
     * Check if the list contains the given value
     * @return true if the list contains the given value
     */
    bool contains(T value)
    {
        Node* current = head;

        while (current != NULL)
        {
            if (current->get_val() == value)
            {
                return true;
            }
            current = current->get_next();
        }
        return false;
    }




    /**
     * Get an array version of the list
     * @return an array version of the list
     */
    T* to_array()
    {
        T* arr = new T[size];

        Node* current = head;

        for (int i = 0; i < size; i++)
        {
            arr[i] = current->get_val();
            current = current->get_next();
        }
        return arr;
    }





    /**
     * Check if the list is empty
     * @return whether the list is empty
     */
    bool is_empty()
    {
        return size == 0;
    }





    /**
     * Get the size of the list
     * @return number of elements in the list 
     */
    int get_size()
    {
        return size;
    }
};
