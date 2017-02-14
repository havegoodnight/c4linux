目标
```
汇编与C相互调用
```
备注
```
使用 nasm 进行汇编的时候的参数为 : 
nsam -f elf32 foo.asm
使用 gcc 编译 C 代码的时候的参数为 : 
gcc -m 32 bar.c # 这里 -m32 指的是在 32 位平台下 , -m64 则是 64 位
当两者都编译成功后 , 需要将两个输出文件链接在一起
ld -m elf_i386 foobar foo.o bar.o
```
