#include<iostream>
using namespace std;

struct Rect{
	double x,y,w,h;
};

double overlap(Rect A, Rect B){
	double x, y;
	//Overlaping case
	if(B.x>A.x&&B.y<A.y&&(A.x + A.w)>(B.x + B.w)&&(A.y + A.h)>(B.y + B.h))return (B.w-B.x)*(B.h-B.x);
	else if(B.x<A.x&&B.y>A.y&&(A.x + A.w)<(B.x + B.w)&&(A.y + A.h)<(B.y + B.h))return (A.w-A.x)*(A.h-A.x);
	//Normal interserting case
	x=min((A.x + A.w),(B.x + B.w))-max(A.x,B.x);
	y=min(A.y,B.y)-max((A.y-A.h),(B.y - B.h));
	//checking for non-intersecting case
	if(x*y<0)return 0;
	else return x*y;
}

int main(){
	Rect R1 = {-1,2,6.9,9.6};
	Rect R2 = {0,0,10.2,2.5};
	cout << overlap(R1,R2);

	return 0;
}
