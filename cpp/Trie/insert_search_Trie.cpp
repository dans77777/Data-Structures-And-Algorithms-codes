#include<iostream>
#include<vector>
using namespace std;
class TrieNode{
    public:
bool isTerminal;
TrieNode* child[26];

TrieNode()
{
    isTerminal=false;
    for(int i=0;i<26;i++)
    {
        child[i]=NULL;
    }
}

};

void add(string word, TrieNode* trie)
{
    int n=word.size();
for(int i=0;i<n;i++)
{
    if(trie->child[word[i]-'A']==NULL)
    {
        trie->child[word[i]-'A']=new TrieNode();
    }
    trie=trie->child[word[i]-'A'];
}
trie->isTerminal=true;
}
bool search(string word, TrieNode* trie)
{
     int n=word.size();
for(int i=0;i<n;i++)
{
    if(trie->child[word[i]-'A']==NULL)
    {
       return false;
    }
    trie=trie->child[word[i]-'A'];
}
 return trie->isTerminal;
}
int main()
{
    vector<string> dict;
    dict.push_back("ARE");
    dict.push_back("DO");
     dict.push_back("DOT");
    dict.push_back("NEWS");
     dict.push_back("NEW");
    dict.push_back("NO");
     dict.push_back("AS");
    dict.push_back("NOT");

    TrieNode* root= new TrieNode();
    for(int i=0;i<dict.size();i++)
    {
        add(dict[i],root);
    }

    cout<<search("ARE", root)<<endl;
    cout<<search("NO", root)<<endl;
    cout<<search("NOT", root)<<endl;
    cout<<search("AS", root)<<endl;
    cout<<search("WIN", root)<<endl;

return 0;
}
