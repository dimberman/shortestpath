all:
	g++ main.cpp AdjacencyList.cpp Algorithm1.cpp Node.cpp PathNode.cpp -g -o main
clean:
	/bin/rm -f *.o main *~
