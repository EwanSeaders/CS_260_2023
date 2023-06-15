/*graph.cpp
this file includes the implementation of the Graph class

further documentation included in design.md
*/

#include "graph.h"


Graph::Graph() {
    // do nothing for now for now
}

Graph::~Graph(){
    for (auto node : nodes){
        delete node;
    }
    nodes.clear();
}

// DijkstraTable* Graph::initTable(string source){// initializes the dijkstrTable for the graph
//     DijkstraTable table;
//     table.nodeList = nodes;
//     table.currWeight[nodes.size()];
//     table.predecessorList[nodes.size()];
//     for (int i=0; i < nodes.size(); i++) {
//         table.currWeight[i] = 9999999999;
//         table.predecessorList[i] = nullptr;
//         if (table.nodeList[i]->getValue() == source) {
//             table.currWeight[i] = 0;
//         }
//     }
//     return &table;
// }

// primary functions
// start----------------------------------------------------------------------------------------

// Add a node using name, returns true if the node is added, false otherwise
bool Graph::addNode(string newName) {
    if (nodeExists(newName)) {return false;}// checks if node name already exists and returns false if duplicate
    // create a node
    GraphNode *newNode = new GraphNode(newName);
    //add to nodes list
    nodes.push_back(newNode);
    return true;
}

// Add an edge using source and destination as names of nodes to connect, returns true if the edge is added, false otherwise
// adds undirected edges
bool Graph::addEdge(string sourceName, string destinationName, int weight) {
    if ((nodeExists(sourceName) && nodeExists(destinationName)) == false) {return false;}// false if a node doesnt exist
    if (edgeExists(sourceName, destinationName)) {return false;}// false if edge is a duplicate
    // find and create pointers to source and destination
    GraphNode *source = findNodeHelper(sourceName);
    GraphNode *destination = findNodeHelper(destinationName);
    // create a new edge with proper parameters
    source->addEdge(destination, weight);
    destination->addEdge(source, weight);
    return true;
}

// Check if a node exists with the given name, returns true if node exists, false otherwise...
bool Graph::nodeExists(string name) {
    if (findNodeHelper(name) == nullptr) {
        return false;
    }
    return true;
}

// Check if an edge exists with the given name, returns true if edge exists, false otherwise...
bool Graph::edgeExists(string source, string destination) {
    GraphNode* sourceNode = findNodeHelper(source);// finds node
    if (sourceNode == nullptr) {return false;}
    if (travelEdge(sourceNode, destination) == nullptr) {return false;}// travels to the edge with pointers
    return true;
}

// Find a minimum spanning tree and return it in string form
string Graph::minimumSpanningTree() {
    vector<pair<int, edge*>> edges = buildEdgeVector();// build sorted list of edges
    initSets();// initialize the nodes dWeight values
    vector<edge*> spanningTree;
    for (auto edge : edges) {// iterate through edges
        int s = edge.second->source->dWeight;
        int d = edge.second->destination->dWeight;
        if (s != d) {// if nodes are not in the same tree, merge tree
            spanningTree.push_back(edge.second);// add edge to the list of edges in the MST
            if (updateNodeSet(s, d) == true) {break;}//update node sets and break the loop if all nodes have been hit
        }
    }
    string myString = spanToString(spanningTree);//converts the list of edges to a string representing the MST
    resetNodePubs();// resets public variables
    return myString;
}

// Find shortest path from node with name to each other node that can be reached, returns a string with that information
string Graph::shortestPath(string source, string destination) {// shortest path algorithm implementation
    GraphNode *sourceNode = findNodeHelper(source);
    GraphNode *destinationNode = findNodeHelper(destination);
    dijkstrasAlgorithm(sourceNode, destinationNode);// executes dijkstras algorithm
    string path = pathToString(destinationNode);// converts the path made by dijkstras algorithm to a string
    resetNodePubs();// resets the public variables in all nodes
    return path;
}

// end primary functions_________________________________________________________________________



// generic helper functions
// start----------------------------------------------------------------------------------------

// Finds the node with name, return pointer to that node
GraphNode *Graph::findNodeHelper(string name) {
    for (auto node : nodes) {// iterates through the list of nodes
        if (node->getValue() == name) {// checks for equivalence with string input
            return node;
        }
    }
    return nullptr;
}

// Finds the edge with named source and destination, return pointer to that edge
edge *Graph::findEdgeHelper(string source, string destination) {
    if ((nodeExists(source) && nodeExists(destination)) == false) {return nullptr;}// returns null if the node does not exist
    GraphNode *sourceNode = findNodeHelper(source);
    for (auto edge : sourceNode->getNeighbors())// iterates through neighbors list
        if (edge->destination->getValue() == destination) {
            return edge;
        }
    return nullptr;
}

GraphNode* Graph::travelEdge(GraphNode* source, string destination) {// travels from the source to the destination of the edge by walking over the edge
    for (auto edge : source->getNeighbors()) {
        if (edge->destination->getValue() == destination) {// compare the value of the edge destination to destination argument
            return edge->destination;
        }
    }
    return nullptr;
}

int Graph::getNodeIndex(string value) {// returns the index of a node in the graph based on the name of a node
    for (int i=0; i < nodes.size(); i++) {
        if (nodes[i]->getValue() == value) {return i;}
    }
    return -999999999;
}

vector<GraphNode *> Graph::getNodes(){return nodes;}//returns the node list

void Graph::resetNodePubs() {// resets all nodes public variables
    for (auto node : nodes) {
        node->resetPubs();
    }
}

// end generic helper functions_________________________________________________________________________


// testing/print out functions
// start----------------------------------------------------------------------------------------

void Graph::toString() {// testing function to verify everything is being stored properly
/* Print out all nodes and edges in the form:
    a -> b, c, e
    b -> d, q
    c -> a, b, e, q
    ...
*/
    for (auto node : nodes) {
        cout << node->getValue() << " -> ";
        for (auto edge : node->getNeighbors()) {
            cout << edge->destination->getValue() << ", ";
        }
        cout << endl;
    }
    cout << endl;
}

void Graph::graphPrint() {// prints a string representation of all nodes in the graph
            for (auto node : nodes) {
                cout << node->getValue() << ", ";
            }
            cout << endl;
        }

// end test functions_________________________________________________________________________

// ##########################################################################################################

// private functions
// shortest path specific helper functions
// start----------------------------------------------------------------------------------------

GraphNode* Graph::minWeightNode(){
    int minVal = 999999999;
    for (auto node : nodes) {// iterates throught the list of weights to find min
        if ((node->getDWeight() < minVal) && (node->isVisited() == false)){minVal = node->getDWeight();}
    }
    for (auto node : nodes){// iterates back through to select the minimum node
        if ((minVal == node->getDWeight()) && (node->isVisited() == false)) {return node;}
    }
    return nullptr;
}

string Graph::pathToString(GraphNode *destination) {// converts the shortest path found using shortest path to a string
    GraphNode *current = destination;
    string shortestPath = "" + current->getValue();
    // walks down the graph following the parent pointers and adding the values to the string
    while (current->dParent != nullptr) {
        shortestPath = current->dParent->getValue() + ", " + shortestPath;
        current = current->dParent;
    }
    return shortestPath;
}

void Graph::dijkstrasAlgorithm(GraphNode *sourceNode, GraphNode *destinationNode) {
    sourceNode->dWeight = 0;
    GraphNode *currentNode = sourceNode;
    // main while loop to execute algorithm
    while (destinationNode->isVisited() == false) {
        currentNode->visited = true;
        for (auto edge : currentNode->getNeighbors()) {// iterates through the nodes neighbors
            if (edge->destination->isVisited()) {continue;}
            if ((edge->weight + currentNode->getDWeight()) < edge->destination->getDWeight()) {// if current weight + edge weight are less than the neighbors total weight
                edge->destination->dWeight = edge->weight + currentNode->getDWeight();// updates the weight
                edge->destination->dParent = currentNode;// updates parent node
            }
        }
        currentNode = minWeightNode();// changes current node to the next lowest visited node
    }
}

// end shortest path functions_________________________________________________________________________

// minimum spanning tree specific functions
// start----------------------------------------------------------------------------------------

vector<pair<int, edge*>> Graph::buildEdgeVector() {// builds a vector of edges sorted by weight
    vector<pair<int, edge*>> edges;// chose a pair so it would sort properly
    for (auto node : nodes) {// iterates through nodes list
        for (auto edge : node->getNeighbors()) {// iterates through
            edge->source->visited = true;
            if (edge->destination->isVisited()) {continue;}// skips edges that are duplicates because of undirected graph
            edges.push_back(pair(edge->weight, edge));// adds alements to the list
        }
        sort(edges.begin(), edges.end());// sorts edges by weight
    }
    // resetNodePubs();// resets the public variables
    return edges;
}

void Graph::printEdges(vector<pair<int, edge*>> edges){
    for (auto edge : edges) {
        cout << "(" <<edge.first << ", "<< edge.second << "), ";
    }
    cout << endl;
}

void Graph::initSets() {
    int i = 1;
    for (auto node : nodes) {// sets the values of the nodes in ascending order
        node->dWeight = i;
        i += 1;
    }
}

bool Graph::updateNodeSet(int source, int destination){// updates dweight in min spanning tree to the lowest value between all connected nodes
    int resetValue = min(source, destination);// chooses min value to set as the new name of the graphs subtree
    int oldValue = max(source, destination);
    int nodeCount = 0;
    for (auto node : nodes) {// loop updates the nodes in the graph to reflect change
        if (node->dWeight == oldValue) {node->dWeight = resetValue;}// sets to the new value
        if (node->dWeight == resetValue) {nodeCount += 1;}// update count
    }
        if (nodeCount == nodes.size()) {return true;}// return true if all nodes are in one set
        return false;
}

string Graph::spanToString(vector<edge*> spanningTree) {// converts a list of edges to a string
    string myString = "";
    for (auto edge : spanningTree) {// formulates the string
        myString += "(" + edge->source->getValue() + " <--> " + edge->destination->getValue() + "), ";
    }
    return myString;
}

// end minimum spanning tree functions_________________________________________________________________________
