#include<iostream>
using namespace std;

void strassen(int A[][2],int B[][2],int C[][2])
{
    int P1=(A[0][0]+A[1][1])*(B[0][0]+B[1][1]);
    int P2=(A[1][0]+A[1][1])*B[0][0];
    int P3=A[0][0]*(B[0][1]-B[1][1]);
    int P4=A[1][1]*(B[1][0]-B[0][0]);
    int P5=(A[0][0]+A[0][1])*B[1][1];
    int P6=(A[1][0]-A[0][0])*(B[0][0]+B[0][1]);
    int P7=(A[0][1]-A[1][1])*(B[1][0]+B[1][1]);

    C[0][0]=P1+P4-P5+P7;
    C[0][1]=P3+P5;
    C[1][0]=P2+P4;
    C[1][1]=P1-P2+P3+P6;
}

int main(){
    int A[2][2]={{1,2},{3,4}};
    int B[2][2]={{5,6},{7,8}};
    int C[2][2];

    strassen(A,B,C);

    cout<<"Result:\n";
    for(int i=0;i<2;i++)
    {
        for(int j=0;j<2;j++)
        {
            cout<<C[i][j]<<" ";
        }
        cout<<endl;
    }
    return 0;
}
