#include<stdlib.h>
#include<time.h>
#include<math.h>
#include"randgen.h"

void seed_rand(){
	srand(time(0));
}

double rand_gen(){
	double r = (double)rand() / (double)RAND_MAX;
	return r;
}

long uniform(long a, long b)
{ 
	return (a + (b - a) * rand_gen());
}

long zipf(double a, double* s, long n){
	double x, p = 0;
	int i = 0;
	if(*s == 0){
		for(i = 1; i <= n; i++){
			*s += 1.0 / pow((double)i, a);
			*s = 1.0 / *s;
		}
	}
	do{
		x = rand_gen();
	}
	while((x == 0) || (x == 1));
	for(i = 1; i <= n; i++){
		p += *s / pow((double)i, a);
		if(p >= x)
			return (i);
	}
	return (n);
}
int main(){
return 0;
}
