#include<iostream>
#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<ctime>
#include<cmath>
#include<algorithm>
#define maxn 5
#define maxm 10
#define maxv 10
using namespace std;
int n,m;
int sz1,sz2;
int stone[maxn+5];
int other[maxn+5];

inline int random(int n){
	return rand()%n+1;
}
inline int random(int l,int r){
	return l+rand()%(r-l+1);
}

void add(){
	random_shuffle(other+1,other+1+sz2);
	printf("+ %d\n",other[sz2]);
	stone[++sz1]=other[sz2];
	sz2--;
}

void del(){
	random_shuffle(stone+1,stone+1+sz1);
	printf("- %d\n",stone[sz1]);
	other[++sz2]=stone[sz1];
	sz1--;
}
int main(){
	srand(time(NULL));
	n=random(maxn);
	m=random(maxm);
	printf("%d\n",n);
	for(int i=2;i<=n;i++){
		printf("%d %d %d\n",random(i-1),i,random(maxv));
	}
	printf("%d\n",m);
	
	for(int i=1;i<=n;i++){
		other[++sz2]=i;
	}
	for(int i=1;i<=m;i++){
		if(sz1>0&&sz2>0){
			int cmd=random(1,3);
			if(cmd==1){
				printf("?\n");
			}else if(cmd==2){
				add();
			}else{
				del();
			}
		}else if(sz2>0){
			int cmd=random(1,2);
			if(cmd==1){
				printf("?\n");
			}else{
				add();
			}
		}else if(sz1>0){
			int cmd=random(1,2);
			if(cmd==2) cmd=3;
			if(cmd==1){
				printf("?\n");
			}else{
				del();
			}
		}
	}
}
