//�Ⱥϲ�����
//ö��ÿ�����ÿ���߶Σ����ͳ�ƴ� 
//����˵ö����p���������x,�������ηֱ���x1,y1��һ���߶Σ�������������������ƶ���λ����x1-x~y1-x֮��Ļ�������ǻ�Ϊ�������׵ģ�
//���������൱�ڸ�һ�������x1-x~y1-x��һ�μ���һ����󿴿��ĸ�λ��ֵ�����Ϊ֮ǰ�������Ѿ��ǲ��ص��ˣ����Բ��ص���һ����ᱻ��μ����� 
//��ֺ�,ͳ������λ�ü���
//ע�⴦������ͳһ����1e6 
#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#define maxn 10000
#define maxm 1000
#define maxv 1000000
using namespace std;
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

int n,m;
int a[maxn+5];
struct seg{
	int l;
	int r;
}b[maxm+5];
int cnt=0;
int div1[maxv*2+5];
int div2[maxv*2+5];
int main(){
	n=qread();
	m=qread();
	for(int i=1;i<=n;i++){
		a[i]=qread();
	}
	for(int i=1;i<=m;i++){
		b[i].l=qread();
		b[i].r=qread();
		div1[b[i].l]++;
		div1[b[i].r+1]--;
	}
	for(int i=1;i<=maxv;i++){
		div1[i]+=div1[i-1];
	}
	for(int i=0;i<=maxv;i++){
		if(div1[i]>1) div1[i]=1;
	}
	memset(b,0,sizeof(b));
	if(div1[0]>0) b[++cnt].l=0;
	if(div1[0]>0&&div1[1]==0) b[cnt].r=0;
	for(int i=1;i<=maxv;i++){
		if(div1[i-1]==0&&div1[i]>0) b[++cnt].l=i;
		if(div1[i+1]==0&&div1[i]>0) b[cnt].r=i;
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=cnt;j++){
			div2[b[j].l-a[i]+maxv]++;
			div2[b[j].r-a[i]+maxv+1]--;
		}
	}
	for(int i=1;i<=maxv*2;i++){
		div2[i]+=div2[i-1];
	}
	int d=0,s=0;
	for(int i=0;i<=maxv*2;i++){
		if(div2[i]>s){
			s=div2[i];
			d=abs(i-maxv);
		}else if(div2[i]==s){
			if(abs(i-maxv)<d) d=abs(i-maxv);
		}
	}
	printf("%d %d\n",d,s);
}
