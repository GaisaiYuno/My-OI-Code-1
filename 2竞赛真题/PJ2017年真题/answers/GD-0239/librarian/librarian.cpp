#include <iostream>
#include <cstdio>
#define max_num 100000000
using namespace std;

//Obviously this piece also.

int book[1050],reader[1050],l[1050];

int pow(int base,int p){
	return (p == 0) ? 1 : base * pow(base,p - 1);
}

int main(){
	freopen("librarian.in","r",stdin);
	freopen("librarian.out","w",stdout);
	int n,q;
	cin>>n>>q;
	for(int i = 0;i < n;i++) cin>>book[i];
	for(int i = 0;i < q;i++) cin>>l[i]>>reader[i];
	for(int i = 0;i < q;i++){
		int ans = max_num;
		int have_answer = 0;
		for(int j = 0;j < n;j++){
			if(reader[i] == book[j] % pow(10,l[i])){
				if(book[j] < ans) ans = book[j];
				have_answer = 1;
			} 
		}
		if(have_answer == 1) cout<<ans<<endl;
		else cout<<-1<<endl;
	}
	
	return 0;
}
