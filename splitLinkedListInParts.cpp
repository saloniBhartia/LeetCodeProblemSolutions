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
    int getLength(ListNode* head) {
        int len =0;
        while(head) {
            head = head->next;
            ++len;
        }
        return len;
    }
    
    ListNode* findAt(ListNode* root, int pos) {
        for(int i=0;i<pos;i++) {
            root = root->next;
        }
        return root;
    }
public:
    vector<ListNode*> splitListToParts(ListNode* root, int k) {
        vector<ListNode*> target;
        int len = getLength(root);
        int numOfNodes=1,extraNodes=0;
        ListNode* ptr;
        int i=0, addExtraNode;
    
        if(k<len) {
            numOfNodes= len/k;
            extraNodes = len%k;
        }
        
        while(root) {
           addExtraNode =0;
           if(extraNodes>0) {
               addExtraNode =1;
           }
            target.push_back(root);
            ptr = findAt(root, numOfNodes+addExtraNode-1);
            --extraNodes;
            root = ptr->next;
            ptr->next = NULL;
        }
        
        while(target.size()<k) {
            target.push_back(NULL);
        }
        return target;
    }
};