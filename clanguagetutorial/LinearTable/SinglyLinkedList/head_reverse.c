#include <stdio.h>
#include <stdlib.h>
typedef struct Link {
	int  elem;
	struct Link *next;
}link;
link * initLink();
void display(link *p);
link * iteration_reverse(link* head);
link * head_reverse(link * head);
link * local_reverse(link * head);

int main() {
	link*p = NULL;
	p = initLink();
	display(p);

	p = iteration_reverse(p);
	display(p);

	p = head_reverse(p);
	display(p);

	p = local_reverse(p);
	display(p);
	return 0;
}

link * initLink() {
	int i = 0;
	link * temp = NULL;
	link * p = (link*)malloc(sizeof(link));
	p->elem = 0;
	p->next = NULL;
	temp = p;
	for (i = 1; i < 5; i++) {
		link *a = (link*)malloc(sizeof(link));
		a->elem = i;
		a->next = NULL;
		temp->next = a;
		temp = temp->next;
	}
	return p;
}
link * iteration_reverse(link* head) {
	if (head == NULL || head->next == NULL || head->next->next == NULL) {
		return head;
	}
	else {
		link * beg = NULL;
		link * mid = head->next;
		link * end = head->next->next;
		while (1)
		{
			mid->next = beg;
			if (end == NULL) {
				break;
			}
			beg = mid;
			mid = end;
			end = end->next;
		}
		head->next = mid;
		return head;
	}
}
link * head_reverse(link * head) {
	link * new_head = (link*)malloc(sizeof(link));
	new_head->elem = 0;
	new_head->next = NULL;
	link * temp = NULL;
	if (head == NULL || head->next == NULL || head->next->next == NULL ) {
		return head;
	}
	while (head->next != NULL)
	{
		temp = head->next;
		head->next = head->next->next;

		temp->next = new_head->next;
		new_head->next = temp;
	}
	return new_head;
}
link * local_reverse(link * head) {
	link * beg = NULL;
	link * end = NULL;
	if (head == NULL || head->next == NULL || head->next->next == NULL) {
		return head;
	}
	beg = head->next;
	end = head->next->next;
	while (end != NULL) {
		beg->next = end->next;
		end->next = head->next;
		head->next = end;
		end = beg->next;
	}
	return head;
}

void display(link *p) {
	link* temp = p->next;
	while (temp) {
		printf("%d ", temp->elem);
		temp = temp->next;
	}
	printf("\n");
}