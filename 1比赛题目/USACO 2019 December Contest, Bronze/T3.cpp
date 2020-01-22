#include<iostream>
#include<cstdio>
#include<cstring> 
#include<map>
#include<algorithm>
#define maxn 100
using namespace std;
int n;
char tp1[maxn+5],tp2[maxn+5];
struct lim{
	int x;
	int y;
}a[maxn+5]; 
string name[9]={"","Bessie","Buttercup","Belinda","Beatrice","Bella","Blue","Betsy","Sue"}; 
map<string,int>id;
int seq[9];
bool check(){
	for(int i=1;i<=n;i++){
		int pos=0;
		for(int j=1;j<=8;j++){
			if(seq[j]==a[i].y){
				pos=j;
				break;
			}
		}
		if(seq[pos-1]==a[i].x||seq[pos+1]==a[i].x) continue;
		else return 0;
	}
	return 1;
}
int main(){
#ifndef LOCAL
	freopen("lineup.in","r",stdin);
	freopen("lineup.out","w",stdout);
#endif 
	sort(name+1,name+1+8);
	for(int i=1;i<=8;i++){
		id[name[i]]=i;
//		cout<<"id: "<<name[i]<<"="<<i<<endl;
	}
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		scanf("%s must be milked beside %s",tp1,tp2);
		a[i].x=id[string(tp1)];
		a[i].y=id[string(tp2)];
//		printf("lim: %d must be milked beside %d\n",a[i].x,a[i].y);
	} 
//	printf("ok\n");
	for(int i=1;i<=8;i++) seq[i]=i;
//	if(check()) printf("ok\n");
	do{
//		printf("ok\n");
		if(check()){
			for(int i=1;i<=8;i++){
				cout<<name[seq[i]]<<endl;
			}
			break;
		}
	}while(next_permutation(seq+1,seq+1+8));
}

