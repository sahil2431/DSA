#include<iostream>
#include<vector>
using namespace std;

void print(vector<int> &vec , int size) {
    for(int i=0;i<size;i++) {
        cout<<vec[i]<<" ";
    }
    cout<<"\n";
}

void selectionSort(vector<int> &vec , int n) {
    int minIndex;
    //loop for passes
    for (int i = 0; i < n-1; i++)
    {
        minIndex = i;
        //loop to find index of minimum element
        for (int j = i+1; j <n ; j++)
        {
           if(vec[minIndex]>vec[j]) {
              minIndex = j;
           }
        }
        //condition of swapping
        if(minIndex != i) {
            int temp = vec[minIndex];
            vec[minIndex] = vec[i];
            vec[i] = temp;
            
        }
        
    }
    
}


int main() {
    vector<int> vec = {2,1,9,5,3,15,54,69,25,14,32,100,154,84,52};
    int n = vec.size();
    cout<<"Unsorted Array: ";
    print(vec, n);              //print the array
    selectionSort(vec , n);
    cout<<"Sorted Array: ";
    print(vec,n);              //print the sorted array
    return 0;
}