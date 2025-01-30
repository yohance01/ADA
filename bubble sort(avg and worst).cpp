// Time Complexity for avg and worst = O(n*n)
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
void bubbleSort(int arr[], int n)
{
    for(int i=0;i<n-1;i++)
    {
        for(int j=i+1;j<n;j++)
        {
            if(arr[i]>arr[j])
            {
                int temp =arr[i];
                arr[i]=arr[j];
                arr[j]=temp;
            }
        }
    }
}
int main()
{
    int n=1000;
    double result[20][2];
    int r=0;
    while(n<=20000)
    {
        double time = 0;
        for(int i=0; i<10; i++)
        {
            int arr[n];
            randomNumbers(arr,n);
            clock_t start = clock();
            bubbleSort(arr,n);
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
