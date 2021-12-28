#include <vector>

using namespace std;



template <typename T>
class Stack
{
private:

    vector<T> vec;


public:

    void push(T value);

    T pop();

    T peek();

    int get_size();

    bool is_empty();
};



template <typename T>
void Stack<T>::push(T value)
{
    vec.push_back(value);
}



template <typename T>
T Stack<T>::pop()
{
    T result = vec[vec.size() - 1];
    vec.pop_back();
    return result;
}



template <typename T>
T Stack<T>::peek()
{
    return vec[vec.size() - 1];
}



template <typename T>
int Stack<T>::get_size()
{
    return vec.size();
}



template <typename T>
bool Stack<T>::is_empty()
{
    return vec.size() == 0;
}
