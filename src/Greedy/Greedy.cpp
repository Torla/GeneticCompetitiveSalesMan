//
// Created by munfo on 28/02/2019.
//

#include "Greedy.h"

using namespace std;

Solution Greedy::minDistance(const Graph &graph, unsigned int startNode) {
	Solution ret(&graph);
	vector<bool> used(graph.size());
	for(register unsigned int i=0;i<graph.size();i++){
		used.at(i)=false;
	}
	ret[0]=(startNode);
	used.at(startNode)=true;
	for(register unsigned int i=1;i<graph.size();i++){
		int min=INT32_MAX;
		unsigned int minNode =0;
		for (register unsigned int j=0; j < graph.size(); j++){
			if(used.at(j)) continue;
			if(graph(i-1,j)<min){
				min=graph(i-1,j);
				minNode=j;
			}
		}
		ret[i]=minNode;
		used.at(minNode)=true;
	}
	return ret;
}

std::vector<Solution> Greedy::gen(const Graph &graph) {
	vector<Solution> ret;
	for(register unsigned int i=0;i<graph.size();i++) {
		ret.push_back(minDistance(graph,i));
	}
	return ret;
}
