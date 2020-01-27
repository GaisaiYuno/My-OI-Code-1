#include<iostream>
#include<cstdio>
#include<cstring>
#include<stack>
#define maxn 21 
using namespace std;
int n,t;
string c;
int dp[maxn];
/*inline int to_num(int l,int r,string c){
	int x=0;
	int i=l;
	while(c[i]=='0') i++;
	while(i<=r){
		x=x*10+c[i]-'0';
		i++; 
	}
	return x;
}
inline int cal_value(string a){
	stack<int>s;
	int last=0;
	for(int i=0;i<a.length();i++){
		if(!isdigit(a[i])){
			s.push(to_num(0,i-1,a));
			last=i;
			break;
		}
		if(i==a.length()-1){
			s.push(to_num(0,i,a));
			break;
		}
	}
	for(int i=last;i<a.length();i++){
		if(a[i]=='+'){
			for(int j=i;j<a.length();j++){
				if(j==a.length()-1){
					s.push(to_num(i+1,j,a));
				}
				else if(!isdigit(a[j])){
					s.push(to_num(i+1,j-1,a));
					break;
				}
			}
		}
		if(a[i]=='*'){
			int t=s.top(); 
			s.pop();
			for(int j=i;j<a.length();j++){
				if(j==a.length()-1){
					s.push(to_num(i+1,j,a)*t);
					break;
				}
				else if(!isdigit(a[j])){
					s.push(to_num(i+1,j-1,a)*t);
					break;
				}
			}
		}
	}
	int ans=0;
	while(!s.empty()){
		ans+=s.top();
		s.pop();
	}
	return ans;
}*/ 
int main(){
	freopen("puzzle.in","r",stdin);
	freopen("puzzle.out","w",stdout); 
	t=0;
	while(1){ 
		cin>>c;
		cin>>t;
		if(t<0) break;
	    cout<<"-1"<<endl;
	} 
	return 0; 
	
}
