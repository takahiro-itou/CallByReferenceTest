#!/usr/bin/env  python3

import  math

##  関数 f を [a,b] 上で積分する
def integral(f, a, b, h = 0.001):
    sum = 0.0
    v1  = None
    v2  = f(a)
    x   = a
    i   = 0

    while (a + i * h <= b):
        v1 = v2
        v2 = f(a + i * h)
        i  += 1
        daikei = (v1 + v2) * h / 2.0
        sum += daikei;
    # End While
    return  sum
# End Def (integral)

##   積分したい関数

def func1(x):
    return  x

def func2(x):
    return  math.cos(x * math.pi / 2.0)


##  main

print(integral(func1, 0, 1))
print(integral(func2, 0, 1))
