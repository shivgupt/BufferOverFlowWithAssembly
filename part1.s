.section .data
path: 
.string "/bin/sh"

.section .text
.globl _start
_start:
	movq %rsp,%rbp
	movq $path,%rdi		#pointer to hard coded shell path
	movq $59,%rax
	movq $0, %rsi	
	movq $0,%rdx
	syscall
	movq %rax, %rbx
	movq $60, %rax	
	movq $0, %rdi
	syscall
