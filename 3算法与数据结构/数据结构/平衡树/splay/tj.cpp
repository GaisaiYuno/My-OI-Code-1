#include<cstdio>
#include<cstring>
#include<algorithm>
#define N 110000
using namespace std;
inline int read(){
    int x=0,f=1;char ch=getchar();
    while(ch<'0'||ch>'9') {if (ch=='-') f=-1;ch=getchar();}
    while(ch<='9'&&ch>='0') x=x*10+ch-'0',ch=getchar();
    return x*f;
}
int n,c[N][2],fa[N],size[N],root,cnt,m;
char s[N],v[N],op[10];
unsigned int hs[N],p[N];
inline void update(int x){
    int l=c[x][0],r=c[x][1];
    size[x]=size[l]+size[r]+1;
    hs[x]=hs[l]*(p[size[r]+1])+p[size[r]]*(v[x]-'a'+1)+hs[r];
}
inline void build(int f,int l,int r){
    if (l>r) return;int mid=l+r>>1;
    c[f][mid>f]=mid;fa[mid]=f;v[mid]=s[mid];hs[mid]=s[mid]-'a'+1;
    if (l==r) {size[l]=1;return;}
    build(mid,l,mid-1);build(mid,mid+1,r);update(mid);
} 
inline void rotate(int x,int &tar){
    int y=fa[x],z=fa[y];
    if (y==tar) tar=x;else c[z][c[z][1]==y]=x;
    int l=c[y][1]==x,r=l^1;
    fa[c[x][r]]=y;fa[y]=x;fa[x]=z;
    c[y][l]=c[x][r];c[x][r]=y;update(y);update(x);
}
inline void splay(int x,int &tar){
    while(x!=tar){
        int y=fa[x],z=fa[y];
        if (y!=tar){
            if (c[y][0]==x^c[z][0]==y) rotate(x,tar);else rotate(y,tar);
        }rotate(x,tar);
    }
}
inline int find(int x,int sz){
    int l=c[x][0],r=c[x][1];
    if (size[l]+1==sz) return x;
    if (sz<=size[l]) return find(l,sz);else return find(r,sz-size[l]-1);
}
inline int split(int x,int y){
    int xx=find(root,x),yy=find(root,y);
    splay(yy,root);splay(xx,c[root][0]);return c[xx][1];
}
inline bool check(int x,int y,int mid){
    int xx=split(x,x+mid+1),tmp=hs[xx];
    int yy=split(y,y+mid+1),tmp1=hs[yy];
    return tmp==tmp1;
}
inline void print(int x){
    if (c[x][0]) print(c[x][0]);
    printf("%c %u\n",v[x],hs[x]);
    if (c[x][1]) print(c[x][1]);
}
int main(){
//    freopen("bzoj1014.in","r",stdin);
    scanf("%s",s+2);n=strlen(s+2);root=n+3>>1;p[0]=1;m=read();cnt=n+2;
    for (int i=1;i<=100100;++i) p[i]=p[i-1]*27;build(0,1,n+2);
    print(root);puts("");
    for (int i=1;i<=m;++i){
        scanf("%s",op);
        if (op[0]=='Q'){
            int x=read(),y=read();int l=1,r=min(cnt-x-1,cnt-y-1);
            while(l<=r){
                int mid=l+r>>1;
                if (check(x,y,mid)) l=mid+1;else r=mid-1;
            } printf("%d\n",r);
        }
        if (op[0]=='R'){
            int x=read();char cc[2];scanf("%s",cc);
            int tmp=split(x,x+2);v[tmp]=cc[0];hs[tmp]=cc[0]-'a'+1;
            update(fa[tmp]);update(root);
        }
        if (op[0]=='I'){
            int x=read()+1;char cc[2];scanf("%s",cc);
            int xx=find(root,x),yy=find(root,x+1);splay(yy,root);splay(xx,c[root][0]);
            v[++cnt]=cc[0];hs[cnt]=cc[0]-'a'+1;size[cnt]=1;fa[cnt]=xx;c[xx][1]=cnt;
            update(xx);update(root);
        } 
    }
    return 0;
}
