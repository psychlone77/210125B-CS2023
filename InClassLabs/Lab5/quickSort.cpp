#include <iostream>
#include <chrono>
using namespace std;


// function to print the array
void printArray(int array[], int size) {
  int i;
  for (i = 0; i < size; i++)
    cout << array[i] << " ";
  cout << endl;
}

// function to rearrange array (find the partition point)
int partition(int array[], int start, int end) {

  int pivot = array[end];
  int i = (start - 1);
  for (int j = start; j < end; j++) {
    if (array[j] <= pivot) {
      i++;
      int temp = array[i];
      array[i] = array[j];
      array[j] = temp;
    }
  }
  
      int temp = array[i+1];
      array[i+1] = array[end];
      array[end] = temp;
  
  // return the partition point
  return (i + 1);
}

void quickSort(int array[], int start, int end) {
  if (start < end) {

    int pivot = partition(array, start, end);

    quickSort(array, start, pivot - 1);

    quickSort(array, pivot + 1, end);
  }
}

// Driver code
int main()
{
  int input;
  int count = 20;
  int numEl[] ={500,1000,2000,5000,7500,10000,15000,22500};
  for(int item:numEl){

    int arr[item];
    int timesum = 0;

    for (int j = 0; j < count; j++) {
        
        for (int i = 0; i < input; i++) {
        arr[i] = rand() % 1000;
        }

        auto arr_size = sizeof(arr) / sizeof(arr[0]);
    
        auto start = chrono::high_resolution_clock::now();
        quickSort(arr, 0, arr_size-1);
        auto stop = chrono::high_resolution_clock::now();

        auto duration = chrono::duration_cast<chrono::microseconds>(stop - start);
        timesum += duration.count();  
    }
    cout << "Time For "<< item << ": " <<(timesum / count)<<endl;
    }
  
  return 0;
}
