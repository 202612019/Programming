/*
--LRU Cache with Operator Overloading--

Implement an LRUCache class.
The constructor receives the cache capacity.
Implement get(key) to return the value associated with a key.
Return -1 when the key does not exist.
Implement put(key,value) to insert or update a key.
When capacity is exceeded, remove the least recently used key.
Overload = to copy the state of one cache object into another.
Use a friend operator<< to display cache entries for debugging/output.
Cache get and put operations must run in average O(1) time.
Input Format

The first operation initializes LRUCache.
Subsequent operations are either put or get.
put contains a key and value.
get contains a key.
The capacity is provided during initialization.
Operations are processed sequentially.
Constraints

1 <= capacity <= 3000

0 <= key <= 10^4

0 <= value <= 10^5

At most 2 * 10^5 calls to get and put.

get and put must have average O(1) complexity. Assignment must correctly copy cache contents. The friend function must access cache data without making the data public.

Output Format

For every get, output the returned value.
put produces no direct value.
Represent constructor and put results as null if following the LeetCode format.
The output sequence must match the expected result.
explaination:
LRUCache lRUCache = new LRUCache(2);
lRUCache.put(1, 1); // cache is {1=1}
lRUCache.put(2, 2); // cache is {1=1, 2=2}
lRUCache.get(1); // return 1
lRUCache.put(3, 3); // LRU key was 2, evicts key 2, cache is {1=1, 3=3}
lRUCache.get(2); // returns -1 (not found)
lRUCache.put(4, 4); // LRU key was 1, evicts key 1, cache is {4=4, 3=3}
lRUCache.get(1); // return -1 (not found)
lRUCache.get(3); // return 3
lRUCache.get(4); // return 4

Sample Input 0
["LRUCache", "put", "put", "get", "put", "get", "put", "get", "get", "get"]
[[2], [1,1], [2,2], [1], [3,3], [2], [4,4], [1], [3], [4]]

Sample Output 0
[null, null, null, 1, null, -1, null, -1, 3, 4]

*/

#include <iostream>
#include <list>
#include <unordered_map>
#include <vector>
#include <string>
#include <cctype>

using namespace std;

class LRUCache {
private:
    int capacity;
    list<pair<int, int>> cacheList; 
    unordered_map<int, list<pair<int, int>>::iterator> cacheMap;

public:
    LRUCache(int cap = 0) { capacity = cap; }

    LRUCache& operator=(const LRUCache& other) {
        if (this != &other) {
            capacity = other.capacity;
            cacheList = other.cacheList; 
            cacheMap.clear();
            for (auto it = cacheList.begin(); it != cacheList.end(); ++it) {
                cacheMap[it->first] = it;
            }
        }
        return *this;
    }

    int get(int key) {
        if (!cacheMap.count(key)) return -1; 
        cacheList.splice(cacheList.begin(), cacheList, cacheMap[key]);
        return cacheMap[key]->second;
    }

    void put(int key, int value) {
        if (cacheMap.count(key)) {
            cacheMap[key]->second = value;
            cacheList.splice(cacheList.begin(), cacheList, cacheMap[key]);
            return;
        }
        if (cacheList.size() == capacity) {
            cacheMap.erase(cacheList.back().first); 
            cacheList.pop_back();   
        }
        cacheList.push_front({key, value});
        cacheMap[key] = cacheList.begin();
    }
};

int main() {
    vector<string> cmds;
    vector<int> nums;
    char ch;
    string word = "", num = "";
    
    while (cin >> ch) {
        if (isalpha(ch)) {
            word += ch;
        } else if (word != "") {
            cmds.push_back(word);
            word = "";
        }
        
        if (isdigit(ch)) {
            num += ch;
        } else if (num != "") {
            nums.push_back(stoi(num));
            num = "";
        }
    }
    if (word != "") cmds.push_back(word);
    if (num != "") nums.push_back(stoi(num));

    LRUCache* cache = nullptr;
    int n_idx = 0;
    
    cout << "[";
    for (size_t i = 0; i < cmds.size(); ++i) {
        if (cmds[i] == "LRUCache") {
            cache = new LRUCache(nums[n_idx++]);
            cout << "null";
        } 
        else if (cmds[i] == "put") {
            cache->put(nums[n_idx], nums[n_idx + 1]);
            n_idx += 2;
            cout << "null";
        } 
        else if (cmds[i] == "get") {
            cout << cache->get(nums[n_idx++]);
        }
        
        if (i < cmds.size() - 1) cout << ", ";
    }
    cout << "]\n";

    return 0;
}

// #include <iostream>
// #include <list>
// #include <unordered_map>
// #include <vector>
// #include <string>
// #include <cctype>

// using namespace std;

// class LRUCache {
// private:
//     int capacity;
//     list<pair<int, int>> cacheList; 
//     unordered_map<int, list<pair<int, int>>::iterator> cacheMap;

// public:
//     LRUCache(int cap = 0) {
//         capacity = cap;
//     }

//     LRUCache& operator=(const LRUCache& other) {
//         if (this != &other) {
//             capacity = other.capacity;
//             cacheList = other.cacheList; 
            
//             cacheMap.clear();
//             for (auto it = cacheList.begin(); it != cacheList.end(); ++it) {
//                 cacheMap[it->first] = it;
//             }
//         }
//         return *this;
//     }

//     int get(int key) {
//         if (!cacheMap.count(key)) {
//             return -1; 
//         }
//         cacheList.splice(cacheList.begin(), cacheList, cacheMap[key]);
//         return cacheMap[key]->second;
//     }

//     void put(int key, int value) {
//         if (cacheMap.count(key)) {
//             cacheMap[key]->second = value;
//             cacheList.splice(cacheList.begin(), cacheList, cacheMap[key]);
//             return;
//         }

//         if (cacheList.size() == capacity) {
//             int lruKey = cacheList.back().first;
//             cacheMap.erase(lruKey); 
//             cacheList.pop_back();   
//         }

//         cacheList.push_front({key, value});
//         cacheMap[key] = cacheList.begin();
//     }

//     friend ostream& operator<<(ostream& os, const LRUCache& cache) {
//         os << "{";
//         for (auto it = cache.cacheList.begin(); it != cache.cacheList.end(); ++it) {
//             os << it->first << "=" << it->second;
//             if (next(it) != cache.cacheList.end()) os << ", ";
//         }
//         os << "}";
//         return os;
//     }
// };

// int main() {
//     ios_base::sync_with_stdio(false);
//     cin.tie(NULL);

//     string input = "";
//     char c;
//     while (cin >> c) {
//         input += c;
//     }
    
//     if (input.empty()) return 0;

//     int depth = 0;
//     string cmds_part = "";
//     size_t i = 0;
//     for (; i < input.size(); ++i) {
//         if (input[i] == '[') depth++;
//         else if (input[i] == ']') depth--;
        
//         cmds_part += input[i];
//         if (depth == 0) break;
//     }
//     i++;
//     string args_part = (i < input.size()) ? input.substr(i) : "";

//     vector<string> commands;
//     string cmd = "";
//     bool in_quote = false;
//     for (char ch : cmds_part) {
//         if (ch == '"') {
//             if (in_quote) {
//                 commands.push_back(cmd);
//                 cmd = "";
//             }
//             in_quote = !in_quote;
//         } else if (in_quote) {
//             cmd += ch;
//         }
//     }

//     vector<vector<int>> args;
//     vector<int> cur_arg;
//     string num = "";
//     for (size_t j = 1; j < args_part.size() && j < args_part.size() - 1; ++j) {
//         char ch = args_part[j];
//         if (ch == '[') {
//             cur_arg.clear();
//         } else if (ch == ']') {
//             if (!num.empty()) {
//                 cur_arg.push_back(stoi(num));
//                 num = "";
//             }
//             args.push_back(cur_arg);
//         } else if (isdigit(ch) || ch == '-') {
//             num += ch;
//         } else if (ch == ',') {
//             if (!num.empty()) {
//                 cur_arg.push_back(stoi(num));
//                 num = "";
//             }
//         }
//     }

//     LRUCache* cache = nullptr;
//     cout << "[";
//     for (size_t k = 0; k < commands.size(); ++k) {
//         if (commands[k] == "LRUCache") {
//             cache = new LRUCache(args[k][0]);
//             cout << "null";
//         } else if (commands[k] == "put") {
//             cache->put(args[k][0], args[k][1]);
//             cout << "null";
//         } else if (commands[k] == "get") {
//             int val = cache->get(args[k][0]);
//             cout << val;
//         }
        
//         if (k != commands.size() - 1) {
//             cout << ", ";
//         }
//     }
//     cout << "]\n";

//     delete cache;
//     return 0;
// }
