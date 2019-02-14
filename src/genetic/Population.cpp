//
// Created by munfo on 11/02/2019.
//

#include "Population.h"


const float  Population::steadyRatio = 0.1;

bool Population::solComp(Chromosome *a, Chromosome *b) {
	return (a->evaluateCost()<b->evaluateCost());
}

void Population::nextGeneration() {
	std::vector<Chromosome *> children;
	std::vector<Chromosome *> parentsCouples;


	rouletteWheel(parentsCouples,pop.size() - pop.size()*steadyRatio);




	for(register unsigned int i=1;i<parentsCouples.size();i+=2){ // todo opt steady ratio
		children.push_back(new Chromosome(*parentsCouples[i],*parentsCouples[i-1]));
		children.push_back(new Chromosome(*parentsCouples[i-1],*parentsCouples[i]));
	}


	if(steadyRatio!=0)std::sort(pop.begin(),pop.end(),Population::solComp);
	for(register unsigned int i=0;i<pop.size();i+=1){
		if(i<pop.size()*steadyRatio-(pop.size()%2)){
			children.push_back(pop[i]);
		}
		else free(pop[i]);
	}


	pop.swap(children);
}

void Population::rouletteWheel(std::vector<Chromosome *> &parentCouples, unsigned int couplesNumber) {
	
	const int precision = 100000;
	
	std::vector<unsigned int> prob(pop.size()),probS(pop.size());
	int sum=0;
	for(int i=0;i<pop.size();i++){
		prob[i]=pop[i]->evaluateCost();
		sum+=prob[i];
	}
	if(sum==0) sum=1; // todo del this
	for(unsigned int i=0;i<pop.size();i++){
		prob[i]=(prob[i]*precision)/sum+i%2;
	}
	probS[0]=0;
	for(unsigned int i=1;i<pop.size();i++){
		probS[i]=probS[i-1]+prob[i];
	}

	if(probS[pop.size()-1]<precision) probS[pop.size()-1]=precision;
	//std::cout << probS[pop.size()-1];

	//binary search

	std::uniform_int_distribution<std::mt19937::result_type> distInt(0,precision-1);

	int r;
	for(int i=0;i<couplesNumber;i++) {
		r=distInt(Random::rng);
		int s=0,d=pop.size(),x=s+(d-s)/2;
		while(!(probS[x]<=r && probS[x+1]>r)){
			if(probS[x+1]==r) {
				x++;
				break;
			}
			else if(probS[x]>r){
				d=x;
			}
			else {
				s=x;
			}
			x=s+(d-s)/2;
		}
		parentCouples.push_back(pop[x]);
	}


}

