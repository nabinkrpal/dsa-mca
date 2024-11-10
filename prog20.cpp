#include <iostream>
using namespace std;

void merge(int arr[], int left, int mid, int right) {
    int n1 = mid - left + 1;
    int n2 = right - mid;
    
    int L[n1], R[n2];

    for (int i = 0; i < n1; i++) L[i] = arr[left + i];
    for (int j = 0; j < n2; j++) R[j] = arr[mid + 1 + j];

    int i = 0, j = 0, k = left;
    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            arr[k] = L[i];
            i++;
        } else {
            arr[k] = R[j];
            j++;
        }
        k++;
    }

    while (i < n1) {
        arr[k] = L[i];
        i++;
        k++;
    }

    while (j < n2) {
        arr[k] = R[j];
        j++;
        k++;
    }
}

void mergeSort(int arr[], int left, int right) {
    if (left < right) {
        int mid = left + (right - left) / 2;
        mergeSort(arr, left, mid);
        mergeSort(arr, mid + 1, right);
        merge(arr, left, mid, right);
    }
}

int partition(int arr[], int low, int high) {
    int pivot = arr[high];
    int i = low - 1;

    for (int j = low; j < high; j++) {
        if (arr[j] <= pivot) {
            i++;
            int temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
        }
    }

    int temp = arr[i + 1];
    arr[i + 1] = arr[high];
    arr[high] = temp;
    
    return i + 1;
}

void quickSort(int arr[], int low, int high) {
    if (low < high) {
        int pi = partition(arr, low, high);
        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}

void printArray(int arr[], int size) {
    for (int i = 0; i < size; i++) cout << arr[i] << " ";
    cout << endl;
}

int main() {
    const int max=10;
    int arr1[max],n1;
    cout<<"Enter no. of elements of array: ";
    cin>>n1;
    cout<<"Enter the Elements of array fro Merge sort. \n";
    for(int i=0; i<n1; i++){
        cout<<"Enter "<<i+1<<" th element: ";
        cin>>arr1[i];
    }
    cout<<endl;
    mergeSort(arr1, 0, n1 - 1);
    cout << "Merge Sorted array: ";
    printArray(arr1, n1);

    int arr2[max],n2;
    cout<<"Enter no. of elements of array: ";
    cin>>n2;
    cout<<"Enter the Elements of array fro Quick sort. \n";
    for(int i=0; i<n2; i++){
        cout<<"Enter "<<i+1<<" th element: ";
        cin>>arr2[i];
    }
    cout<<endl;
    quickSort(arr2, 0, n2 - 1);
    cout << "Quick Sorted array: ";
    printArray(arr2, n2);

    return 0;
}
