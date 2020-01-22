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
int n,m;		//��ͼ���� 
ll s,d,r;		//�����ĸ������˺��͹�����Χ 
int t;			//��ʱ�� 

int info[Size][Size];	//��Ϣ�� 
int hasant[Size][Size];	//�������ϣ����У���¼��� 
bool hastow[Size][Size];		//���޷����� 

struct tower {
	int x,y;	//����λ�� 
} tank[Size];	//gcd��tank 

int antnum;		//�������� 
int allnum;		//�ӵ�1s�����ڵ��������� 
int cakeant;	//���ߵ�������ϱ�ţ���û�б����ߣ���Ϊ0�� 
struct student {	//gcd��tankѹѧ�� 
	int x,y;	//λ�� 
	ll hp,lv;	//Ѫ�����ȼ�level 
	int age;	//���� 
	int prex,prey;		//ǰһ������λ�� 
	inline void clear() {
		x=y=hp=lv=age=0;
		prex=prey=-1;
	}
} ant[Size];
const int dx[] = {0,1,0,-1};	//������������˳ʱ����ת 
const int dy[] = {1,0,-1,0};

inline bool check(int x,int y) {
	//�ж�(x,y)������ܲ���ȥ 
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
	//��ʼ��1.1^i 
	pw[0]=1;
	for(re i=1; i<=100000; i++) {
		pw[i]=pw[i-1]*1.1;
		if(pw[i]>(ll)d*t)	pw[i]=(ll)d*t+1;
	}
}
bool GameFail=false;	//��Ϸʧ�ܵı�� 
void AddAnt() {
	++antnum;
	++allnum;
	ant[antnum].clear();
	ant[antnum].x=0;
	ant[antnum].y=0;
	ant[antnum].lv=(allnum-1)/6+1;	//ǰ6ֻ��1����7ֻ��2����13ֻ��3...... 
	ant[antnum].hp=int(4.0*pw[ant[antnum].lv]);
	ant[antnum].age=0;
	hasant[0][0]=antnum;
}
void AddInfo() {		//������Ϣ�� 
	for(re i=1; i<=antnum; i++) {
		if(i==cakeant) {
			info[ant[i].x][ant[i].y]+=5;
		} else {
			info[ant[i].x][ant[i].y]+=2;
		}
	}
}
void RefreshAnt() {		//ˢ������ʬ�� 
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
void EndSecond() {		//������һ�� 
	//��󣬵�ͼ�����е����Ϣ����ʧ1��λ��
	for(re i=0; i<=n; i++) {
		for(re j=0; j<=m; j++) {
			if(info[i][j]) {
				info[i][j]--;
			}
		}
	}
	//�������ϵ������1��������1�뵽�˽�����
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
	for(re i=1; i<=s; i++) {	//������������target 
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
	//��֤k!=0 && k!=inf 
	double OH_k=-1.0/k;		//���ߵ�б�� 
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
void Xuming(int nowtime) {	//��i�룬����һ���׸����� 
	//1�������������ͼ������������6��һֻ���Ͼͻ��ڶ��ڳ��� 
	if(antnum<6 && !hasant[0][0]) {
		AddAnt();
	}
	//���������Լ����ڵ�����һЩ��Ϣ�� 
	AddInfo();
	//�����ƶ����ȳ������������ƶ���
	for(re i=1; i<=antnum; i++) {
		//�ҳ���Ϣ�����ĵ� 
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
		//��û�л�ֻ��һ����ȥ�ĵ㣬��ʱ����5�ı���Ҳ��������Ӱ�� 
		ant[i].prex=ant[i].x;
		ant[i].prey=ant[i].y;
		if(top==0) {
			continue;
		} else if(tot==1 || ant[i].age%5!=4) {
			//ageһ��ʼ��0���ʱ��һ��ʼ��1 
			//���age%5==4����ʱ��%5==0������Ż�˳ʱ����ת 
			UpdateAnt(i,stk[1]);
		} else {
			//��ʱ����ת 
			int zyd=pos-1;
			if(!zyd)	zyd=tot;
			UpdateAnt(i,can[zyd]);
		}
		hasant[ant[i].prex][ant[i].prey]=0;
		hasant[ant[i].x][ant[i].y]=i;
	}
	//�ƶ���Ϻ�����������ڵ����λ���ϲ��ҵ���û�����ߣ�
	//���ѵ��⿸�ϣ�Ѫ�����ӣ�������ʱ�������ܴ����������target��
	if(!cakeant) {
		for(re i=1; i<=antnum; i++) {
			if(ant[i].x==n && ant[i].y==m) {
				cakeant=i;
				ant[i].hp+=((int)floor(4.0*pw[ant[i].lv]))>>1;	//����ʱѪ����һ�� 
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
	//Ȼ��������ͬʱ��ʼ���������������������ֻ���ŵ�������Ϲ��ˣ�����˲���λ��
	for(re i=1; i<=s; i++) {	//������������ʼ���� 
		//������Ŀ������֮����һ���ߣ��ж���û������������ 
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
//		puts("����Զϲ�������");
//	}
	//����������������ֿ����������û�������ѵ�λ�ã�����Ϊ���������˵��⡣��ϷҲ�ڴ�ʱ������
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
//			puts("����Զϲ����ɪ��");
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
