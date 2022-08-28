// C++ program for building Heap from Array
#include <iostream>
using namespace std;


void minHeapify(int arr[], int n, int i) 
{
	int l = 2 * i + 1; 
	int r = 2 * i + 2; 
    int smallest = i;
    if (l < n && arr[l] < arr[i]) smallest = l;
    if (r < n && arr[r] < arr[smallest]) smallest = r;
    if (smallest != i) {
        swap(arr[i], arr[smallest]);
        minHeapify(arr, n, smallest);
    }
}

/*
T.C. : O(n)
*/
void buildHeap(int arr[], int n)
{
	int startIdx = (n / 2) - 1;			//get bottommost rightmost index
	for (int i = startIdx; i >= 0; i--) {
		minHeapify(arr, n, i);
	}
}


void printHeap(int arr[], int n)
{
	cout << "Array representation of Heap is:\n";

	for (int i = 0; i < n; ++i)
		cout << arr[i] << " ";
	cout << "\n";
}


int main()
{
	//Input Array
	int arr[] = {10, 5, 20, 2, 4, 8};

	int n = sizeof(arr) / sizeof(arr[0]);

	buildHeap(arr, n);

	printHeap(arr, n);


	return 0;
}
