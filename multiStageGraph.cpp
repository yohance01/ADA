// BACKWARD APPROACH-
// #include <iostream>
// #include <climits>
// using namespace std;
// #define N 9
// #define INF INT_MAX

// int NOS(int cost[N][N]) 
// {
//     int k = 1;
//     int node = N - 1;
//     while (node != 0) 
//     {
//         for (int j = node - 1; j >= 0; j--) 
//         {
//             if (cost[j][node] != INF) 
//             {
//                 node = j;
//                 k++;
//                 break;
//             }
//         }
//     }
//     return k;
// }

// void MSG(int cost[N][N], int n, int k) 
// {
//     int fdist[N];  
//     int d[N];  
//     fdist[N-1] = 0;

//     for (int j = 0; j < N - 1; j++)  
//     {  
//         fdist[j] = INF;  
//         d[j] = -1;  
//     }

//     for (int j = N - 2; j >= 0; j--)  
//     {  
//         for (int r = j + 1; r < N; r++)  
//         {  
//             if (cost[j][r] != INF && cost[j][r] + fdist[r] < fdist[j])  
//             {  
//                 fdist[j] = cost[j][r] + fdist[r];  
//                 d[j] = r;  
//             }  
//         }  
//     }

//     // Path reconstruction
//     int p[N];  
//     p[0] = 0; // Start node is always 0
//     int node = 0;  

//     for (int j = 1; j < k; j++)  
//     {  
//         if (d[node] == -1)  
//         {  
//             cout << "Error: No valid path found!" << endl;  
//             return;  
//         }  
//         p[j] = d[node];  
//         node = d[node];  
//     }  

//     cout << "MINIMUM DIST: " << fdist[0] << endl;  
//     cout << "SHORTEST PATH: ";  
//     for (int j = 0; j < k; j++)  
//     {  
//         cout << p[j] << " ";  
//     }  
// }

// int main() 
// {
//     int cost[N][N] =
//     {
//         {INF, 5, 2, INF, INF, INF, INF, INF, INF},
//         {INF, INF, INF, 3, INF, 3, INF, INF, INF},
//         {INF, INF, INF, 6, 5, 8, INF, INF, INF},
//         {INF, INF, INF, INF, INF, INF, 1, 4, INF},
//         {INF, INF, INF, INF, INF, INF, 6, 2, INF},
//         {INF, INF, INF, INF, INF, INF, 6, 2, INF},
//         {INF, INF, INF, INF, INF, INF, INF, INF, 7},
//         {INF, INF, INF, INF, INF, INF, INF, INF, 3},
//         {INF, INF, INF, INF, INF, INF, INF, INF, INF}
//     };

//     int K = NOS(cost);
//     MSG(cost, N, K);

//     return 0;
// }

FORWARD APPROACH-
#include <iostream>
#include <climits>
using namespace std;
#define N 9
#define INF INT_MAX
int NOS(int cost[N][N])
{
    int k=1;
    int node=0;
    while(node!=N-1)
    {
        for(int j=node+1;j<N;j++)
        {
            if(cost[node][j]!=INF)
            {
                node=j;
                k++;
                break;
            }
        }
    }
    return k;
}

void MSG(int cost[N][N], int n, int k)
{
    int fdist[N];
    int d[N];
    fdist[N-1]=0;
    for(int j=N-2;j>=0;j--)  
    {  
        fdist[j]=INT_MAX;  
        for(int r=j+1;r<N;r++)  
        {  
            if(cost[j][r]!=INF && cost[j][r]+fdist[r]<fdist[j])  
            {  
                fdist[j]=cost[j][r]+ fdist[r];  
                d[j]=r;  
            }  
        }  
    }
    int p[N];
    p[0]=0;
    p[k-1]=N-1;
    for(int j=1;j<k-1;j++)
    {
        p[j]=d[p[j-1]];
    }
    cout<<"MINIMUM DIST: "<<fdist[0]<<endl;
    
    cout<<"SHORTEST PATH: ";
    for(int j=0;j<k;j++)
    {
        cout<<p[j]<<" ";
    }
}

int main()
{
    int cost[N][N] =
      {{INF, 5, 2, INF, INF, INF, INF, INF,INF},
       {INF, INF, INF, 3, INF, 3, INF, INF, INF},
       {INF, INF, INF, 6, 5, 8, INF, INF, INF},
       {INF, INF, INF, INF, INF, INF, 1, 4, INF},
       {INF, INF, INF, INF, INF, INF, 6, 2, INF},
       {INF, INF, INF, INF, INF, INF, 6, 2, INF},
       {INF, INF, INF, INF, INF, INF, INF, INF, 7},
       {INF, INF, INF, INF, INF, INF, INF, INF, 3},
      {INF, INF, INF, INF, INF, INF, INF, INF, INF}};
      int K= NOS(cost);
      MSG(cost,N,K);
    return 0;
}
