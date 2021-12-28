#include <unordered_map>
#include <stdexcept>

using namespace std;


template <typename T, typename K>
class Bimap
{
private:

    unordered_map<T, K> firstmap;

    unordered_map<K, T> secondmap;


public:

    bool add(T, K);

    void remove(T);

    void remove(K);

    T get_corresponding(K);

    K get_corresponding(T);

    bool contains(T);

    bool contains(K);

    int get_size();
};



template <typename T, typename K>
bool Bimap<T, K>::add(T value1, K value2)
{
    if (contains(value1) || contains(value2))
    {
        return false;
    }
    firstmap[value1] = value2;
    secondmap[value2] = value1;
    
    return true;
}



template <typename T, typename K>
void Bimap<T, K>::remove(T value)
{
    if (!contains(value))
    {
        return;
    }
    K corresponding = firstmap[value];

    firstmap.erase(value);
    secondmap.erase(corresponding);
}



template <typename T, typename K>
void Bimap<T, K>::remove(K value)
{
    if (!contains(value))
    {
        return;
    }
    T corresponding = secondmap[value];

    firstmap.erase(corresponding);
    secondmap.erase(value);
}



template <typename T, typename K>
K Bimap<T, K>::get_corresponding(T key)
{
    if (!contains(key))
    {
        throw invalid_argument("Key not existed");   
    }
    return firstmap[key];
}



template <typename T, typename K>
T Bimap<T, K>::get_corresponding(K key)
{
    if (!contains(key))
    {
        throw invalid_argument("Key not existed");
    }
    return secondmap[key];
}




template <typename T, typename K>
bool Bimap<T,K>::contains(T value)
{
    return firstmap.find(value) != firstmap.end();
}



template <typename T, typename K>
bool Bimap<T, K>::contains(K value)
{
    return secondmap.find(value) != secondmap.end();
}



template <typename T, typename K>
int Bimap<T, K>::get_size()
{
    return firstmap.size();
}
