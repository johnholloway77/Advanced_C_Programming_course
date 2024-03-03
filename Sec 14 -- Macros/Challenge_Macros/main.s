	.text
	.file	"main.c"
	.globl	main                            # -- Begin function main
	.p2align	4, 0x90
	.type	main,@function
main:                                   # @main
	.cfi_startproc
# %bb.0:
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset %rbp, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register %rbp
	subq	$48, %rsp
	movl	$0, -4(%rbp)
	movabsq	$.L.str, %rdi
	movl	$30, %esi
	movabsq	$.L.str.1, %rdx
	movabsq	$.L.str.2, %rcx
	movabsq	$.L.str.3, %r8
	movabsq	$.L.str.4, %r9
	movb	$0, %al
	callq	printf
	movabsq	$.L.str.5, %rdi
	movb	$0, %al
	callq	printf
	movabsq	$.L.str.6, %rdi
	movb	$0, %al
	callq	printf
	movabsq	$.L.str.7, %rdi
	leaq	-8(%rbp), %rsi
	movb	$0, %al
	callq	scanf
	movabsq	$.L.str.8, %rdi
	movb	$0, %al
	callq	printf
	movabsq	$.L.str.7, %rdi
	leaq	-12(%rbp), %rsi
	movb	$0, %al
	callq	scanf
	movl	-8(%rbp), %esi
	movl	-12(%rbp), %edx
	movl	-8(%rbp), %ecx
	addl	-12(%rbp), %ecx
	movabsq	$.L.str.9, %rdi
	movb	$0, %al
	callq	printf
	movabsq	$.L.str.10, %rdi
	movb	$0, %al
	callq	printf
	movabsq	$.L.str.11, %rdi
	movb	$0, %al
	callq	printf
	movabsq	$.L.str.7, %rdi
	leaq	-16(%rbp), %rsi
	movb	$0, %al
	callq	scanf
	movl	-16(%rbp), %esi
	movl	-16(%rbp), %edx
	imull	-16(%rbp), %edx
	movl	-16(%rbp), %ecx
	imull	-16(%rbp), %ecx
	imull	-16(%rbp), %ecx
	movabsq	$.L.str.12, %rdi
	movb	$0, %al
	callq	printf
	cmpl	$0, __isthreaded
	jne	.LBB0_5
# %bb.1:
	movq	__stdinp, %rcx
	movl	8(%rcx), %eax
	addl	$-1, %eax
	movl	%eax, 8(%rcx)
	cmpl	$0, %eax
	jge	.LBB0_3
# %bb.2:
	movq	__stdinp, %rdi
	callq	__srget
	movl	%eax, -24(%rbp)                 # 4-byte Spill
	jmp	.LBB0_4
.LBB0_3:
	movq	__stdinp, %rcx
	movq	(%rcx), %rax
	movq	%rax, %rdx
	addq	$1, %rdx
	movq	%rdx, (%rcx)
	movzbl	(%rax), %eax
	movl	%eax, -24(%rbp)                 # 4-byte Spill
.LBB0_4:
	movl	-24(%rbp), %eax                 # 4-byte Reload
	jmp	.LBB0_6
.LBB0_5:
	movq	__stdinp, %rdi
	callq	getc
.LBB0_6:
	movabsq	$.L.str.13, %rdi
	movb	$0, %al
	callq	printf
	movabsq	$.L.str.14, %rdi
	movb	$0, %al
	callq	printf
	cmpl	$0, __isthreaded
	jne	.LBB0_11
# %bb.7:
	movq	__stdinp, %rcx
	movl	8(%rcx), %eax
	addl	$-1, %eax
	movl	%eax, 8(%rcx)
	cmpl	$0, %eax
	jge	.LBB0_9
# %bb.8:
	movq	__stdinp, %rdi
	callq	__srget
	movl	%eax, -28(%rbp)                 # 4-byte Spill
	jmp	.LBB0_10
.LBB0_9:
	movq	__stdinp, %rcx
	movq	(%rcx), %rax
	movq	%rax, %rdx
	addq	$1, %rdx
	movq	%rdx, (%rcx)
	movzbl	(%rax), %eax
	movl	%eax, -28(%rbp)                 # 4-byte Spill
.LBB0_10:
	movl	-28(%rbp), %eax                 # 4-byte Reload
	movl	%eax, -32(%rbp)                 # 4-byte Spill
	jmp	.LBB0_12
.LBB0_11:
	movq	__stdinp, %rdi
	callq	getc
	movl	%eax, -32(%rbp)                 # 4-byte Spill
.LBB0_12:
	movl	-32(%rbp), %eax                 # 4-byte Reload
                                        # kill: def $al killed $al killed $eax
	movb	%al, -17(%rbp)
	movsbl	-17(%rbp), %eax
	movl	%eax, -40(%rbp)                 # 4-byte Spill
	movsbl	-17(%rbp), %ecx
	xorl	%eax, %eax
                                        # kill: def $al killed $al killed $eax
	cmpl	$65, %ecx
	movb	%al, -33(%rbp)                  # 1-byte Spill
	jl	.LBB0_14
# %bb.13:
	movsbl	-17(%rbp), %eax
	cmpl	$90, %eax
	setle	%al
	movb	%al, -33(%rbp)                  # 1-byte Spill
.LBB0_14:
	movl	-40(%rbp), %esi                 # 4-byte Reload
	movb	-33(%rbp), %cl                  # 1-byte Reload
	movabsq	$.L.str.17, %rdx
	movabsq	$.L.str.16, %rax
	testb	$1, %cl
	cmovneq	%rax, %rdx
	movabsq	$.L.str.15, %rdi
	movb	$0, %al
	callq	printf
	movsbl	-17(%rbp), %eax
	movl	%eax, -48(%rbp)                 # 4-byte Spill
	movsbl	-17(%rbp), %ecx
	xorl	%eax, %eax
                                        # kill: def $al killed $al killed $eax
	cmpl	$97, %ecx
	movb	%al, -41(%rbp)                  # 1-byte Spill
	jl	.LBB0_16
# %bb.15:
	movsbl	-17(%rbp), %eax
	cmpl	$122, %eax
	setle	%al
	movb	%al, -41(%rbp)                  # 1-byte Spill
.LBB0_16:
	movl	-48(%rbp), %esi                 # 4-byte Reload
	movb	-41(%rbp), %cl                  # 1-byte Reload
	movabsq	$.L.str.17, %rdx
	movabsq	$.L.str.19, %rax
	testb	$1, %cl
	cmovneq	%rax, %rdx
	movabsq	$.L.str.18, %rdi
	movb	$0, %al
	callq	printf
	xorl	%eax, %eax
	addq	$48, %rsp
	popq	%rbp
	.cfi_def_cfa %rsp, 8
	retq
.Lfunc_end0:
	.size	main, .Lfunc_end0-main
	.cfi_endproc
                                        # -- End function
	.type	.L.str,@object                  # @.str
	.section	.rodata.str1.1,"aMS",@progbits,1
.L.str:
	.asciz	"Challenge 1:\nThis is line %d inside the file %s\nThe file was created on %s at %s\nIs this file ISO standard? %s \n"
	.size	.L.str, 113

	.type	.L.str.1,@object                # @.str.1
.L.str.1:
	.asciz	"main.c"
	.size	.L.str.1, 7

	.type	.L.str.2,@object                # @.str.2
.L.str.2:
	.asciz	"Feb 28 2024"
	.size	.L.str.2, 12

	.type	.L.str.3,@object                # @.str.3
.L.str.3:
	.asciz	"10:16:55"
	.size	.L.str.3, 9

	.type	.L.str.4,@object                # @.str.4
.L.str.4:
	.asciz	"Yes"
	.size	.L.str.4, 4

	.type	.L.str.5,@object                # @.str.5
.L.str.5:
	.asciz	"\nChallenge 2:\n"
	.size	.L.str.5, 15

	.type	.L.str.6,@object                # @.str.6
.L.str.6:
	.asciz	"Enter the first number: "
	.size	.L.str.6, 25

	.type	.L.str.7,@object                # @.str.7
.L.str.7:
	.asciz	"%d"
	.size	.L.str.7, 3

	.type	.L.str.8,@object                # @.str.8
.L.str.8:
	.asciz	"Enter second number: "
	.size	.L.str.8, 22

	.type	.L.str.9,@object                # @.str.9
.L.str.9:
	.asciz	"The sum of %d and %d is %d\n"
	.size	.L.str.9, 28

	.type	.L.str.10,@object               # @.str.10
.L.str.10:
	.asciz	"\nChallenge 3\n"
	.size	.L.str.10, 14

	.type	.L.str.11,@object               # @.str.11
.L.str.11:
	.asciz	"Enter the number to get it squared and cubed: "
	.size	.L.str.11, 47

	.type	.L.str.12,@object               # @.str.12
.L.str.12:
	.asciz	"The value of %d squared is %d and cubed is %d\n"
	.size	.L.str.12, 47

	.type	.L.str.13,@object               # @.str.13
.L.str.13:
	.asciz	"\nChallenge 4\n"
	.size	.L.str.13, 14

	.type	.L.str.14,@object               # @.str.14
.L.str.14:
	.asciz	"Enter a char to have it checked by as upper or lower case "
	.size	.L.str.14, 59

	.type	.L.str.15,@object               # @.str.15
.L.str.15:
	.asciz	"Is %c uppercase? %s\n"
	.size	.L.str.15, 21

	.type	.L.str.16,@object               # @.str.16
.L.str.16:
	.asciz	"yes"
	.size	.L.str.16, 4

	.type	.L.str.17,@object               # @.str.17
.L.str.17:
	.asciz	"no"
	.size	.L.str.17, 3

	.type	.L.str.18,@object               # @.str.18
.L.str.18:
	.asciz	"Is %c lowercase? %s\n"
	.size	.L.str.18, 21

	.type	.L.str.19,@object               # @.str.19
.L.str.19:
	.asciz	"YES"
	.size	.L.str.19, 4

	.ident	"FreeBSD clang version 16.0.6 (https://github.com/llvm/llvm-project.git llvmorg-16.0.6-0-g7cbf1a259152)"
	.section	".note.GNU-stack","",@progbits
	.addrsig
	.addrsig_sym printf
	.addrsig_sym scanf
	.addrsig_sym __srget
	.addrsig_sym getc
	.addrsig_sym __isthreaded
	.addrsig_sym __stdinp
