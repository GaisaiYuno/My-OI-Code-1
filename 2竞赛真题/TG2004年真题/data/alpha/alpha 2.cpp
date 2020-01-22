#include<iostream>
#include<cstdio>
#include<cstring>
#include<map>
#include<fstream>
using namespace std;
int n;
char s1[30],s2[30],s3[30];
int alls[90];
map<char,int>x;
map<char,int>used_letter;
int used_num[30];
int jw[30];
bool flag=false;
int is_back_ok(int now) {
	for(int i=3*n-1; i>now; i-=3) {
		if((used_letter[alls[i]]&&used_letter[alls[i-1]]&&used_letter[alls[i-2]])
		        &&(x[alls[i]]!=(x[alls[i-1]]+x[alls[i-2]])%n)
		        &&(x[alls[i]]!=(x[alls[i-1]]+x[alls[i-2]]+1)%n)) {
			return 0;
		}
	}
	return 1;
}
int is_this_ok(int now) {
	if(now%3!=2) return 1;
	int cons=now/3*3;
	int sum=x[alls[cons]]+x[alls[cons+1]]+jw[now/3];
	int tmp=sum;
	sum%=n;
	if(sum==x[alls[cons+2]]) {
		jw[now/3+1]=tmp/n;
		return 1;
	}
	return 0;
}
void dfs(int now) {
	if(flag) return;
	if(is_this_ok(now-1)==0) return;
	if(is_back_ok(now-1)==0) return;
	if(now==n*3) {
		flag=true;
		std::map<char,int>::iterator it;
		for(it=x.begin();it!=x.end();it++){
		    cout<<it->second<<' '; 
		} 
		return;
	}
	if(used_letter[alls[now]]==0) {
		for(int i=n-1; i>=0; i--) {
			if(used_num[i]==0) {
				int temp_jw=jw[now/3];
				x[alls[now]]=i;
				used_letter[alls[now]]=1;
				used_num[i]=1;
				dfs(now+1);
				used_letter[alls[now]]=0;
				used_num[i]=0;
				jw[now/3]=temp_jw;
			}
		}
	}
	else dfs(now+1);
	return;
}
int main() {
	//freopen("alpha8.in","r",stdin);
	//freopen("alpha.out","w",stdout);
	cin>>n;
	cin>>s1;
	cin>>s2;
	cin>>s3;
	for(int i=0; i<n; i++) {
		alls[3*(n-1-i)]=s1[i];
		alls[3*(n-1-i)+1]=s2[i];
		alls[3*(n-1-i)+2]=s3[i];
	}
	dfs(0);
	return 0;
}
