/*
 * =====================================================================================
 *
 *       Filename:  day103_Lru_Cache.cpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  09/26/2020 12:00:13 AM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Saurabh Bhartia (SB), s.bhartia.sb98@gmail.com
 *   Organization:  
 *
 * =====================================================================================
 */
#include <stdlib.h>
// design the class:
 int ct=0;
 list<int>q;
 map<int,int>m;
 int capacity;

// list<pair<int, int>> lst;
// unordered_map<int, list<pair<int, int>>::iterator> mp;
// int size;
class LRUCache
{
private:
    
public:
    
    LRUCache(int cap)
    {
        // constructor for cache
    //     ios_base::sync_with_stdio(false);
    // cin.tie(NULL);
    // cout.tie(NULL);
        capacity=cap;
        ct =0;
        // size = cap;
        // s.clear();
        q.clear();
        m.clear();
        
    }
    
    static int get(int key)
    {
        // this function should return value corresponding to key
        if(m.find(key)==m.end())
            return -1;
        q.remove(key);
        q.push_back(key);
        return m[key];
        // if(mp.find(key) == mp.end())
        //     return -1;
            
        // auto it = mp[key];
        // int val = it->second;
        // lst.erase(it);
        // lst.push_front({key, val});
        // mp[key] = lst.begin();
        
        // return val;
    }
    
    static void set(int key, int value)
    {
        // cout << key << " new value " << value << endl;
        if(ct<capacity && m.find(key)==m.end()){
            q.push_back(key);
            m[key]=value;
            ct++;
        }
        else if(m.find(key)!=m.end()){
            // cout << key<<" "<<m[key] << " ";
            m[key]=value;
            // cout << key<<" "<<m[key] << endl;
            q.remove(key);
            q.push_back(key);
        }
        else if(ct==capacity && m.find(key)==m.end())
        {
            // cout << key1 << " old key"<<endl;
            int key1=q.front();
            q.pop_front();
            m.erase(key1);
            q.push_back(key);
            m[key]=value;
            
        }
        // if(mp.find(key) == mp.end()){
        //     if(lst.size() == size){
        //         auto last = lst.back();
        //         mp.erase(last.first);
        //         lst.pop_back();
        //     }
        // }
        // else{
        //     auto it = mp[key];
        //     lst.erase(it);
        // }
            
        // lst.push_front({key, value});
        // mp[key] = lst.begin();
        // cout << ct << " new capacity " << endl;
        // storing key, value pair
    }
};
