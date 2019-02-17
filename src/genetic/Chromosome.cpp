//
// Created by munfo on 11/02/2019.
//

#include "Chromosome.h"

float Chromosome::mutationRate;

Solution Chromosome::order1CrossOver(const Solution &sol1, const Solution &sol2) {

	unsigned int crossL,crossR;
	Solution ret(sol1);
	std::uniform_int_distribution<std::mt19937::result_type> dist(0,sol1.len());
	crossL= dist(Random::rng);
	std::uniform_int_distribution<std::mt19937::result_type> dist1(crossL,sol1.len());
	crossR = dist1(Random::rng);
	unsigned int k=0;
	std::vector<int> v;
	for(unsigned int i=crossL;i<crossR;i++){
		v.push_back(sol1.get(i));
	}
	for(int i=0;i<sol1.len();){
		if(i==crossL) i=crossR;
		if(i==sol1.len()) break;
		if(std::find(v.begin(),v.end(),sol2.get(k))==v.end()) {
			ret[i] = sol2.get(k);
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
