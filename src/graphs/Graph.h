//
// Created by munfo on 08/02/2019.
//

#ifndef GENETICCOMPETITIVESALESMAN_GRAPH_H
#define GENETICCOMPETITIVESALESMAN_GRAPH_H


#include <array>
#include <random>
#include <time.h>
#include "Matrix.h"
#include "Path.h"
#include "../Rand.h"

class Graph : public Matrix<int>{


public:
	explicit Graph(unsigned int nodesNum, unsigned int minCost=0, unsigned int maxCost=100)
		:Matrix(nodesNum)
	{
		std::uniform_int_distribution<std::mt19937::result_type> dist6(minCost,maxCost);

		for(register unsigned int i=0;i<nodesNum;i++){
			for(register unsigned int j=0;j<nodesNum;j++){
				(*this)(i,j)= dist6(Random::rng);
			}
		}
	}

	void placeOptimal(const Path* path);

	unsigned int pathCost(const Path* path) const;

	unsigned int pathCostCycle(const Path *path) const;
};


#endif //GENETICCOMPETITIVESALESMAN_GRAPH_H
