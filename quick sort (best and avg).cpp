//Time Complexity for best and avg = O(nlogn)
#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

void randomNumbers(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        arr[i] = rand() % n;
    }
}

int partition(int arr[], int low, int high) {
    int pivot = arr[low];
    int i = low + 1;
    int j = high;

    while (i <= j) {
        while (i <= j && arr[i] <= pivot) i++;
        while (i <= j && arr[j] > pivot) j--;
        if (i < j) {
            swap(arr[i], arr[j]);
        }
    }

    swap(arr[low], arr[j]);
    return j;
}

void quickSort(int arr[], int low, int high) {
    if (low < high) {
        int p = partition(arr, low, high);
        quickSort(arr, low, p - 1);
        quickSort(arr, p + 1, high);
    }
}

int main() {
    srand(time(0));

    int n = 1000;
    double result[20][2];
    int r = 0;
    while (n <= 20000) {
        double totalTime = 0;

        for (int i = 0; i < 10; i++) {
            int arr[n];
            randomNumbers(arr, n);
            clock_t start = clock();
            quickSort(arr, 0, n - 1);
            clock_t end = clock();
            totalTime += double(end - start) / CLOCKS_PER_SEC;
        }

        double averageTime = totalTime / 10.0;
        result[r][0] = n;
        result[r][1] = averageTime;
        n += 1000;
        r++;
    }

    cout<<"Result matrix: "<<endl;
    for(int i=0;i<20;i++)
    {
        for(int j=0;j<2;j++)
        {
            cout<<result[i][j]<<" ";
        }
        cout<<endl;
    }

    return 0;
}
