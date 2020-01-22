#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<queue>
#include<stack>
#include<vector>
#include<utility>
#include<cmath>
#define maxn 100
using namespace std;
namespace Geometry {
	const double eps=1e-12;
	const double pi=acos(-1.0);
	struct point {
		double x;
		double y;
		point() {

		}
		point(double _x,double _y) {
			x=_x;
			y=_y;
		}
		friend point operator + (point p,point q) {
			return point(p.x+q.x,p.y+q.y);
		}
		friend point operator - (point p,point q) {
			return point(p.x-q.x,p.y-q.y);
		}
		double length() {
			return sqrt(x*x+y*y);
		}
		friend bool operator == (point P,point Q) {
			return (P.x==Q.x&&P.y==Q.y);
		}
	};
	typedef point Vector;
	int dcmp(double x) { //带精度误差的判断
		if(fabs(x)<eps) return 0;
		else return x>0?1:-1;
	}
	double dot(Vector p,Vector q) {
		return p.x*q.x+p.y*q.y;
	}
	double cross(Vector p,Vector q) {
		return p.x*q.y-p.y*q.x;
	}
	double dist(point P,point Q) {
		return (P-Q).length();
	}
	double dist_to_seg(point P,point A,point B) { //点P到线段AB的距离
		if(A==B) return dist(P,A);
		Vector v1=B-A,v2=P-A,v3=P-B;
		if(dcmp(dot(v1,v2))<0) return v2.length();
		else if(dcmp(dot(v1,v3))>0) return v3.length();
		else return fabs(cross(v1,v2))/v1.length();
	}
	bool is_intersect(point O,double r,point A,point B) { //圆(O,r)与线段AB是否相交
		if(dcmp(r-dist_to_seg(O,A,B))>=0) return 1;//r>=dist(O,AB)
		else return 0;
	}
};
using namespace Geometry;

int n,m,T;
int S,D,R;
const int dirx[5]= {0,0,-1,0,1}; //1E->2S->3W->4N,0不动
const int diry[5]= {0,1,0,-1,0};
inline int oppose(int dir) {//反方向 
	static const int op[5]= {0,3,4,1,2};
	return op[dir];
//	if(dir==1) return 3;
//	if(dir==2) return 4;
//	if(dir==3) return 1;
//	if(dir==4) return 2;
//	else return 0;
}
inline int turn_cw_90(int dir) {//顺时针转90度 
	return (dir==4)?1:(dir+1);
}
inline int turn_ucw_90(int dir){
	return (dir==1)?4:(dir-1);
} 
int now_tim;
int graph[maxn+5][maxn+5];
int info[maxn+5][maxn+5];
struct ant_type {
	int x;//x坐标
	int y;//y坐标
	int hp;//血量
	int dir;//来的方向,0表示被卡住
	int birth_tim;//出生时的时间
	int age;//年龄
	int level;//级别
	bool has_cake;
	inline point gpoint() {
		return point(x,y);
	}
	ant_type() {

	}
	ant_type(int _x,int _y,int _hp,int _dir,int _birth_tim,int _age,int _level) {
		x=_x;
		y=_y;
		hp=_hp;
		dir=_dir;
		birth_tim=_birth_tim;
		age=_age;
		level=_level;
		has_cake=false;
	}
	int get_ini_hp() {
		double pw=pow(1.1,level);
		if(pw>1.0*D*T) pw=1.0*D*T+1;
		return floor(4*pw);
	}
	void update_trace() {
//		int prex=x+dirx[oppose(dir)],prey=y+diry[oppose(dir)];
//		graph[prex][prey]=0;
		info[x][y]+=(has_cake?5:2);
	}
	void kill() {
		graph[x][y]=0;
	}
	void print() {
#ifdef DEBUG
		printf("age=%d level=%d hp=%d pos=(%d,%d)\n",age,level,hp,x,y);
		return;
#endif
		printf("%d %d %d %d %d\n",age,level,hp,x,y);
	}
	void move() {
		int nowdir=0;
		int num=-1;
		for(int i=1; i<=4; i++) { //从东开始顺时针找，相当于同时执行路线选择规则1,2
			int xx=x+dirx[i];
			int yy=y+diry[i];
			if(xx>n||yy>m||xx<0||yy<0) continue;//超出边界
			if(dir!=0&&i==oppose(dir)) continue;//是蚂蚁上一秒所在的点(除非上一个时刻蚂蚁就被卡住)
			if(graph[xx][yy]>0) continue;//有蚂蚁或炮台
			if(info[xx][yy]>num) { //找信息素最少的
				nowdir=i;
				num=info[xx][yy];
			}
		}
		if(nowdir==0) { //被卡住
			dir=0;
			return;
		}
		if((age+1)%5==0) { //age是从0开始的，所以要加1
			//逆时针转90度 
			for(int i=1; i<=4; i++) {
				nowdir=turn_ucw_90(nowdir);
				int xx=x+dirx[nowdir];
				int yy=y+diry[nowdir];
				if(xx>n||yy>m||xx<0||yy<0) continue;
				if(dir!=0&&nowdir==oppose(dir)) continue;
				if(graph[xx][yy]>0) continue;
				break;
			}
		}
		graph[x][y]=0;
		x=x+dirx[nowdir];
		y=y+diry[nowdir];
		graph[x][y]=1;
		dir=nowdir;
	}
};



int spawned_ant_cnt;//生成过的蚂蚁数量
vector<ant_type>ant;
void spawn() {
	if(ant.size()<6) {
		spawned_ant_cnt++;
		ant_type p=ant_type(0,0,0,0,now_tim,0,(spawned_ant_cnt-1)/6+1);
		p.hp=p.get_ini_hp();
		ant.push_back(p);
	}
}

bool is_cake_get=false;
int target=-1;
void get_cake(ant_type &p,int id) {
	if(is_cake_get){
		if(id==target){
			int ini_hp=p.get_ini_hp();
			p.hp+=floor(1.0*ini_hp/2);
			if(p.hp>ini_hp) p.hp=ini_hp;
		}
		return;
	}
	else {
		if(p.x==n&&p.y==m) {
			p.has_cake=1;
			int ini_hp=p.get_ini_hp();
			p.hp+=floor(1.0*ini_hp/2);
			if(p.hp>ini_hp) p.hp=ini_hp;//血量增加不会超过上限
			target=id;
			is_cake_get=true;
		}

	}
}
bool cmp_birth_tim (ant_type p,ant_type q) {
	return p.birth_tim<q.birth_tim;
}
bool cmp_age (ant_type p,ant_type q) {
	return p.age>q.age;
}
void move_all() {
	sort(ant.begin(),ant.end(),cmp_birth_tim);
	for(int i=0; i<ant.size(); i++) ant[i].move();
	for(int i=0; i<ant.size(); i++) get_cake(ant[i],i);
}

struct tower_type {
	int x;
	int y;
	tower_type() {

	}
	tower_type(int _x,int _y) {
		x=_x;
		y=_y;
	}
	inline point gpoint() {
		return point(x,y);
	}
	int get_target() { //选定目标
		if(is_cake_get&&dcmp(R-dist(ant[target].gpoint(),gpoint()))>0) return target;
		//任何打得到target的塔的炮口都会对准target
		else {
			double mindist=1e10;
			int mintim=now_tim+1;
			int id=-1;
			for(int i=0; i<ant.size(); i++) {
				double td=dist(ant[i].gpoint(),gpoint());
				if(td<mindist) {
					mindist=td;
					mintim=ant[i].birth_tim;
					id=i;
				} else if(td==mindist&&ant[i].birth_tim<mintim) {
					mintim=ant[i].birth_tim;
					id=i;
				}
			}
			return id;
		}
	}
	void shoot() {
		int id=get_target();
		point start=gpoint();
		point end=ant[id].gpoint();
		if(id==-1) return;
		if(dcmp(R-dist(start,end))<0) return;//超出射程
		for(int i=0; i<ant.size(); i++) {
			if(is_intersect(ant[i].gpoint(),0.5,start,end)) {
				ant[i].hp-=D;
			}
		}
	}
};
vector<tower_type>tower;

void attack() {
	for(int i=0; i<tower.size(); i++) tower[i].shoot();
	static vector<ant_type>tmp;
	tmp.clear();
	for(int i=0; i<ant.size(); i++) {
		if(ant[i].hp>=0){
			tmp.push_back(ant[i]);
			if(i==target) target=tmp.size()-1;
		}
		else {
			ant[i].kill();
			if(i==target) {
				target=-1;
				is_cake_get=false;
			}
		}
	}
	ant.clear();
	for(int i=0;i<tmp.size(); i++) ant.push_back(tmp[i]);
}
void left_info() {
	for(int i=0; i<ant.size(); i++) ant[i].update_trace();
}
bool is_lost() {
	if(is_cake_get&&ant[target].x==0&&ant[target].y==0) return 1;
	else return 0;
}
void add_tim() {
	for(int i=0; i<=n; i++) {
		for(int j=0; j<=m; j++) {
			if(info[i][j]>0) info[i][j]--;
		}
	}
	for(int i=0; i<ant.size(); i++) ant[i].age++;
	now_tim++;
}


void print_all_ant() {
	printf("debugging:\n");
	for(int i=0; i<ant.size(); i++) {
		ant[i].print();
	}
	printf("\n");
}

int main() {
//	freopen("antbuster.in","r",stdin);
//	freopen("antbuster.out","w",stdout);
	scanf("%d %d",&n,&m);
	scanf("%d %d %d",&S,&D,&R);
	tower.resize(S);
	for(int i=0; i<S; i++) {
		scanf("%d %d",&tower[i].x,&tower[i].y);
		graph[tower[i].x][tower[i].y]=2;
	}
	scanf("%d",&T);
	now_tim=0;
	while(now_tim<T) {
//		if(now_tim==8){
//			now_tim=8;
//		}
//		print_all_ant();
		spawn();
//		print_all_ant();
		left_info();
		move_all();
//		print_all_ant(); 
		attack();
		if(is_lost()) {
			printf("Game over after %d seconds",now_tim);
			return 0;
		}
//#ifdef DEBUG
//		print_all_ant();
//#endif
		add_tim();

	}
	printf("The game is going on\n");
	printf("%d\n",ant.size());
//	sort(ant.begin(),ant.end(),[]()->bool{});
	sort(ant.begin(),ant.end(),cmp_age);
	for(int i=0; i<ant.size(); i++) {
		ant[i].print();
	}
}
