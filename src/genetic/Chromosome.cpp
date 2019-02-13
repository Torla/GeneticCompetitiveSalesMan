//
// Created by munfo on 11/02/2019.
//

#include "Chromosome.h"

const float Chromosome::mutationRate = 0.5;

Solution Chromosome::order1CrossOver(Solution &sol1, Solution &sol2) {

	unsigned int crossL,crossR;
	Solution ret(sol1);
	std::uniform_int_distribution<std::mt19937::result_type> dist(0,sol1.len());
	crossL= dist(Random::rng);
	std::uniform_int_distribution<std::mt19937::result_type> dist1(crossL,sol1.len());
	crossR = dist1(Random::rng);
	crossL=0;
	crossR=0;
	int k=0;
	std::vector<int> v;
	for(int i=crossL;i<crossR;i++){
		v.push_back(sol1[i]);
	}
	for(int i=0;i<sol1.len();){
		if(i==crossL) i=crossR;
		if(i==sol1.len()) break;
		if(std::find(v.begin(),v.end(),sol2[k])==v.end()) {
			ret[i] = sol2[k];
			i++;
		}
		k++;
	}
	return ret;
}

Solution Chromosome::mutation(Solution sol) {
	std::uniform_int_distribution<std::mt19937::result_type> distFloat(0,1000);
	std::uniform_int_distribution<std::mt19937::result_type> distInt(0,sol.len()-1);
	if(mutationRate*1000-distFloat(Random::rng)>0){
		int a=distInt(Random::rng);
		int b=distInt(Random::rng);

		const unsigned int temp = sol[a];
		sol[a] = sol[b];
		sol[b] = (temp);
	}

	return sol;
}
