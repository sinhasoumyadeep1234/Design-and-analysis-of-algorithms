//Merge sort by SS//
#include <stdio.h>
void mergesort(int [],int, int);
void merge(int [],int,int,int);

int main(){
int a[20],i,n;
printf("Enter the size of the array:");
scanf("%d", &n);
printf("\nEnter the array elements:");
for(i=0;i<n;i++){
scanf("%d", &a[i]);
}
mergesort(a,0,n-1);
printf("\nArray after merge sort is:\n\n");
for(i=0;i<n;i++){
printf("%d ",a[i]);
}
return 0;
}
void mergesort(int a[20],int low,int high){
int mid;
if(high>low){
mid = (low + high) / 2;
mergesort(a,low,mid);
mergesort(a,mid+1,high);
merge(a,low,mid,high);
}
}
void merge(int a[],int low,int mid,int high){
int i,j,k,b[20],t;
i=k=low;
j=mid+1;
while (i<=mid && j<=high){
if (a[i]<a[j]){
   b[k++]=a[i++];
}
else{
   b[k++]=a[j++];
}
}
if(j>high){
	for(t=i;t<=mid;t++)
	b[k++]=a[t];
}
else{
	for(t=j;t<=high;t++)
		b[k++]=a[t];
	}
	for(t=low;t<=high;t++){
		a[t]=b[t];
	}
}