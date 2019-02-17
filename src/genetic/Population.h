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

	std::vector<Chromosome*> pop;
	Graph *graphWithTraffic;
	Graph *graph;
	static bool traffic;

	static bool solComp(Chromosome* a,Chromosome* b);
	void rouletteWheel(std::vector<Chromosome *> &parentCouples, unsigned int couplesNumber);
	int binarySearch(const std::vector<unsigned int> &probS, unsigned int r) const;
	void computeTrafficOnGraph();


public:
	explicit Population(Graph *graph,unsigned int size):pop(size),graph(graph){

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

	unsigned int size(){
		return pop.size();
	}

	Chromosome best(){

		std::sort(pop.begin(),pop.end(),Population::solComp);

		return *pop[0];

	}

	float meanCost(){
		int sum=0;
		for(auto p:pop){
			sum+=p->evaluateCost();
		}
		return (float)sum/pop.size();
	}

	float stdDevCost(){
		float mean = meanCost();
		float ret=0;
		for(auto p:pop){
			ret += pow(p->evaluateCost() - mean,2);
		}
		ret/=pop.size();
		return sqrtf(ret);
	}



	void nextGeneration();


	friend std::ostream& operator<<(std::ostream & stream,Population & obj){

		std::sort(obj.pop.begin(),obj.pop.end(),Population::solComp);
		for(auto i : obj.pop){
			stream << *i << i->evaluateCost()  << std::endl;
		}
		return stream;
	}

	void save(const char* path){
		std::ofstream myfile;
		myfile.open (path);
		myfile << *this;
		myfile.close();
	}


};


#endif //GENETICCOMPETITIVESALESMAN_POPULATION_H
