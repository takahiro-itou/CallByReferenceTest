#if 0
g++  -o test -g -O0 -std=c++11 test.cpp
exit 0
#endif

#include <iostream>
#include <list>

void show_list(const std::list<int> * const ls)
{
    const std::list<int>::const_iterator itrEnd = ls->end();
    for (std::list<int>::const_iterator
            itr = ls->begin(); itr != itrEnd; ++ itr )
    {
        fprintf(stdout, "%d, ", *itr);
    }
    fprintf(stdout, "ls = %p\n", ls);
    return;
}

void func(std::list<int> *x)
{
    fprintf(stderr, "%p\n", x);
    x->push_back(3);
    x = new std::list<int>( {1, 2, 3, 4} );
    fprintf(stderr, "%p\n", x);
    x->push_back(5);
    show_list(x);
}

int main(int argc, char * argv[])
{
    std::list<int>   a = { 1, 2 };
    std::list<int> * pa = &a;

    show_list(pa);      //  1, 2
    func(pa);
    show_list(pa);      //  1,2,3,4,5 ? => 正解は 1,2,3,
}
