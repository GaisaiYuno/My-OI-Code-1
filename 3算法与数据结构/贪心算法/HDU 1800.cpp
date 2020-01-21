#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
#define maxn 3005
using namespace std;
int n;
long long a[maxn];
int used[maxn];
inline int fastread(){
	long long x=0;
	int sign=1;
	char c=getchar();
	while(c<'0'&&c>'9'){
		if(c=='-') sign=-1;
		c=getchar();
	}
	while(c>='0'&&c<='9'){
		x=x*10+c-'0';
		c=getchar();
	}
	return x*sign;
}
int cmp(int x,int y){
	return x>y;
}
int main(){
	while(cin>>n){
		for(int i=1;i<=n;i++) a[i]=fastread();
		memset(used,0,sizeof(used));
		sort(a+1,a+1+n,cmp);
		long long tmp=0;
		int cnt=0;
		for(int i=1;i<=n;i++){
			if(used[i]==0){
				tmp=a[i];
				used[i]=1;
				for(int j=i+1;j<=n;j++){
					if(used[j]==0&&tmp<a[j]){
						tmp=a[j];
						used[j]=1;
					}
				}
				cnt++;
			}
		}
		cout<<cnt<<endl; 
	}
} 
