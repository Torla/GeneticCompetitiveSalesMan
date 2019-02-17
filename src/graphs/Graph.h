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
	explicit Graph(unsigned int nodesNum, int minCost=0, int maxCost=100)
		:Matrix(nodesNum)
	{
		std::uniform_int_distribution<std::mt19937::result_type> dist6(minCost,maxCost);

		for(register int i=0;i<nodesNum;i++){
			for(register int j=0;j<nodesNum;j++){
				(*this)(i,j)= dist6(Random::rng);
			}
		}
	}

	void placeOptimal(const Path* path);

	int pathCost(const Path* path) const;

	int pathCostCycle(const Path *path) const;
};


#endif //GENETICCOMPETITIVESALESMAN_GRAPH_H
