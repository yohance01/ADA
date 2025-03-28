#include <iostream>
using namespace std;
void initializeMatrix(int matrix[10][10], int size) {
    for(int i=0;i<size;i++)
    {
        for(int j=0;j<size;j++)
        {
            matrix[i][j]=0;
        }
    }
}
void addMatrix(int a[10][10], int b[10][10], int result[10][10], int size)
{
    for(int i=0;i<size;i++)
    {
        for(int j=0;j<size;j++)
        {
            result[i][j]=a[i][j]+b[i][j];
        }
    }
}
void matMul(int a[10][10], int b[10][10], int c[10][10], int size)
    {
    if (size == 1)
    {
        c[0][0]=a[0][0] * b[0][0];
        return;
    }
    int newSize= size/2;
    int A11[10][10], A12[10][10], A21[10][10], A22[10][10];
    int B11[10][10], B12[10][10], B21[10][10], B22[10][10];
    int C11[10][10], C12[10][10], C21[10][10], C22[10][10];
    int temp1[10][10], temp2[10][10];
    initializeMatrix(C11, newSize);
    initializeMatrix(C12, newSize);
    initializeMatrix(C21, newSize);
    initializeMatrix(C22, newSize);
    for (int i=0;i<newSize;i++) {
        for (int j=0;j<newSize;j++) {
            A11[i][j]=a[i][j];
            A12[i][j]=a[i][j+newSize];
            A21[i][j]=a[i+newSize][j];
            A22[i][j]=a[i+newSize][j+newSize];

            B11[i][j]=b[i][j];
            B12[i][j]=b[i][j+newSize];
            B21[i][j]=b[i+newSize][j];
            B22[i][j]=b[i+newSize][j+newSize];
        }
    }
    matMul(A11, B11, temp1, newSize);
    matMul(A12, B21, temp2, newSize);
    addMatrix(temp1, temp2, C11, newSize);
    matMul(A11, B12, temp1, newSize);
    matMul(A12, B22, temp2, newSize);
    addMatrix(temp1, temp2, C12, newSize);
    matMul(A21, B11, temp1, newSize);
    matMul(A22, B21, temp2, newSize);
    addMatrix(temp1, temp2, C21, newSize);
    matMul(A21, B12, temp1, newSize);
    matMul(A22, B22, temp2, newSize);
    addMatrix(temp1, temp2, C22, newSize);
    for (int i=0; i<newSize;i++)
    {
        for (int j=0; j<newSize;j++)
        {
            c[i][j]=C11[i][j];
            c[i][j+newSize]=C12[i][j];
            c[i+newSize][j]=C21[i][j];
            c[i+newSize][j+newSize]=C22[i][j];
        }
    }
}
int main() {
    int n;
    cout<<"Enter size for the matrices: ";
    cin>>n;
    int a[10][10], b[10][10], c[10][10];
    cout<<"Enter elements in matrix A:"<<endl;
    for(int i=0; i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            cin>>a[i][j];
        }
    }
    cout<<"Enter elements in matrix B:"<<endl;
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            cin>>b[i][j];
        }
    }
    initializeMatrix(c, n);
    matMul(a, b, c, n);
    cout<<"Resultan:"<<endl;
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            cout<<c[i][j]<<" ";
        }
        cout<<endl;
    }
    return 0;
}
