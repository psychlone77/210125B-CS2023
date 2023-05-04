#include <iostream>
#include <sstream>
#include <vector>
using namespace std;
  
// function to heapify the tree
void heapify(int arr[], int n, int root)
{
   // build heapify
  int largest;
  int leftChild = 2*root + 1;
  int rightChild = 2*root + 2;
  if(leftChild<n and arr[leftChild]>arr[root]){
    largest = leftChild;
  }
  else{
    largest = root;
  }

  if(rightChild<n and arr[rightChild]>arr[largest]){
    largest = rightChild;
  }

  if(largest != root){
    swap(arr[root], arr[largest]);
    heapify(arr, n, largest);
  }
   
}
  
// implementing heap sort
void heapSort(int arr[], int n)
{
  // build heap
  /*int tempArr[n];
  for(int i = 0; i<n; i++){
    tempArr[i] = arr[i];
  }*/
  for(int i = n/2-1; i>=0; i--){
    heapify(arr, n, i);
  }
   // extracting elements from heap one by one
  int heapSize = n;
  for(int i = 0; i<n; i++){
    swap(arr[0], arr[heapSize-1]);
    heapSize--;
    heapify(arr,heapSize, 0);
  }
   
}
  
/* print contents of array */
void displayArray(int arr[], int n)
{
   for (int i=0; i<n; ++i)
   cout << arr[i] << " ";
   cout << "\n";
}
  
// main program
int main()
{
  //int heap_arr[] = {4,17,3,12,9,6};
  //int n = sizeof(heap_arr)/sizeof(heap_arr[0]);

  //Below is way to get space seperated integers from user
  cout << "Enter space-separated integers: ";
  string input;
  getline(std::cin, input);

  istringstream iss(input);
  vector<int> numbers;
  int num;

  while (iss >> num) {
      numbers.push_back(num);
  }

  // Create an array from the vector
  int n = numbers.size();
  int* heap_arr = new int[n];
  for (int i = 0; i < n; ++i) {
      heap_arr[i] = numbers[i];
  }

  //displayArray(heap_arr,n);
  //3 93 29 21 44 67 88 20
  //9 8 7 6 5 4 3 2 1
  
  heapSort(heap_arr, n);
  
  cout << "\n" <<"Sorted array"<<endl;
  displayArray(heap_arr, n);
}
