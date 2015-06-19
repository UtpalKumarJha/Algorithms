#include<bits/stdc++.h>
#define MP make_pair
#define PB push_back
#define maxi 1000
using namespace std;

typedef pair<int,int> pr;
int n,a,b,c,m;
vector<pr> arr[maxi];

set<pr> s;

int ans[maxi],mark[maxi];

void prim()
{
   for(int i=0;i<=n;i++)
   {
     ans[i]=12312412;
   }

   int an =0;

   ans[a]=0;

   s.insert(MP(0,a));

   while(!s.empty())
   {
     pr aa = *s.begin();
     s.erase(aa);

     int first = aa.first;
     int second = aa.second;
     an+=first;
     mark[second]=1;
     cout<<second<<endl;
     for(int j=0;j<arr[second].size();j++)
     {
        int f = arr[second][j].first;
        int g = arr[second][j].second;
      
        if(!mark[f] && ans[f]>g)
        {
          ans[f]=g;
          s.insert(MP(g,f));
        }
        
     }
     cout<<endl;
   }
   cout<<"SWAG OF MST IS"<<endl;
   cout<<an<<endl;

}

int main()
{
  cin >> n>>m;
  for(int i=0;i<m;i++)
  {
    cin >> a >> b >> c;
    arr[a].PB(MP(b,c));
    arr[b].PB(MP(a,c));
  }

  cin >>a;
  prim();

  return 0;
}