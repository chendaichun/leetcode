#include<iostream>
#include<vector>
struct ListNode {
	int val;
	ListNode* next;
	ListNode(int x) : val(x), next(NULL) {}
};

bool hasCycle(ListNode* head, int pos)
{
	ListNode* ptr1 = head;
	ListNode* ptr2 = head;
	do {
		ptr1 = ptr1->next;
		ptr2 = ptr2->next->next;
		if (ptr2->val == pos) {
			return false;
		}
	} while (ptr1 != ptr2);
	return true;
}

