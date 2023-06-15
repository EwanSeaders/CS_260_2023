
#include "smart_hash.h"

SmartHashtable::SmartHashtable(int initialSize) {
    size = 0;
    capacity = initialSize;

    values = new string[capacity];
}

SmartHashtable::~SmartHashtable() {
    for (auto stack : values){
        delete[] stack;
    }
    delete[] &values;
}

int SmartHashtable::hash(string key) {
    int result = 0;
    int count = 1;
    for(auto character : key) {
        result += character*count; // add unicode values together and multply by their position
        count++;
    }

    return result % capacity; // mod capacity so that the index is guaranteed to be in my table!

}

int SmartHashtable::add(string newKey) {
    int result = 0;

    // find index of key, place value at index position in values array
    int index = hash(newKey);

    // should have collision detection and handling... and update size appropriately
    if(values[index] == "" && newKey != "") {
        size++;
    } else { // either collision or inserting a newKey of ""
        result = -1;
    }

    // then write to correct position (current collision handling technique: overwrite old value...)
    values[index]->push_back(newKey);

    return result; // maybe a different return value on collision?
}

// Calculate index from key, find and return that index from values array if it matches the proposed key, return an empty string otherwise.
string SmartHashtable::find(string key) {
    string result = "";

    // find index of key
    int index = hash(key);
    
    // grab value stored at index in values array
    result = values[index];

    // check if value is the expected value!
    if(result != key) {
        result = "";
    }

    // return resulting value
    return result;
}

string SmartHashtable::remove(string oldKey) {
    string result = "";
    //calculate index with hash
    int index = hash(oldKey);

    // get value from index of array
    result = values[index];

    // check if value is the expected value!
    if(result != oldKey) {
        result = "";
    } else {
        values[index] = ""; // actually delete the value!
        size--;
    }

    // return that value
    return result;
}

void SmartHashtable::print() {
    for(int i=0; i < capacity;i++) {
        for (int n = values[i].size())
        cout << values[i] << ", ";
    }
    cout << endl;
}

int SmartHashtable::getSize() { return size; }
int SmartHashtable::getCapacity() { return capacity; }