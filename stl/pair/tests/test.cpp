#include <iostream>
#include <utility>
#include <map>
#include <string>
using namespace std;

/*
struct pair {
    typename1 first;
    typename2 second;
};

2个元素绑定在一起，合成1个，可以看做内部只有
pair<typename1, typename2> name;
初始化 ： p = pair<string, int> p("haha", 5);
         或p = make_pair("haha", 5);
比较操作数： 2个pair类型可以用==，！=，<,<=,>,>=比较，先比较first，只有其相等才比较second


*/




int main() {
    map<string, int> mp;
    mp.insert(make_pair("haha", 5));
    mp.insert(pair<string, int>("ha", 10));
    for (map<string, int> :: iterator it = mp.begin(); it != mp.end(); it++)
        cout << it->first << " " << it->second << endl;
    return 0;
}
