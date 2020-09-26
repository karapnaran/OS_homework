#include <iostream>
#include <algorithm>
#include "complex.h"
using namespace std;

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
    sort(a,a+N);
    for(int i=0; i<N; ++i)
    {
        cout<<a[i].AbsoluteValue()<<endl;
    }
    return 0;
}
