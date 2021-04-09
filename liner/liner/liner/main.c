//
//  main.c
//  liner
//
//  Created by George  on 09/04/2021.
//

#include <stdio.h>

// forward declarations
typedef struct AnObject sObj;   	// Object type
void set(sObj* this, int a, int b);
int add(sObj* this);            	// Object method
void initAnObject(sObj* so);    	// Object constructor

// Type declarations
typedef struct AnObject {
    int a;
    int b;
	void (*set)(sObj*, int, int);
    int (*add)(sObj* this);
} sObj;

int main(int argc, const char * argv[]) {
    // insert code here...
    int i;
    sObj aObj,bObj,cObj;
    
    initAnObject(&aObj);
    initAnObject(&bObj);
	initAnObject(&cObj);
	
	aObj.set(&aObj, 10, 10);
	bObj.set(&bObj, 1, 1);
	cObj.set(&cObj, 5, 1);
	
   for (i=0; i<10; i++) {
        aObj.a += i;
        bObj.b += aObj.a;
        printf("Hello.. aObj:%d, bObj: %d, cObj: %d\n", aObj.add(&aObj), bObj.add(&bObj), cObj.add(&cObj) );
    }
    return i;
}

/*************************/
// Functional Declarations
/*************************/


void initAnObject(sObj* so) {
    so->add = &add;
	so->set = &set;
    so->set(so, 10, 1);
    return;
}

int add(sObj* this) {
    return this->a + this->b;
}

void set(sObj* this, int a, int b) {
	this->a = a;
	this->b = b;
}
