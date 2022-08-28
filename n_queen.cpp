#include <stdio.h>
#include <math.h>

void nq(int,int);
int place(int,int);
int disp(int);

int x[50],c=0;

void nq(int k,int n){
	int i;
	for(i=1;i<=n;i++){
		if(place(k,i)){
			x[k]=i;
			if(k==n)
			   disp(n);
			else
			   nq(k+1,n);
		}
	}
}
int place(int k,int i){
	int j;
	for(j=1;j<=k-1;j++){
		if((x[j]==i) || abs(j-k)==abs(x[j]-i))
		    return 0;
	}
	return 1;
}
int disp(int n){
	int i,j;
	c++;
	printf("Solution number %d is=",c);
	printf("\n");
	for(i=1;i<=n;i++){
		for(j=1;j<=n;j++){
			if(x[i]==j)
				printf("\tQ");
			else
			    printf("\t_");
			
		}
	printf("\n");
	printf("\n");
	
	}
	}
int main(){
	int k,n;
	printf("Enter the number of queens:");
	scanf("%d",&n);
	nq(1,n);
}