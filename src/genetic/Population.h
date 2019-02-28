//
// Created by munfo on 11/02/2019.
//

#ifndef GENETICCOMPETITIVESALESMAN_POPULATION_H
#define GENETICCOMPETITIVESALESMAN_POPULATION_H


#include <vector>
#include <set>
#include <fstream>
#include <memory>
#include "Chromosome.h"
#include "../Greedy/Greedy.h"


class Population {
private:
	static float steadyRatio;
	static float nearRatio;
	static float bottleNeckRatio;
	static float bottleNeckGravity;
	static bool traffic;
	static float disasterRate;
	static float disasterGravity;
	static bool greedy;

	std::vector<std::shared_ptr<Chromosome>> pop;
	Graph *graphWithTraffic;
	const Graph *graph;

	static bool solComp(std::shared_ptr<Chromosome> a,std::shared_ptr<Chromosome> b);
	void rouletteWheel(std::vector<std::shared_ptr<Chromosome>> &parentCouples, unsigned int couplesNumber);
	int binarySearch(const std::vector<unsigned int> &probS, unsigned int r) const;
	void computeTrafficOnGraph();


public:
	explicit Population(const Graph *graph,unsigned int size):pop(size),graph(graph){

		graphWithTraffic = new Graph(*graph);

		std::vector<Solution> g;

		if(greedy){
			g = Greedy::gen(*graphWithTraffic);
		}

		for(int i=0;i<size;i++){
			if(i<g.size()){
				pop[i].reset(new Chromosome(g[i]));
			}
			else {
				pop[i].reset(new Chromosome(graphWithTraffic));
			}
		}

		std::sort(pop.begin(),pop.end(),Population::solComp);

	}

	virtual ~Population() {
		for (auto i : pop) {
			i.reset();
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
		Population::bottleNeckRatio = bottleNeck;
	}
	static void setDisasterRate(float disasterRate) { Population::disasterRate = disasterRate;
	}
	static void setDisasterGravity(float disasterGravity) {
		Population::disasterGravity = disasterGravity;
	}
	static void setGreedy(bool greedy) {
		Population::greedy = greedy;
	}

	unsigned int size()const{
		return pop.size();
	}

	Chromosome best()const{

		return **std::min_element(pop.begin(),pop.end(),Population::solComp);

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

		std::vector<std::shared_ptr<Chromosome>> obj(p.pop);
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
