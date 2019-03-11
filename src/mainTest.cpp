#include <iostream>

#include <thread>

#include "genetic/Chromosome.h"
#include "Simulation.h"
#include "Greedy/Greedy.h"


using namespace std;
using namespace Simulation;





int main(int argc,char * argv[]) {


	Random::init(5);

	Chromosome::setMutationRate(0.5);
	Population::setSteadyRatio(0.9);
	Population::setNearRatio(0);
	Population::setBottleNeck(0.1);
	Population::setDisasterRate(0);
	Population::setTraffic(false);
	Population::setGreedy(true);


	init(20,1,1000,1000,10000);
	run();


	cout << bestCost() << endl;


	return 0;
}
