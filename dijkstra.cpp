#include<bits/stdc++.h>
#define MP make_pair
#define PB push_back
#define maxi 400005
using namespace std;
typedef long long ll;
ll n,k,a,b,c;
ll value[maxi],mark[maxi];

vector< pair < ll, pair< ll,ll >  > > arr[maxi];
typedef pair < pair <ll,ll> ,pair<ll,ll> > lol; 
set< pair < pair <ll,ll> ,pair<ll,ll> > > s;

vector<ll> v;
ll d;

ll ar[maxi];

void dij(int x)
{
   for(int i=0;i<=n+1;i++)
   {
     value[i]=12345678912345678;
   }

   value[x]=0;

   s.insert(MP(MP(0,0),MP(x,0)));

   while(!s.empty())
   {
     lol aa = *s.begin();
     s.erase(s.begin());

     ll check = aa.second.first;
     ll check1 = aa.second.second;
     if(!mark[check])
     { 
        v.push_back(check1);
        for(int j=0;j<arr[check].size();j++)
        {
           ll bb = arr[check][j].first;
           ll cc = arr[check][j].second.first;
           ll dd = arr[check][j].second.second;

           if(value[cc]>=value[check]+dd)
           {
             value[cc]=value[check]+dd;
             s.insert(MP(MP(value[cc],dd),MP(cc,bb)));
           }

        }
     }

     mark[check]=1;

   }
 
    ll sum=0;
    sort(v.begin(),v.end());

    for(int i=1;i<v.size();i++)
    {
       sum+=ar[v[i]];
    }
 
   cout<<sum<<endl;
    for(int i=1;i<v.size();i++)
    {
       cout<<v[i]<<" ";
    }
    cout<<endl;
    



}

int main()
{
   cin >> n >> k;

   for(int i=0;i<k;i++)
   {
     cin >> a >> b >> c;
     arr[a].PB(MP(i+1,MP(b,c)));
     arr[b].PB(MP(i+1,MP(a,c)));
     ar[i+1]=c;
   }

   cin >> d;

  dij(d);

   return 0;
}