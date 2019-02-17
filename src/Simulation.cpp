//
// Created by munfo on 15/02/2019.
//

#include "Simulation.h"



Graph* graph;
Population* population;
int turn;

void  Simulation::init(int nodeNums,int minCost,int maxCost,int popSize) {
	graph = new Graph(nodeNums,minCost,maxCost);
	population = new Population(graph,popSize);


}

#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wmissing-noreturn"
void Simulation::start() {
	for(turn=0;;turn++){
		Solution sol = population->best();
		std::cout << turn << " " << "  " << sol.evaluateCost() << "  " << population->meanCost()  << " " << population->stdDevCost() << std::endl;
		population->nextGeneration();
		population->save("pop.txt");
	}

}
#pragma clang diagnostic pop
