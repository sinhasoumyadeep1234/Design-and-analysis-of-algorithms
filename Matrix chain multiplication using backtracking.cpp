//MATRIX CHAIN MULTIPLICATION BY SS//
#include <stdio.h>
void matrix_chain(int[],int);
int optimal_parenthesis(int,int);
int m[5][5],s[5][5];
int main(){
	int p[20],n,i,j;
	printf("Enter the no. of matrix:");
	scanf("%d",&n);
	printf("\nEnter the matrix's dimensions:");
	for(i=0;i<=n;i++){
		scanf("%d",&p[i]);
	}
	matrix_chain(p,n);
	printf("\nThe number of scaler multiplications are = %d\n",m[1][n]);
	optimal_parenthesis(1,n);
}
void matrix_chain(int p[],int n){
	int q,l,i,j,k;
	for(i=1;i<=n;i++){
		m[i][i]=0;
	}
	for(l=2;l<=n;l++){
		for(i=1;i<=(n-l+1);i++){
			j=i+l-1;
			m[i][j]=999;
			for(k=i;k<=(j-1);k++){
				q=m[i][k]+m[k+1][j]+p[i-1]*p[k]*p[j];
				if(q<m[i][j]){
					m[i][j]=q;
					s[i][j]=k;
				}
			}
		}
	}
}
optimal_parenthesis(int i,int j){
	if(i==j)
	   printf("  A%d",i);
	else{
		printf(" ( ");
		optimal_parenthesis(i,s[i][j]);
		optimal_parenthesis(s[i][j]+1,j);
		printf(" ) ");
	}
	
}