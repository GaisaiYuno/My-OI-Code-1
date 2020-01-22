#include<iostream>
#include<cstdio>
using namespace std;
int a,b,k;
int ts[9][1000],o[1000],zz[9];
int main()
{
	freopen("librarian.in","r",stdin);
	freopen("librarian.out","w",stdout);
	for(int q=0;q<10;++q)
	zz[q]=0;
	cin>>a>>b;
	for(int q=0;q<a;++q)
	{
		cin>>k;
		if(k/10==0) { ts[1][zz[1]]=k; zz[1]++;}
		else
		if(k/100==0) { ts[2][zz[2]]=k; zz[2]++;}
		else
		if(k/1000==0) { ts[3][zz[3]]=k; zz[3]++;}
		else
		if(k/10000==0) { ts[4][zz[4]]=k; zz[4]++;}
		else
		if(k/100000==0) { ts[5][zz[5]]=k; zz[5]++;}
		else
		if(k/1000000==0) { ts[6][zz[6]]=k; zz[6]++;}
		else
		if(k/10000000==0) { ts[7][zz[7]]=k; zz[7]++;}
		else
		if(k/100000000==0) { ts[8][zz[8]]=k; zz[8]++;}
	}
	for(int q=0;q<b;++q)
	{
		int p,i,zx;
		cin>>p>>i;
		int y=10;
		for(int wt=1;wt<p;++wt)
		y=y*10;
		for(int w=p;w<9;++w)
		{
			for(int e=0;e<zz[w];++e)
			{
				if(ts[w][e]%y==i && (o[q]>ts[w][e]||o[q]==0))
				o[q]=ts[w][e];
			}
			if(o[q]!=0)
			goto js;
			if(w==8&&o[q]==0)
			o[q]=-1;
		}
		js:;
	}
	for(int q=0;q<b;++q)
	cout<<o[q]<<endl;
	return 0;
}
