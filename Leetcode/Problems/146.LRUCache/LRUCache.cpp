/*
 ****************************************************************
 * Author : Anurag Shekhar
 * Email : anurag.shekhar.work@gmail.com
 *
 * Github : https://github.com/anurag-shekhar
 * LinkedIn : https://www.linkedin.com/in/anurag-shekhar/
 *
 * File Name : LRUCache.cpp
 * Created on : Sat May 22 2021
 ****************************************************************
 */

class LRUCache {
public:
    class LL
    {
        public:
        int key;
        int val;
        LL *next;
        LL *prev;
        
        LL(int a, int b) : key(a), val(b), next(NULL), prev(NULL){}
    };
    int size, currSize;
    unordered_map<int,LL*> m;
    LL *head;
    LL *tail;
    
    void push_front(LL* node)
    {   
        currSize++;
        if(!head)
        {
            head = node;
            tail = node;
            return;
        }
        
        node->next = head;
        head->prev = node;
        head = node;
        
    }
    void remove(LL* node)
    {
        currSize--;
        
        //remove node from current position
        LL *n = node->next;
        LL *p = node->prev;
        node->next = NULL;
        node->prev = NULL;
        
        //re-adjusting the pointers
        if(p)
            p->next = n;
        if(n)
            n->prev = p;
        
        //updating tail
        if(node == tail)
            tail = p;
        //updating head    
        if(node == head)
           head = n; 
    }
    void pop_back()
    {
        currSize--;
        LL *del = tail;
        tail = tail->prev;
        tail->next = NULL;
        delete del;
    }
    LRUCache(int capacity) {
        size = capacity;
        m.clear();
        currSize = 0;
        head = NULL;
        tail  = NULL;
    }
    
    int get(int key) {
        if(m.count(key)==0)
            return -1;
        LL *node = m[key];
        remove(node);
        push_front(node);
        
        return node->val;
        
    }
    
    void put(int key, int value) {
        
        LL *node;
        if(m.count(key)==0)
        {
            node = new LL(key,value);
            m[key] = node;    
        }
        else 
        {   node = m[key];
            node->val = value;
            remove(node);
        }
        push_front(node);
        if(currSize > size)
        {
            m.erase(tail->key);
            pop_back();
        }
        
    }
};
