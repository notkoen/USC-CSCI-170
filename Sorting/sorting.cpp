//==============================
// Name: Aaron K.
// Class: USC CSCI-170
// Assignment: Sorting
// Date: 3/25/2022
//------------------------------

#include <iostream>
#include <ctime>

using namespace std;

void InsertionSort(int arr[], int len) {
    int i, j, k;
    for(i = 1; i < len; i++) {
        j = arr[i];
        k = i - 1;
        while(k >= 0 && arr[k] > j) {
            arr[k + 1] = arr[k];
            k = k - 1;
        }
        arr[k + 1] = j;
    }
}

void Merge(int arr[], int low, int mid, int high) {
    int k;
    int n1 = mid - low + 1;
    int n2 =  high - mid;

    // Create temp arrays
    int L[n1], R[n2];

    // Copy data to temp arrays L[] and R[]
    for(int i = 0; i < n1; i++)
        L[i] = arr[low + i];
    for(int j = 0; j < n2; j++)
        R[j] = arr[mid + 1 + j];

    // Merge the temp arrays back into arr[l..r]
    int i = 0;
    int j = 0;
    k = low;
    
    while(i < n1 && j < n2) {
        if(L[i] <= R[j]) {
            arr[k] = L[i];
            i++;
        }
        else {
            arr[k] = R[j];
            j++;
        }
        k++;
    }

    // Copy the remaining elements of L[], if there are any
    while(i < n1) {
        arr[k] = L[i];
        i++;
        k++;
    }

    // Copy the remaining elements of R[], if there are any
    while(j < n2) {
        arr[k] = R[j];
        j++;
        k++;
    }
}

void MergeSort(int arr[], int low, int high) {
    if (low < high) {
        // Same as (l+r)/2 but avoids overflow for large l & h
        int m = low + (high - low) / 2;
        MergeSort(arr, low, m);
        MergeSort(arr, m + 1, high);
        Merge(arr, low, m, high);
    }
}

//Do not change the main function.
int main(int argc, char* argv[]) {
    int n;
    clock_t start;
    double durationI = 0, durationM = 0;

    cin >> n;
    int *arr = new int[n];
    int *backup = new int[n];
    for(int i = 0; i < n; i++) {
        if(n < 100)
            cin >> arr[i];
        else
            arr[i] = n-i;
        backup[i] = arr[i];
    }
    
    start = clock();
    InsertionSort(arr, n);
    durationI += (clock() - start) / (double)CLOCKS_PER_SEC;
    
    if(n < 100) {
        for(int i = 0; i < n; i++)
            cout << arr[i] << " ";
    }
    
    for(int j = 0; j < n; j++)
        arr[j] = backup[j];

    start = clock();
    MergeSort(arr, 0, n-1);
    durationM += (clock() - start) / (double)CLOCKS_PER_SEC;

    if(n < 100) {
        for(int i = 0; i < n; i++)
            cout << arr[i] << " ";
        cout << endl;
    }

    if(n >= 100) {
        cout << "MergeSort on " << n << " elements took " << durationM << " seconds." << endl;
        cout << "InsertionSort took " << durationI << " seconds." << endl;
    }
    
    delete [] arr;
    delete [] backup;
	return 0;
}