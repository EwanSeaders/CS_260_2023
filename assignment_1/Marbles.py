from __future__ import annotations
import random

class BagOfMarbles:
    def __init__(self, bag:list[Marble]=[]) -> None:
        self.bag = bag
        self.marbles = len(self.bag)

    def add_marble(self, marble:Marble):
        self.bag.append(marble)
        self.marbles += 1

    def add_many(self, num:int, marble:Marble):
        for x in range(num):
            self.add_marble(marble)
    
    def remove(self, num:int):
        for x in range(num):
            rand_index = int(random.randrange(0,self.marbles))
            self.bag.remove(self.bag[rand_index])
            self.marbles -= 1

    
    def __str__(self) -> str:
        return f"{self.bag}"
    def __repr__(self) -> str:
        pass

class Marble:
    def __init__(self, size, color) -> None:
        self.size = size
        self.color = color

    def __repr__(self) -> str:
        return f"Marble({self.size},'{self.color}')"

if __name__ == "__main__":
    test = BagOfMarbles()
    print(test)
    test.add_many(3, Marble(7, "blue"))
    test.add_many(2, Marble(7, "red"))
    test.add_many(1, Marble(7, "green"))
    print(test)
    print(test.marbles)
    # print(random.randrange(1,10))
    test.remove(2)
    print(test)
    print(test.marbles)
