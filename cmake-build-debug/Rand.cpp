//
// Created by munfo on 11/02/2019.
//

#include "Rand.h"

std::mt19937 Random::rng;

void Random::init(int seed){
	Random::rng.seed(seed);
};
