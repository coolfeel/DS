#include <stdio.h>
//设计一个高效的算法，将顺序表的元素逆序，要求空间复杂度为O(1)
 
typedef struct arrayList {
	int *data;
	int maxSize,length;	
}sqList;

int main() {
	return 0;
} 

void reverse (sqList &l) {
	int t;
	for (int i=0;i<l.length/2;i++) {
		t=l.data[i];
		l.data[i]=l.data[l.length-1-i];
		l.data[l.length-1-i]=t;
	}
		
}


void reverseElem (sqList &l) {
	int temp;                     //只借助一个辅助变量交换 
	for (int i=0;i<l.length/2;i++) {
		temp=l.data[i];
		l.data[i]=l.data[l.length-1-i];
		l.data[l.length-1-i]=temp;
	}
}
