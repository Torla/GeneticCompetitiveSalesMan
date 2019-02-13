//
// Created by munfo on 08/02/2019.
//

#include "Graph.h"
#include "Path.h"

int Graph::pathCost(const Path * path) {
	int ret=0;
	for(register unsigned int i=0;i<path->size()-1;i++){
		ret += (*this)((unsigned int) path->at(i), path->at(i+1));
	}
	return ret;
}

int Graph::pathCostCycle(const Path *path) {
	return this->pathCost(path) + (*this)(path->at(path->size()-1),path->at(0));
}
