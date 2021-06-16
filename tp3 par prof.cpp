#include<iostream>
#include<string.h>
using namespace std;
char intro[10];
int lngr(char *tab)
{
	int l=0;
	while(tab[l]!='\0')
	{
		
		l++;
	}
	return l;
}
int cmp(char *t1,char *t2)
{
	int i1;
	
	while(t1[i1]==t2[i1]&&t1[i1]!='\0')
	{
		i1++;
	}

	if(t1[i1]>t2[i1])
	{
		return 1;
	}
	else if(t1[i1]<t2[i1])
	{
		return -1;
	}
	else
	{
		return 0;
	}
}
void trier(char **txt,int n1)
{
	char *p;
	int h,l;
	p=new char[10];
	
	for(l=n1-1;l>=1;l--)
	{
		for(h=0;h<l;h++)
		{
			if(cmp(txt[h],txt[h+1])==1)
			{
				p=txt[h];
				txt[h]=txt[h+1];
				txt[h+1]=p;
			}
		}
	}
	for(h=0;h<n1;h++)
	{
		cout<<txt[h]<<"\n";
	}}
char* saisir(){
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
main(){
	int n,i;
	char **t;
	cout<<"donner n ";
	cin>>n;
	t=new char*[n];
	for(i=0;i<n;i++)
	{
		cout<<"donner le mot";
		t[i]=saisir();
	}
	for(i=0;i<n;i++)
	{
		cout<<t[i]<<"\t"<<lngr(t[i])<<"\n";
	}
	cout<<"\n";
	trier(t,n);
}
