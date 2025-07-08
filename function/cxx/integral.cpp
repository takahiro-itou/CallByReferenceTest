#if 0
g++  -o integral -g -O0 -std=c++11 integral.cpp
exit 0
#endif

#include    <iostream>
#include    <math.h>

const   double  PI  = 3.14159265359;

/**
**  関数ポインタ型。
**/

typedef double (* FuncPointer)(double x);

double  integral(FuncPointer f, double a, double b, double h)
{
    const int n = (b - a) / h;
    double  sum = 0.0;
    double  v1, v2;

    v2  = (* f)(a);
    for ( int i = 1; i < n; ++ i ) {
        v1  = v2;
        v2  = (* f)(a + i * h);
        double  daikei = (v1 + v2) * h / 2.0;
        sum += daikei;
    }
    return ( sum );
}

//  積分したい関数。    //

double  func1(double x) {
    return ( x );
}

double  func2(double x) {
    return ( cos(x * PI / 2.0) );
}

int main(int argc, char * argv[])
{
    //  f(x) = x の積分 => x^2/2    //
    //  [0,1] 上 => 1/2             //
    std::cout   <<  integral(func1, 0, 1, 0.001)
                <<  std::endl;

    //  f(x) = sin(x * PI / 2) の積分   //
    //  => cos(x * PI / 2) * (2 / PI)   //
    //  [0,1] 上 => 2 / PI = 0.63662..  //
    std::cout   <<  integral(func2, 0, 1, 0.001)
                <<  std::endl;
}
