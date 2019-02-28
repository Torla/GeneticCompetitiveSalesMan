cmake_minimum_required(VERSION 3.5)
project(GeneticCompetitiveSalesMan)

set(CMAKE_CXX_STANDARD 11)

add_executable(GeneticCompetitiveSalesMan src/main.cpp src/graphs/Graph.cpp src/graphs/Graph.h src/graphs/Path.cpp src/graphs/Path.h src/graphs/Matrix.h src/solution/Solution.cpp src/solution/Solution.h src/genetic/Chromosome.cpp src/genetic/Chromosome.h src/Rand.cpp src/Rand.h src/genetic/Population.cpp src/genetic/Population.h src/Simulation.cpp src/Simulation.h src/Greedy/Greedy.cpp src/Greedy/Greedy.h)

add_executable(Test src/mainTest.cpp src/graphs/Graph.cpp src/graphs/Graph.h src/graphs/Path.cpp src/graphs/Path.h src/graphs/Matrix.h src/solution/Solution.cpp src/solution/Solution.h src/genetic/Chromosome.cpp src/genetic/Chromosome.h src/Rand.cpp src/Rand.h src/genetic/Population.cpp src/genetic/Population.h src/Simulation.cpp src/Simulation.h src/Greedy/Greedy.cpp src/Greedy/Greedy.h)
