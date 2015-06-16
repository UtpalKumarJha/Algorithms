#include<bits/stdc++.h>
#define PB push_back
#define MP make_pair

using namespace std;
int x,y,a,b;
typedef pair<int,int> pr;
typedef long long ll;
vector<pr> v;
int dp[1000][1000];

ll knap(int n,int k)
{
	if(dp[n][k]!=-1)
	{
       return dp[n][k];
	}
	if(n==0 || k==0)
	{
		return 0;
	}
	if(v[n-1].first>k)
	{
		knap(n-1,k);
	}
	else
	{
		ll u = knap(n-1,k-v[n-1].first)+v[n-1].second;
		ll v = knap(n-1,k);
		dp[n][k]=max(u,v);
		return dp[n][k];
	}
}

int main()
{
	while(1)
	{
		cin >> a >> b;
		if(a==0 && b==0)
		{
			break;
		}
		else
		{
			v.clear();
			for(int i=0;i<1000;i++)
			{
				for(int j=0;j<1000;j++)
				{
					dp[i][j]=-1;
				}
			}

			for(int i=0;i<b;i++)
			{
				cin >> x >> y;
				v.PB(MP(x,y));
			}

			ll  ans = knap(b,a);

            int low = 0,high=a;
            while(low<high)
            {
            	int mid=(low+high)/2;
            	if(knap(b,mid)<ans)
            	{
            		low=mid+1;
            	}
            	else
            	{
            		high=mid;
            	}
            }

			cout<<low<<" "<<ans<<endl;
		}
	}
	return 0;
}