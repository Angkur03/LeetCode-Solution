/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};
*/

class Solution {
public:
    Node* connect(Node* root) {
        if(root == NULL) return root;
        
        queue<Node*> qq;
        qq.push(root);
        
        while(!qq.empty()) {
            int size = qq.size();
            Node* last = NULL;
            
            while(size--) {
                Node* top = qq.front(); 
                qq.pop();
                if(top->right) qq.push(top->right);
                if(top->left) qq.push(top->left);
                top->next = last;
                last = top;
                //cout<<top->val<<" "<<last->val<<endl;
            }
        }
        return root;
    }
};