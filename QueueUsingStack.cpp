#include<iostream>
using namespace std;

class node {
public:
    int data;
    node* next;

    node(int val) {
        data = val;
        next = NULL;
    }
};

class stack {
    
public:
    node* top = NULL;
    bool isEmpty() {
        if(top == NULL) return 1;
        return 0;
    }
    void push(int val) {
        if(isEmpty()) {
            top = new node(val);
        }
        else {
            node* new_node = new node(val);
            new_node->next = top;
            top = new_node;
        }
    }

    int pop() {
        if(isEmpty()) {
            return -1;
        }
        else {
            int delVal = top->data;
            node* temp = top;
            top = top->next;
            free(temp);
            return delVal;
        }
    }
};

class queue {
public:
    stack stack1;
    stack stack2;

    void enqueue() {
        int val;
        cout<<"Enter data: ";
        cin>>val;
        stack1.push(val);
        return;
    }
 
    void dequeue() {
        if(stack1.isEmpty() && stack2.isEmpty()) {
            cout<<"Queue underflow!\n";
            return;
        }
        if(stack2.isEmpty()) {
            while(!stack1.isEmpty()) {           //all elements of stack1 will be pop out to stack2
                stack2.push(stack1.pop());
            }
        }
        cout<<"Delted element: "<<stack2.pop()<<endl;
        return;
    }

};

int main() {
	int choice;
	printf("1) Enqueue\n2) Dequeue\n3) Exit\n");
	queue que;
	do {
		printf("Enter: ");
		scanf("%d",&choice);
		
		switch(choice) {
			case 1:
				que.enqueue();
				break;
			case 2:
				que.dequeue();
				break;
			/* case 3:
				print();
				break; */
			case 3:
				printf("Exiting!\n");
				break;
			default:
				printf("Wrong choice Try again!\n");
		}
	}while(choice != 3);
	
	return 0;
}
