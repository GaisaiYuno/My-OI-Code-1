#include<iostream> 
#include<cstdio>
#include<cstring>
#define maxn 205
using namespace std;
int t;
int n;
char a[maxn];
int judge(char x,char y){
	char t1,t2,t3,t4;
	if(x=='a'){
		t1=t2=x+1;
	}else if(x=='z'){
		t1=t2=x-1;
	}else{
		t1=x+1;
		t2=x-1;
	}
	if(y=='a'){
		t3=t4=y+1;
	}else if(y=='z'){
		t3=t4=y-1;
	}else{
		t3=y+1;
		t4=y-1;
	}
	if(t1==t3||t2==t3||t1==t4||t2==t4) return 1;
	else return 0;
} 
int main(){
	scanf("%d",&t);
	for(int i=1;i<=t;i++){
		scanf("%d",&n);
		scanf("%s",a+1);
		bool flag=true;
		for(int i=1;i<=n;i++){
			if(a[i]==a[n-i+1]) continue;
			else{
				if(judge(a[i],a[n-i+1])==0) flag=false;
			}
		}
		if(flag) printf("YES\n");
		else printf("NO\n"); 
	}
} 
