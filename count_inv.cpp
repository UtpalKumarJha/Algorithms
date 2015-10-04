#include<bits/stdc++.h>
#define maxi 10001
using namespace std;

int n,arr[maxi],tree[4*maxi];
typedef long long ll;

ll read(int idx)
{
   int cnt=0;

   while(idx>0)
   {
     cnt+=tree[idx];
     idx -=((idx)&(-idx));
   }
   return cnt;
}

ll update(int idx,int value)
{
   while(idx<=maxi)
   {
   	 tree[idx]+=value;
   	 idx += ((idx)&(-idx));
   }
}

int main()
{
 	  cin >> n;
    
    for(int i=1;i<=n;i++)
    {
    	cin >> arr[i];
    }

    long long ans =0;

    for(int i=n;i>=1;i--)
    {
    	int x = read(arr[i]);
    	ans+=x;
    	update(arr[i],1);
    }

   cout<<ans<<endl;

	return 0;

}