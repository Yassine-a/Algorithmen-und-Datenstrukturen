#define CATCH_CONFIG_RUNNER
#include "catch.h"

#include <iostream>
#include <omp.h>

#include "sorting.h"
#include "hashtable.h"

using namespace std;

//benchmark functions
void benchmark_quicksort();

int generateRand() { //create random nums
	return rand() % 500 + 1000; //random numbers from 1 to 9999
}

int main(int argc, char** argv) {

	int n = 200;
	HashTable hash(1000);
	vector<unsigned int> vals(500);
	
	srand(time(NULL));
	for (int i = 0; i < 500; i++) vals[i] = generateRand();

	

	random_shuffle(vals.begin(), vals.end());

	for (int i = 0; i < n; i++)
		hash.insert(vals[i]);

	cout << "# Colisions: " << hash.getCollisionCount() << endl;

	std::vector<int> V{ 10,5,9,4,8,3,7,2,6,1 };
	std::vector<int> a(V);
	sorting::QuickSort(a, 0, 9);
	//sorting::HeapSort(a, a.size());
	//sorting::getMaxHeap(a);
	//sorting::getMinHeap(a);
	//sorting::insertItem(a,15);

  Catch::Session().run();
  std::cin.get();


  benchmark_quicksort();
}




//executes benchmark for quicksort
void benchmark_quicksort() {

 // //file stream
 // ofstream quicksort_measurement;
 // quicksort_measurement.open("quicksort.txt", ios::out | ios::app);

 // //benchmark parameters / variables
 // double dtime;
 // int n_start = 1000;
 // int n_step = 1000;
 // int n_end = 1000000;

 // vector<int> V;

 // //actual benchmark loop
 // for (int n = n_start; n<=n_end; n += n_step) {
	//
	////"progress bar"
 //   std::cout << "Running Quicksort with n: " << n << std::endl;

	////generate n random integers
	//sorting::randomizeVector(V, n);

	////start measurement
 //   dtime = omp_get_wtime();
 //   
	////execzute sorting algorithm
 //   sorting::QuickSort(V,0,V.size()-1);

	////stop time
 //   dtime = omp_get_wtime() - dtime;

	////write to file
 //   quicksort_measurement << n << "\t" << setprecision(10) << scientific << dtime << endl;
 // }

 // //close file handle
 // quicksort_measurement.close();


}

