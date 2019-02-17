//
// Created by munfo on 10/02/2019.
//

#ifndef GENETICCOMPETITIVESALESMAN_SOLUTION_H
#define GENETICCOMPETITIVESALESMAN_SOLUTION_H


#include <algorithm>
#include <random>
#include "../graphs/Path.h"
#include "../graphs/Graph.h"
#include "../Rand.h"
#include <iostream>

class Solution : public Path{
private:
	Graph* graph;
public:
	explicit Solution(Graph* graph) : Path(graph->size()),graph(graph) {
		this->clear();
		for(register unsigned int i=0;i<graph->size();i++) this->push_back(i);
		std::shuffle(this->begin(),this->end(), Random::rng);
	}

	unsigned int evaluateCost(){
		return graph->pathCost(this);
	}

	unsigned int len()const {
		return this->Path::size();
	}

	friend std::ostream& operator<< (std::ostream& stream, Solution& sol) {

		stream << "[";
		std::vector<unsigned int> a = sol.getLinkRepresentation();
		for(std::vector<unsigned int>::iterator it =a.begin(); it != a.end(); ++it){
			stream << *it;
			stream << " ";
		}
		stream << "]";
		return stream;
	}



};


#endif //GENETICCOMPETITIVESALESMAN_SOLUTION_H
