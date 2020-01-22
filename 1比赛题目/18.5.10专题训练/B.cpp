#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
#define maxn 2005
using namespace std;
const double eps=1e-7;
int dcmp(double x){
	if(abs(x)<eps) return 0;
	else return x<0?-1:1;
}
struct point{
	double x;
	double y;
	typedef point vector;
	point(){}
	point(int xx,int yy){
		x=xx;
		y=yy;
	}
    friend vector operator +(vector a,vector b){
    	return vector(a.x+b.x,a.y+b.y);
	} 
	friend vector operator -(vector a,vector b){
    	return vector(a.x-b.x,a.y-b.y);
	} 
	friend bool operator ==(vector a,vector b){
		return dcmp(a.x-b.x)==0&&dcmp(a.y-b.y)==0;
	}
};
typedef point vector;
double cross(vector a,vector b){
	return a.x*b.y-a.y*b.x;
}

bool seg_inter(point a1,point a2,point b1,point b2){
	double c1=cross(a2-a1,b1-a1);
	double c2=cross(a2-a1,b2-a1);
	double c3=cross(b2-b1,a1-b1);
	double c4=cross(b2-b1,a2-b1);
	return dcmp(c1)*dcmp(c2)<0&&dcmp(c3)*dcmp(c4)<0;
} 

struct union_find_set{
	int fa[maxn],num[maxn];
	void ini(int n){
		for(int i=1;i<=n;i++) fa[i]=num[i]=i;
	}
	int find(int x){
		if(fa[x]!=x){
			fa[x]=find(fa[x]);
			return fa[x];
		}else return x;
	}
	void union_set(int x,int y){
		int fx=find(x);
		int fy=find(y);
		if(fx!=fy){
			fa[fx]=fy;
			num[fy]+=num[fx];
			num[fx]=0;
		} 
	}
}; 
union_find_set S;
int t,n;
point dot[maxn*2];
int main(){
	scanf("%d",&t);
	char cmd;
	while(t--){
		scanf("%d",&n);
		S.ini(n);
		int size=0;
		for(int i=1;i<=n;i++){
			scanf("%c",&cmd);
			if(cmd=='P'){
				point a,b;
				scanf("%lf %lf %lf %lf",&a.x,&a.y,&b.x,&b.y);
				dot[++size]=a;
				dot[++size]=b;
				for(int j=1;j<size-1;j+=2){
					if(seg_inter(dot[j],dot[j+1],a,b)){
						union_set(j/2+1,size/2);
					}
				}
			}else{
				
			}
		} 
	}
}


