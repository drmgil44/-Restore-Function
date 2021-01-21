#include <stdlib.h>
#include <stdio.h>
#include <string>

using namespace std;

class string;

int g1 = 1;
int g2 = 2;

class TestA {
    int i1;
    string s1;
    int aFunc1(){
        return 1;
    }
    void aFunc2(bool flag){
        flag = true;
    }
};

class TestB{
    char c2;
    double d2;
    TestA a2;
    void bFunc1(char x, double y, TestA z){
        c2 = x;
        d2 = y;
        a2 = z;
    }
};

int test1(int *b, int c[3], double d[]){
    c[0] = 1;
    return a;
}

void test2(bool a, char b, short c, int d, long e, long long e2, float f, double g, long double h){
    a = 1;
}

int main(){
    return 0;
}

