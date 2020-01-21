#include<iostream>
#include<cstdio>
#include<cmath>
#include<utility>
#include<cstdlib>
#include<ctime>
#define MAXN 1000
#define MAXT 4000//温度 
#define EPS 1e-15//误差 
#define DELTA 0.998//降温速率 
#define TIMES 6//退火次数 
using namespace std;
struct item{
    double x;
    double y;
    double m;
}a[MAXN+5];
int n;
inline double dist(double x1,double y1,double x2,double y2){
    return sqrt((x1-x2)*(x1-x2)+(y1-y2)*(y1-y2));
}
double check(double newx,double newy){
    double ans=0;
    for(int i=1;i<=n;i++){
        ans+=dist(a[i].x,a[i].y,newx,newy)*a[i].m;
    }
    return ans;
} 

double ansx,ansy,answ;
void SA(){
    double t=MAXT;
    while(t>EPS){
        double tx=ansx+(rand()*2-RAND_MAX)*t; 
        double ty=ansy+(rand()*2-RAND_MAX)*t; //变化值大小与t成正比
        double tw=check(tx,ty);
        double de=tw-answ;
        if(de<0){
            ansx=tx;
            ansy=ty;
            answ=tw;
        }else if(exp(-de/t)*RAND_MAX>rand()){
            ansx=tx;
            ansy=ty;
            //只是跳到另一个地方继续找最小值，跳过去的地方不是最小值，不更新ans 
        }
        t*=DELTA; 
    }
} 

int main(){
	srand(rand());
    scanf("%d",&n);
    for(int i=1;i<=n;i++){
        scanf("%lf %lf %lf",&a[i].x,&a[i].y,&a[i].m);
        ansx+=a[i].x;
        ansy+=a[i].y;
    }
    ansx/=n;
    ansy/=n;//平均数为初始解
    answ=check(ansx,ansy);
    for(int i=1;i<=TIMES;i++){
        SA(); 
    } 
    printf("%.3f %.3f\n",ansx,ansy);
}

