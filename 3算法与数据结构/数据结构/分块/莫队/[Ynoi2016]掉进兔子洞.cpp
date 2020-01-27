//https://www.luogu.org/problem/P4688
//��Ϊ���䳤��-ÿ���������������г��ֵ���С����*3
//������bitsetά������Ȩֵ���ϣ���ͬ����������ͬ�� 
//andһ�¾͵õ���С���� 
//��ѯ�ʵ���������𿪽��������ٺϲ� 
#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<algorithm>
#include<bitset>
#define maxn 100000
#define maxt 25000
using namespace std;
int n,m; 
int a[maxn+5];
int tmp[maxn+5];
void discrete(){
	//���ֿ����ظ����֣�bitsetֻ�ܼ�¼0��1����ɢ��ǰ����ȥ�ء�
	//1 2 2 3 3 ->1 2 2 4 4
	//Ȼ�󴢴��ʱ����x+cnt[x]�洢��ͬ���������1��2�洢��3 
	for(int i=1;i<=n;i++) tmp[i]=a[i];
	sort(tmp+1,tmp+1+n);
	for(int i=1;i<=n;i++) a[i]=lower_bound(tmp+1,tmp+1+n,a[i])-tmp; 
}
int bsz;
int belong[maxn+5];
struct que{
	int l;
	int r;
	int id;
	friend bool operator < (que p,que q){
		if(belong[p.l]==belong[q.l]) return p.r<q.r;
		else return belong[p.l]<belong[q.l];
	}
}q[maxn+5];
bitset<maxn+5>f;
bitset<maxn+5>res[maxt+5];
int cntv[maxn+5];
int len[maxt+5];
void add(int val){
	//��x����������Ϊcntv[x]��ʱ��bitset��[x+cntv[x]]λΪ1 
	f[val+cntv[val]]=1;
	cntv[val]++;
}
void del(int val){
	f[val+cntv[val]-1]=0;
	cntv[val]--;
}

void print(bitset<maxn+5> &x){
	for(int i=0;i<n;i++) cout<<x[i];
	printf("\n");
}
void solve(int x,int y){//�������� 
	int l,r;
	int cnt=0;
	memset(cntv,0,sizeof(cntv));
	memset(len,0,sizeof(len));
	f.reset();
	for(int i=x;i<=y;i++){
		cnt++;
		scanf("%d %d",&q[cnt].l,&q[cnt].r);
		len[i-x+1]+=q[cnt].r-q[cnt].l+1;
		q[cnt].id=i-x+1;
		
		cnt++;
		scanf("%d %d",&q[cnt].l,&q[cnt].r);
		len[i-x+1]+=q[cnt].r-q[cnt].l+1;
		q[cnt].id=i-x+1;
		
		cnt++;
		scanf("%d %d",&q[cnt].l,&q[cnt].r);
		len[i-x+1]+=q[cnt].r-q[cnt].l+1;
		q[cnt].id=i-x+1;
		
		res[i-x+1].set();//������λ��ʼֵ���1���������ֱ��&,�����ʼΪ0��&�껹��0 
	}
	sort(q+1,q+1+cnt);
	l=1,r=0;
	for(int i=1;i<=cnt;i++){
		while(l>q[i].l) add(a[--l]);
		while(r<q[i].r) add(a[++r]);
		//��add��del,����ɾ����cntΪ0��ɵ���ѧ���� 
		while(l<q[i].l) del(a[l++]);
		while(r>q[i].r) del(a[r--]);
		res[q[i].id]&=f; 
	}
	
	for(int i=1;i<=y-x+1;i++) printf("%d\n",len[i]-(int)res[i].count()*3);
} 
int main(){
	scanf("%d %d",&n,&m);
	for(int i=1;i<=n;i++) scanf("%d",&a[i]);
	discrete();
	bsz=sqrt(n);
	for(int i=1;i<=n;i++) belong[i]=i/bsz+1;
	for(int i=1;i<=m;i+=maxt) solve(i,min(i+maxt-1,m)); 
}

