//
// Created by munfo on 15/02/2019.
//

#include <memory>
#include "Simulation.h"


#include <chrono>


using namespace std;


unique_ptr<Graph> graph;
unique_ptr<Population> population;
unsigned int turn;
clock_t startTime;
int maxTime;

void  Simulation::init(unsigned int nodeNums,unsigned int minCost,unsigned int maxCost,unsigned int popSize, unsigned int maxTime) {
	turn=0;

	graph.reset(new Graph(nodeNums,minCost,maxCost));
	population.reset(new Population(graph.get(),popSize));


	startTime =clock();
	::maxTime=maxTime;

}

#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wmissing-noreturn"
void Simulation::run() {
	for(turn;;turn++){
		int el = ((clock()- startTime)*1000)/CLOCKS_PER_SEC;
		if(el >= maxTime){
			break;
		}
		Solution sol = population->best();
		//cout << turn << " " << "  " << sol.evaluateCost() <<  endl;
		population->nextGeneration();
		//population->save("pop.txt");

	}

}
#pragma clang diagnostic pop

int Simulation::bestCost(){
	return population->best().evaluateCost();
}

int Simulation::getTurn() {
	return turn;
}
