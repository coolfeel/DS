#include <stdio.h>
/*
长度为n的顺序表L，编写一个时间复杂度为O(n)，空间复杂度为O(1),的算法，该算法删除线性表
中所有值为x的元素 
*/ 

typedef struct arrayList {
	int *data;
	int maxSize,length;
}sqList;

int main() {
	
	return 0;
} 

void deleteEle(sqList &l,int x) {
	int *p,i;
	for (i=0;i<l.length;i++) {		
		if (l.data[i]==x) {		
			for (p=&(l.data[i]);p<&(l.data[l.length]);p++)
				*(p-1)=*p;
		}
	}	
}

void deleteElem(sqList &l,int x) {       //直接把不是x的重组到L中  
	int k=0;
	for (int i=0;i<l.length;i++) {
		if (l.data[i]!=x) {
			l.data[k]=l.data[i];
			k++;
		}	
	}
	l.length=k;
}
