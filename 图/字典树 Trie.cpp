#include <bits/stdc++.h>
using namespace std;

const int SIZE = 26;

class TrieNode{
public:
	TrieNode* children[SIZE];
	bool isEnd;
	TrieNode(){
		this->isEnd = false;
		for(int i=0; i<SIZE; i++)
			this->children[i] = NULL;
	}
};

void insert(TrieNode* root, string key){
	TrieNode* pCrawl = root;
	for(int i=0; i<key.length(); i++){
		int index = key[i]-'a';
		if(!pCrawl->children[index])
			pCrawl->children[index] = new TrieNode();
		pCrawl = pCrawl->children[index];
	}
	pCrawl->isEnd = true;
}

bool search(TrieNode* root, string key){
	TrieNode* pCrawl = root;
	for(int i=0; i<key.length(); i++){
		int index = key[i]-'a';
		if(!pCrawl->children[index])
			return false;
		pCrawl = pCrawl->children[index];
	}
	return (pCrawl != NULL && pCrawl->isEnd);
}

bool isEmpty(TrieNode* root){
	for(int i=0; i<SIZE; i++)
		if(root->children[i])
			return false;
	return true;
}

TrieNode* remove(TrieNode* root, string key, int depth = 0){
	if(!root)
		return NULL;
	if(depth == key.size()){
		if(root->isEnd)
			root->isEnd = false;
		if(isEmpty(root)){
			delete root;
			root = NULL;
		}
		return root;
	}
	int index = key[depth] - 'a';
	root->children[index] = remove(root->children[index], key, depth+1);
	if(isEmpty(root) && root->isEnd == false){
		delete root;
		root = NULL;
	}
	return root;
}

int main(){
	string keys[] = {"the", "a", "there", "answer",
					"any", "by", "bye", "their", "hero", "heroplane"
					};
	int n = sizeof(keys)/sizeof(keys[0]);
	TrieNode* root = new TrieNode();
	for(int i=0; i<n; i++)
		insert(root, keys[i]);
	search(root, "the")? cout << "Yes\n" : cout << "No\n";
	search(root, "these")? cout << "Yes\n" : cout << "No\n";

	remove(root, "heroplane"); 
    search(root, "hero") ? cout << "Yes\n" : cout << "No\n"; 
    search(root, "heroplane") ? cout << "Yes\n" : cout << "No\n"; 
	return 0;
}
