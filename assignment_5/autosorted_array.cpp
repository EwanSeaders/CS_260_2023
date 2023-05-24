#include <iostream>

using namespace::std;
// struct array{
//     string data;
// };

class autosortArray {
private:
    int size = 10;
    string my_array[10];
    string* array = my_array;
public:



    void doubleArraySize(){
        size = size * 2;
        string* new_array = new string[size];
        for(int i; i < size; i++) {
            new_array[i] = "";
        }
        for(int i; i < size; i++) {
            new_array[i] = my_array[i];
        }
        // delete[] my_array;
        array = new_array;

    }
    
    void add(string value) {
        if (my_array[size-1] != ""){
            doubleArraySize();
        }
        for(int i = 0; i < size; i++){
            if (array[i] == ""){
                array[i] = value;
                return;
            }
        }
    }

void print() {
        for(int i = 0; i < size; i++) {
            if (array[i] != ""){
                cout << array[i] << ", ";
            }
        }
        cout << endl;
    }

};


int main() {
    autosortArray array_;
    array_.add("hello");
    array_.add("goodbye");
    array_.add("hello");
    array_.add("goodbye");
    array_.add("hello");
    array_.add("goodbye");
    array_.add("hello");
    array_.add("goodbye");
    array_.add("hello");
    array_.add("goodbye");
    array_.print();

    array_.add("hello");
    array_.print();

    array_.add("goodbye");
    array_.print();
    printf("end program");
    return 0;
}