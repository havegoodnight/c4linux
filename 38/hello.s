	.file	"hello.c"
	.section	.rodata
.LC0:
	.string	"b = %d\n"
.LC1:
	.string	"q = %d\n"
.LC2:
	.string	"m = %d\n"
.LC3:
	.string	"n = %d\n"
	.text
	.globl	main
	.type	main, @function
main:
.LFB0:
	.cfi_startproc
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	subq	$32, %rsp
	movl	$20, -24(%rbp)
	movl	$20, -20(%rbp)
	movl	$20, -16(%rbp)
	addl	$1, -24(%rbp)
	addl	$1, -24(%rbp)
	movl	-24(%rbp), %eax
	leal	(%rax,%rax), %edx
	addl	$1, -24(%rbp)
	movl	-24(%rbp), %eax
	addl	%edx, %eax
	movl	%eax, -12(%rbp)
	addl	$1, -20(%rbp)
	addl	$1, -20(%rbp)
	movl	-20(%rbp), %eax
	addl	%eax, %eax
	movl	%eax, -8(%rbp)
	addl	$1, -16(%rbp)
	addl	$1, -16(%rbp)
	movl	-16(%rbp), %eax
	leal	(%rax,%rax), %edx
	addl	$1, -16(%rbp)
	movl	-16(%rbp), %eax
	addl	%eax, %edx
	addl	$1, -16(%rbp)
	movl	-16(%rbp), %eax
	addl	%edx, %eax
	movl	%eax, -4(%rbp)
	movl	-24(%rbp), %eax
	movl	%eax, %esi
	movl	$.LC0, %edi
	movl	$0, %eax
	call	printf
	movl	-12(%rbp), %eax
	movl	%eax, %esi
	movl	$.LC1, %edi
	movl	$0, %eax
	call	printf
	movl	-8(%rbp), %eax
	movl	%eax, %esi
	movl	$.LC2, %edi
	movl	$0, %eax
	call	printf
	movl	-4(%rbp), %eax
	movl	%eax, %esi
	movl	$.LC3, %edi
	movl	$0, %eax
	call	printf
	movl	$0, %eax
	leave
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE0:
	.size	main, .-main
	.ident	"GCC: (Ubuntu 4.8.4-2ubuntu1~14.04.3) 4.8.4"
	.section	.note.GNU-stack,"",@progbits
