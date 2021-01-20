#include <stdlib.h>
#include <stdio.h>
#include <string>
using namespace std;

int g1 = 1;
int g2 = 2;

class TestA{
    int p;
    public:
        double q;
};

class TestB{
    public:
        TestA a;
        int bFunc1(int i){
            return i;
        }
};
