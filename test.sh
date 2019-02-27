#!/bin/bash

cmake CMakeLists.txt -DCMAKE_BUILD_TYPE=Release
make GeneticCompetitiveSalesMan


parProcess=2

filePath="results"
sortedFilePath="results_sorted"

testsForCase="10"


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



echo "starting script test"


echo "popsize,steady,near,bottle,disa,mut,avg " > $filePath
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
        ./GeneticCompetitiveSalesMan --seed ${i} --time ${timePerTest} --graphSize ${graphSize} --graphMinCost ${minCost} --graphMaxCost ${maxCost} --popSize ${popSize} --mutRate ${mutRate} --steadyRatio ${steadyRatio} --nearRatio ${nearRatio} --bottleNeckRatio ${bottleNeckRatio} --disasterRate ${disasterRate}  >> temp1 &
        if ! ((i%$parProcess)); then
	wait
	fi
    done
    wait
    awk '{ total += $1 } END { print total/NR }' temp1 >> $filePath
done
done
done
done
done
done
echo "sorting"
sort -k7 -n -t ',' $filePath > $sortedFilePath
echo "all done"
