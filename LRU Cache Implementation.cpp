#include <bits/stdc++.h>

class LRUCache
{
public:
    queue<int> q;
    unordered_map<int, int> cache;
    unordered_map<int, int> count;
    int size;

    void insert_to_queue(int x)
    {
        count[x]++;
        q.push(x);
    }

    LRUCache(int capacity)
    {
        size = capacity;
    }

    int get(int key)
    {
        if (cache.find(key) == cache.end())
        {
            return -1;
        }

        insert_to_queue(key);
        return cache[key];
    }

    void put(int key, int val)
    {
        if (cache.size() < size)
        {
            cache[key] = val;
            insert_to_queue(key);
            return;
        }

        if (cache.find(key) != cache.end())
        {
            cache[key] = val;
            insert_to_queue(key);
            return;
        }

        while (true)
        {
            int candidate = q.front();
            q.pop();
            count[candidate]--;
            if (count[candidate] == 0)
            {
                cache.erase(candidate);
                break;
            }
        }
        cache[key] = val;
        insert_to_queue(key);
    }
};
