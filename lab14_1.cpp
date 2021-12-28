#include <iostream>
#include <cmath>
using namespace std;

void stat(const double[],int,double[]);

int main(){
    double A[] = {1.2,3.5,6.9,7.8,12.5,0.5};
    int N = sizeof(A)/sizeof(A[0]);
    double B[6];
    stat(A,N,B);
    cout << "Arithmetic Mean = " << B[0];
    cout << "\nStandard Deviation = " << B[1];
    cout << "\nGeometric Mean = " << B[2];
    cout << "\nHarmonic Mean = " << B[3];
    cout << "\nMax = " << B[4];
    cout << "\nMin = " << B[5];
    return 0;
}

void stat(const double A[], int N, double B[]){
    double mean = 0;
    for (int i = 0; i < N; i++){
        mean += A[i];
    }
    B[0] = mean/N;

    double std = 0;
    for (int i = 0; i < N; i++){
        std += pow(A[i] - (mean/N),2);
    }
    B[1] = sqrt(std/N);

    double geo = 1;
    for (int i = 0; i < N; i++){
        geo *= A[i];
    }
    B[2] = pow(geo,1./N);

    double hamon = 0;
    for (int i = 0; i < N; i++){
        hamon += 1./A[i];
    }
    B[3] = N/hamon;

    double max = A[0], min = A[0];
    for (int i = 1; i < N; i++){
        if(max < A[i]) max = A[i];
        if(min > A[i]) min = A[i];
    }
    B[4] = max;
    B[5] = min;
}
