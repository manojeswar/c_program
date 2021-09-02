#include<stdio.h>
#include<stdlib.h>

struct list
{
	int data;
	struct list *next;
};

struct queue
{
	struct list *front, *rear;
};

struct list * new_node (int value)
{
	struct list * temp = NULL;

	temp = (struct list *) malloc (sizeof(struct list));
	temp->data = value;
	temp->next = NULL; 
  
	return temp;
}

struct queue * new_queue ()
{
	struct queue * que = NULL;
	
	que = (struct queue *)malloc(sizeof(struct queue));
	que->front = NULL;
	que->rear = NULL;
	
	return que;
}
   

void enqueue (struct queue **head, int value)
{
	struct list *temp = NULL;
	struct queue *current = *head;

	temp = new_node(value);

	if (current->rear == NULL)
	{
		// insert at head if new list
		current->front = temp;
		current->rear = temp;
		return;
	}

	current->rear->next = temp;
	current->rear = temp;
	return;
}

void dequeue ( struct queue *current)
{
	struct list *delete;
	
	if (current->front == NULL) {
		printf("front null return\n");
		return;
	} else {
		delete = current->front;
		current->front = current->front->next;
		free(delete);
	}
	if (current->front == NULL) {
		current->rear = NULL;
	}
}

void print_list (struct queue* head)
{
	struct queue * current = head;
	if (current == NULL)
		return;

	printf("Print List\n");
	while(current != NULL && current->front!= NULL)
	{
		printf("%d   >",current->front->data);
		current->front = current->front->next;
	} 
	printf("NULL\n");
}

int main(void)
{

	struct queue *que = NULL;

	que = new_queue();

	// insert at tail
	enqueue(&que, 10);
	enqueue(&que, 11);
	enqueue(&que, 12);
	enqueue(&que, 14);
	enqueue(&que, 15);

//	print_list(que);
	dequeue(que);
//	print_list(que);
	dequeue(que);
//	print_list(que);
	dequeue(que);
	print_list(que);

	return 0;
}
