#include<iostream>
using namespace std;

int fibonacci(int n) {
    if(n==0) return 0;
    if(n==1) return 1;

    return fibonacci(n-1) + fibonacci(n-2);
} 

int main() {
    int num;
    cout<<"Enter a number: ";
    cin>>num;

    cout<<"Fibonacci number of "<<num<<" is: "<<fibonacci(num);
    return 0;

}