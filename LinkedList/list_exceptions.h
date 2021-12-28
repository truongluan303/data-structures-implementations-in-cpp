#include <exception>

using namespace std;


/**
 * An exception that is thrown when someone attempts
 * to removing operations on an empty list
 */
struct EmptyListRemoval: public exception
{
public:
    virtual const char* what() const throw() 
    {
        return "Attempted to remove from an empty list!";
    }
};



/**
 * An exception that is thrown when an index/position
 * if out of the range of a list
 */
struct IndexOutOfRange: public exception
{
public:
    virtual const char* what() const throw()
    {
        return "Index is out of range";
    }
};
