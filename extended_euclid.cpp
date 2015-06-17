
// extended euclid algorithm to find inverse of two coprime numbers

#include<bits/stdc++.h>
using namespace std;
int t;
typedef long long ll;
ll a,b,c;
 
ll gcd(ll x,ll y)
{
	if(y==0)
	{
		return x;
	}
	return gcd(y,x%y);
}
 
pair<ll, pair<ll, ll> > extendedEuclid(ll a, ll b) {
    ll x = 1, y = 0;
    ll xLast = 0, yLast = 1;
    ll q, r, m, n;
    while(a != 0) {
        q = b / a;
        r = b % a;
        m = xLast - q * x;
        n = yLast - q * y;
        xLast = x, yLast = y;
        x = m, y = n;
        b = a, a = r;
    }
    return make_pair(b, make_pair(xLast, yLast));
}
 
int modInverse(ll a, ll m) {
    return (extendedEuclid(a,m).second.first + m) % m;
}
 
int main()
{
	cin >> t;
	while(t--)
	{
		cin >> a >> b >> c;
 
        if(gcd(a,b)!=1)
        {
        	//cout<<gcd(a,c)<<endl;
           cout<<"-1"<<endl;
        }
        else
        {
        	ll sum=0;
            ll ans = modInverse(a,b);
            if(ans<b)
            {
               if(c%2==0)
            {
               sum+=(a*(c/2));
               sum+=(ans*(c/2));
            }
            else
            {
            	sum+=(a*(c+1)/2);
            	sum+=(ans*(c/2));
            }
            cout<<sum<<endl;	
            }
            else
            {
            	cout<<"-1"<<endl;
            }
            
        }
 
	}
	return 0;
}