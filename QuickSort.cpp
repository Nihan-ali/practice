#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'
#define output(x) cout << x << endl
#define print(x) cout << #x << " = " << x << endl
#define sz 1000
int arr[sz],n;

int partition(int arr[], int low, int high)
{
	int pivot=arr[high];
	int i = low-1; 

	for(int j = low; j<=high-1;j++)
	{
		if(arr[j]<pivot)
		{
			i++;
			swap(arr[i],arr[j]);
		}
	}
	swap(arr[i+1],arr[high]);
	return i+1;
}

void QuickSort(int arr[],int low,int high)
{
	if(low<high)
	{
		int pivot=partition(arr,low,high);
		QuickSort(arr,low,pivot-1);
		QuickSort(arr,pivot+1,high);
	}
}

int main()
{
	cin>>n;
	for(int i=0;i<n;i++)
	{
		cin>>arr[i];
	}
	QuickSort(arr,0,n-1);
	for(int i=0;i<n;i++)
		cout<<arr[i]<<' ';
	cout<<endl;
	
}