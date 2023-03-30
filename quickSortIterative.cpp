#include <bits/stdc++.h> 
#include <chrono>
using namespace std; 
int partition(int arr[], int l, int h) 
{ 
  int x = arr[h]; 
  int i = (l - 1); 
  for (int j = l; j <= h - 1; j++) { 
    if (arr[j] <= x) { 
      i++; 
      swap(arr[i], arr[j]); 
    } 
  } 
  swap(arr[i + 1], arr[h]); 
  return (i + 1); 
} 
void quickSort(int arr[], int l, int h) 
{ 
  int stack[h-l+1]; 
  int top = -1; 
  stack[++top]=l; 
  stack[++top]=h; 
  while(top >= 0) 
  { 
    h = stack[top--]; 
    l = stack[top--]; 
    int p = partition(arr, l, h); 
    if(p-1>l) 
    { 
      stack[++top] = l; 
      stack[++top] = p - 1; 
    } 
    if(p+1<h) 
    { 
      stack[++top] = p + 1; 
      stack[++top] = h; 
    } 
  } 
} 
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