#!/bin/bash
count=0;
total=0; 
if (($#<2)); #[1]prints user msg if not provided two filenames
then
   echo "1.not provided two filenames required.provide\"(infilename outfilename)\"in this format.\n2.Also only names should be given not with extensions of file(ex: college should be given as filename not college.csv)\n 3.so exitting"
   exit 1
fi


if [ !  -f "$1".csv ]; #checks if inputfile exists or not (if not prints appropriate msg)
then
  echo "input file does not exists"
  exit 1
fi

#[3]prints the columns of mentioned file with spaces in between them in output file 
INPUT="$1".csv
OLDIFS=$IFS
IFS=','
[ ! -f $INPUT ] && { echo "$INPUT file not found"; exit 99; }
while read  Name PredominantDegree HighestDegree FundingModel Region Geography AdmissionRate ACTMedian SATAverage AverageCost Expenditure AverageFacultySalary MedianDebt AverageAgeofEntry MedianFamilyIncome MedianEarnings 
do      
       
       
    echo "$Name $PredominantDegree $HighestDegree $Region $Geography $AdmissionRate $AverageCost $Expenditure " >> "$2".txt  
done < $INPUT
if [[ $Name != "" ]] ; then
    echo "$Name $PredominantDegree $HighestDegree $Region $Geography $AdmissionRate $AverageCost $Expenditure " >> "$2".txt  
fi 
IFS=$OLDIFS
echo -e "\n" >> "$2".txt

#[4]the script should save the Name of the college whose HighestDegree is Bachelor’s to the output file

INPUT="$1".csv
OLDIFS=$IFS
IFS=','
[ ! -f $INPUT ] && { echo "$INPUT file not found"; exit 99; }
while read  Name PredominantDegree HighestDegree FundingModel Region Geography AdmissionRate ACTMedian SATAverage AverageCost 
do      
       if [ $HighestDegree ==  "Bachelor's" ];
       then 
	     echo "$Name" >> "$2".txt
	     
	fi 
	if [ $Geography == "Mid-size City" ];
	then 
	   a+=($AdmissionRate)
	fi
	if [ $Geography == "Small City" ];
	then 
	   b+=($AdmissionRate)
	fi
	if [ $Geography == "Remote Rural" ];
	then 
	   c+=($AdmissionRate)
	fi
	if [ $Geography == "Fringe Rural" ];
	then 
	   d+=($AdmissionRate)
	fi
	if [ $Geography == "Large Suburb" ];
	then 
	   e+=($AdmissionRate)
	fi
	if [ $Geography == "Distant Town" ];
	then 
	   f+=($AdmissionRate)
	fi
	if [ $Geography == "Large City" ];
	then 
	   g+=($AdmissionRate)
	fi
	if [ $Geography == "Remote Town" ];
	then 
	   h+=($AdmissionRate)
	fi
	if [ $Geography == "Small Suburb" ];
	then 
	   j+=($AdmissionRate)
	fi
	if [ $Geography == "Mid-size Suburb" ];
	then 
	   k+=($AdmissionRate)
	fi
	if [ $Geography == "Fringe Town" ];
	then 
	   l+=($AdmissionRate)
	fi
	if [ $Geography == "Distant Rural" ];
	then 
	   m+=($AdmissionRate)
	fi
	
done < $INPUT
if [[ $Name != "" ]] ; then
if [ $HighestDegree ==  "Bachelor's" ];
       then 
	     echo "$Name" >> "$2".txt
	     
	fi 
	if [ $Geography == "Mid-size City" ];
	then 
	   a+=($AdmissionRate)
	fi
	if [ $Geography == "Small City" ];
	then 
	   b+=($AdmissionRate)
	fi
	if [ $Geography == "Remote Rural" ];
	then 
	   c+=($AdmissionRate)
	fi
	if [ $Geography == "Fringe Rural" ];
	then 
	   d+=($AdmissionRate)
	fi
	if [ $Geography == "Large Suburb" ];
	then 
	   e+=($AdmissionRate)
	fi
	if [ $Geography == "Distant Town" ];
	then 
	   f+=($AdmissionRate)
	fi
	if [ $Geography == "Large City" ];
	then 
	   g+=($AdmissionRate)
	fi
	if [ $Geography == "Remote Town" ];
	then 
	   h+=($AdmissionRate)
	fi
	if [ $Geography == "Small Suburb" ];
	then 
	   j+=($AdmissionRate)
	fi
	if [ $Geography == "Mid-size Suburb" ];
	then 
	   k+=($AdmissionRate)
	fi
	if [ $Geography == "Fringe Town" ];
	then 
	   l+=($AdmissionRate)
	fi
	if [ $Geography == "Distant Rural" ];
	then 
	   m+=($AdmissionRate)
	fi
fi
count=0;
total=0; 
#[5]grouping  the colleges with respect to Geography Column of the dataset and each groups admission rates are saved into arrays/lists
#computing the averages of all groups
for i in ${a[@]}
   do 
     total=$(echo $total+$i | bc )
     ((count++))
   done
x0=$(echo "scale=4; $total / $count" | bc ) 
count=0;
total=0;
for i in ${b[@]}
   do 
     total=$(echo $total+$i | bc )
     ((count++))
   done
x1=$(echo "scale=4; $total / $count" | bc )
count=0;
total=0;
 for i in ${c[@]}
   do 
     total=$(echo $total+$i | bc )
     ((count++))
   done
x2=$(echo "scale=4; $total / $count" | bc )
count=0;
total=0;
 for i in ${d[@]}
   do 
     total=$(echo $total+$i | bc )
     ((count++))
   done
x3=$(echo "scale=4; $total / $count" | bc)  
count=0;
total=0;
for i in ${e[@]}
   do 
     total=$(echo $total+$i | bc )
     ((count++))
   done
x4=$(echo "scale=4; $total / $count" | bc ) 
count=0;
total=0;
for i in ${f[@]}
   do 
     total=$(echo $total+$i | bc )
     ((count++))
   done
x5=$(echo "scale=4; $total / $count" | bc) 
count=0;
total=0; 
for i in ${g[@]}
   do 
     total=$(echo $total+$i | bc )
     ((count++))
   done
x6=$(echo "scale=4; $total / $count" | bc)  
count=0;
total=0;
for i in ${h[@]}
   do 
     total=$(echo $total+$i | bc )
     ((count++))
   done
x7=$(echo "scale=4; $total / $count" | bc )
count=0;
total=0;
for i in ${j[@]}
   do 
     total=$(echo $total+$i | bc )
     ((count++))
   done
x8=$(echo "scale=4; $total / $count" | bc )
count=0;
total=0;
for i in ${k[@]}
   do 
     total=$(echo $total+$i | bc )
     ((count++))
   done
x9=$(echo "scale=4; $total / $count" | bc  )
count=0;
total=0;
for i in ${l[@]}
   do 
     total=$(echo $total+$i | bc )
     ((count++))
   done
x10=$(echo "scale=4; $total / $count" | bc  )
count=0;
total=0;
for i in ${m[@]}
   do 
     total=$(echo $total+$i | bc )
     ((count++))
   done
x11=$(echo "scale=4; $total / $count" | bc  )

echo -e "\n" >> "$2".txt
echo "Geography: Average Admission Rate" >> "$2".txt
echo "Mid-size City: $x0" >> "$2".txt
echo "Small City: $x1" >> "$2".txt
echo "Remote Rural: $x2" >> "$2".txt
echo "Fringe Rural: $x3" >> "$2".txt
echo "Large Suburb: $x4" >> "$2".txt
echo "Distant Town: $x5" >> "$2".txt
echo "Large City: $x6"  >> "$2".txt
echo "Remote Town: $x7"  >> "$2".txt
echo "Small Suburb: $x8" >> "$2".txt
echo "Mid-size Suburb: $x9" >> "$2".txt
echo "Fringe Town: $x10" >> "$2".txt
echo "Distant Rural: $x11" >> "$2".txt


#[6]sorts the rows according to column of median earnings and stores it into dum.txt file
sort -k 16 -t , -n -r  "$1".csv > dum.txt
echo -e "\n" >> "$2".txt
echo "Top five colleges having maximum MedianEarnings:" >> "$2".txt
r=0
INPUT=dum.txt
OLDIFS=$IFS
IFS=','
#prints the top five colleges having max medianearnings to output file
[ ! -f $INPUT ] && { echo "$INPUT file not found"; exit 99; }
while read Name PredominantDegree HighestDegree FundingModel Region Geography AdmissionRate ACTMedian SATAverage AverageCost
do
   echo $Name >> "$2".txt
   ((r++))
   if [[ "$r" == '5' ]];
   then break
    fi
done < $INPUT
   
