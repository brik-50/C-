//tp2 qst 1
#include<iostream>
using namespace std;
int i,j;
const int n=5;
int t[n][n];
main()
{
	for(i=0;i<n;i++)
	{
		t[i][0]=1;
		t[i][i]=1;
		for(j=1;j<i;j++)
		{
			t[i][j]=t[i-1][j]+t[i-1][j-1];
		}
	}
	for(i=0;i<n;i++)
	{
		for(j=0;j<i+1;j++)
		{
			cout<<t[i][j];
		}
		cout<<"\n";
	}
}
