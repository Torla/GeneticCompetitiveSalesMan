#!/bin/bash

cmake CMakeLists.txt
make all


filePath="results"

testsForCase="10"


timePerTest="1000"
graphSize="20"
minCost="1"
maxCost="1000"
popSize="100"

steadyRatioSet="0 0.1 0.5 0.7 0.9"
mutRateSet="0 0.1 0.5 0.7 1"
nearRatioSet="0 0.1 0.5 0.7 1"
bottleNeckRatioSet="0 0.01 0.05 0.1 0.5"
disasterRateSet="0 0.01 0.05 0.1 0.5"



echo "starting script test"


echo "steady,near,bottle,disa,avg " > $filePath

for steadyRatio in ${steadyRatio};
do
for nearRatio in ${nearRatioSet}
do
for bottleNeckRatio in ${bottleNeckRatioSet}
do
for disasterRate in ${disasterRateSet}
do
for mutRate in ${mutRateSet}
do
    echo -e "\r$steadyRatio,$nearRatio,$bottleNeckRatio,$disasterRate"
    echo -n "0/$testsForCase"
    echo -n "\r$steadyRatio,$nearRatio,$bottleNeckRatio,$disasterRate," >> $filePath

    sum=0

    for i in $(seq 1 $testsForCase);
    do
        echo -n -e "\r$i/$testsForCase"
        value=$(./GeneticCompetitiveSalesMan --seed ${i} --time ${timePerTest} --graphSize ${graphSize} --graphMinCost ${minCost} --graphMaxCost ${maxCost} --popSize ${popSize} --mutRate ${mutRate} --steadyRatio ${steadyRatio} --nearRatio ${nearRatio} --bottleNeckRatio ${bottleNeckRatio} --disasterRate ${disasterRate} |tr -d '\n ')
        ((sum=sum+value))
    done
    echo $((sum/testsForCase)) >> $filePath
done
done
done
done
done



