/*
Approach: Hash, Doublly Linked List
Note: 문제의 속성을 파악하고 자료구조를 정하자
Constant find -> Hash Tablej
Costant remove -> Doubly Linked List
Time Complexity: O(1) each operation.
Space Complexity: O(n) store cache memory.
*/
#include <list>
#include <unordered_map>

class LRUCache {
   public:
    LRUCache(size_t capacity) : capacity_(capacity) {}

    int get(int key) {
        auto iter = cache_lookup_.find(key);
        if (iter == cache_lookup_.end()) {
            return -1;
        }

        cache_memory_.splice(cache_memory_.begin(), cache_memory_,
                             iter->second);
        return iter->second->second;
    }

    void put(int key, int value) {
        auto iter = cache_lookup_.find(key);
        if (iter != cache_lookup_.end()) {
            cache_memory_.splice(cache_memory_.begin(), cache_memory_,
                                 iter->second);
            iter->second->second = value;
            return;
        }
        if (cache_memory_.size() == capacity_) {
            int key_to_del = cache_memory_.back().first;
            cache_memory_.pop_back();
            cache_lookup_.erase(key_to_del);
        }
        cache_memory_.emplace_front(key, value);
        cache_lookup_[key] = cache_memory_.begin();
    }

   private:
    size_t capacity_;
    std::unordered_map<int, std::list<std::pair<int, int>>::iterator>
        cache_lookup_;
    std::list<std::pair<int, int>> cache_memory_;
};