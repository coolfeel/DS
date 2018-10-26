#include <stdio.h>
#include <stdlib.h>

#define MAXSIZE 100

typedef struct BiTNode {                    //链式存储结构 
	char data;
	struct BiTNode *lchild,*rchild;
}BiTNode,*BiTree;


   
int visit(char c);                     //访问结点 
int initBiTree(BiTree &T);             //初始化 
int createBiTree(BiTree &T);            //创建 
int isEmptyBiTree(BiTree T);           //判空 
char getRoot(BiTree T);                 //获得根结点 
int depthBiTree(BiTree T);            //获得深度 
int destroyBiTree(BiTree &T);         //销毁 
int preOrder(BiTree T);               //先序遍历 
int inOrder(BiTree T);                //中序遍历 
int lastOrder(BiTree T);             //后序遍历 

int main() {
	
	BiTNode TN;
	BiTree T=&TN;
	
    	
    createBiTree(T);
    preOrder(T);
    printf("%d\n",depthBiTree(T));
    printf("%c\n",getRoot(T));
    inOrder(T);
    return 0;
}




int visit(char c) {             //访问 
	printf("%c",c);
	return 1;
} 


int initBiTree(BiTree &T) {      //初始化 
	T=NULL;
	return 1;
}


int createBiTree(BiTree &T) {    //创建二叉树 
	char data;
	scanf("%c",&data);
	
	if (data=='#')
		T=NULL;
	else {
		T=(BiTNode *)malloc(sizeof(BiTNode));
		if (!T)
			return 0;
		T->data=data;
		createBiTree(T->lchild);
		createBiTree(T->rchild);
	}
	
}


int isEmptyBiTree(BiTree T) {   //判空 
	if (!T)
		return 1;
	else
		return 0;
}


char getRoot(BiTree T) {           //得到根结点 
	return T->data;
}


int depthBiTree(BiTree T) {          //求树的深度 
	int i,j;
	if (!T)
		return 0;
	else {
		if (T->lchild)
			i=depthBiTree(T->lchild);
		else
			i=0;
		if (T->rchild)
			j=depthBiTree(T->rchild);
		else
			j=0;
	}
	return i>j?i+1:j+1;
}


int destroyBiTree(BiTree &T) {           //销毁二叉树 
	if (!T)
		return 0;
	else {
		if (T->lchild) 
			destroyBiTree(T->lchild);
		if (T->rchild)
			destroyBiTree(T->rchild);
	}
	free(T);
	T=NULL;
	return 1;
}


int preOrder(BiTree T) {                   //先序遍历二叉树 
    if(!T)
        return 0;
    visit(T->data);
    preOrder(T->lchild);
    preOrder(T->rchild);
    return 1;
} 


int inOrder(BiTree T){                   //中序遍历 
    if(!T)
       return 0;
    inOrder(T->lchild);
    visit(T->data);
    inOrder(T->rchild);
    return 1;
}


int lastOrder(BiTree T){              //后序遍历 
    if(!T)
       return 0;
    lastOrder(T->lchild);
    lastOrder(T->rchild);
    visit(T->data);
    return 1;
}
