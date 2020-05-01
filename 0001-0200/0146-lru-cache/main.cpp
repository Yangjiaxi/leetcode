#include <iostream>
#include <list>
#include <unordered_map>

using namespace std;

class LRUCache {
  private:
    using Key_T = unsigned;
    using Value_T = unsigned;
    struct Item {
        Key_T key;
        Value_T value;
        Item(Key_T _key, Value_T _value) : key(_key), value(_value) {}
    };
    using List = list<Item>;
    using Map = unordered_map<Key_T, List::iterator>;

    unsigned max_cap;
    List cache;
    Map table;

  public:
    LRUCache(int capacity) : cache(), table(), max_cap(capacity) { table.reserve(max_cap * 2); }

    int get(Key_T key) {
        auto it = table.find(key);
        if (it == table.end())
            return -1;
        cache.splice(cache.begin(), cache, it->second);
        return cache.begin()->value;
    }

    void put(Key_T key, Value_T value) {
        auto it = table.find(key);
        if (it == table.end()) {
            if (cache.size() == max_cap) {
                /** >> capacity exceed <<
                 * 1. remove in hashtable
                 * 2. remove in list (back of list)
                 */
                table.erase(cache.back().key);
                cache.pop_back();
            }
            cache.push_front({key, value});
            table.emplace(key, cache.begin());
        } else {
            it->second->value = value;
            cache.splice(cache.begin(), cache, it->second);
            table[key] = cache.begin();
        }
    }
};

int main() {
    LRUCache cache(1);

    cache.put(2, 100);
    cout << cache.get(2) << endl;
    cache.put(3, 2);
    cout << cache.get(2) << endl;
    cout << cache.get(3) << endl;

    return 0;
}