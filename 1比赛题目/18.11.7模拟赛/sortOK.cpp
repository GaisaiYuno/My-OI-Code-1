//LOJ 2181
//�ȶ���Сһ�������������ϣ�ֱ����ɡ�
//������β���������ÿһ�㣨����Ϊ2^x���������ҳ�ÿ���Ƿ��ź���������ǣ�num++,
//����ÿһ�㣬���num>2��Ȼ�޽⣬��Ϊ��һ���Ѿ��źã�����ֳ����Σ�����������������ԣ�����ö��
//����ֲ���˳���޹أ���Ȼ��,ÿ�μ��ϲ������Ľ׳�
#include<iostream>
#include<cstdio>
#include<cstring>
#define maxn 5005
using namespace std;
int n;
long long ans=0;
int a[maxn];
int pow2[20];
long long fact[20];
void init(){
	pow2[0]=1;
	for(int i=1;i<=n;i++){
		pow2[i]=pow2[i-1]<<1;
	}
	fact[0]=1;
	for(int i=1;i<=n;i++){
		fact[i]=fact[i-1]*i;
	}
}
int check(int x,int k){//�ж��Ƿ���� 
	for(int i=1;i<pow2[k];i++){
		if(a[x+i]!=a[x+i-1]+1) return 0;
	}
	return 1;
}

void change(int x,int y,int t){
	for(int i=0;i<pow2[t];i++){
		swap(a[x+i],a[y+i]); 
	} 
}

void dfs(int x,int k){//x��������x�㳤��2^x����k�������� 
	if(x==n+1){
		ans+=fact[k];
		return;
	}
	int seq1=0,seq2=0;
	for(int i=1;i<=pow2[n];i+=pow2[x]){
		if(check(i,x)==0){
			if(seq1==0) seq1=i;
			else if(seq2==0) seq2=i;
			else return; //����ò�ǵ����Ķγ���2������Ȼ�޽� 
		} 
	}
	if(seq1==0&&seq2==0) dfs(x+1,k);
	else if(seq2==0){//���öε����ߺ��Ұ�߽��� 
		change(seq1,seq1+pow2[x-1],x-1);
		dfs(x+1,k+1);
		change(seq1,seq1+pow2[x-1],x-1);
	}else{
		//2�����Ϸ��ĶΣ�ÿ�������ߣ��ɻ��ཻ������2*2�ַ��� 
		for(int i=0;i<=1;i++){
			for(int j=0;j<=1;j++){
				change(seq1+i*pow2[x-1],seq2+j*pow2[x-1],x-1);
				if(check(seq1,x)&&check(seq2,x)){
					dfs(x+1,k+1);
					change(seq1+i*pow2[x-1],seq2+j*pow2[x-1],x-1);
					break;      
				}
				change(seq1+i*pow2[x-1],seq2+j*pow2[x-1],x-1);
			}
		} 
	} 
}
int main(){
	scanf("%d",&n);
	init();
	for(int i=1;i<=(1<<n);i++){
		scanf("%d",&a[i]);
	}
	dfs(0,0);
	printf("%lld\n",ans);
}
