Ewan Seaders
Graph project design

this file holds the written out design for the files in the graph project
classes

    edge:
        design:
            the edge class will be made using a struct
            it will store 3 types of data:
                1. source- pointer to the source node
                2. destination- pointer to the destination node
                3. weight- weight of the edge (int)


        tests:
            1. create an edge and show that each of the 3 datapoints stored can be accessed


    GraphNode:
        design:
            the GraphNode class will hold all the functionality of the nodes in our graph
            Storage:
                1. stores a string value as the name of the node
                2. stores a vector of edge pointers
                
            
            functionality:
                1. it will be able to add edges
                2. it will be able to return its name and stored list of edges
                3. it will have functionality to help check for specific edges in the node


        tests:
            1. add edges and print out the list of newly added edges
            2. make sure destructor can properly delete a node

    Graph:
        design:
            1. the graph will be an undirected and
            2. remove function will delete
            3. only non negative values will be allowed for edges
            4. loops will not be checked for
            5. duplicates of edges are not allowed
            6. duplicates of nodes are not allowed
            
            shortest path algorithm (dijktras):
                
                1. specify a start and end node
                2. make vectors with:
                    - vector<GraphNode*> storing all nodes in the graph
                    - veector<int> storing the current cost to reach (all start at 999999999 except start node start at 0)
                    - vector<Graphnode*> storing the pointer to the nodes predecessor
                3. find and begin at start node
                4. visit each neighbor if it is not visited
                    - if the weight of the current node + the edge weight to get to the next node is less than its current value, update the value
                5. search through the list of nodes and find the one with the smallest weight that hasnt been visited
                6. repeat  until destination node is marked visited



            minimum spanning tree algorithm:

            storage
                1. the graph will be stored as a list of GraphNode pointers
                

        tests:
            1. add nodes to the graph
            2. try to add a node with a name that already exists
            3. 

            