#include<iostream>
using namespace std;
int stack[10];
int TOP = -1;

bool isEmpty() {
    if(TOP == -1) {
        return 1;
    }
}
bool push(char ch) {
    if(TOP == 99) {
        return 0;
    }
    else {
        TOP++;
        stack[TOP] = ch;
        return  1;
    }
}

bool pop() {
    if(TOP == -1) {
        return 0;          //Stack underflow
    }
    else {
        TOP--;
        return 1;
    }
}
int main() {
    string exp = "7-(8(3*9)+11+12))-8)";
    for(int i=0;i<exp.size();i++) {
        if(exp[i] == '(') {
            if(!push('(')) {
                cout<<"Stack Overflow! Big expression!\n";
                exit(0);
            }
        }
        else if(exp[i] == ')') {
            if(!pop()) {
                cout<<"Parenthesis is unbalanced!\n";
                exit(0);
            }
        }
    }
    if(isEmpty()) cout<<"Parenthesis is balanced!\n";
    else cout<<"Parenthesis is unbalanced!\n";
    return 0;
}