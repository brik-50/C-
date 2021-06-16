
#include<iostream>
using namespace std;
main()
{
	int n,*t,i,j,k,z;
	cout<<"donner la dim de tableau ";
	cin>>n;
	t=new int[n];
	for(i=0;i<n;i++)
	{
		cout<<i<<"\t";
		cin>>t[i];
	}
	cout<<"affichage \n";
	for(i=0;i<n;i++)
	{
		cout<<t[i]<<"\t";
	}
	cout<<"\n___________ \n";
	int *ttt;
	ttt=new int[2*n];
	ttt[0]=t[0];
	int c;
	int p=0;
	for(i=p;i<n;i++)
	{
		c=0;
		for(j=0;j<=p;j++)
		{
			if(t[i]==ttt[j])
			{
				c=1;
				break;
			}
		}
		if(c==0)
		{
			p+=2;
			ttt[p]=t[i];
		}
	}
	for(i=0;i<=p;i+=2)
	{
		k=0;
		for(j=0;j<n;j++)
		{
			if(ttt[i]==t[j])
			{
				k++;
			}
		}
		ttt[i+1]=k;
	}
	cout<<p+1<<"\n";
	for(i=0;i<=p+1;i++)
	{
		cout<<ttt[i]<<"\t";
	}
}





/*
//tp1 ex1 qst 2 //

#include<stdio.h>
int t1[10],i,t3[20];
main()
{
	const int n=10;
	for(i=0;i<n;i++)
	{
		printf("t[%d] ",i+1);
		scanf("%d",&t1[i]);
	}
	for(i=0;i<n;i++)
	{
		printf("%d ",t1[i]);
	}
	t3[0]=t1[0];
	int j=0;
	int tst=0;
	int k=2;
	int l=0;
	int x=0;
	for(i=l;i<n;i++)
	{
		if(t1[i]!=t1[i+1])
		{
			for(j=0;j<i;j++)
			{
				if(t1[i+1]!=t1[j])
				{
					tst=0;
				}
				else
				{
					tst=1;
					break;
				}
			}
			if(tst==0)
			{
				t3[k]=t1[i+1];
				k=k+2;
				l=i+1;
				tst=0;
				x=x+1;	
			}
		}
	}
    printf("\n");
	for(i=0;i<2*x;i++)
	{
		printf("%d ",t3[i]);
	}
		int c=0;
	printf("\n");
	for(i=0;i<2*x;i+=2)
	{
		for(j=0;j<n;j++)
		{
			if(t3[i]==t1[j])
			{
				c=c+1;
			}
		}
		t3[i+1]=c;
		c=0;
	}
	for(i=0;i<2*x;i++)
	{
		printf("%d ",t3[i]);
	}

	
}


*/
