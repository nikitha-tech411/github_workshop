#include<stdio.h>
#include<stdlib.h>
struct Node
{
	struct Node *prev;
	int data;
	struct Node *next;
};
struct Node *insertAtBeginning(struct Node *head,int value)
{
	struct Node *temp=(struct Node *)malloc(sizeof(struct Node));
	temp->data=value;
	temp->prev=NULL;
	temp->next=head;
	if(head!=NULL)
	head->prev=temp;
	return temp;
}
struct Node *deleteAtBeginning(struct Node * head )
{
	if(head==NULL)
	{
		printf("list is empty\n");
		return head;
	}
	struct Node *temp=head;
	head=head->next;
	if(head!=NULL)
	head->prev=NULL;
	free(temp);
	return head;
}
struct Node *deleteAtEnd(struct Node *head)
{
	if(head==NULL)
	{
		printf("list is empty\n");
		return head;
	}
	struct Node *p=head;
	if(p->next==NULL)
	{
		free(p);
		return NULL;
	}
	while(p->next!=NULL)
	p=p->next;
	p->prev->next=NULL;
	free(p);
	return head;
}
struct Node *deleteAtPosition(struct Node *head,int pos)
{
	if(head==NULL)
	{
		printf("list is empty\n");
		return head;
	}
	struct Node *p=head;
	int i=1;
	if(pos==1)
	{
		head=head->next;
		if(head!=NULL)
		head->prev=NULL;
		free(p);
		return head;
	}
	while(i<pos-1&&p->next!=NULL)
	{
		p=p->next;
		i++;
	}
	if(p->next==NULL)
	{
		printf("invalid position\n");
		return head;
	}
	struct Node *temp=p->next;
	p->next=temp->next;
	if(temp->next!=NULL)
	temp->next->prev=p;
	free(p);
	return head;
}
void display(struct Node *head)
{
	if(head==NULL)
	{
		printf("list is empty\n");
		return;
	}
	struct Node *p=head;
	printf("DLL");
	while(p!=NULL)
	{
		printf("%d<->",p->data);
		p=p->next;
	}
	printf("NULL\n");
}
int main()
{
	struct Node *head=NULL;
	int choice,value,pos;
	while(1)
	{
		printf("\n...DLLM...\n");
		printf("1.insert at beginning\n");
		printf("2.delete at beginning\n");
		printf("3.delete at end\n");
		printf("4.delete at position\n");
		printf("5.display\n");
		printf("6.exit\n");
		printf("enter choice:");
		scanf("%d",&choice);
		switch(choice)
		{
			case 1:
				printf("enter value:");
				scanf("%d",&value);
				head=insertAtBeginning(head,value);
				break;
			case 2:
			    head=deleteAtBeginning(head);
				break;
			case 3:
			    head=deleteAtEnd(head);
				break;
			case 4:
			    printf("enter position:");
				scanf("%d",&pos);
				head=deleteAtPosition(head,pos);
				break;
			case 5:
				display	(head);
				break;
			case 6:
			    exit(0);
			default:
				printf("invalid choice\n");
									
		}
	}
}