#include <iostream>

#include "genetic/Chromosome.h"
#include "Simulation.h"


using namespace std;



int main(int argc,char * argv[]) {



	Random::init(0);

	Chromosome::setMutationRate(0.5);
	Population::setSteadyRatio(0.9);
	Population::setNearRatio(0.5);
	Population::setBottleNeck(0.1);
	Population::setTraffic(true);


	Simulation::init(20,0,1000,100);

	Simulation::start();

	return 0;
}
