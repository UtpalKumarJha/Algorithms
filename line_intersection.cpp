#include<bits/stdc++.h>
using namespace std;

int A1,A2,B1,B2,C1,C2;

int main()
{
    int x1,x2,x3,x4,y1,y2,y3,y4;    	
	cout << "ENTER THE COORDINATES OF FIRST LINE SEGMENT"<<endl;
	cin >> x1 >> y1 >> x2 >> y2;
	cout << "ENTER THE CORDINATES OF SECOND LINE SEGMENT"<<endl;
	cin >> x3 >> y3 >> x4 >> y4;
	
	A1 = x2-x1;
	B1 = y2-y1;
	C1 = A1*x1 + B1*y1;
	
	A2 = x4-x3;
	B2 = y4-y3;
    C2 = A2*x3 + B2*y3;
    
    double det = A1*B2-A2*B1;
    
    
    if(det==0)
    {
		cout << "lines are parallel"<<endl;
	}
	else
	{
		cout << "The points of intersection of two lines are"<<endl;
		double x = (B1*C2-B2*C1)/det;
		double y = (A1*C2-A2*C1)/det;
		cout << x<< " "<<y <<endl;
	}	

	
	return 0;
}
