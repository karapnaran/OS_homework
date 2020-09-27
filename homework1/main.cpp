#include <iostream>
#include <algorithm>
#include <random>
#include "complex.h"
using namespace std;

// Checks if the array is sorted
bool isSorted(Complex a[], int n)
{
    for(int i=0; i<n-1; ++i)
        if (a[i] > a[i+1]) return false;
    return true;
}

// Generates permuatations of the array
void shuffle(Complex a[], int n)
{
    for (int i=0; i < n; i++)
        swap(a[i], a[rand()%n]);
}

// Sorts the array using Bogo sort
void bogosort(Complex a[], int n)
{
    // if array is not sorted then shuffle the array again
    while (!isSorted(a,n))
        shuffle(a,n);
}

int main()
{
    const int N=5;
    Complex a[N];
    for(int i=0; i<N; ++i)
    {
        double real,imaginary;
        cin>>real>>imaginary;
        a[i]=Complex(real,imaginary);
    }
    bogosort(a,N);
    // Prints already sorted absolute values
    for(int i=0; i<N; ++i)
        cout<<a[i].AbsoluteValue()<<endl;
    return 0;
}
