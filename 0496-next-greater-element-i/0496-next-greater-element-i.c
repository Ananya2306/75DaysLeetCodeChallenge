#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int data[1000];
    int top;
} Stack;

void push(Stack *s, int val) {
    s->data[++s->top] = val;
}

int pop(Stack *s) {
    return s->data[s->top--];
}

int peek(Stack *s) {
    return s->data[s->top];
}

int isEmpty(Stack *s) {
    return s->top == -1;
}

int* nextGreaterElement(int* nums1, int nums1Size,
                        int* nums2, int nums2Size,
                        int* returnSize) {

    int map[10001];

    // Initialize all values with -1
    for (int i = 0; i <= 10000; i++) {
        map[i] = -1;
    }

    Stack s;
    s.top = -1;

    // Monotonic stack
    for (int i = nums2Size - 1; i >= 0; i--) {

        while (!isEmpty(&s) && peek(&s) <= nums2[i]) {
            pop(&s);
        }

        if (!isEmpty(&s)) {
            map[nums2[i]] = peek(&s);
        }

        push(&s, nums2[i]);
    }

    int *ans = (int*)malloc(nums1Size * sizeof(int));

    for (int i = 0; i < nums1Size; i++) {
        ans[i] = map[nums1[i]];
    }

    *returnSize = nums1Size;
    return ans;
}