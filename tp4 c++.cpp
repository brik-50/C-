#include<iostream>
#include<cmath>
using namespace std;
// la fonction de reservation :
float*** reservation(float ***t,int m,int l,int c)
{
	
	int i1,j1;
	t=new float**[m];
	for(i1=0;i1<m;i1++)
	{
		t[i1]=new float *[l];
		for(j1=0;j1<l;j1++)
		{
			t[i1][j1]=new float[c];
			for(int k1=0;k1<c;k1++)
			{
				t[i1][j1][k1]=0;
			}
		}
	}
	return t;
}
// la fonction de remplissage des matrice paire.
float*** remplissage(float ***t,int m,int l,int c)
{
	int i2,j2,k2;
	for(k2=0;k2<m;k2=k2+2)
	{
		for(i2=0;i2<l;i2++)
		{
			for(j2=0;j2<c;j2++)
			{
			     cout<<"t["<<k2<<"]["<<i2<<"]["<<j2<<"]=\t ";
				 cin>>t[k2][i2][j2];	
			}
		}
	}
	return t;
}
//affichage de tout les matrices paire avec leurs valeurs et impaire de valeurs nulle.
float*** affichage(float ***t,int m,int l,int c)
{
	int i3,j3,k3;
	for(k3=0;k3<m;k3=k3+1)
	{
		cout<<"matrice n "<<k3<<"\n";
		for(i3=0;i3<l;i3++)
		{
			for(j3=0;j3<c;j3++)
			{
				cout<<"\t "<<t[k3][i3][j3];
			}
			cout<<"\n";
		}
		cout<<"\n \n";
	}
	return t;
}

float fc(int i)
{
	int cc;
	if(i==0)
	{
		cc=1;
	}
	else
	{
		cc=1/sqrt(2);
	}
	return cc;
}
//fonction a remplir les matrice impaire.
float*** calcul(float ***t,int m,int l,int c)
{
	int num,num2,k4,i4,j4,s;
	for(k4=1;k4<m;k4=k4+2)
	{
		for(num=0;num<l;num=num+4)
		{
			for(num2=0;num2<c;num2=num2+4)
			{
				for(i4=num;i4<num+4;i4++)
				{
					for(j4=num2;j4<num2+4;j4++)
					{
						 s=0;
						 for(int x=0;x<4;x++)
						 {
						 	for(int y=0;y<4;y++)
						 	{
						 		s=s+t[k4-1][x][y]*cos((2*x+1)*i4*3.14/16)*cos((2*y+1)*j4*3.14/16);
							}
						 }
						 t[k4][i4][j4]=(1/sqrt(2))*fc(i4)*fc(j4)*s;
					}
				}
			}
		}
	}
	return t;
}
main()
{
	int m,l,c;
	float ***T;
	cout<<"donner m=nombre de matrice ";
	cin>>m;
	cout<<"donner l=nombre de ligne ";
	cin>>l;
	
	while(l%4!=0)
	{
		cout<<"donner l=nombre de ligne *4 ";
	    cin>>l;
	}
	cout<<"donner c=nombre de colone ";
	cin>>c;
	while(c%4!=0)
	{
		cout<<"donner c=nombre de colone *4 ";
	    cin>>c;
	}
	
	T=reservation(T,m,l,c);
	T=remplissage(T,m,l,c);
	T=affichage(T,m,l,c);
	T=calcul(T,m,l,c);
	T=affichage(T,m,l,c);

}
