// autosorted_array.cpp
// this file represents a class that makes an autosorted array
/*this array will be arranged such that it makes a binary tree
    1. index 0 will always be the top value of the tree
    2. from then on the left child of any given element will be calculated by 2i+1 where i is the index in the array
    3. the right child respecitvely will be calculated with 2i+2

tests- 
    add()-
        insert good middle value (50)
        insert at least 1 value greater and 1 less than- print array and manually check they are in the right position
        insert values until it forces the function to double the array size- shouldnt crash and next print out should look bigger
        insert duplicate values and make sure they still sort properly

    search()- 
        search for top value
        search for values in the mid range but greater than top value
        search for values in the mid range but less than top value
        search for greatest available value
        search for least available value
        search for value above greatest value
        search for value below least value

*/
#include <iostream>

using namespace::std;

class autosortArray {
private:
    int size = 8;
    int* array = new int[size];

    void clean_array(int array[]){// sets array default values to -1 // O(N)
        for(int i=0; i < size; i++){
            array[i] = -1;
        }
    }

    void doubleArraySize(){// doubles the size of the array // O(N)
        
        size = size * 2;
        int* new_array = new int[size];
        clean_array(new_array);
        for(int i=0; i < size/2; i++) {
            new_array[i] = array[i];
        }
        delete[] *&array;
        array = new_array;
    }

public:
   
    autosortArray() {// constructor method
        clean_array(array);
    }
    
    ~autosortArray() {// destructor method
        delete[] array;
    }

    void add(int value) {// adds value to the array as a binary search tree// O(log(N) or O(N) if array is too small
        int i = 0;
        while(array[i] != -1) {
            if (value <= array[i]){i = 2*i + 1;}
            else {i = 2*i + 2;}
            if (i >= size) {// Check if the index is within array bounds
                doubleArraySize();// O(2N) or O(N)
            }
        }
        array[i] = value;
    }

    bool search(int value, int i=0){// searches for values // O(logN)
        if (i >= size) {return false;}// if index is out of bounds
        if (value == array[i]){return true;}// if value is found return true
        if (value <= array[i] && (array[2*i + 1] != -1) && (2*i + 1 <= size)){return search(value, 2*i + 1);}// if the value is <= value at index
        if (value > array[i] && (array[2*i + 2] != -1) && (2*i + 2 <= size)){return search(value, 2*i + 2);}// if the value is > value at index
        if ((array[2*i + 1] == -1) && (array[2*i + 2] == -1)) {return false;}// if both children are null (-1) return false
        return false;
    }

    void print() {// prints out all elements in the array
        for(int i = 0; i < size; i++) {
            cout << array[i] << ", ";
            // if (array[i] != -1){
            //     cout << array[i] << ", ";
            // }
        }
        cout << endl;
    }

};


int main() {
    autosortArray array_;
    // code uses -1 which could be a valid input but works as long as you know you arent entering -1
    
    // add values to the array and makes sure double array function works 
    array_.add(50);
    array_.add(40);
    array_.add(60);
    array_.print();
    cout << endl;

    array_.add(30);
    array_.add(70);
    array_.add(100);
    array_.add(65);
    array_.add(10);
    array_.add(0);
    array_.add(11);
    array_.add(200);
    
    // adds duplicates (also for later testing with search)
    array_.add(50);
    array_.add(40);
    array_.add(30);
    array_.add(60);
    array_.add(70);
    array_.add(100);
    array_.add(65);
    array_.add(10);
    array_.add(0);
    array_.add(11);
    array_.add(200);
    array_.add(-20);
    array_.add(-20);

    array_.print();
    cout << "search(50) expected: 1 : " << array_.search(50) << endl;// value at the top of binary tree structure
    cout << "search(100) expected: 1 : " << array_.search(100) << endl;// greatest available value
    cout << "search(-20) expected: 1 : " << array_.search(-20) << endl;// smallest available value
    cout << "search(11) expected: 1 : " << array_.search(11) << endl;// value in middle to the right
    cout << "search(65) expected: 1 : " << array_.search(65) << endl;// value in middle to the left
    cout << "search(300) expected: 0 : " << array_.search(300) << endl;// value larger than in the dataset
    cout << "search(-300) expected: 0 : " << array_.search(-300) << endl;// value smaller than in the dataset
    array_.print();

    printf("end program");
    return 0;
}