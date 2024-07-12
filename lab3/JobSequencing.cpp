#include <algorithm>
#include <iostream>
#include <functional>

using namespace std;

class Job{
    public:
    char id;
    int deadline;
    int profit;
    Job(char id, int deadline, int profit){
        this->id = id;
        this->deadline = deadline;
        this->profit = profit;
    }
};

class Sequencing{
    public:
    bool comparison(Job a, Job b){
        return (a.profit > b.profit);
    }

    void JobScheduling(Job arr[], int n){
        sort(arr, arr + n, [this](Job a, Job b){
            return comparison(a, b);
        });

        int result[n];
        int slot[n];

        for (int i = 0; i < n; i++){
            slot[i] = false;
        }

        for (int i = 0; i < n; i++){
            for (int j = min(n, arr[i].deadline) - 1; j >= 0; j--){
                if(slot[j] == false){
                    result[j] = i;
                    slot[j] = true;
                    break;
                }
            }
        }

        for (int i = 0; i < n; i++){
            if(slot[i]){
                cout << arr[result[i]].id << " ";
            }
        }
    }

    void toString(Job arr[], int size){
        for (int i = 0; i < size; i++){
            cout << arr[i].id << " " << arr[i].deadline << " " << arr[i].profit << endl;
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

int main(){
    Job arr[] = {
        Job('a', 2, 100),
        Job('b', 1, 19),
        Job('c', 2, 27),
        Job('d', 1, 25),
        Job('e', 3, 15),
        Job('f', 2, 50),
        Job('g', 1, 30),
        Job('h', 3, 35),
        Job('i', 3, 20),
        Job('j', 1, 12)

    };

    int N = sizeof(arr) / sizeof(arr[0]);
    Sequencing sequencing;
    auto jobScheduling = [&](){
        sequencing.JobScheduling(arr, N);
    };

    cout << "Jobs: " << endl;
    cout << "ID Deadline Profit" << endl;
    sequencing.toString(arr, N);
    cout << "Job sequence: ";
    auto value = getTime(jobScheduling);
    cout << endl;
    cout << "Time taken to schedule jobs: \n" << value << "ns" << endl;
    return 0;
}
