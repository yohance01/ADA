#include <iostream>
using namespace std;
int main()
{
    int n;
    cout<<"Odd value of n: ";
    cin>>n;
    int arr[n][n];
    for(int i=0;i<n;i++)
    {
        //initialised whole matrix to 0 initially
        for(int j=0;j<n;j++)
        {
            arr[i][j]=0;
        }
    }
    //first element at mid column of first row
    int r=0;
    int c=n/2;
    arr[r][c]=1;
    for(int i=2;i<=(n*n);i++)
    {
        //next element at prev row prev col
        int newr=r-1;
        int newc=c-1;
        if(newr==-1) newr=n-1;
        if(newc==-1) newc=n-1;
        //if occupied, simply next row same col
        if(arr[newr][newc]!=0) {newr=r+1; newc=c;}
        arr[newr][newc]=i;
        r=newr;
        c=newc;
    }
    cout<<"magic Square: "<<endl;
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            cout<<arr[i][j]<<" ";
        }
        cout<<endl;
    }
}
