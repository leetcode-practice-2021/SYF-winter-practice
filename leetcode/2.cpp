//
// 2. 两数相加
// Created by 师域飞 on 2021/2/2.
//

struct ListNode {
    int val;
    ListNode *next;

    ListNode() : val(0), next(nullptr) {}

    ListNode(int x) : val(x), next(nullptr) {}

    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode *addTwoNumbers(ListNode *l1, ListNode *l2) {
        ListNode *p = nullptr;
        ListNode *sum = p;
        int carry = 0;
        int s = 0;
        while (l1 != nullptr || l2 != nullptr) {
            s = l1->val + l2->val + carry;
            s = s % 10;
            carry = s / 10;
            sum->val = s;
            sum->next = sum;
            sum->next = nullptr;
            l1=l1->next;
            l2=l2->next;
        }
        if (l1 == nullptr && l2 == nullptr) {
            if (carry > 0) {
                sum->val = 1;
                sum->next= nullptr;
            }
        } else if (l1== nullptr){
            sum->val=l2->val+carry;
            sum->next=sum;
            sum->next= nullptr;
            l2=l2->next;
            while (l2!= nullptr){
                sum->val=l2->val;
                sum->next=sum;
                sum->next= nullptr;
                l2=l2->next;
            }
        }
        else {
            sum->val=l1->val+carry;
            sum->next=sum;
            sum->next= nullptr;
            l1=l1->next;
            while (l1!= nullptr){
                sum->val=l1->val;
                sum->next=sum;
                sum->next= nullptr;
                l1=l1->next;
            }
        }
        return p;
    }
};

/**
 * class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode *head = nullptr, *tail = nullptr;
        int carry = 0;
        while (l1 || l2) {
            int n1 = l1 ? l1->val: 0;
            int n2 = l2 ? l2->val: 0;
            int sum = n1 + n2 + carry;
            if (!head) {
                head = tail = new ListNode(sum % 10);
            } else {
                tail->next = new ListNode(sum % 10);
                tail = tail->next;
            }
            carry = sum / 10;
            if (l1) {
                l1 = l1->next;
            }
            if (l2) {
                l2 = l2->next;
            }
        }
        if (carry > 0) {
            tail->next = new ListNode(carry);
        }
        return head;
    }
};
 */