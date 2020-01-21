#include<iostream>
#include<cstdio>
#include<cstring>
#include<fstream>
#define maxn 100005
using namespace std;
long long n,k,sum;
long long e[maxn],dp[maxn]; 
inline long long fread() {
	long long x=0,sign=1;
	char c=getchar();
	while(c<'0'||c>'9') {
		if(c=='-') sign=-1;
		c=getchar();
	}
	while(c>='0'&&c<='9') {
		x=x*10+c-'0';
		c=getchar();
	}
	return x*sign;
}
int head=0;
int tail=0;
struct node{
	long long value;
	long long index;
}q[maxn];
void push(int v,int i) {
	while(v<q[tail-1].value&&head<tail) tail--;
	q[tail].value=v;
	q[tail].index=i;
	tail++;
}
void pop(int i){
	while(i-q[head].index>=k&&head<tail)head++;
}
void debug(){
	for(int i=head;i<tail;i++) cout<<q[i].value<<' ';
	cout<<endl;
}
int main(){
	//ifstream fin,fans;
	//fin.open("mowlawn.7.in");
	//fans.open("mowlawn.7.ans");
	//fin>>n>>k;
	cin>>n>>k;
	sum=0;
	for(int i=1;i<=n;i++){
	    //fin>>e[i];
	    e[i]=fread();
	    sum+=e[i];
	} 
    //memset(dp,0x7f,sizeof(dp));
    for(int i=1;i<=k;i++){
    	push(e[i],i);
	}
	for(int i=k+1;i<=n;i++){
		//debug();
		push(dp[i-1]+e[i],i);
		dp[i]=q[head].value;
		pop(i);
	}
	cout<<sum-dp[n]<<endl;
	/*long long d;
	fans>>d;
	if(d==sum-dp[n]){
		cout<<"AC!";
		cout<<"read "<<sum-dp[n]<<' '<<"expected "<<d;
	}
	else{
		cout<<"WA!\n";
		cout<<"read "<<sum-dp[n]<<' '<<"expected "<<d;
	}*/
}
//f[i]=min(f[i],f[j-1]+e[j]) jÊôÓÚ 

