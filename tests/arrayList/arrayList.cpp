#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>

#define LIST_INIT_SIZE 100
#define LISTINCREMENT 10

typedef struct list {
	int *elem;  //首地址 
	int length; //顺序表长度 
	int listsize; //已分配的长度 
}arrayList,*pArrayList;


bool initList(pArrayList list);    //初始顺序表 
bool insertElem(pArrayList list,int i,int e); //插入元素 
void listElems(pArrayList list); //输出顺序表 
bool deleteElem(pArrayList list,int i,int *val); //删除元素 

int main() {  //主函数 
	pArrayList list=NULL; //只是定义一个结构体指针，最初指向空 
	int i;
	int len; //想要的顺序表长度 len
	int num; //输入的元素 
	int n; //删除元素位置 
	int *val=NULL;
	
	arrayList l;  //定义结构体变量 
	list=&l; //将结构体指针指向此结构体 
	
	if (initList(list)) {
		printf("创建成功\n");
		 
		printf("请输入想要的顺序表长度:\n");
		scanf("%d",&len);
			
		for (i=1;i<=len;i++) {
			scanf("%d",&num);
			insertElem(list,i,num); 
		}
		
		printf("输出元素:");
		listElems(list);
		
		printf("\n");
		
		printf("请输入删除元素的位置:\n");
		scanf("%d",&n);
	
		deleteElem(list,n,val);
		
		printf("输出元素:");
		listElems(list);
		
	}		
	else
		printf("创建失败");	
		
	return 0;
}

bool initList(pArrayList L) { //初始顺序表 
	L->elem=(int *)malloc(LIST_INIT_SIZE*sizeof(int));
	if (!L->elem)
		return false;
	L->length=0;
	L->listsize=LIST_INIT_SIZE;
	return true;
} 

bool insertElem(pArrayList L,int i,int e) { //插入元素 
	int *newbase,*p,*q;
	
	if (i<1||i>L->length+1)
		return false;
		
	if (L->length>=L->listsize) {
		newbase=(int *)realloc(L->elem,(L->listsize+LISTINCREMENT)*sizeof(int));
		if (!newbase)
			return false;
		L->elem=newbase;
		L->listsize+=LISTINCREMENT;
	}
	
	q=&L->elem[i-1];  //q指到要添加元素的位置 
	
	for (p=&L->elem[L->length-1];p>=q;p--) {  //通过p指针将元素向后移动 
		*(p+1)=*p;
	}
	
	*q=e;
	L->length++;
	
	return true;
} 

void listElems(pArrayList L) { //输出循序表 
	int i;
	for (i=0;i<L->length;i++)
		printf("%d",L->elem[i]);  //顺序表元素下标从0开始 
}

bool deleteElem(pArrayList L,int i,int *val) {
	int *q;
	
	if (i<1||i>L->length)
		return false;
	q=&L->elem[i-1]; //q指向删除元素的位置 
	val=q; 
	printf("删除的元素为:%d ",*val);
	
	for (q++;q<=&L->elem[L->length-1];q++) { //从要删除的位置下一个开始移动 
		*(q-1)=*q;
	}	
	L->length--;
	return true;
}
