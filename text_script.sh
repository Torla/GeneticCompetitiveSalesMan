#!/bin/bash

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
	value=$(./GeneticCompetitiveSalesMan $i |tr -d '\n ')
	((sum=sum+value))
	echo  $value >> $filePath
done


echo -e "\n$((sum/10))"
