#include<bits/stdc++.h>
#define maxi 1000005
using namespace std;

typedef long long ll;

ll t,n,arr[maxi];

multiset<ll> s;

int main()
{
	cin >>t;
	while(t--)
	{
		s.clear();
		cin >> 	n;
		for(int i=0;i<n;i++)
		{
			cin >> arr[i];
		
		}

        s.insert(arr[0]);

        for(int i=1;i<n;i++)
        {
        	auto it = s.upper_bound(arr[i]);
        	if(it==s.end())
        	{
        		s.insert(arr[i]);
        	}
        	else
        		{
        			typedef multiset< ll > :: iterator It;
        			pair<It,It> pit =s.equal_range(*it);
       
                    if( distance( pit.first, pit.second ) >= 2 )
                     {
                         s.erase( pit.first );
                         s.insert(arr[i]);
                     }
                     else
                     {
                     	s.erase(*it);
                     	s.insert(arr[i]);
                     }
        			
                    
        		}
        }

        cout<<s.size()<<" ";
        for(auto ii= s.begin();ii!=s.end();ii++)
        {
        	cout<<*ii<<" ";
        }
        cout<<endl;

	}
	return 0;
}