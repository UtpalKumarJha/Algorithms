#include<bits/stdc++.h>
using namespace std;

string s;


unsigned int hash(const char* s)
{
    unsigned int hash = 0;
    while (*s)
    {
        hash = hash * 101  +  *s++;
    }
    return hash;
}

int main()
{
	cin >> s;
	cout<<hash(s.c_str())<<endl;
	return 0;
}
