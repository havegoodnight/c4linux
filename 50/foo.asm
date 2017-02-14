extern bar_function

[section .data]
	arg1 db 10; 声明一个字型数据 (4 字节 , 32 位)
	arg2 db 20

[section .text]
	global _start
	global foo_function

	_start:
		push word [arg2] ; 最后一个参数压栈
		push word [arg1] ; 倒数第二个参数压栈 (第一个参数)
		call bar_function ; 调用函数
		add esp, 0008H ; 将栈顶移动到压栈之前的状态
		; 执行 Linux 系统调用 (现在连系统都没有 , 怎么执行系统调用 ? )
		mov ebx, 0
		mov eax, 1
		int 80H

	foo_function:
		mov edx, [esp + 8] ; 对应参数count , 也就是 C 语言函数中的第二个参数
		mov ecx, [esp + 4] ; 对应参数buf
		mov ebx,1 ; 对应参数fd，fd = 1，在linux中对应于stdout，指的是显示屏
		mov eax,4 ; 系统调用号为4，sys_write
		int 0x80
		ret
