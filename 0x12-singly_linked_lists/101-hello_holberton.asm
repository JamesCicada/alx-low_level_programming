section .data
	hello db "Hello, Holberton", 10 ; String to be printed

section .text
	global _start

_start:
	; Prepare the arguments for printf
	mov rdi, hello ; First argument: address of the string
	xor rax, rax  ; Clear rax to indicate no vector registers are used
	call printf   ; Call printf function

	; Exit the program
	xor edi, edi  ; Clear edi for exit status 0
	mov eax, 60   ; System call number for exit
	syscall	  ; Call the kernel

section .data
	format db "%s", 0  ; Format string for printf

section .text
	extern printf

_start:
	; Push the format string address onto the stack
	push format

	; Push the argument for printf (address of hello)
	push hello

	; Call printf
	call printf

	; Clean up the stack
	add rsp, 8

	; Exit the program
	mov eax, 60   ; System call number for exit
	xor edi, edi  ; Exit status 0
	syscall

section .data
	hello db 'Hello, Holberton', 0

section .text
	global _start

_start:
	; Prepare the arguments for printf
	mov rdi, 1
	mov rsi, hello
	mov rdx, 16
	mov rax, 1
	syscall

	; Exit the program
	mov rdi, 0
	mov rax, 60
	syscall
; I used a little bit of Goodle's Help
