#include<iostream>
#include<vector>
using namespace std;

void printArray(vector<int> &vec,int n) {
    for(int i= 0;i<n;i++) {
        cout<<vec[i]<<" ";
    }
    cout<<endl;
}

int partition(vector<int> &a , int low , int high) {
    int pivot = a[low]; 
    int i = low + 1;
    int j = high;
    int temp;
    do {
        while(a[i] <= pivot) i++;      //finding element greter than pivot
        while(a[j] > pivot) j--;       //finding element less than or equal to pivot

        // swap a[i] and a[j]
        if(i<j) {
            temp = a[i];
            a[i] = a[j];
            a[j] = temp;
        }

    }while(i<j);

    //swap pivot and the a[j]
    temp = a[low];
    a[low] = a[j];
    a[j] = temp;

    return j;   //partition index
}

void quickSort(vector<int> &a , int low , int high) {
    int partitionIndex;    //Index of pivot after partition
    if(low>=high) {  //Stopping condition of recursion
        return;
    }
    partitionIndex = partition(a , low , high);
    printArray(a,10);
    quickSort(a, low, partitionIndex -1 );     //sort left sub array
    quickSort(a , partitionIndex + 1 , high);  //sort right sub array
    
}

int main() {
    vector<int> vec = {2,1,3,9,4,4,8,7,5,6};
    int n = vec.size();
    cout<<"Unsorted Array: ";
    printArray(vec, n);              
    quickSort(vec , 0 ,n-1);
    cout<<"Sorted Array: ";
    printArray(vec,n);
    return 0;
}