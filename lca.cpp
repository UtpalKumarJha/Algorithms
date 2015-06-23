#include<bits/stdc++.h>
#define pb push_back
using namespace std;

int val[10000],l[10000],h[10000],cnt,level,n,m,t,i,j,p,seg[100000],x,y,q,ind[100000];
bool vis[10005];
vector<int> vec[100000];

void dfs(int x,int level)
{
	int i;
	val[cnt]=x;
	l[cnt++]=level;
	vis[x]=false;
	for(i=0;i<vec[x].size();i++)
	{
		if(vis[vec[x][i]])
		{
			level++;
			vis[vec[x][i]]=false;
			dfs(vec[x][i],level);
			level--;
			val[cnt]=x;
			l[cnt++]=level;
		}
	}
}

void build(int node,int i,int j)
{
	if(i==j)
	{
		seg[node]=l[i];
		ind[node]=i;
		return;
	}
	
	int mid=(i+j)>>1;

	build(node<<1,i,mid);
	build((node<<1)+1,mid+1,j);

	if(seg[node<<1]<seg[(node<<1)+1])
	{
		ind[node]=ind[node<<1];
	}
	else
	{
	   ind[node]=ind[(node<<1)+1];	
	}

	seg[node]=min(seg[node<<1],seg[(node<<1)+1]);
	
}

int query(int node,int i,int j,int start,int end)
{
	if(i>end || j<start) 
		return 0;
	if(i>=start && j<=end) 
		return node;

	int mid=(i+j)>>1;
	
	int p=query(node<<1,i,mid,start,end);
	int q=query((node<<1)+1,mid+1,j,start,end);

	if(seg[p]<seg[q])
	  return p;
	else  
	  return q;
}

int main()
{
	cin >> t;
	int w=1;
	while(w<=t)
	{
		bool mark[1001]={false};
		cin >> n;
		cnt=0;
		level=0;

		for(i=1;i<=n;i++)
		{	
			cin >> m;
			while(m--)
			{
				cin >> p;
				mark[p]=true;
				vec[i].pb(p);
			}
			vis[i]=true;
		}

		for(i=1;i<=n;i++)
		{
			if(mark[i]==false)
			{
				dfs(i,level);
				 break;
			}
		}

		int visited[1005]={0};

		for(i=0;i<cnt;i++)
		{
			vec[i].clear();
			
			if(!visited[val[i]])
			{
				h[val[i]]=i;
				visited[val[i]]=1;
			}
		}

		seg[0]=INT_MAX;
		
		build(1,0,cnt-1);
		
		int f,s;
		cin >> q;
		printf("Case %d:\n",w);

		while(q--)
		{
			cin >> x;
			cin >> y;
			
			f=h[x];
			s=h[y];

			if(f>s)
			{
				swap(f,s);
			} 
			
			cout<<val[ind[query(1,0,cnt-1,f,s)]]<<endl;
		}
		
	w++;	
	} 
	return 0;
}

