#include <stdio.h>
#include <stdlib.h>

#define InitSize 100  //初始容量 
#define INCREMENT 50  //增量 

typedef struct array {
	int *data;
	int length,MaxSize;
}Sqlist;


void print(Sqlist l); //输出 
bool init(Sqlist &l);	//初始化 
void destory(Sqlist &l); //销毁 
void isEmpty(Sqlist l); //判空 
int getLength(Sqlist l); //获得长度 
int locateElem(Sqlist l,int e); //定位特定元素 
void nextElem(Sqlist l,int e); //下一个元素 
int getElem(Sqlist l,int i,int *e); //得到元素 
bool insert(Sqlist &l,int i,int e); //插入 
void deleteElem(Sqlist &l,int i,int *e);  //删除      


int main() {
	
	int e=123;
	
	Sqlist sql1;
	
	init(sql1);
	
	insert(sql1,1,222);
	insert(sql1,2,22);
	insert(sql1,3,2224);
	
	deleteElem(sql1,1,&e);
	printf("删除的是%d元素  ",e);
	print(sql1);
	
	
	return 0;
}

bool init(Sqlist &l) {                   //初始化 
	l.data=(int *)malloc(sizeof(int)*InitSize);  //动态分配 
	if (l.data==NULL)
		return false;
	l.length=0;                        //长度初始化为0 
	l.MaxSize=InitSize;              //当前表的最大容量 
	return true;
} 

void destory(Sqlist &l) {           //销毁 
	if (l.data!=NULL) {              //连续内存 只需释放首地址 
		free(l.data); 
		printf("顺序表已销毁");
	}
		
} 

void isEmpty(Sqlist l) {             //判空 
	if (l.data!=NULL) {
		if (l.length==0) {            //看长度 
			printf("表中无元素");
		}
		else
			printf("表中元素"); 
	}
	else
		printf("表不存在");
} 


int getLength(Sqlist l) {
	if (l.data!=NULL)                    //表存在，返回长度 
		return l.length;
	else
		printf("表不存在");
	return 0;
}


int locateElem(Sqlist l,int e) {         //找到特定元素位置 
	int i;
	for (i=0;i<l.length;i++) {
		if (l.data[i]==e) {
			printf("元素的位置为%d",i+1);
			return i+1;
		} 
	}
	printf("没有此元素");
	return 0;
} 


void nextElem(Sqlist l,int e) {           //求特定元素后继元素 
	int i;
	i=locateElem(l,e);
	if (i!=0) {
		if (i=l.length)
			printf("最后一个元素没有后继");
		else
			printf("后继为%d",l.data[i]);
	}
	else
		printf("没有此元素");
}


int getElem(Sqlist l,int i,int *e) {      //得到确定位置元素 
	if (i<1||i>l.length) 
		return 0; 
	*e=l.data[i-1];
	return *e;
}


void clear(Sqlist &l) {                   //长度为0即清空 
	if (l.data!=NULL)
		l.length=0;
}



bool insert(Sqlist &l,int i,int e) {
	
	int *newbase;               //新分配的首地址 
	int *p,*q;
	
	if (i<1||i>l.length+1)
		return false;
		
	if (l.length>=l.MaxSize) {
		newbase=(int *)realloc(l.data,(l.MaxSize+INCREMENT)*sizeof(int));
		if (newbase==NULL)
			return false;
		else
			l.data=newbase;
	}
	
	p=&(l.data[i-1]);                             //p指向插入位置 
	
	for (q=&(l.data[l.length-1]);q>=p;q--)        //从最后位置开始到插入位置向后移 
		*(q+1)=*q;

	*p=e;                                         //e元素插入 
	l.length++;
	
	return true;
}


void deleteElem(Sqlist &l,int i,int *e) {     //删除元素,删除的元素取指针，在函数外部也能访问 
											  //并且形参可以修改实参 
	int *p;
	
	if (i<1||i>l.length)
		return;
	p=&(l.data[i-1]);                       //p指向删除位置 
	*e=l.data[i-1];                          
	 
	for (;p<&(l.data[l.length-1]);p++)      //p之后的向前移动，遍历到倒数第二个元素就行 
		*p=*(p+1);                           //p+1已指最后一个了 
	
	l.length--;
} 

void print(Sqlist l) {
	int i;
	for (i=0;i<l.length;i++) {
		printf("%d ",l.data[i]);
	}
}
