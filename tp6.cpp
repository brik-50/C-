#include<iostream>
using namespace std;
class matrice{
	int c,l,**m;
	public:
		matrice(int a=2,int b=2)
		{
			c=b;
			l=a;
			m=new int*[l];
			for(int i=0;i<l;i++)
			{
				m[i]=new int[c];
			}
		}
		void initialise()
		{
			for(int i=0;i<l;i++)
			{
				for(int j=0;j<c;j++)
				{
					cout<<i+1<<"\t";
					cin>>m[i][j];
				}
			}
		}
		void affichage()
		{
			cout<<"\n";
			for(int i=0;i<l;i++)
			{
				for(int j=0;j<c;j++)
				{
					cout<<m[i][j]<<"\t";
				}
				cout<<"\n";
			}
		}
	    matrice(matrice &v)
		{
			c=v.c;
			l=v.l;
			m=new int*[l];
			for(int i=0;i<l;i++)
			{
				for(int j=0;j<c;j++)
				{
					m[i][j]=v.m[i][j];
				}
			}
		}
		~matrice()
		{
			for(int i=0;i<l;i++)
			{
				delete []m[i];
			}
			delete []m;
		}
		produit(matrice &w)
		{
			if(c!=w.l)
			{
				cout<<"impossible de faire le produit \n";
			}
			else
			{
				int s=0;
				int **p;
				p=new int*[l];
				for(int i=0;i<l;i++)
				{
					p[i]=new int[w.c];
				}
				for(int i=0;i<l;i++)
				{
					for(int j=0;j<w.c;j++)
					{
						s=0;
						for(int k=0;k<c;k++)
						{
							s=s+p[i][k]*w.p[k][j];
						}
						p[i][j]=s;
					}
				}
				for(int i=0;i<l;i++)
				{
					for(int j=0;j<w.c;j++)
					{
						cout<p[i][j]<<"\t";
					}
					cout<<"\n";
				}
			}
		}
};
main()
{
	matrice a(2,1),b(3,2);
	a.initialise();
	cout<<"l'affichage de la matrice 1 "<<endl;
	a.affichage();
	cout<<"\n";
	b.initialise();
	cout<<"l'affichage de la matrice 2 "<<endl;
	b.affichage();
	a.produit(b);
}
