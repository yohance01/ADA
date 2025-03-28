#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;
void randomNumbers(int arr[], int n)
{
    srand(time(0));
    for(int i=0;i<n;i++)
    {
        arr[i]=rand() % n;
    }
}
void merge(int arr[], int l, int mid, int r) {
    int n1 = mid - l + 1;
    int n2 = r - mid;
    int a[n1];
    int b[n2];

    for (int i = 0; i < n1; i++) {
        a[i] = arr[l + i];
    }
    for (int i = 0; i < n2; i++) {
        b[i] = arr[mid + 1 + i];
    }

    int i = 0, j = 0, k = l;
    while (i < n1 && j < n2) {
        if (a[i] < b[j]) {
            arr[k] = a[i];
            i++;
        } else {
            arr[k] = b[j];
            j++;
        }
        k++;
    }
    while (i < n1) {
        arr[k] = a[i];
        i++;
        k++;
    }
    while (j < n2) {
        arr[k] = b[j];
        j++;
        k++;
    }
}
void mergeSort(int arr[], int l, int r) {
    if (l < r) {
        int mid = (l + r) / 2;
        mergeSort(arr, l, mid);
        mergeSort(arr, mid + 1, r);
        merge(arr, l, mid, r);
    }
}
int main()
{
    int n=1000;
    double result[10][2];
    int r=0;
    while(n<=10000)
    {
        double time = 0;
        for(int i=0; i<10; i++)
        {
            int arr[n];
            randomNumbers(arr,n);
            clock_t start = clock();
            mergeSort(arr,0,n-1);
            clock_t end = clock();
            double duration = double(end - start) / CLOCKS_PER_SEC;
            time = time + duration;
        }
        double average = time / 10;
        result[r][0]=n;
        result[r][1]=average;
        n+=1000;
        r++;
    }
    cout<<"Result matrix: "<<endl;
    for(int i=0;i<10;i++)
    {
        for(int j=0;j<2;j++)
        {
            cout<<result[i][j]<<" ";
        }
        cout<<endl;
    }
    return 0;
}

