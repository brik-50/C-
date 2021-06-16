#include<iostream>
using namespace std;
class vecteur{
	int a,b,c; 
	public:
		vecteur(int x=1,int y=1,int z=1)
		{
			a=x;
			b=y;
			c=z;
		}
		void deplace(int dx=0,int dy=0,int dz=0)
		{
			a=a+dx;
			b=b+dy;
			c=c+dz;
		}
		void affichage()
		{
			cout<<"\n";
			cout<<a<<"\t"<<b<<"\t"<<c<<"\n";
		}
		int produit(vecteur v2)
		{
			int z=a*v2.a+b*v2.b+c*v2.c;
			return z;
		}
		int produit(vecteur *v2)
		{
			int z=a*v2->a+b*v2->b+c*v2->c;
			return z;
		}
};
int produit(vecteur v0,vecteur v1) 
{
	int z;
	z=v0.produit(v1); 
	return z;
}
int produit(vecteur *v0,vecteur *v1)
{
	int z=0;
	z=v0->produit(*v1);
	return z;
}
main()
{
	vecteur v,v2(1,2,3);
	cout<<"affichage de vecteur "<<endl;
	v.affichage();
	cout<<"affichage de vecteur2 "<<endl;
	v2.affichage();
	vecteur *a,*b;
	a=new vecteur(1,2,3);
	b=new vecteur(2,2,2);
	cout<<"affichage de a "<<endl;
	a->affichage();
	cout<<"affichage de b "<<endl;
	b->affichage();
	cout<<"\n";
	cout<<"affichage de a apres la fonction du deplacement "<<endl;
	a->deplace(1,1,1);
	a->affichage();
	cout<<"affichage de produit de a et b "<<endl;
	cout<<produit(a,b);
}
