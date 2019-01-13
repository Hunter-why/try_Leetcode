// Method 1: Recursively, split one list to two sublists via traversal, then sort and merge 
class Solution {
public:
    ListNode *sortList(ListNode *head) {
        if (head ==nullptr || head->next == nullptr)    // one or nothing
            return head;
        ListNode *front, *back;
        splitList(head, front, back);   // return front half and back half as "front" and "back", respectively. 
        front = sortList(front);        // sort front half list
        back = sortList(back);          // sort back half list

        return mergeList(front, back);  // merge two sorted list and return head
    }

    void splitList(listNode *head, ListNode *& front, listNode *& back) {
        ListNode *slow = head;
        ListNode *fast = head->next;

        while (fast != nullptr) {
            fast = fast->next;
            if (fast != nullptr) {
                fast = fast->next;
                slow = slow->next;
            }
        }
        front = head;
        back = slow->next;
        slow->next = nullptr;
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

// Method 2: Solve this Iteratively. An method according to STL LIST::sort()
//          the counter idea mentioned by Alex in "efficient programming using component".
class Solution {
public: 
    ListNode *sortList(ListNode *head) {
        if (head == nullptr || head->next == nullptr)
            return head;
        ListNode *carry;
        vector<ListNode *> counter(64, nullptr); //the counter, counter[i] for a list, the length of which is 2 ^ i.
        int fill = 0;   //current counter idx
        while (head != nullptr) {               // for every node
            carry = head;
            head = head->next;
            carry->next = nullptr;
            int i=0;
            while (i < fill && counter[i] != nullptr) {
                counter[i] = mergeList(carry, counter[i]);
                carry = nullptr;
                swap(carry, counter[i++]);
            }
            swap(carry, counter[i]);
            if (i == fill)
                ++fill;
        }
        for (int i=i; i<fill; ++i)
            counter[i] = mergeList(counter[i], counter[i-1]);
        return counter[fill-1];
    }

    void swap(ListNode *&l1, ListNode *&l2) {
        ListNode *tmp = l1;
        l1=l2;
        l2=tmp;
    }

    ListNode *mergeList(ListNode *head1, ListNode *head2) {
        if (head1 == nullptr)
            return head2;
        if (head2 == nullptr)
            return head1;
        if (head1->val <= head2->val) {
            ListNode *tmp = head1;
            head1->next = mergeList(head1->next, head2);
            return tmp;
        }
        else {
            ListNode *tmp = head2;
            head2->next = mergeList(head1, head2->next);
            return tmp;
        }
    }
    
};