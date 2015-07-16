#include<bits/stdc++.h>
#define maxi 100005
using namespace std;

stack<char> s;

char ch[maxi];

int main()
{
	cin >> ch;
	int l = strlen(ch);


   for(int i=0;i<l;i++)
   {
   	 if(ch[i]=='(' || ch[i]=='{' || ch[i]=='[')
   	 {
   	   s.push(ch[i]);	
   	 }

   	 if(ch[i]==')')
   	 {
   	 	if(s.top()=='(')
   	 	{
   	 		s.pop();
   	 	}
   	 	else
   	 	{
   	 		cout<<"not possible"<<endl;
   	 		return 0;
   	 	}
   	 }

     
   	 if(ch[i]=='}')
   	 {
   	 	if(s.top()=='{')
   	 	{
   	 		s.pop();
   	 	}
   	 	else
   	 	{
   	 		cout<<"not possible"<<endl;
   	 		return 0;
   	 	}
   	 }
   	 
     
   	 if(ch[i]==']')
   	 {
   	 	if(s.top()=='[')
   	 	{
   	 		s.pop();
   	 	}
   	 	else
   	 	{
   	 		cout<<"not possible"<<endl;
   	 		return 0;
   	 	}
   	 }

   }

   if(s.empty())
   {
   	cout<<"cool"<<endl;
   }
   else
   {
   	cout<<"not possible"<<endl;
   }

	return 0;
}