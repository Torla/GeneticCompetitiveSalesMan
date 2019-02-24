#include <iostream>
#include <getopt.h>

#include "genetic/Chromosome.h"
#include "Simulation.h"


using namespace std;
using namespace Simulation;





int main(int argc,char * argv[]) {




	Random::init(0);

	Chromosome::setMutationRate(0.5);
	Population::setSteadyRatio(0.9);
	Population::setNearRatio(0);
	Population::setBottleNeck(0.05);
	Population::setDisasterRate(0);
	Population::setTraffic(false);


	init(20,0,1000,100,10000);
	run();

	cout << bestCost() << endl;

	return 0;
}
