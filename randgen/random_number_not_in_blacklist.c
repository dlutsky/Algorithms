#include<stdlib.h>
#include"randgen.h"

int rand_find(int a, int b, int *bk_list, int n){
	long r = rand_gen() * (b - a + 1 - n);
	int l = 0, u = n;
	while(l < u){
		int m = l + (u - l) / 2;
		int f = bk_list[m] - m - a;
		if(f >= r + 1){
			u = m;
		}
		else{
			l = m + 1;
		}
	}
	int f = bk_list[l] - l - a;
	int d = r - f;
	return bk_list[l] + d;
}
