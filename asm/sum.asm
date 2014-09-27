section .data
	num1: equ 100
	num2: equ 50
	msg: db "Sum is correct\n"

section .text
	
	global _start

_start:
	mov rax, num1
	mov rbx, num2
	add rax, rbx
	cmp rax, 150
	jne .exit
	jmp .rightSum

.rightSum:
	;; Write syscall
	mov rax, 1
	;; file description, stdout
	mov rdi, 1
	;; msg address
	mov rsi, msg
	;; length of message
	mov rdx, 15
	;; call write syscall
	syscall
	;;exit
	jmp .exit

.exit:
	;; exit syscal
	mov rax, 60
	mov rdi, 0
	syscall
		


