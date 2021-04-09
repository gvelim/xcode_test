//
//  main.c
//  liner
//
//  Created by George  on 09/04/2021.
//

#include <stdio.h>

// forward declarations
typedef struct AnObject sObj;   		// Object type
void set(sObj* this, int a, int b);
int add(sObj* this);            		// Object method
void initAnObject(sObj*, int, int);  	// Object constructor


// Type declarations
typedef struct AnObject {
    int a;
    int b;
	void (*set)(sObj*, int, int);
    int (*add)(sObj*);
} sObj;

int main(int argc, const char * argv[]) {

    sObj aObj,bObj,cObj;
    
    initAnObject(&aObj, 10, 10);
    initAnObject(&bObj, 1, 1);
	initAnObject(&cObj, 5, 5);
	
	aObj.set(&aObj, 10, 12);
	
   for (int i=0; i<10; i++) {
        aObj.a += i;
        bObj.b += aObj.a;
        printf("Hello.. aObj:%d, bObj: %d, cObj: %d\n", aObj.add(&aObj), bObj.add(&bObj), cObj.add(&cObj) );
    }
    return 0;
}

/*************************/
// Functional Declarations
/*************************/


void initAnObject(sObj* so,int a, int b) {
    so->add = &add;
	so->set = &set;
    so->set(so, a, b);
    return;
}

int add(sObj* this) {
    return this->a + this->b;
}

void set(sObj* this, int a, int b) {
	this->a = a;
	this->b = b;
}
