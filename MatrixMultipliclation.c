#include<stdio.h>

int main() {
	int r1,c1,r2,c2;
	printf("Enter rows of 1st matrix: ");
	scanf("%d", &r1);
	printf("Enter column of 1st matrix: ");
	scanf("%d", &c1);
	printf("Enter rows of 2nd matrix: ");
	scanf("%d", &r2);
	printf("Enter column of 2nd matrix: ");
	scanf("%d", &c2);
	
	if(c1 != r2) {
		printf("Matrix multiplication is not possible\n");
	}
	
	else {
		int mat1[r1][c1] , mat2[r2][c2] , ans[r1][c2];
		
		for(int i=0;i<r1;i++) {
			for(int j=0;j<c1;j++) {
				printf("Enter the element a%d%d: ",i+1,j+1);
				scanf("%d",&mat1[i][j]);
			}
	    }
	    
	    for(int i=0;i<r2;i++) {
			for(int j=0;j<c2;j++) {
				printf("Enter the element b%d%d: ",i+1,j+1);
				scanf("%d",&mat2[i][j]);
			}
	    }
	    
	    int sum =0;
	    for(int i=0;i<r1;i++) {
	    	for(int j=0;j<c2;j++) {
	    		sum = 0;
	    		for(int k=0;k<c1;k++) {
	    			sum += mat1[i][k] * mat2[k][i];
				}
				ans[i][j] = sum;
			}
		}
		
		printf("Multiplication of matrices is: \n");
	    for(int i=0;i<r1;i++) {
			for(int j=0;j<c2;j++) {
				printf("%d\t",ans[i][j]);
			}
			printf("\n");
	    }
	    
    }
	return 0;


}
