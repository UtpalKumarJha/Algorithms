#include<bits/stdc++.h>
using namespace std;

struct node
{
	struct node *next;
	int value;
};

typedef struct node ll;
int n,a,x,y;

int main()
{
	cin >> n;

    ll *first = new node();
    ll *start = first;

	for(int i=0;i<n;i++)
	{
		cin >> a;
		start->value=a;
		start->next=new node();
		start = start->next; 
	}

    cout<<"Enter the position where in you want to insert next integer along with it's value"<<endl;

    cin >> x >> y; 

    start = first;

    for(int i=0;i<x;i++)
    {
       start=start->next;
    }

    ll *temp = new node();
    ll *temp1 = new node();

    temp1 = start->next;
   
    start->next = NULL;

    start->next=temp;
    temp->value=y;
    temp->next=temp1;

    start = first;

    while(start->next)
    {
    	cout<<start->value<<" ";
    	start= start->next;
    }

    cout<<endl;


    cout<<"Enter the position from wherein you want to delete it's value"<<endl;
    cin >> n;
    start=first;
    for(int i=0;i<n-1;i++)
    {
    	start=start->next;
    }
    
    temp = start->next->next;
    delete(start->right);
    start->right=temp;
    
    start = first;
    while(start->next)
    {
    	cout<<start->value<<" ";
    	start= start->next;
    }

    cout<<endl;
	return 0;
}