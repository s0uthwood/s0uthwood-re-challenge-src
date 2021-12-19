	.file	"junk.c"
	.intel_syntax noprefix
	.text
	.comm	input,101,32
	.globl	cipher
	.data
	.align 32
	.type	cipher, @object
	.size	cipher, 56
cipher:
	.string	"flag{Naawcsgaywcqv|`5LybG{ck}n}Pq}~L~`x|Gp}Ka~~kFys}qr}"
	.section	.rodata
.LC0:
	.string	"%64s"
.LC1:
	.string	"First check pass!"
.LC2:
	.string	"Second check pass!"
.LC3:
	.string	"Third check pass!"
.LC4:
	.string	"Fourth check pass!"
.LC5:
	.string	"Fifth check pass!"
.LC6:
	.string	"All junk code cleared!"
.LC7:
	.string	"Wrong"
	.text
	.globl	main
	.type	main, @function
main:
.LFB0:
	.cfi_startproc
	endbr64
	push	rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	mov	rbp, rsp
	.cfi_def_cfa_register 6
	sub	rsp, 32
#APP
# 22 "junk.c" 1
	.intel_syntax noprefix

# 0 "" 2
#NO_APP
	mov	DWORD PTR -20[rbp], 0
	lea	rsi, input[rip]
	lea	rdi, .LC0[rip]
	mov	eax, 0
	call	__isoc99_scanf@PLT
#APP
# 26 "junk.c" 1
	lea rbx, input[rip]
	cmp byte ptr [rbx], 'f'
	jnz fail
	cmp byte ptr [rbx+1], 'l'
	jnz fail
	cmp byte ptr [rbx+2], 'a'
	jnz fail
	cmp byte ptr [rbx+3], 'g'
	jnz fail
	cmp byte ptr [rbx+4], '{'
	jnz fail
	cmp byte ptr [rbx+54], '}'
	jnz fail
	
# 0 "" 2
#NO_APP
	lea	rdi, .LC1[rip]
	call	puts@PLT
#APP
# 43 "junk.c" 1
	xor rax, rax
	jz LABEL2
	.byte 0xE8
	LABEL2:
	
# 0 "" 2
#NO_APP
	mov	DWORD PTR -16[rbp], 5
	jmp	.L2
.L3:
	mov	eax, DWORD PTR -16[rbp]
	cdqe
	lea	rdx, input[rip]
	movzx	eax, BYTE PTR [rax+rdx]
	mov	edx, eax
	mov	eax, DWORD PTR -16[rbp]
	add	eax, 8
	xor	eax, edx
	mov	ecx, eax
	mov	eax, DWORD PTR -16[rbp]
	cdqe
	lea	rdx, input[rip]
	mov	BYTE PTR [rax+rdx], cl
	mov	eax, DWORD PTR -16[rbp]
	cdqe
	lea	rdx, input[rip]
	movzx	ecx, BYTE PTR [rax+rdx]
	mov	eax, DWORD PTR -16[rbp]
	cdqe
	lea	rdx, cipher[rip]
	movzx	eax, BYTE PTR [rax+rdx]
	xor	eax, ecx
	movzx	eax, al
	or	DWORD PTR -20[rbp], eax
	add	DWORD PTR -16[rbp], 1
.L2:
	cmp	DWORD PTR -16[rbp], 17
	jle	.L3
	cmp	DWORD PTR -20[rbp], 0
	jne	.L16
	lea	rdi, .LC2[rip]
	call	puts@PLT
#APP
# 56 "junk.c" 1
	jz LABEL3
	jnz LABEL3
	.byte 0xE8
	LABEL3:
	
# 0 "" 2
#NO_APP
	mov	DWORD PTR -12[rbp], 18
	jmp	.L6
.L7:
	mov	eax, DWORD PTR -12[rbp]
	cdqe
	lea	rdx, input[rip]
	movzx	eax, BYTE PTR [rax+rdx]
	mov	edx, eax
	mov	eax, DWORD PTR -12[rbp]
	xor	eax, edx
	mov	ecx, eax
	mov	eax, DWORD PTR -12[rbp]
	cdqe
	lea	rdx, input[rip]
	mov	BYTE PTR [rax+rdx], cl
	mov	eax, DWORD PTR -12[rbp]
	cdqe
	lea	rdx, input[rip]
	movzx	ecx, BYTE PTR [rax+rdx]
	mov	eax, DWORD PTR -12[rbp]
	cdqe
	lea	rdx, cipher[rip]
	movzx	eax, BYTE PTR [rax+rdx]
	xor	eax, ecx
	movzx	eax, al
	or	DWORD PTR -20[rbp], eax
	add	DWORD PTR -12[rbp], 1
.L6:
	cmp	DWORD PTR -12[rbp], 29
	jle	.L7
	cmp	DWORD PTR -20[rbp], 0
	jne	.L17
	lea	rdi, .LC3[rip]
	call	puts@PLT
#APP
# 69 "junk.c" 1
	call Sub4
	.byte 0xE8
	jmp Label4
	Sub4:
	add dword ptr [rsp], 1
	ret
	Label4:
	
# 0 "" 2
#NO_APP
	mov	DWORD PTR -8[rbp], 30
	jmp	.L9
.L10:
	mov	eax, DWORD PTR -8[rbp]
	cdqe
	lea	rdx, input[rip]
	movzx	eax, BYTE PTR [rax+rdx]
	mov	edx, eax
	mov	eax, DWORD PTR -8[rbp]
	sub	eax, 16
	xor	eax, edx
	mov	ecx, eax
	mov	eax, DWORD PTR -8[rbp]
	cdqe
	lea	rdx, input[rip]
	mov	BYTE PTR [rax+rdx], cl
	mov	eax, DWORD PTR -8[rbp]
	cdqe
	lea	rdx, input[rip]
	movzx	ecx, BYTE PTR [rax+rdx]
	mov	eax, DWORD PTR -8[rbp]
	cdqe
	lea	rdx, cipher[rip]
	movzx	eax, BYTE PTR [rax+rdx]
	xor	eax, ecx
	movzx	eax, al
	or	DWORD PTR -20[rbp], eax
	add	DWORD PTR -8[rbp], 1
.L9:
	cmp	DWORD PTR -8[rbp], 41
	jle	.L10
	cmp	DWORD PTR -20[rbp], 0
	jne	.L18
	lea	rdi, .LC4[rip]
	call	puts@PLT
#APP
# 85 "junk.c" 1
	call    Sub5
	.byte   0xE8
	jmp     LABEL5
	Sub5:
	pop     rax
	add     rax, 1
	push    rax
	mov     rax, rsp
	xchg    rax, [rax]
	pop     rsp
	mov     [rsp+0], rax
	ret
	LABEL5:
	
# 0 "" 2
#NO_APP
	mov	DWORD PTR -4[rbp], 42
	jmp	.L12
.L13:
	mov	eax, DWORD PTR -4[rbp]
	cdqe
	lea	rdx, input[rip]
	movzx	eax, BYTE PTR [rax+rdx]
	mov	edx, eax
	mov	eax, DWORD PTR -4[rbp]
	sub	eax, 23
	xor	eax, edx
	mov	ecx, eax
	mov	eax, DWORD PTR -4[rbp]
	cdqe
	lea	rdx, input[rip]
	mov	BYTE PTR [rax+rdx], cl
	mov	eax, DWORD PTR -4[rbp]
	cdqe
	lea	rdx, input[rip]
	movzx	ecx, BYTE PTR [rax+rdx]
	mov	eax, DWORD PTR -4[rbp]
	cdqe
	lea	rdx, cipher[rip]
	movzx	eax, BYTE PTR [rax+rdx]
	xor	eax, ecx
	movzx	eax, al
	or	DWORD PTR -20[rbp], eax
	add	DWORD PTR -4[rbp], 1
.L12:
	cmp	DWORD PTR -4[rbp], 53
	jle	.L13
	cmp	DWORD PTR -20[rbp], 0
	jne	.L19
	lea	rdi, .LC5[rip]
	call	puts@PLT
	lea	rdi, .LC6[rip]
	call	puts@PLT
	mov	eax, 0
	jmp	.L15
.L16:
	nop
	jmp	.L5
.L17:
	nop
	jmp	.L5
.L18:
	nop
	jmp	.L5
.L19:
	nop
.L5:
#APP
# 109 "junk.c" 1
	fail:
# 0 "" 2
#NO_APP
	lea	rdi, .LC7[rip]
	call	puts@PLT
	mov	eax, 0
.L15:
	leave
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE0:
	.size	main, .-main
	.ident	"GCC: (Ubuntu 9.4.0-1ubuntu1~20.04) 9.4.0"
	.section	.note.GNU-stack,"",@progbits
	.section	.note.gnu.property,"a"
	.align 8
	.long	 1f - 0f
	.long	 4f - 1f
	.long	 5
0:
	.string	 "GNU"
1:
	.align 8
	.long	 0xc0000002
	.long	 3f - 2f
2:
	.long	 0x3
3:
	.align 8
4:
