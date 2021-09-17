# Tester_Simple_Sorting_Algorithms

Author: Katarzyna Miałkowska

## Contents ##

1) generator.cxx
- Generates random output, assuming in the argument:
<data amount> <maximum range>

2) bubble.cxx
- Bubble sort implementation.

3) selection.cxx
- Implement selection sort.

4) counting.cxx
- Implement counting sort.

5) insertion.cxx
- Implementation insertion sort.

6) radix.cxx
- Implementation of positional sort. Using the queue.hxx implementation.

7) queue.hxx
- Implementation of the queue.

5) stdsort.cxx
- Implementing sort using std :: sort.

6) tester.cxx
- Tester implementation.

7) tester.hxx
- Includes sort functions.

8) gnuplot.hxx
- The class needed to generate a plot using the gnuplot program.

7) Makefile
- Contains program compilations and run tester.cxx.

## Makefile ##

- In order to compile all programs,, execute:
 make all
- To clean the contents of unnecessary files, execute:
make clean
- To run the tester, execute:
make test

## Tester ##

The tester program compares all of the above sort implementations in time and generates chart.

1) tester.cxx 
- tester implementation that calls all sorting implementations for n random operations:
n = 10,000, 20,000, 80,000, 160,000.
Displays the execution time for each sort, then generates a graph showing the
visually, the time of sorting for n data. The chart will be in the graphs.pdf file

2) tester.hxx 
- contains all sort implementations and generator.

3) gnuplot.hxx 
- the class needed to generate a chart using the gnuplot program.
