#include <iostream>
#include <chrono>
using namespace std;

struct node {
    int data;
    node *next;
};


class Stack {

private:
    node *head;

public:
    Stack() {
        head = NULL;
    }

    void push(int val){
        node *temp = new node;
        temp->data = val;
        temp->next = NULL;
        
        if(head == NULL) {
            head = temp;
        }
        else {
            temp->next = head;
            head = temp;
        }
    }

    int pop(){
        if(head == NULL){
            cout<<"Stack UnderFlow";
        }
        else{
            int output = head->data;
            head = head->next;
            return output;
        }
    }

    bool isEmpty(){
        if(head == NULL){
            return true;
        }
        else{
            return false;
        }
    }

    int stackTop(){
        return head->data;
    }

    void display(){
        node *currentNode = head;
        while(currentNode != NULL){
            cout<<currentNode->data<<",";
            currentNode = currentNode->next;
        }
        cout<<endl;
    }

};//end of Linked list class

int main(){

    int timesum = 0;
    int count = 20;

    for (int j = 0; j < count; j++) { //repeat the operations and get average
        Stack s = Stack();
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
    cout << "Average Time for each pass is "<<(timesum / count)<<endl;
}