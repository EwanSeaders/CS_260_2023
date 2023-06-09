// #pragma once
#include <iostream>
#include <string>

using std::cout;
using std::endl;
using std::string;

class Hashtable {
    public:
        Hashtable(int initialCapacity=16);
        ~Hashtable();
        int add(string newKey);
        string remove(string oldKey);
        string find(string key);
        // may want a search based on index, rather than string...
        int getSize();//returns size
        int getCapacity();// returns capacity
        void print();// prints all elements in the hashtable

    private:
        int size; // actual objects added to hashtable
        int capacity; // maximum possible objects in hashtable with currently allocated memory
        string *values; // pointer to array of strings, which are my hashtable's values, indexed by some key
        int hash(string key);
};

