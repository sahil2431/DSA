#include<iostream>
#include<vector>
using namespace std;

void printArray(vector<int> &vec,int n) {
    for(int i= 0;i<n;i++) {
        cout<<vec[i]<<" ";
    }
    cout<<endl;
}

int max_element(vector<int> &a, int size) {
    int max = a[0];
    for(int i =1;i<size;i++) {
        if(a[i]>max) max = a[i];
    }

    return max;
}

void countSort(vector<int> &a , int n) {
    int max = max_element(a , n);  //Find the maximum element
    int *count = new int[max+1];   //Count array

    //Initializing the element of array b with 0
    for(int i=0;i<max+1;i++){   
        count[i] = 0;
    }
     //increment the element of array b of index a[i] 
    for(int i=0;i<n;i++) {
        count[a[i]] ++;        
    }
    
    /* for(int i= 0;i<max+1;i++) {
        cout<<b[i]<<" ";
    }
    cout<<endl;
 */
    int i = 0;   //pointer for count array
    int j = 0;   //pointer for main array
    while(i<max+1) {
        if(count[i] != 0) {
            while(count[i] != 0) {
                a[j] = i;
                j++;
                count[i]--;
            }
        }
        i++;
    }
}


int main() {
    vector<int> vec = {3,1,9,7,1,2,4};
    int n = vec.size();
    cout<<"Unsorted Array: ";
    printArray(vec, n);
    
    countSort(vec  , n);
    cout<<"Sorted Array: ";
    printArray(vec,n);
    return 0;
}