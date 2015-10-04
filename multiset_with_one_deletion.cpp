#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

multiset<ll> s;

ll n,a;

int main()
{
    cin >> n;
    for(int i=0;i<n;i++)
    {
        cin >> a;
        s.insert(a);
    }

    // to delete just one occurence use s.find


    cout<<"ENTER THE NUMBE OF DELETIONS YOU WANT TO HAve"<<endl;
   ll m;

    cin >> m;


    for(int i=0;i<m;i++)
    {
        cin >> a;
        if(s.find(a)!=s.end())
        s.erase(s.find(a));
        else
        cout<<"NUMBER DOESN'T EXIST"<<endl;
    } 

    for(auto ii = s.begin();ii!=s.end();ii++)
    {
        cout<<*ii<<" ";
    }
    cout<<endl;


    return 0;
}