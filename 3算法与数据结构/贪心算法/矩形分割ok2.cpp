//��� ���ηָ� 
#include<iostream>
#include<algorithm>
#define max 2004
using namespace std;
int n,m;
int ah=1,as=1;
int h[max],s[max];
long long ans=0;
bool cmp(int a,int b){
	return a>=b;
}
int main(){
	/* ���=����*Ҫ�еĴ�����
	   Ҫ�еĴ���Խ��Խ���������ڴ�������ʱ��ѡ���۽ϴ�� 
	*/ 
	cin>>n>>m;
    int p=1,q=1;
    for(int i=1;i<n;i++) cin>>h[i];
    for(int j=1;j<m;j++) cin>>s[j];
    sort(h+1,h+n,cmp);
    sort(s+1,s+m,cmp);
    while(p<n&&q<m){
        if(h[p]<s[q]){
            ans=s[q]*as+ans;
            q++;
            ah++;//�����еĴ������� 
        } 
        else if(h[p]>s[q]){
            ans=h[p]*ah+ans; 
            p++;
            as++;//�����еĴ������� 
        }
        else{ 
			if(as<ah){
			  ans=s[q]*as+ans;
			  q++;
			  ah++;
			}
			else{
			 ans=h[p]*ah+ans; 
    		p++;
    		as++;
            }
        } 
    }

     while(q<m) {
     	 ans=s[q]*as+ans;
     	 q++;
	 }
	  
     while(p<n) {
     	ans=h[p]*ah+ans;
     	p++;
	 }
    cout<<ans;
    return 0; 

}

