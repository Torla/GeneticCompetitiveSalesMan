#!/bin/bash

cmake CMakeLists.txt
make all

filePath="results"

testsForCase="10"

echo "starting script test"


echo " " > filePath


sum=0
echo -n  "0/$testsForCase"

for i in $(seq 1 $testsForCase);
do
	echo -n -e "\b\b\b\b\b\b\b\b\btest:$i/$testsForCase"
	echo -n "$i," >> $filePath
	value=$(./GeneticCompetitiveSalesMan --seed $i --time 1000 --graphSize 20 --graphMinCost 1 --graphMaxCost 1000 --popSize 100 --mutRate 0.5 --steadyRatio 0.9 --nearRatio 0 --bottleNeckRatio 0.1 --disasterRate 0 |tr -d '\n ')
	((sum=sum+value))
	echo  $value >> $filePath
done


echo -e "\n$((sum/10))"
