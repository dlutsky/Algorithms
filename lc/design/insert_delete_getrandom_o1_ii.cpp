class RandomizedCollection {
private:
  std::vector<std::pair<int, int>> collection;
  std::unordered_map<int, std::vector<int>> map;
public:
  /** Initialize your data structure here. */
  RandomizedCollection() {

  }

  /** Inserts a value to the collection. Returns true if the collection did not already contain the specified element. */
  bool insert(int val) {
    bool result = map.find(val) == map.end();
    collection.push_back(std::make_pair(val, map[val].size()));
    map[val].push_back(collection.size()-1);
    return result;
  }

  /** Removes a value from the collection. Returns true if the collection contained the specified element. */
  bool remove(int val) {
    if(!map.count(val)){
      return false;
    }
    int index = map[val].back();
    collection[index] = collection.back();
    map[collection.back().first][collection.back().second] = index;
    collection.pop_back();
    map[val].pop_back();
    if(map[val].empty()){
      map.erase(val);
    }
    return true;
  }

  /** Get a random element from the collection. */
  int getRandom() {
    return collection[rand() % collection.size()].first;
  }
};
