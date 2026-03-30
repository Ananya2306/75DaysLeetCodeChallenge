#include <stdlib.h>
#include <stdbool.h>

#define MAX 100

typedef struct {
    int inStack[MAX];
    int outStack[MAX];
    int inTop;
    int outTop;
} MyQueue;

MyQueue* myQueueCreate() {
    MyQueue* obj = (MyQueue*)malloc(sizeof(MyQueue));
    obj->inTop = -1;
    obj->outTop = -1;
    return obj;
}

void myQueuePush(MyQueue* obj, int x) {
    obj->inStack[++(obj->inTop)] = x;
}

void transfer(MyQueue* obj) {
    while (obj->inTop != -1) {
        obj->outStack[++(obj->outTop)] = obj->inStack[(obj->inTop)--];
    }
}

int myQueuePop(MyQueue* obj) {
    if (obj->outTop == -1) {
        transfer(obj);
    }
    return obj->outStack[(obj->outTop)--];
}

int myQueuePeek(MyQueue* obj) {
    if (obj->outTop == -1) {
        transfer(obj);
    }
    return obj->outStack[obj->outTop];
}

bool myQueueEmpty(MyQueue* obj) {
    return (obj->inTop == -1 && obj->outTop == -1);
}

void myQueueFree(MyQueue* obj) {
    free(obj);
}