//
// Created by munfo on 28/02/2019.
//

#ifndef GENETICCOMPETITIVESALESMAN_GREEDY_H
#define GENETICCOMPETITIVESALESMAN_GREEDY_H

#include "../solution/Solution.h"


namespace Greedy{
	std::vector<Solution> gen(const Graph &graph);
	Solution minDistance(const Graph &graph, unsigned int startNode);
}

#endif //GENETICCOMPETITIVESALESMAN_GREEDY_H
