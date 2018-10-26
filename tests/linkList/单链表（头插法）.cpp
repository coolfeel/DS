#include <stdio.h>
#include <stdlib.h>

typedef struct lNode {
	int data;
	struct lNode *next; 
}lNode,*linkedList;

linkedList initList(linkedList &l);            //初始化 
void print(linkedList l);                      //输出 
int getElem(linkedList l,int i);				//按序号获得元素 
int locateElem(linkedList l,int e);             //定位元素 

int main() {
	lNode l;
	linkedList p=&l;
	initList(p);
	print(p);
	printf("位置元素是：%d  ",getElem(p,1));
	printf("3在位置:%d",locateElem(p,3));	
	return 0;
}

linkedList initList(linkedList &l) {
	int x;
	linkedList s;
	l=(linkedList)malloc(sizeof(lNode));
	l->next=NULL;
	
	scanf("%d",&x);
	while (x!=9999) {
		s=(linkedList)malloc(sizeof(lNode));
		s->data=x;
		s->next=l->next;
		l->next=s;
		scanf("%d",&x);
	}
	return l;
}

int getElem(linkedList l,int i) {
	int j=1;
	linkedList p=l->next;
	if (i<1)
		return 0;
	while (p&&j<i) {
		p=p->next;
		j++;
	}
	
	return p->data;
}

int locateElem(linkedList l,int e) {
	linkedList p=l->next;
	int i=1;
	while (p&&p->data!=e) {
		i=i+1;
		p=p->next;
	}
	return i;
}


void print(linkedList l) {
	linkedList p=l->next;
	while (p) {
		printf("%d ",p->data);
		p=p->next;
	}
} 
