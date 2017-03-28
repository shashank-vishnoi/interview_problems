#include<iostream>

using namespace std;

#define null NULL

class TrieNode{
	public:
		char alphabet;
		int value;
		TrieNode* next;
		TrieNode* child;
	TrieNode()
	{
		next=null;
		child=null;
		alphabet = '.';
	}
	TrieNode(char ch)
	{
		this->alphabet = ch;
	        next=null;
       		child = null;	       
	}
};
//1. If trie is empty i.e. having only root then craete all characters as a child e.g. shas: s-h-a-s-null
//2. else search the first character in all it's childs which are in linked list at the same level - Level search
	//2.1 if found in the same level then traverse all it's child nodes until matches then go to step 2
	//2.2 If not found add new child same as step 1.


TrieNode* sameLevelSearch(TrieNode* trie, char ch)
{
	if(!trie)
		return 0;
	while(trie->alphabet != ch)
	{
		trie=trie->next;
		if(trie == 0)
			return 0;
	}
	return trie;
}
//should be called when no match found
TrieNode* insertAllCharacterAsChildNodes(TrieNode *trie, char keys[])
{
	for(int i=0; keys[i]!= '\0'; i++)
	{
		trie->child = new TrieNode(keys[i]);
		trie=trie->child;
	}
	return trie;
}

void add(TrieNode* trie, char keys[])
{
	if(!trie) 
		return;
	if(trie->alphabet == '.' && trie->child == 0)
	{
		trie->child = new TrieNode(keys[0]);
		insertAllCharacterAsChildNodes(trie->child, keys+1);
		return;
	}
	else if(trie->alphabet == '.')
	{
		int i=0;
		//for(int i=0; keys[i]!='\0'; i++)
		{
			TrieNode* foundNode = sameLevelSearch(trie->child,keys[i]);
			if(foundNode)
			{
				add(foundNode->child,(keys+i+1));
			}else{
				TrieNode* t= trie->child;
				while(t->next != 0)
					t = t->next;
				t->next = new TrieNode(keys[0]);
				insertAllCharacterAsChildNodes(t->next,keys+1);
			}
		}
	}
	else{
		TrieNode* foundNode = sameLevelSearch(trie,keys[0]);
		if(foundNode)
		{
			if(foundNode->child != 0)
				add(foundNode->child,(keys+1));
			else
				insertAllCharacterAsChildNodes(foundNode,keys+1);
		}
		else{
			trie->next = new TrieNode(keys[0]);
			insertAllCharacterAsChildNodes(trie->next,(keys+1));
		}
	}
}


void printnext(TrieNode* t)
{
	if(!t)
		return;
	if(t->child)
		cout<<t->alphabet<<"-";
	else
		cout<<t->alphabet<<endl;
	printnext(t->child);
}

void print(TrieNode *t)
{
	if(!t)
		return;
	if(t->next)
	{
		cout<<t->alphabet<<"-";
	}else{
		cout<<t->alphabet<<endl;
	}
	TrieNode *temp = t;
	while(temp->next != 0)
	{
		printnext(temp->next);
		temp=temp->next;
		if(temp->next)
			cout<<" -";
	}
	print(t->child);
}

int main()
{
	TrieNode* Trie = new TrieNode();
	add(Trie,"shas");
	add(Trie,"shvish");
	add(Trie,"shashank");
	add(Trie,"abc");
	add(Trie,"xyz");
	add(Trie,"abcdef");
	add(Trie,"shasabcd");
	add(Trie,"rose");
	add(Trie,"kerala");
	add(Trie,"kerALA");
	print(Trie);
}
