#include<bits/stdc++.h>
using namespace std;

// printing the array. 
void printarr(int arr[],int n) {
    for(int i = 0; i < n;i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

// insertion_sort
void insertSort(int arr[],int n) {
    for(int i = 0 ; i < n;i++) {
        int temp = i;
        for(int j = i-1; j >= 0;j--) {
            if(arr[j] < arr[temp]) {
                continue;
            } else {
                swap(arr[j],arr[temp]);
                temp--;
            }
        }
    }
}

// merge-sort
void merge(int arr[],int fstart,int mid,int end) {
    int arr1size = mid - fstart + 1;
    int arr2size = end - mid;
    int arr1[arr1size];
    int arr2[arr2size];
    for(int i = 0;i<arr1size;i++) {
        arr1[i] = arr[fstart + i];
    }
    for(int j = 0;j<arr2size;j++) {
        arr2[j] = arr[mid + 1 + j];
    }
    int start1 = 0;
    int start2 = 0;
    int start = fstart;
    while(start1 < arr1size && start2 < arr2size) {
        if(arr1[start1] < arr2[start2]) {
            arr[start] = arr1[start1];
            start1++;
        } else {
            arr[start] = arr2[start2];
            start2++;
        }
        start++;
    }

    while (start1 < arr1size) {
        arr[start] = arr1[start1];
        start1++;
        start++;
    }

    while(start2 < arr2size) {
        arr[start] = arr2[start2];
        start2++;
        start++;
    }
}   

void mergesort(int arr[],int s,int e) {
    if (s >= e) {
        return;
    }
    int mid = s + (e-s)/2;
    mergesort(arr,s,mid);
    mergesort(arr,mid+1,e);
    merge(arr,s,mid,e);
}

// heap sort
void heapify(int arr[],int n,int i) {
    int largest = i;
    int l = 2*i+1;
    int r = 2*i+2;
    if(l < n && arr[l] > arr[largest]) {
        largest = l;
    }
    if(r < n && arr[r] > arr[largest]) {
        largest = r;
    }
    if(largest != i) {
        swap(arr[i],arr[largest]);
        heapify(arr,n,largest);
    }
}

void heapsort(int arr[], int n) {
    for(int i = n/2-1;i>=0;i--) {
        heapify(arr,n,i);
    }
    for(int i = n - 1; i > 0;i--) {
        swap(arr[0],arr[i]);
        heapify(arr,i,0);
    }
}

// quick sort
int part(int arr[],int start,int end) {
    int i = start - 1;
    for(int j = start;j <= end-1;j++) {
        if(arr[j] < arr[end]) {
            i++;
            swap(arr[i],arr[j]);
        }
    }
    swap(arr[i+1],arr[end]);
    return (i + 1);
}

void quicksort(int arr[],int start,int end) {
    if(start < end) {
        int partition = part(arr,start,end);
        quicksort(arr,start,partition-1);
        quicksort(arr,partition+1,end);
    }
}

// choose your algorithm :)
int main() {
    int n;
    cin >> n;
    int arr[n];
    for(int i = 0; i < n;i++) {
        int mem;
        cin >> mem;
        arr[i] = mem;
    }
    // insertSort(arr,n);
    // mergesort(arr,0,n-1);
    // heapsort(arr,n);
    // quicksort(arr,0,n-1);
    printarr(arr,n);
}