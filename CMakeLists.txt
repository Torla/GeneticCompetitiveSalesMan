cmake_minimum_required(VERSION 3.9)
project(GeneticCompetitiveSalesMan)

set(CMAKE_CXX_STANDARD 11)

add_executable(GeneticCompetitiveSalesMan cmake-build-debug/main.cpp cmake-build-debug/Graphs/Graph.cpp cmake-build-debug/Graphs/Graph.h cmake-build-debug/Graphs/Path.cpp cmake-build-debug/Graphs/Path.h cmake-build-debug/graphs/Matrix.h cmake-build-debug/solution/Solution.cpp cmake-build-debug/solution/Solution.h cmake-build-debug/genetic/Chromosome.cpp cmake-build-debug/genetic/Chromosome.h cmake-build-debug/Rand.cpp cmake-build-debug/Rand.h cmake-build-debug/genetic/Population.cpp cmake-build-debug/genetic/Population.h)