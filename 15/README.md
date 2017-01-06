目的 : 
```
通过gcc的编译参数来了解编译的整个完整流程
```

---
1. 编译预处理
2. 编译
3. 汇编
4. 链接

---
1. 编译预处理(将 include 的文件替换到当前源码文件 , 展开宏定义)
```
gcc -E main.c -o main.i
gcc -E print.c -o print.i
```

---
2. 编译(生成汇编代码)
```
gcc -S main.i -o main.s
gcc -S print.i -o print.s
```

---
3. 汇编(将汇编代码生成二进制代码)
```
gcc -c main.s -o main.o
gcc -c print.s -o print.o
```

---
4. 链接(将静态库连接成一个完整的可执行程序)
```
gcc main.o -o main.out print.o
```
