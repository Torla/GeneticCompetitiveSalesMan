//
// Created by munfo on 15/02/2019.
//

#include <memory>
#include "Simulation.h"


#include <chrono>

using namespace std::chrono;
using namespace std;


unique_ptr<Graph> graph;
unique_ptr<Population> population;
unsigned int turn;
microseconds startTime;
microseconds maxTime;

void  Simulation::init(unsigned int nodeNums,unsigned int minCost,unsigned int maxCost,unsigned int popSize, unsigned int maxTime) {
	graph.reset(new Graph(nodeNums,minCost,maxCost));
	population.reset(new Population(graph.get(),popSize));

	startTime = duration_cast<microseconds>(system_clock::now().time_since_epoch());
	microseconds m(maxTime*1000);
	::maxTime=m;


}

#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wmissing-noreturn"
void Simulation::run() {
	for(turn=0;;turn++){
		microseconds el = duration_cast<microseconds>(system_clock::now().time_since_epoch())-startTime-maxTime;
		if(el.count() >= 0){
			break;
		}
		Solution sol = population->best();
		//cout << turn << " " << "  " << sol.evaluateCost() << "  " << population->meanCost()  << " " << population->stdDevCost() << endl;
		population->nextGeneration();
		//population->save("pop.txt");

	}

}
#pragma clang diagnostic pop

int Simulation::bestCost(){
	return population->best().evaluateCost();
}