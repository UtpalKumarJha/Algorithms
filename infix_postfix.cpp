#include<bits/stdc++.h>
#define PB push_back
using namespace std;

string st;
int l;

vector<char> ans;
stack<char> s;

void call()
{
	while(s.top()!='(')
	{
        ans.PB(s.top());
		s.pop();
	}
    s.pop();
}

int precedence(char vv)
{
    if(vv=='+' || vv=='-')
    {
        return 0;
    }
    else if(vv=='*' || vv=='/')
    {
        return 1;
    }
    else if(vv=='^')
    {
        return 2;
    }
    return -1;
}

void callbaby(char cd)
{
   int r = precedence(s.top());
   int t = precedence(cd);

   if(r<=t)
   {
     s.push(cd);
   }
   else
   {
     while(r>t)
     {
        char dfg = s.top();
        ans.PB(dfg);
        s.pop();
        r=precedence(s.top());
     }
     s.push(cd);
   }

}

int main()
{
	cin >> st;
	l = st.length();

    for(int i=0;i<l;i++)
    {
    	if(st[i]!='+' && st[i]!='-' && st[i]!='*' && st[i]!='/' && st[i]!='(' && st[i]!=')' && st[i]!='^')
    	{
    		ans.PB(st[i]);
    	}
        else if(st[i]=='(')
        {
        	s.push(st[i]);
        }
        else if(st[i]==')')
        {
        	call();
        }
        else if(st[i]=='+' || st[i]=='-' || st[i]=='*' || st[i]=='/' || st[i]=='^')
        {
            if(s.size()!=0)
            callbaby(st[i]);
            else
            s.push(st[i]);
        }
    }

    while(!s.empty())
    {
        ans.PB(s.top());
        s.pop();
    }
    for(int i=0;i<ans.size();i++)
    cout<<ans[i];
    cout<<endl;

	return 0;
}