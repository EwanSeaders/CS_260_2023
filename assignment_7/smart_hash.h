// #pragma once
#include <iostream>
#include <string>
#include <vector>

using std::vector;
using std::cout;
using std::endl;
using std::string;
using std::remove;

class SmartHashtable {
    public:
        SmartHashtable(int initialCapacity=16);
        ~SmartHashtable();
        int add(string newKey);
        string remove(string oldKey);
        string find(string key);
        // may want a search based on index, rather than string...
        int getSize();//returns size
        int getCapacity();// returns capacity
        void print();// prints all elements in the hashtable

    private:
        int size; // actual objects added to hashtable
        int capacity; // maximum possible objects in hashtable without collision in currently allocated memory
        vector<string> *values; // pointer to array of strings, which are my hashtable's values, indexed by some key
        int hash(string key);
        int collisionCount;
};
