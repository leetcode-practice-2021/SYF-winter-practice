//
// 19. 删除链表的倒数第 N 个结点
// Created by 师域飞 on 2021/1/27.
//

//进阶：你能尝试使用一趟扫描实现吗？

struct ListNode {
     int val;
     ListNode *next;
     ListNode() : val(0), next(nullptr) {}
     ListNode(int x) : val(x), next(nullptr) {}
     ListNode(int x, ListNode *next) : val(x), next(next) {}
    };

class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode*p=head;
        ListNode *q=head;
        int index=0;
        while (p!= nullptr){
            p=p->next;
            if (p == nullptr && index<1)
                return nullptr;
            if(index++>n){
                q=q->next;
            }
        }
        if (q==head){
            head=head->next;
        }
        q->next=q->next->next;
        return head;
    }
};