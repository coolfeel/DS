#include <stdio.h>
#include <stdlib.h>

#define MaxSize 50

typedef struct SeqQueue {             //循环队列 （静态顺序队列） 
	int data[MaxSize];
	int front,rear;
}SeqQueue,*PSeqQueue;

PSeqQueue initQueue();                //初始 
bool enQueue(PSeqQueue pqueue,int x); //入队 
bool qeQueue(PSeqQueue pqueue,int *x);//出队 
bool isEmplyQueue(PSeqQueue pqueue);  //判空 

int main() {
	
	int x;
	
	PSeqQueue pqueue=initQueue();
	
	enQueue(pqueue,2);
	
	if (enQueue(pqueue,1)) {	
		printf("入队成功\n");
	}
	
	enQueue(pqueue,3);
	
	qeQueue(pqueue,&x);
	
	return 0;
}

PSeqQueue initQueue() {
	PSeqQueue pqueue=(PSeqQueue)malloc(sizeof(SeqQueue));    //分配一个队列结构体空间，包括一个一维数组 
	if (pqueue==NULL) 
		printf("创建失败");
	else {
		pqueue->front=0;                                     //front和rear表示数组下标，从0开始 
		pqueue->rear=pqueue->front;                          //初始时都指向0 
	}
	return pqueue; 
} 

bool enQueue(PSeqQueue pqueue,int x) {
	if ((pqueue->rear+1)%MaxSize==pqueue->front)             //入队时判满 
		return false;
	else {
		pqueue->data[pqueue->rear]=x;                        //循环队列rear指向最后一个元素的下一个位置 
		pqueue->rear=(pqueue->rear+1)%MaxSize;               //rear下标加1需要%MaxSize归0化 
		return true;
	}
} 


bool qeQueue(PSeqQueue pqueue,int *x) {
	if (pqueue->front==pqueue->rear)                         //出队时判空 
		return false;
	else {
		*x=pqueue->data[pqueue->front];                      //top指向开始的元素，出队先取值 
		printf("出队元素：%d  ",*x);
		pqueue->front=(pqueue->front+1)%MaxSize;             //再将front下标加1归0化 
		return true;
	}
}



bool isEmplyQueue(PSeqQueue pqueue) {
	if (pqueue->front==pqueue->rear)
		return true;
	else
		return false;
}
