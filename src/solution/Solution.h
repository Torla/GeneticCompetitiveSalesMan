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
	const Graph* graph;
public:
	explicit Solution(const Graph* graph) : Path(graph->size()),graph(graph) {
		this->clear();
		for(register unsigned int i=0;i<graph->size();i++) this->push_back(i);
		std::shuffle(this->begin(),this->end(), Random::rng);
	}

	unsigned int evaluateCost()const{
		return graph->pathCostCycle(this);
	}

	unsigned int len()const {
		return this->Path::size();
	}

	unsigned int distance(const Solution & sol)const{
		std:vector<unsigned int> a=this->getLinkRepresentation(),b=sol.getLinkRepresentation();
		unsigned int ret=0;
		for(register unsigned int i=0;i<this->size();i++){
			if(a[i]!=b[i]) ret++;
		}
		return ret;

	}

	friend std::ostream& operator<< (std::ostream& stream,const Solution& sol) {

		stream << "[";
		std::vector<unsigned int> a = sol.getLinkRepresentation();
		for (unsigned int &it : a) {
			stream << it;
			stream << " ";
		}
		stream << "]";
		return stream;
	}



};


#endif //GENETICCOMPETITIVESALESMAN_SOLUTION_H
