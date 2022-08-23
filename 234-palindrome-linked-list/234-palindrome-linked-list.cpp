/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    bool isPalindrome(ListNode* head) {
        int flag = true;
        vector<int>vec;
        while(head != NULL) {
            vec.push_back(head->val);
            head = head->next;
        }
        if(vec.size() == 0) {
            return true;
        }
        
        for(int i=0; i<vec.size()/2; i++) {
            if(vec[i] != vec[vec.size() - 1 - i]) {
                return false;
            }
        }
        return true;
        
    }
};