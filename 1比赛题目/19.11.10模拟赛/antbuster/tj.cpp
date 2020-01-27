#include<stdio.h>
#include<cstring>
#include<algorithm>
#include<math.h>
//#include<conio.h>
#include<cstdio>
#define re register int
#define rl register ll
#define eps 1e-12
using namespace std;
typedef long long ll;
int read() {
	re x=0,f=1;
	char ch=getchar();
	while(ch<'0' || ch>'9') {
		if(ch=='-')	f=-1;
		ch=getchar();
	}
	while(ch>='0' && ch<='9') {
		x=10*x+ch-'0';
		ch=getchar();
	}
	return x*f;
}
namespace Solution {

const int Size=45;
double pw[200005];
int n,m;		//地图长宽 
ll s,d,r;		//炮塔的个数，伤害和攻击范围 
int t;			//总时间 

int info[Size][Size];	//信息素 
int hasant[Size][Size];	//有无蚂蚁，若有，记录编号 
bool hastow[Size][Size];		//有无防御塔 

struct tower {
	int x,y;	//炮塔位置 
} tank[Size];	//gcd的tank 

int antnum;		//蚂蚁数量 
int allnum;		//从第1s到现在的蚂蚁总数 
int cakeant;	//拿走蛋糕的蚂蚁编号（若没有被拿走，则为0） 
struct student {	//gcd的tank压学生 
	int x,y;	//位置 
	ll hp,lv;	//血量，等级level 
	int age;	//年龄 
	int prex,prey;		//前一秒所在位置 
	inline void clear() {
		x=y=hp=lv=age=0;
		prex=prey=-1;
	}
} ant[Size];
const int dx[] = {0,1,0,-1};	//先面向正东，顺时针旋转 
const int dy[] = {1,0,-1,0};

inline bool check(int x,int y) {
	//判断(x,y)这个点能不能去 
	if(x<0 || y<0 || x>n || y>m)	return false;
	if(hasant[x][y] || hastow[x][y])	return false;
	return true;
}
inline double dist(double x1,double y1,double x2,double y2) {
	return (x2-x1)*(x2-x1)+(y2-y1)*(y2-y1);
}
void ReadData() {
	n=read();
	m=read();
	s=read();
	d=read();
	r=read();
	for(re i=1; i<=s; i++) {
		tank[i].x=read();
		tank[i].y=read();
		hastow[tank[i].x][tank[i].y]=true;
	}
	t=read();
}
void Init() {
	//初始化1.1^i 
	pw[0]=1;
	for(re i=1; i<=100000; i++) {
		pw[i]=pw[i-1]*1.1;
		if(pw[i]>(ll)d*t)	pw[i]=(ll)d*t+1;
	}
}
bool GameFail=false;	//游戏失败的标记 
void AddAnt() {
	++antnum;
	++allnum;
	ant[antnum].clear();
	ant[antnum].x=0;
	ant[antnum].y=0;
	ant[antnum].lv=(allnum-1)/6+1;	//前6只是1，第7只是2，第13只是3...... 
	ant[antnum].hp=int(4.0*pw[ant[antnum].lv]);
	ant[antnum].age=0;
	hasant[0][0]=antnum;
}
void AddInfo() {		//增加信息素 
	for(re i=1; i<=antnum; i++) {
		if(i==cakeant) {
			info[ant[i].x][ant[i].y]+=5;
		} else {
			info[ant[i].x][ant[i].y]+=2;
		}
	}
}
void RefreshAnt() {		//刷新蚂蚁尸体 
	for(re i=1; i<=antnum; i++) {
		if(ant[i].hp<0) {
			if(i==cakeant)	cakeant=0;
			hasant[ant[i].x][ant[i].y]=0;
			ant[i].clear();
			for(re j=i; j<antnum; j++) {
				swap(ant[j],ant[j+1]);
			}
			antnum--;
			if(cakeant>i)	cakeant--;
			i--;
		}
	}
}
void EndSecond() {		//结束这一秒 
	//最后，地图上所有点的信息素损失1单位。
	for(re i=0; i<=n; i++) {
		for(re j=0; j<=m; j++) {
			if(info[i][j]) {
				info[i][j]--;
			}
		}
	}
	//所有蚂蚁的年龄加1。漫长的1秒到此结束。
	for(re i=1; i<=antnum; i++) {
		ant[i].age++;
	}
}
inline void UpdateAnt(int id,int dir) {
	ant[id].x+=dx[dir];
	ant[id].y+=dy[dir];
}
void GetTarget(int *target) {
	memset(target,0,(s+1)<<2);
	for(re i=1; i<=s; i++) {	//遍历炮塔，求target 
		if(cakeant && dist(ant[cakeant].x,ant[cakeant].y,tank[i].x,tank[i].y)<=r*r) {
			target[i]=cakeant;
		} else {
			int mind=1e8,antid=0;
			for(re j=1; j<=antnum; j++) {
				int nowd=dist(ant[j].x,ant[j].y,tank[i].x,tank[i].y);
				if(nowd<mind) {
					mind=nowd;
					antid=j;
				}
			}
			if(mind<=r*r) {
				target[i]=antid;
			}
		}
	}
}
bool OnLine(double x1,double y1,double x2,double y2,int id) {
	/*
	   O(ant[id].x,ant[id].y)
	 	.-----/ B(Bx,By)
	 	|    /
	 	|   / H(Hx,Hy)
	 	|  /
	 	| /
	 	|/
	 	A(Ax,Ay)
	*/
	//y=kx+b 
	double k=1.0*(y2-y1)/(x2-x1);
	double Ox=ant[id].x,Oy=ant[id].y;
	double Ax=ant[id].x,Ay=y1+(ant[id].x-x1)*k;
	double b=Ay-k*Ax;
	//k*Ax+b=Ay => b=Ay-k*Ax
	//保证k!=0 && k!=inf 
	double OH_k=-1.0/k;		//垂线的斜率 
	//OH_k*Ox+OH_b=Oy => OH_b=Oy-OH_k*Ox 
	double OH_b=Oy-OH_k*Ox;
	//kx+b=OH_kx+OH_b
	//(k-OH_k)x=OH_b-b
	double Hx=(OH_b-b)/(k-OH_k);
	double Hy=OH_k*Hx+OH_b;
	if(Hx>=x1 && Hx<=x2 && sqrt(dist(Hx,Hy,Ox,Oy))<=0.5) {
		return true;
	}
	return false;
}
void EqualX_Shoot(int x1,int y1,int x2,int y2) {	//x1==x2
	int sy=min(y1,y2),dy=max(y1,y2);
	for(re j=1; j<=antnum; j++) {
		if(ant[j].x==x1 && ant[j].y>=sy && ant[j].y<=dy) {
			ant[j].hp-=d;
		}
	}
}
void EqualY_Shoot(int x1,int y1,int x2,int y2) {	//y1==y2
	int sx=min(x1,x2),tx=max(x1,x2);
	for(re j=1; j<=antnum; j++) {
		if(ant[j].y==y1 && ant[j].x>=sx && ant[j].x<=tx) {
			ant[j].hp-=d;
		}
	}
}
void Xuming(int nowtime) {	//第i秒，把这一秒献给长者 
	//1秒的最初，如果地图上蚂蚁数不足6，一只蚂蚁就会在洞口出生 
	if(antnum<6 && !hasant[0][0]) {
		AddAnt();
	}
	//蚂蚁们在自己所在点留下一些信息素 
	AddInfo();
	//考虑移动。先出生的蚂蚁先移动。
	for(re i=1; i<=antnum; i++) {
		//找出信息素最多的点 
		int top=0,tot=0,stk[5],can[5];
		memset(stk,0,sizeof(stk));
		memset(can,0,sizeof(can));
		int maxi=-1,pos=-1;
		for(re j=0; j<4; j++) {
			int nx=ant[i].x+dx[j];
			int ny=ant[i].y+dy[j];
			if(check(nx,ny) && (nx!=ant[i].prex || ny!=ant[i].prey)) {
				can[++tot]=j;
				if(info[nx][ny]>maxi) {
					maxi=info[nx][ny];
					stk[top=1]=j;
					pos=tot;
				} else if(info[nx][ny]==maxi) {
					stk[++top]=j;
				}
			}
		}
		//若没有或只有一个可去的点，则活动时间是5的倍数也不会结果有影响 
		ant[i].prex=ant[i].x;
		ant[i].prey=ant[i].y;
		if(top==0) {
			continue;
		} else if(tot==1 || ant[i].age%5!=4) {
			//age一开始是0，活动时间一开始是1 
			//如果age%5==4，则活动时间%5==0，方向才会顺时针旋转 
			UpdateAnt(i,stk[1]);
		} else {
			//逆时针旋转 
			int zyd=pos-1;
			if(!zyd)	zyd=tot;
			UpdateAnt(i,can[zyd]);
		}
		hasant[ant[i].prex][ant[i].prey]=0;
		hasant[ant[i].x][ant[i].y]=i;
	}
	//移动完毕后，如果有蚂蚁在蛋糕的位置上并且蛋糕没被拿走，
	//它把蛋糕扛上，血量增加，并在这时被所有能打到它的塔设成target。
	if(!cakeant) {
		for(re i=1; i<=antnum; i++) {
			if(ant[i].x==n && ant[i].y==m) {
				cakeant=i;
				ant[i].hp+=((int)floor(4.0*pw[ant[i].lv]))>>1;	//出生时血量的一半 
				ant[i].hp=min(ant[i].hp,(ll)floor(4.0*pw[ant[i].lv]));
				break;
			}
		}
	}
//	if(nowtime==158) {
//		cakeant=cakeant;
//	}
	int target[Size];
	GetTarget(target);
	//然后所有塔同时开始攻击。如果攻击结束后那只扛着蛋糕的蚂蚁挂了，蛋糕瞬间归位。
	for(re i=1; i<=s; i++) {	//遍历炮塔，开始攻击 
		//在塔和目标蚂蚁之间连一条线，判断有没有蚂蚁在线上 
		if(!target[i])	continue;
		int x1=tank[i].x,y1=tank[i].y;
		int x2=ant[target[i]].x,y2=ant[target[i]].y;
		if(tank[i].x>ant[target[i]].x) {
			swap(x1,x2);
			swap(y1,y2);
		}
		if(x1==x2) {
			EqualX_Shoot(x1,y1,x2,y2);
//			printf("attack!");
		} else if(y1==y2) {
			EqualY_Shoot(x1,y1,x2,y2);
//			printf("attack!");
		} else {
			//.....................................................
			for(re j=1; j<=antnum; j++) {
				if(dist(tank[i].x,tank[i].y,ant[j].x,ant[j].y)<=r*r) {
					if(OnLine(x1,y1,x2,y2,j)) {
						ant[j].hp-=d;
//						printf("attack!");
					}
				}
			}
			//.....................................................
		}
	}
//	if(nowtime==t) {
//		puts("我永远喜欢珂朵莉");
//	}
	//攻击结束后，如果发现扛蛋糕的蚂蚁没死并在窝的位置，就认为蚂蚁抢到了蛋糕。游戏也在此时结束。
	if(cakeant && ant[cakeant].hp>=0) {
		if(ant[cakeant].x==0 && ant[cakeant].y==0) {
			GameFail=true;
		}
	}
	RefreshAnt();
	if(!GameFail) {
		EndSecond();
	}
}
void main() {
//	freopen("data.txt","r",stdin);
//	freopen("antbuster.in","r",stdin);
//	freopen("WA.txt","w",stdout);
	ReadData();
	Init();
	for(re i=1; i<=t; i++) {
//		if(i==t) {
//			puts("我永远喜欢艾瑟雅");
//		}
		if(i==9){
			i=9;
		}
		Xuming(i);
		if(GameFail) {
			printf("Game over after %d seconds\n",i);
			break;
		}
		printf("%d\n",antnum);
		for(re j=1; j<=antnum; j++) {
			printf("%d %lld %lld %d %d\n",ant[j].age,ant[j].lv,ant[j].hp,ant[j].x,ant[j].y);
		}
	}
	if(!GameFail)	puts("The game is going on");
	printf("%d\n",antnum);
	for(re i=1; i<=antnum; i++) {
		printf("%d %lld %lld %d %d\n",ant[i].age,ant[i].lv,ant[i].hp,ant[i].x,ant[i].y);
	}
}

}
int main() {
	Solution::main();
	return 0;
}
/*
4 4
1 5 1
1 2
4
*/ 
