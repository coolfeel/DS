#include <iostream>
#include <queue>
#include <string>
using namespace std;

/*
队列，先进先处的限制性数据结构
front(),访问对首元素
back()，访问队尾元素
push(),入队元素
pop(),出队元素
empty(),检测队是否为空
size(),元素个数

用途：
广度优先搜索时可用
访问队首和队尾元素，要判断是否队空，否则出错
双端队列：deque,首尾皆可插入和删除的队
优先队列：priority_queue，使用堆实现的默认将当前队列最大元素置于对首的队列
eg : priority_queue <typename> name;
访问： 使用top()访问优先级最高的元素
push(),入队元素
pop（）,队首元素出队
empty(),检测是否空队
size(),元素个数

priority_queue<int> q;
priority_queue<int, vector<int>, less<int> > q; 第2个参数是来承载底层数据结构堆的容器，第3个参数是对第1个参数的比较类，less<int>表示数字越大优先级越高，greater<int>反之
解决贪心，也可对迪杰斯特拉算法优化，因为优先队列的本质是堆
*/


struct fruit {
        string name;
        int price;
        friend bool operator < (const fruit &f1, const fruit &f2) {  //重载<，表示价格越高，优先级越高，
            return f1.price < f2.price;            //刚好和sort中的cmp相反？？？
        }
    }f1, f2, f3;

int main() {
    priority_queue<fruit> q;
    f1.name = "桃子";
    f1.price = 3;
    f2.name = "梨子";
    f2.price = 4;
    f3.name = "苹果";
    f3.price = 1;
    q.push(f1); q.push(f2); q.push(f3);
    cout << q.top().name << " " << q.top().price << endl;
    return 0;
}
