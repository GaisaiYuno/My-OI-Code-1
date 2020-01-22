//librarian
//hrf
#include<iostream>
#include<cstdio>
#include<cmath>
#include<cstring>
#include<cstdlib>
#include<algorithm>
using namespace std;
const int maxn=1005;
int n,q,b[maxn],l[maxn],need[maxn],ans=0;
bool cmp(int x,int y)
{
	return x>y;
}
int find(int x){
	int bei=1;
	int ans1=10000009;
	for(int i=1;i<=l[x];i++)
	  bei*=10;
	for(int i=1;i<=n;i++)
	  if(b[i]%bei==need[x])
	    ans1=min(ans1,b[i]);
	return ans1;
}
int main()
{
	freopen("librarian.in","r",stdin);
	freopen("librarian.out","w",stdout);
	memset(b,0,sizeof(b));
	memset(l,0,sizeof(l));
	memset(need,0,sizeof(need));
    cin>>n>>q;
    for(int i=1;i<=n;i++)
    	cin>>b[i];
    sort(b+1,b+1+n,cmp);//pai
    for(int i=1;i<=q;i++)	
     cin>>l[i]>>need[i];
//caozuo
    int min=10000009;
    int t;
    for(int i=1;i<=q;i++)
    {
    	ans=find(i);
    	if(ans==10000009)cout<<-1;
    	else cout<<ans;
    	cout<<endl;
    }
	return 0;
}
