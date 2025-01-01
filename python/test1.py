#!/usr/bin/env  python3

def func(x):
    print(id(x))
    x.append(3)
    x = [1, 2, 3, 4]
    x.append(5)
    print(id(x))
    print(f"@func.x = {x}")

a = [1, 2]
print(f"@main.a = {a}")
func(a)
print(f"@main.a = {a}")
