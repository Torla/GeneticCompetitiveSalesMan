#!/bin/bash

cmake CMakeLists.txt
make all


filePath="results"

testsForCase="10"


timePerTest="1000"
graphSize="20"
graphSize="20"
minCost="1"
maxCost="1000"
popSize="100"



echo "starting script test"


echo " " > $filePath


sum=0

echo -n  "0/$testsForCase"

for steadyRatio in 0 0.1 0.5 0.7 0.9
do
    echo -e "\b\b\b\b\b\b\bsteadyR=$steadyRatio"
    echo -n "$steadyRatio," >> $filePath;
    for i in $(seq 1 $testsForCase);
    do
        echo -n -e "\b\b\b\b\b\b\b\b\btest:$i/$testsForCase"
        echo -n "$i," >> $filePath
        value=$(./GeneticCompetitiveSalesMan --seed ${i} --time ${timePerTest} --graphSize ${graphSize} --graphMinCost ${minCost} --graphMaxCost ${maxCost} --popSize ${popSize} --mutRate 0.5 --steadyRatio 0.9 --nearRatio 0 --bottleNeckRatio 0 --disasterRate 0 |tr -d '\n ')
        ((sum=sum+value))
    done
    echo $((sum/testsForCase)) >> $filePath;
done


