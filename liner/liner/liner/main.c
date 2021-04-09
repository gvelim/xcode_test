//
//  main.c
//  liner
//
//  Created by George  on 09/04/2021.
//

#include <stdio.h>

typedef struct ObjectOrientedDummy {
    int a;
    int b;
    int (*add)(void* this);
} sOOD;

int add(sOOD* this) {
    return this->a + this->b;
}

int main(int argc, const char * argv[]) {
    // insert code here...
    int i;
    sOOD dummy;
    
    dummy.add = (void*)&add;
    dummy.a = 10;
    dummy.b = 1;
    
    for (i=0; i<10; i++) {
        dummy.a += i;
        printf("Hello, %d World!\n", dummy.add(&dummy) );
    }
    return i;
}
