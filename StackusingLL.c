#include<stdio.h>

struct Node {
	int val;
	struct Node* next;
};

struct Node* createNode(int data) {
	struct Node* ptr = (struct Node*) malloc (sizeof(struct Node));
	ptr->val = data;
	ptr->next = NULL;
	return ptr;
}

struct Node* top=NULL;

void push() {
	int data;
	printf("Enter data: ");
	scanf("%d",&data);
	struct Node* new_node = createNode(data);
	if(top==NULL) new_node->next = NULL;
	else new_node->next = top;
	
	top=new_node;
	
	printf("Data inserted!\n"); 
	
}

void pop() {
	if(top == NULL) {
		printf("Stack underflow!\n");
		return;
	}
	struct Node* temp = top;
	top=top->next;
	printf("Deleted data: %d\n",temp->val);
	free(temp);
	
}

void print() {
	if(top == NULL) {
		printf("Stack underflow!\n");
		return;
	}
	struct Node* temp = top;
	printf("Elements of stack: ");
	while(temp != NULL) {
		printf("%d ",temp->val);
		temp= temp->next;
	}
	printf("\n");
	
}

int main() {
	int choice;
	printf("1) Push\n2) Pop\n3) Print\n4) Exit\n");
	
	do {
		printf("Enter: ");
		scanf("%d",&choice);
		
		switch(choice) {
			case 1:
				push();
				break;
			case 2:
				pop();
				break;
			case 3:
				print();
				break;
			case 4:
				printf("Exiting!\n");
				break;
			default:
				printf("Wrong choice Try again!\n");
		}
	}while(choice != 4);
	
	return 0;
}
