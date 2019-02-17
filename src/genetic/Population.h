//
// Created by munfo on 11/02/2019.
//

#ifndef GENETICCOMPETITIVESALESMAN_POPULATION_H
#define GENETICCOMPETITIVESALESMAN_POPULATION_H


#include <vector>
#include <set>
#include <fstream>
#include "Chromosome.h"



class Population {
private:
	static float steadyRatio;
	static float nearRatio;
	static float bottleNeck;
	static float bottleNeckGravity;
	static bool traffic;

	std::vector<Chromosome*> pop;
	Graph *graphWithTraffic;
	const Graph *graph;

	static bool solComp(Chromosome* a,Chromosome* b);
	void rouletteWheel(std::vector<Chromosome *> &parentCouples, unsigned int couplesNumber);
	int binarySearch(const std::vector<unsigned int> &probS, unsigned int r) const;
	void computeTrafficOnGraph();


public:
	explicit Population(const Graph *graph,unsigned int size):pop(size),graph(graph){

		graphWithTraffic = new Graph(*graph);

		for(int i=0;i<size;i++){
			pop[i] = new Chromosome(graphWithTraffic);
		}

		std::sort(pop.begin(),pop.end(),Population::solComp);

	}

	virtual ~Population() {
		for (auto i : pop) {
			free(i);
		}
	}

	static void setSteadyRatio(float steadyRatio) {
		Population::steadyRatio = steadyRatio;
	}
	static void setNearRatio(float nearRatio) {
		Population::nearRatio = nearRatio;
	}
	static void setTraffic(bool traffic) {
		Population::traffic = traffic;
	}
	static void setBottleNeck(float bottleNeck) {
		Population::bottleNeck = bottleNeck;
	}

	unsigned int size()const{
		return pop.size();
	}

	Chromosome best(){ //todo const check this and don't sort

		std::sort(pop.begin(),pop.end(),Population::solComp);

		return *pop[0];

	}

	float meanCost()const{
		int sum=0;
		for(auto p:pop){
			sum+=p->evaluateCost();
		}
		return (float)sum/pop.size();
	}

	float stdDevCost()const{
		float mean = meanCost();
		float ret=0;
		for(auto p:pop){
			ret += pow(p->evaluateCost() - mean,2);
		}
		ret/=pop.size();
		return sqrtf(ret);
	}



	void nextGeneration();


	friend std::ostream& operator<<(std::ostream & stream,const Population & p){

		std::vector<Chromosome *> obj(p.pop);
		std::sort(obj.begin(),obj.end(),Population::solComp);
		for(auto i : obj){
			stream << *i << i->evaluateCost()  << std::endl;
		}
		return stream;
	}

	void save(const char* path)const{
		std::ofstream myfile;
		myfile.open (path);
		myfile << *this;
		myfile.close();
	}



};


#endif //GENETICCOMPETITIVESALESMAN_POPULATION_H
