/* Deng Haijun 2012/12/13
for i <- 2 to N
    j <- i
    while j > 1 and a[j] < a[j - 1]
       swap a[j] and a[j - 1]
       j <- j - 1
2
5
1 1 1 2 2
5
2 1 3 1 2
*/

#include <stdio.h>

static long long int cntr=0;

void merge(long long int [],int,int,int);

void mergeSort(long long int arr[],int low, int high){
     if(low>=high)return;
     int mid=(low+high)/2;
     mergeSort(arr,low,mid);
	 mergeSort(arr,mid+1,high);		
	 merge(arr,low,mid,high);
}

void merge(long long int arr[], int low, int mid, int high){
    long long int a[high-low+1];
    int i = low;
	int j = mid+1;
	int k = 0;
	while(i<=mid && j<=high){
		if(arr[i]>arr[j]){
			a[k]=arr[j];
			cntr+=mid-i+1;
			j++;
		}
		else{
			a[k]=arr[i];
			i++;
		}
		k++;
	}
	while(i<=mid){
		a[k]=arr[i];
		k++;i++;
	}
	while(j<=high){
		a[k]=arr[j];
		k++;j++;
	}
    int p=0;
	for(int m=low;m<=high;m++,p++){
		arr[m]=a[p];
	}
}

int main(){
    int t;
    scanf("%d",&t);
    for(;t>0;t--){
            cntr=0;
            long long int n;
            scanf("%lld",&n);
            long long int arr[n];
            for(int i=0;i<n;i++){
                    scanf("%lld",&arr[i]);       
            }
            mergeSort(arr, 0, n-1);        
            printf("%lld\n",cntr);   
    }
    //getch();
    return 0;    
  
}
