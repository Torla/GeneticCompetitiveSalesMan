//
// Created by munfo on 11/02/2019.
//

#ifndef GENETICCOMPETITIVESALESMAN_CHROMOSOME_H
#define GENETICCOMPETITIVESALESMAN_CHROMOSOME_H


#include "../solution/Solution.h"
#include "../Rand.h"

class Chromosome: public Solution {
private:
	const static float mutationRate;
	static Solution order1CrossOver(Solution &sol1, Solution &sol2);
	static Solution mutation(Solution so1);
public:
	Chromosome(Graph *graph):Solution(graph){}
	Chromosome(Chromosome& c1,Chromosome& c2):Solution(mutation(order1CrossOver(c1,c2))){
	}

};


#endif //GENETICCOMPETITIVESALESMAN_CHROMOSOME_H
