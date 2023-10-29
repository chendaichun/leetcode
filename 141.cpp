#include<iostream>
#include<vector>
#include<unordered_set>
using namespace std;

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

bool hasCycle(ListNode* head)
{
	unordered_set<ListNode*> set;
	while (head != nullptr) {
		if (!set.count(head)) {
			set.insert(head);
		}
		else {
			return true;
		}
		head = head->next;
	}
	return false;
}

