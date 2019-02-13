#include <iostream>

#include "genetic/Chromosome.h"
#include "genetic/Population.h"


using namespace std;



int main() {

	Random::init(time(nullptr));

	Graph graph(20,0,100);

	Population population(&graph,1000);

	Solution sol = population.best();

	cout << sol << sol.evaluateCost();


	return 0;
}