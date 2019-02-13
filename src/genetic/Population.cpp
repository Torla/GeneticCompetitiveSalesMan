//
// Created by munfo on 11/02/2019.
//

#include "Population.h"

bool Population::solComp(Chromosome *a, Chromosome *b) {
	return (a->evaluateCost()<b->evaluateCost());
}

