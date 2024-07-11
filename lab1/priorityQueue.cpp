#include <iostream>
#include <ctime>
#include <vector>
#include <functional>

using namespace std;

template <typename T>


class PriorityQueue {
    vector<T> data;

    public:
    PriorityQueue(){
    }

    void enqueue(T item){
        data.push_back(item);
        int c = data.size() - 1;

        while (c > 0){
            int p = (c - 1) / 2;
            if (data[c] <= data[p])
                break;
            T temp = data[p];
            data[p] = data[c];
            data[c] = temp;
            c = p;
        }
    }

    T dequeue(){
        int l = data.size() - 1;
        T fi = data[0];
        data[0] = data[l];
        data.pop_back();
        --l;

        int p = 0;

        while (true){
            int c = 2 * p + 1;
            if (c > l)
                break;

            int rchild = c + 1;
            if (rchild <= l && data[rchild] > data[c])
                c = rchild;

            if (data[p] >= data[c])
                break;

            T temp  = data[p];
            data[p] = data[c];
            data[c] = temp;
            p = c;
        }
        return fi;
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
    PriorityQueue<int> pq;
    auto enqueue = [&](){
        for(int i = 0; i < 1000000; i++){
            pq.enqueue(i);
        }
    };
    auto dequeue = [&](){
        for(int i = 0; i < 1000000; i++){
            pq.dequeue();
        }
    };

    cout << "Time taken to enqueue 1000000 elements: " << getTime(enqueue) << "ns" << endl;
    cout << "Time taken to dequeue 1000000 elements: " << getTime(dequeue) << "ns" << endl;
}