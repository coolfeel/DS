#include <stdio.h>
#include <malloc.h>

typedef struct node {
	int data;
	struct node *next;
}NODE,*pNODE;

bool initList(pNODE pnode);
bool insertList(pNODE pHead,int i,int e);
void traverse(pNODE pHead); 

int main() {
	pNODE pHead=NULL;
	NODE node;
	pHead=&node;
	
	if (initList(pHead)) {
		printf("成功");
		if (insertList(pHead,1,2)) {
			printf("插入成功");
			if (insertList(pHead,2,3)) {
				printf("插入成功");	
			}
		}
		traverse(pHead);	 
	}			
	return 0;
} 

bool initList(pNODE pHead) {
	pHead=(pNODE)malloc(sizeof(NODE));
	if (!pHead)
		return false;
	pHead->next=NULL;
	
	return true;	
}

bool insertList(pNODE pHead,int i,int e) {
	int j=0;
	pNODE p=pHead,newNode=NULL;
	
	while (p&&j<i-1) {
		p=p->next;
		j++;
	}
	
	if (!p||j>i-1) {
		return false;
	}
	
	newNode=(pNODE)malloc(sizeof(NODE));
	newNode->data=e;
	if (p->next!=NULL)
		printf("11");
	newNode->next=p->next;
	p->next=newNode;
	return true;
}

void traverse(pNODE pHead) {
	pNODE p=pHead->next;
	while (p!=NULL) {
		printf("%d",p->data);
		p=p->next;
	}
} 
