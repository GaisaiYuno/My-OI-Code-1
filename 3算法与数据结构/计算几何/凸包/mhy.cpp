#include <bits/stdc++.h>
#include <cmath>
#define MAXN 1000005
#define eps 1e-6
using namespace std;
struct Point{
    double x,y;
}p[MAXN];
Point p0;
int pos;
inline double operator * (const Point &A,const Point &B){
    return A.x*B.y-A.y*B.x;
}
inline Point operator - (const Point &A,const Point &B){
    return Point{A.x-B.x,A.y-B.y};
}
inline Point operator + (const Point &A,const Point &B){
    return Point{A.x+B.x,A.y+B.y};
}
inline double pf(double x){
    return x*x;
}
inline double dis(const Point &A,const Point &B){
    return sqrt(pf(A.x-B.x)+pf(A.y-B.y));
}
bool flag;
inline bool operator < (const Point &A,const Point &B){
    if (flag){
        if (abs((A-p0)*(B-p0))>eps) return ((A-p0)*(B-p0))>eps;
        else return dis(p0,A)<dis(p0,B);
    }
    else {
        if (A.x!=B.x) return A.x<B.x;
        else return A.y>B.y;
    }
}
Point stk[MAXN];
int top,cnt;
inline void Insert(Point a){
    p[++cnt]=a;
    if (p[pos].y>p[cnt].y||(p[pos].y==p[cnt].y&&p[pos].x>p[cnt].x)) pos=cnt;
}
set<Point>S;
int vis[MAXN],id[MAXN],tot;
Point c[MAXN];
double ans;//现在的答案 
inline void Add(Point a){
    c[++tot]=a;
}
inline void Init(){
    pos=1;
    cnt=0;
    for (register int i=1;i<=tot;++i){
        if (!vis[i]) Insert(c[i]);
    }
    //printf("-----%d\n",cnt);
    p0=p[pos];
    swap(p[1],p[pos]);
    flag=true;
    sort(p+2,p+1+cnt);
    flag=false;
    for (register int i=1;i<=cnt;++i){
        while (top>1&&(stk[top]-stk[top-1])*(p[i]-stk[top-1])<=0) top--;
        stk[++top]=p[i];
    }
    ans=0;
    for (register int i=2;i<top;++i){
        ans+=dis(stk[i],stk[i+1]);
    }
    ans+=dis(stk[top],stk[1]);

    S.clear();
    for (register int i=1;i<=top;++i){
        S.insert(stk[i]);
        //printf("Inserting %f %f\n",stk[i].x,stk[i].y);
    }
}
inline void Print(){
    printf("Set Elements:\n");
    for (set<Point>::iterator it=S.begin();it!=S.end();++it){
        printf("%f %f\n",(*it).x,(*it).y);
    }
    printf("\n");
}
inline void AddCity(Point x){
    //Print();
    //printf("Adding Point %f %f\n",x.x,x.y);
    set<Point>::iterator r=S.lower_bound(x),l=r,t;
    l--;
    if ((*r-*l)*(x-*l)<0) return ;
    //printf("Pre %f %f\n",(*l).x,(*l).y);
    //printf("Nex %f %f\n",(*r).x,(*r).y);
    ans-=dis(*l,*r);
    S.insert(x);
    while (true){//搞掉右边的
        t=r;r++;
        if (r==S.end()) break;
        if ((*r-x)*(*t-x)>0) break;
        ans-=dis(*t,*r);
        //printf("Deleting %f %f %f %f and %f\n",(*t).x,(*t).y,(*r).x,(*r).y,dis(*t,*r));
        S.erase(*t);
    }
    //printf("ans adds %f\n",dis(x,*r));
    while (l!=S.begin()){//搞掉左边的 
        t=l;l--;
        //if () break;
        if ((*t-x)*(*l-x)>0) break;
        ans-=dis(*t,*l);
        //printf("Deleting %f %f and %f\n",(*t).x,(*t).y,dis(*t,*l));
        S.erase(*t);
    }
    //printf("ans adds %f\n",dis(x,*l));
    //printf("then ans becomes %f\n",ans);
    S.insert(x);
    r=S.lower_bound(x),l=r;
    l--,r++;
    ans+=dis(x,*l)+dis(x,*r);
}
double Ans[MAXN];
int n,sx,sy,m;
int main(){
    scanf("%d%d%d",&n,&sx,&sy);
    Add(Point{(double)sx,(double)sy});
    scanf("%d",&m);
    for (register int i=1;i<=m;++i){
        int x,y;
        scanf("%d%d",&x,&y);
        Add(Point{(double)x,(double)y});
    }
    Add(Point{0,0});
    Add(Point{(double)n,0});
    int q;
    scanf("%d",&q);
    for (register int i=1;i<=q;++i){
        int opr;
        scanf("%d",&opr);
        if (opr==1){
            int city;
            scanf("%d",&city);
            vis[city+1]=1;//因为首都编号为1所以+1 
            id[i]=city+1;
        }
        else{
            id[i]=0;
        }
    }

    Init();//建出上凸壳

    for (register int i=q;i>=1;--i){
        if (id[i]) AddCity(c[id[i]]);
        else Ans[i]=ans;
    }
    for (register int i=1;i<=q;++i){
        if (!id[i]){
            printf("%.2f\n",Ans[i]);
        }
    }
}
