#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>

typedef struct Node {                //链式栈的结点 
	int data;
	struct Node *pNext;
}NODE,*PNODE;


typedef struct Stack {               //创建栈 
	PNODE pTop;                      //用结点PNODE存储 
	PNODE pBottom;
}STACK,*PSTACK;

void initStack(PSTACK);              //初始栈 
void pushStack(PSTACK,int);          //入栈 
void traverse(PSTACK);              //遍历输出 
bool popStack(PSTACK,int*);          //出栈 
bool is_empty(PSTACK);              //判空 
void clear(PSTACK);                 //每个元素都销毁 

int main() {
	
	STACK S;
	int val;
	
	initStack(&S);
	pushStack(&S,1);
	pushStack(&S,2);
	popStack(&S,&val); //因为值传递，所以用地址 
	traverse(&S);
	
	return 0;
} 


void initStack(PSTACK pS) {
	pS->pTop=(PNODE)malloc(sizeof(NODE));   //创建一个结点给栈顶 
	if (pS->pTop==NULL) {
		printf("分配失败");
		exit(-1);
	}
	else {
		pS->pBottom=pS->pTop;     //初始栈顶栈底 指向同一个位置 
		pS->pTop->pNext=NULL;    //或pS->pBottom->pNext=NULL
	}
		
		 
}

void pushStack(PSTACK pS,int val) {
	PNODE pNew=(PNODE)malloc(sizeof(NODE));    //入栈要再创建一个新结点 ，动态入不需判空 
	pNew->data=val;                            
	pNew->pNext=pS->pTop;                      //开始top不为空,新结点的下一个指向top 
	pS->pTop=pNew;								//top指向新结点，此时top指向新结点（栈顶），bottom指向初始结点（栈底） 
	return;
}

void traverse(PSTACK pS) {
	PNODE p=pS->pTop;                          //头结点指针给一个指针结点变量 
	while(p!=pS->pBottom) {                     //从头开始遍历，如果不是尾就输出 
		printf("%d",p->data); 
		p=p->pNext;                            //指向下一个 
	}
	return;
}

bool is_empty(PSTACK pS) {
	if (pS->pTop==pS->pBottom)               //刚开始top和bottom指向同一个位置为空 
		return true;
	else 
		return false;
}


bool popStack(PSTACK pS,int *pval) {
	if (is_empty(pS)) {                 //出栈判空 
		return false;
	}
	else {                                                 //链式指针是向栈底指的 
		PNODE r=pS->pTop;   //借助一个指针r，不然直接赋值pS->Top=pS->Top->pNext之后找不到原来的pS->Top，就不能释放其内存 
		*pval=r->data;      //先把栈顶数据取出 
		pS->pTop=r->pNext;  //指针向栈底移动 
		free(r);            //释放原来的顶 
		r=NULL;             
		return true;
	}
}

void clear(PSTACK pS) {
	if (is_empty(pS)) {           //销毁前  判空 
		return;
	}
	else {
		PNODE p=pS->pTop;
		PNODE q=NULL;
		while (p!=pS->pBottom) {  //p指向顶,q指向其下一个 ，每个元素都销毁 
			q=p->pNext;
			free(p);
			p=q;
		}                      //全部释放完后，在移动top=bottom 
		pS->pTop=pS->pBottom;
	}
}
