#ifndef VECTOR
#define VECTOR

#include <iostream> 
#include <vector>
using namespace std;

// Declaration for linear_search function
template<typename Item_Type>
int linear_search(const vector<Item_Type>& items, const Item_Type& target, size_t pos_last);

#endif