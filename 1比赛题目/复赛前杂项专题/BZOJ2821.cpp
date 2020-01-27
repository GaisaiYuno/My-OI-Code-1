#include<iostream>
#include<cstdio>
#include<cstring> 
#include<cmath>
#define maxn 100000
#define maxb 330 
using namespace std;
int n,m,c;
inline void qread(int &x){
	x=0;
	int sign=1;
	char c=getchar();
	while(c<'0'||c>'9'){
		if(c=='-') sign=-1;
		c=getchar();
	}
	while(c>='0'&&c<='9'){
		x=x*10+c-'0';
		c=getchar();
	}
	x=x*sign;
}
inline void qprint(int x){
	if(x<0){
		putchar('-');
		qprint(-x); 
	}else if(x==0){
		putchar('0');
		return;
	}else{
		if(x>=10) qprint(x/10);
		putchar('0'+x%10);
	}
}
int a[maxn+5];
int bsz,bcnt;
int bel[maxn+5],lb[maxn+5],rb[maxn+5];

int cnt[maxn+5];
int sum[maxb+5][maxn+5];//ǰi����ÿ�����ĳ��ִ��� 
int res[maxb+5][maxb+5];//��i����j�Ĵ� 
void pre_work(){
	for(int i=1;i<=n;i++) sum[bel[i]][a[i]]++;
	for(int i=1;i<=c;i++){
		for(int j=1;j<=bcnt;j++) sum[j][i]+=sum[j-1][i];
	}
	for(int i=1;i<=bcnt;i++){
		int now=0;
		for(int j=lb[i];j<=n;j++){
			cnt[a[j]]++;
			if(cnt[a[j]]%2==0) now++;
			else if(cnt[a[j]]>2) now--;
			res[i][bel[j]]=now;
		}
		for(int j=lb[i];j<=n;j++) cnt[a[j]]--;//��ԭ 
	}
}

int query(int l,int r){
	int ans=0;
	if(bel[l]==bel[r]){
		for(int i=l;i<=r;i++){
			//if(check(cnt[a[j]]) now--;
			//cnt[a[j]]++;
			//if(check(cnt[a[j]]) now++; 
			cnt[a[i]]++;
			if(cnt[a[i]]%2==0) ans++;
			else if(cnt[a[i]]>2) ans--;
			//���cnt[a[i]]=1,��ô֮ǰcnt[a[i]]=0,��δ��Ϊ��ż��������𰸣�����-- 
			//����ԭ������ż���α�����1�Σ����ڱ�������Σ�Ҫ-- 
		}
		for(int i=l;i<=r;i++) cnt[a[i]]--;
		return ans; 
	}
	ans=res[bel[l]+1][bel[r]-1];
	//����ɢ�Ŀ� 
	for(int i=l;i<=rb[bel[l]];i++){
		cnt[a[i]]++;
		if((cnt[a[i]]+sum[bel[r]-1][a[i]]-sum[bel[l]][a[i]])%2==0) ans++;
		else if((cnt[a[i]]+sum[bel[r]-1][a[i]]-sum[bel[l]][a[i]])>2) ans--;
	}
	for(int i=lb[bel[r]];i<=r;i++){
		cnt[a[i]]++;
		if((cnt[a[i]]+sum[bel[r]-1][a[i]]-sum[bel[l]][a[i]])%2==0) ans++;//���ɢ�Ĳ���+�м�����һ������ż���Σ���++ 
		else if((cnt[a[i]]+sum[bel[r]-1][a[i]]-sum[bel[l]][a[i]])>2) ans--;
	}
	for(int i=l;i<=rb[bel[l]];i++) cnt[a[i]]--;
	for(int i=lb[bel[r]];i<=r;i++) cnt[a[i]]--;
	return ans;
}
int main(){
//	freopen("2.in","r",stdin);
	int l,r;
	qread(n);
	qread(c);
	qread(m);
	for(int i=1;i<=n;i++) qread(a[i]);
//	bsz=sqrt(n/(log(n)/log(2)));
	bsz=sqrt(n);
	bcnt=1;
	for(int i=1;i<=n;i++){
		bel[i]=bcnt;
		if(i%bsz==0) bcnt++;
	}
	for(int i=1;i<=n;i++){
		lb[i]=(i-1)*bsz+1;
		rb[i]=min(i*bsz,n);		
	} 
	pre_work();
	int last=0;
	for(int i=1;i<=m;i++){
		qread(l);
		qread(r);
		l=(l+last)%n+1;
		r=(r+last)%n+1;
		if(l>r) swap(l,r);
		last=query(l,r);
		qprint(last);
		putchar('\n');
	}
}
