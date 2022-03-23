https://www.interviewbit.com/problems/clone-graph/

/**
 * Definition for undirected graph.
 * struct UndirectedGraphNode {
 *     int label;
 *     vector<UndirectedGraphNode *> neighbors;
 *     UndirectedGraphNode(int x) : label(x) {};
 * };
 */
map<UndirectedGraphNode*, UndirectedGraphNode*>cloned;

UndirectedGraphNode *Solution::cloneGraph(UndirectedGraphNode *node) {
    if(!node) return NULL;
    if(cloned.find(node) != cloned.end()) return cloned[node];
    UndirectedGraphNode* clone = new UndirectedGraphNode(node->label);
    cloned[node]=clone;
    for(auto child: node->neighbors) {
        UndirectedGraphNode* clonedChild = cloneGraph(child);
        clone->neighbors.push_back(clonedChild);
    }
    return clone;
}
