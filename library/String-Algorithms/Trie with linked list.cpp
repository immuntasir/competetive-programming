// Supports character set {a - z}
#include <bits/stdc++.h>
using namespace std;
struct node {
	int words;
	int prefixes;
	node *next[26+1];
	node() {
		for(int i=0;i<26;i++) next[i]=NULL;
		words = prefixes = 0;
	}
}*root;
void insert(char *str,int len) {
	node *curr=root;
	for(int i=0;i<len;i++) {
		int id=str[i]-'a';
		if(curr->next[id]==NULL)
			curr->next[id]=new node();
        curr->prefixes++;
		curr=curr->next[id];
	}
	curr->words++;
}
int wordsearch (char *str,int len) {
	node *curr=root;
	for(int i=0;i<len;i++) {
		int id=str[i]-'a';
		if(curr->next[id]==NULL) return false;
		curr=curr->next[id];
	}
	return curr->words;
}
int prefixsearch (char *str, int len) {
    node *curr=root;
	for(int i=0;i<len;i++) {
		int id=str[i]-'a';
		if(curr->next[id]==NULL) return false;
		curr=curr->next[id];
	}
	return curr->prefixes;
}
void del(node *cur)
{
      for(int i=0;i<26;i++)
             if(cur->next[i])
                  del(cur->next[i]) ;
          delete(cur) ;
}
int main(){
    freopen("in.txt", "r", stdin);
	puts("ENTER NUMBER OF WORDS");
	root=new node();
	int num_word;
	cin>>num_word;
	for(int i=1;i<=num_word;i++)
	{
		char str[50];
		scanf("%s",str);
		insert(str,strlen(str));
	}
	puts("ENTER NUMBER OF QUERY");
	int query;
	cin>>query;
	for(int i=1;i<=query;i++)
	{
        int x;
		char str[50];
		scanf("%d %s", &x, str);
		if (x == 1) {
            //printf("%d words found\n", wordsearch(str, strlen(str)));
		}
		else {
            //printf("%d words with such prefix found\n", prefixsearch(str, strlen(str)));
		}
	}
	del(root);
	return 0;
}
