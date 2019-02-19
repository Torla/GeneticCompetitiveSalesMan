//
// Created by munfo on 11/02/2019.
//

#include "Population.h"

float  Population::steadyRatio=0;
float  Population::nearRatio=0;
float  Population::bottleNeck=0;
float  Population::bottleNeckGravity=0.1;
bool  Population::traffic=false;

bool Population::solComp(const std::shared_ptr<Chromosome> a, const std::shared_ptr<Chromosome> b) {
	return (a->evaluateCost()<b->evaluateCost());
}

void Population::nextGeneration() {
	std::vector<std::shared_ptr<Chromosome>> children;
	std::vector<std::shared_ptr<Chromosome>> parentsCouples;

	std::uniform_real_distribution<> distFloat(0,1);

	float tempSR=steadyRatio;
	if(distFloat(Random::rng)-bottleNeck<0){
		steadyRatio*=bottleNeckGravity;
		std::cout << "bottle" << std::endl;
	}


	rouletteWheel(parentsCouples, static_cast<unsigned int>(pop.size() - pop.size() * steadyRatio));


	for(register unsigned int i=1;i<parentsCouples.size();i+=2){
		children.emplace_back(new Chromosome(*parentsCouples[i],*parentsCouples[i-1]));
		children.emplace_back(new Chromosome(*parentsCouples[i-1],*parentsCouples[i]));
	}


	if(steadyRatio!=0)std::sort(pop.begin(),pop.end(),Population::solComp);
	for(register unsigned int i=0;i<pop.size();i+=1){
		if(i<pop.size()*steadyRatio-(pop.size()%2)){
			children.push_back(pop[i]);
		}
		else {
			pop[i].reset();
		}
	}


	steadyRatio=tempSR;


	pop.swap(children);

	children.clear();

	if(traffic) computeTrafficOnGraph();

}

void Population::rouletteWheel(std::vector<std::shared_ptr<Chromosome>> &parentCouples, unsigned int couplesNumber) {
	
	const int precision = 100000;

	
	std::vector<unsigned int> prob(pop.size()),probS(pop.size()),probD(pop.size()),probDS(pop.size());

	int sum=0,max=0;
	for(int i=0;i<pop.size();i++){
		prob[i]=pop[i]->evaluateCost();
		if(prob[i]>max) max = prob[i];
	}
	for(int i=0;i<pop.size();i++){
		prob[i]=max-prob[i];
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


	unsigned int r;
	std::uniform_int_distribution<std::mt19937::result_type> distInt(0,precision-1);
	for(int i=0;i<couplesNumber;i+=2) {
		r=distInt(Random::rng);
		parentCouples.push_back(pop[binarySearch(probS,r)]);
		if(nearRatio==0){
			r=distInt(Random::rng);
			parentCouples.push_back(pop[binarySearch(probS,r)]);
			continue;
		}
		int sumD=0;
		for(unsigned int x=0;x<pop.size();x++){
			unsigned int d=parentCouples[i]->distance(*pop.at(x));
			probD[x]=graph->size()-d;
			sumD+=probD[x];
		}
		if(sumD==0) sumD=1;
		for(unsigned int x=0;x<pop.size();x++){
			probD[x]= static_cast<unsigned int>(((probD[x] * precision * nearRatio ) / sumD) + prob[x] * (1 - nearRatio));
		}
		probDS[0]=0;
		for(unsigned int x=1;x<pop.size();x++){
			probDS[x]=probDS[x-1]+probD[x];

		}

		if(probDS[pop.size()-1]<precision) probDS[pop.size()-1]=precision;

		r=distInt(Random::rng);
		parentCouples.push_back(pop[binarySearch(probDS,r)]);

	}
}

int Population::binarySearch(const std::vector<unsigned int> &probS, unsigned int r) const {
	int s=0,d= pop.size(),x= s + (d - s) / 2;
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
	return x;
}

void Population::computeTrafficOnGraph() {
	for (register unsigned int i = 0; i < graph->size();i++) {
		for (register unsigned int j = 0; j < graph->size();j++) {
			(*graphWithTraffic)(i,j)=(*graph)(i,j);
		}
	}
	for(auto p:pop){
		for(register unsigned int i=0;i<p->size();i++){
			(*graphWithTraffic)(p->get(i),p->get((i+1)%p->size()))+=1; //todo change this
		}
	}
}

