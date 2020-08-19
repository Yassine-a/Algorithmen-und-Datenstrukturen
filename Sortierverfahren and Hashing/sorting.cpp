#include "sorting.h"


namespace sorting {

	//************
	// QuickSort *
	//************      
	//Divide and Conquer Alg
	void QuickSort(vector<int> &arr, int left, int right) {
		
			//{cout << "QuickSort(" << "a" << "," << left << "," << right << ")" <<
			//endl; }


		int i = left;
		int j = right;
		int pivot = arr[(left + right) / 2];


		//{	cout << "pivot = a[" << (left + right) / 2 << "] = " << pivot << endl;
		//}
		/* partition */

		while (i <= j) {
			while (pivot > arr[i] && i <= j)
				i++;
			//	if (i > j) break;
			while (pivot < arr[j] && i <= j)
				j--;
			//	if (i > j) break;
			if (i <= j) {
				if(i!=j)cout << "Exchange -  ";
				swap(arr[i], arr[j]);
				
				i++;
				j--;
			}
		};

		//{cout << "Result: "; for (int i = 0; i < arr.size(); i++)cout << arr[i] << " "; cout << endl;
		//}
			/* recursion */

		if (left < j) 	QuickSort(arr, left, j);
		if (i < right)  QuickSort(arr, i, right);


	}

	//************
	// MergeSort *
	//************

	//***************************
	// implement mergesort here *
	//***************************


	void Merge(vector<int> &a, vector<int> &temp, int low, int middle, int high) {
		temp.resize(a.size());
		for (int i = low; i <= high; i++) temp[i] = a[i];

		int i = low;
		int j = middle + 1;
		int c = low;

		//Copy the smallest values from either the left or the right side back to the original array
		while (i <= middle && j <= high)
		{
			if (temp[i] <= temp[j])
			{
				a[c] = temp[i]; 
				i++;
			}
			else 
			{ 
				a[c] = temp[j]; 
				j++; 
			}
			c++;
		}
		// Just copy the rest of the left side of the array into the a Array
		while (i <= middle)
		{
			a[c] = temp[i];
			c++;
			i++;
		}
	}

	void MergeSort(vector<int> &a, vector<int> &temp, int low, int high) {

		//cout << "MergeSort(" << low << "," << high << ")" << endl;
		if (low < high)
		{
			int middle = (high + low) / 2;
			MergeSort(a, temp, low, middle);
			MergeSort(a, temp, middle + 1, high);
			//cout << "MergeSort(" << low << "," << middle <<","<< high << "): " ;
			Merge(a, temp, low, middle, high);
			//for (int i = 0; i <a.size(); i++)cout << a[i] << " "; cout << endl;
		}
	}




	//************
	// Heapsort  *
	//************

	void HeapSort(vector<int> &a, int n) {


		/*cout << "heap sort:" << endl << "durchlauf 0: ";*/

				/*for (int i = 0; i <n; i++)
				{
					cout << a[i] << " ";
				}
				cout << endl;*/

				/*cout << "percdown(" << a[n / 2] << ") ";*/

		for (int i = n / 2; i >= 0; i--) //-1
		{
				/*cout << "percDown(" << a[i] << ") "; cout  << "Durchlauf "<<i<<" : "; for (int i = 0; i <n; i++) {cout << a[i] << " ";}
				cout << endl;*/
			heapify(a, i, n);
		}

			cout << "Heap Sort:" << endl << "Durchlauf 0: ";

			for (int i = 0; i <n; i++)
			{
				cout << a[i] << " ";
			}
			cout << endl;

		//Reconstract the array and replace the first element(the largest) with the last and dec i (forget it)
		for (int i = n - 1; i >= 0; i--)
		{
			/*cout << "percDown(" << a[i] << ") "; cout << "Durchlauf " << i << " : "; for (int i = 0; i <n; i++) { cout << a[i] << " "; }
			cout << endl;*/

			swap(a[0], a[i]);
			heapify(a, 0, i); // i the number of elements left in the array
		}
		for (int i = 0; i <n; i++) { cout << a[i] << " "; } cout << endl;

	}


	void heapify(vector<int> &a, int start, int end)
	{
		int current = start;
		int l = 2 * start + 1;
		int r = 2 * start + 2;
		//  current as root
		// left = 2*i + 1
		// right = 2*i + 2
		// If left child is larger than root ==> Max Heap
		if (l < end && a[l] > a[current])
			current = l;

		// If right child is larger than current so far
		// If current is not root
		////Recursively heapify the affected sub-tree
		if (r < end && a[r] > a[current])
			current = r;


		if (current != start) // nur wenn left oder right > als current, wenn nicht dann las es gut sein
		{
			swap(a[start], a[current]);

			// like a Top-Down Method 
			heapify(a, current, end);
		}
	}



	//************
	// Shellsort *
	//************
	void ShellSort(vector<int> &a, int n)
	{
		int gap = 1;
		while (((2 * gap) + 1) < n)
		{
			gap = 2 * gap;
		}
		gap = 5;
		int k = 0;
		while (gap > 0)
		{
			

			for (int i = gap; i < n; i += 1)
			{
				int temp = a[i];

				int j;
				for (j = i; j >= gap && a[j - gap] > temp; j -= gap) // j muss > als gap sein && 1 > 7 bzw. 2 > 8 ...
				{
					cout << a[j] << " " << a[j - gap] << endl;
					a[j] = a[j - gap];
					
				}

				a[j] = temp;
				
			}
			if (k == 0) {
				k++;
				gap = 3;
			}
			else if (k == 1) {
				gap = 1;
				k++;
			}
			else gap = 0;
			cout << gap << endl;
		}

		cout << "Shell Sort (H = 2H+1)" << endl;
		for (int i = 0; i <n; i++) { cout << a[i] << " "; } cout << endl;


	}

	void getMaxHeap(vector<int>&a) {
		int n = a.size();

		for (int i = (n) / 2; i >= 0; i--)
		{
			int current = i; int l = 2 * i + 1; int r = 2 * i + 2;

			if (l<n&&a[l]>a[current]) current = l;
			if (r<n&&a[r]>a[current]) current = r;

			if (current != i) {
				swap(a[i], a[current]);
				l = current * 2 + 1; 
				r = current * 2 + 2;

				while ( (l < n && a[l] > a[current]) || ( r < n && a[r] > a[current]))
				{
					l = current * 2 + 1; r = current * 2 + 2;
					int j = current;
					if (l<n&&a[l]>a[current]) current = l;
					if (r<n&&a[r]>a[current]) current = r;

					if (current != j) swap(a[j], a[current]);
				}
			}
		}
		for (int i = 0; i < n; i++) { cout << a[i] << " "; } cout << endl;
	}

	void getMaxHeap1(vector<int>&a) {
		int n = a.size();

		for (int i = (n) / 2; i >= 0; i--)
		{
			int current = i; int l = 2 * i + 1; int r = 2 * i + 2;

			if (l<n&&a[l]>a[current]) current = l;
			if (r<n&&a[r]>a[current]) current = r;

			if (current != i) {
				swap(a[i], a[current]);
				getMaxHeap(a);
			}
		}
		for (int i = 0; i < n; i++) { cout << a[i] << " "; } cout << endl;
	}



	void getMinHeap(vector<int>&a) {
		int n = a.size();

		for (int i = (n) / 2; i >= 0; i--)
		{
			int current = i; int l = 2 * i + 1; int r = 2 * i + 2;

			if (l<n&&a[l]<a[current]) current = l;
			if (r<n&&a[r]<a[current]) current = r;

			if (current != i) {
				swap(a[i], a[current]);
				l = current * 2 + 1;
				r = current * 2 + 2;

				while ((l < n && a[l] < a[current]) || (r < n && a[r] < a[current]))
				{
					l = current * 2 + 1; r = current * 2 + 2;
					int j = current;
					if (l<n&&a[l]<a[current]) current = l;
					if (r<n&&a[r]<a[current]) current = r;

					if (current != j) swap(a[j], a[current]);
				}
			}
		}
	
		cout << endl << "MinHeap Final Results"<<endl;
		for (int i = 0; i < n; i++) { cout << a[i] << " "; } cout << endl;
	}


	void insertItem (vector<int>&a, int item) {
		a.push_back(item);
		int n = a.size();

		for (int i = n - 1; i > 0; i = (i - 1) / 2) {
			if (a[i] < a[(i - 1) / 2]) {
				int tmp = a[i];
				a[i] = a[(i - 1) / 2];
				a[(i-1)/2] = tmp;
			}
		}

		cout << endl << "Final Results" << endl;
		for (int i = 0; i < n; i++) { cout << a[i] << " "; } cout << endl;
	}

  void randomizeVector(vector<int> &array, int n) {
    array.resize(n);

    for(unsigned int i=0;i<array.size();i++)
      array[i]=rand() % 1000000;
  }


}





