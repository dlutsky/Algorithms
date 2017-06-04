const int NUM_BUCKETS = 1000;

template<class KEY, class VALUE>
class HashMap{
private:
	class HashNode{
	public:
		KEY key;
		VALUE value;
		HashNode *next;
		HashNode(KEY k, VALUE v) : key(k), value(v), next(NULL){
		}
	};
	class HashBucket{
	public:
		HashNode *head;
		int bucket_size;
		HashBucket() : head(NULL), bucket_size(0){
		}
		~HashBucket(){
			clear();
		}
		void clear(){
			HashNode *entry = head;
			while(entry != NULL){
				HashNode *prev = entry;
				entry = entry->next;
				delete prev;
			}
			head = NULL;
			bucket_size = 0;
		}
	};
	HashBucket *buckets;
	int num_buckets;
	int hashcode(KEY key){
	}
public:
	HashMap(){
		num_buckets = NUM_BUCKETS;
		buckets = new HashBucket[num_buckets];
	}
	~HashMap(){
		delete[] buckets;
	}
	void set(KEY key, VALUE value){
		HashBucket bucket = buckets[hashcode(key)];
		if(bucket.head != NULL){
			HashNode *entry = bucket.head;
			HashNode *prev = NULL;
			while(entry){
				if(entry->key == key)
					break;
				prev = entry;
				entry = entry->next;
			}
			if(entry){
				entry->value = value;
			}
			else{
				prev->next = new HashNode(key, value);
			}
		}
		else{
			bucket.head = new HashNode(key, value);
		}
		bucket.bucket_size++;
	}
	bool contains(KEY key){
		HashBucket bucket = buckets[hashcode(key)];
		if(bucket.head != NULL){
			HashNode *entry = bucket.head;
			while(entry){
				if(key == entry->key)
					return true;
				entry = entry->next;
			}
		}
		return false;
	}
	VALUE get(KEY key){
		HashBucket bucket = buckets[hashcode(key)];
		if(bucket.head != NULL){
			HashNode *entry = bucket.head;
			while(entry){
				if(key == entry->key)
					return entry->value;
				entry = entry->next;
			}
		}
		return 0;
	}
	void remove(KEY key){
		HashBucket bucket = buckets[hashcode(key)];
		if(bucket.head != NULL){
			HashNode *entry = bucket.head;
			HashNode *prev = NULL;
			while(entry){
				if(key == entry->key)
					break;
				prev = entry;
				entry = entry->next;
			}
			if(prev != NULL){
				prev->next = entry->next;
			}
			else{
				bucket.head = entry->next;
			}
			delete entry;
		}
	}
};
