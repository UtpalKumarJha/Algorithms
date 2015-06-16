#include<bits/stdc++.h>
using namespace std;
unsigned int n,t;
unsigned decimal;

// 10 represetns number of bits . N represents the number to be converted
// only possible uptil 32 bit numbers to be on safe side and only convert number to bits not the other way round
int main()
{
	cin >> t;
	while(t--)
	{
		cin >> n;
        string s = bitset<10>(n).to_string();
        cout<<s<<endl;

	}
	return 0;
}