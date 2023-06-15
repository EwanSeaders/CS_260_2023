#include <iostream>
#include "smart_hash.h"

int main(){
    SmartHashtable testHash(16);
    
    testHash.add("dereks");// at the bottom of a longer stack
    testHash.add("ewan");// permutations of ewan
    testHash.add("wane");
    testHash.add("anew");
    testHash.add("nawe");
    testHash.add("a");
    testHash.add("b");
    testHash.add("c");// stand alone value
    testHash.add("d");
    // testHash.add("");
    testHash.add("a");
    testHash.add("a");
    testHash.add("fun");
    testHash.add("hello, world");
    testHash.add("peaches");
    testHash.add("q");// at the top of a longer stack
    testHash.add("yikes");
    testHash.add("test");
    testHash.print();

    // find tests
    cout << testHash.find("c") << endl;// stand alone value
    cout << testHash.find("q") << endl;// at the top of a longer stack
    cout << testHash.find("dereks") << endl;// at the bottom of a longer stack
    cout << testHash.find("jeremy") << endl;// value that does not exist

    cout << testHash.remove("ewan") << endl;
    testHash.print();
    cout << testHash.remove("dereks") << endl;// at the bottom of a longer stack
    testHash.print();
    cout << testHash.remove("q") << endl;// at the top of a longer stack
    testHash.print();
    cout << testHash.remove("c") << endl;// stand alone value
    testHash.print();
    cout << testHash.remove("wane") << endl;
    cout << testHash.remove("anew") << endl;
    cout << testHash.remove("nawe") << endl;
    cout << testHash.remove("a") << endl;
    cout << testHash.remove("b") << endl;
    cout << testHash.remove("d") << endl;
    cout << testHash.remove("a") << endl;
    cout << testHash.remove("a") << endl;
    cout << testHash.remove("fun") << endl;
    cout << testHash.remove("hello, world") << endl;
    cout << testHash.remove("peaches") << endl;
    cout << testHash.remove("yikes") << endl;
    cout << testHash.remove("test") << endl;//remove last word in the hashtable
    cout << testHash.remove("jeremy") << endl;// remove a word that doesnt exist
    
    testHash.print();

    

    cout << "end program";
    return 0;
}



