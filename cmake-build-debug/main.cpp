#include <iostream>

#include "genetic/Chromosome.h"


using namespace std;

int main() {

	Random::init(time(nullptr));

	Graph graph(5,0,100);

	Chromosome solution(&graph);
	Chromosome solution1(&graph);
	Chromosome solution3(solution,solution1);


	cout << solution << solution.evaluateCost() << endl ;
	cout << solution1 << solution1.evaluateCost() << endl ;
	cout << solution3 << solution3.evaluateCost() << endl ;

	return 0;
}