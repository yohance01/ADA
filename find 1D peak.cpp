#include <iostream>
using namespace std;

int find1DPeak(int arr[], int size)
{
    int low=0, high=size-1;
    while(low<=high)
    {
        int mid= low + (high - low) / 2;
        if((mid==0 || arr[mid-1]<arr[mid])  && (mid==size-1 || arr[mid+1]<arr[mid]))
        {return mid;}
        else if(mid>0 && arr[mid-1]>arr[mid])
        {high = mid-1;}
        else
        {low = mid+1;}
    }
    return -1;
}
int main()
{
    int n;
    cout<<"Enter size of array: ";
    cin>>n;
    int arr[n];
    cout<<"Enter elements: ";
    for(int i=0;i<n;i++)
    {
        cin>>arr[i];
    }
    int result = find1DPeak(arr, n);
    cout<<"Peak found at index= "<<result<<" with its value= "<<arr[result];
    return 0;
}
