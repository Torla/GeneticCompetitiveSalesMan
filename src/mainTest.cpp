#include <iostream>
#include <getopt.h>
#include <unistd.h>

#include "genetic/Chromosome.h"
#include "Simulation.h"


using namespace std;
using namespace Simulation;





int main(int argc,char * argv[]) {

	clock_t tStart = clock();


	Random::init(1);

	Chromosome::setMutationRate(0.5);
	Population::setSteadyRatio(0.9);
	Population::setNearRatio(0);
	Population::setBottleNeck(0.1);
	Population::setDisasterRate(0);
	Population::setTraffic(false);


	init(20,1,1000,100,1000);


	cout << bestCost() << endl;


	return 0;
}
