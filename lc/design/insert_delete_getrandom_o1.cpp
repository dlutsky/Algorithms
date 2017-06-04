class RandomizedSet {
private:
  std::vector<int> set;
  std::unordered_map<int, int> map;
public:
  /** Initialize your data structure here. */
  RandomizedSet() {

  }

  /** Inserts a value to the set. Returns true if the set did not already contain the specified element. */
  bool insert(int val) {
    if(map.count(val)){
      return false;
    }
    set.push_back(val);
    map[val] = set.size()-1;
    return true;
  }

  /** Removes a value from the set. Returns true if the set contained the specified element. */
  bool remove(int val) {
    if(!map.count(val)){
      return false;
    }
    int index = map[val];
    set[index] = set.back();
    map[set.back()] = index;
    set.pop_back();
    map.erase(val);
    return true;
  }

  /** Get a random element from the set. */
  int getRandom() {
    if(set.empty()){
      return 0;
    }
    return set[rand() % set.size()];
  }
};
