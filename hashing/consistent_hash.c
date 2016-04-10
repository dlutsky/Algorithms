#include"consistent_hash.h"

int32_t jump_consistent_hash(uint64_t key, int32_t num_buckets)
{
	int64_t state = 0;
	while(state < num_buckets){
		key = key * 2862933555777941757ULL + 1;
		state = (state + 1) * (double(1LL << 31) / double((key >> 33) + 1));
	}
	return state;
}
