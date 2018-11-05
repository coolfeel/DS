#include <iostream>
#include <vector>

/*
vector向量，变长数组
使用普通数组容易超内存，使用vector方便很多
vector还可以用来以邻接表的方式存储图

直接访问访问：直接访问v[index]，从0到v.size() - 1
迭代器访问：vector<typename> :: iterator it

常用：
push_back()，最后面添加元素
pop_back(), 删除尾元素
size(), 元素个数
clear(),清空所有元素
insert(it, x),任意迭代器it处插入元素, eg : v.insert(v.begin() + 2, -1), v[2]处
erase(it), 删除迭代器it处的元素， eg : v.erase(v.begin() + 3)
erase(first, last)    删除区间[first, last)内的所有元素

*/


using namespace std;

int main() {

    return 0;
}
