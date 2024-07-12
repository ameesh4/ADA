#include <iostream>
#include <functional>

using namespace std;

class KnapSack{
    public:

    int knapSackRec(int W, int wt[], int val[], int index, int** dp){
        if(index < 0 || W == 0){
            return 0;
        }

        if(dp[index][W] != -1){
            return dp[index][W];
        }

        if(wt[index] > W){
            return dp[index][W] = knapSackRec(W, wt, val, index - 1, dp);
        }else{
            dp[index][W] = max(val[index] + knapSackRec(W - wt[index], wt, val, index - 1, dp), knapSackRec(W, wt, val, index - 1, dp));
            return dp[index][W];
        }
    }

    int knapSack(int W, int wt[], int val[], int n){
        int** dp;
        dp = new int*[n];

        for (int i = 0; i < n; i++){
            dp[i] = new int[W + 1];
        }

        for (int i = 0; i < n; i++){
            for (int j = 0; j < W + 1; j++){
                dp[i][j] = -1;
            }
        }
        return knapSackRec(W, wt, val, n - 1, dp);
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
    int size = 1000;
    for (int i = 0; i < 5; i++){
        int profit[size];
        int weight[size];
        for (int i = 0; i < size; i++){
            auto v = rand() % 10;
            auto w = rand() % 10;
            profit[i] = v;
            weight[i] = w;
        }
        int n = sizeof(profit) / sizeof(profit[0]);
        int W = 10;
        KnapSack knapSack;
        auto knap = [&](){
            knapSack.knapSack(W, weight, profit, n);
        };
        cout << "Time taken to process " << size << " elements: " << getTime(knap) << "ns" << endl;
        size += 500;
    }
}

