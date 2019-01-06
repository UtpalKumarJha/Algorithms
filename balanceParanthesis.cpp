#include <iostream> 
#include <algorithm>    // for lower_bound, upper_bound and sort 
#include <vector> 
#include<math.h>      // for vector 
#define PB push_back
#define MP make_pair  
using namespace std; 
typedef long long ll;

ll n,x;

typedef pair<int,int> pr;

string str;
ll cnt;
ll gl[500005];
ll gr[500005];

int main()
{
    cin >> n;
    for(int i=0;i<n;i++)
    {
    	cin >> str;
    	ll length = str.length();
    	ll sum = 0;
    	ll mn = 0;

    		for(int i=0;i<length;i++)
    		{
    			if(str[i]=='(')
    			{
    				sum++;
    			}
    			else
    			{
    				sum--;
    			}
    			mn = min(mn,sum);
    		}
    		if(sum==0)
    		{
    			if(mn>=0)
    			{
    				cnt++;
    			}
    		}
    		else
    		{
    			if(sum<0)
    			{
    				if(mn == sum)
    				{
    					gr[-sum]++;
    				}
    			}
    			else if(mn>=0)
    			{
    				gl[sum]++;
    			}
    		}
    }

    ll ans = cnt/2;

    for(int i=0;i<5e+5;i++)
    {
    	ans+=min(gr[i],gl[i]);
    }

    cout<<ans<<endl;
	return 0;
}