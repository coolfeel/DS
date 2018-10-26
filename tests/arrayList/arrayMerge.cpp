#include <stdio.h>
#include <malloc.h>

#define LIST_INIT_SIZE 100
#define LISTINCREMENT 10

typedef struct list {
	int *elem;
	int length;
	int listsize;	
}arrayList,*pArrayList;

bool initList(pArrayList list);
bool mergeList(pArrayList pA,pArrayList pB,pArrayList pC);
bool insertElem(pArrayList list,int i,int e); //插入元素 
void listElems(pArrayList list); //输出顺序表 

int main() {
	pArrayList pA=NULL,pB=NULL,pC=NULL;
	arrayList la,lb,lc;
	pA=&la;
	pB=&lb;
	pC=&lc;
	
	int lenA,lenB,numA,numB,i;
	
	if (initList(pA)&&initList(pB)) {
		printf("初始化成功");
		printf("请输入想要的顺序表A长度:\n");
		scanf("%d",&lenA);
			
		for (i=1;i<=lenA;i++) {
			scanf("%d",&numA);
			insertElem(pA,i,numA); 
		}
		
		listElems(pA);
		
		printf("请输入想要的顺序表B长度:\n");
		scanf("%d",&lenB);
			
		for (i=1;i<=lenB;i++) {
			scanf("%d",&numB);
			insertElem(pB,i,numB); 
		}
		
		listElems(pB);
		
		printf("合并AB后为:");
		mergeList(pA,pB,pC);
		
		listElems(pC);
	}
	else
		printf("初始化失败");
	
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


bool mergeList(pArrayList pA,pArrayList pB,pArrayList pC) {
	int *pa,*pb,*pc,*pa_last,*pb_last;
	
	pa=pA->elem; pb=pB->elem; 
	pC->listsize=pC->length=pA->length+pB->length;
	pc=pC->elem=(int *)malloc(pC->listsize*sizeof(int));
	
	if (!pC->elem)
		return false;
	
	pa_last=pA->elem+pA->length-1;
	pb_last=pB->elem+pB->length-1;
	
	while (pa<=pa_last&&pb<=pb_last) {
		if (*pa<=*pb)
			*pc++=*pa++;
		else
			*pc++=*pb++;
	}
	
	while (pa<=pa_last) {
		*pc++=*pa++;
	}
	while (pb<=pb_last) {
		*pc++=*pb++;
	}
	
	return true;
}

void listElems(pArrayList L) { //输出循序表 
	int i;
	for (i=0;i<L->length;i++)
		printf("%d",L->elem[i]);  //顺序表元素下标从0开始 
}
