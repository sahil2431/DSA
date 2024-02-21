#include<stdio.h>
#include <stdbool.h>

#define MAX 5

int queue[MAX] , rear =-1 , front = -1;

bool isFull() {
	if((rear == MAX-1 && front == 0) || rear == front-1){
		return 1;
	}
	
	else return 0;
}

bool isEmpty() {
	if(front == -1) {
		return 1;
	}
	
	else return 0;
}

void enqueue() {
	if(isFull()) {
		printf("Queue overflow!\n");
	}
	
	else {
		int data;
    	printf("Enter data: ");
    	scanf("%d",&data);
    	if(front == -1) {
    		front =0;
    		rear = 0;
		}
    	else if(front>0 && rear == MAX-1) rear=0;
    	else rear++;
    	
    	queue[rear] = data; 
    	printf("Data inserted.\n");
	} 
}

void dequeue() {
	if(isEmpty()) printf("Queue underflow!\n");
	else {
		printf("Deleted element: %d\n",queue[front]);
		if(front == rear) {
			front = -1;
			rear = -1;
		}
		
		else if(front == MAX-1 && rear >=0) front = 0;
		else front ++;
	}
}

void print() {
	if(isEmpty()) printf("Queue underflow!\n");
	else {
		int i= front;
		printf("Queue is: ");
		while(i != rear) {
			printf("%d ",queue[i]);
			if(i == MAX-1) i = 0;
			else i++;
		}
		printf("%d\n",queue[i]);
	}
	return;
}

int main() {
	int choice;
	printf("1) Enqueue\n2) Dequeue\n3) Print\n4) Quit\n");
	
	do {
		printf("Enter: ");
		scanf("%d",&choice);
		
		switch (choice) {
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
	} while(choice != 4);
	
	return 0;
}
