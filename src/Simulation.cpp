//
// Created by munfo on 15/02/2019.
//

#include <memory>
#include "Simulation.h"



std::unique_ptr<Graph> graph;
std::unique_ptr<Population> population;
int turn;

void  Simulation::init(unsigned int nodeNums,unsigned int minCost,unsigned int maxCost,unsigned int popSize) {
	graph.reset(new Graph(nodeNums,minCost,maxCost));
	population.reset(new Population(graph.get(),popSize));


}

#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wmissing-noreturn"
void Simulation::start() {
	for(turn=0;;turn++){
		Solution sol = population->best();
		std::cout << turn << " " << "  " << sol.evaluateCost() << "  " << population->meanCost()  << " " << population->stdDevCost() << std::endl;
		population->nextGeneration();
		//population->save("pop.txt");
	}

}
#pragma clang diagnostic pop
