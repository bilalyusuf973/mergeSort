#include <iostream>
#include<vector>
using namespace std;
void merge(int arr[], int s, int mid, int e){
    int len1 = mid-s+1,  len2 = e-mid;
    int *left = new int[len1];
    int *right = new int[len2];

    int k = s;

    for(int i=0;i<len1;i++){
        left[i] = arr[k++];
    }

    for(int i=0;i<len2;i++){
        right[i] = arr[k++];
    }

    k = s;
    int i = 0,  j = 0;
    while(i<len1 && j<len2){
        if(left[i]>right[j]){
            arr[k++] = right[j++];
        }
        else{
            arr[k++] = left[i++];
        }
    }

    while(i<len1){
        arr[k++] = left[i++];
    }
    while(j<len2){
        arr[k++] = right[j++];
    }

    delete []left;
    delete []right;

    return;
}
void mergeSort(int arr[], int s, int e){
    if(s>=e){
       return; 
    }
    int mid = s+(e-s)/2;
    mergeSort(arr, s, mid);
    mergeSort(arr, mid+1, e);
    merge(arr, s, mid, e);
}
int main()
{
    int arr[9]={9,8,7,6,5,4,3,2,1};
    mergeSort(arr,0,8);
    for(int i=0;i<9;i++){
        cout<<arr[i]<<" ";
    }    
    return 0;
} 