#include <stdlib.h>

typedef struct {
    int *small;   // max heap
    int *large;   // min heap
    int smallSize;
    int largeSize;
    int capacity;
} MedianFinder;

/* ---------- Heap Helper Functions ---------- */

void swap(int *a, int *b){
    int t=*a; *a=*b; *b=t;
}

/* Max Heap Insert */
void maxHeapInsert(MedianFinder* obj, int val){
    int i = obj->smallSize++;
    obj->small[i] = val;

    while(i>0){
        int p=(i-1)/2;
        if(obj->small[p] >= obj->small[i]) break;
        swap(&obj->small[p], &obj->small[i]);
        i=p;
    }
}

/* Min Heap Insert */
void minHeapInsert(MedianFinder* obj, int val){
    int i = obj->largeSize++;
    obj->large[i] = val;

    while(i>0){
        int p=(i-1)/2;
        if(obj->large[p] <= obj->large[i]) break;
        swap(&obj->large[p], &obj->large[i]);
        i=p;
    }
}

/* Max Heap Pop */
int maxHeapPop(MedianFinder* obj){
    int top = obj->small[0];
    obj->small[0] = obj->small[--obj->smallSize];

    int i=0;
    while(1){
        int l=2*i+1,r=2*i+2,largest=i;

        if(l<obj->smallSize && obj->small[l]>obj->small[largest])
            largest=l;
        if(r<obj->smallSize && obj->small[r]>obj->small[largest])
            largest=r;

        if(largest==i) break;

        swap(&obj->small[i],&obj->small[largest]);
        i=largest;
    }
    return top;
}

/* Min Heap Pop */
int minHeapPop(MedianFinder* obj){
    int top=obj->large[0];
    obj->large[0]=obj->large[--obj->largeSize];

    int i=0;
    while(1){
        int l=2*i+1,r=2*i+2,smallest=i;

        if(l<obj->largeSize && obj->large[l]<obj->large[smallest])
            smallest=l;
        if(r<obj->largeSize && obj->large[r]<obj->large[smallest])
            smallest=r;

        if(smallest==i) break;

        swap(&obj->large[i],&obj->large[smallest]);
        i=smallest;
    }
    return top;
}

/* ---------- Main Functions ---------- */

MedianFinder* medianFinderCreate() {
    MedianFinder* obj = malloc(sizeof(MedianFinder));

    obj->capacity = 50000;
    obj->small = malloc(sizeof(int)*obj->capacity);
    obj->large = malloc(sizeof(int)*obj->capacity);

    obj->smallSize=0;
    obj->largeSize=0;

    return obj;
}

void medianFinderAddNum(MedianFinder* obj, int num) {

    if(obj->smallSize==0 || num <= obj->small[0])
        maxHeapInsert(obj,num);
    else
        minHeapInsert(obj,num);

    /* balance heaps */
    if(obj->smallSize > obj->largeSize + 1)
        minHeapInsert(obj, maxHeapPop(obj));

    if(obj->largeSize > obj->smallSize)
        maxHeapInsert(obj, minHeapPop(obj));
}

double medianFinderFindMedian(MedianFinder* obj) {

    if(obj->smallSize > obj->largeSize)
        return obj->small[0];

    return ((double)obj->small[0] + obj->large[0]) / 2.0;
}

void medianFinderFree(MedianFinder* obj) {
    free(obj->small);
    free(obj->large);
    free(obj);
}