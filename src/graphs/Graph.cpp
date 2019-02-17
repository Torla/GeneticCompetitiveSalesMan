//
// Created by munfo on 08/02/2019.
//

#include "Graph.h"
#include "Path.h"

int Graph::pathCost(const Path * path) const {
	int ret=0;
	for(register unsigned int i=0;i<path->size()-1;i++){
		ret += (*this)(path->get(i), path->get(i+1));
	}
	return ret;
}

int Graph::pathCostCycle(const Path *path) const {
	return this->pathCost(path) + (*this)(path->get(path->size()-1),path->get(0));
}

void Graph::placeOptimal(const Path *path) {

	for(register unsigned int i=0;i<path->size();i++){
		(*this)(path->get(i),path->get((i+1)%path->size()))=0;
	}




}
