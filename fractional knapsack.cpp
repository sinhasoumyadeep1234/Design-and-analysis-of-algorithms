//FRACTIONAL KNAPSACK USING GREEDY BY SS//

#include <stdio.h>
void knapsack(int,int);
struct kn{
	int p;
	int w;
	float r;
	float x;
}
k[10],t;

int main(){
	int n,m,i,j;
	printf("Enter the number of objects:");
	scanf("%d",&n);
	printf("Enter the knapsack capacity:");
	scanf("%d",&m);
	for(i=0;i<n;i++){
		printf("\nEnter the profit and weight of each object:");
		scanf("%d   %d",&k[i].p,&k[i].w);
		k[i].r=(float)k[i].p/k[i].w;
		k[i].x=0;
	}
for(i=0;i<n-1;i++){
	for(j=i+1;j<n;j++){
		if(k[i].r<k[j].r){                   // sorting the objects according weights
			t=k[i];
			k[i]=k[j];
			k[j]=t;
		}
	}
}
for(i=0;i<n;i++)
printf("\n\t%f",k[i].r);
knapsack(n,m);
}
void knapsack(int n,int m){
	float c=0;
	int i,j;
	for(i=0;i<n;i++){
		if(k[i].w<m){              // if the weight of the object is less than the capacity of the knapsack
			k[i].x=1;             // if the item is taken then modify the vector with 1
			m=m-k[i].w;          // reducing the knapsack capacity
			c=c+k[i].p;         //adding the profit of the object
		}
		else{
			break;
		}
	}
if(m!=0){                      // if capacity of the knapsack is not 0
	k[i].x=(float)m/k[i].w;     //partially taking the object
	c=c+(k[i].x+k[i].p);
}
printf("\n\nThe maximum profit is %f",c);

}













