// #include "hashtable.h"

#include <iostream>
#include <string>

using std::cout;
using std::endl;
using std::string;

class Hashtable {
    public:
        Hashtable(int initialSize) {
            size = 0;
            capacity = initialSize;

            values = new string[capacity];
        }

        ~Hashtable() {
            delete[] values;
        }

        

        int add(string newKey) {
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
            values[index] = newKey;

            return result; // maybe a different return value on collision?
        }

        // Calculate index from key, find and return that index from values array if it matches the proposed key, return an empty string otherwise.
        string find(string key) {
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

        string remove(string oldKey) {
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

        void print() {
            for(int i=0; i < capacity;i++) {
                cout << values[i] << ", ";
            }
            cout << endl;
        }

        int getSize() { return size; }
        int getCapacity() { return capacity; }
    private:
        int size; // actual objects added to hashtable
        int capacity; // maximum possible objects in hashtable with currently allocated memory
        string *values; // pointer to array of strings, which are my hashtable's values, indexed by some key
        
        int hash(string key) {
            int result = 0;

            for(auto character : key) {
                result += character; // add unicode values together!
            }

            return result % capacity; // mod capacity so that the index is guaranteed to be in my table!

        }
};








int main() {
    Hashtable myHash(16);
    myHash.add("dereks");
    myHash.add("ewan");
    myHash.add("wane");
    myHash.add("anew");
    myHash.add("nawe");

    myHash.print();

    cout << "end program" << endl;
}