#include<bits/stdc++.h>
#define PB push_back
#define maxi 101
using namespace std;

int n,arr[maxi],tree[4*maxi];

vector<int> ans[maxi];

void update(int idx,int value,int first)
{
	while(idx<=maxi)
	{
	   ans[idx].PB(first);
       tree[idx]+=value;
       idx+=((idx)&(-idx));
	}
}

void construct()
{
	for(int i=1;i<=n;i++)
	{
		update(i,arr[i],i);
	}
}

typedef long long ll;

ll read(int idx)
{
	ll sum=0;
	while(idx>0)
	{
      sum+=(tree[idx]);
      idx-=((idx)&(-idx));
	}
	return sum;
}

int a,b;

int main()
{
	cin >> n;

	for(int i=1;i<=n;i++)
	{
		cin >> arr[i];
	}
    
    construct();
    int nq;
    cout<<"enter number of queries"<<endl;
    cin >> nq;

   

    for(int i=0;i<nq;i++)
    {
    	cin >> a >> b;
    	cout<<read(b)-read(a)+arr[a]<<endl;
    }

	return 0;
}