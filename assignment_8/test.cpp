/* test.cpp
Ewan Seaders
this file includes all tests used to ensure the Graph structure functions as intended
the classes tested in this file are:
    1. edge
    2. GraphNode
    3. Graph

further documentation included in design.md
*/

#include <iostream>

#include "graph.h"
// #include "graph_node.h"
#include <algorithm>

using std::cout;
using std::endl;
using std::sort;
using std::set_union;


int main(int argc, char **argv) {
    
    // edge tests
    cout << "edge testing" << endl;
    edge *newEdge = new edge{nullptr, nullptr, 42};
    cout << "newEdge-> source: " << newEdge->source << "\nnewEdge->destination: " << newEdge->destination << "\nnewEdge->weight: " << newEdge->weight<< endl;


    // //create a simple node to test
    cout << "\n\n";
    cout << "GraphNode testing" << endl;
    GraphNode *newNode = new GraphNode("albany");
    cout << "newNode->getValue(): " << newNode->getValue() << "\nnewNode->getNeighbors().size(): " << newNode->getNeighbors().size() << endl;
    
    newNode->addEdge(newNode, 1);
    newNode->addEdge(newNode, 2);
    newNode->addEdge(newNode, 3);
    newNode->addEdge(newNode, 4);
    cout << "newNode->getValue(): " << newNode->getValue() << "\nnewNode->getNeighbors(): " << newNode->getNeighbors().size() << endl;
    newNode->printNeighbors();

    delete newNode;
    // cout << "newNode->getValue(): " << newNode->getValue() << "\nnewNode->getNeighbors(): " << newNode->getNeighbors().size() << endl;
    // newNode->printNeighbors();

    // Graph tests
    cout << "\n\n";
    cout << "Graph testing" << endl;
    Graph myGraph;

    // test addNode
    // add nodes to the graph (unconnected)
    cout << "myGraph.addNode('Corvallis'): " << myGraph.addNode("Corvallis") << endl;
    cout << "myGraph.addNode('Albany'): " << myGraph.addNode("Albany") << endl;
    cout << "myGraph.addNode('Eugene'): " << myGraph.addNode("Eugene") << endl;
    cout << "myGraph.addNode('Lebanon'): " << myGraph.addNode("Lebanon") << endl;
    cout << "myGraph.addNode('Lebanon'): " << myGraph.addNode("Lebanon") << endl << endl;// add a node that already exists

    myGraph.graphPrint(); //print out nodes

    // findNodeHelper tests
    // cout << "findNodeHelper('Albany'): " << myGraph.findNodeHelper("Albany")->getValue() << endl;  // tests findNodeHelper Function
    // cout << "findNodeHelper('Albany'): " << myGraph.findNodeHelper("Alb") << endl;  // tests findNodeHelper Function if input is not found

    
    // addEdge tests
    cout << "addEdge('Corvallis', 'Albany', 4): " << myGraph.addEdge("Corvallis", "Albany", 4) << endl;// adds a new edge
    cout << "addEdge('Corvallis', 'Albany', 4): " << myGraph.addEdge("Corvallis", "Albany", 4) << endl;// attempts to add an edge that already exists
    cout << "addEdge('Corvallis', 'Sweethome', 4): " << myGraph.addEdge("Corvallis", "Sweethome", 4) << endl;// attempts to add an edge to a node that doesn't exist
    cout << "addEdge('newport', 'sweethome', 4): " << myGraph.addEdge("newport", "sweethome", 4) << endl;// attempts to add an edge where neither node exists
    cout << "addEdge('Corvallis', 'Eugene', -4): " << myGraph.addEdge("Corvallis", "Eugene", -4) << endl;// attempts to add a negative weight edge
    cout << "addEdge('Eugene', 'Lebanon', 4): " << myGraph.addEdge("Eugene", "Lebanon", 4) << endl << endl;

    // findEdgeHelper tests
    cout << "findEdgeHelper('Eugene', 'Lebanon') source: " << myGraph.findEdgeHelper("Eugene", "Lebanon")->source->getValue()// test for find edge helper
         <<  " destination: " << myGraph.findEdgeHelper("Eugene", "Lebanon")->destination->getValue() <<  endl;
    
    cout << "findEdgeHelper('Eugene', 'Lebanon') source: " << myGraph.findEdgeHelper("Lebanon", "Eugene")->source->getValue()// test for the reverse order edge that should exist 
         <<  " destination: " << myGraph.findEdgeHelper("Lebanon", "Eugene")->destination->getValue() <<  endl;
    
    cout << "findEdgeHelper('Eug', 'Leban') source: " << myGraph.findEdgeHelper("Eug", "Leban")// tests outcome of edge not existing
         <<  " destination: " << myGraph.findEdgeHelper("Eug", "Leban") <<  endl << endl;

    // prints out all nodes and their edges to check everything is working
    myGraph.toString();
    
    // nodeExists tests
    cout << "myGraph.nodeExists('Albany'): " << myGraph.nodeExists("Albany") << endl;// expected true
    cout << "myGraph.nodeExists('Canby'): " << myGraph.nodeExists("Canby") << endl;// expected false
    
    // edgeExists tests
    cout << "myGraph.edgeExists('Albany', 'Corvallis'): " << myGraph.edgeExists("Albany", "Corvallis") << endl;// expected true
    cout << "myGraph.edgeExists('Canby', 'Corvallis'): " << myGraph.edgeExists("Canby", "Corvallis") << endl;// expected false due to source node not existing
    cout << "myGraph.edgeExists('Corvallis', 'Canby'): " << myGraph.edgeExists("Corvallis", "Canby") << endl;// expected false due to destination node not existing
    cout << "myGraph.edgeExists('Corvallis', 'Lebanon'): " << myGraph.edgeExists("Corvallis", "Lebanon") << endl;// expected false due to edge not existing

    // travelEdge tests
    cout << "source: " << myGraph.findNodeHelper("Corvallis")->getValue() << "  " << "myGraph.travelEdge(myGraph.findNodeHelper('Corvallis'), 'Albany')->getValue(): " 
        << myGraph.travelEdge(myGraph.findNodeHelper("Corvallis"), "Albany")->getValue() << endl;// expected: Albany

    cout << "source: " << myGraph.findNodeHelper("Corvallis")->getValue() << "  " << "myGraph.travelEdge(myGraph.findNodeHelper('Corvallis'), 'Lebanon'): " 
        << myGraph.travelEdge(myGraph.findNodeHelper("Corvallis"), "Lebanon") << endl;// expected: 0



    // shortest path algorithm testing
    Graph dijkstraTestGraph;
    // add nodes to the graph
    dijkstraTestGraph.addNode("a");
    dijkstraTestGraph.addNode("b");
    dijkstraTestGraph.addNode("c");
    dijkstraTestGraph.addNode("d");
    dijkstraTestGraph.addNode("e");
    dijkstraTestGraph.addNode("f");

    dijkstraTestGraph.addEdge("a", "b", 1);
    dijkstraTestGraph.addEdge("a", "c", 3);
    dijkstraTestGraph.addEdge("b", "d", 3);
    dijkstraTestGraph.addEdge("b", "c", 5);
    dijkstraTestGraph.addEdge("c", "d", 7);
    dijkstraTestGraph.addEdge("c", "e", 5);
    dijkstraTestGraph.addEdge("d", "f", 12);
    dijkstraTestGraph.addEdge("e", "f", 1);
    dijkstraTestGraph.toString();
    
    cout << "shortestPath('a','f'): " << dijkstraTestGraph.shortestPath("a","f") << endl;// path with multiple path options
    cout << "shortestPath('a','b'): " << dijkstraTestGraph.shortestPath("a","b") << endl;
    cout << "shortestPath('a','d'): " << dijkstraTestGraph.shortestPath("a","d") << endl;
    cout << "shortestPath('f','b'): " << dijkstraTestGraph.shortestPath("f","b") << endl;// path with different start node
    cout << "shortestPath('a','d'): " << dijkstraTestGraph.shortestPath("a","d") << endl;
    cout << "shortestPath('a','a'): " << dijkstraTestGraph.shortestPath("a","a") << endl;// returns the shortest path to start node


    Graph MSTgraph;
// minimum spanning tree test graph
// visual available in github repository
    MSTgraph.addNode("a");
    MSTgraph.addNode("b");
    MSTgraph.addNode("c");
    MSTgraph.addNode("d");
    MSTgraph.addNode("e");
    MSTgraph.addNode("f");
    MSTgraph.addNode("g");
    MSTgraph.addNode("h");
    MSTgraph.addNode("i");
    MSTgraph.addNode("j");// j and k not connected to the rest of the graph but have a node between them
    MSTgraph.addNode("k");

    MSTgraph.addEdge("a", "b", 4);
    MSTgraph.addEdge("a", "h", 8);
    MSTgraph.addEdge("b", "c", 8);
    MSTgraph.addEdge("b", "h", 11);
    MSTgraph.addEdge("c", "d", 7);
    MSTgraph.addEdge("c", "f", 4);
    MSTgraph.addEdge("c", "i", 2);
    MSTgraph.addEdge("d", "e", 9);
    MSTgraph.addEdge("d", "f", 14);
    MSTgraph.addEdge("e", "f", 10);
    MSTgraph.addEdge("f", "g", 2);
    MSTgraph.addEdge("g", "h", 1);
    MSTgraph.addEdge("g", "i", 6);
    MSTgraph.addEdge("h", "i", 7);
    MSTgraph.addEdge("j", "k", 177);// add edge between the 2 disconncted nodes
    MSTgraph.toString();// check the graph is coming out properly
    

    
    // dijkstraTestGraph.printEdges(dijkstraTestGraph.buildEdgeVector());// verifies the list of edges is full ordered properly

    cout << "dijkstraTestGraph Minimum Spanning Tree\n" << dijkstraTestGraph.minimumSpanningTree() << endl << endl;// test on connected graph
    cout << "MSTgraph Minimum Spanning Tree\n" << MSTgraph.minimumSpanningTree() << endl << endl;// test on disconnected graph

    cout << "MSTgraph.shortestPath('a','f'): " << MSTgraph.shortestPath("a","f") << endl;// path with multiple path options
    cout << "MSTgraph.shortestPath('a','b'): " << MSTgraph.shortestPath("a","b") << endl;
    cout << "MSTgraph.shortestPath('a','d'): " << MSTgraph.shortestPath("a","d") << endl;
    cout << "MSTgraph.shortestPath('a','e'): " << MSTgraph.shortestPath("a","e") << endl;
    cout << "MSTgraph.shortestPath('a','j'): " << MSTgraph.shortestPath("a","j") << endl;


    cout << "end program" << endl;
}
