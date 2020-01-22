#include<iostream>
#include<stack>
#include<cctype>
#include<cstring>
#define maxn 26
using namespace std;
struct matrix{
	int a;
	int b; 
}m[maxn];
int n;
stack<matrix>s;
int main(){
	cin>>n;
	for(int i=0;i<n;i++){
		char name;
		cin>>name;
		int k=name-'A';
		cin>>m[k].a>>m[k].b;
	}
	string expr;
	while(cin>>expr){
		int ans=0;
		while(!s.empty()) s.pop();
		int len=expr.length(); 
		for(int i=0;i<len;i++){
			if('A'<=expr[i]&&expr[i]<='Z') s.push(m[expr[i]-'A']);
			else if(expr[i]==')'){
				matrix m1,m2;
				m2=s.top();
				s.pop();
				m1=s.top();
				s.pop();
				//printf("m1:%d %d     m2:%d %d\n",m1.a,m1.b,m2.a,m2.b);
				if(m1.b!=m2.a){
					ans=-1;
					break;
				}
				ans+=m1.a*m1.b*m2.b;
				matrix m3;
				m3.a=m1.a;
				m3.b=m2.b;
				s.push(m3);
			}
		}
		if(ans==-1) cout<<"error"<<endl;
		else cout<<ans<<endl;
	}
	return 0;
} 
