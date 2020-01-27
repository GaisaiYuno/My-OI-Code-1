//������ÿ����Ϊ������˵Ĵ𰸣��Լ������Ҷ˵Ĵ𰸣����õ���ջO(n)
//Ԥ����ǰ׺��
//Ȼ�����ǿ���һ��ѯ�ʣ��������ǵõ�[l,r]�е����ֵλ��maxp
//��ô���ǵĴ𰸣��൱����ѯ������[l,maxp-1]�����е���Ϊ��˵Ĵ���[mp+1,r]�����е���Ϊ�Ҷ˵�Ĵ� 
#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath> 
#include<stack>
#define maxn 300005
using namespace std;
int n,m,t;
inline int qread(){
	int x=0,sign=1;
	char c=getchar();
	while(c<'0'||c>'9'){
		if(c=='-') sign=-1;
		c=getchar();
	} 
	while(c>='0'&&c<='9'){
		x=x*10+c-'0';
		c=getchar(); 
	}
	return x*sign;
}
inline void qprint(long long x){
	if(x==0){
		putchar('0');
		return;
	}else{
		if(x/10>0) qprint(x/10);
		putchar(x%10+'0');
	}	
}

int a[maxn];
int pow2[maxn];
int Log2[maxn];
int st[maxn][32];
void st_init(){//st��ͳ���������ֵ��λ�� 
	pow2[0]=1;
	for(int i=1;i<=20;i++){
		pow2[i]=pow2[i-1]*2;
	}
	int j=0;
	Log2[0]=-1;
	for(int i=1;i<=n;i++){
		if(i==pow2[j]){
			Log2[i]=Log2[i-1]+1;
			j++;
		}else Log2[i]=Log2[i-1];
	}
	
	memset(st,0,sizeof(st));
	for(int i=1;i<=n;i++) st[i][0]=i;
	for(int j=1;(1<<j)<=n;j++){
		for(int i=1;i+(1<<(j-1))<=n;i++){
			if(a[st[i][j-1]]>=a[st[i+(1<<(j-1))][j-1]]) st[i][j]=st[i][j-1];
			else st[i][j]=st[i+(1<<(j-1))][j-1];
		}
	}
}

int st_query(int l,int r){
	int k=Log2[r-l+1]; 
	if(a[st[l][k]]>a[st[r-(1<<k)+1][k]]) return st[l][k];
	else return st[r-(1<<k)+1][k];
}

stack<int>s;
long long ansl[maxn],ansr[maxn];
void monotonic_stack(){//����ջ��anslΪi��Ϊ��˵�ĸ�����ansrΪi��Ϊ�Ҷ˵�ĸ��� 
	s.push(a[n]);
	for(int i=n-1;i>=1;i--){//����ѭ�� 
		while(!s.empty()&&s.top()<a[i]){//��ʱs[top]��i�ұ���<i����i��s[top]��λ���Ƿ������������䣬ansl[i]++ 
			ansl[i]++;
			s.pop();
		}
		if(!s.empty()) ansl[i]++;
		while(!s.empty()&&s.top()<=a[i]) s.pop();
		s.push(a[i]);
	}
	while(!s.empty()) s.pop();
	s.push(a[1]);
	for(int i=2;i<=n;i++){
		while(!s.empty()&&s.top()<a[i]){
			ansr[i]++;
			s.pop();
		}
		if(!s.empty()) ansr[i]++;
		while(!s.empty()&&s.top()<=a[i]) s.pop();
		s.push(a[i]);
	}
}

long long query(int l,int r){
	int maxp=st_query(l,r); //��Ȼ��Բ������������ֵ 
//	printf("debug:%d\n",maxp);
	return ansl[maxp-1]-ansl[l-1]+ansr[r]-ansr[(maxp+1)-1];
	         //��˵���[l,maxp-1]        //�Ҷ˵���[maxp+1,r] 
}
int main(){
//	freopen("2.in","r",stdin);
//	freopen("tmp2.out","w",stdout);
	int l,r,u,v; 
	n=qread();
	m=qread();
	t=qread();
	for(int i=1;i<=n;i++) a[i]=qread();
	st_init();
	monotonic_stack();
	for(int i=1;i<=n;i++){
		ansl[i]+=ansl[i-1];
		ansr[i]+=ansr[i-1];
//		printf("%d %d\n",ansl[i],ansr[i]);
	}
	long long last=0;
	for(int i=1;i<=m;i++){
		l=qread();
		r=qread();
		if(t==0){
			u=l;
			v=r;
		}else{
			u=(l+last-1)%n+1;
			v=(r+last-1)%n+1;
			if(u>v) swap(u,v); 
		}
//		printf("[%d,%d]->[%d,%d]\n",l,r,u,v);
		last=query(min(u,v),max(u,v));
		qprint(last);
		putchar('\n');
	} 
}
