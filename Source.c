#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <windows.h>

typedef struct student {
	int score;
	struct student* next;
}LinkList;
void see(LinkList* link);
LinkList* creat(int n);
LinkList* insert(LinkList *link);
LinkList* del(LinkList * link);
LinkList* add(LinkList* link);
LinkList* change(LinkList * link,int n);
int main() {
	LinkList * ll = creat(3);

	add(ll);
	see(ll);
	del(ll);
	see(ll);
	insert(ll);
	see(ll);
	system("pause");
	return 0;
}


LinkList* creat(int n) { //n is the number of linked list nodes
	 
	LinkList* head, * node, * end; 
	head = (LinkList*)malloc(sizeof(LinkList)); //malloc struct memory size
	end = head; //headcode  head is invariant all the time
	printf("in-end-> %d\n", end->score);

	for (int i = 0; i < n; i++) {
		node = (LinkList*)malloc(sizeof(LinkList)); //normal node allocation
		scanf("%d", &node->score);
		end->next = node; //The end next is new node
		printf("in-in-end-> %d\n", end->score);


		end = node; //end is new nodes
		printf("in-in-in-end-> %d\n", end->score);


	}
	end->next = NULL; //end up creating
	printf("end-> %d\n", end->score);
	printf("head-> %d\n", head->score);
	return head;
}

LinkList* add(LinkList * link) {

	LinkList* node;
	node = (LinkList*)malloc(sizeof(LinkList));
	while (link->next != NULL) { //only to the last linked list member  it need next -> NULL
		link = link->next;
	}
	printf("enter num:");
	scanf("%d", &node->score); //given a score value
	link->next = node; //can not give a node->score  it need alloc memory space  else it will memory unsafe
	link->next->next = NULL; //set next memory spece null
	return link;
}

LinkList* del(LinkList* link) {
	
	int num = 0;
	printf("enter num:");
	scanf("%d", &num);
	
    LinkList* p = NULL,*p2=NULL,*p3=NULL; //from 2 nodes set out
	p = link;
	//no elements
	if (p == NULL) {
		printf("LinkList is empty!");
		system("pause");
		return 0;
	}
	else {
		//When > 1 nodes
		printf("> 1 nodes");
		while (p->next != NULL) {
			p2 = p->next;
			//		p3 = p2->next;
			if (p2->score == num) {
				printf("Coordinate");
				p->next = p2->next;
				free(p2);
				return 0;
			}

			p = p->next;
		}

	}

	return link;
}

void see(LinkList * link) {
	while (link->next != NULL) {
		link = link->next;
		printf("Score: %d \n",link->score);
	}
}

LinkList* insert(LinkList * link) {

	//create new node

	LinkList* head,*node;
	head = link;
	
	node = (LinkList*)malloc(sizeof(LinkList));
	printf("Where num you want to append:\n");
	int num;
	scanf("%d",&num);


	printf("What num you want to add\n");
	int num2;
	scanf("%d", &num2);
	node->score = num2;
	while (link->next != NULL) {
		link = link->next;
		if (link->score == num) {
			node->next = link->next;
			link->next = node;
			printf("append successfully!\n");
		}

	
	}
	
	return head;
}