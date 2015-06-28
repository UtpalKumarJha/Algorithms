#include<bits/stdc++.h>
#define maxi 1000005
using namespace std;


typedef long long ll;

ll arr[maxi],tree[maxi];

int n,x,y,q;

ll segment(int index,int start,int end)
{
	if(start==end)
	{
		tree[index]=arr[start];
		return tree[index];
	}

    int mid = (start+end)/2;

    tree[index]=segment(2*index+1,start,mid)+segment(2*index+2,mid+1,end);
    return tree[index];

}

ll query(int index,int start,int end)
{
   if(start>y || end<x)
   {
   	 return 0;
   }

   if(start>=x && end<=y)
   {
   	 return tree[index];
   }

   int mid = (start+end)/2;

   int l = query(2*index+1,start,mid);
   int m = query(2*index+2,mid+1,end);
   
   return l+m;

}

int main()
{
	cin >> n;
	for(int i=0;i<n;i++)
	{
		cin >> arr[i];
	}

    segment(0,0,n-1);

   cout<<"Enter number of queries"<<endl;
   cin >> q;

   for(int i=0;i<q;i++)
   {
      cin >> x >>y;
      cout<<query(0,0,n-1)<<endl;
   }

	return 0;
}