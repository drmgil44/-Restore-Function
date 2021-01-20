#include <stdlib.h>
#include <stdio.h>
#include <string>
class string;
using namespace std;

int g1 = 1;
int g2 = 2;

class TestA {
    int i;
    int j;
    int aFunc1(){
        return 1;
    }
    void aFunc2(bool flag){
        flag = true;
    }
};

class TestB{
    double p;
    double q;
    void bFunc1(char c, int x, string s){
        s = "hel";
    }
};

int test1(int a, int *b, int c[3], double d[]){
    c[0] = 1;
    return a;
}

void test2(bool a, char b, short c, int d, long e, long long e2, float f, double g, long double h){
    a = 1;
}

int main(){
    return 0;
}

