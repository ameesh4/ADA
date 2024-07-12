#include <bits/stdc++.h>
using namespace std;

class subsetSum {
    public:
    bool flag = 0;
    void PrintSubsetSum(int i, int n, int set[], int targetSum,
                        vector<int>& subset)
    {
        if (targetSum == 0) {
    
            flag = 1;
            cout << "[ ";
            for (int i = 0; i < subset.size(); i++) {
                cout << subset[i] << " ";
            }
            cout << "]";
            return;
        }
    
        if (i == n) {
            return;
        }
        PrintSubsetSum(i + 1, n, set, targetSum, subset);
    
        if (set[i] <= targetSum) {
    
            subset.push_back(set[i]);
    
            PrintSubsetSum(i + 1, n, set, targetSum - set[i],
                        subset);
    
            subset.pop_back();
        }
    }
};

long long getTime(std::function<void()> f){
    auto start = clock();
    f();
    auto end = clock();
    long double duration = end - start;
    return (duration/CLOCKS_PER_SEC) * 1000000000;
}

int main()
{
    subsetSum s;
    int set[] = { 3, 34, 4, 12, 5, 2 };
    int n = sizeof(set) / sizeof(set[0]);
    int targetSum = 9;
    vector<int> subset;
    auto subsetProblem = [&](){
        s.PrintSubsetSum(0, n, set, targetSum, subset);
        cout << endl;
    };

    if (!s.flag) {
        cout << "There is no such subset";
    }

    cout << getTime(subsetProblem) << "ns Time taken" << endl;
 
    return 0;
}