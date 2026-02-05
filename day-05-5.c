//Problem: A system receives two separate logs of user arrival times from two different servers. 
//Each log is already sorted in ascending order. 
//Your task is to create a single chronological log that preserves the correct order of arrivals.

#include <stdio.h>
int main(){
    int p,q;
    printf("Enter size of first array: ");
    scanf("%d",&p); 
    printf("Enter size of second array: ");
    scanf("%d",&q);
    int arr1[p];
    int arr2[q];
    for(int i=0;i<p;i++){
        printf("Enter element %d of first array: ",i+1);
        scanf("%d",&arr1[i]);
    }
    for(int i=0;i<q;i++){
        printf("Enter element %d of second array: ",i+1);
        scanf("%d",&arr2[i]);
    }
    int arr3[p+q];
//add elemens in ascending order
    int i=0,j=0,k=0;
    while(i<p && j<q){
        if(arr1[i]<arr2[j]){
            arr3[k]=arr1[i];
            i++;
        }
        else{
            arr3[k]=arr2[j];
            j++;
        }
        k++;
    }
    while(i<p){
        arr3[k]=arr1[i];
        i++;
        k++;
    }
    while(j<q){
        arr3[k]=arr2[j];
        j++;
        k++;
    }
    printf("Merged array in ascending order: ");
    for(int i=0;i<p+q;i++){
        printf("%d ",arr3[i]);
    }
    return 0;
}
