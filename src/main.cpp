#include <iostream>

#include "genetic/Chromosome.h"
#include "Simulation.h"


using namespace std;



int main() {

	Random::init(0);

	Chromosome::setMutationRate(0.5);
	Population::setSteadyRatio(0.1);
	Population::setNearRatio(0.5);
	Population::setTraffic(false);


	Simulation::init(20,0,100,100);

	Simulation::start();

	return 0;
}
