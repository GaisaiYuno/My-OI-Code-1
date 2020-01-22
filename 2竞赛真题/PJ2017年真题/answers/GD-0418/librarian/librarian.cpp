#include<cstdio>
#include<iostream>
using namespace std;
int n,q;
int main()
{
	freopen("librarian.in","r",stdin);
	freopen("librarian.out","w",stdout);
	int o;
	scanf("%d%d",&n,&q);
	int i,j,k;
	string s[1001];
	char a[1000];
	char c;
	string st;
	string pq;
	bool f1=0,f2=0;
	for(i=1;i<=n;i++)
	 {
	 	cin>>s[i];
	 	a[i]=s[i][0];
     }
	for(i=1;i<=q;i++)
	 {
	 	cin>>o>>st;
	 	for(j=1;j<=n;j++)
	 	{
	 		int l=s[j].length()-1;
	 	if(st[st.length()-1]==s[j][l])
	 	 {
	 	 	for(k=0;k<=st.length()-1;k++)
	 	 	 if(st[st.length()-1-k]==s[j][l-k])
			    f1=1;
	 	 	 else 
			   {
			   f1=0;
			   break;
		       }
	 	 }
	 	  else f1=0;
	 	  
	 	  if(f1)
	 	   if(pq.length()-1>s[j].length()-1)
	 	    {
	 	    pq=s[j];
	 	    c=a[j];
	 	    }
	 	     else if(pq.length()-1==s[j].length()-1&&a[j]<c)
	 	      {
	 	   pq=s[j];
	 	   c=a[j];
	          }
	 	  
	 	  if(!f2&&f1)
	 	   {
	 	   f2=1;
	 	   pq=s[j];
	 	   c=a[j];
	       }
	    }
	    if(pq!="")
	     cout<<pq;
	     else cout<<-1;
	    f2=0;
	    pq="";
	    c=' ';
	 }
	 return 0;
}
