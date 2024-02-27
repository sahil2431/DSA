#include<iostream>
#include<vector>
using namespace std;

void printArray(vector<int> &vec,int n) {
    for(int i= 0;i<n;i++) {
        cout<<vec[i]<<" ";
    }
    cout<<endl;
}


void bubbleSort(vector<int> &vec, int n) {
    int temp;
    for(int i = 0;i<n-1;i++) {    //loop for passes
        printf("No. of passes: %d\n",i+1);   
        
        for(int j= 0;j<n-1-i;j++) {         //loop for comparision
            if(vec[j]>vec[j+1]) {        //condition for swap  
                temp = vec[j];
                vec[j]  = vec[j+1];
                vec[j+1] = temp;
                
            }
        }
        
    }
}

void bubbleSortAdaptive(vector<int> &vec, int n) {
    int temp;
    int isSorted;
    for(int i = 0;i<n-1;i++) {    //loop for passes
        printf("No. of passes: %d\n",i+1);   
        isSorted = 1;               //A variable to check sorted array
        for(int j= 0;j<n-1-i;j++) {         //loop for comparision
            if(vec[j]>vec[j+1]) {        //condition for swap  
                temp = vec[j];
                vec[j]  = vec[j+1];
                vec[j+1] = temp;
                isSorted = 0;
            }
        }
        if(isSorted) return;   //if no swap occurs in a pass then array is sorted , hence return
    }
}


int main() {
    //vector<int> vec = {1,2,3,4,5,6,7,8,9,10};
    vector<int> vec = {25,2,36,24,1,5,84,12};
    int n = vec.size();
    cout<<"Unsorted Array: ";
    printArray(vec,n);      //print the original array
    //bubbleSortAdaptive(vec , n);
    bubbleSort(vec , n);  //Sort the array
    cout<<"Sorted Arry: ";  //print the sorted array
    printArray(vec,n);

    cout<<endl;

    return 0;

}