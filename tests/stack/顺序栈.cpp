#include <stdio.h>
#include <stdlib.h>

#define MaxSize 50

typedef struct SeqStack {    //顺序栈 
	int data[MaxSize];
	int top;               //栈顶指针  top代表数组下标  从0开始 
}SeqStack,*PSeqStack;


PSeqStack initSeqStack();             //初始栈 
bool isEmptySatck(SeqStack stack);   //判断是否为空 
bool pushStack(PSeqStack pstack,int x); //入栈 
int getTop(PSeqStack pstack);            //得到栈顶元素 
bool popStack(PSeqStack pstack);         //出栈


int main() {
	
	PSeqStack pstack=initSeqStack();
	
	if (pstack) {
		pushStack(pstack,1);
		pushStack(pstack,2);
		pushStack(pstack,3);
		printf("%d",getTop(pstack));
	}
	
	for (int i=0;i<3;i++) {
		popStack(pstack);
	}
	
	return 0;
} 

PSeqStack initSeqStack() {
	PSeqStack pstack=(PSeqStack)malloc(sizeof(SeqStack));    //直接分配一个结构体 
	if (pstack==NULL)
		printf("创建失败");
	else
		pstack->top=-1;      //栈空，栈顶为-1，当有1个元素指向0，top直接指向顶元素 
	return pstack;                                       
}


bool isEmptySatck(SeqStack stack) {
	if (stack.top==-1)           
		return true;
	else
		return false;
}


bool pushStack(PSeqStack pstack,int x) {
	if (pstack->top==MaxSize-1) {               //插入时判满 
		printf("栈满");
		return false;
	}
	else {
		pstack->top++;
		pstack->data[pstack->top]=x;
		return true;
	}			
}


bool popStack(PSeqStack pstack) {              //出栈时判空 
	if (pstack->top==-1) {
		printf("栈空");
		return false;
	}		
	else {
		printf ("栈顶元素：%d",pstack->data[pstack->top]);
		pstack->top--;
	}
		
}

int getTop(PSeqStack pstack) {               //直接得到顶元素 
	return pstack->data[pstack->top];
}
