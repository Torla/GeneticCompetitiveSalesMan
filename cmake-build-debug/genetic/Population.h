//
// Created by munfo on 11/02/2019.
//

#ifndef GENETICCOMPETITIVESALESMAN_POPULATION_H
#define GENETICCOMPETITIVESALESMAN_POPULATION_H


#include <vector>
#include "Chromosome.h"

class Population {
private:
	std::vector<Chromosome*> pop;
	Graph *graph;

	static bool solComp(Chromosome* a,Chromosome* b);

public:
	explicit Population(Graph *graph,unsigned int size):pop(size),graph(graph){
		for(int i=0;i<size;i++){
			pop[i] = new Chromosome(graph);
		}


	}

	virtual ~Population() {
		for (auto i : pop) {
			free(i);
		}
	}

	Chromosome best(){

		std::sort(pop.begin(),pop.end(),Population::solComp);

		return *pop[0];

	}

	friend std::ostream& operator<<(std::ostream & stream,Population & obj){
		for(auto i : obj.pop){
			stream << *i << i->evaluateCost() << std::endl;
		}
		return stream;
	}

};


#endif //GENETICCOMPETITIVESALESMAN_POPULATION_H
