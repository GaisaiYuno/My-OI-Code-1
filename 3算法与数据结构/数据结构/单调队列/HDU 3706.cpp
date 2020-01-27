#include<iostream>
#define maxn 10000005  
using namespace std;
struct node{
	int ans;
	int id;
}q[maxn];
long long n,a,b;
int head,tail;
int main(){
	long long s,ans;
	while(cin>>n>>a>>b){
		head=1,tail=1;
		ans=s=1;
		for(int i=1;i<=n;i++)  
        {  
            s=(s*a)%b;  
            while(head<=tail&&q[tail-1].ans>s) tail--;  
            q[tail].id=i;
            q[tail].ans=s; 
            tail++;
            while(i-q[head].id>a) head++; //元素个数大于a个，出队  
            ans*=q[head].ans;                 
            ans%=b;  
        }  
        cout<<ans<<endl; 
	}
}
