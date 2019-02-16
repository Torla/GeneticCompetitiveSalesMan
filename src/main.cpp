#include <iostream>

#include "genetic/Chromosome.h"
#include "genetic/Population.h"
#include "Simulation.h"


using namespace std;



int main() {

	Random::init(0);

	Simulation::init(20,1000);

	Simulation::start();

	return 0;
}
