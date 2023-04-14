#include <iostream>
#include <cstdio>
using namespace::std;
// using std::cout;
// using std::endl;

int main()
{
    int eger = 42;
    float ing = 3.14;
    char mander = 'c';
    long long int longNumber = 9999999999; // int is optional to specify
    short int y = 65535;
    bool isTrue = false; // talk about truthiness and falsiness...
    void *empty;

    int *int_ptr = &eger;
    if(eger) {
        cout << "eger (" << eger << ") is truthy!" << endl << endl;
        printf("eger (%i), is truthy, ing: %f, mander");
    } else{
        cout << "eger (" << eger << ") is truthy!" << endl << endl;
    }

    cout << "Hello World" << endl;
    cout << "Goodbye" << endl << endl;
    return 0;
}