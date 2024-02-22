#include<iostream>
#include<vector>
#include<string>
using namespace std;

vector<char> stack;
int TOP =-1;

//Precedance table
int precedance(char ch) {
    if(ch == '+' || ch == '-') return 1;
    else if(ch == '*' || ch == '/') return 2;
    else if(ch == '^') return 3;
    else if(ch == '(') return 5;
}

//Compare the precedance of character with top of the stack
bool isPrecedance(char ch) {
    if(ch == ')') return 0;
    if(stack[TOP] == '(') return 1;
    else if(precedance(ch) > precedance(stack[TOP])) return 1;
    return 0;
}

//Check the character is opretor or not
bool isOperator(char ch) {
    if(ch == '+' || ch == '-' || ch == '*' || ch == '/' || ch == ')' || ch =='(' || ch == '^') {
        return 1;
    }
    return 0;
}
//check that stack is Empty or not
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
        stack.push_back(ch);
        return ;
    }
}

char pop() {
     if(TOP == -1) {
        return ' ';          //Stack underflow
    }
    else {
        char ch = stack[TOP];
        stack.pop_back();
        TOP--;
        return ch; //return the top operator of the stack
    }
}

int main() {
    string infix_exp = "a+(b/c^d)*f*(h^g^i-j)";
    int size = infix_exp.size();
    string postfix_exp = "";
    int i = 0;
    
    while(i<size) {
        if(!isOperator(infix_exp[i])) {
            postfix_exp += infix_exp[i];
            i++;
         
        }
        else {
            if(infix_exp[i] == ')') {
                while(!isEmpty() && stack[TOP] != '(') {
                    postfix_exp += pop();
                }
                if(!isEmpty()) pop(); // Pop '('
                i++;
            }
            else {
                if(isEmpty() || isPrecedance(infix_exp[i])) {
                    push(infix_exp[i]);
                    i++;
                }
                else {
                    postfix_exp += pop();
                }
            }

        }
        
    }
    
    while(!isEmpty()) {
        if(stack[TOP] == '(' || stack[TOP] == ')') pop();
        else postfix_exp += pop();
    }
    cout<<"Postfix Expression: "<<postfix_exp;
    return 0;

}