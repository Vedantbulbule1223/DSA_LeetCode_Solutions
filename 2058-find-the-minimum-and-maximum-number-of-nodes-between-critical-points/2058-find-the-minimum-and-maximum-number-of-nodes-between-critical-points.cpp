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
    vector<int> nodesBetweenCriticalPoints(ListNode* head) {
        vector<int>ans = {-1 , -1};

        if(!head || !head->next || !head->next->next){
            return ans;
        }
        ListNode* prevNode = head;
        ListNode* curr =  head->next;
        int pos = 1;
        int first =  -1;
        int prevC = -1;
        int minD = INT_MAX;

        while(curr->next != nullptr){
            ListNode* nextNode =  curr->next;

            bool isMax =  curr->val > prevNode->val && curr->val > nextNode->val;
            bool isMin =  curr->val < prevNode->val && curr->val < nextNode->val;

            if(isMax || isMin) {
                if(first == -1){
                    first =  pos;
                }else {
                    minD = min(minD , pos-prevC);
                }

                prevC = pos;
            }
            prevNode = curr;
            curr = nextNode;
            pos++;


        }
        if(first == -1 || first == prevC){
            return ans;
        }
        int maxD = prevC - first;

        return{minD , maxD};
    }
};