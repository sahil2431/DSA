#include<stdio.h>

struct node {
	int val;
	struct node* next;
};

struct node* createNode(int data) {
	struct node* ptr = (struct node*) malloc(sizeof(struct node));
	ptr->val = data;
	ptr->next = NULL;
	return ptr;	
}

struct node* f = NULL;
struct node* r = NULL;

void enqueue() {
	int data;
	printf("Enter element: ");
	scanf("%d",&data);
	struct node* ptr = createNode(data);
	if(f == NULL) {
		f=ptr;
	}
	
	else r->next  = ptr;
	
	r = ptr;
}

void dequeue() {
	if(f == NULL) printf("Queue underflow!\n");
	else {
		struct node* temp = f;
		f = f->next;
		
		printf("Deleted element: %d\n", temp->val);
		free(temp);
	}
}

void print() {
	if(f == NULL) printf("Queue underflow!\n");
	else {
		struct node* temp = f;
		printf("Queue is: ");
		while(temp != NULL) {
			printf("%d ",temp->val);
			temp = temp->next;
		}
		printf("\n");
    }
}

int main() {
	int ch;
	printf("1) Enqueue\n2) Dequeue\n3) Print\n4) Quit\n");
	
	do {
		printf("Enter: ");
		scanf("%d",&ch);
		
		switch (ch) {
			case 1:
				enqueue();
				break;
			case 2:
				dequeue();
				break;
			case 3:
				print();
				break;
			case 4:
				printf("Exiting!\n");
				break;
			default:
				printf("Wrong choice! Try again\n");
				
		}
	} while(ch != 4);
	
	return 0;
}
