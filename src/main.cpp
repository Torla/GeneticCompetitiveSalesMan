#include <iostream>

#include "genetic/Chromosome.h"
#include "Simulation.h"


using namespace std;



int main() {

	Random::init(0);

	Chromosome::setMutationRate(0.2);
	Population::setSteadyRatio(0.9);
	Population::setNearRatio(0.5);

	Simulation::init(50,0,100,100);

	Simulation::start();

	return 0;
}
