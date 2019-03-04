#!/bin/bash

parProcess=2

filePath="results"
sortedFilePath="results_sorted"

testsForCase="10"


computeBenchmark=true
timePerBenchmark="100000"

timePerTest="1000"
graphSize="20"
minCost="1"
maxCost="1000"

popSizeSet="100 1000 5000 10000"
steadyRatioSet="0.01 0.2 0.5 0.7 0.9"
mutRateSet="0 0.1 0.5 0.7 1"
nearRatioSet="0"
bottleNeckRatioSet="0 0.01 0.05 0.1 0.5"
disasterRateSet="0 0.01 0.05 0.1 0.5"


cmake CMakeLists.txt -DCMAKE_BUILD_TYPE=Release
make GeneticCompetitiveSalesMan


echo "starting script test"

echo "benchMark computation"
if (${computeBenchmark}==1); then
    for i in $(seq 1 ${testsForCase});
    do
            ./GeneticCompetitiveSalesMan --seed ${i} --time ${timePerBenchmark} --graphSize ${graphSize} --graphMinCost ${minCost} --graphMaxCost ${maxCost} --greedy --popSize 1000 --mutRate 0.5 --steadyRatio 0.7 --nearRatio 0 --bottleNeckRatio 0.1 --disasterRate 0.01 | cat " ${i}"  >> benchmark &

    done
fi

echo "popsize,steady,near,bottle,disa,mut,turn,avg " > $filePath
for popSize in ${popSizeSet};
do
for steadyRatio in ${steadyRatioSet};
do
for nearRatio in ${nearRatioSet}
do
for bottleNeckRatio in ${bottleNeckRatioSet}
do
for disasterRate in ${disasterRateSet}

do
for mutRate in ${mutRateSet}
do
    echo -e "\r$popSize,$steadyRatio,$nearRatio,$bottleNeckRatio,$disasterRate,$mutRate"
    echo -n "0/$testsForCase"
    echo -n "$popSize,$steadyRatio,$nearRatio,$bottleNeckRatio,$disasterRate,$mutRate," >> $filePath

    echo > temp1
    for i in $(seq 1 $testsForCase);
    do
        echo -n -e "\r$i/$testsForCase"
        ./GeneticCompetitiveSalesMan --seed ${i} --time ${timePerTest} --graphSize ${graphSize} --graphMinCost ${minCost} --graphMaxCost ${maxCost} --greedy --popSize ${popSize} --mutRate ${mutRate} --steadyRatio ${steadyRatio} --nearRatio ${nearRatio} --bottleNeckRatio ${bottleNeckRatio} --disasterRate ${disasterRate}  >> temp1 &
        if ! ((i%$parProcess)); then
	        wait
	    fi
    done
    wait
    awk 'BEGIN{ORS=","}{ total += $1 } END { print total/NR }' temp1 >> $filePath
    echo -n -e " " >> $filePath
    awk 'BEGIN{ORS="\n"}{ total += $2 } END { print total/NR }' temp1 >> $filePath
done
done
done
done
done
done
echo "sorting"
sort -k8 -g -t ',' $filePath > $sortedFilePath
echo "all done"
