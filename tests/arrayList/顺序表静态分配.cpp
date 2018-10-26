#include <stdio.h>
#define MaxSize 50

typedef struct array {
	int data[MaxSize];             //大小 
	int length;					  //当前长度 
}Sqlist;

bool insert(Sqlist &l,int i,int e); //如果对顺序表进行修改 需取地址& 
void print(Sqlist l);               //不修改可直接 传结构体变量 
int locateElem(Sqlist l,int e);

int main() {
	
	int i;
	Sqlist sql1;
	sql1.length=0;                 //init length 0 
	
	for (i=1;i<=10;i++) 
		insert(sql1,i,i);
	
	printf("长度%d  ",sql1.length);
	
	for (i=0;i<sql1.length;i++)
		printf("%d ",sql1.data[i]);
	
	printf("位置%d",locateElem(sql1,10));
	return 0;
}

bool insert(Sqlist &l,int i,int e) {
	int j;
	if (i<1||i>l.length+1)         //在第1和length+1个位置插入 
		return false;
	if (l.length>=MaxSize)         //判断当前是否超过或等于最大长度 
		return false;
	for (j=l.length;j>=i;j--)     //从最后一个到i都向后移 
		l.data[j]=l.data[j-1];
	l.data[i-1]=e;                //元素插入 
	l.length++;
	
	return true;
} 

void print(Sqlist l) {              //输出 
	int i;
	for (i=0;i<l.length;i++)
		printf("%d ",l.data[i]);
}

int locateElem(Sqlist l,int e) {     //按值查找位置 
	int i;
	for (i=0;i<l.length;i++) {
		if (l.data[i]==e) {
			return i+1;
		}
	}
	return 0;
}
