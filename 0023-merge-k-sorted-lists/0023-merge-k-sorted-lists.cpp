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

    struct compnod{
        bool operator()(ListNode* const& p1, ListNode* const& p2){
            return p1->val > p2->val;
        }

    };
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        priority_queue<ListNode*,vector<ListNode*>,compnod>pq;
        int n=lists.size();
        for(int i=0;i<n;i++)if(lists[i]!=NULL)pq.push(lists[i]);
        ListNode* ans=new ListNode(0);
        auto temp=ans;
        while(!pq.empty()){
            auto node=pq.top();
            pq.pop();
            temp->next = node;
            temp = node;
            if(node->next!=NULL)pq.push(node->next);
        }
        return ans->next;
        
    }
};