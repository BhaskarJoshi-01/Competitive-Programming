#include<stdio.h>

int find_element(float* arr,int n,float num){
    int start = 0;
    int end = n-1;
    while(start <= end){
        int temp = (start+end)>>1;
        // printf("temp : %d, start : %d, end : %d \n",start,temp,end);
        if(num > arr[temp]){
            start = temp + 1;
        }
        else if (num < arr[temp]){
            end = temp - 1;
        }
        else return temp;
    }
    return -1;
}

int merge(float* arr,int l,int  m, int r){
    int n1 = m - l + 1;
    int n2 = r - m;
    float L[n1],R[n2];
    for(int i=0;i<n1;i++){
        L[i] = arr[l+i];
    }
    for(int i=0;i<n2;i++){
        R[i] = arr[m+i+1];
    }
    int i=0,j=0,k=l;
    while(i < n1 && j < n2){
        if(L[i]<=R[j]){
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
    while(i < n1){
        arr[k] = L[i];
        k++;
        i++;
    }
    while(j < n2){
        arr[k] = R[j];
        j++;
        k++;
    }
}

int mergesort(float* arr,int l, int r){
    if(l < r){
        int m = (l+r)>>1;
        mergesort(arr,l,m);
        mergesort(arr,m+1,r);
        merge(arr,l,m,r);
    }
}

int upperbound(float* arr, int n , float num){
    int start = 0;
    int end = n-1;
    int temp;
    while(start <= end){
        temp = (start+end)>>1;
        // printf("temp : %d, start : %d, end : %d \n",start,temp,end);
        if(arr[temp] > num && ( temp == 0 || num >= arr[temp-1] )){
            return temp;
        }
        else if(num < arr[temp]){
            end = temp - 1;
        }
        else{
            start = temp + 1;
        }
    }
    return temp;
}

int lowerbound(float* arr, int n , float num){
    int start = 0;
    int end = n-1;
    int temp;
    while(start <= end){
        temp = (start + end)>>1;
        if(num <= arr[temp] && ( temp == 0 || num > arr[temp-1] )){
            return temp;
        }
        else if(num > arr[temp]){
            start = temp + 1;
        }
        else{
            end = temp - 1;
        }
    }
    return temp;
}
int main(){
    int n;
    float val;
    scanf("%d%f",&n,&val);
    float arr[n];
    for(int i=0;i<n;i++){
        scanf("%f",&arr[i]);
    }
    mergesort(arr,0,n-1);
    for(int i=0;i<n;i++){
        printf("%0.0f ",arr[i]);
    }
    printf("\n");
    // int ret_val = upperbound(arr,n,val);
    // ret_val > -1?printf("%d\n",ret_val):printf("Not Found\n");
    return 0;
}