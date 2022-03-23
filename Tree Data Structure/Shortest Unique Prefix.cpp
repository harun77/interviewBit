https://www.interviewbit.com/problems/shortest-unique-prefix/

struct Node {
    int f;
    Node* next[26];

    Node() {
        f = 0;
        for(int i=0; i<26; i++) next[i] = NULL;
    }
};

void add(Node* root, string s, int idx) {
    if(idx==s.size()) return;

    int id = s[idx] - 'a';
    if(!root->next[id]) root->next[id] = new Node();
    ++root->next[id]->f;
    add(root->next[id], s, idx+1);
}

int find(Node* root, string s, int idx) {
    if(idx == s.size()) return idx;
    int id = s[idx] - 'a';
    if(root->next[id]->f == 1) return idx+1;
    return find(root->next[id], s, idx+1);
} 

vector<string> Solution::prefix(vector<string> &A) {
    vector<string>dict;
    Node* root = new Node();
    for(auto s:A) add(root, s, 0);
    for(auto s:A) { 
        int L = find(root, s, 0);
        dict.push_back(s.substr(0, L));
    }    
    return dict;
}
