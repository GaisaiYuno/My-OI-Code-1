#include<iostream>
#include<cstdio>
using namespace std;
struct vector{
	double x;
	double y;
	vector(){
		
	}
	vector(double xx,double yy){
		x=xx;
		y=yy;
	}
	friend vector operator +(vector a,vector b){
		return vector(a.x+b.x,a.y+b.y);
	}
	friend vector operator -(vector a,vector b){
		return vector(a.x-b.x,a.y-b.y);
	}
};
typedef vector point;
double dot(vector a,vector b){
	return a.x*b.x+a.y*b.y;
}
double cross(vector a,vector b){
	return a.x*b.y-a.y*b.x;
}
double len(vector a){
	return cross(a,a);
}

int main(){
	
}
