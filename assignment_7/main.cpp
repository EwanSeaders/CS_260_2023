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
    myHash.add("");
    myHash.add("a");
    

    
    myHash.print();

    cout << "end program" << endl;
    

}