/*
������������������ 
������ �������
��ת��� ����
������� 
first  �������
second ��������� �ж�a������û��������Ž�β�� ��ת 
       �ж���Щ���к�����С�� 
third  ��� 
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
	for(int i=1;i<=n;i++)//������ͼ����  ��c�����泤�� 
	{
		x=1;
		cin>>an;
		j=strlen(an);
		S=j;
		while(j>=0)//��ת��� 
		{
			a[i][x]=an[j-1];
			//cout<<a[i][x];
			x++;
			j--;
		}
		
		
	}
	
	for(int i=1;i<=q;i++)//������ų���
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
		
		for(j=1;j<=n;j++)//��ı��� 
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
