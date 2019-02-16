//
// Created by munfo on 15/02/2019.
//

#ifndef GENETICCOMPETITIVESALESMAN_SIMULATION_H
#define GENETICCOMPETITIVESALESMAN_SIMULATION_H


#include "graphs/Graph.h"
#include "genetic/Population.h"

namespace Simulation {

	void  init(int nodeNums,int minCost,int maxCost,int popSize);
	void start();

};


#endif //GENETICCOMPETITIVESALESMAN_SIMULATION_H
