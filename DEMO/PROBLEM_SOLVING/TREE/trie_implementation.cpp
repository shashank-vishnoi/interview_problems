#include<iostream>
#include<deque>
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
	trie->value = 1;
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
		if(trie->alphabet == keys[0] && keys[1] == '\0')
			trie->value = 1;
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

void printAllChild(TrieNode* t, deque<char> q)
{
	if(!t)
		return;
	q.push_back(t->alphabet);
	if(t->value == 1 && t->child != 0)//last node
	{
		//print deque
		deque<char> q1 = q;
		while(!q1.empty())
		{
			cout<<q1.front()<<"-";
			q1.pop_front();
		}
		cout<<endl;
	}
	else if(t->value == 1)
	{
		int s = q.size();
		for(int i =0 ; i<s ; i++ )
		{
			cout<<q.front()<<"-";
			q.pop_front();
		}
		cout<<endl;
		return;
	}
	printAllChild(t->child, q);
	//deque<char> temp;
	if(t->next != 0 && t->next->alphabet != '\0')
	{
		q.pop_back();
		printAllChild(t->next,q);
	}
}

void display(TrieNode *t)
{
	if(!t)
		return;
	static deque<char> q;
	q.push_back(t->alphabet);
	printAllChild(t->child,q);
	//traverseNext(t->next);
	//display(t->child->next);
}

int isExsist(TrieNode* t, char keys[])
{
	if(!t)
		return 0;
	if(t->alphabet != '.') //not a root
		return 0;
	for(int i=0; keys[i]!='\0'; i++)
	{
		
		TrieNode* node = sameLevelSearch(t->child,keys[i]);
		if(node == 0)
			return 0;
		else if(node->value == 1 && keys[i+1] == '\0')
			return 1;
		else
			t=node;
	}
	return 0;
}


int main()
{
	TrieNode* Trie = new TrieNode();
	add(Trie,"shas");
	add(Trie,"shvhn");
	add(Trie,"shvh");
	add(Trie,"shashank");
	add(Trie,"shash");
	add(Trie,"abc");
	add(Trie,"xyz");
	add(Trie,"abcdef");
	add(Trie,"shasabcd");
	add(Trie,"rose");
	add(Trie,"kerala");
	add(Trie,"kerALA");
	//print(Trie);
	display(Trie);
	if(isExsist(Trie,"shash"))
		cout<<"shash Found"<<endl;
	else
		cout<<"Not found\n";

}
/*
.-s-h-a-s-
.-s-h-a-s-h-
.-s-h-a-s-h-a-n-k-
.-s-h-a-s-a-b-c-d-
.-s-h-v-h-
.-s-h-v-h-n-
.-a-b-c-
.-a-b-c-d-e-f-
.-x-y-z-
.-r-o-s-e-
.-k-e-r-a-l-a-
.-k-e-r-A-L-A-
shash Found


*/



