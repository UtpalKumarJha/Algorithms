#include<bits/stdc++.h>
#define maxi 101
using namespace std;

int t,a,b,c,d;

char ch[maxi],ch1[maxi];

int dp[maxi][maxi];

int lcs(int m,int n)
{

	if(dp[m][n]!=-1)
	{
		return dp[m][n];
	}
	if(m<=0 || n<=0)
	{
		return 0;
	}
	if(ch[m-1]==ch1[n-1])
	{
		dp[m][n]=1+lcs(m-1,n-1);
		return dp[m][n];
	}
	else
	{
		dp[m][n]=max(lcs(m-1,n),lcs(m,n-1));
		return dp[m][n];
	}

}

int main()
{
	cin >> t;
	while(t--)
	{
		for(int i=0;i<100;i++)
		{
			for(int j=0;j<100;j++)
			{
				dp[i][j]=-1;
			}
		}
		cin >> ch;
		cin >> ch1;
		a=strlen(ch);
		b=strlen(ch1);


        cout<<lcs(a,b)<<endl;

        for(int i=1;i<=a;i++)
		{
			for(int j=1;j<=b;j++)
			{
				cout<<dp[i][j]<<" ";
			}
			cout<<endl;
		}

		cout<<dp[a][b]<<endl;
      
	}
	return 0;
}