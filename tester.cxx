#include "tester.hxx"
#include "gnuplot.hxx"

void test_sort_10k();
void test_sort_20k();
void test_sort_80k();
void test_sort_160k();

std::ofstream Bdata, Sdata, Idata, Cdata, Rdata, STDdata;
std::string BubblePlot("Bdata.dat");
std::string SelectionPlot("Sdata.dat");
std::string InsertionPlot("Idata.dat");
std::string CountingPlot("Cdata.dat");
std::string RadixPlot("Rdata.dat");
std::string StdPlot("STDdata.dat");
std::string name_graphs("graphs");
std::string type("pdf");

int main(){
   
    /*data needed for charts */
    Bdata.open (BubblePlot, std::ios::out | std::ios::app); 
    Sdata.open (SelectionPlot, std::ios::out | std::ios::app); 
    Idata.open (InsertionPlot, std::ios::out | std::ios::app); 
    Cdata.open (CountingPlot, std::ios::out | std::ios::app); 
    Rdata.open (RadixPlot, std::ios::out | std::ios::app); 
    STDdata.open (StdPlot, std::ios::out | std::ios::app);

    test_sort_10k();
    test_sort_20k();
    test_sort_80k();
    test_sort_160k();

    /*create a chart*/
    gnuplot p;
    std::string setB("\'./" + BubblePlot + "\' u 1:2 w l");
    std::string setS("\'./" + SelectionPlot + "\' u 1:2 w l");
    std::string setI("\'./" + InsertionPlot + "\' u 1:2 w l");
    std::string setC("\'./" + CountingPlot + "\' u 1:2 w l");
    std::string setR("\'./" + RadixPlot + "\' u 1:2 w l");
    std::string setSTD("\'./" + StdPlot + "\' u 1:2 w l");

    p("set terminal " + type);
    p("set output \"" + name_graphs + '.' + type + "\""); 
    p("set xlabel 'data'");
    p("set ylabel 't/s'");
    p("set title 'sortowanie proste'");

        p("set xrange [0:160000]");
        p("set yrange [0:0.01]");
    p("plot " + setB + " , " + setS + " , " + setI + " , " + setC + " , " + setR + " , " + setSTD);
        p("set xrange [0:160000]");
        p("set yrange [0:1]");
    p("plot " + setB + " , " + setS + " , " + setI + " , " + setC + " , " + setR + " , " + setSTD);
        p("set xrange [0:160000]");
        p("set yrange [0:10]");
    p("plot " + setB + " , " + setS + " , " + setI + " , " + setC + " , " + setR + " , " + setSTD);
        p("set xrange [0:160000]");
        p("set yrange [0:600]");
    p("plot " + setB + " , " + setS + " , " + setI + " , " + setC + " , " + setR + " , " + setSTD);


    //p("plot \'./b.dat\' u 1:2 w l ");
    //p("plot 'a.dat'");
    // p("set term postscript eps");
    // p("set output \"a.eps\" ");
    // p("plot \'./a.dat\' u 1:2 w l ");




    Bdata.close();
    Sdata.close();
    Idata.close();
    Cdata.close();
    Rdata.close();
    STDdata.close();

    // test the sorts by giving copies of random numbers to the programs,

    /*test for 10000 data*/
   
    return 0;
}

void test_sort_10k(){
    std::vector<int> gen10000;
    int gen = 10000;
     // generate numbers to the vector
    generator(gen10000, gen, 10000);

    std::cout << "\t-TEST 10000 n-\n";

    /*test bubble sort for 10000 random number*/
    auto Bstart = std::chrono::high_resolution_clock::now();
        bubble(gen10000);
    auto Bend = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> bubbleElapsed = Bend - Bstart;
    std::cerr << "Bubble elapsed time[s] =" << bubbleElapsed.count() << std::endl;
        Bdata << gen << '\t' << bubbleElapsed.count() << '\n';

    /*test selection sort for 10000 random number*/
    auto Sstart = std::chrono::high_resolution_clock::now();
        selection(gen10000);
    auto Send = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> selectionElapsed = Send - Sstart;
    std::cerr << "Selection elapsed time[s] =" << selectionElapsed.count() << std::endl;
        Sdata << gen << '\t' << selectionElapsed.count() << '\n';

   /*test insertion sort for 10000 random number*/
    auto Istart = std::chrono::high_resolution_clock::now();
        insertion(gen10000);
    auto Iend = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> insertionElapsed = Iend - Istart;
    std::cerr << "Insertion elapsed time[s] =" << insertionElapsed.count() << std::endl;
        Idata << gen << '\t' << insertionElapsed.count() << '\n';

    /*test counting sort for 10000 random number*/
    auto Cstart = std::chrono::high_resolution_clock::now();
        counting(gen10000);
    auto Cend = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> countingElapsed = Cend - Cstart;
    std::cerr << "Counting elapsed time[s] =" << countingElapsed.count() << std::endl;
        Cdata << gen << '\t' << countingElapsed.count() << '\n';

     /*test radix sort for 10000 random number*/
    auto Rstart = std::chrono::high_resolution_clock::now();
        radix(gen10000);
    auto Rend = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> radixElapsed = Rend - Rstart;
    std::cerr << "Radix elapsed time[s] =" << radixElapsed.count() << std::endl;
        Rdata << gen << '\t' << radixElapsed.count() << '\n';

     /*test std::sort sort for 10000 random number*/
    auto STDstart = std::chrono::high_resolution_clock::now();
        stdsort(gen10000);
    auto STDend = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> stdsortElapsed = STDend - STDstart;
    std::cerr << "std::sort elapsed time[s] =" << stdsortElapsed.count() << std::endl;
        STDdata << gen << '\t' << stdsortElapsed.count() << '\n';
}

void test_sort_20k(){
    std::vector<int> gen20000;
    int gen = 20000;
    // generate numbers to the vector
    generator(gen20000, gen, 10000);

    std::cout << "\t-TEST 20000 n-\n";

    /*test bubble sort for 20000 random number*/
    auto Bstart = std::chrono::high_resolution_clock::now();
        bubble(gen20000);
    auto Bend = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> bubbleElapsed = Bend - Bstart;
    std::cerr << "Bubble elapsed time[s] =" << bubbleElapsed.count() << std::endl;
        Bdata << gen << '\t' << bubbleElapsed.count() << '\n';

    /*test selection sort for 20000 random number*/
    auto Sstart = std::chrono::high_resolution_clock::now();
        selection(gen20000);
    auto Send = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> selectionElapsed = Send - Sstart;
    std::cerr << "Selection elapsed time[s] =" << selectionElapsed.count() << std::endl;
        Sdata << gen << '\t' << selectionElapsed.count() << '\n';

   /*test insertion sort for 20000 random number*/
    auto Istart = std::chrono::high_resolution_clock::now();
        insertion(gen20000);
    auto Iend = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> insertionElapsed = Iend - Istart;
    std::cerr << "Insertion elapsed time[s] =" << insertionElapsed.count() << std::endl;
        Idata << gen << '\t' << insertionElapsed.count() << '\n';

    /*test counting sort for 20000 random number*/
    auto Cstart = std::chrono::high_resolution_clock::now();
        counting(gen20000);
    auto Cend = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> countingElapsed = Cend - Cstart;
    std::cerr << "Counting elapsed time[s] =" << countingElapsed.count() << std::endl;
        Cdata << gen << '\t' << countingElapsed.count() << '\n';

     /*test radix sort for 20000 random number*/
    auto Rstart = std::chrono::high_resolution_clock::now();
        radix(gen20000);
    auto Rend = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> radixElapsed = Rend - Rstart;
    std::cerr << "Radix elapsed time[s] =" << radixElapsed.count() << std::endl;
        Rdata << gen << '\t' << radixElapsed.count() << '\n';

     /*test std::sort sort for 20000 random number*/
    auto STDstart = std::chrono::high_resolution_clock::now();
        stdsort(gen20000);
    auto STDend = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> stdsortElapsed = STDend - STDstart;
    std::cerr << "std::sort elapsed time[s] =" << stdsortElapsed.count() << std::endl;
        STDdata << gen << '\t' << stdsortElapsed.count() << '\n';
}

void test_sort_80k(){
    std::vector<int> gen80000;
    int gen = 80000;
    // generate numbers to the vector
    generator(gen80000, gen, 10000);

    std::cout << "\t-TEST 80000 n-\n";

    /*test bubble sort for 80000 random number*/
    auto Bstart = std::chrono::high_resolution_clock::now();
        bubble(gen80000);
    auto Bend = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> bubbleElapsed = Bend - Bstart;
    std::cerr << "Bubble elapsed time[s] =" << bubbleElapsed.count() << std::endl;
        Bdata << gen << '\t' << bubbleElapsed.count() << '\n';

    /*test selection sort for 80000 random number*/
    auto Sstart = std::chrono::high_resolution_clock::now();
        selection(gen80000);
    auto Send = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> selectionElapsed = Send - Sstart;
    std::cerr << "Selection elapsed time[s] =" << selectionElapsed.count() << std::endl;
        Sdata << gen << '\t' << selectionElapsed.count() << '\n';
        
   /*test insertion sort for 80000 random number*/
    auto Istart = std::chrono::high_resolution_clock::now();
        insertion(gen80000);
    auto Iend = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> insertionElapsed = Iend - Istart;
    std::cerr << "Insertion elapsed time[s] =" << insertionElapsed.count() << std::endl;
        Idata << gen << '\t' << insertionElapsed.count() << '\n';

    /*test counting sort for 80000 random number*/
    auto Cstart = std::chrono::high_resolution_clock::now();
        counting(gen80000);
    auto Cend = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> countingElapsed = Cend - Cstart;
    std::cerr << "Counting elapsed time[s] =" << countingElapsed.count() << std::endl;
        Cdata << gen << '\t' << countingElapsed.count() << '\n';

     /*test radix sort for 80000 random number*/
    auto Rstart = std::chrono::high_resolution_clock::now();
        radix(gen80000);
    auto Rend = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> radixElapsed = Rend - Rstart;
    std::cerr << "Radix elapsed time[s] =" << radixElapsed.count() << std::endl;
        Rdata << gen << '\t' << radixElapsed.count() << '\n';

     /*test std::sort sort for 80000 random number*/
    auto STDstart = std::chrono::high_resolution_clock::now();
        stdsort(gen80000);
    auto STDend = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> stdsortElapsed = STDend - STDstart;
    std::cerr << "std::sort elapsed time[s] =" << stdsortElapsed.count() << std::endl;
        STDdata << gen << '\t' << stdsortElapsed.count() << '\n';
}

void test_sort_160k(){
    std::vector<int> gen160000;
    int gen = 160000;
    // generate numbers to the vector
    generator(gen160000, gen, 10000);

    std::cout << "\t-TEST 160000 n-\n";

    /*test bubble sort for 160000 random number*/
    auto Bstart = std::chrono::high_resolution_clock::now();
        bubble(gen160000);
    auto Bend = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> bubbleElapsed = Bend - Bstart;
    std::cerr << "Bubble elapsed time[s] =" << bubbleElapsed.count() << std::endl;
        Bdata << gen << '\t' << bubbleElapsed.count() << '\n';

    /*test selection sort for 160000 random number*/
    auto Sstart = std::chrono::high_resolution_clock::now();
        selection(gen160000);
    auto Send = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> selectionElapsed = Send - Sstart;
    std::cerr << "Selection elapsed time[s] =" << selectionElapsed.count() << std::endl;
        Sdata << gen << '\t' << selectionElapsed.count() << '\n';

   /*test insertion sort for 160000 random number*/
    auto Istart = std::chrono::high_resolution_clock::now();
        insertion(gen160000);
    auto Iend = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> insertionElapsed = Iend - Istart;
    std::cerr << "Insertion elapsed time[s] =" << insertionElapsed.count() << std::endl;
        Idata << gen << '\t' << insertionElapsed.count() << '\n';

    /*test counting sort for 160000 random number*/
    auto Cstart = std::chrono::high_resolution_clock::now();
        counting(gen160000);
    auto Cend = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> countingElapsed = Cend - Cstart;
    std::cerr << "Counting elapsed time[s] =" << countingElapsed.count() << std::endl;
        Cdata << gen << '\t' << countingElapsed.count() << '\n';

     /*test radix sort for 160000 random number*/
    auto Rstart = std::chrono::high_resolution_clock::now();
        radix(gen160000);
    auto Rend = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> radixElapsed = Rend - Rstart;
    std::cerr << "Radix elapsed time[s] =" << radixElapsed.count() << std::endl;
        Rdata << gen << '\t' << radixElapsed.count() << '\n';

     /*test std::sort sort for 160000 random number*/
    auto STDstart = std::chrono::high_resolution_clock::now();
        stdsort(gen160000);
    auto STDend = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> stdsortElapsed = STDend - STDstart;
    std::cerr << "std::sort elapsed time[s] =" << stdsortElapsed.count() << std::endl;
        STDdata << gen << '\t' << stdsortElapsed.count() << '\n';
}