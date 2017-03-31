#include<iostream>
#include<deque>
using namespace std;

#define null NULL
static int totoal_count;

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
		alphabet = ch;
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
	{
		return;
	}
	if(trie->alphabet == '.' && !(trie->child))
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
				if((foundNode->child != 0) )//|| (keys+1) != '\0')
				{
					if(keys[1] != '\0')
						add(foundNode->child,(keys+1));
					else
						foundNode->value = 1;
				}
				else
					insertAllCharacterAsChildNodes(foundNode,keys+1);
			}else{
				TrieNode* t= trie->child;
				while(t->next != 0)
					t = t->next;
				t->next = new TrieNode(keys[0]);

				insertAllCharacterAsChildNodes(t->next,keys+1);
			}
		}
	}
	else if(keys[0] != '\0'){
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
		if(trie->alphabet == keys[0] && keys[1] == '\0')
			trie->value = 1;
	}
//	else if(keys[0] == '\0')
//		trie->value = 1;
	else
		return;
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
		totoal_count++;
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
		totoal_count++;
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
	if(t->next != 0)// && t->next->alphabet != '\0')
	{
		q.pop_back();
		printAllChild(t->next,q);
	}
}

void printOnlyChilds(TrieNode* t, deque<char> q)
{
	if(!t)
		return;
	q.push_back(t->alphabet);
	if(t->value == 1 && t->child != 0)//last node
	{
		totoal_count++;
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
		totoal_count++;
		for(int i =0 ; i<s ; i++ )
		{
			cout<<q.front()<<"-";
			q.pop_front();
		}
		cout<<endl;
		return;
	}
	printAllChild(t->child, q);
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


void printAllPrefix(TrieNode *t,char keys[],deque<char> q)
{
	if(!t)
		return;
	if(keys[0] == '\0')
		//printAllChild(t,q);
		printOnlyChilds(t,q);
	/*else if(keys[1] == '\0')
	{
		printAllChild(t,q);	
		return;
	}*/
	TrieNode* node = sameLevelSearch(t,keys[0]);
	if(!node)
		return;
	else{
		q.push_back(node->alphabet);
		/*if(keys[1] == '\0' && node->alphabet == keys[0])
			printAllChild(node,q);
		else
			q.push_back(node->alphabet);*/
		if(keys[1] == '\0')
		{
			q.pop_back();
			printOnlyChilds(node,q);
			return;
		}
		printAllPrefix(node->child,keys+1,q);	
		//printAllPrefix(node,keys+1,q);	
	}

}

void printPrefix(TrieNode* t, char keys[])
{
	deque<char> q;
	totoal_count=0;
	printAllPrefix(t->child,keys,q);
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
	add(Trie,"s");
	add(Trie,"ss");
	add(Trie,"sss");
	add(Trie,"ssss");
	add(Trie,"sssss");
	//print(Trie);
	display(Trie);
	if(isExsist(Trie,"s"))
		cout<<"s Found"<<endl;
	else
		cout<<"Not found\n";

	cout<<"----------------s-------------------------"<<endl;
	printPrefix(Trie,"s");
	cout<<"Toatal->"<<totoal_count<<endl;
	cout<<"----------------ss-------------------------"<<endl;
	printPrefix(Trie,"ss");
	cout<<"Toatal->"<<totoal_count<<endl;
	cout<<"----------------sha-------------------------"<<endl;
	printPrefix(Trie,"sha");
	cout<<"Toatal->"<<totoal_count<<endl;
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



