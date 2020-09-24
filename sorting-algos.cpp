#include<bits/stdc++.h>
using namespace std;



// Bubble sort || high complexity || stable || swap until no swap || O(n^2)


void bubblesort(int a[],int n){
	for(int i=0;i<n;i++){
			for(int j=0;j<n-i-1;j++){
				if(a[j]>a[j+1]){
					int temp=a[j];
					a[j]=a[j+1];
					a[j+1]=temp;
				}
			}
	}
}



// selection sort || simple || for small data || stable || least swaps || O(n^2) || inplace


void selectionsort(int a[],int n){
	for(int i=0;i<n;i++){
		int min=i;
		for(int j=i+1;j<n;j++){
			if(a[j]<a[min]){
				min=j;
			}
		}
		int temp=a[min];
		a[min]=a[i];
		a[i]=temp;
	}
}


// insertion sort || simple || remove element from input and insert into correct position || stable || inplace || O(n^2)
// used as recursive base

void insertionsort(int a[],int n){
	for(int i=1;i<n;i++){
		int j=i;
		int v=a[i];
		while(a[j-1]>v && j>=1){
			a[j]=a[j-1];
			j--;
		}
		a[j]=v;
	}
}


//merge sort || stable || starts with small data and end with large file

void merge(int a[],int start,int mid,int end,int temp[]){
	int i,j,k;
	i=start;
	j=mid;
	k=start;

	while(i<mid && j<=end){
		if(a[i]<=a[j]){
			temp[k++]=a[i++];
		}
		else
		{
			temp[k++]=a[j++];
		}
	}

	while(i<mid){
		temp[k++]=a[i++];
	}
	while(j<=end){
		temp[k++]=a[j++];
	}
	int ll=0;
	for(int low=start;low<=end;low++){
		a[low]=temp[low];
		ll++;
	}
}





void mergesort(int a[],int start,int end,int temp[]){
	if(end>start){
		int mid=start+(end-start)/2;
		mergesort(a,start,mid,temp);
		mergesort(a,mid+1,end,temp);
		merge(a,start,mid+1,end,temp);
	}
}




// quicksort || unstable || partition

void swap(int *a,int *b){
	int temp=*a;
	*a=*b;
	*b=temp;
}


int parition(int a[],int low,int high){
	int pivot=a[high];
	int i=low-1;
	for(int j=low;j<high;j++){
		if(a[j]<pivot){
			i++;
			swap(&a[i],&a[j]);
		}
	}

	swap(&a[i+1],&a[high]);
	return i+1;
}


void quicksort(int a[],int start,int end){

	if(start<end){
		int pi=parition(a,start,end);

		quicksort(a,start,pi-1);
		quicksort(a,pi+1,end);
	}
}




//counting sort || O(n) || Used where values are more keys are less

int find_max(int a[],int n){
	int max=-9999999;
	for(int i=0;i<n;i++){
		if(a[i]>max){
			max=a[i];
		}
	}
	return max;
}



void count(int a[],int n){
	int k=find_max(a,n);
	int count[k+1];
	for(int i=0;i<=k;i++){
		count[i]=0;
	}


	for(int i=0;i<n;i++){
		count[a[i]]++;
	}

	for(int i=1;i<=k;i++){
		count[i]=count[i]+count[i-1];
	}
	int output[n];

	for(int j=n-1;j>=0;j--){
		output[count[a[j]]]=a[j];
		count[a[j]]--;
	}

	for(int i=0;i<n;i++){
		a[i]=output[i+1];
	}


}

//heapsort

void heapify(int a[],int n,int i){
	int l=2*i+1;
	int r=2*i+2;
	int largest=i;

	if(l<n && a[l]>largest){
		largest=l;
	}
	if(r<n && a[r]<largest){
		largest=r;
	}

	if(i!=largest){
		swap(&a[i],&a[largest]);
		heapify(a,largest,i);
	}
}

void heapsort(int a[],int n){

	for(int i=n/2-1;i>=0;i--){
		heapify(a,n,i);
	}

	for(int i=n-1;i>0;i--){
		swap(&a[i],&a[0]);
		heapify(a,i,0);
	}
}



int main(){
	int n;
	cin>>n;
	int a[n];
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	//bubblesort(a,n);
	//selectionsort(a,n);
	//insertionsort(a,n);
	//int temp[n];
	//mergesort(a,0,n-1,temp);
	//quicksort(a,0,n-1);
	//count(a,n);
	heapsort(a,n);
	for(int i=0;i<n;i++){
		cout<<a[i]<<" ";
	}
}
