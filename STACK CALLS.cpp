#include <iostream>
#include <stack>
#include <cstdlib>
#include <ctime>
using namespace std;

void randomNumbers(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        arr[i] = rand() % n;
    }
}

int partition(int arr[], int low, int high)
{
    int pivot=arr[low];
    int i=low+1;
    int j=high;

    while(i<=j)
    {
        while(i<=j && arr[i]<=pivot) i++;
        while(i<=j && arr[j] >pivot) j--;
        if (i<j) {
            swap(arr[i], arr[j]);
    }
}

    swap(arr[low], arr[j]);
    return j;
}

int QSI(int arr[], int low, int high)
{
    int calls=0;
    stack <int> st;
    do
    {
        while(low<high)
        {
            int j= partition(arr,low,high);
            if((j-low)<(high-j))
            {
                st.push(j+1);
                st.push(high);
                calls+=2;
                high=j-1;
            }
            else
            {
                st.push(low);
                st.push(j-1);
                calls+=2;
                low=j+1;
            }
        }
        if (st.empty()) 
        {
            
            
            return calls;
        }
        else
        {
            high=st.top();
            st.pop();
            low=st.top();
            st.pop();
        }
    } while (true);
}

int main() {
    
    srand(time(0));
    int n = 10;
    double result[5][2];
    int r = 0;
    int calls;
    while (n <= 1000)
    {
            int arr[n];
            randomNumbers(arr, n);
            calls = QSI(arr, 0, n - 1);
            result[r][0] = n;
            result[r][1] = calls;
            n *=2;
            r++;
    }
    
    
    cout<<"Result matrix: "<<endl;
    for(int i=0;i<5;i++)
    {
        for(int j=0;j<2;j++)
        {
            cout<<result[i][j]<<" ";
        }
        cout<<endl;
    }

    return 0;
}
