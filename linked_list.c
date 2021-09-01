#include<stdio.h>
#include<stdlib.h>

struct list
{
   int data;
   struct list *next;
};

void insert (struct list **head, int value)
{
  struct list *temp = NULL;
  struct list *current = *head;

  temp = (struct list *)malloc (sizeof(struct list));
  temp->data = value;
  temp->next = NULL; 
 
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

void print_list (struct list* head)
{
  while(head != NULL)
  {
    printf("%d   >",head->data);
    head = head->next;
  } 

}

int main()
{

  struct list *head = NULL;

  insert(&head, 10);
  insert(&head, 11);
  insert(&head, 12);
  insert(&head, 14);
  insert(&head, 15);
  insert_beginning(&head, 9);
  insert_beginning(&head, 8);
  insert_between(&head,13,5);

  print_list(head);

return 0;
}
