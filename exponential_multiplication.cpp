#include<bits/stdc++.h>
using namespace std;
const int mod = 1000000009;
typedef long long ll;

ll calc(ll base,ll power)
{
	ll res = 1;
	while(power!=0)
	{
		if(power&1)
		{
			res=(res*base)%mod;
		}

        base=(base*base)%mod;

		power/=2;
	}
	return res;
}
int t;
int base,power;
int main()
{
	cin >> t;
	while(t--)
	{
		cin >> base >> power;
		cout<<calc(base,power)<<endl;
	}
	return 0;
}