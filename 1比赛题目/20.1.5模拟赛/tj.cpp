#include<cstdio>
#include<cstring>
const int N=26,M=105,P=10000;
int n,m,F,i,j,len[N],nxt[M],f[N][M],g[N][M],v[N][M];char s[M],a[N][M];
inline void up(int&x,int y){x+=y;if(x>=P)x-=P;}
void dp(int x,int y){
  if(v[x][y])return;
  int i,j;
  for(i=0,j=y;i<len[x];i++)if(a[x][i]>='a'){
    while(j&&s[j+1]!=a[x][i])j=nxt[j];
    if(s[j+1]==a[x][i])j++;
    if(j==m)up(f[x][y],1),j=nxt[j];
  }else{
    int k=a[x][i]-'A';
    dp(k,j),up(f[x][y],f[k][j]),j=g[k][j];
  }
  v[x][y]=1,g[x][y]=j;
}
int main(){
  scanf("%d%s",&n,s),F=s[0]-'A';
  while(n--){
    scanf("%s",s),m=strlen(s);
    len[i=s[0]-'A']=m-2;
    for(j=2;j<m;j++)a[i][j-2]=s[j];
  }
  scanf("%s",s+1),m=strlen(s+1);
  for(i=2;i<=m;nxt[i++]=j){
    while(j&&s[j+1]!=s[i])j=nxt[j];
    if(s[j+1]==s[i])j++;
  }
  dp(F,0);
  return printf("%d",f[F][0]),0;
}
