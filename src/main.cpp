#include <iostream>

#include "genetic/Chromosome.h"
#include "genetic/Population.h"


using namespace std;



int main() {

	Random::init(0);

	Graph graph(10,0,1000);

	Solution solution(&graph);

	for(unsigned int i=0;i<solution.size();i++) solution[i]=i;

	graph.placeOptimal(&solution);

	std::cout << solution.evaluateCost() << solution;

	Population population(&graph,101);
	population.nextGeneration();


while(true) {
	Solution sol = population.best();
	cout << population.size() << sol << sol.evaluateCost() << endl;
	population.nextGeneration();
	 }


	return 0;
}
