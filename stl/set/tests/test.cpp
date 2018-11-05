#include <iostream>
#include <set>


/*
集合，内部自动有序，且不含重复元素的容器
常用：
insert(),插入元素，除了vector和string容器，其他的容器都不支持*(it + 1)的访问
find(value),返回对应值为value的迭代器（指针）
erase(it), 删除单个元素，it为所要删除元素的迭代器
erase(value)， 删除元素
erase(first, last)， 删除区间内的元素，eg : s.erase(it, s.end())
size(), 元素个数
clear(), 清空

set : 唯一排序的
multiset : 不唯一但排序的
unordered_set ： 唯一不排序的

*/


using namespace std;

int main() {

    return 0;
}
