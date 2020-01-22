/*
读入书量、读者数量 
用书量 读入书号
翻转书号 储存
读入读者 
first  读入书号
second 读入需求号 判断a中书有没有以需求号结尾的 翻转 
       判断这些书中号码最小的 
third  输出 
*/
#include<cmath>
#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
using namespace std;

int main()
{
	freopen("librarian.in","r",stdin);
	freopen("librarian.out","w",stdout);
	char an[100],a[100][100]={0},b[100]={0},bn[100],d[100],jl[100]={0},c[100][100];
	int j,x=1,cw=0,h;
	int n,q,number,S,zx;
	cin>>n>>q;
	for(int i=1;i<=n;i++)//读入总图书量  用c来储存长度 
	{
		x=1;
		cin>>an;
		j=strlen(an);
		S=j;
		while(j>=0)//翻转书号 
		{
			a[i][x]=an[j-1];
			//cout<<a[i][x];
			x++;
			j--;
		}
		
		
	}
	
	for(int i=1;i<=q;i++)//读入书号长度
	{
		x=1;
		cin >> d[i];
		cin>>bn;	
		j=strlen(bn);
		
		while(j>=0)
		{
			b[x]=bn[j];
			//cout<<b[x];
			x++;
			j--;
		}
		
		for(j=1;j<=n;j++)//书的本数 
		{
			cw=0;
			for(x=1;x<d[i];x++)
			{
				if(a[i][x]!=b[x])
				{
					c[j]=a[i];
					h++;
				}
				
			}	
		}
		if(c=='0') cout<< '-1';
	}
	
	
    return 0;
}
