#include<cstdio>
#include<cstring>
#include<memory.h>
#include<cstdlib>
#define MAXNUM 1000+1 
typedef char Str[8];
using namespace std;
struct Strstr{
	int len;
	Str a;
	int num;
};
inline int read(){
	int x=0;char c=getchar();
	while(c<'0'||c>'9') c=getchar();
	while(c>='0'&&c<='9') x=x*10+c-'0',c=getchar();
	return x;
}
inline void print(int x){
	if(x<0){
		putchar('-');
		x=-x;
	}
	if(x>9) print(x/10);
	putchar(x%10+'0');
}
inline Strstr strread(){
	int x=read(); Str a;
	gets(a);
	Strstr p;
	p.len=x;
	strcpy(p.a,a);
	int num=atoi(a);
	return p;
}
inline void strprint(Strstr a){
	print(a.len);
	putchar(' ');
	print(a.num);
	putchar(' ');
	puts(a.a);
}
void quicksort(Strstr a[],int l,int r){
	if(l>=r) return;
	int i=l,j=r;
	Strstr k=a[(l+r)/2];
	while(i<j){
		while(a[i].num<k.num) i++;
		while(a[j].num>k.num) j--;
		if(i<=j){
			Strstr tmp=a[i];
			a[i]=a[j];
			a[j]=tmp;
			i++;j--;
		}
	}
	if(l<j) quicksort(a,l,j);
	if(r>i) quicksort(a,i,r);
}
int main(){
	int n,q,tmp;
	Strstr books[MAXNUM];
	Strstr readers[MAXNUM];
	freopen("librarian.in","r",stdin);
	freopen("librarian.out","w",stdout);
	n=read();q=read();
	for(int i=1;i<=n;i++) gets(books[i].a),books[i].len=strlen(books[i].a),books[i].num=atoi(books[i].a);
	for(int i=1;i<=q;i++) readers[i]=strread();
	quicksort(books,1,n);
	for(int i=1;i<=q;i++){
		int l=-1;
		for(int k=1;k<=n;k++){
			bool flag=1;
			for(int j=0;j<=readers[i].len;j++)
				if(books[k].a[books[k].len-j]!=readers[i].a[readers[i].len-j]){
					flag=0;
					break;
				}
			if(flag){
				l=books[k].num;
				break;
			}
		}
		print(l);
		putchar('\n');
	}
	fclose(stdin);
	fclose(stdout);
}
