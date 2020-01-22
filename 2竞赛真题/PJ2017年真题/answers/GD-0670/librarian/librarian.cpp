#include<iostream>
#include<cstdio>
#include<algorithm>
#include<string>
using namespace std;

int main()
{
	freopen(" librarian.in","r",stdin);
	freopen(" librarian.out","w",stdout);
 	int n,q;
 	string number[1001],reader,ans[1001];
 	cin>>n>>q;
 	for(int i=0;i<n;i++)cin>>number[i];
 	for(int i=0;i<q;i++)
 	{
 		int t=1000000,s,min,o=0;
 		cin>>s>>reader;
 		for(int j=0;j<n;j++)
 		{
 			int k=0,l=0;
 			for(int x=number[j].size()-s;x<number[j].size();x++)
 			{
 				if(reader[k]==number[j][x])l++;
 				k++;
 			}
 			if(l==s)if(number[j].size()<t){min=j;o=1;}
 		}
 		if(o==1)ans[i]=number[min];
 		else ans[i]="-1";
 	}
 	for(int i=0;i<q;i++)cout<<ans[i]<<endl;
 	return 0;
}
