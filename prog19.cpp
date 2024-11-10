#include <iostream>
#include <cmath>
using namespace std;


void heapify(int arr[], int n, int i) {
    int largest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;

    if (left < n && arr[left] > arr[largest]) largest = left;
    if (right < n && arr[right] > arr[largest]) largest = right;

    if (largest != i) {
        int temp = arr[i];
        arr[i] = arr[largest];
        arr[largest] = temp;
        heapify(arr, n, largest);
    }
}


void heapSort(int arr[], int n) {
    for (int i = n / 2 - 1; i >= 0; i--) heapify(arr, n, i);
    for (int i = n - 1; i > 0; i--) {
        int temp = arr[0];
        arr[0] = arr[i];
        arr[i] = temp;
        heapify(arr, i, 0);
    }
}

void countingSort(int arr[], int n, int maxValue) {
    int count[maxValue + 1] = {0};
    int output[n];

    for (int i = 0; i < n; i++) count[arr[i]]++;
    for (int i = 1; i <= maxValue; i++) count[i] += count[i - 1];
    for (int i = n - 1; i >= 0; i--) {
        output[count[arr[i]] - 1] = arr[i];
        count[arr[i]]--;
    }

    for (int i = 0; i < n; i++) arr[i] = output[i];
}

void countingSortForRadix(int arr[], int n, int exp) {
    int output[n];
    int count[10] = {0};

    for (int i = 0; i < n; i++) count[(arr[i] / exp) % 10]++;
    for (int i = 1; i < 10; i++) count[i] += count[i - 1];
    for (int i = n - 1; i >= 0; i--) {
        output[count[(arr[i] / exp) % 10] - 1] = arr[i];
        count[(arr[i] / exp) % 10]--;
    }

    for (int i = 0; i < n; i++) arr[i] = output[i];
}

void radixSort(int arr[], int n) {
    int maxValue = arr[0];
    for (int i = 1; i < n; i++) {
        if (arr[i] > maxValue) maxValue = arr[i];
    }

    for (int exp = 1; maxValue / exp > 0; exp *= 10) countingSortForRadix(arr, n, exp);
}

void bucketSort(float arr[], int n) {
    int bucketSize = 10;
    float buckets[10][10] = {0}; 
    int count[10] = {0};          

    for (int i = 0; i < n; i++) {
        int bucketIndex = static_cast<int>(bucketSize * arr[i]);
        buckets[bucketIndex][count[bucketIndex]++] = arr[i];
    }

    for (int i = 0; i < bucketSize; i++) {
        for (int j = 1; j < count[i]; j++) {
            float key = buckets[i][j];
            int k = j - 1;
            while (k >= 0 && buckets[i][k] > key) {
                buckets[i][k + 1] = buckets[i][k];
                k--;
            }
            buckets[i][k + 1] = key;
        }
    }

    int idx = 0;
    for (int i = 0; i < bucketSize; i++) {
        for (int j = 0; j < count[i]; j++) {
            arr[idx++] = buckets[i][j];
        }
    }
}

int returnmax(int arr[], int s){
    int max=arr[0];
    for(int i=1; i<s ;i++){
        if(max<arr[i]){
            max=arr[i];
        }
    }
    return max;
}
void printIntArray(int arr[], int n) {
    for (int i = 0; i < n; i++) cout << arr[i] << " ";
    cout << endl;
}

void printFloatArray(float arr[], int n) {
    for (int i = 0; i < n; i++) cout << arr[i] << " ";
    cout << endl;
}

int main() {
    const int max = 50;
    int arr1[max];
    int n1;
    cout<<"Enter no. of elements of array: ";
    cin>>n1;
    cout<<"Enter the Elements of array fro heap sort.\n";
    for(int i=0; i<n1; i++){
        cout<<"Enter "<<i+1<<" th element: ";
        cin>>arr1[i];
    }
    cout<<endl;
    heapSort(arr1, n1);
    cout << "Heap Sorted array: ";
    printIntArray(arr1, n1);

    int arr2[max];
    int n2;
    cout<<"Enter no. of elements of array: ";
    cin>>n2;
    cout<<"Enter the Elements of array for count sort.\n";
    for(int i=0; i<n2; i++){
        cout<<"Enter "<<i+1<<" th element: ";
        cin>>arr2[i];
    }
    cout<<endl;
    int m1=returnmax(arr2,n2);
    countingSort(arr2, n2,m1);
    cout << "Counting Sorted array: ";
    printIntArray(arr2, n2);

    int arr3[max];
    int n3;
    cout<<"Enter no. of elements of array: ";
    cin>>n3;
    cout<<"Enter the Elements of array fro Radix sort. \n";
    for(int i=0; i<n3; i++){
        cout<<"Enter "<<i+1<<" th element: ";
        cin>>arr3[i];
    }
    cout<<endl;
    radixSort(arr3, n3);
    cout << "Radix Sorted array: ";
    printIntArray(arr3, n3);

    float arr4[max];
    int n4;
    cout<<"Enter float no. of elements of array: ";
    cin>>n4;
    cout<<"Enter the Elements of array Bucket sort.\n";
    for(int i=0; i<n4; i++){
        cout<<"Enter "<<i+1<<" th element: ";
        cin>>arr4[i];
    }
    cout<<endl;
    bucketSort(arr4, n4);
    cout << "Bucket Sorted array: ";
    printFloatArray(arr4, n4);

    return 0;
}
