#include <iostream>

#include "genetic/Chromosome.h"
#include "genetic/Population.h"


using namespace std;



int main() {

	Random::init(0);

	Graph graph(20,0,100);

	Population population(&graph,1000);
	population.nextGeneration();


while(true) {
	Solution sol = population.best();
	cout << population.size() << sol << sol.evaluateCost() << endl;
	population.nextGeneration();
	 }


	return 0;
}
