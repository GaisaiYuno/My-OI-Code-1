#include <iostream>
#include <cstdio>
#define MAXN 500005
#define MAXS 10000000
using namespace std;

int n,d,k,mindis,maxdis,nowpos=0,ans=0;
int x[MAXN],s[MAXN],node[MAXS];
int f[MAXS];

void sjudge()
{
	for (int g=0;g<x[n];g++){
		mindis=1;
		maxdis=1+g;
		while (nowpos<=x[n]){
			for (int i=mindis;i<=x[n]-nowpos;i++){
				if (node[nowpos+i]==0){
					continue;
				}else{
					
				}
			}
		}
	}
}

int main()
{
	int tmp=0;
	freopen ("jump.in","r",stdin);
	freopen ("jump.out","w",stdout);
	cin>>n>>d>>k;
	mindis=d;
	maxdis=d;
	for (int i=1;i<=n;i++){
		cin>>x[i]>>s[i];
		node[x[i]]=s[i];
		if (s[i]>0){
			tmp+=s[i];
		}
	}
	if (tmp<k){
		cout<<"-1"<<endl;
		return 0;
	}
	if (d==1){
		sjudge();
		return 0;
	}
	
	fclose(stdin);
	fclose(stdout);
	return 0;
}
