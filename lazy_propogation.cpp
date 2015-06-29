#include<bits/stdc++.h>
#define maxi 1000005
using namespace std;

typedef long long ll;

ll arr[maxi],tree[maxi],lazy[maxi];
int n,y,x,q,value;

ll build(int index,int start,int end)
{
	if(start==end)
	{
		tree[index]=arr[start];
		return tree[index];
	}

    int mid =(start+end)/2;

    tree[index]=max(build(2*index+1,start,mid),build(2*index+2,mid+1,end));
    return tree[index];
}


ll query(int index,int start,int end)
{
	if(lazy[index]!=0)
    {
       tree[index]+=lazy[index];

       if(start!=end)
       {
       	  lazy[2*index+2]+=lazy[index];
       	  lazy[2*index+1]+=lazy[index];
       }

       lazy[index]=0;
    }
    
	if(start>y || end<x)
	{
		return INT_MIN;
	}

    if(start>=x && y>=end)
    {
    	return tree[index];
    }

    int mid =(start+end)/2;

    return max(query(2*index+1,start,mid),query(2*index+2,mid+1,end));

}

ll update(int index,int start,int end,int val)
{
    
    if(lazy[index]!=0)
    {
       tree[index]+=lazy[index];

       if(start!=end)
       {
       	  lazy[2*index+2]+=lazy[index];
       	  lazy[2*index+1]+=lazy[index];
       }

       lazy[index]=0;
    }

	if(start>y || end<x)
	{
		return INT_MIN;
	}

    if(start>=x && end<=y)
    {
    	tree[index]+=val;

    	if(start!=end)
    	{
           lazy[2*index+1]+=val;
           lazy[2*index+2]+=val;
    	}

       return tree[index];

    }

    int mid = (start+end)/2;

    ll zz = update(2*index+1,start,mid,val);
    ll yy = update(2*index+2,mid+1,end,val);
    tree[index]=max(yy,zz);
    return tree[index];

}

int main()
{
	cin >> n;

    for(int i=0;i<n;i++)
    {
    	cin >> arr[i];
    }

    build(0,0,n-1);

    cout<<"ENTER NUMBER OF QUERIES"<<endl;
    cin >> q;

    while(q--)
    {
    	cin >> x >> y;
    	cout<<query(0,0,n-1)<<endl;
    }
    
    cout<<"ENTER AN INDEX TO UPDATE THE TREE"<<endl;

    cin >> x >> y >> value;
    update(0,0,n-1,value);

    cout<<"ENTER A QUERY TO PRINT THE ANSWER"<<endl;
    cin >> x >> y;
    cout<<query(0,0,n-1)<<endl;

	return 0;
}