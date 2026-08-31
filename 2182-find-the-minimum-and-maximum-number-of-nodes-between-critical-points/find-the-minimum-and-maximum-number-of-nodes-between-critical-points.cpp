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
        ListNode* temp=head->next;
        vector<int>ans;
        int cnt=1;
        if(head->next==NULL || head->next->next==NULL){
            return {-1,-1};
        }
        while(temp->next!=NULL){
            if(temp->val>head->val && temp->val>temp->next->val ||
                temp->val<head->val && temp->val<temp->next->val ){
                    ans.push_back(cnt);
                }
                temp=temp->next;
                head=head->next;
                cnt++; 
        }
        int n=ans.size();
        if(n < 2) {
        return {-1, -1};
    }

    int mini = INT_MAX;
    for(int i = 1; i < n; i++) {
        mini = min(mini, ans[i] - ans[i-1]);
    }
    int maxi=ans[n-1]-ans[0];
        return {mini,maxi};
    }
};