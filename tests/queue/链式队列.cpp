#include <stdio.h>
#include <stdlib.h>

typedef struct Node {                   //链式队列 ，创建结点 
	int data;
	struct Node *PNode;
}Node,*PNode; 

typedef struct Queue {                  //创建队列结构体由，多个结点组成 
	PNode front;
	PNode rear;
}Queue,*PQueue;

void initQueue(PQueue pqueue);         //初始 
void enQueue(PQueue pqueue,int x);     //入队 
bool deQueue(PQueue pqueue,int *x);    //出队 
bool isEmptyQueue(PQueue pqueue);      //判空 
void traverse(PQueue pqueue);          //遍历队列 

int main() {
	
	Queue queue;                   //先有队列 
	PQueue pqueue=&queue;          //再有指针,不然报错 
	int x;
	
	initQueue(pqueue);
	
	enQueue(pqueue,1);
	enQueue(pqueue,2);
	enQueue(pqueue,3);
	enQueue(pqueue,4);	
	
	deQueue(pqueue,&x);
	
	traverse(pqueue);
	
	return 0;
} 


void initQueue(PQueue pqueue) {
	pqueue->front=(PNode)malloc(sizeof(Node));     //先创建一个结点给头指针 
	if (pqueue->front==NULL) {
		printf("分配失败");
		return;
	}		
	else {
		pqueue->rear=pqueue->front;               //初始头和尾指针指向同一位置 
		pqueue->front->PNode=NULL;                //下一个指向空 
		printf("分配成功");
	} 	
}


void enQueue(PQueue pqueue,int x) {
	PNode pNew=(PNode)malloc(sizeof(Node));     //入队，创建新结点 
	pNew->data=x;
	pNew->PNode=NULL;                          //新结点下一个为空 
	pqueue->rear->PNode=pNew;                  //新结点和尾结点接上 
	pqueue->rear=pNew; 
}


bool deQueue(PQueue pqueue,int *x) {
	if (pqueue->front==pqueue->rear) {     //出队判空 
		return false;
	}
	else {
		PNode p=pqueue->front->PNode;      //从头结点的下一个开始遍历出队，头结点不存元素
		*x=p->data;                        
		pqueue->front->PNode=p->PNode;     //用指针将p断掉 
		if (pqueue->rear==p) {             //如果出队的为最后一个元素，直接将尾指针指向头指针 
			pqueue->rear=pqueue->front;    //全部出去之后,尾结点悬空，应将其恢复初始，指向和头指针一样 
		} 
		free(p);                           //然后释放p 
		return true;
	}
}

void traverse(PQueue pqueue) {	
	PNode p=pqueue->front->PNode;               //头结点指针给一个指针结点变量 
	while(p!=pqueue->rear) {                   //从头开始遍历，如果不是尾就输出 
		printf("%d ",p->data); 
		p=p->PNode;                            //指向下一个 
	}
	printf("%d",p->data);
}



bool isEmptyQueue(PQueue pqueue) {
	if (pqueue->front==pqueue->rear)
		return true;
	else
		return false;
}
