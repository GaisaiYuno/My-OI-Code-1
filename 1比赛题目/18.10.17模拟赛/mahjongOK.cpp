//直接模拟
//O(n^3) 
#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#define maxn 3005
using namespace std;
int n,m;
int a[maxn];
int cnt[maxn];
int tmp[maxn];
int maxa;
int check(int val){
	int vis=0;
	bool flag=false;
	cnt[val]++; 
	for(int i=1;i<=n;i++){//枚举对子 
		if(cnt[i]<2) continue;//如果个数太少，继续
		for(int j=1;j<=n;j++){
			tmp[j]=cnt[j];
		} 
		tmp[i]-=2;
		vis=0;
		flag=false;
		for(int j=1;j<=maxa-2;j++){//以[1,maxa-2]为起点找顺子，每个数i和i+1,i+2配对 
			if(tmp[j]<0) break;//不够
			if(j==maxa-2) flag=true; 
			if(tmp[j]==0) continue;
			int shun=tmp[j]%3; 
			for(int k=1;k<=shun;k++){//选tmp%3个顺子 
				tmp[j]--;
				tmp[j+1]--;
				tmp[j+2]--;
				vis++;
			}
			vis+=tmp[j]/3;//选tmp/3个刻子 
			tmp[j]=0;
		}
		if(!flag) continue;
		//最后两个数单独选 
		vis+=tmp[maxa-1]/3+tmp[maxa]/3;//选刻子 
		tmp[maxa-1]%=3;
		tmp[maxa]%=3;
		if(vis==m) flag=true;//选完所有数 
		if(tmp[maxa-1]!=0||tmp[maxa]!=0) flag=false;
		if(flag) break;
	}
	cnt[val]--;
	return flag;
}
int main(){
	bool ok=false;
	scanf("%d %d",&n,&m);
	for(int i=1;i<=m*3+1;i++){
		scanf("%d",&a[i]);
		maxa=max(maxa,a[i]);
		cnt[a[i]]++;
	}
	for(int i=1;i<=n;i++){
		maxa=max(maxa,i);
		if(check(i)){
			printf("%d ",i);
			ok=true;
		}
	}
	if(!ok) printf("NO");
}
