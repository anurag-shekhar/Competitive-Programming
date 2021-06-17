/*
 ****************************************************************
 * Author : Anurag Shekhar
 * Email : anurag.shekhar.work@gmail.com
 *
 * Github : https://github.com/anurag-shekhar
 * LinkedIn : https://www.linkedin.com/in/anurag-shekhar/
 *
 * File Name : 725.cpp
 * Created on : Thu Jun 17 2021
 ****************************************************************
 */

class LRUCache {
    public:
    class LL
    {
        public :
        int key; 
        int val;
        LL* prev;
        LL* next;
        LL(int id, int v): key(id), val(v), prev(NULL), next(NULL) {}
    };
    LL *head, *tail;
    int size;
    int currSize = 0;
    unordered_map<int, LL*> m;
    LRUCache(int capacity) {
        
        m.clear();
        head = NULL;
        tail = NULL;
        size = capacity;
        currSize = 0;
    }

    void insert_node(LL* node)
    {
        currSize++;
        if(!head)
        {
            head = node;
            tail = node;
        }
        else 
        {
            node->next = head;
            head->prev = node;
            head = node;
        }
    }
    LL* delete_node(LL* node)
    {
        LL* prev = node->prev;
        LL* next = node->next;
        currSize--;
        if(!next && !prev)   // <- A -> 
        {
            head=NULL;
            tail=NULL;
        }
        else if(!prev)  //     <- A -> x -> x ->
        {
            head = head->next;
            head->prev = NULL;
        }
        else if(!next)  //     <- x -> x -> A ->
        {
            tail = tail->prev;
            tail->next = NULL;
        }
        else            //     <- x -> A -> x ->
        {
            prev->next = next;
            next->prev = prev;
        }
        node->prev = NULL;
        node->next = NULL;
        return node;
    }

    void print()
    {
        LL* tmp = head;
        while(tmp)
        {
            cout<<tmp->val<<" ";
            tmp = tmp->next;
        }
        cout<<endl;
    }
    int get(int key) {
        
        if(m.count(key))
        {
            LL* node = m[key];
            node = delete_node(node);
            insert_node(node);
            //cout<<"G"<<endl;
            //print();
            return node->val;
        }
        //cout<<"G"<<endl;
        //print();
        return -1;
    }

    void set(int key, int val) {
        
        if(m.count(key))
        {
            m[key]->val = val;
            LL* node = m[key];
            delete_node(node);
            insert_node(node);
        }
        else 
        {
            LL* node = new LL( key,val);
            m[key] = node;
            if(currSize == size)
            {
                m.erase(tail->key);
                delete_node(tail);
                insert_node(node);
            }
            else 
                insert_node(node);
        }
        //cout<<"S"<<endl;
        //print();
    }
};
