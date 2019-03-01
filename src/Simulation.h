//
// Created by munfo on 15/02/2019.
//

#ifndef GENETICCOMPETITIVESALESMAN_SIMULATION_H
#define GENETICCOMPETITIVESALESMAN_SIMULATION_H


#include "graphs/Graph.h"
#include "genetic/Population.h"

namespace Simulation {

	void  init(unsigned int nodeNums,unsigned int minCost,unsigned int maxCost,unsigned int popSize, unsigned int maxTime);
	void run();
	int bestCost();
	int getTurn();

};


#endif //GENETICCOMPETITIVESALESMAN_SIMULATION_H
