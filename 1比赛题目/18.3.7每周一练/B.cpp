#include<iostream>
#include<cstring>
#include<cstdio>
#define MAXN 50005
using namespace std;
int n;
int x[MAXN],y[MAXN],level[MAXN];
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
inline void qwrite(int x){
     if(x<0){
	    putchar('-');
		x=-x;
     }
     if(x>9) qwrite(x/10);
     putchar(x%10+'0');
}
int main(){
	int cnt=0;
    while(cin>>n){
    	memset(level,0,sizeof(level)); 
    	for(int i=1;i<=n;i++){
    		x[i]=qread();
    		y[i]=qread();
    		cnt=0;
    		for(int j=1;j<=i;j++){
    			if(x[j]<=x[i])cnt++;		
			}
			level[cnt]++;
		}
		for(int i=1;i<=n;i++) {
			qwrite(level[i]);
			putchar('\n');
		}
	}	
	return 0;
} 
