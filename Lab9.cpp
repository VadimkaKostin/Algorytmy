#include <iostream>
#include <time.h>
#include <iomanip>

using namespace std;

void inputA(float *a[],int m,int n);

void findX(float *a[], float x, int m, int n);

void findUnderDiagonalA(float *a[], float x, int m, int n);

int main(){
    srand(time(NULL));
    int m,n;
    float X;

    cout << "Enter m and n: ";
    cin >> m >> n;

    cout << "Enter X: ";
    cin >> X;

    float A[m][n];
    float *p[m];
    for (int i = 0; i < n; i++)
    {
        p[i] = A[i];
    }

    inputA(p,m,n);

    findX(p,X,m,n);

    findUnderDiagonalA(p,X,m,n);

    system("pause");
}

void inputA(float *a[],int m,int n){
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            a[i][j] = (float)(rand()%200 - 100);
        }
    }
}

void findX(float *a[], float x, int m, int n){
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cout << setw(4) << a[i][j];
        }
        cout << endl;
    }
    cout << endl;

    int d = 1, count = 0;
    for (int i = 0; i < m; i++)
    {
        if(d>0){
            for (int j = 0; j < n; j++)
            {
                if(a[i][j]==x){
                    cout <<"X found at A[" << i+1 <<"]["<< j+1 <<"]\n";
                    count++;
                }
            }
        } else {
            for (int j = n-1; j >= 0; j--)
            {
                if(a[i][j]==x){
                    cout <<"X found at A[" << i+1 <<"]["<< j+1 <<"]\n";
                    count++;
                }
            }
        }
        d *= -1;
    }
    if(count==0)
        cout << "X not found\n\n";
}

void findUnderDiagonalA(float *a[], float x, int m, int n){
    int amount = 0;
    cout << "\nElements bigger then X under the diagonal: \n";
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < i; j++)
        {
            if(a[i][j]>x){
                cout << a[i][j] << " ";
                amount++;
            }
        }
    }
    cout <<"\nAmount: " << amount << endl;
}