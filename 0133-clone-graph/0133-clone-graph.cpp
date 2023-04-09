class Solution {
public:
    unordered_map<Node* , Node*> mp; 
    Node* cloneGraph(Node* node) {
        if(node == NULL) 
        {
            return NULL;
        }
        
 
        if(mp.find(node) == mp.end()) // if not present in map
        {
            mp[node] = new Node(node -> val, {}); // make a copy
            
            for(auto adj: node -> neighbors) // travel in adjcant
            {
                mp[node] -> neighbors.push_back(cloneGraph(adj)); //add copy
            }
        }
        
        return mp[node];
        
    }
};
