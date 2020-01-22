#include<bits/stdc++.h>
using namespace std;
long long n,q,i,j,x,k1=1,k2=1,tot,s[1001],l1,s1[1001],str[1001],p,ans[1001],h=1;
char a[10000001],b[10000001];
bool flag=false;
int main(){
	freopen("librarian.in","r",stdin);
	freopen("librarian.out","w",stdout);
    cin>>n>>q;
	for(j=1;j<=n;j++){
	cin>>a;
	getchar();
	l1=strlen(a);
	str[j]=l1;
	for(i=1;i<=l1;i++){
	s[j]*=10;
	s[j]+=a[i-1]-'0';
	}
	} 
	for(i=1;i<=q;i++){
	cin>>x>>b;
	tot=0;
	k1=1;
	k2=1;
	flag=false;
	for(i=1;i<=x;i++){
		tot*=10;
		tot+=b[i-1]-'0';
		k1*=10;
		}
		for(p=1;p<=n;p++){
			if((s[p]-tot)%k1==0&&str[p]>=x&&s[p]-tot>=0){
				flag=true;
				s1[k2]=s[p];
				k2++;
			}	
		}	
		if(flag!=true){
		 ans[h]=-1;
		 h++;	
		}
		else{
			k2--;
			sort(s1+1,s1+k2+1);
			ans[h]=s1[1];
			h++;
		}
		if(h-1==q) break;
	}
	for(i=1;i<=h-1;i++){
		cout<<ans[i];
		if(i!=h-1) cout<<endl;
	}  
}
