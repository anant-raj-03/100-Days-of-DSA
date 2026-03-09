#include <stdlib.h>

typedef struct {
    int *heap;
    int size;
    int capacity;
    int k;
} KthLargest;

void swap(int *a, int *b){
    int t=*a;
    *a=*b;
    *b=t;
}

void heapifyUp(KthLargest* obj,int i){
    while(i>0){
        int parent=(i-1)/2;
        if(obj->heap[parent] <= obj->heap[i])
            break;
        swap(&obj->heap[parent],&obj->heap[i]);
        i=parent;
    }
}

void heapifyDown(KthLargest* obj,int i){
    while(1){
        int smallest=i;
        int left=2*i+1;
        int right=2*i+2;

        if(left<obj->size && obj->heap[left]<obj->heap[smallest])
            smallest=left;

        if(right<obj->size && obj->heap[right]<obj->heap[smallest])
            smallest=right;

        if(smallest==i)
            break;

        swap(&obj->heap[i],&obj->heap[smallest]);
        i=smallest;
    }
}

void insert(KthLargest* obj,int val){
    obj->heap[obj->size++]=val;
    heapifyUp(obj,obj->size-1);
}

void removeMin(KthLargest* obj){
    obj->heap[0]=obj->heap[obj->size-1];
    obj->size--;
    heapifyDown(obj,0);
}

KthLargest* kthLargestCreate(int k, int* nums, int numsSize) {
    
    KthLargest* obj=(KthLargest*)malloc(sizeof(KthLargest));
    
    obj->heap=(int*)malloc(sizeof(int)*(numsSize+10000));
    obj->size=0;
    obj->k=k;
    obj->capacity=numsSize+10000;

    for(int i=0;i<numsSize;i++){
        insert(obj,nums[i]);
        if(obj->size>k)
            removeMin(obj);
    }

    return obj;
}

int kthLargestAdd(KthLargest* obj, int val) {
    
    insert(obj,val);
    
    if(obj->size>obj->k)
        removeMin(obj);
    
    return obj->heap[0];
}

void kthLargestFree(KthLargest* obj) {
    free(obj->heap);
    free(obj);
}