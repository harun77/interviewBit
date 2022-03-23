https://www.interviewbit.com/problems/largest-distance-between-nodes-of-a-tree/

class Node {
public: 
    int label;
    vector<Node*> child;
    Node(int x) {
        this->label = x;
    }
};

int ans;

int maxDepth(Node* root) {
    int first=0, second=0;
    for(auto node:root->child) {
        int length = maxDepth(node)+1;
        if(length>first) {
            second=first;
            first=length;
        } else if(length>second) second=length;
    }
    ans=max(ans, first+second);
    return first;
}

int Solution::solve(vector<int> &A) {
    int N=A.size();
    vector<Node*>nodes;
    for(int i=0;i<N;i++) nodes.push_back(new Node(i));
    Node *root;
    for(int i=0;i<N;i++) {
        if(A[i]==-1) root = nodes[i]; 
        else nodes[A[i]]->child.push_back(nodes[i]);
    }
    ans=0;
    maxDepth(root);
    return ans;
}
