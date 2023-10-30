#include<iostream>
#include<vector>
#include<unordered_set>
using namespace std;
struct ListNode {
	int val;
	ListNode* next;
	ListNode(int x) : val(x), next(NULL) {}
};

ListNode* detectCycle(ListNode* head)
{
	unordered_set<ListNode*> set;
	while (head != nullptr) {
		if (!set.count(head)) {
			set.insert(head);
		}
		else {
			return head;
		}
		head = head->next;
	}
	return nullptr;
}

ListNode* detectCycle(ListNode* head)
{
	if (head == nullptr)return head;
	ListNode* ptr1 = head;
	ListNode* ptr2 = head;
	do {
		ptr1 = ptr1->next;
		if (ptr2->next == nullptr || ptr2->next->next == nullptr) {
			return nullptr;
		}
		ptr2 = ptr2->next->next;
	} while (ptr1 != ptr2);
	ptr1 = head;
	while (ptr1 != ptr2) {
		ptr1 = ptr1->next;
		ptr2 = ptr2->next;
	}
	return ptr2;
}
