#include <iostream>
#include <functional>

using namespace std;

class Sort{

    public:
    void swap(int *a, int *b){
        int temp = *a;
        *a = *b;
        *b = temp;
    }

    int partition(int arr[], int low, int high){
        int pivot = arr[high];
        int i = low - 1;

        for (int j = low; j <= high - 1; j++){
            if(arr[j] < pivot){
                i++;
                swap(&arr[i], &arr[j]);
            }
        }
        swap(&arr[i + 1], &arr[high]);
        return i + 1;
    }

    void quickSort(int arr[], int low, int high){
        if(low < high){
            int pi = partition(arr, low, high);
            quickSort(arr, low, pi - 1);
            quickSort(arr, pi + 1, high);
        }
    }

    void merge(int arr[], int mid, int left, int right){
        int subArr1 = mid - left + 1;
        int subArr2 = right - mid;

        auto *leftArr = new int[subArr1];
        auto *rightArr = new int[subArr2];

        for (int i = 0; i < subArr1; i++){
            leftArr[i] = arr[left + i];
        }
        for (int i = 0; i < subArr2; i++){
            rightArr[i] = arr[mid + 1 + i];
        }

        auto indexofSubArr1 = 0;
        auto indexofSubArr2 = 0;

        int indexofMergedArr = left;

        while(indexofSubArr1 < subArr1 && indexofSubArr2 < subArr2){
            if(leftArr[indexofSubArr1] <= rightArr[indexofSubArr2]){
                arr[indexofMergedArr] = leftArr[indexofSubArr1];
                indexofSubArr1++;
            }
            else{
                arr[indexofMergedArr] = rightArr[indexofSubArr2];
                indexofSubArr2++;
            }
            indexofMergedArr++;
        }
        
        while(indexofSubArr1 < subArr1){
            arr[indexofMergedArr] = leftArr[indexofSubArr1];
            indexofSubArr1++;
            indexofMergedArr++;
        }

        while (indexofSubArr2 < subArr2){
            arr[indexofMergedArr] = rightArr[indexofSubArr2];
            indexofSubArr2++;
            indexofMergedArr++;
        }
        delete[] leftArr;
        delete[] rightArr;
    }

    void mergeSort(int arr[], int left, int right){
        if(left >= right){
            return;
        }
        int mid = left + (right - left) / 2;
        mergeSort(arr, left, mid);
        mergeSort(arr, mid + 1, right);
        merge(arr, mid, left, right);
    }

    void toString(int arr[], int size){
        for (int i = 0; i < size; i++){
            cout << arr[i] << " ";
        }
        cout << endl;
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
    Sort sort;
    int size = 100000;
    int arr[size];
    for (int i = 0; i < size; i++){
        int v = rand() % size;
        arr[i] = v;
    }
    auto sorted = [&](){
        sort.mergeSort(arr, 0, size - 1);
    };

    auto sorted2 = [&](){
        sort.quickSort(arr, 0, size - 1);
    };

    cout << "Time taken to MergeSort "<< size << ": \n" << getTime(sorted) << "ns" << endl;
    cout << "Time taken to QuickSort "<< size << ": \n" << getTime(sorted2) << "ns" << endl;
    return 0;
}

