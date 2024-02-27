#include<iostream>
#include<vector>
using namespace std;

void printArray(vector<int> &vec,int n) {
    for(int i= 0;i<n;i++) {
        cout<<vec[i]<<" ";
    }
    cout<<endl;
}


void merge(vector<int> &a ,int low,int mid ,int high) {
    int i,j,k,b[high+1];
    i=low;
    j=mid+1;
    k=low;
    while(i<=mid && j<=high) {
        if(a[i]<a[j]) {
            b[k]=a[i];
            k++;
            i++;
        }
        else {
            b[k] = a[j];
            j++;
            k++;
        }
    }
    while(i<=mid) {         //if elements of right part is covered but left part has some elements 
        b[k]=a[i];
        k++;
        i++;
    }
    while(j<=high) {        //if elements of left part is covered but right part has some elements 
        b[k]=a[j];
        k++;
        j++;
    }

    for(int n = low;n<=high;n++) {
        a[n]=b[n];         //transfering sorted array b to a
    }
}

void mergeSort(vector<int> &a,int low , int high){
    if(low>=high) {
        return;
    }

    int mid = (low + high)/2;
    mergeSort(a,low,mid);        //for left part of array
    mergeSort(a,mid+1,high);     //for right part of array
    merge(a,low,mid,high);       //merging of sorted left and right part of array in sorted
}


int main() {
    vector<int> vec = {2,1,3,9,4,4,8,7,5,6};
    int n = vec.size();
    cout<<"Unsorted Array: ";
    printArray(vec, n);              
    mergeSort(vec , 0 ,n-1);
    cout<<"Sorted Array: ";
    printArray(vec,n);
    return 0;
}