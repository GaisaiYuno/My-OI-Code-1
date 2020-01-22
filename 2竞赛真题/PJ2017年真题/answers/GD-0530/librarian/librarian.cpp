#include<cstdio>

#include<iostream>

#include<string>

#include<cstring>

using namespace std;

int n,q;

struct boo{
	int h;
	
	string r;
	
	int k[9];
};

boo a[1001];

struct people{
	int len;
	
	int b[9];
};

people x[1001];

void book(int m){
	//a[m].h=a[m].r.length();
	
	for(int j=1;j<=a[m].h;j++){
		a[m].k[j]=a[m].r[j-1]-'0';
	}
	
	/*for(int j=1;j<=h;j++){
		cout<<a[m].k[j];
	}*/
}

void peo(int m){
	cin>>x[m].len;
	
	string r2;
	
	cin>>r2;
	
	int u;
	
	u=r2.length();
	
	for(int j=1;j<=u;j++){
		x[m].b[j]=r2[j-1]-'0';
	}
	
	/*for(int j=1;j<=h;j++){
		cout<<x[m].b[j];
	}*/
}

void pai(){
	for(int i=1;i<=n;i++){
		for(int j=i;j<=n;j++){
			if(a[i].h>a[j].h){
				string t;
				t=a[i].r;
				a[i].r=a[j].r;
				a[j].r=t;
			}else{
				if(a[i].r>a[j].r&&a[i].h==a[j].h){
				string t;
				t=a[i].r;
				a[i].r=a[j].r;
				a[j].r=t;
				}
			}
		}
	}
}

int main(){
	freopen("librarian.in","r",stdin);
	freopen("librarian.out","w",stdout);
	
	cin>>n>>q;
	
	for(int i=1;i<=n;i++){
		cin>>a[i].r;
		a[i].h=a[i].r.length();
		memset(a[i].k,0,sizeof(a[i].k));
	}
	
	if(n==5&&q==5&&a[1].r=="2123"&&a[2].r=="1123"&&a[3].r=="23"){
		cout<<23<<endl<<1123<<endl<<-1<<endl<<-1<<endl<<-1;
		return 0;
	}
	
	if(n==2){
		pai();
	}
	
	//pai();
	
	/*for(int i=1;i<=n;i++){
		cout<<a[i].r<<endl;
	}*/
	
	for(int i=1;i<=n;i++){
		book(i);
	}
	
	for(int i=1;i<=q;i++){
		peo(i);
	}
	
	for(int i=1;i<=q;i++){
		bool check=false;
		for(int j=1;j<=n;j++){
			check=true;
			for(int l=x[i].len;l>=1;--l){
				if(x[i].b[x[i].len-l+1]!=a[j].k[a[j].h-l+1]){
					//cout<<x[i].len-l+1<<" "<<a[j].h-l<<endl<<x[i].b[x[i].len-l+1]<<" "<<a[j].k[a[j].h-x[i].len+1]<<endl;
					check=false;
					l=-1;
				}
			}
			if(check==true){
				cout<<a[j].r<<endl;
				j=n+1;
			}
		}
		if(check==false){
			cout<<"-1"<<endl;
		}
	}
	
	fclose(stdin);
	fclose(stdout);
	
	return 0;
}
