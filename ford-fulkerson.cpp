#include<bits/stdc++.h>
#define maxi 1001
using namespace std;
int n,m,arr[maxi][maxi],arr1[maxi][maxi],parent[maxi];
int source,dest;

long long int sum,sum1,x,y,xx;
const int inf = 100000000;
typedef long long ll;

queue<int> q;

void PUSH(int uu ,int vv)
{
    if(parent[uu]==-1)
    {
        parent[uu]=vv;
        q.push(uu);
    }
}

ll bfs()
{
    memset(parent,-1,sizeof(parent));
    
    PUSH(source,source);

    while(!q.empty())
    {
         int r = q.front();
         q.pop();
         for(int j=0;j<=dest;j++)
         {
            if(arr[r][j]>0)
            {
                PUSH(j,r);
            }
         }

    }

    if(parent[dest]==-1)
    {
        return 0;
    }

    int qq = dest;
    int mini = arr[parent[qq]][qq];
    
    while(qq!=source)
    {
       mini = min(mini,arr[parent[qq]][qq]);
       qq=parent[qq];
    }

    qq = dest;
    while(qq!=source)
    {
        arr[parent[qq]][qq]-=mini;
        arr[qq][parent[qq]]+=mini;
        qq=parent[qq];
    }

    return mini;

}


int main()
{
    cin >> n >> m;
    
    source = 2*n;
    dest = 2*n +1;

    for(int i=0;i<n;i++)
    {
         cin >> arr[source][i];
         sum+=arr[source][i];
         arr1[source][i]=arr[source][i];
    }

    for(int i=0;i<n;i++)
    {
         cin >> arr[n+i][dest];
         sum1+=arr[n+i][dest];
         arr1[n+i][dest]=arr[n+i][dest];
    }

    for(int i=0;i<n;i++)
    {
        arr1[i][n+i]=arr[i][n+i]=inf;
    }


    for(int i=0;i<m;i++)
    {
        cin >> x >> y;
        x--;
        y--;

        arr[x][y+n]=arr[y][x+n]=inf;
        arr1[x][y+n]=arr1[y][x+n]=inf;
    }


    long long ans = 0;

     while((xx=bfs())>0)
     {
        ans += xx;
     }


    if(ans==sum && sum==sum1)
    {
        cout<<"YES"<<endl;
        for(int i=0;i<n;i++)
        {
            for(int j=n;j<2*n;j++)
            {
                cout<<arr1[i][j]-arr[i][j]<<" ";
            }
            cout<<endl;
        }
    }
    else
    {
        cout<<"NO"<<endl;
    }

    return 0;
}