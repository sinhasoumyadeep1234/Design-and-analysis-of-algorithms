//BFS BY SS//
#include<stdio.h>
void insert(int n);
int del();
int empty();
void bfs(int s);
int q[10];
int f=-1;
int r=-1;
int s,n,i,j,vis[10],u,g[10][10];
int main(){
	int e,v;
	printf("Enter the number of vertex and edge:");
	scanf("%d%d",&n,&e);
	for(i=1;i<=n;i++){
		for(j=1;j<=n;j++){
			g[i][j]=0;
		}
	}
	for(i=1;i<=e;i++){
		printf("\nEnter the start & end vertex:");
		scanf("%d%d",&u,&v);
		g[u][v]=g[v][u]=1;
	}
	printf("\nEnter the source vertex:");
	scanf("%d",&s);
	bfs(s);
	return 0;
}
void insert(int n){
	if(r==10-1){
		printf("\nThe queue is overflow:");
	}
	else{
		if(f==-1)
		   f=0;
		   r=r+1;
		   q[r]=n;
		}
}
int del(){
	int item;
	if(f==-1 || f>r){
		printf("\nQueue is underflow");
	}
	item=q[f];
	f=f+1;
	return item;
}
int empty(){
	if(f==-1 || f>r)
	  return 1;
	else
	  return 0;
}
void bfs(int s){
	int d;
	u=s;
	insert(s);
	vis[s]=1;
	d=del();
	printf("\nThe value of d is : %d",d);
	do{
		for(i=1;i<=n;i++){
			if(g[d][i]==1 && vis[i]==0)
			insert(i);
			vis[i]=1;
		}
		d=del();
		if(d!=0)
		   printf("%d",d);
	} while(!empty());
}