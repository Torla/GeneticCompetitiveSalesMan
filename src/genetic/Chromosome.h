//
// Created by munfo on 11/02/2019.
//

#ifndef GENETICCOMPETITIVESALESMAN_CHROMOSOME_H
#define GENETICCOMPETITIVESALESMAN_CHROMOSOME_H


#include <utility>

#include "../solution/Solution.h"
#include "../Rand.h"

class Chromosome: public Solution {
private:
	static float mutationRate;
	static Solution order1CrossOver(const Solution &sol1,const Solution &sol2);
	static Solution mutation(Solution so1);
public:
	explicit Chromosome(const Graph *graph):Solution(graph){}
	Chromosome(Solution solution):Solution(std::move(solution)){}
	Chromosome(const Chromosome& c1,const Chromosome& c2):Solution(mutation(order1CrossOver(c1,c2))){
	}

	static void setMutationRate(float mutationRate) {
		Chromosome::mutationRate = mutationRate;
	}

};


#endif //GENETICCOMPETITIVESALESMAN_CHROMOSOME_H
