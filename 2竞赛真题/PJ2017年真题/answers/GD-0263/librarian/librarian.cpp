#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;
const int maxn=1000+5;
int n,q;
int Book[maxn];
int Lenth,Number;
bool cmp(const int &a,const int &b){
	return a<b;
}
void Check(int Len,int Num){
	int BOOK;
	int NUM;
	int j;
	for(int i=0;i<n;i++){
		if(Book[i]<Num) continue;
		j=0; BOOK=Book[i]; NUM=Num;
		while(j<Len&&(BOOK%10)==(NUM%10)){
			BOOK=(BOOK-BOOK%10)/10; NUM=(NUM-NUM%10)/10; j++;
		} 
		if(j==Len){
			printf("%d\n",Book[i]); return;
		}
	}
	printf("-1\n");
}
void Solve(){
	memset(Book,0,sizeof(Book));
	scanf("%d%d",&n,&q);
	for(int i=0;i<n;i++) scanf("%d",&Book[i]);
	sort(Book,Book+n,cmp);
	for(int i=0;i<q;i++){
		scanf("%d%d",&Lenth,&Number);
		Check(Lenth,Number);
	}
}
int main(){
	freopen("librarian.in","r",stdin);
	freopen("librarian.out","w",stdout);
	Solve();
	fclose(stdin);
	fclose(stdout);
	return 0;
}
