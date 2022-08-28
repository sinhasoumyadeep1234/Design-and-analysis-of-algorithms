//Floyd-Warshall BY SS
#include<stdio.h>
void floyd(int[10][10],int);
int main(){
	int n,e,i,j,u,v,w,g[10][10];
	printf("Enter the number of vertex:");
	scanf("%d",&n);
	printf("Enter the number of the edges:");
	scanf("%d",&e);
	for(i=1;i<=n;i++){
		for(j=1;j<=n;j++){
			if(i==j){
				g[i][j]=0;            //vertex to itself is 0
			}
			else{
				g[i][j]=999;          //vetex to all other vertex is infinity
			}
		}
	}
	for(i=1;i<=e;i++){
		printf("Enter the start vertex,end vertex with its weight:");
		scanf("%d  %d  %d",&u,&v,&w);
		g[u][v]=w;
	}
	floyd(g,n);
	printf("The matrix is:\n");
	for(i=1;i<=n;i++){
		for(j=1;j<=n;j++){
			printf("%d\t",g[i][j]);
		}
		printf("\n");
	}
}
void floyd(int g[10][10],int n){
	int i,j,k;
	for(k=1;k<=n;k++){
		for(i=1;i<=n;i++){
			for(j=1;j<=n;j++){
				if(g[i][k]+g[k][j]<g[i][j]){
					g[i][j]=g[i][k]+g[k][j];
				}
			}
		}
	}
}