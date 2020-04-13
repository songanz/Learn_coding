#include "header.h"
#include <typeinfo>
using namespace std;

struct Triangle {  // 习惯: struct start with capital letter
  double a,b,c;  // those are members. No memory allocated yet!!!
  string name;  // those are members. No memory allocated yet!!!
};

bool compare_x (vector<int> &v1, vector<int> &v2) {
  return (v1[0] < v2[0]);
}

struct ListNode {
  int val;
  ListNode* next;
  ListNode();
  ListNode(int x): val(x), next(nullptr) {}
};

int main(){
    int  var;
    int  *ptr;  // 表示这个变量是一个指针
    int  val;
    int &rvar = var;  // 必须初始化
    /*
    引用的格式：引用就是某一变量（目标）的一个别名，对引用的操作与对变量直接操作完全一样
    类型名  &  别名 = var;
    1.定义的时候必须初始化，即& 前面有类名或类型名，&别名后面一定带 “=” （在= 左边）；
    2.&后面的别名是新的名字，之前不存在。

    函数中的形参 int &i 也是引用；

    & 取地址时：
    如果&是取址运算符，也就意味着取一个变量的地址并付给指针变量。&后面紧跟的是变量（已存在）；
    */
   bool b = true ^ true;
   cout << b << endl;

    /* Bitwise exclusive OR
        0 ^ 0 = 0;
        0 ^ 1 = 1; 
        1 ^ 0 = 1; 
        1 ^ 1 = 0
    */

    var = 3000;

    // 获取 var 的地址
    ptr = &var;

    // 获取指针变量的地址
    int **pptr;
    pptr = &ptr; 

    // 获取 ptr 的值
    val = *ptr;  // *运算只能对指针做

    // 获取 pptr 的值
    int *temp;  // pptr 的值也是个地址
    temp = *pptr; // 会发现等于 ptr 

    // 单引号 vs 双引号
    vector<char> t;
    // t.push_back("1");  // 必须给*"1"
    t.push_back(*"1");  // 双引号是字符串 string, 相当与一个指针指向字符，
    t.push_back('1');   // 单引号返回char

    cout << "Value of ptr :   " << ptr << "\n";  // use "\n" instead of endl will hold and print when ready
    cout << "Value of *pptr : " << temp << "\n";  // therefore quicker
    cout << "Value of &ptr :  " << pptr << "\n";

    cout << "Value of var :" << var << "\n";
    cout << "Value of val :" << val << "\n";
    cout << "Value of rvar :" << rvar << "\n";

    // create priority queue on end time
    // 如果要用到小顶堆(升序)，则一般要把模板的3个参数都带进去
    // STL里面定义了一个仿函数greater<>，基本类型可以用这个仿函数声明小顶堆
    // 如果不定义就是降序
    priority_queue<int, vector<int>, greater<int> > pq;
    pq.push(10);
    pq.push(9);
    pq.push(8);
    pq.push(7);
    pq.push(6);

    Triangle t1;
    t1.a = 3;  // member access using dot
    Triangle t2 = {3,4,5,"lalala"};  // 另一种initialize的方法
    Triangle t3 = t2;  // actrual copy the data并不像array一样 (copy the pointer)

    vector< vector<int> > v = {{3,9,10}, {2,7,15}, {5,12,12}, {15,20,10}};
    sort(v.begin(), v.end(), compare_x);
    cout << v[0][0] << '\n';

    int a[2] = {1, 2};
    cout << a << '\n';
    cout << *begin(a) << '\n';
    cout << *(end(a)-1) << '\n';
    cout << *(end(a)) << '\n';  // nullptr

    array<int, 2> x = {10,20};
    cout << *x.begin() << '\n';
    
    int n = 5;
    cout << n/6 << '\n';

    ListNode* ans;
    cout << (ans == nullptr) << '\n';

    cout << typeid(pow(10,2)).name() << '\n';
}