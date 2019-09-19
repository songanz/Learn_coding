#include "header.h"
using namespace std;

int main(){
    int  var;
    int  *ptr;  // 表示这个变量是一个指针
    int  val;
    int &rvar = var; 
    /*
    引用的格式：引用就是某一变量（目标）的一个别名，对引用的操作与对变量直接操作完全一样， 必须初始化
    类型名  &  别名 = var;
    1.定义的时候必须初始化，即& 前面有类名或类型名，&别名后面一定带 “=” （在= 左边）；
    2.&后面的别名是新的名字，之前不存在。

    函数中的形参 int &i 也是引用；

    & 取地址时：
    如果&是取址运算符，也就意味着取一个变量的地址并付给指针变量。&后面紧跟的是变量（已存在）；
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

    cout << "Value of ptr :   " << ptr << endl;
    cout << "Value of *pptr : " << temp << endl;
    cout << "Value of &ptr :  " << pptr << endl;

    cout << "Value of var :" << var << endl;
    cout << "Value of val :" << val << endl;
    cout << "Value of rvar :" << rvar << endl;
    
}