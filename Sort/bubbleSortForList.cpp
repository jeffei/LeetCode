void bubbleSortForList(ListNode* head){
	if(!head||!head->next) return;
	for(ListNode* i=head;i->next;i=i->next){
		for(ListNode* j=head;j->next;j=j->next){
			if(j->val>j->next->val) 
				swap(j->val,j->next->val);
		}
	}
}
