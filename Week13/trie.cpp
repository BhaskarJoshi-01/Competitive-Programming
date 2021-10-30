#include<bits/stdc++.h>
using namespace std;

struct trie{
    struct trie *alpha[26];
    bool isEnd;
};

void insert_trie(string s,struct trie* head){
    struct trie* temp = head;
    for(int i=0;i<s.size();i++){
        if(temp->alpha[s[i]-'a']==NULL){
            struct trie* temp2 = (struct trie*)malloc(sizeof(struct trie));
            temp->alpha[s[i]-'a'] = temp2;
            temp = temp2;
        }
        else{
            temp = temp->alpha[s[i]-'a'];

        }
        if(i == s.size()-1){
            temp->isEnd = true;
        }
    }
}

void print_trie(struct trie* head,string s){
    if(head->isEnd){
        cout<<s<<" ";
    }
    for(int i=0;i<26;i++){
        if(head->alpha[i]!=NULL){
            char t = (char)(i+'a');
            print_trie(head->alpha[i],s+t);
        }
    }
}

int main(){
    int n;cin>>n;
    struct trie *head = (struct trie*)malloc(sizeof(struct trie));
    for(int i=0;i<n;i++){
        string s;cin>>s;
        transform(s.begin(),s.end(),s.begin(),::tolower);
        insert_trie(s,head);
    }
    print_trie(head,"");
    cout<<"\n";
}
