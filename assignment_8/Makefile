CC = g++
exe_file = run

$(exe_file): driver.cpp graph.o graph_node.o
	$(CC) driver.cpp graph.o graph_node.o -o $(exe_file)

graph.o: graph.cpp graph.h
	$(CC) -c graph.cpp

graph_node.o: graph_node.cpp graph_node.h edge.h
	$(CC) -c graph_node.cpp

clean:
	rm -f *.o $(exe_file)

# g++ driver.cpp graph.h graph.cpp graph_node.h edge.h graph_node.cpp -o driver

# compile path
# g++ test.cpp graph.cpp graph_node.cpp -o test