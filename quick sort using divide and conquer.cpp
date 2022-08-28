//QUICK SORT USING DIVIDE AND CONQUER BY SS//

#include <stdio.h>

void qs(int a[],int low,int high);
int partition(int a[],int low,int high);

int main(){
	int a[100],i,n;
	printf("Enter the array Size:");
	scanf("%d",&n);
	printf("Enter the array elements:");
	for(i=0;i<n;i++){
		scanf("%d",&a[i]);
	}
qs(a,0,n-1);
printf("\nThe array after sorting is:\n");
for(i=0;i<n;i++){
	printf(" %d",a[i]);
}
}
void qs(int a[],int low,int high){
	int q;
	if(high>low){
		q=partition(a,low,high);
		qs(a,low,q-1);            // sorting before pivot
		qs(a,q+1,high);          // sorting after pivot
	}
}
int partition(int a[],int low,int high){
	int temp,x,i,j;
	x=a[high];                    // assigning the pivot element with the rightmost value
	i=low-1;                     // index of smaller element and indicates the correct position of pivot found so far
	for(j=low;j<high;j++){
		if(a[j]<=x){             // if the element is smaller than pivot
			i=i+1;               // increment the index of smaller element
			temp=a[i];
			a[i]=a[j];
			a[j]=temp;               
		}
	}
	temp=a[high];
	a[high]=a[i+1];
	a[i+1]=temp;
	return(i+1);
}