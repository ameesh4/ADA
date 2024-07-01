#include <iostream>
#include <ctime>
#include <vector>

using namespace std;

template <typename T>


class PriorityQueue {
    vector<T> data;

    public:
    PriorityQueue(){
    }

    //c = current index
    //p = parent index
    void enqueue(T item){
        clock_t st, et;
        st = clock();
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
        et = clock();
        cout << "Time taken to enqueue: " << (et - st)*0.001<< "ms" << endl;
    }

    T dequeue(){
        clock_t st, et;
        st = clock();
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
        et = clock();
        cout << "Time taken to dequeue: " << (et - st)*0.001<< "ms" << endl;
        return fi;
    }
};

int main(){
    PriorityQueue<int> pq;
    pq.enqueue(10);
    cout << pq.dequeue();
}