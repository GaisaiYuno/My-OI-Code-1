#include<iostream>
#include<cstdio>
#include<cmath>
using namespace std;
int t;
struct vector{
	double x;
	double y;
	double z;
};
vector init(double x,double y,double z){
	vector v;
	v.x=x;
	v.y=y;
	v.z=z;
	return v;
	/*������ʼ��*/ 
}
vector cross(vector a,vector b){
	vector ans;
	ans.x=a.y*b.z-b.y*a.z;
	ans.y=a.z*b.x-b.z*a.x;
	ans.z=a.x*b.y-b.x*a.y;
	return ans;
	/*
	�������
	a=(X1,Y1,Z1),b=(X2,Y2,Z2),
    ab=(Y1Z2-Y2Z1,Z1X2-Z2X1,X1Y2-X2Y1)
	*/ 
} 
double module(vector v){
	return sqrt(v.x*v.x+v.y*v.y+v.z*v.z);
	/*
    ��������ģ��,������Ϊ���������ĳ���
    �ռ�����(x,y,z)������x,y,z�ֱ��������ϵ����꣬ģ���ǣ�sqrt(x^2+y^2+z^2)
    */ 
}
int main(){
    cin>>t;
	while(t--){
		vector AB,AC;
		double h1,r1,x1,y1,z1;
        double h2,r2,x2,y2,z2,x3,y3,z3;
        scanf("%lf%lf%lf%lf%lf",&h1,&r1,&x1,&y1,&z1);
        scanf("%lf%lf%lf%lf%lf%lf%lf%lf",&h2,&r2,&x2,&y2,&z2,&x3,&y3,&z3);
        double jh=z1+h1-r1,th=z2+0.9*h2-r2;
        AB=init(x1-x2,y1-y2,jh-th);
        AC=init(x3,y3,z3);
        double dist=module(cross(AB,AC))/module(AC);//����ͷ�����ĵ�B��ǹֱ��AC�ľ��� |ABXAC|/|AC|  X�ǲ��   ||��ʾģ ;
        if(dist<=r1) cout<<"YES"<<endl;
        else cout<<"NO"<<endl;     
	}  
}
