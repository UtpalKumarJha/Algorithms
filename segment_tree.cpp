#include<bits/stdc++.h>
using namespace std;

int n,arr[1000];
int tree[100000];
int p,q,qq;

int segment_min(int index,int start,int end)
{
	if(start==end)
	{
		tree[index]=arr[start];
		return tree[index];
	}
	
	int mid = (start+end)/2;
	
	int g = segment_min(2*index+1,start,mid);
	int h = segment_min(2*index+2,mid+1,end);
	
	tree[index]=min(g,h);
	return tree[index];
	
}

int mi(int index,int start,int end)
{
	if(start>=p && end<=q)
	{
		return tree[index];
	}
	if(start>q || end <p)
	{
		return INT_MAX;
	}
	
	int mid=(start+end)/2;
	
	return min(mi(2*index+1,start,mid),mi(2*index+2,mid+1,end));
	
}

int main()
{
	cin >> n;
	
	for(int i=0;i<n;i++)
	{
		cin >> arr[i];
	}
	
	segment_min(0,0,n-1);
	
	for(int i=0;i<2*n+5;i++)
	{
		cout <<tree[i]<< " ";
	}
	cout <<endl;
	cout <<"ENTER NUMBER OF QUERIES"<<endl;
	
	cin >> qq;
	while(qq--)
	{
		cin >> p >> q;
		cout <<mi(0,0,n-1)<<endl;
	}
	
	return 0;
}
