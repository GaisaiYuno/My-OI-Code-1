#include<iostream>
#include<cstring>
using namespace std;
int t,n,sum,ans;
char S[1000],F[1000];
void dfs(int a,int b,int c){
	if(a>b)return;
	if(a*2>n||b*2>n)return;
	int x=c;
	bool k=1;
	for(int i=1;i<sum;i++){
		if(S[i]!=F[i]){
			k=0;break;
		}
	}
	if(k){
		x++;
	}
	if(a+b==n){
		ans+=x;
	}
	char f=F[1];
	for(int i=1;i<sum-1;i++){
		F[i]=F[i+1];
	}
	F[sum-1]='0';
	dfs(a+1,b,x);
	F[sum-1]='1';
	dfs(a,b+1,x);
	for(int i=sum-1;i>1;i--){
		F[i]=F[i-1];
	}
	F[1]=f;
	return;
}
int main(){
	cin>>t;
	for(int i=0;i<t;i++){
		memset(S,0,sizeof(S));
		memset(F,0,sizeof(F));
		ans=0,sum=0;
		cin>>n;
		getchar();
		for(sum=1;;sum++){
			char s;
			s=getchar();
			if(s=='\n')break; 
			S[sum]=s;
		}
		dfs(0,0,0);
		cout<<ans<<endl;
	}
	return 0;
} 
