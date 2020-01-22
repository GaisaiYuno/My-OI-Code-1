#include<algorithm>
#include<iostream>
#include<fstream>
#include<cstdio>
#include<cmath>
using namespace std;
long long n,m,tn,find_;
char str[100];
string s[1050];
bool ch(int i)
{
  if (s[i].size()<tn)return 0;
  int temp=0;
  for (int k=s[i].size()-tn;temp<tn;k++)
   {
   	 if (str[temp]!=s[i][k])
   	  return 0;
   	 temp++; 
   }
  return 1;
}
bool comp(string a,string b)
{
  long long tempa=0,tempb=0;
  for (int i=0;i<a.size();i++)
   tempa=tempa*10+a[i]-48;
  for (int i=0;i<b.size();i++)
   tempb=tempb*10+b[i]-48; 
  return tempa<tempb; 
}
int main()
{
  freopen("librarian.in","r",stdin);
  freopen("librarian.out","w",stdout);
  cin>>n>>m;
  for (int i=1;i<=n;i++)
   {scanf("%s",&str);s[i]=str;}
  sort(s+1,s+n+1,comp);
  for (int i=1;i<=m;i++)
   {
   	 find_=0;
   	 scanf("%d",&tn);
   	 scanf("%s",&str);
   	 for (int j=1;j<=n;j++)
   	  if (ch(j))
   	   {cout<<s[j]<<endl;
   	    find_=1;
   	    break;}
   	 if (!find_)
	  cout<<"-1\n";
   }
  return 0;
}
