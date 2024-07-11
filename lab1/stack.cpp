#include <iostream>
#include <chrono>
#include <functional>
using namespace std;

class Stack{
    int *data;
    int top;
    int size;

    public:
    Stack(int size){
        this->size = size;
        data = (int *)(calloc(this->size, sizeof(int)));
        top = 0;
    }

    void push(int item){
        if(top + 1 <= size){
            data[top] = item;
            top++;
        }
        else{
            cout << "Stack is full" << endl;
        }

    }

    int pop(){
        if(top == 0){
            cout << "Stack is empty" << endl;
            return 0;
        }
        int tdata = data[top-1];
        top--;
        return tdata;
    }

    int peek(){
        return data[top-1];
    }
};

long long getTime(std::function<void()> f){
    auto start = clock();
    f();
    auto end = clock();
    long double duration = end - start;
    return (duration/CLOCKS_PER_SEC) * 1000000000;
}

int main(){
    Stack s(100000000);
    auto push = [&](){
        for(int i = 0; i < 100000000; i++){
            s.push(i);
        }
    };

    auto pop = [&](){
        for(int i = 0; i < 100000000; i++){
            s.pop();
        }
    };
    cout << "Time taken to push 10000000 elements:" << getTime(push) << "ns" << endl;
    cout << "Time taken to pop 10000000 elements:" << getTime(pop) << "ns" << endl;
}


