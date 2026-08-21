	.file	"factorial.cpp"
	.text
	.p2align 4,,15
	.def	___tcf_0;	.scl	3;	.type	32;	.endef
___tcf_0:
LFB1923:
	.cfi_startproc
	movl	$__ZStL8__ioinit, %ecx
	jmp	__ZNSt8ios_base4InitD1Ev
	.cfi_endproc
LFE1923:
	.p2align 4,,15
	.globl	__Z9factoriali
	.def	__Z9factoriali;	.scl	2;	.type	32;	.endef
__Z9factoriali:
LFB1489:
	.cfi_startproc
	movl	4(%esp), %edx
	movl	$1, %eax
	cmpl	$1, %edx
	jbe	L5
	.p2align 4,,10
L4:
	imull	%edx, %eax
	subl	$1, %edx
	cmpl	$1, %edx
	jne	L4
	rep ret
L5:
	rep ret
	.cfi_endproc
LFE1489:
	.def	___main;	.scl	2;	.type	32;	.endef
	.section .rdata,"dr"
LC0:
	.ascii "Enter a number: \0"
LC1:
	.ascii "Factorial of \0"
LC2:
	.ascii " is: \0"
	.section	.text.startup,"x"
	.p2align 4,,15
	.globl	_main
	.def	_main;	.scl	2;	.type	32;	.endef
_main:
LFB1490:
	.cfi_startproc
	leal	4(%esp), %ecx
	.cfi_def_cfa 1, 0
	andl	$-16, %esp
	pushl	-4(%ecx)
	pushl	%ebp
	.cfi_escape 0x10,0x5,0x2,0x75,0
	movl	%esp, %ebp
	pushl	%esi
	pushl	%ebx
	pushl	%ecx
	.cfi_escape 0xf,0x3,0x75,0x74,0x6
	.cfi_escape 0x10,0x6,0x2,0x75,0x7c
	.cfi_escape 0x10,0x3,0x2,0x75,0x78
	subl	$44, %esp
	call	___main
	movl	$LC0, 4(%esp)
	movl	$__ZSt4cout, (%esp)
	call	__ZStlsISt11char_traitsIcEERSt13basic_ostreamIcT_ES5_PKc
	leal	-28(%ebp), %eax
	movl	$__ZSt3cin, %ecx
	movl	%eax, (%esp)
	call	__ZNSirsERi
	movl	-28(%ebp), %esi
	subl	$4, %esp
	cmpl	$1, %esi
	jbe	L11
	movl	%esi, %eax
	movl	$1, %ebx
	.p2align 4,,10
L10:
	imull	%eax, %ebx
	subl	$1, %eax
	cmpl	$1, %eax
	jne	L10
L9:
	movl	$13, 8(%esp)
	movl	$LC1, 4(%esp)
	movl	$__ZSt4cout, (%esp)
	call	__ZSt16__ostream_insertIcSt11char_traitsIcEERSt13basic_ostreamIT_T0_ES6_PKS3_i
	movl	$__ZSt4cout, %ecx
	movl	%esi, (%esp)
	call	__ZNSolsEi
	subl	$4, %esp
	movl	%eax, %esi
	movl	$5, 8(%esp)
	movl	$LC2, 4(%esp)
	movl	%eax, (%esp)
	call	__ZSt16__ostream_insertIcSt11char_traitsIcEERSt13basic_ostreamIT_T0_ES6_PKS3_i
	movl	%esi, %ecx
	movl	%ebx, (%esp)
	call	__ZNSolsEi
	subl	$4, %esp
	movl	%eax, (%esp)
	call	__ZSt4endlIcSt11char_traitsIcEERSt13basic_ostreamIT_T0_ES6_
	leal	-12(%ebp), %esp
	xorl	%eax, %eax
	popl	%ecx
	.cfi_remember_state
	.cfi_restore 1
	.cfi_def_cfa 1, 0
	popl	%ebx
	.cfi_restore 3
	popl	%esi
	.cfi_restore 6
	popl	%ebp
	.cfi_restore 5
	leal	-4(%ecx), %esp
	.cfi_def_cfa 4, 4
	ret
L11:
	.cfi_restore_state
	movl	$1, %ebx
	jmp	L9
	.cfi_endproc
LFE1490:
	.p2align 4,,15
	.def	__GLOBAL__sub_I__Z9factoriali;	.scl	3;	.type	32;	.endef
__GLOBAL__sub_I__Z9factoriali:
LFB1924:
	.cfi_startproc
	subl	$28, %esp
	.cfi_def_cfa_offset 32
	movl	$__ZStL8__ioinit, %ecx
	call	__ZNSt8ios_base4InitC1Ev
	movl	$___tcf_0, (%esp)
	call	_atexit
	addl	$28, %esp
	.cfi_def_cfa_offset 4
	ret
	.cfi_endproc
LFE1924:
	.section	.ctors,"w"
	.align 4
	.long	__GLOBAL__sub_I__Z9factoriali
.lcomm __ZStL8__ioinit,1,1
	.ident	"GCC: (MinGW.org GCC-6.3.0-1) 6.3.0"
	.def	__ZNSt8ios_base4InitD1Ev;	.scl	2;	.type	32;	.endef
	.def	__ZStlsISt11char_traitsIcEERSt13basic_ostreamIcT_ES5_PKc;	.scl	2;	.type	32;	.endef
	.def	__ZNSirsERi;	.scl	2;	.type	32;	.endef
	.def	__ZSt16__ostream_insertIcSt11char_traitsIcEERSt13basic_ostreamIT_T0_ES6_PKS3_i;	.scl	2;	.type	32;	.endef
	.def	__ZNSolsEi;	.scl	2;	.type	32;	.endef
	.def	__ZSt4endlIcSt11char_traitsIcEERSt13basic_ostreamIT_T0_ES6_;	.scl	2;	.type	32;	.endef
	.def	__ZNSt8ios_base4InitC1Ev;	.scl	2;	.type	32;	.endef
	.def	_atexit;	.scl	2;	.type	32;	.endef
