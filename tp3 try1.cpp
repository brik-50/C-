#include<iostream>
#include<string.h>
using namespace std;
int n,l,h,j;
char **txt,intro[10],*c,*r;
int max(int a,int b)
{
	int m;
	if(a>b)
	{
		m=a;
	}
	else
	{
		m=b;
	}
	return m;
}
int min(int a,int b)
{
	int n;
	if(a>b)
	{
		n=b;
	}
	else
	{
		n=a;
	}
	return n;
}
char* saisir()
{
	char *t;
	cin>>intro;
	t=new char[strlen(intro)+1];
	if(t)
	{
		strcpy(t,intro);
	}
	else
	{
		printf("pas despace");
		exit(-1);
	}
	return t;
}
char* cmp(char *t1,char *t2)
{
	int x,y,k=0,n1,n2,i;
	n1=strlen(t1);
	n2=strlen(t2);
	char *t;
	t=new char[max(n1,n2)];
    for(i=0;i<min(n1,n2);i++)
    {
    	x=t1[i],y=t2[i];
    	if(x>y)
    	{
    		strcpy(t,t1);
    		break;
		}
		else if(x<y)
		{
			strcpy(t,t2);
			break;
		}
		else
		{
			k=k+1;
		}
	}
	if(k==min(n1,n2))
	{
		if(n1==min(n1,n2))
		{
			strcpy(t,t2);
		}
		else
		{
			strcpy(t,t1);
		}
	}
	return t;
}
char* fin(char**tab,int f)
{
	for(h=f+1;h<n;h++)
	{
		c=cmp(tab[f],tab[h]);
		if(strcmp(c,tab[h])==0)
		{
			r=tab[h];
			tab[h]=tab[f];
			tab[f]=r;
		}
		
	}
    return tab[f];
}
main()
{
	cout<<"la dim ";
	cin>>n;
	txt=new char*[n];
	for(l=0;l<n;l++)
	{
		cout<<"t["<<l+1<<"]"<<"\t";
		txt[l]=saisir();
	}
	for(l=0;l<n;l++)
	{
		cout<<fin(txt,l)<<"\n";
	}
}

