typedef struct {
    int *heap;
    int size;
    int k;
} KthLargest;

void heapifyUp(KthLargest* obj, int index) {
    while (index > 0) {
        int parent = (index - 1) / 2;

        if (obj->heap[parent] <= obj->heap[index])
            break;

        int temp = obj->heap[parent];
        obj->heap[parent] = obj->heap[index];
        obj->heap[index] = temp;

        index = parent;
    }
}

void heapifyDown(KthLargest* obj, int index) {
    while (1) {
        int left = 2 * index + 1;
        int right = 2 * index + 2;
        int smallest = index;

        if (left < obj->size &&
            obj->heap[left] < obj->heap[smallest])
            smallest = left;

        if (right < obj->size &&
            obj->heap[right] < obj->heap[smallest])
            smallest = right;

        if (smallest == index)
            break;

        int temp = obj->heap[index];
        obj->heap[index] = obj->heap[smallest];
        obj->heap[smallest] = temp;

        index = smallest;
    }
}

KthLargest* kthLargestCreate(int k, int* nums, int numsSize) {
    KthLargest* obj = (KthLargest*)malloc(sizeof(KthLargest));

    obj->heap = (int*)malloc(sizeof(int) * (k + numsSize));
    obj->size = 0;
    obj->k = k;

    for (int i = 0; i < numsSize; i++) {
        if (obj->size < k) {
            obj->heap[obj->size] = nums[i];
            heapifyUp(obj, obj->size);
            obj->size++;
        }
        else if (nums[i] > obj->heap[0]) {
            obj->heap[0] = nums[i];
            heapifyDown(obj, 0);
        }
    }

    return obj;
}

int kthLargestAdd(KthLargest* obj, int val) {
    if (obj->size < obj->k) {
        obj->heap[obj->size] = val;
        heapifyUp(obj, obj->size);
        obj->size++;
    }
    else if (val > obj->heap[0]) {
        obj->heap[0] = val;
        heapifyDown(obj, 0);
    }

    return obj->heap[0];
}

void kthLargestFree(KthLargest* obj) {
    free(obj->heap);
    free(obj);
}

/**
 * Your KthLargest struct will be instantiated and called as such:
 * KthLargest* obj = kthLargestCreate(k, nums, numsSize);
 * int param_1 = kthLargestAdd(obj, val);
 * kthLargestFree(obj);
 */