#include<bits/stdc++.h>
using namespace std;

struct node
{
    struct node *left;
    struct node *right;
    int value;
};

typedef struct node ll;

int a,n;

int main()
{
    cin >> n;

    ll *first=new node();
    ll *start = first;
    ll *temp= new node();

    for(int i=0;i<n;i++)
    {
        cin >> a;
        if(i==0)
        {
           temp=start; 
           start->left=NULL;
           start->value=a;
           start->right = new node();
           start=start->right;
        }
        else if(i==n-1)
        {
           start->right=NULL;
           start->value=a;
           start->left=temp;
        }
        else
        {
           start->left=temp;
           start->right=new node();
           start->value=a;
           temp=start;
           start=start->right;
        }
    }

    start = first;

    while(start->right)
    {
        cout<<start->value<<" ";
        start=start->right;
    }
    cout<<start->value;
    cout<<endl;

    while(start->left)
    {
        cout<<start->value<<" ";
        start=start->left;
    }
    cout<<start->value;
    cout<<endl;

    return 0;
}