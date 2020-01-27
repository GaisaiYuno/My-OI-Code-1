#include<iostream>
#include<cstdio>
#define maxn 200005
using namespace std;
int n;
char s[maxn];
int ans[maxn];
bool check(int mid){
	int cnt1=0,cnt2=0;
	for(int i=1;i<=n;i++){
		if(s[i]=='('){
			if(cnt1<mid){
				cnt1++;
				ans[i]=1;
			}else if(cnt2<mid){
				cnt2++;
				ans[i]=0;
			}else return 0;
		}else{
			if(cnt1){
				cnt1--;
				ans[i]=1;
			}else{
				cnt2--;
				ans[i]=0;
			}
		}
	}
	return 1;
}
int main(){
	scanf("%d",&n);
	scanf("%s",s+1);
	int l=0,r=n,mid,res=0;
	while(l<=r){
		int mid=(l+r)>>1;
		if(check(mid)){
			res=mid;
			r=mid-1;
		}else l=mid+1; 
	}
	check(res);
	for(int i=1;i<=n;i++) printf("%d",ans[i]);
}

