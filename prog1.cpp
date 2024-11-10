#include <iostream>
using namespace std;

void traverse(int arr[], int size) {
    cout << "Array elements: ";
    for (int i = 0; i < size; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}



void insertAtBeginning(int arr[], int &size, int element) {
    for (int i = size; i > 0; i--) {
        arr[i] = arr[i - 1];
    }
    arr[0] = element;
    size++;
}
void insertAtEnd(int arr[], int &size, int element) {
    arr[size] = element;
    size++;
}
void insertAtPosition(int arr[], int &size, int element, int position) {
    if (position > size || position < 0) {
        cout << "Invalid position!" << endl;
        return;
    }
    for (int i = size; i > position; i--) {
        arr[i] = arr[i - 1];
    }
    arr[position] = element;
    size++;
}




void deleteFromBeginning(int arr[], int &size) {
    if (size == 0) {
        cout << "Array is empty!" << endl;
        return;
    }
    for (int i = 0; i < size - 1; i++) {
        arr[i] = arr[i + 1];
    }
    size--;
}
void deleteFromEnd(int arr[], int &size) {
    if (size == 0) {
        cout << "Array is empty!" << endl;
        return;
    }
    size--;
}
void deleteFromPosition(int arr[], int &size, int position) {
    if (position >= size || position < 0) {
        cout << "Invalid position!" << endl;
        return;
    }
    for (int i = position; i < size - 1; i++) {
        arr[i] = arr[i + 1];
    }
    size--;
}




void insertionSort(int arr[], int size) {
    for (int i = 1; i <= size-1; i++) {
        int key = arr[i];
        int j = i - 1;
        while (j >= 0 && arr[j] > key) {
            arr[j+1] = arr[j];
            j--;
        }
        arr[j + 1] = key;
    }
}




int linearSearch(int arr[], int size, int element) {
    for (int i = 0; i < size; i++) {
        if (arr[i] == element) {
            return i;
        }
    }
    return -1;
}




int binarySearch(int arr[], int size, int element) {
    insertionSort(arr, size);
    int left = 0, right = size - 1;
    while (left <= right) {
        int mid = left + (right - left) / 2;
        if (arr[mid] == element) {
            return mid;
        } else if (arr[mid] < element) {
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }
    return -1;
}
int binarySearch(int arr[], int low, int high, int target) {
    insertionSort(arr, high+1);
    if (low <= high) {
        int mid = low + (high - low) / 2;
        if (arr[mid] == target)
            return mid;
        if (arr[mid] > target)
            return binarySearch(arr, low, mid - 1, target);
        return binarySearch(arr, mid + 1, high, target);
    }
    return -1;
}




int main() {
    const int MAX_SIZE = 100;
    int arr[MAX_SIZE];
    int size = 0;
    int choice, element, position;

    
    cout << "Enter the number of elements in the array (max " << MAX_SIZE << "): ";
    cin >> size;
    
    if (size > MAX_SIZE) {
        cout << "Exceeds maximum allowed size. Setting size to " << MAX_SIZE << "." << endl;
        size = MAX_SIZE;
    }

    cout << "Enter the elements of the array:\n";
    for (int i = 0; i < size; i++) {
        cout<<"Element:"<<i+1<<" ";
        cin >> arr[i];
    }

    do {
        cout << "\nMenu:\n";
        cout << "1. Traverse Array\n";
        cout << "2. Insert Element\n";
        cout << "3. Delete Element\n";
        cout << "4. Insertion Sort\n";
        cout << "5. Linear Search\n";
        cout << "6. Binary Search\n";
        cout << "7. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                traverse(arr, size);
                break;

            case 2: {
                int insertChoice;
                cout << "\nInsert Menu:\n";
                cout << "1. Insert at Beginning\n";
                cout << "2. Insert at End\n";
                cout << "3. Insert at Position\n";
                cout << "Enter your choice: ";
                cin >> insertChoice;

                cout << "Enter element to insert: ";
                cin >> element;

                if (insertChoice == 1) {
                    insertAtBeginning(arr, size, element);
                } else if (insertChoice == 2) {
                    insertAtEnd(arr, size, element);
                } else if (insertChoice == 3) {
                    cout << "Enter position (0 to " << size << "): ";
                    cin >> position;
                    insertAtPosition(arr, size, element, position);
                } else {
                    cout << "Invalid choice!" << endl;
                }
                break;
            }

            case 3: {
                int deleteChoice;
                cout << "\nDelete Menu:\n";
                cout << "1. Delete from Beginning\n";
                cout << "2. Delete from End\n";
                cout << "3. Delete from Position\n";
                cout << "Enter your choice: ";
                cin >> deleteChoice;

                if (deleteChoice == 1) {
                    deleteFromBeginning(arr, size);
                } else if (deleteChoice == 2) {
                    deleteFromEnd(arr, size);
                } else if (deleteChoice == 3) {
                    cout << "Enter position (0 to " << size - 1 << "): ";
                    cin >> position;
                    deleteFromPosition(arr, size, position);
                } else {
                    cout << "Invalid choice!" << endl;
                }
                break;
            }

            case 4:
                insertionSort(arr, size);
                cout << "Array sorted using insertion sort." << endl;
                break;

            case 5:
                cout << "Enter element to search (linear search): ";
                cin >> element;
                position = linearSearch(arr, size, element);
                if (position != -1) {
                    cout << "Element found at positon " << position+1 << "." << endl;
                } else {
                    cout << "Element not found!" << endl;
                }
                break;

            case 6:
                cout << "Enter element to search (binary search): ";
                cin >> element;
                position = binarySearch(arr, 0, size-1, element);
                if (position != -1) {
                    cout << "Element found at position from sorted array " << position+1<< "." << endl;
                } else {
                    cout << "Element not found!" << endl;
                }
                break;

            case 7:
                cout << "Exiting..." << endl;
                break;

            default:
                cout << "Invalid choice! Please choose again." << endl;
        }
    } while (choice<7 && choice>0);

    return 0;
}
