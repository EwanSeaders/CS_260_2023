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


using std::cout;
using std::endl;


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

    cout << "end program" << endl;
}
