#include "test_struct.h"

class TestCteste {
    int i;
    int j;
    int cFunc1(TestB b){
        b.a.q = 1.0;
        return 1;
    }
    void cFunc2(bool flag){
        flag = true;
    }
};


int main(){
    return 0;
}