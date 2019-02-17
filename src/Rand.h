//
// Created by munfo on 11/02/2019.
//

#ifndef GENETICCOMPETITIVESALESMAN_RAND_H
#define GENETICCOMPETITIVESALESMAN_RAND_H


#include <random>

namespace Random {
	extern std::mt19937 rng;
	void init(unsigned int);
};


#endif //GENETICCOMPETITIVESALESMAN_RAND_H
