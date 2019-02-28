#include <iostream>
#include <getopt.h>

#include "genetic/Chromosome.h"
#include "Simulation.h"


using namespace std;
using namespace Simulation;





int main(int argc,char * argv[]) {

	int gSize,minCost,maxCost,popSize,time;

	while(true) {
		static struct option long_option[]{
				{"seed",         required_argument, 0, 's'},
				{"time",         required_argument, 0, 't'},
				{"graphSize",    required_argument, 0, 'g'},
				{"graphMinCost", required_argument, 0, 'm'},
				{"graphMaxCost", required_argument, 0, 'M'},
				{"popSize",      required_argument, 0, 'S'},
				{"mutRate",      required_argument, 0, 'u'},
				{"steadyRatio",  required_argument, 0, 'd'},
				{"nearRatio",    required_argument, 0, 'N'},
				{"bottleNeckRatio",required_argument,0,'B'},
				{"disasterRate", required_argument, 0, 'D'},
				{"greedy",        no_argument,      0, 'G'},
				{"traffic",      no_argument,       0, 'T'}
		};
		int index;
		int c=-1;
		c = getopt_long(argc, argv, "sgmMStudNDTG", long_option, &index);
		if(c==-1) {
			break;
		};
		switch (c) {
			case 's':
				Random::init(static_cast<unsigned int>(atoi(optarg)));
				break;
			case 't':
				time=atoi(optarg);
				break;
			case 'g':
				gSize=atoi(optarg);
				break;
			case 'm':
				minCost=atoi(optarg);
				break;
			case 'M':
				maxCost=atoi(optarg);
				break;
			case 'S':
				popSize=atoi(optarg);
				break;
			case 'u':
				Chromosome::setMutationRate(atof(optarg));
				break;
			case 'd':
				Population::setSteadyRatio(atof(optarg));
				break;
			case 'N':
				Population::setNearRatio(atof(optarg));
				break;
			case 'B':
				Population::setBottleNeck(atof(optarg));
				break;
			case 'D':
				Population::setDisasterRate(atof(optarg));
				break;
			case 'G':
				Population::setGreedy(true);
				break;
			case 'T':
				Population::setTraffic(true);
				break;
			case '?':
				break;
			default:
				break;
		}
	}





	init(gSize,minCost,maxCost,popSize,time);
	run();

	cout << bestCost() << endl;
	return 0;
}
