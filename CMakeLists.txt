cmake_minimum_required(VERSION 3.9)
project(GeneticCompetitiveSalesMan)

set(CMAKE_CXX_STANDARD 11)

add_executable(GeneticCompetitiveSalesMan src/main.cpp src/Graphs/Graph.cpp src/Graphs/Graph.h src/Graphs/Path.cpp src/Graphs/Path.h src/graphs/Matrix.h src/solution/Solution.cpp src/solution/Solution.h src/genetic/Chromosome.cpp src/genetic/Chromosome.h src/Rand.cpp src/Rand.h src/genetic/Population.cpp src/genetic/Population.h)