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

class Graph : public Matrix<int>{


public:
	explicit Graph(unsigned int nodesNum, int minCost=0, int maxCost=100)
		:Matrix(nodesNum)
	{
		std::mt19937 rng;
		rng.seed(static_cast<unsigned int>(time(NULL)));
		std::uniform_int_distribution<std::mt19937::result_type> dist6(minCost,maxCost);

		for(register int i=0;i<nodesNum;i++){
			for(register int j=0;j<nodesNum;j++){
				(*this)(i,j)= dist6(rng);
			}
		}
	}
	int pathCost(const Path* path);

	int pathCostCycle(const Path *path);
};


#endif //GENETICCOMPETITIVESALESMAN_GRAPH_H