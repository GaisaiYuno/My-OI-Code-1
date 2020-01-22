#include<stdio.h>
#include<cstdlib>
#define re register int
using namespace std;
const int Size=200005;
char str[Size];
int main() {
    freopen("data.txt","w",stdout);
    int n=200,m=1e9;
    printf("%d %d\n",n,m);
    for(re i=1; i<=(n>>1); i++) {
        for(re j=1; j<=99997; j++) {
            str[j]='x';
        }
        str[99998]=i/26+'a';
        str[99999]=i%26+'a';
        str[100000]='c';
        puts(str+1);
    }
    for(re i=(n>>1)+1; i<=n; i++) {
        str[1]='d';
        for(re j=2; j<=99998; j++) {
            str[j]='y';
        }
        str[99999]=i/26+'a';
        str[100000]=i%26+'a';
        puts(str+1);
    }
    return 0;
}
