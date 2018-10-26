#include <stdio.h>
#include <stdlib.h>

typedef struct lNode {
	int data;
	struct lNode *next;
}lNode,*linkList;

int main() {
	return 0;
}

linkList initList(linkList &L) {
	int x;
	linkList s;
	L=(linkList)malloc(sizeof(lNode));             //创建头结点 
	L->next=NULL;
	
	scanf("%d",&x);
	while (x!=0) {
		s=(linkList)malloc(sizeof(lNode));         //创建新结点s 
		s->data=x;									//头插法,一直在头结点之后插入 
		s->next=L->next;
		L->next=s;
		scanf("%d",&x);
	}
	return L;
}
/*
linkList initList(linkList &L) {
	int x;
	L=(linkList)malloc(sizeof(lNode));            //创建头结点 
	L->next=NULL; 
	
	linkList s,r=L;                               //r为尾指针，始终指向最后结点，开始指向头结点 
	scanf("%d",&x);
	while (x!=0) {
		s=(linkList)malloc(sizeof(lNode));       //创建新结点，尾插法 
		r->next=s;
		r=s;
		scanf("%d",&x);
	}
	r->next=NULL;
	return L;
}
*/

linkList getElem(linkList L,int i) {            //按序号得到元素 ,从1开始，0为头结点 
	int j=1;
	linkList p=L->next;                         //p指向头结点的下一个 
	if (i==0)
		return L;
	if (i<1)
		return NULL;
	while (p&&j<i) {                           //p不空,j为i-1时为i的前一个,p->next为i位置元素 
		p=p->next;
		j++;
	}
	return p;                                  //返回i位置元素地址 
}

int locateElem(linkedList L,int e) {           //定位元素位置 
	linkedList p=L->next;
	int i=1;
	while (p&&p->data!=e) {
		p=p->next;
		i=i+1;
	}
	if (p==NULL)                               //遍历到最后一个都不是e，则p为NULL 
		return 0;
	else
		return i;
}

bool insert(linkList &L,int i,int e) {
	linkList s=(linkList)malloc(sizeof(lNode));
	if (s==NULL)
		return false;
	s->data=e;
	linkList p=getElem(L,i-1);                 //p指向i的前一个位置 
	s->next=p->next;
	p->next=s;
	return true;
}

bool deleteElem(linkList &L,int i,int &e) {
	linkList p=getElem(L,i-1);                 //p指向i的前一个 
	linkList q=p->next;                        //q指向要删除的i 
	e=q->data;
	p->next=q->next;
	free(q);
	return true; 
}
 
 
void destroyList(LinkList &L) {          //销毁单链表 
　　linkList p=L,q=p->next;              //p指向头，q指向头的下一个 
　　while (q!=NULL)
　　{ 
　　　　free(p);
　　　　p=q;                             //p指向下一个位置q 
　　　　q=p->next;                       //q指向p的下一个 
　　}
　　free(p); /*此时q为NULL, p指向尾结点,释放它*/
}

void print(linkList L) {
	linkList p=L->next;
	while (p) {
		printf("%d ",p->data);
		p=p->next;
	}
} 
