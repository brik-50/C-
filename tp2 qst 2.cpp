#include<iostream>
#include<string.h>
using namespace std;
char intro[10];// tableau intermidiaire pour faire une allocation dynamique des
//chaine de caractere. 


//fonction qui calcule la longueur d une chaine de caracteres.
int lngr(char *tab)
{
	int j=0,l=0;
	while(tab[j]!='\0')
	{
		j++;
		l++;
	}
	return l;
}
/* on peut aussi utiliser cette forme :
int lngr(char *tab)
{
	for(int j=0;tab[j]!='\0';j++);
	return j;
}
*/
//programme qui peremt de comparer deux chaines de caractere: 
int cmp(char *t1,char *t2)
{
	int i1;
	//on chereche premieremnt l indice de caractere different entre 2 chaine de caractere .
	//car si 2 indice sont les meme il faut passer au deuxieme.
	while(t1[i1]==t2[i1]&&t1[i1]!='\0')
	{
		i1++;
	}
	// on note i1 lindice de cararctere different entre 2 chaine.
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
//le code qui permet de poser les chaines de caractere en ordre par rapport 
// au code acii de indice de difference.

void tp(char **txt,int n1)
{
	char *ptr;// pointeur intermidiaire.
	int h,l;
	ptr=new char[10];
	//en parcouris tout les chaine de caractere
	// en utilise le principe de tire de bulle pour l ordre des chaines:
	for(l=n1-1;l>=1;l--)
	{
		for(h=0;h<l;h++)
		{
			if(cmp(txt[h],txt[h+1])==1)
			{
				ptr=txt[h];
				txt[h]=txt[h+1];
				txt[h+1]=ptr;
			}
		}
	}
	// affichage de tableau par ordre.
	for(h=0;h<n1;h++)
	{
		cout<<"t("<<h+1<<")="<<txt[h]<<"\n";
	}
	
}
// location dynamique des chaine de caractere.
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
main()
{
	int n,i;
	char **t;
	cout<<"donner n ";
	cin>>n;
	t=new char*[n];
	for(i=0;i<n;i++)
	{
		cout<<"t("<<i+1<<")";
		t[i]=saisir();
	}
	for(i=0;i<n;i++)
	{
		cout<<"t("<<i+1<<")="<<t[i]<<"\t"<<lngr(t[i])<<"\n";
	}
	cout<<"\n";
	tp(t,n);
}
