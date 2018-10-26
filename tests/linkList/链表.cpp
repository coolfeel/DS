#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>

typedef struct Node {
	int data;
	struct Node *pNext;
}NODE,*PNODE; 

	
PNODE create_list();
void traverse_list(PNODE pHead);
bool is_empty(PNODE pHead); 
int length_list(PNODE);
bool insert_list(PNODE,int,int);
bool delete_list(PNODE,int,int *);
void sort_list(PNODE);


int main() {
	PNODE pHead=NULL;
	pHead=create_list();
	traverse_list(pHead);
	return 0;
}


PNODE create_list() {
	int len;								//有效节点长度 
	int i;
	int val;								//存放临时输入的节点值
	
	PNODE pHead=(PNODE)malloc(sizeof(NODE));
	if (pHead==NULL) {
		printf("内存分配失败");
		exit(-1);
	}
	
	PNODE pTail=pHead;                     //设置当前尾节点 
	pTail->pNext=NULL; 
	
	printf("请输入节点个数：len=");
	scanf("%d",&len);
	
	for (i=0;i<len;i++) {
		printf("请输入第%d个节点的值:",i+1);
		scanf("%d",&val);
		
		PNODE pNew=(PNODE)malloc(sizeof(NODE));
		
		if (pNew==NULL) {
			printf("内存分配失败");
			exit(-1);
		}
		
		//pNew->data=val;
		//pHead->pNext=pNew;      全部是头指向新节点 
		//pNew->pNext=NULL; 
		
		pNew->data=val;           
		pTail->pNext=pNew;        //pTail是当前尾节点 
		pNew->pNext=NULL;
		pTail=pNew; 
	} 
	
	return pHead;
}


void traverse_list(PNODE pHead) {
	PNODE p=pHead->pNext;
	while(p!=NULL) {
		printf("%d",p->data);
		p=p->pNext;
	}
	printf("\n");
}


bool is_empty(PNODE pHead) {
	if (pHead->pNext==NULL) 
		return true;
	else 
		return false;
}


int length_list(PNODE pHead) {
	PNODE p=pHead->pNext;
	int len=0;
	while(p!=NULL) {
		len+=1;
		p=p->pNext;
	}
	return len;
}
