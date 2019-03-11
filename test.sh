#!/bin/bash

parProcess=4

filePath="results"
sortedFilePath="results_sorted"

testsForCase="4"


computeBenchmark="true"
timePerBenchmark="10000"

timePerTest="1000"
graphSize="20"
minCost="1"
maxCost="1000"

popSizeSet="1000"
steadyRatioSet="0.01 0.2 0.5 0.7 0.9"
mutRateSet="0 0.1 0.5 0.7 1"
nearRatioSet="0"
bottleNeckRatioSet="0 0.01 0.05 0.1 0.5"
disasterRateSet="0"


cmake CMakeLists.txt -DCMAKE_BUILD_TYPE=Release
make GeneticCompetitiveSalesMan


echo "starting script test"


if [ $computeBenchmark = true ] ; then
	echo "benchMark computation"
	echo -n "0/$testsForCase"
	echo -e -n " " > benchMark
    for i in $(seq 1 ${testsForCase});
    do
            ./GeneticCompetitiveSalesMan --seed ${i} --time ${timePerBenchmark} --graphSize ${graphSize} --graphMinCost ${minCost} --graphMaxCost ${maxCost} --greedy --popSize 1000 --mutRate 0.5 --steadyRatio 0.7 --nearRatio 0 --bottleNeckRatio 0.1 --disasterRate 0.01 | awk -v i=${i} '{print $2","i}' >> benchmark &
			pidV[${i}]=$!
    done
    for i in $(seq 1 ${testsForCase});
    do
		wait ${pidV[$i]}
		echo -n -e "\r$i/$testsForCase"
	done
	cat benchmark | sort -k2 -n -t "," |column -s "," -t| awk '{print $1" "$2}' > benchmark
	for i in $(awk '{print $1}' benchmark);
	do
	    bench[${i}]=${i}
	    echo ${bench[${i}]}
	done
	echo -e "\n"
	echo "benchMark Done"
fi



echo "popsize,steady,near,bottle,disa,mut,turn,avg,avgRel,stDev " > $filePath
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

    rm temp1
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
	var=$(awk -v sep=',' 'BEGIN{ORS=OFS="";for(i=1;i<ARGC;i++){print ARGV[i],sep}}' "${bench[@]}")
    awk -v arr=${var} 'BEGIN{ORS=",";arr=split(arr,ben,",")}{ total += $2;totalRel += $2/(ben[FNR]);totalSq += ($2/(ben[FNR])*$2/(ben[FNR]))} END { print total/NR; print totalRel/NR; print (totalSq - ((totalRel)*(totalRel))/NR)/NR}' temp1 >> $filePath
	echo -n -e "\n" >> $filePath
done
done
done
done
done
done
echo "sorting"
sort -k9 -g -t ',' $filePath > $sortedFilePath
echo "all done"
