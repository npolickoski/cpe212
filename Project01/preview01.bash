#!/bin/bash 

#
# preview01.bash   CPE212 Spring2019 Project01 -- Review
#

#if [ ! -e ./project01 ]
if [ $# -ne 3 ]
then
   #echo "Error: your project01 executable was not found"
   echo "Error: Incorrect argument list"
   echo "Usage: preview01.bash <your executable> <tests directory> <reference executable>"
else
   echo
   echo "***********************************************"
   echo "** WARNING:                                  **"
   echo "**   Use of preview01 is NO SUBSTITUE for    **"
   echo "**   thoroughly testing your own code prior  **"
   echo "**   to submission of your work for grading. **"
   echo "**   Your actual grade may be LOWER than     **"
   echo "**   that suggested by preview01.            **"
   echo "***********************************************"
   echo   
   echo "preview01:"
   echo "For each file of test inputs, this script will execute"
   echo "your program and the sample solution and print just"
   echo "the lines of output where your program produces "
   echo "DIFFERENT output than the sample solution. "
   echo
   echo "Your program's output appears on the left and the sample"
   echo "solution's output will appear on the right."
   echo

   # Set initial number of points earned
   score=0
   possible=0

   for testname in $(ls $2/tests/p01input*.txt)
   do
      # Pick two file names
      file1=./$RANDOM.txt
      file2=./$RANDOM.txt

      # Execute student program
      (ulimit -t 3; 
       ulimit -f 100; 
       $1 $testname > $file1)
      result=$?

      # Increment possible score
      let "possible = possible + 1"

      if [ $result != 0 ]
      then
         echo "FAILED $testname"
      else
         # Execute sample solution
         $3 $testname > $file2


         # Write output differences to stdout
         echo
         echo
         echo "**************  Start of $testname  ***************"
         echo
         sdiff -bBWis $file1  $file2

         # Compare student program output to sample solution output
         delta=`sdiff -bBWis $file1  $file2 | wc -l`


         # Determine PASS-FAIL status
         echo
         if [ $delta == 0 ]
         then
            echo "PASSED $testname"
            let "score = score + 1"
         else
            echo "FAILED $testname"
         fi
         echo
         echo "***************  End of $testname   ****************"
         echo
         echo
    fi

    rm $file1 $file2

   done

   echo "Estimated Score = $score out of $possible possible points"

  echo
fi


