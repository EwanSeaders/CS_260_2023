#include "hashtable.h"

int main() {
    Hashtable myHash(16);
    myHash.add("dereks");
    myHash.add("ewan");
    myHash.add("wane");
    myHash.add("anew");
    myHash.add("nawe");
    myHash.add("a");
    myHash.add("b");
    myHash.add("c");
    myHash.add("d");
    // myHash.add("");
    myHash.add("a");
    myHash.add("fun");
    myHash.add("hello, world");
    myHash.add("peaches");
    myHash.add("q");
    myHash.add("yikes");
    myHash.add("test");
    

    
    myHash.print();

    cout << "end program" << endl;
    

}