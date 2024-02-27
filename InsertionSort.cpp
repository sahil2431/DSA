#include<iostream>
#include<vector>
using namespace std;

void print(vector<int> &vec , int size) {
    for(int i=0;i<size;i++) {
        cout<<vec[i]<<" ";
    }
    cout<<"\n";
}
void insertionSort(vector<int> &vec ,int n ) {
    int key,j;
    //Loop for passes
    for (int i = 1; i < n; i++)
    {
        key = vec[i];
        j = i-1;
        //loop for comparison
        while (j>= 0 && vec[j]>key)    //it will give ascending order .
        {                             //For descending order replace the condition vec[j]>key with vec[j]<key.
            vec[j+1] = vec[j];
            j--;
        }
        vec[j+1] = key;
    }
    
}

int main() {
    vector<int> vec = {2,1,9,5,3,15,54,69,25,14,32,100,154,84,52};
    int n = vec.size();
    cout<<"Unsorted Array: ";
    print(vec, n);              //print the sorted array
    insertionSort(vec , n);
    cout<<"Sorted Array: ";
    print(vec,n);
    return 0;
}