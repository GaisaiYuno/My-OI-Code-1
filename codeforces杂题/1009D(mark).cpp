//gcd(x,y)=1,1<=x,y<=n�Ķ�����phi(1)+phi(2)+...+phi(n)
//ŷ�����������ܿ죬��n=600ʱ�ͳ���100000
//����ֱ�ӱ���ö�٣���cnt>=mʱbreak
//��Ϊ��������ܿ죬���Բ���TLE 
#include<iostream>
#include<cstdio>
#include<cstring>
#include<vector>
#define maxn 100005
using namespace std;
vector<int>v[maxn];
int n,m;
inline int gcd(int a,int b){
	return b==0?a:gcd(b,a%b);
}
int main(){
	scanf("%d %d",&n,&m);
	int cnt=0;
	for(int i=1;i<=n;i++){
		for(int j=i+1;j<=n;j++){
			if(gcd(i,j)==1){
				v[i].push_back(j);
				cnt++;
			}
			if(cnt>=m) break;
		}
		if(cnt>=m) break;
	}
	if(cnt>=m&&m>=n-1){
		printf("Possible\n");
		for(int i=1;i<=n;i++){
			for(int j=0;j<v[i].size();j++){
				printf("%d %d\n",i,v[i][j]);
			}
		}
	}else{
		printf("Impossible\n");
	}
} 
