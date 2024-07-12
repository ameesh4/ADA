
#include <bits/stdc++.h>
#include <iostream>
#include <functional>
#include <algorithm>

using namespace std;

long long getTime(std::function<void()> f){
    auto start = clock();
    f();
    auto end = clock();
    long double duration = end - start;
    return (duration/CLOCKS_PER_SEC) * 1000000000;
}

class Items{
    public:
    int weight;
    int value;
    Items(int weight, int value){
        this->weight = weight;
        this->value = value;
    }
};

class Knapsack{
    public:

    static bool cmp(Items a, Items b){
        double r1 = (double)a.value / a.weight;
        double r2 = (double)b.value / b.weight;
        return r1 > r2;
    }

    double fractionalknapsack(int W, Items arr[], int n){
        sort(arr, arr + n, cmp);

        double finalv = 0.0;

        for (int i = 0; i < n; i++){
            if(arr[i].weight <= W){
                W -= arr[i].weight;
                finalv += arr[i].value;
            }
            else{
                finalv += arr[i].value * ((double)W / arr[i].weight);
                break;
            }
        }

        return finalv;
    }

    void toString(Items arr[], int size){
        for (int i = 0; i < size; i++){
            cout << arr[i].weight << " " << arr[i].value << endl;
        }
    }
};

int main(){
    Knapsack knapsack;
    Items arr[] = {{10, 60}, {40, 40}, {20, 100}, {30, 120}, {50, 60}, {10, 40}, {20, 80}};
    int N = sizeof(arr) / sizeof(arr[0]);
    int W = 50;
    double maxvalue = 0.0;
    auto knapsackfn = [&](){
        maxvalue = knapsack.fractionalknapsack(W, arr, N);
    };
    maxvalue = knapsack.fractionalknapsack(W, arr, N);
    cout << "Items: " << endl;
    cout << "W V" << endl;
    knapsack.toString(arr, N);
    cout << "Maximum value we can obtain = " << maxvalue << endl;
    cout << "Time taken to calculate maximum value: " << getTime(knapsackfn) << "ns" << endl;
    return 0;
}