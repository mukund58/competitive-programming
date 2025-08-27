#include <bits/stdc++.h>
using namespace std;

class LRUCache {
public:

    class Node{
	    public:
        int key;
        int val;
        Node *prev;
        Node *next;

        Node(int k,int v){
            key =k;
            val=v;
        }
    };

    Node* head = new Node(-1,-1);
    Node* tail = new Node(-1,-1);

    int cap;
    unordered_map<int,Node*> m;

    LRUCache(int capacity) {
   	cap = capacity;
	head->next = tail;
	tail->prev = head;
    }

    void addNode(Node* newnode){
	Node* tmp = head->next;

	newnode -> next = tmp;
	newnode -> prev = head;

	head->next = newnode;
	tmp->prev = newnode;

    }   
    void deleteNode(Node* delNode){
	    Node *tmpPrev = delNode->prev;
	    Node *tmpNext = delNode->next;

	    tmpPrev -> next = tmpNext;
	    tmpNext-> prev = tmpPrev;
    }

    int get(int key) {
    	if(m.find(key) != m.end()){
		Node* resNode = m[key];

		int ans = resNode->val;

		m.erase(key);
		deleteNode(resNode);
		addNode(resNode);

		m[key] = head-> next;
		return ans;
	}    
	return -1;
    }
    
    void put(int key, int value) {
        
    	if(m.find(key) != m.end()){
		Node* curr = m[key];
		m.erase(key);
		deleteNode(curr);
	}
	if(m.size() == cap){
		m.erase(tail->prev->key);
		deleteNode(tail->prev);
	}
		addNode(new Node(key,value));

		m[key] = head-> next;
	}    
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */
