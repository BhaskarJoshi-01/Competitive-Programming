#include <bits/stdc++.h>

void swap(float *a, float *b){
    float temp = *a;
    *a = *b;
    *b = temp;
}

int partition(float *arr,int l,int r){
    int pivot = arr[r];
    int i = l;
    for(int j=l;j<=r-1;j++){
        if(arr[j] < pivot){
            swap(&arr[j],&arr[i]);
            i++;
        }
    }
    swap(&arr[i],&arr[r]);
    return i;
}

void quick_sort(float *arr,int l,int r){
    if(l<r){
        int part = partition(arr,l,r);
        quick_sort(arr,l,part-1);
        quick_sort(arr,part+1,r);
    }
}

int main(){
    int n;
    std::cin >> n;
    float arr[n];
    for(int i=0;i<n;i++){
        std::cin >> arr[i];
    }
    quick_sort(arr,0,n-1);
    for(int i=0;i<n;i++){
        std::cout << arr[i] << " ";
    }
    std::cout<<"\n";
}