 /**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

// Method 1: Merge the first two Lists in "vector Lists", place it in cur new indx in vector lists.
//          do this Iteratively, untill only one list int vector list, aka maxium cur new idx is 0 
//          time complexity is O(?).
class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        int k = lists.size();
        if (k == 0)
            return nullptr;
        if (k == 1)
            return lists[0];
        int i=0, j=0;
        int curK = k, nextK = 0;
        while (curK > 1) {
            for (i=0, j=1; j<curK; j+=2, i+=2) {
                lists[nextK++] = mergeList(lists[i], lists[j]);
            }
            if (i<curK)
                lists[nextK++] = lists[i];
            curK = nextK;
            nextK = 0;
        }
        return lists[0];
        
    }
    ListNode* mergeList(ListNode *head1, ListNode *head2) {
        if (head1 == nullptr)
            return head2;
        if (head2 == nullptr)
            return head1;
        if (head1->val <= head2->val) {
            head1->next = mergeList(head1->next, head2);
            return head1;
        }
        else {
            head2->next = mergeList(head1, head2->next);
            return head2;
        }
    }
};

//  Method 2: maintain "A min-Heap" which holds lists' head node, nullptr is considered as minium node
//          every time pop the minium node from heap, add the second node of list, and push_heap().
//          if the list does not have a second node, pop_back from the vector lists.
//          do this Iteratively, till every node has been handled. time complexity is O(nlogk).
class Solution {
public: 
    ListNode *mergeKLists(vector<ListNode *> &lists) {
        ListNode *newHead = nullptr;
        ListNode *newEnd = nullptr;
        auto comp = [](ListNode *a ,ListNode *b){
             if (a == nullptr) return false;
             else if (b == nullptr) return true;
             else return a->val > b->val;
        };
        make_heap(lists.begin(), lists.end(), comp);
        while (!lists.empty()) {
            pop_heap(lists.begin(), lists.end(), comp);
            if (lists.back() == nullptr) {
                lists.pop_back();
                continue;
            }
            if (newHead == nullptr) {
                newHead = lists.back();
                newEnd = newHead;
                // newEnd->next = nullptr;
            }
            else {
                newEnd->next = lists.back();
                newEnd = newEnd->next;
                // newEnd->next = nullptr;
            }
            if (lists.back()->next == nullptr) {
                lists.pop_back();
            }
            else {
                lists[lists.size()-1] = lists.back()->next;
                push_heap(lists.begin(), lists.end(), comp);
            }
        }
        if (newEnd != nullptr)
            newEnd->next = nullptr;
        return newHead;
    }
};