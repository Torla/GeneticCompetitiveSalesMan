#include <iostream>

#include "graphs/Graph.h"
#include "graphs/Path.h"
#include "solution/Solution.h"

using namespace std;

int main() {
	std::cout << "Hello, World!" << std::endl;

	Graph graph(20,0,100);

	Solution solution(&graph);

	cout << solution ;

	return 0;
}