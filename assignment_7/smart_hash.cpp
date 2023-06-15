
#include "smart_hash.h"

SmartHashtable::SmartHashtable(int initialSize) {
    size = 0;
    capacity = initialSize;
    collisionCount = 0;

    values = new vector<string>[capacity];
    for (int i=0; i < capacity; i++) {
        values[i].push_back("");
    }
}

SmartHashtable::~SmartHashtable() {
    // for (auto stack : values){
    //     delete[] stack;
    // }
    delete values;
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
    // then write to correct position (current collision handling technique: overwrite old value...)
    values[index].push_back(newKey);
    size++;

    return result; // maybe a different return value on collision?
}

// Calculate index from key, find and return that index from values array if it matches the proposed key, return an empty string otherwise.
string SmartHashtable::find(string key) {
    string result = "";

    // find index of key
    int index = hash(key);
    
    // grab value stored at index in values array
    if (values[index].back() == key) {// best case recudes time complexity
        return values[index].back();
    }
    
    for (int i=values[index].size()-1; i >= 0; i = i-1){// loops through vector at index as a stack
        result = values[index][i];
        if (result == key){
            return result;}
    }
    result = "";
    // return resulting value
    return result;
}

string SmartHashtable::remove(string oldKey) {
    string result = "";
    //calculate index with hash
    int index = hash(oldKey);

    // get value from index of array
    
    // grab value stored at index in values array
    if (values[index].back() == oldKey) {// best case
        result = values[index].back();
        values[index].pop_back();
    }
    
    else {
        for (int i=values[index].size()-1; i >= 0; i = i-1){// loops through vector at index as a stack
            result = values[index][i];
            if (values[index][i] == oldKey){
                result = values[index][i];
                values[index][i] = "";
                break;
            }
        }
    }
    return result;
}

void SmartHashtable::print() {
    
    for(int n = 0; n < capacity; n++) {
    // for(auto stack : *values) {
        for (int i=values[n].size()-1; i >= 0; i=i-1){// loops through vector at index as a stack
            cout  << values[n][i] << "-> ";
        }
        cout << endl;
        // cout << values[n].back() << ", ";
    }
    cout << endl;

}



int SmartHashtable::getSize() { return size; }
int SmartHashtable::getCapacity() { return capacity; }