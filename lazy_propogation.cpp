//AUTHOR : Sarang ShrivastAava

#include<bits/stdc++.h>
#define ll long long int 
#define llu unsigned long long int
#define mod 1000000007
#define in1(x) scanf("%lld",&x)
#define in2(x,y) scanf("%lld%lld",&x,&y)
#define in3(x,y,z) scanf("%lld%lld%lld",&x,&y,&z)
using namespace std;

ll n;

ll update(ll tree[],ll helper[],ll i,ll j,ll val,ll l,ll r,ll node){

    if(helper[node]!=0)
    {
        tree[node]+=(helper[node]*(j-i+1));

        if(i!=j)
        {
            helper[2*node]+=helper[node];
            helper[2*node+1]+=helper[node];
        }

        helper[node]=0;
    }

    if(i>r||j<l)
        return tree[node];

    if(i>=l&&j<=r)
    {
        tree[node]+=(val*(j-i+1));
        if(i!=j)
        {
            
            helper[2*node]+=val;
            helper[2*node+1]+=val;
        }

        return tree[node];
    }

    ll mid=(i+j)/2;
    tree[node]=(update(tree,helper,i,mid,val,l,r,node<<1)+update(tree,helper,mid+1,j,val,l,r,(node<<1)+1));
    return tree[node];
}

ll query(ll tree[],ll helper[],ll i,ll j,ll node,ll l,ll r)
{
    
    if(i>r||j<l)
        return 0;
    if(helper[node]!=0)
    {
        tree[node]+=(helper[node]*(j-i+1));
        if(i!=j)
        {
            helper[2*node]+=helper[node];
            helper[2*node+1]+=helper[node];
        }
        helper[node]=0;
    }
    if(i>=l&&j<=r)return tree[node];
    ll mid=(i+j)>>1;
    return (query(tree,helper,i,mid,node<<1,l,r)+query(tree,helper,mid+1,j,(node<<1)+1,l,r));
}

int main()
{
    ll t,l,r,c,i,p,s,j;
    in1(t);
    while(t--)
    {
        ll tree[300000]={0},helper[300000]={0};
        scanf("%lld%lld",&n,&c);
        for(i=0;i<c;i++)
        {
            in1(p);
            if(p==0)
            {       
                in3(l,r,s);
                update(tree,helper,1,n,s,l,r,1);
            }
            else
            {
           
                in2(l,r);
                printf("%lld\n",query(tree,helper,1,n,1,l,r));
            }
        }
        
    }
    return 0;
}