目的 : 
```
练习使用 gcc -E 来进行编译预处理操作
观察宏定义如何被展开
观察被 include 的文件如何被导入源码文件
```

---
错误的做法 : (在头文件中(print.h ... )包含如下代码)
```c
#include <stdio.h>

void print(char *content);
```

---
正确的做法 : (在头文件(print.h ... )中包含如下代码)
```c
#ifndef __PRINT_H__ // 宏函数 (判断变量是否被定义)
#define __PRINT_H__


#include <stdio.h>

void print(char *content);


#endif // 结束 if 判断块 (即结束宏函数的作用域)
```

---
测试方法 : 
在 main.c 中重复包含 "print.c"
然后使用 `gcc -E main.c -o main.i` 来对源代码进行编译预处理操作
然后统计生成的完整代码中 `void print(char *content);` 这个函数的个数
如果统计结果大于 1 , 则说明存在问题 , 如果等于 1 , 说明已经成功解决了这个问题
1. 错误样例(error目录中的代码)
```
cd ./error
gcc -E main.c -o main.i
cat ./main.i | grep -c "*content" # 统计 print.h 中 print 函数的标志
```
发现输出为 7 , 说明这个头文件被包含了 7 次
2. 正确样例(success目录中的代码)
```
cd ./success
gcc -E main.c -o main.i
cat ./main.i | grep -c "*content"
```
输出结果为 1 , 该问题被解决

---
结果分析 : 
当使用错误的做法的时候
如果在 main.c 中包含了 cprint.h 和 print.h
并且在 cprint.h 中包含了 print.h
这种情况就会导致 print.h 在 main.c 中包含了两次
那么在编译的时候就会导致函数重复定义

解决的方法就是在包含之前使用宏定义进行判断某一个宏常量是否已经被定义
如果已经被定义 , 则代表这个文件已经被包含 , 反之则未被包含
而为了让那个宏常量和头文件关联在一起
一般情况下使用 \_\_文件名\_后缀名\_\_ 来作为宏常量的名称

---
注 : 
```
可以使用gcc的选项--verbose
来显示完整的预处理编译汇编链接的过程
```
