#include <stdio.h>
#include <stdlib.h>

typedef struct lNode {
	int data;
	struct lNode *next;
}lNode,*linkList;


linkList initList(linkList &l);               //初始化 
void print(linkList l);                       //输出 
bool insert(linkList &l,int i,int e);         //插入 
bool deleteElem(linkList &l,int i,int &e);    //删除 

int main() {
	lNode l;
	linkList p=&l;
	int e;
	initList(p);
	
	print(p);
	if (insert(p,2,1000))
		printf("ok");
	else
		printf("no");
	print(p);
	deleteElem(p,3,e);
	print(p);
	printf("删除的元素:%d",e);
	return 0;
}

linkList initList(linkList &l) {                      //尾插法 
	int x;
	l=(linkList)malloc(sizeof(lNode));
	linkList s,r=l;
	scanf("%d",&x);
	while (x!=9999) {
		s=(linkList)malloc(sizeof(lNode));
		s->data=x;
		r->next=s;
		r=s;
		scanf("%d",&x);
	}
	r->next=NULL;
	return l;
}

linkList getElem(linkList l,int i) {
	int j=1;
	linkList p=l->next;
	if (i==0)
		return l;
	if (i<1)
		return NULL;
	while (p&&j<i) {
		p=p->next;
		j++;
	}
	return p;
}

bool insert(linkList &l,int i,int e) {
	linkList s=(linkList)malloc(sizeof(lNode));
	if (s==NULL)
		return false;
	s->data=e;
	linkList p=getElem(l,i-1);
	s->next=p->next;
	p->next=s;
	return true;
}

bool deleteElem(linkList &l,int i,int &e) {
	linkList p=getElem(l,i-1);
	linkList q=p->next;
	e=q->data;
	p->next=q->next;
	free(q);
}
 
void print(linkList l) {
	linkList p=l->next;
	while (p) {
		printf("%d ",p->data);
		p=p->next;
	}
} 
