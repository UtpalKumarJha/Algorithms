#include<bits/stdc++.h>
using namespace std;
int t,n;
char ch[300];

struct trie
{
	trie *next[30];
	int leaf;

    trie()
    {
    	memset(next,0,sizeof(next));
    	leaf=0;
    }

    void add(char *s)
    {
    	if(*s==0)
    	{
    		leaf = 1;
    		return;
    	}

        int c = *s-'a';

        if(!next[c])
        {
        	next[c] = new trie();
        }

        next[c]->add(s+1);
    }

    void frees(trie *root)
    {
    	for(int i=0;i<30;i++)
    	{
    		//int c = *s-'a';
    		if(next[i])
    		{
    			root->frees(next[i]);
    			delete(next[i]);
    		}
    	}

        delete(root);

    }

    int search(char *s)
    {
    	
    	if(*s==0)
    	{
    		if(leaf==1)
    		{
    			return 1;
    		}
    		else
    		{
    			return 0;
    		}
    	}

        int c = *s-'a';

        if(!next[c])
        {
        	return 0;
        }
        else
        {
        	return next[c]->search(s+1);
        }

    }

};

int q;

int main()
{
	cin >> t;
	trie *root = new trie();
	while(t--)
	{
		cin >> ch;
        root->add(ch);
	}
    cin >> q;

    while(q--)
    {
    	cin >> ch;
    	if(root->search(ch))
    	{
    		cout<<"exists"<<endl;
    	}
    	else
    	{
    		cout<<"doesn't exist"<<endl;
    	}
    }
    
    root->frees(root);
    //free(root);
    //trie.frees(root);
    /*
     while(q--)
    {
    	cin >> ch;
    	if(root->search(ch))
    	{
    		cout<<"exists"<<endl;
    	}
    	else
    	{
    		cout<<"doesn't exist"<<endl;
    	}
    }
*/

	return 0;
}