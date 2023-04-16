Bag of Marbles implementation design


1.  to represent a bag of marbles i will have an array of integers where each integer represents a different marble with color and size attributes.  to retrieve attributes of the marbles I will have a function that takes in the integer representing the marble and outputs a string representing the marbles attributes (color, size, shape)

2.  to add a mable to the bag I will append a user specified number to the array representing the marble.  to do this i will have an integer that keeps track of the additions to and subractions from the array to give the proper index for insertion

3.  to remove a marble and give it a random feel I will use a random number generator to generate a number in the range of defined numbers for marbles and using a for loop, I will remove one of the elemnts with that value

4.  to test this I will use the following tests:

for adding marbles-

- check lenghth of array and last element before and after adding a marble to verify the marble added is represented in the bag
- check what happens when I add a marble beyond the bags capacity

for removing marbles-

- check lenghth of array before and after removing a marble to verify the marble was removed
- check what happens when I try to remove a marble when the bag is empty
