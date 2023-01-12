#include "../inc/coord.h" 
bool equal(coord a,coord b){
	return a.x==b.x && a.y==b.y;
}
coord plus(coord a,coord b){
	coord tmp;
	tmp.x=a.x+b.x;
	tmp.y=a.y+b.y;
	return tmp;
}
coord minus(coord a,coord b){
	coord tmp;
	tmp.x=a.x-b.x;
	tmp.y=a.y-b.y;
	return tmp;
}

coord devide(coord a,short scalar){
	a.x/=scalar;
	a.y/=scalar;
	return a;
}

coord multiply(coord a,short scalar){
	a.x*=scalar;
	a.y*=scalar;
	return a; 
}
