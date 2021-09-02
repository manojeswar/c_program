#include<stdio.h>
#include<stdlib.h>

struct list
{
	int data;
	struct list *next;
};

struct list * new_node (int value)
{
	struct list *temp = NULL;

	temp = (struct list *) malloc (sizeof(struct list));
	temp->data = value;
	temp->next = NULL; 
  
	return temp;
}
   

void insert_tail (struct list **head, int value)
{
	struct list *temp = NULL;
	struct list *current = *head;

        temp = new_node(value);

	if (*head == NULL)
	{
		*head = temp;
		return;
	}

	while(current->next != NULL) {
		current = current->next;
	} 

	current->next = temp;
	return;
}

void insert_beginning (struct list **head, int value)
{

	struct list *temp = NULL;
	struct list *current = *head;

	temp = (struct list *) malloc (sizeof(struct list));
	temp->data = value;
	temp->next = current;

	*head = temp;

}

void insert_between (struct list **head, int value, int pos)
{

	struct list *temp = NULL;
	struct list *current = *head;
	int local_count = 1;

	temp = (struct list *) malloc (sizeof(struct list));
	temp->data = value;
	temp->next = NULL;

	if ( pos == local_count )
	{
		insert_beginning(head,value);
	} else {
		while((current!=NULL) && (pos!=local_count+1))
		{
			current = current->next;
			local_count = local_count + 1;
		}

		temp->next = current->next;
		current->next = temp;
	}


}

void delete_value (struct list ** head, int value)
{
	struct list *current = *head;
	struct list *delete = NULL;
	struct list *prev;

	if(current == NULL) {
		printf("No List\n");
		return;
	} else if ((current != NULL) && (current->data == value)) { 
		*head = current->next;
		free(current);
		current = NULL;
		return;
	}

	while ( current!= NULL && (current->data!=value))
	{
		prev = current;
		current = current->next;
	}
	
	if (current == NULL)
		return;

	if(current->data == value)
	{
		prev->next = current->next;
		free(current);
		current = NULL;
		return;
	}
}

void print_list (struct list* head)
{
	if (head == NULL)
		return;

	printf("Print List\n");
	while(head != NULL && head->next!= NULL)
	{
		printf("%d   >",head->data);
		head = head->next;
	} 
	printf("%d\n",head->data);
}

int main(void)
{

	struct list *head = NULL;

	// insert at tail
	insert_tail(&head, 10);
	insert_tail(&head, 11);
	insert_tail(&head, 12);
	insert_tail(&head, 14);
	insert_tail(&head, 15);

	// insert at head
	insert_beginning(&head, 9);
	insert_beginning(&head, 8);

	// insert at specific position
	insert_between(&head,13,5);
	insert_between(&head,1,1);
	insert_between(&head,2,2);

	print_list(head);

	delete_value(&head,15);
	print_list(head);
	delete_value(&head,2);
	print_list(head);
	delete_value(&head,1);
	print_list(head);

	return 0;
}
