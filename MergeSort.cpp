#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'
#define output(x) cout << x << endl
#define print(x) cout << #x << " = " << x << endl
#define sz 1000
int arr[sz],n;

void Merge(int arr[],int l, int mid, int r)
{
	int n1=mid-l+1,n2=r-mid;
	int left[n1],right[n2];
	int i,j,k;
	for(int i=0;i<n1;i++)
		left[i]=arr[l+i];
	for(i=0;i<n2;i++)
		right[i]=arr[mid+i+1];
	i=0,j=0,k=l; 
	while(i<n1&&j<n2)
	{
		if(left[i]<=right[j])
			arr[k] = left[i++];
		
		else arr[k]=right[j++];
		k++;
	}
	while(i<n1)
		arr[k++]=left[i++];
	while(j<n2)
		arr[k++]=right[j++];
}

void MergeSort(int arr[], int l, int r)
{
	if(l<r)
	{
		int mid = l+(r-l)/2;
		MergeSort(arr,l,mid);
		MergeSort(arr,mid+1,r);
		Merge(arr,l,mid,r);
	}
}

int main()
{
	cin>>n;
	for(int i=0;i<n;i++)
	{
		cin>>arr[i];
	}
	MergeSort(arr,0,n-1);
	for(int i=0;i<n;i++)
	{
		cout<<arr[i]<<' ';
	}
	cout<<endl;
}
