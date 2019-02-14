//
// Created by munfo on 11/02/2019.
//

#ifndef GENETICCOMPETITIVESALESMAN_POPULATION_H
#define GENETICCOMPETITIVESALESMAN_POPULATION_H


#include <vector>
#include <set>
#include "Chromosome.h"



class Population {
private:

	const static float steadyRatio;

	std::vector<Chromosome*> pop;
	Graph *graphWithTraffic;
	Graph *graph;

	static bool solComp(Chromosome* a,Chromosome* b);
	void rouletteWheel(std::vector<Chromosome *> &parentCouples, unsigned int couplesNumber);
	void computeTrafficOnGraph();


public:
	explicit Population(Graph *graph,unsigned int size):pop(size),graph(graph){

		graphWithTraffic = new Graph(*graph);

		for(int i=0;i<size;i++){
			pop[i] = new Chromosome(graphWithTraffic);
		}

		std::sort(pop.begin(),pop.end(),Population::solComp);

	}

	virtual ~Population() {
		for (auto i : pop) {
			free(i);
		}
	}

	unsigned int size(){
		return pop.size();
	}

	Chromosome best(){

		std::sort(pop.begin(),pop.end(),Population::solComp);

		return *pop[0];

	}

	void nextGeneration();


	friend std::ostream& operator<<(std::ostream & stream,Population & obj){
		for(auto i : obj.pop){
			stream << *i << i->evaluateCost() << std::endl;
		}
		return stream;
	}

};


#endif //GENETICCOMPETITIVESALESMAN_POPULATION_H
