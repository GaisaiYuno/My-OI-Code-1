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
	return a>b;
}
int main(){
	/* ���=����*Ҫ�еĴ�����
	   Ҫ�еĴ���Խ��Խ���������ڴ�������ʱ��ѡ���۽ϴ�� 
	*/ 
	cin>>n>>m;
    int p=0,q=0;
    for(int i=0;i<n-1;i++) cin>>h[i];
    for(int j=0;j<m-1;j++) cin>>s[j];
    sort(h,h+n-1,cmp);
    sort(s,s+n-1,cmp);
    while(p<n-1&&q<m-1){
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

     while(q<m-1) {
     	 ans=s[q]*as+ans;
     	 q++;
	 }
	  
     while(p<n-1) {
     	ans=h[p]*ah+ans;
     	p++;
	 }
    cout<<ans;
    return 0; 

}

