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

void stat(const double value[],int size_A,double B[]){
    double sum;
    double var;
    double Geo = 1.00;
    double Harmonic;
    double min = value[0];
    double max = value[0];
    for(int i = 0; i < size_A; i++){
        sum += value[i];
    }
    B[0] = sum /size_A;
    for(int n= 0;n < size_A; n++){
        var +=(value[n] - B[0]) *  (value[n] - B[0]);
    }
    var /= size_A;
    B[1] = sqrt(var);
    for(int a = 0; a < size_A;a++){
        Geo = Geo * value[a];
    }
    B[2] = pow(Geo,(double)1/size_A);
    for(int b = 0; b < size_A; b++){
        Harmonic += 1/value[b];
    }
    B[3] = size_A / Harmonic;
    for(int c= 0; c < size_A;c++){
        if(min > value[c]) min = value[c];
        if(max < value[c]) max = value[c];
    }
    B[4] = max;
    B[5] = min;
}

