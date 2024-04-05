#include "iostream"
#include "vector"
#include "iterator"
#include "list"

using namespace std;
// Function to perform linear search recursively
template<typename type>
int linear_search(vector<type>& items, type target, int index){

    if(index >= items.size())
        return -1;

    if(target == items[index])
        return index;
    else
        return linear_search(items,target,index-1);
}
