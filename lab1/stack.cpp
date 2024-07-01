#include <iostream>
#include <ctime>

using namespace std;


template <typename T>
class Stack{
    T *data;
    int top;

    public:
    Stack(int size){
        data = new T[size];
        top = 0;
    }

    void push(T item){
        clock_t st, et;
        st = clock();
        data[top] = item;
        top++;
        et = clock();
        cout << "Time taken to push: " << (et - st)*0.001<< "ms" << endl;
    }

    T pop(){
        clock_t st, et;
        st = clock();
        T tdata = data[top-1];
        top--;
        et = clock();
        cout << "Time taken to pop: " << (et - st)*0.001<< "ms" << endl;
        return tdata;
    }

    T peek(){
        return data[top-1];
    }
};

int main(){
    Stack<int> s(10);
    s.push(1);
    s.push(2);
    cout << s.pop() << "\n";
    s.push(3);
    cout << s.pop() << "\n";
}
