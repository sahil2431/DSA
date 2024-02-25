#include<iostream>
#include<queue>
using namespace std;

class stack {
    queue<int> q1,q2;
public:
    
    void push() {
        int data;
        cout<<"Enter data: ";
        cin>>data;
        q2.push(data);

        while(!q1.empty()) {
            q2.push(q1.front());
            q1.pop();

        }

        queue<int> q = q1;
        q1 = q2;
        q2 = q;
    }

    void pop() {
        if(q1.empty() ) {
            cout<<"Stack underflow!\n";
            return;
        }
        cout<<"Deleted element: "<<q1.front();
        cout<<endl;
        q1.pop();
        return;
    }

    int peek() {
        if(q1.empty() ) {
            cout<<"Stack underflow!\n";
            return -1;
        }
        return q1.front();
    }
};

int main() {
	int choice;
	printf("1) Popn2) Pop\n3) Exit\n");
	stack s;
	do {
		printf("Enter: ");
		scanf("%d",&choice);
		
		switch(choice) {
			case 1:
				s.push();
				break;
			case 2:
				s.pop();
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