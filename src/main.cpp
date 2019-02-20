#include <iostream>

#include "genetic/Chromosome.h"
#include "Simulation.h"
#include <thread>


using namespace std;





int main(int argc,char * argv[]) {



	Random::init(1);

	Chromosome::setMutationRate(0.5);
	Population::setSteadyRatio(0.9);
	Population::setNearRatio(0);
	Population::setBottleNeck(0);
	Population::setDisasterRate(0.1);
	Population::setTraffic(false);


	Simulation::init(20,0,1000,1000);

	Simulation::start();

	return 0;
}
