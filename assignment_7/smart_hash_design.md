design:
    the table will implement a more sophisticated hash function that should reduce collision likelihood
    the table will also have collision handling:
        - if the hash value of two items are the same they will be added to a vector stored at that value in the hashtable
        - the table will look up based on hash value then search through the vector
        - the vector will act like a stack,  accessing the top value first folowed by any others inserted previously
        - the hash function will now multiply each character in the word by its position as well

testing:
    add(): O(1)
        - add words with several permutations to analyze collisions
        - add words that collide and add to the stack
        - add words that wont collide
    find(): O(N), but O(1) most of the time
        - search for a word that has no collisions
        - search for a word that is at the top of a stack
        - search for a word that is inside a stack of collisions
        - search for a word that does not exist
    remove(): O(N), but O(1) most of the time
        - remove a word that has no collisions
        - remove a word that is at the top of a stack
        - remove a word that is inside a stack of collisions
        - search for a word that does not exist
