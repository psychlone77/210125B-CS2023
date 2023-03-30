#include <iostream>
#include <vector>
using namespace std;

vector<int> insertionSort(vector<int> arr, int num){
/* A simple version of insertion sort. Since the array that is given is already sorted
we only have to insert number to correct position of the array*/
    for(int i = 0; i<arr.size();i++){
        if(num<=arr[i]){
            arr.insert(arr.begin() + i, num);
            return arr;
        }
    }
    arr.push_back(num);
    return arr;
}

float median(vector<int> arr){
    if(arr.size() % 2 != 0){
        int mid = arr.size()/2;
        return arr[mid];
    }
    else{
        int mid = arr.size()/2;
        return float(arr[mid]+arr[mid-1])/2;
    }
}

int main(){
    int input;
    cout << "Enter a number: ";
    cin >> input;
    int *arr = new int[input];

    // creating an displaying initial array
    for (int i = 0; i < input; i++) {
        arr[i] = rand() % 1000;
    }
    cout << endl << "Initial Array is: " << endl;
    for (int i = 0; i < input; i++) {
        cout << arr[i] << " ";
        }
    cout << endl << endl;

    vector<int> sorted;
    for(int j = 0; j < input; j++){
        sorted = insertionSort(sorted, arr[j]);
        cout << "[";
        for (int i = 0; i < sorted.size()-1; i++) {
        cout << sorted[i] << ", ";
        }
        cout << sorted[sorted.size()-1]<<"]"<< endl; // printing last element
        cout << "Median = "<<median(sorted) << endl << endl;
    }
    return 0;
}