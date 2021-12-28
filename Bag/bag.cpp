#include <unordered_map>

using namespace std;



template <typename T>
class Bag
{
private:
    
    int size;                   // total items in the bag
    unordered_map<T, int> map;  // map the value with the number of occurences

public:

    Bag();

    bool add(T val);

    bool add(T val, int occurences);

    bool remove(T val);

    bool remove(T val, int occurences);

    bool remove_all(T val);

    int count(T val);

    int get_size();

    bool is_empty();
};




template <typename T>
Bag<T>::Bag()
{
    size = 0;
}




/**
 * Add an element to the bag
 * @param val the value of the new element
 * @return whether the same element was already in the bag
 */
template <typename T>
bool Bag<T>::add(T val)
{
    bool result;

    if (map.find(val) == map.end())
    {
        map[val] = 1;
        result = true;
    }
    else
    {
        map[val]++;
        result = false;
    }
    size++;
    return result;
}




/**
 * Add the given number of occurences to the bag
 * @param val the value of the new elements
 * @param occurences the number of new elements to be added
 * @return whether the same element was already in the bag
 */
template <typename T>
bool Bag<T>::add(T val, int occurences)
{
    bool result;

    if (map.find(val) == map.end())
    {
        map[val] = occurences;
        result = true;
    }
    else
    {
        map[val] += occurences;
        result = false;
    }
    size += occurences;
    return result;
}




/**
 * Remove an element from the bag
 * @param val the value of the element to be removed
 * @return whether this call changed the bag
 */
template <typename T>
bool Bag<T>::remove(T val)
{
    if (map.find(val) == map.end() || map[val] == 0)
    {
        return false;
    }

    map[val]--;

    size--;

    return true;
}




/**
 * Remove the given number of occurences from the bag
 * @param val the value of the elements to be removed
 * @param occurences the number of elements to be removed
 * @return whether this call changed the bag
 */
template <typename T>
bool Bag<T>::remove(T val, int occurences)
{
    if (map.find(val) == map.end() || map[val] == 0)
    {
        return false;
    }
    
    map[val] -= occurences;

    if (map[val] < 0)
    {
        map[val] = 0;
    }

    size -= occurences;

    return true;
}




/**
 * Remove all elements with the given value from the bag
 * @param val the value of the elements to be removed
 * @return whether the call changed the bag
 */
template <typename T>
bool Bag<T>::remove_all(T val)
{
    if (map.find(val) == map.end() || map[val] == 0)
    {
        return false;
    }
        
    size -= map[val];
    map[val] = 0;

    return true;
}




/**
 * Get the number of occurences of the elements with the given value
 * @param val the value of the elements to be counted
 * @return the occurences of the elements with the given value
 */
template <typename T>
int Bag<T>::count(T val)
{
    if (map.find(val) == map.end())
    {
        return 0;
    }
    return map[val];
}




/**
 * Get the total size of the bag
 * @return the number of all elements in the bag
 */
template <typename T>
int Bag<T>::get_size()
{
    return size;
}




/**
 * Check if the bag is empty
 * @return whether the size of the bag is 0
 */
template <typename T>
bool Bag<T>::is_empty()
{
    return size == 0;
}
