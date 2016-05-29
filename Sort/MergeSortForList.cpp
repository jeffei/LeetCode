ListNode* MergeSort(ListNode* h1,ListNode* h2){
	ListNode dummy(INT_MIN);
	for(ListNode* p=&dummy;h1||h2;p=p->next){
		int val1=h1? h1->val : INT_MAX;
		int val2=h2? h2->val : INT_MAX;
		if(val1<val2){p->next=h1;h1=h1->next;}
		else{p->next=h2;h2=h2->next;}
	}
	return dummy.next;
}
ListNode* Guibin(ListNode* head){
	if(!head|| !head->next) return head;
	ListNode *fast=head, *slow=head;
	while(fast&&fast->next&&fast->next->next){
		fast=fast->next->next;
		slow=slow->next;
	}
	ListNode* head2=slow->next;
	slow->next=nullptr;
	ListNode* n1=Guibin(head);
	ListNode* n2=Guibin(head2);
	return MergeSort(n1,n2);
}

