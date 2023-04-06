#include <iostream>
#include <chrono>
using namespace std;


class Stack {
    private:
    int top=-1;
    int size;
    int* stack;

    public:
    Stack(int size){
        this->size = size;
        stack = new int[size];
    }

    void push(int val){
        if(top>=size-1){
            cout<<"Stack Overflow"<<endl;
        }
        else{
            top += 1;
            stack[top]=val;
        }
    }
    bool isEmpty(){
        if(top<=-1){
            return true;
        }
        else{
            return false;
        }
    }

    bool isFull(){
        if(top==size){
            return true;
        }
        else{
            return false;
        }
    }

    int stackTop(){
        return stack[top];
    }

    int pop(){
        if(isEmpty()){
            cout<<"Stack Underflow"<<endl;
        }
        else{
            int output = stack[top];
            top -= 1;
            return output;
        }
    }

    void display(){
        for(int i = 0; i<=top; i++){
            cout<<stack[i]<<",";
        }
        cout<<endl;
    }
};//end of class stack


int main(){

    int timesum = 0;
    int count = 20;

    for (int j = 0; j < count; j++) { //repeat the operations and get average
        int size = 5;
        //cout<<"Enter Size: ";
        //cin>>size;
        Stack s = Stack(size);
        cout<<"Pass "<<j<<endl;
        auto start = chrono::high_resolution_clock::now();

        for(int i = 0; i<10; i++){
            s.push(rand()%100);
        }
        s.display();
        for(int i = 0; i<5; i++){
            s.pop();
        }
        s.display();
        for(int i = 0; i<4; i++){
            s.push(rand()%100);
        }
        s.display();

        auto stop = chrono::high_resolution_clock::now();

        auto duration = chrono::duration_cast<chrono::microseconds>(stop - start);
        timesum += duration.count(); 
        cout<<endl; 
    }
    cout << "Average Time is for each pass is "<<(timesum / count)<<endl;
}