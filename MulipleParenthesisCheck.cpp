#include<iostream>
using namespace std;
int stack[100];
int TOP = -1;

bool isEmpty() {
    if(TOP == -1) {
        return 1;
    }
    return 0;
}
void push(char ch) {
    if(TOP == 99) {
        return;
    }
    else {
        TOP++;
        stack[TOP] = ch;
        return ;
    }
}

bool match( char ch1 , char ch2) {
    if(ch1 == '(' && ch2 == ')') return 1;
    if(ch1 == '{' && ch2 == '}') return 1;
    if(ch1 == '[' && ch2 == ']') return 1;

    return 0;
}
void pop() {
    if(TOP == -1) {
        return;          //Stack underflow
    }
    else {
        TOP--;
        return;
    }
}
int main() {
    string exp = "[58*99(7-8)*{9}]";
    for(int i=0 ;i<exp.size();i++) {

        if(exp[i] == '(' || exp[i] == '{' || exp[i] == '[') {
           push(exp[i]);
        }
        
        else if(exp[i] == ')' || exp[i] == '}' || exp[i] == ']') {
            if(isEmpty()) {
                cout<<"Parenthesis is unbalanced!\n";
                exit(0);
            }

            if(!match(stack[TOP],exp[i])) {
                cout<<"Parenthesis is unbalanced!\n";
                exit(0);
            }
            
            pop();
        }
    }
    if(isEmpty()) cout<<"Parenthesis is balanced!\n";
    else cout<<"Parenthesis is unbalanced!\n";
    return 0;
    }

