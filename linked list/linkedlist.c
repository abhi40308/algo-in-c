#include <stdio.h>
#include <stdlib.h>
struct  node
{
	int data;
	struct node *next;
}*newnode,*temp;
struct node *start=NULL,*end = NULL;
struct node* create(int a)
{
	newnode = (struct node*)malloc(sizeof(struct node));
	newnode->data=a;
	newnode->next = NULL;
	return newnode;
}
void insert_beg()
{	int x;
	printf("Enter data:  ");
	scanf("%d",&x);
	newnode = create(x);
	if(start == NULL)
		{start = newnode;
			end=newnode;}
	else
	{newnode ->next = start;
		start = newnode;}
}
void insert_end()
{
	int x;
	printf("Enter data:  ");
	scanf("%d",&x);
	newnode = create(x);
	if(end == NULL)
	{
		end=newnode;
		start = newnode;
	}
	else{
		end -> next =newnode;
		end = newnode;
	}
}
struct node* search(int pos)
{	struct node *flag=start;
	if(flag == NULL)
		return NULL;
	for(int i=2;i<pos;i++)
	{
		flag = flag->next;
		if(flag==NULL)
			break;
	}
	return flag;
}
void insert_mid()
{
	int x,pos;
	printf("Enter data:  ");
	scanf("%d",&x);
	printf("Enter position:   ");
	scanf("%d",&pos);
	newnode = create(x);
	temp = search(pos);
	if(temp == NULL)
		printf("Wrong choice!!!!");
	else
	{newnode ->next = temp ->next;
	temp ->next =newnode;}
}
void print()
{
	struct node *flag=start;
	for(int i=0;;i++)
	{	printf("%d",flag->data); printf("  ->   ");
		flag = flag->next;
		if(flag==NULL)
			break;
	}
}
void delete_pos()
{   int pos;
    printf("Enter position:   ");
    scanf("%d",&pos);
    temp = search(pos);
    if(temp == NULL)
        printf("Wrong choice!!!!");
    else
    {
        newnode  = temp -> next;
        temp ->next = newnode -> next;
        free(newnode);
    }
}
void update_val()
{
    int x,pos;
    printf("Enter new data:  ");
    scanf("%d",&x);
    printf("Enter position:   ");
    scanf("%d",&pos);
    temp = search(pos);
    if(temp == NULL)
        printf("Wrong choice!!!!");
    else
    { newnode = temp -> next;
        newnode->data = x;
    }
}
void search_elem()
{
    int x,pos=0,q=1;
    printf("Enter data to be searched:  ");
    scanf("%d",&x);
    struct node *flag=start;
            for(;flag!=NULL;)
            {   pos++;
                if(flag-> data == x)
                    {   q=0; break; }
                flag = flag->next;
            }
            if(q)
                {  printf("\nData not found!!!!"); }
            else
            printf("\nData found at position %d",pos);
}
void sorted_ascend()
{
    struct node *flag=start;
            for(;flag!=NULL;)
            {   
                for(temp = flag->next;temp!=NULL;)
                {
                    if(flag->data > temp ->data)
                    {
                        int x=flag->data;
                        flag->data = temp->data;
                        temp->data = x;
                    }
                    temp = temp->next;
                }
                flag = flag->next;
            }
}
int main()
{
	int ch;
    char ans = 'Y';
 
    while (ans == 'Y'||ans == 'y')
    {
    	printf("\n---------------------------------\n");
        printf("\nOperations on singly linked list\n");
        printf("\n---------------------------------\n");
        printf("\n1.Insert node at first");
        printf("\n2.Insert node at last");
        printf("\n3.Insert node at position");
        printf("\n4.Sort Linked List in Ascending Order");
        printf("\n5.Delete Node from any Position");
        printf("\n6.Update Node Value");
        printf("\n7.Search Element in the linked list");
        printf("\n8.Display List from Beginning to end");
        printf("\n10.Exit\n");
        printf("\n~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
        printf("\nEnter your choice:   ");
        scanf("%d", &ch);
        switch (ch)
        {
        case 1: 
            printf("\n...Inserting node at first...\n");
            insert_beg();
            break;
        case 2: 
            printf("\n...Inserting node at last...\n");
            insert_end();
            break;
        case 3: 
            printf("\n...Inserting node at position...\n");
            insert_mid();
            break;
        case 4: 
            printf("\n...Sorted Linked List in Ascending Order...\n");
            sorted_ascend();
            print();
            break;
        case 5: 
            printf("\n...Deleting Node from any Position...\n");
            delete_pos();
            break;
        case 6: 
            printf("\n...Updating Node Value...\n");
            update_val();
            break;
        case 7: 
            printf("\n...Searching Element in the List...\n");
            search_elem();
            break;
        case 8: 
            printf("\n...Displaying List From Beginning to End...\n");
            print();
            break;
        case 10: 
            printf("\n...Exiting...\n");
            exit(1);
        default: 
            printf("\n...Invalid Choice...\n");
            break;
        }
        printf("\nYOU WANT TO CONTINUE (Y/N)");
        scanf(" %c", &ans);
    }
    return 0;
}