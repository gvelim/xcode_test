//
//  main.c
//  liner
//
//  Created by George  on 09/04/2021.
//

#include <stdio.h>

// forward declarations
typedef struct AnObject sObj;   // Object type
int add(sObj* this);            // Object method
void initAnObject(sObj* so);    // Object constructor

// Type declarations
typedef struct AnObject {
    int a;
    int b;
    int (*add)(sObj* this);
} sObj;

int main(int argc, const char * argv[]) {
    // insert code here...
    int i;
    sObj aObj,bObj;
    
    initAnObject(&aObj);
    initAnObject(&bObj);
    
    for (i=0; i<10; i++) {
        aObj.a += i;
        bObj.b += aObj.a;
        printf("Hello.. aObj.a:%d, bObj.b: %d\n", aObj.add(&aObj), bObj.add(&bObj) );
    }
    return i;
}

/*************************/
// Functional Declarations
/*************************/


void initAnObject(sObj* so) {
    so->add = &add;
    so->a = 10;
    so->b = 1;
    return;
}

int add(sObj* this) {
    return this->a + this->b;
}
