#include <stdio.h>
#include <stdlib.h>
/*
	从顺序表中删除具有最小值得元素（假设唯一），函数返回被删除元素，空出的位置由最后一个元素填补
	表为空时显示错误信息 
*/
typedef struct arrayList {
	int *data;
	int maxSize,length;	
}sqList;

int main() {
	
	return 0;
}

int back(sqList &l,int *e) {
	
	int min,t;
	
	if (l.data==NULL) {                     //首地址判空 
		printf("顺序表为空");
		exit(1);
	}
	
	min=l.data[0];
	for (int i=1;i<l.length;i++) {
		if (l.data[i]<min) {
			min=l.data[i];
			t=i;
		}
	}
	l.data[t]=l.data[l.length-1];
	return min;                            //填补后没减长度 
		
} 



bool deleteElem(sqList &l,elemType &value) {
	//删除顺序表中最小值元素结点，并通过引用型参数e返回其值
	if (l.length==0)                    //表空，用长度判断 
		return false;
	value=l.data[0];
	int pos=0;
	for (int i=1;i<l.length;i++)      
		if (l.data[i]<value) {          //打擂台算法 
			value=l.data[i];
			pos=i;                      //pos记住最小值下标 
		} 
	l.data[pos]=l.data[l.length-1];
	l.length--;                         //长度减少 
	return true;
}
