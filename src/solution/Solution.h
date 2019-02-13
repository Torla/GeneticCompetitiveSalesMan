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
		std::mt19937 rng;
		rng.seed(static_cast<unsigned int>(time(nullptr)));

		this->clear();
		for(register unsigned int i=0;i<graph->size();i++) this->push_back(i);
		std::shuffle(this->begin(),this->end(), Random::rng);
	}

	unsigned int evaluateCost(){
		return graph->pathCostCycle(this);
	}


	unsigned int& operator[](unsigned int i){
		return this->at(i);
	}

	unsigned int len()const {
		return this->Path::size();
	}

	friend std::ostream& operator<< (std::ostream& stream, Solution& sol) {

		stream << "[";
		for(std::vector<unsigned int>::iterator it = sol.begin(); it != sol.end(); ++it){
			stream << *it;
			stream << " ";
		}
		stream << "]";
		return stream;
	}



};


#endif //GENETICCOMPETITIVESALESMAN_SOLUTION_H
