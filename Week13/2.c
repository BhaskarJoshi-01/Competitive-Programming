#include <stdio.h>

void swap(float *a,float *b){
    float temp = *a;
    *a = *b;
    *b = temp;
}

void merge(float *arr,int l ,int m, int r){
    int n1 = m-l+1;
    int n2 = r-m;
    float L[n1],R[n2];
    for(int i=0;i<n1;i++){
        L[i] = arr[l+i];
    }
    for(int j=0;j<n2;j++){
        R[j] = arr[j+m+1];
    }
    int i=0,j=0,k=l;
    while(i<n1&&j<n2){
        if(L[i] < R[j]){
            arr[k] = L[i];
            i++;
            k++;
        }
        else{
            arr[k] = R[j];
            j++;
            k++;
        }
    }
    while(i<n1){
        arr[k] = L[i];
        i++;
        k++;
    }
    while(j<n2){
        arr[k] = R[j];
        j++;
        k++;
    }
}

void selection_sort(float *arr,int n){
    for(int i=0;i<n;i++){
        int temp = i;
        for(int j=i;j<n;j++){
            if(arr[temp] > arr[j]){
                temp = j;
            }
        }
        swap(&arr[i],&arr[temp]);
    }
}

void bubble_sort(float *arr, int n){
    for(int i=0;i<n;i++){
        for(int j=1;j<n;j++){
            if(arr[j-1]>arr[j]){
                swap(&arr[j-1],&arr[j]);
            }
        }
    }
}

void insertion_sort(float *arr,int n){
    for(int i=0;i<n;i++){
        for(int j=i;j>0;j--){
            if(arr[j-1]>arr[j]){
                swap(&arr[j-1],&arr[j]);
            }
        }
    }
}

void merge_sort(float *arr,int l, int r){
    if(l<r){
        int m = (l+r)>>1;
        merge_sort(arr,l,m);
        merge_sort(arr,m+1,r);
        merge(arr,l,m,r);
    }
}

int main(){
    int n;
    scanf("%d",&n);
    float arr[n];
    for(int i=0;i<n;i++){
        scanf("%f",&arr[i]);
    }
    // selection_sort(arr,n);
    // bubble_sort(arr,n);
    // insertion_sort(arr,n);
    merge_sort(arr,0,n-1);
    for(int i=0;i<n;i++){
        printf("%0.0f ", arr[i]);
    }
    printf("\n");
}