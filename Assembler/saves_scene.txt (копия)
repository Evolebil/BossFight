	.file	"saves_scene.cpp"
	.intel_syntax noprefix
# GNU C++17 (GCC) version 15.2.1 20260209 (x86_64-pc-linux-gnu)
#	compiled by GNU C version 15.2.1 20260209, GMP version 6.3.0, MPFR version 4.2.2, MPC version 1.3.1, isl version isl-0.27-GMP

# warning: MPC header version 1.3.1 differs from library version 1.4.1.
# GGC heuristics: --param ggc-min-expand=100 --param ggc-min-heapsize=131072
# options passed: -masm=intel -mtune=generic -march=x86-64 -O3 -std=c++17 -fno-builtin -fno-plt -fno-inline
	.text
#APP
	.globl _ZSt21ios_base_library_initv
#NO_APP
	.align 2
	.p2align 4
	.globl	_ZN10SavesScene6updateEf
	.type	_ZN10SavesScene6updateEf, @function
_ZN10SavesScene6updateEf:
.LFB12873:
	.cfi_startproc
# saves_scene.cpp:292: }
	ret	
	.cfi_endproc
.LFE12873:
	.size	_ZN10SavesScene6updateEf, .-_ZN10SavesScene6updateEf
	.align 2
	.p2align 4
	.globl	_ZN10SavesScene12getNextSceneEv
	.type	_ZN10SavesScene12getNextSceneEv, @function
_ZN10SavesScene12getNextSceneEv:
.LFB12875:
	.cfi_startproc
# saves_scene.cpp:375:     return nextScene;
	mov	eax, DWORD PTR 8[rdi]	# this_2(D)->nextScene, this_2(D)->nextScene
# saves_scene.cpp:376: }
	ret	
	.cfi_endproc
.LFE12875:
	.size	_ZN10SavesScene12getNextSceneEv, .-_ZN10SavesScene12getNextSceneEv
	.p2align 4
	.type	_ZL14countUTF8CharsRKNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEEE, @function
_ZL14countUTF8CharsRKNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEEE:
.LFB12825:
	.cfi_startproc
	push	r13	#
	.cfi_def_cfa_offset 16
	.cfi_offset 13, -16
	push	r12	#
	.cfi_def_cfa_offset 24
	.cfi_offset 12, -24
	mov	r12, rdi	# str, str
	push	rbp	#
	.cfi_def_cfa_offset 32
	.cfi_offset 6, -32
	push	rbx	#
	.cfi_def_cfa_offset 40
	.cfi_offset 3, -40
	sub	rsp, 8	#,
	.cfi_def_cfa_offset 48
# saves_scene.cpp:19:     for (size_t i = 0; i < str.size(); ++i)
	call	[QWORD PTR _ZNKSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEE4sizeEv@GOTPCREL[rip]]	#
# saves_scene.cpp:19:     for (size_t i = 0; i < str.size(); ++i)
	test	rax, rax	# _5
	je	.L8	#,
	mov	r13, rax	# _5,
# saves_scene.cpp:19:     for (size_t i = 0; i < str.size(); ++i)
	xor	ebx, ebx	# i
# saves_scene.cpp:18:     size_t count = 0;
	xor	ebp, ebp	# <retval>
	.p2align 4
	.p2align 3
.L7:
# saves_scene.cpp:20:         if ((str[i] & 0xC0) != 0x80) count++;
	mov	rsi, rbx	#, i
	mov	rdi, r12	#, str
	call	[QWORD PTR _ZNKSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEEixEm@GOTPCREL[rip]]	#
# saves_scene.cpp:20:         if ((str[i] & 0xC0) != 0x80) count++;
	movsx	eax, BYTE PTR [rax]	# _3, *_1
	and	eax, 192	# _4,
# saves_scene.cpp:20:         if ((str[i] & 0xC0) != 0x80) count++;
	cmp	eax, 128	# _4,
	setne	al	#, tmp109
# saves_scene.cpp:19:     for (size_t i = 0; i < str.size(); ++i)
	add	rbx, 1	# i,
# saves_scene.cpp:20:         if ((str[i] & 0xC0) != 0x80) count++;
	movzx	eax, al	# tmp109, tmp109
	add	rbp, rax	# <retval>, tmp109
# saves_scene.cpp:19:     for (size_t i = 0; i < str.size(); ++i)
	cmp	r13, rbx	# _5, i
	jne	.L7	#,
# saves_scene.cpp:22: }
	add	rsp, 8	#,
	.cfi_remember_state
	.cfi_def_cfa_offset 40
	mov	rax, rbp	#, <retval>
	pop	rbx	#
	.cfi_def_cfa_offset 32
	pop	rbp	#
	.cfi_def_cfa_offset 24
	pop	r12	#
	.cfi_def_cfa_offset 16
	pop	r13	#
	.cfi_def_cfa_offset 8
	ret	
	.p2align 4,,10
	.p2align 3
.L8:
	.cfi_restore_state
	add	rsp, 8	#,
	.cfi_def_cfa_offset 40
# saves_scene.cpp:18:     size_t count = 0;
	xor	ebp, ebp	# <retval>
# saves_scene.cpp:22: }
	pop	rbx	#
	.cfi_def_cfa_offset 32
	mov	rax, rbp	#, <retval>
	pop	rbp	#
	.cfi_def_cfa_offset 24
	pop	r12	#
	.cfi_def_cfa_offset 16
	pop	r13	#
	.cfi_def_cfa_offset 8
	ret	
	.cfi_endproc
.LFE12825:
	.size	_ZL14countUTF8CharsRKNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEEE, .-_ZL14countUTF8CharsRKNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEEE
	.p2align 4
	.type	_ZL12truncateUTF8RKNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEEEm, @function
_ZL12truncateUTF8RKNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEEEm:
.LFB12826:
	.cfi_startproc
	push	r15	#
	.cfi_def_cfa_offset 16
	.cfi_offset 15, -16
	push	r14	#
	.cfi_def_cfa_offset 24
	.cfi_offset 14, -24
	mov	r14, rdi	# <retval>, .result_ptr
# saves_scene.cpp:25:     if (countUTF8Chars(str) <= maxChars) return str;
	mov	rdi, rsi	#, str
# saves_scene.cpp:24: static std::string truncateUTF8(const std::string& str, size_t maxChars) {
	push	r13	#
	.cfi_def_cfa_offset 32
	.cfi_offset 13, -32
	push	r12	#
	.cfi_def_cfa_offset 40
	.cfi_offset 12, -40
	push	rbp	#
	.cfi_def_cfa_offset 48
	.cfi_offset 6, -48
	mov	rbp, rsi	# str, str
	push	rbx	#
	.cfi_def_cfa_offset 56
	.cfi_offset 3, -56
	sub	rsp, 24	#,
	.cfi_def_cfa_offset 80
# saves_scene.cpp:24: static std::string truncateUTF8(const std::string& str, size_t maxChars) {
	mov	r12, QWORD PTR fs:40	# maxChars, MEM[(<address-space-1> long unsigned int *)40B]
	mov	QWORD PTR 8[rsp], r12	# D.172680, maxChars
	mov	r12, rdx	# maxChars, maxChars
# saves_scene.cpp:25:     if (countUTF8Chars(str) <= maxChars) return str;
	call	_ZL14countUTF8CharsRKNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEEE	#
# saves_scene.cpp:25:     if (countUTF8Chars(str) <= maxChars) return str;
	cmp	r12, rax	# maxChars, _1
	jnb	.L14	#,
# saves_scene.cpp:27:     while (bytePos < str.size() && chars < maxChars) {
	mov	rdi, rbp	#, str
# saves_scene.cpp:26:     size_t chars = 0, bytePos = 0;
	xor	ebx, ebx	# bytePos
# saves_scene.cpp:26:     size_t chars = 0, bytePos = 0;
	xor	r15d, r15d	# chars
# saves_scene.cpp:27:     while (bytePos < str.size() && chars < maxChars) {
	call	[QWORD PTR _ZNKSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEE4sizeEv@GOTPCREL[rip]]	#
	mov	r13, rax	# _4,
# saves_scene.cpp:27:     while (bytePos < str.size() && chars < maxChars) {
	test	rax, rax	# _4
	jne	.L15	#,
	jmp	.L16	#
	.p2align 4,,10
	.p2align 3
.L22:
# saves_scene.cpp:29:         if      ((c & 0x80) == 0x00) bytePos += 1;
	add	rbx, 1	# bytePos,
.L18:
# saves_scene.cpp:34:         chars++;
	add	r15, 1	# chars,
# saves_scene.cpp:27:     while (bytePos < str.size() && chars < maxChars) {
	cmp	r15, r12	# chars, maxChars
	jnb	.L16	#,
.L37:
	cmp	rbx, r13	# bytePos, _4
	jnb	.L16	#,
.L15:
# saves_scene.cpp:28:         unsigned char c = static_cast<unsigned char>(str[bytePos]);
	mov	rsi, rbx	#, bytePos
	mov	rdi, rbp	#, str
	call	[QWORD PTR _ZNKSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEEixEm@GOTPCREL[rip]]	#
# saves_scene.cpp:28:         unsigned char c = static_cast<unsigned char>(str[bytePos]);
	movzx	eax, BYTE PTR [rax]	# _3, *_2
# saves_scene.cpp:29:         if      ((c & 0x80) == 0x00) bytePos += 1;
	test	al, al	# _3
	jns	.L22	#,
# saves_scene.cpp:30:         else if ((c & 0xE0) == 0xC0) bytePos += 2;
	mov	edx, eax	# _14, _3
	and	edx, -32	# _14,
	cmp	dl, -64	# _14,
	je	.L35	#,
# saves_scene.cpp:31:         else if ((c & 0xF0) == 0xE0) bytePos += 3;
	mov	edx, eax	# _13, _3
	and	edx, -16	# _13,
	cmp	dl, -32	# _13,
	je	.L36	#,
# saves_scene.cpp:32:         else if ((c & 0xF8) == 0xF0) bytePos += 4;
	and	eax, -8	# _12,
# saves_scene.cpp:32:         else if ((c & 0xF8) == 0xF0) bytePos += 4;
	lea	rdx, 4[rbx]	# tmp125,
	add	rbx, 1	# tmp124,
	cmp	al, -16	# _12,
	cmove	rbx, rdx	# tmp124,, bytePos, tmp125
# saves_scene.cpp:34:         chars++;
	add	r15, 1	# chars,
# saves_scene.cpp:27:     while (bytePos < str.size() && chars < maxChars) {
	cmp	r15, r12	# chars, maxChars
	jb	.L37	#,
	.p2align 4
	.p2align 3
.L16:
# saves_scene.cpp:36:     return str.substr(0, bytePos);
	mov	rcx, rbx	#, bytePos
	xor	edx, edx	#
	mov	rsi, rbp	#, str
	mov	rdi, r14	#, <retval>
	call	[QWORD PTR _ZNKSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEE6substrEmm@GOTPCREL[rip]]	#
.L13:
# saves_scene.cpp:37: }
	mov	rax, QWORD PTR 8[rsp]	# tmp132, D.172680
	sub	rax, QWORD PTR fs:40	# tmp132, MEM[(<address-space-1> long unsigned int *)40B]
	jne	.L38	#,
	add	rsp, 24	#,
	.cfi_remember_state
	.cfi_def_cfa_offset 56
	mov	rax, r14	#, <retval>
	pop	rbx	#
	.cfi_def_cfa_offset 48
	pop	rbp	#
	.cfi_def_cfa_offset 40
	pop	r12	#
	.cfi_def_cfa_offset 32
	pop	r13	#
	.cfi_def_cfa_offset 24
	pop	r14	#
	.cfi_def_cfa_offset 16
	pop	r15	#
	.cfi_def_cfa_offset 8
	ret	
	.p2align 4,,10
	.p2align 3
.L35:
	.cfi_restore_state
# saves_scene.cpp:30:         else if ((c & 0xE0) == 0xC0) bytePos += 2;
	add	rbx, 2	# bytePos,
	jmp	.L18	#
	.p2align 4,,10
	.p2align 3
.L36:
# saves_scene.cpp:31:         else if ((c & 0xF0) == 0xE0) bytePos += 3;
	add	rbx, 3	# bytePos,
	jmp	.L18	#
	.p2align 4,,10
	.p2align 3
.L14:
# saves_scene.cpp:25:     if (countUTF8Chars(str) <= maxChars) return str;
	mov	rsi, rbp	#, str
	mov	rdi, r14	#, <retval>
	call	[QWORD PTR _ZNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEEC1ERKS4_@GOTPCREL[rip]]	#
# saves_scene.cpp:25:     if (countUTF8Chars(str) <= maxChars) return str;
	jmp	.L13	#
.L38:
# saves_scene.cpp:37: }
	call	[QWORD PTR __stack_chk_fail@GOTPCREL[rip]]	#
	.cfi_endproc
.LFE12826:
	.size	_ZL12truncateUTF8RKNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEEEm, .-_ZL12truncateUTF8RKNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEEEm
	.p2align 4
	.type	_ZL15popLastUTF8CharRNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEEE, @function
_ZL15popLastUTF8CharRNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEEE:
.LFB12827:
	.cfi_startproc
	push	rbp	#
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	mov	rbp, rdi	# str, str
	push	rbx	#
	.cfi_def_cfa_offset 24
	.cfi_offset 3, -24
	sub	rsp, 8	#,
	.cfi_def_cfa_offset 32
# saves_scene.cpp:40:     if (str.empty()) return;
	call	[QWORD PTR _ZNKSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEE5emptyEv@GOTPCREL[rip]]	#
# saves_scene.cpp:40:     if (str.empty()) return;
	test	al, al	# retval.74_7
	jne	.L39	#,
# saves_scene.cpp:41:     size_t pos = str.length() - 1;
	mov	rdi, rbp	#, str
	call	[QWORD PTR _ZNKSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEE6lengthEv@GOTPCREL[rip]]	#
# saves_scene.cpp:42:     while (pos > 0 && (static_cast<unsigned char>(str[pos]) & 0xC0) == 0x80)
	sub	rax, 1	# _1,
	mov	rbx, rax	# pos, _1
	jne	.L42	#,
	jmp	.L41	#
	.p2align 4,,10
	.p2align 3
.L48:
	sub	rbx, 1	# pos,
	je	.L41	#,
.L42:
# saves_scene.cpp:42:     while (pos > 0 && (static_cast<unsigned char>(str[pos]) & 0xC0) == 0x80)
	mov	rsi, rbx	#, pos
	mov	rdi, rbp	#, str
	call	[QWORD PTR _ZNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEEixEm@GOTPCREL[rip]]	#
# saves_scene.cpp:42:     while (pos > 0 && (static_cast<unsigned char>(str[pos]) & 0xC0) == 0x80)
	movzx	eax, BYTE PTR [rax]	# *_9, *_9
	and	eax, -64	# _11,
	cmp	al, -128	# _11,
	je	.L48	#,
.L41:
# saves_scene.cpp:45: }
	add	rsp, 8	#,
	.cfi_remember_state
	.cfi_def_cfa_offset 24
# saves_scene.cpp:44:     str.erase(pos);
	mov	rsi, rbx	#, pos
	mov	rdi, rbp	#, str
	mov	rdx, -1	#,
# saves_scene.cpp:45: }
	pop	rbx	#
	.cfi_def_cfa_offset 16
	pop	rbp	#
	.cfi_def_cfa_offset 8
# saves_scene.cpp:44:     str.erase(pos);
	jmp	[QWORD PTR _ZNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEE5eraseEmm@GOTPCREL[rip]]	#
	.p2align 4,,10
	.p2align 3
.L39:
	.cfi_restore_state
# saves_scene.cpp:45: }
	add	rsp, 8	#,
	.cfi_def_cfa_offset 24
	pop	rbx	#
	.cfi_def_cfa_offset 16
	pop	rbp	#
	.cfi_def_cfa_offset 8
	ret	
	.cfi_endproc
.LFE12827:
	.size	_ZL15popLastUTF8CharRNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEEE, .-_ZL15popLastUTF8CharRNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEEE
	.p2align 4
	.type	_ZSt3minImERKT_S2_S2_.constprop.0, @function
_ZSt3minImERKT_S2_S2_.constprop.0:
.LFB13893:
	.cfi_startproc
# /usr/include/c++/15.2.1/bits/stl_algobase.h:241:       return __a;
	cmp	QWORD PTR [rsi], 3	# *__b_1(D),
	mov	rax, rdi	# __a, __a
	cmovb	rax, rsi	# __b,, __a
# /usr/include/c++/15.2.1/bits/stl_algobase.h:242:     }
	ret	
	.cfi_endproc
.LFE13893:
	.size	_ZSt3minImERKT_S2_S2_.constprop.0, .-_ZSt3minImERKT_S2_S2_.constprop.0
	.section	.text._ZZNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEE12_M_constructIPKcEEvT_S8_St20forward_iterator_tagEN6_GuardD2Ev.constprop.0.isra.0,"axG",@progbits,_ZNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEEC5IS3_EEPKcRKS3_,comdat
	.align 2
	.p2align 4
	.type	_ZZNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEE12_M_constructIPKcEEvT_S8_St20forward_iterator_tagEN6_GuardD2Ev.constprop.0.isra.0, @function
_ZZNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEE12_M_constructIPKcEEvT_S8_St20forward_iterator_tagEN6_GuardD2Ev.constprop.0.isra.0:
.LFB13895:
	.cfi_startproc
# /usr/include/c++/15.2.1/bits/basic_string.tcc:248: 	  ~_Guard() { if (_M_guarded) _M_guarded->_M_dispose(); }
	ret	
	.cfi_endproc
.LFE13895:
	.size	_ZZNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEE12_M_constructIPKcEEvT_S8_St20forward_iterator_tagEN6_GuardD2Ev.constprop.0.isra.0, .-_ZZNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEE12_M_constructIPKcEEvT_S8_St20forward_iterator_tagEN6_GuardD2Ev.constprop.0.isra.0
	.section	.text._ZNSt15__new_allocatorImE8allocateEmPKv.isra.0,"axG",@progbits,_ZNSt6vectorIbSaIbEE13_M_insert_auxESt13_Bit_iteratorb,comdat
	.align 2
	.p2align 4
	.type	_ZNSt15__new_allocatorImE8allocateEmPKv.isra.0, @function
_ZNSt15__new_allocatorImE8allocateEmPKv.isra.0:
.LFB13896:
	.cfi_startproc
# /usr/include/c++/15.2.1/bits/new_allocator.h:134: 	if (__builtin_expect(__n > this->_M_max_size(), false))
	mov	rax, rdi	# tmp106, __n
	shr	rax, 60	# tmp106,
	jne	.L59	#,
# /usr/include/c++/15.2.1/bits/new_allocator.h:151: 	return static_cast<_Tp*>(_GLIBCXX_OPERATOR_NEW(__n * sizeof(_Tp)));
	sal	rdi, 3	# _5,
	jmp	[QWORD PTR _Znwm@GOTPCREL[rip]]	#
	.p2align 4,,10
	.p2align 3
.L59:
# /usr/include/c++/15.2.1/bits/new_allocator.h:126:       allocate(size_type __n, const void* = static_cast<const void*>(0))
	sub	rsp, 8	#,
	.cfi_def_cfa_offset 16
# /usr/include/c++/15.2.1/bits/new_allocator.h:138: 	    if (__n > (std::size_t(-1) / sizeof(_Tp)))
	shr	rdi, 61	# tmp107,
	je	.L55	#,
# /usr/include/c++/15.2.1/bits/new_allocator.h:139: 	      std::__throw_bad_array_new_length();
	call	[QWORD PTR _ZSt28__throw_bad_array_new_lengthv@GOTPCREL[rip]]	#
	.p2align 4,,10
	.p2align 3
.L55:
# /usr/include/c++/15.2.1/bits/new_allocator.h:140: 	    std::__throw_bad_alloc();
	call	[QWORD PTR _ZSt17__throw_bad_allocv@GOTPCREL[rip]]	#
	.cfi_endproc
.LFE13896:
	.size	_ZNSt15__new_allocatorImE8allocateEmPKv.isra.0, .-_ZNSt15__new_allocatorImE8allocateEmPKv.isra.0
	.text
	.align 2
	.p2align 4
	.type	_ZNSt15__new_allocatorI6ButtonE8allocateEmPKv.isra.0, @function
_ZNSt15__new_allocatorI6ButtonE8allocateEmPKv.isra.0:
.LFB13897:
	.cfi_startproc
# /usr/include/c++/15.2.1/bits/new_allocator.h:134: 	if (__builtin_expect(__n > this->_M_max_size(), false))
	movabs	rax, 164703072086692425	# tmp101,
	cmp	rax, rdi	# tmp101, __n
	jb	.L66	#,
# /usr/include/c++/15.2.1/bits/new_allocator.h:151: 	return static_cast<_Tp*>(_GLIBCXX_OPERATOR_NEW(__n * sizeof(_Tp)));
	imul	rdi, rdi, 56	# _5, __n,
	jmp	[QWORD PTR _Znwm@GOTPCREL[rip]]	#
	.p2align 4,,10
	.p2align 3
.L66:
# /usr/include/c++/15.2.1/bits/new_allocator.h:138: 	    if (__n > (std::size_t(-1) / sizeof(_Tp)))
	movabs	rax, 329406144173384850	# tmp102,
# /usr/include/c++/15.2.1/bits/new_allocator.h:126:       allocate(size_type __n, const void* = static_cast<const void*>(0))
	sub	rsp, 8	#,
	.cfi_def_cfa_offset 16
# /usr/include/c++/15.2.1/bits/new_allocator.h:138: 	    if (__n > (std::size_t(-1) / sizeof(_Tp)))
	cmp	rax, rdi	# tmp102, __n
	jnb	.L62	#,
# /usr/include/c++/15.2.1/bits/new_allocator.h:139: 	      std::__throw_bad_array_new_length();
	call	[QWORD PTR _ZSt28__throw_bad_array_new_lengthv@GOTPCREL[rip]]	#
	.p2align 4,,10
	.p2align 3
.L62:
# /usr/include/c++/15.2.1/bits/new_allocator.h:140: 	    std::__throw_bad_alloc();
	call	[QWORD PTR _ZSt17__throw_bad_allocv@GOTPCREL[rip]]	#
	.cfi_endproc
.LFE13897:
	.size	_ZNSt15__new_allocatorI6ButtonE8allocateEmPKv.isra.0, .-_ZNSt15__new_allocatorI6ButtonE8allocateEmPKv.isra.0
	.section	.text._ZNSt15__new_allocatorImE10deallocateEPmm.isra.0,"axG",@progbits,_ZNSt13_Bvector_baseISaIbEE13_M_deallocateEv,comdat
	.align 2
	.p2align 4
	.type	_ZNSt15__new_allocatorImE10deallocateEPmm.isra.0, @function
_ZNSt15__new_allocatorImE10deallocateEPmm.isra.0:
.LFB13898:
	.cfi_startproc
# /usr/include/c++/15.2.1/bits/new_allocator.h:172: 	_GLIBCXX_OPERATOR_DELETE(_GLIBCXX_SIZED_DEALLOC(__p, __n));
	sal	rsi, 3	# _2,
	jmp	[QWORD PTR _ZdlPvm@GOTPCREL[rip]]	#
	.cfi_endproc
.LFE13898:
	.size	_ZNSt15__new_allocatorImE10deallocateEPmm.isra.0, .-_ZNSt15__new_allocatorImE10deallocateEPmm.isra.0
	.text
	.align 2
	.p2align 4
	.type	_ZNSt15__new_allocatorI6ButtonE10deallocateEPS0_m.isra.0, @function
_ZNSt15__new_allocatorI6ButtonE10deallocateEPS0_m.isra.0:
.LFB13899:
	.cfi_startproc
# /usr/include/c++/15.2.1/bits/new_allocator.h:172: 	_GLIBCXX_OPERATOR_DELETE(_GLIBCXX_SIZED_DEALLOC(__p, __n));
	imul	rsi, rsi, 56	# _2, __n,
	jmp	[QWORD PTR _ZdlPvm@GOTPCREL[rip]]	#
	.cfi_endproc
.LFE13899:
	.size	_ZNSt15__new_allocatorI6ButtonE10deallocateEPS0_m.isra.0, .-_ZNSt15__new_allocatorI6ButtonE10deallocateEPS0_m.isra.0
	.section	.text._ZNSt15__new_allocatorI9SaveEntryE10deallocateEPS0_m.isra.0,"axG",@progbits,_ZNSt12_Vector_baseI9SaveEntrySaIS0_EED5Ev,comdat
	.align 2
	.p2align 4
	.type	_ZNSt15__new_allocatorI9SaveEntryE10deallocateEPS0_m.isra.0, @function
_ZNSt15__new_allocatorI9SaveEntryE10deallocateEPS0_m.isra.0:
.LFB13900:
	.cfi_startproc
# /usr/include/c++/15.2.1/bits/new_allocator.h:172: 	_GLIBCXX_OPERATOR_DELETE(_GLIBCXX_SIZED_DEALLOC(__p, __n));
	lea	rsi, [rsi+rsi*8]	# _2,
	sal	rsi, 3	# tmp104,
	jmp	[QWORD PTR _ZdlPvm@GOTPCREL[rip]]	#
	.cfi_endproc
.LFE13900:
	.size	_ZNSt15__new_allocatorI9SaveEntryE10deallocateEPS0_m.isra.0, .-_ZNSt15__new_allocatorI9SaveEntryE10deallocateEPS0_m.isra.0
	.text
	.align 2
	.p2align 4
	.type	_ZNSt12_Vector_baseI6ButtonSaIS0_EE11_M_allocateEm.isra.0, @function
_ZNSt12_Vector_baseI6ButtonSaIS0_EE11_M_allocateEm.isra.0:
.LFB13901:
	.cfi_startproc
# /usr/include/c++/15.2.1/bits/stl_vector.h:387: 	return __n != 0 ? _Tr::allocate(_M_impl, __n) : pointer();
	test	rdi, rdi	# __n
	je	.L71	#,
# /usr/include/c++/15.2.1/bits/alloc_traits.h:614:       { return __a.allocate(__n); }
	jmp	_ZNSt15__new_allocatorI6ButtonE8allocateEmPKv.isra.0	#
	.p2align 4,,10
	.p2align 3
.L71:
# /usr/include/c++/15.2.1/bits/stl_vector.h:388:       }
	xor	eax, eax	#
	ret	
	.cfi_endproc
.LFE13901:
	.size	_ZNSt12_Vector_baseI6ButtonSaIS0_EE11_M_allocateEm.isra.0, .-_ZNSt12_Vector_baseI6ButtonSaIS0_EE11_M_allocateEm.isra.0
	.align 2
	.p2align 4
	.type	_ZNKSt13_Bvector_baseISaIbEE13_Bvector_impl11_M_end_addrEv.isra.0, @function
_ZNKSt13_Bvector_baseISaIbEE13_Bvector_impl11_M_end_addrEv.isra.0:
.LFB13902:
	.cfi_startproc
# /usr/include/c++/15.2.1/bits/stl_bvector.h:629: 	_M_end_addr() const _GLIBCXX_NOEXCEPT
	mov	rax, rdi	# ISRA.608, ISRA.608
# /usr/include/c++/15.2.1/bits/stl_bvector.h:634: 	}
	ret	
	.cfi_endproc
.LFE13902:
	.size	_ZNKSt13_Bvector_baseISaIbEE13_Bvector_impl11_M_end_addrEv.isra.0, .-_ZNKSt13_Bvector_baseISaIbEE13_Bvector_impl11_M_end_addrEv.isra.0
	.section	.text._ZNSt6vectorIbSaIbEE15_M_erase_at_endESt13_Bit_iterator.isra.0,"axG",@progbits,_ZNSt6vectorIbSaIbEE5clearEv,comdat
	.align 2
	.p2align 4
	.type	_ZNSt6vectorIbSaIbEE15_M_erase_at_endESt13_Bit_iterator.isra.0, @function
_ZNSt6vectorIbSaIbEE15_M_erase_at_endESt13_Bit_iterator.isra.0:
.LFB13903:
	.cfi_startproc
# /usr/include/c++/15.2.1/bits/stl_bvector.h:1747:       { this->_M_impl._M_finish = __pos; }
	mov	QWORD PTR 16[rdi], rsi	# MEM <unsigned char[12]> [(struct _Bit_iterator *)this_1(D) + 16B], ISRA.612
	mov	DWORD PTR 24[rdi], edx	# MEM <unsigned char[12]> [(struct _Bit_iterator *)this_1(D) + 16B], ISRA.612
# /usr/include/c++/15.2.1/bits/stl_bvector.h:1747:       { this->_M_impl._M_finish = __pos; }
	ret	
	.cfi_endproc
.LFE13903:
	.size	_ZNSt6vectorIbSaIbEE15_M_erase_at_endESt13_Bit_iterator.isra.0, .-_ZNSt6vectorIbSaIbEE15_M_erase_at_endESt13_Bit_iterator.isra.0
	.text
	.align 2
	.p2align 4
	.type	_ZNSt12_Vector_baseI6ButtonSaIS0_EE13_M_deallocateEPS0_m.isra.0, @function
_ZNSt12_Vector_baseI6ButtonSaIS0_EE13_M_deallocateEPS0_m.isra.0:
.LFB13904:
	.cfi_startproc
# /usr/include/c++/15.2.1/bits/stl_vector.h:395: 	if (__p)
	test	rdi, rdi	# __p
	je	.L74	#,
# /usr/include/c++/15.2.1/bits/alloc_traits.h:649:       { __a.deallocate(__p, __n); }
	jmp	_ZNSt15__new_allocatorI6ButtonE10deallocateEPS0_m.isra.0	#
	.p2align 4,,10
	.p2align 3
.L74:
# /usr/include/c++/15.2.1/bits/stl_vector.h:397:       }
	ret	
	.cfi_endproc
.LFE13904:
	.size	_ZNSt12_Vector_baseI6ButtonSaIS0_EE13_M_deallocateEPS0_m.isra.0, .-_ZNSt12_Vector_baseI6ButtonSaIS0_EE13_M_deallocateEPS0_m.isra.0
	.section	.text._ZNSt12_Vector_baseI9SaveEntrySaIS0_EE13_M_deallocateEPS0_m.isra.0,"axG",@progbits,_ZNSt12_Vector_baseI9SaveEntrySaIS0_EED5Ev,comdat
	.align 2
	.p2align 4
	.type	_ZNSt12_Vector_baseI9SaveEntrySaIS0_EE13_M_deallocateEPS0_m.isra.0, @function
_ZNSt12_Vector_baseI9SaveEntrySaIS0_EE13_M_deallocateEPS0_m.isra.0:
.LFB13905:
	.cfi_startproc
# /usr/include/c++/15.2.1/bits/stl_vector.h:395: 	if (__p)
	test	rdi, rdi	# __p
	je	.L76	#,
# /usr/include/c++/15.2.1/bits/alloc_traits.h:649:       { __a.deallocate(__p, __n); }
	jmp	_ZNSt15__new_allocatorI9SaveEntryE10deallocateEPS0_m.isra.0	#
	.p2align 4,,10
	.p2align 3
.L76:
# /usr/include/c++/15.2.1/bits/stl_vector.h:397:       }
	ret	
	.cfi_endproc
.LFE13905:
	.size	_ZNSt12_Vector_baseI9SaveEntrySaIS0_EE13_M_deallocateEPS0_m.isra.0, .-_ZNSt12_Vector_baseI9SaveEntrySaIS0_EE13_M_deallocateEPS0_m.isra.0
	.text
	.align 2
	.p2align 4
	.type	_ZNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEE12_Alloc_hiderC2EPcRKS3_.isra.0, @function
_ZNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEE12_Alloc_hiderC2EPcRKS3_.isra.0:
.LFB13906:
	.cfi_startproc
# /usr/include/c++/15.2.1/bits/basic_string.h:205: 	: allocator_type(__a), _M_p(__dat) { }
	mov	QWORD PTR [rdi], rsi	# *this_1(D)._M_p, __dat
# /usr/include/c++/15.2.1/bits/basic_string.h:205: 	: allocator_type(__a), _M_p(__dat) { }
	ret	
	.cfi_endproc
.LFE13906:
	.size	_ZNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEE12_Alloc_hiderC2EPcRKS3_.isra.0, .-_ZNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEE12_Alloc_hiderC2EPcRKS3_.isra.0
	.section	.text._ZNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEEC2ERKS3_.isra.0,"axG",@progbits,_ZStplIcSt11char_traitsIcESaIcEENSt7__cxx1112basic_stringIT_T0_T1_EERKS8_PKS5_,comdat
	.align 2
	.p2align 4
	.type	_ZNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEEC2ERKS3_.isra.0, @function
_ZNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEEC2ERKS3_.isra.0:
.LFB13907:
	.cfi_startproc
	push	rbx	#
	.cfi_def_cfa_offset 16
	.cfi_offset 3, -16
# /usr/include/c++/15.2.1/bits/basic_string.h:601:       basic_string(const _Alloc& __a) _GLIBCXX_NOEXCEPT
	mov	rbx, rdi	# this, this
# /usr/include/c++/15.2.1/bits/basic_string.h:602:       : _M_dataplus(_M_local_data(), __a)
	call	[QWORD PTR _ZNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEE13_M_local_dataEv@GOTPCREL[rip]]	#
# /usr/include/c++/15.2.1/bits/basic_string.h:602:       : _M_dataplus(_M_local_data(), __a)
	mov	rdi, rbx	#, this
	mov	rsi, rax	#, _3
	call	_ZNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEE12_Alloc_hiderC2EPcRKS3_.isra.0	#
# /usr/include/c++/15.2.1/bits/basic_string.h:605: 	_M_set_length(0);
	xor	esi, esi	#
# /usr/include/c++/15.2.1/bits/basic_string.h:606:       }
	pop	rbx	#
	.cfi_def_cfa_offset 8
# /usr/include/c++/15.2.1/bits/basic_string.h:605: 	_M_set_length(0);
	jmp	[QWORD PTR _ZNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEE13_M_set_lengthEm@GOTPCREL[rip]]	#
	.cfi_endproc
.LFE13907:
	.size	_ZNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEEC2ERKS3_.isra.0, .-_ZNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEEC2ERKS3_.isra.0
	.section	.text._ZSt12__str_concatINSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEEEET_PKNS6_10value_typeENS6_9size_typeES9_SA_RKNS6_14allocator_typeE.isra.0,"axG",@progbits,_ZStplIcSt11char_traitsIcESaIcEENSt7__cxx1112basic_stringIT_T0_T1_EERKS8_PKS5_,comdat
	.p2align 4
	.type	_ZSt12__str_concatINSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEEEET_PKNS6_10value_typeENS6_9size_typeES9_SA_RKNS6_14allocator_typeE.isra.0, @function
_ZSt12__str_concatINSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEEEET_PKNS6_10value_typeENS6_9size_typeES9_SA_RKNS6_14allocator_typeE.isra.0:
.LFB13908:
	.cfi_startproc
	.cfi_personality 0x9b,DW.ref.__gxx_personality_v0
	.cfi_lsda 0x1b,.LLSDA13908
	push	r14	#
	.cfi_def_cfa_offset 16
	.cfi_offset 14, -16
	mov	r14, rsi	# __lhs, __lhs
	push	r13	#
	.cfi_def_cfa_offset 24
	.cfi_offset 13, -24
	mov	r13, rcx	# __rhs, __rhs
	push	r12	#
	.cfi_def_cfa_offset 32
	.cfi_offset 12, -32
	mov	r12, rdx	# __lhs_len, __lhs_len
	push	rbp	#
	.cfi_def_cfa_offset 40
	.cfi_offset 6, -40
	mov	rbp, r8	# __rhs_len, __rhs_len
	push	rbx	#
	.cfi_def_cfa_offset 48
	.cfi_offset 3, -48
# /usr/include/c++/15.2.1/bits/basic_string.h:3815:     __str_concat(typename _Str::value_type const* __lhs,
	mov	rbx, rdi	# <retval>, .result_ptr
# /usr/include/c++/15.2.1/bits/basic_string.h:3823:       _Str __str(_Alloc_traits::_S_select_on_copy(__a));
	call	_ZNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEEC2ERKS3_.isra.0	#
# /usr/include/c++/15.2.1/bits/basic_string.h:3824:       __str.reserve(__lhs_len + __rhs_len);
	lea	rsi, [r12+rbp]	# _4,
	mov	rdi, rbx	#, <retval>
.LEHB0:
	call	[QWORD PTR _ZNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEE7reserveEm@GOTPCREL[rip]]	#
# /usr/include/c++/15.2.1/bits/basic_string.h:3825:       __str.append(__lhs, __lhs_len);
	mov	rdx, r12	#, __lhs_len
	mov	rsi, r14	#, __lhs
	mov	rdi, rbx	#, <retval>
	call	[QWORD PTR _ZNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEE6appendEPKcm@GOTPCREL[rip]]	#
# /usr/include/c++/15.2.1/bits/basic_string.h:3826:       __str.append(__rhs, __rhs_len);
	mov	rdx, rbp	#, __rhs_len
	mov	rsi, r13	#, __rhs
	mov	rdi, rbx	#, <retval>
	call	[QWORD PTR _ZNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEE6appendEPKcm@GOTPCREL[rip]]	#
.LEHE0:
# /usr/include/c++/15.2.1/bits/basic_string.h:3828:     }
	mov	rax, rbx	#, <retval>
	pop	rbx	#
	.cfi_remember_state
	.cfi_def_cfa_offset 40
	pop	rbp	#
	.cfi_def_cfa_offset 32
	pop	r12	#
	.cfi_def_cfa_offset 24
	pop	r13	#
	.cfi_def_cfa_offset 16
	pop	r14	#
	.cfi_def_cfa_offset 8
	ret	
.L83:
	.cfi_restore_state
	mov	rbp, rax	# tmp113,
.L82:
	mov	rdi, rbx	#, <retval>
	call	[QWORD PTR _ZNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEED1Ev@GOTPCREL[rip]]	#
	mov	rdi, rbp	#, tmp113
.LEHB1:
	call	[QWORD PTR _Unwind_Resume@GOTPCREL[rip]]	#
.LEHE1:
	.cfi_endproc
.LFE13908:
	.section	.gcc_except_table._ZSt12__str_concatINSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEEEET_PKNS6_10value_typeENS6_9size_typeES9_SA_RKNS6_14allocator_typeE.isra.0,"aG",@progbits,_ZStplIcSt11char_traitsIcESaIcEENSt7__cxx1112basic_stringIT_T0_T1_EERKS8_PKS5_,comdat
.LLSDA13908:
	.byte	0xff
	.byte	0xff
	.byte	0x1
	.uleb128 .LLSDACSE13908-.LLSDACSB13908
.LLSDACSB13908:
	.uleb128 .LEHB0-.LFB13908
	.uleb128 .LEHE0-.LEHB0
	.uleb128 .L83-.LFB13908
	.uleb128 0
	.uleb128 .LEHB1-.LFB13908
	.uleb128 .LEHE1-.LEHB1
	.uleb128 0
	.uleb128 0
.LLSDACSE13908:
	.section	.text._ZSt12__str_concatINSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEEEET_PKNS6_10value_typeENS6_9size_typeES9_SA_RKNS6_14allocator_typeE.isra.0,"axG",@progbits,_ZStplIcSt11char_traitsIcESaIcEENSt7__cxx1112basic_stringIT_T0_T1_EERKS8_PKS5_,comdat
	.size	_ZSt12__str_concatINSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEEEET_PKNS6_10value_typeENS6_9size_typeES9_SA_RKNS6_14allocator_typeE.isra.0, .-_ZSt12__str_concatINSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEEEET_PKNS6_10value_typeENS6_9size_typeES9_SA_RKNS6_14allocator_typeE.isra.0
	.text
	.align 2
	.p2align 4
	.type	_ZNSt6vectorI6ButtonSaIS0_EEixEm.isra.0, @function
_ZNSt6vectorI6ButtonSaIS0_EEixEm.isra.0:
.LFB13909:
	.cfi_startproc
# /usr/include/c++/15.2.1/bits/stl_vector.h:1264: 	return *(this->_M_impl._M_start + __n);
	imul	rsi, rsi, 56	# _3, __n,
# /usr/include/c++/15.2.1/bits/stl_vector.h:1264: 	return *(this->_M_impl._M_start + __n);
	lea	rax, [rdi+rsi]	# _4,
# /usr/include/c++/15.2.1/bits/stl_vector.h:1265:       }
	ret	
	.cfi_endproc
.LFE13909:
	.size	_ZNSt6vectorI6ButtonSaIS0_EEixEm.isra.0, .-_ZNSt6vectorI6ButtonSaIS0_EEixEm.isra.0
	.align 2
	.p2align 4
	.type	_ZNKSt6vectorI6ButtonSaIS0_EE4sizeEv.isra.0, @function
_ZNKSt6vectorI6ButtonSaIS0_EE4sizeEv.isra.0:
.LFB13910:
	.cfi_startproc
# /usr/include/c++/15.2.1/bits/stl_vector.h:1119: 	ptrdiff_t __dif = this->_M_impl._M_finish - this->_M_impl._M_start;
	movabs	rax, 7905747460161236407	# tmp107,
# /usr/include/c++/15.2.1/bits/stl_vector.h:1119: 	ptrdiff_t __dif = this->_M_impl._M_finish - this->_M_impl._M_start;
	sub	rsi, rdi	# _3, ISRA.635
# /usr/include/c++/15.2.1/bits/stl_vector.h:1119: 	ptrdiff_t __dif = this->_M_impl._M_finish - this->_M_impl._M_start;
	sar	rsi, 3	# tmp105,
	imul	rax, rsi	# __dif_4, tmp105
# /usr/include/c++/15.2.1/bits/stl_vector.h:1123:       }
	ret	
	.cfi_endproc
.LFE13910:
	.size	_ZNKSt6vectorI6ButtonSaIS0_EE4sizeEv.isra.0, .-_ZNKSt6vectorI6ButtonSaIS0_EE4sizeEv.isra.0
	.section	.text._ZStmiRKSt18_Bit_iterator_baseS1_.isra.0,"axG",@progbits,_ZNKSt6vectorIbSaIbEE4sizeEv,comdat
	.p2align 4
	.type	_ZStmiRKSt18_Bit_iterator_baseS1_.isra.0, @function
_ZStmiRKSt18_Bit_iterator_baseS1_.isra.0:
.LFB13911:
	.cfi_startproc
# /usr/include/c++/15.2.1/bits/stl_bvector.h:302:       return (int(_S_word_bit) * (__x._M_p - __y._M_p)
	sub	rdi, rdx	# _5, ISRA.642
# /usr/include/c++/15.2.1/bits/stl_bvector.h:303: 	      + __x._M_offset - __y._M_offset);
	mov	esi, esi	# _7, ISRA.641
# /usr/include/c++/15.2.1/bits/stl_bvector.h:303: 	      + __x._M_offset - __y._M_offset);
	mov	ecx, ecx	# _9, ISRA.643
# /usr/include/c++/15.2.1/bits/stl_bvector.h:303: 	      + __x._M_offset - __y._M_offset);
	lea	rax, [rsi+rdi*8]	# _8,
# /usr/include/c++/15.2.1/bits/stl_bvector.h:303: 	      + __x._M_offset - __y._M_offset);
	sub	rax, rcx	# _10, _9
# /usr/include/c++/15.2.1/bits/stl_bvector.h:304:     }
	ret	
	.cfi_endproc
.LFE13911:
	.size	_ZStmiRKSt18_Bit_iterator_baseS1_.isra.0, .-_ZStmiRKSt18_Bit_iterator_baseS1_.isra.0
	.text
	.p2align 4
	.type	_ZSteqRKSt18_Bit_iterator_baseS1_.isra.0, @function
_ZSteqRKSt18_Bit_iterator_baseS1_.isra.0:
.LFB13912:
	.cfi_startproc
# /usr/include/c++/15.2.1/bits/stl_bvector.h:250:       return __x._M_p == __y._M_p && __x._M_offset == __y._M_offset;
	cmp	rdi, rdx	# ISRA.647, ISRA.649
	sete	al	#, _3
# /usr/include/c++/15.2.1/bits/stl_bvector.h:250:       return __x._M_p == __y._M_p && __x._M_offset == __y._M_offset;
	cmp	esi, ecx	# ISRA.648, ISRA.650
	sete	dl	#, _4
	and	eax, edx	# _2, _4
# /usr/include/c++/15.2.1/bits/stl_bvector.h:251:     }
	ret	
	.cfi_endproc
.LFE13912:
	.size	_ZSteqRKSt18_Bit_iterator_baseS1_.isra.0, .-_ZSteqRKSt18_Bit_iterator_baseS1_.isra.0
	.p2align 4
	.type	_ZStneRKSt18_Bit_iterator_baseS1_.isra.0, @function
_ZStneRKSt18_Bit_iterator_baseS1_.isra.0:
.LFB13913:
	.cfi_startproc
# /usr/include/c++/15.2.1/bits/stl_bvector.h:279:     { return !(__x == __y); }
	call	_ZSteqRKSt18_Bit_iterator_baseS1_.isra.0	#
# /usr/include/c++/15.2.1/bits/stl_bvector.h:279:     { return !(__x == __y); }
	xor	eax, 1	# _2,
# /usr/include/c++/15.2.1/bits/stl_bvector.h:279:     { return !(__x == __y); }
	ret	
	.cfi_endproc
.LFE13913:
	.size	_ZStneRKSt18_Bit_iterator_baseS1_.isra.0, .-_ZStneRKSt18_Bit_iterator_baseS1_.isra.0
	.align 2
	.p2align 4
	.type	_ZNSt14_Bit_referenceaSEb.isra.0, @function
_ZNSt14_Bit_referenceaSEb.isra.0:
.LFB13914:
	.cfi_startproc
# /usr/include/c++/15.2.1/bits/stl_bvector.h:113: 	*_M_p |= _M_mask;
	mov	rax, QWORD PTR [rdi]	# pretmp_11, *ISRA.661_12(D)
# /usr/include/c++/15.2.1/bits/stl_bvector.h:110:     operator=(bool __x) _GLIBCXX_NOEXCEPT
	mov	ecx, edx	# __x, __x
# /usr/include/c++/15.2.1/bits/stl_bvector.h:113: 	*_M_p |= _M_mask;
	mov	rdx, rax	# tmp106, pretmp_11
	or	rdx, rsi	# tmp106, ISRA.662
	not	rsi	# _9
	and	rsi, rax	# tmp107, pretmp_11
	test	cl, cl	# __x
	cmovne	rsi, rdx	# tmp107,, _5, tmp106
	mov	QWORD PTR [rdi], rsi	# *ISRA.661_12(D), _5
# /usr/include/c++/15.2.1/bits/stl_bvector.h:117:     }
	ret	
	.cfi_endproc
.LFE13914:
	.size	_ZNSt14_Bit_referenceaSEb.isra.0, .-_ZNSt14_Bit_referenceaSEb.isra.0
	.align 2
	.p2align 4
	.type	_ZNKSt14_Bit_referencecvbEv.isra.0, @function
_ZNKSt14_Bit_referencecvbEv.isra.0:
.LFB13915:
	.cfi_startproc
# /usr/include/c++/15.2.1/bits/stl_bvector.h:106:     { return !!(*_M_p & _M_mask); }
	and	rsi, QWORD PTR [rdi]	# _4, *ISRA.666_6(D)
# /usr/include/c++/15.2.1/bits/stl_bvector.h:106:     { return !!(*_M_p & _M_mask); }
	setne	al	#, _5
# /usr/include/c++/15.2.1/bits/stl_bvector.h:106:     { return !!(*_M_p & _M_mask); }
	ret	
	.cfi_endproc
.LFE13915:
	.size	_ZNKSt14_Bit_referencecvbEv.isra.0, .-_ZNKSt14_Bit_referencecvbEv.isra.0
	.align 2
	.p2align 4
	.type	_ZNSt14_Bit_referenceaSERKS_.isra.0, @function
_ZNSt14_Bit_referenceaSERKS_.isra.0:
.LFB13916:
	.cfi_startproc
# /usr/include/c++/15.2.1/bits/stl_bvector.h:133:     operator=(const _Bit_reference& __x) _GLIBCXX_NOEXCEPT
	mov	r8, rdi	# ISRA.671, ISRA.671
	mov	r9, rsi	# ISRA.672, ISRA.672
# /usr/include/c++/15.2.1/bits/stl_bvector.h:134:     { return *this = bool(__x); }
	mov	rdi, rdx	#, ISRA.673
	mov	rsi, rcx	#, ISRA.674
	call	_ZNKSt14_Bit_referencecvbEv.isra.0	#
# /usr/include/c++/15.2.1/bits/stl_bvector.h:134:     { return *this = bool(__x); }
	mov	rsi, r9	#, ISRA.672
	mov	rdi, r8	#, ISRA.671
	movzx	edx, al	# _2, _1
	jmp	_ZNSt14_Bit_referenceaSEb.isra.0	#
	.cfi_endproc
.LFE13916:
	.size	_ZNSt14_Bit_referenceaSERKS_.isra.0, .-_ZNSt14_Bit_referenceaSERKS_.isra.0
	.p2align 4
	.type	_ZnwmPv.isra.0, @function
_ZnwmPv.isra.0:
.LFB13917:
	.cfi_startproc
# /usr/include/c++/15.2.1/new:206: void* operator new(std::size_t, void* __p)
	mov	rax, rdi	# __p, __p
# /usr/include/c++/15.2.1/new:208: { return __p; }
	ret	
	.cfi_endproc
.LFE13917:
	.size	_ZnwmPv.isra.0, .-_ZnwmPv.isra.0
	.section	.text._ZNSt11char_traitsIcE6lengthEPKc,"axG",@progbits,_ZNSt11char_traitsIcE6lengthEPKc,comdat
	.p2align 4
	.weak	_ZNSt11char_traitsIcE6lengthEPKc
	.type	_ZNSt11char_traitsIcE6lengthEPKc, @function
_ZNSt11char_traitsIcE6lengthEPKc:
.LFB8401:
	.cfi_startproc
# /usr/include/c++/15.2.1/bits/char_traits.h:393: 	return __builtin_strlen(__s);
	jmp	[QWORD PTR strlen@GOTPCREL[rip]]	#
	.cfi_endproc
.LFE8401:
	.size	_ZNSt11char_traitsIcE6lengthEPKc, .-_ZNSt11char_traitsIcE6lengthEPKc
	.section	.text._ZNSt14_Bit_referenceC2EPmm,"axG",@progbits,_ZNSt14_Bit_referenceC5EPmm,comdat
	.align 2
	.p2align 4
	.weak	_ZNSt14_Bit_referenceC2EPmm
	.type	_ZNSt14_Bit_referenceC2EPmm, @function
_ZNSt14_Bit_referenceC2EPmm:
.LFB10078:
	.cfi_startproc
# /usr/include/c++/15.2.1/bits/stl_bvector.h:97:     : _M_p(__x), _M_mask(__y) { }
	mov	QWORD PTR [rdi], rsi	# *this_2(D)._M_p, __x
# /usr/include/c++/15.2.1/bits/stl_bvector.h:97:     : _M_p(__x), _M_mask(__y) { }
	mov	QWORD PTR 8[rdi], rdx	# *this_2(D)._M_mask, __y
# /usr/include/c++/15.2.1/bits/stl_bvector.h:97:     : _M_p(__x), _M_mask(__y) { }
	ret	
	.cfi_endproc
.LFE10078:
	.size	_ZNSt14_Bit_referenceC2EPmm, .-_ZNSt14_Bit_referenceC2EPmm
	.weak	_ZNSt14_Bit_referenceC1EPmm
	.set	_ZNSt14_Bit_referenceC1EPmm,_ZNSt14_Bit_referenceC2EPmm
	.text
	.align 2
	.p2align 4
	.type	_ZNSt6vectorIbSaIbEEixEm.isra.0, @function
_ZNSt6vectorIbSaIbEEixEm.isra.0:
.LFB13918:
	.cfi_startproc
	sub	rsp, 40	#,
	.cfi_def_cfa_offset 48
# /usr/include/c++/15.2.1/bits/stl_bvector.h:1159: 	return _Bit_reference (this->_M_impl._M_start._M_p
	mov	edx, 1	# tmp112,
	mov	rcx, QWORD PTR fs:40	# tmp121, MEM[(<address-space-1> long unsigned int *)40B]
	mov	QWORD PTR 24[rsp], rcx	# D.172946, tmp121
	mov	ecx, esi	# tmp121, __n
# /usr/include/c++/15.2.1/bits/stl_bvector.h:1160: 			       + __n / int(_S_word_bit),
	shr	rsi, 6	# _6,
# /usr/include/c++/15.2.1/bits/stl_bvector.h:1159: 	return _Bit_reference (this->_M_impl._M_start._M_p
	lea	rsi, [rdi+rsi*8]	# _8,
	mov	rdi, rsp	# tmp116,
	sal	rdx, cl	# _4, tmp121
	call	_ZNSt14_Bit_referenceC1EPmm	#
# /usr/include/c++/15.2.1/bits/stl_bvector.h:1161: 			       1UL << __n % int(_S_word_bit));
	mov	rax, QWORD PTR [rsp]	# D.172941, D.172940
	mov	rdx, QWORD PTR 8[rsp]	# D.172941, D.172940
# /usr/include/c++/15.2.1/bits/stl_bvector.h:1162:       }
	mov	rcx, QWORD PTR 24[rsp]	# tmp122, D.172946
	sub	rcx, QWORD PTR fs:40	# tmp122, MEM[(<address-space-1> long unsigned int *)40B]
	jne	.L102	#,
	add	rsp, 40	#,
	.cfi_remember_state
	.cfi_def_cfa_offset 8
	ret	
.L102:
	.cfi_restore_state
	call	[QWORD PTR __stack_chk_fail@GOTPCREL[rip]]	#
	.cfi_endproc
.LFE13918:
	.size	_ZNSt6vectorIbSaIbEEixEm.isra.0, .-_ZNSt6vectorIbSaIbEEixEm.isra.0
	.section	.text._ZNSt18_Bit_iterator_baseC2EPmj,"axG",@progbits,_ZNSt18_Bit_iterator_baseC5EPmj,comdat
	.align 2
	.p2align 4
	.weak	_ZNSt18_Bit_iterator_baseC2EPmj
	.type	_ZNSt18_Bit_iterator_baseC2EPmj, @function
_ZNSt18_Bit_iterator_baseC2EPmj:
.LFB10091:
	.cfi_startproc
# /usr/include/c++/15.2.1/bits/stl_bvector.h:202:     : _M_p(__x), _M_offset(__y) { }
	mov	QWORD PTR [rdi], rsi	# *this_2(D)._M_p, __x
# /usr/include/c++/15.2.1/bits/stl_bvector.h:202:     : _M_p(__x), _M_offset(__y) { }
	mov	DWORD PTR 8[rdi], edx	# *this_2(D)._M_offset, __y
# /usr/include/c++/15.2.1/bits/stl_bvector.h:202:     : _M_p(__x), _M_offset(__y) { }
	ret	
	.cfi_endproc
.LFE10091:
	.size	_ZNSt18_Bit_iterator_baseC2EPmj, .-_ZNSt18_Bit_iterator_baseC2EPmj
	.weak	_ZNSt18_Bit_iterator_baseC1EPmj
	.set	_ZNSt18_Bit_iterator_baseC1EPmj,_ZNSt18_Bit_iterator_baseC2EPmj
	.section	.text._ZNSt18_Bit_iterator_base10_M_bump_upEv,"axG",@progbits,_ZNSt18_Bit_iterator_base10_M_bump_upEv,comdat
	.align 2
	.p2align 4
	.weak	_ZNSt18_Bit_iterator_base10_M_bump_upEv
	.type	_ZNSt18_Bit_iterator_base10_M_bump_upEv, @function
_ZNSt18_Bit_iterator_base10_M_bump_upEv:
.LFB10093:
	.cfi_startproc
# /usr/include/c++/15.2.1/bits/stl_bvector.h:195:       unsigned int __ofst = _M_offset;
	mov	eax, DWORD PTR 8[rdi]	# __ofst, MEM[(const struct _Bit_iterator_base *)this_6(D)]._M_offset
# /usr/include/c++/15.2.1/bits/stl_bvector.h:209:       if (_M_offset++ == int(_S_word_bit) - 1)
	cmp	eax, 63	# __ofst,
	je	.L105	#,
# /usr/include/c++/15.2.1/bits/stl_bvector.h:209:       if (_M_offset++ == int(_S_word_bit) - 1)
	add	eax, 1	# tmp103,
	mov	DWORD PTR 8[rdi], eax	# this_6(D)->_M_offset, tmp103
	ret	
	.p2align 4,,10
	.p2align 3
.L105:
# /usr/include/c++/15.2.1/bits/stl_bvector.h:212: 	  ++_M_p;
	add	QWORD PTR [rdi], 8	# this_6(D)->_M_p,
# /usr/include/c++/15.2.1/bits/stl_bvector.h:211: 	  _M_offset = 0;
	mov	DWORD PTR 8[rdi], 0	# this_6(D)->_M_offset,
# /usr/include/c++/15.2.1/bits/stl_bvector.h:214:     }
	ret	
	.cfi_endproc
.LFE10093:
	.size	_ZNSt18_Bit_iterator_base10_M_bump_upEv, .-_ZNSt18_Bit_iterator_base10_M_bump_upEv
	.section	.text._ZNSt19_Bit_const_iteratorppEv.isra.0,"axG",@progbits,_ZSt14__copy_move_a2ILb0ESt19_Bit_const_iteratorS0_St13_Bit_iteratorET2_T0_T1_S2_,comdat
	.align 2
	.p2align 4
	.type	_ZNSt19_Bit_const_iteratorppEv.isra.0, @function
_ZNSt19_Bit_const_iteratorppEv.isra.0:
.LFB13919:
	.cfi_startproc
# /usr/include/c++/15.2.1/bits/stl_bvector.h:456:       _M_bump_up();
	jmp	_ZNSt18_Bit_iterator_base10_M_bump_upEv	#
	.cfi_endproc
.LFE13919:
	.size	_ZNSt19_Bit_const_iteratorppEv.isra.0, .-_ZNSt19_Bit_const_iteratorppEv.isra.0
	.text
	.align 2
	.p2align 4
	.type	_ZNSt13_Bit_iteratorppEi.isra.0, @function
_ZNSt13_Bit_iteratorppEi.isra.0:
.LFB13920:
	.cfi_startproc
	push	rbp	#
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	push	rbx	#
	.cfi_def_cfa_offset 24
	.cfi_offset 3, -24
	sub	rsp, 40	#,
	.cfi_def_cfa_offset 64
# /usr/include/c++/15.2.1/bits/stl_bvector.h:350:       iterator __tmp = *this;
	mov	rbp, QWORD PTR [rdi]	# __tmp$D107718$_M_p, MEM <_Bit_type *> [(const struct _Bit_iterator &)this_1(D)]
	mov	ebx, DWORD PTR 8[rdi]	# __tmp$D107718$_M_offset, MEM <unsigned int> [(const struct _Bit_iterator &)this_1(D) + 8]
# /usr/include/c++/15.2.1/bits/stl_bvector.h:351:       _M_bump_up();
	call	_ZNSt18_Bit_iterator_base10_M_bump_upEv	#
# /usr/include/c++/15.2.1/bits/stl_bvector.h:352:       return __tmp;
	mov	QWORD PTR 16[rsp], rbp	# MEM <_Bit_type *> [(struct _Bit_iterator *)&D.172968], __tmp$D107718$_M_p
# /usr/include/c++/15.2.1/bits/stl_bvector.h:353:     }
	mov	rax, QWORD PTR 16[rsp]	#, D.172968
# /usr/include/c++/15.2.1/bits/stl_bvector.h:352:       return __tmp;
	mov	DWORD PTR 24[rsp], ebx	# MEM <unsigned int> [(struct _Bit_iterator *)&D.172968 + 8B], __tmp$D107718$_M_offset
# /usr/include/c++/15.2.1/bits/stl_bvector.h:353:     }
	mov	rdx, QWORD PTR 24[rsp]	#, D.172968
	add	rsp, 40	#,
	.cfi_def_cfa_offset 24
	pop	rbx	#
	.cfi_def_cfa_offset 16
	pop	rbp	#
	.cfi_def_cfa_offset 8
	ret	
	.cfi_endproc
.LFE13920:
	.size	_ZNSt13_Bit_iteratorppEi.isra.0, .-_ZNSt13_Bit_iteratorppEi.isra.0
	.align 2
	.p2align 4
	.type	_ZNSt13_Bit_iteratorppEv.isra.0, @function
_ZNSt13_Bit_iteratorppEv.isra.0:
.LFB13921:
	.cfi_startproc
# /usr/include/c++/15.2.1/bits/stl_bvector.h:342:       _M_bump_up();
	jmp	_ZNSt18_Bit_iterator_base10_M_bump_upEv	#
	.cfi_endproc
.LFE13921:
	.size	_ZNSt13_Bit_iteratorppEv.isra.0, .-_ZNSt13_Bit_iteratorppEv.isra.0
	.section	.text._ZNSt18_Bit_iterator_base12_M_bump_downEv,"axG",@progbits,_ZNSt18_Bit_iterator_base12_M_bump_downEv,comdat
	.align 2
	.p2align 4
	.weak	_ZNSt18_Bit_iterator_base12_M_bump_downEv
	.type	_ZNSt18_Bit_iterator_base12_M_bump_downEv, @function
_ZNSt18_Bit_iterator_base12_M_bump_downEv:
.LFB10094:
	.cfi_startproc
# /usr/include/c++/15.2.1/bits/stl_bvector.h:195:       unsigned int __ofst = _M_offset;
	mov	eax, DWORD PTR 8[rdi]	# __ofst, MEM[(const struct _Bit_iterator_base *)this_6(D)]._M_offset
# /usr/include/c++/15.2.1/bits/stl_bvector.h:221:       if (_M_offset-- == 0)
	test	eax, eax	# __ofst
	je	.L112	#,
# /usr/include/c++/15.2.1/bits/stl_bvector.h:221:       if (_M_offset-- == 0)
	sub	eax, 1	# tmp103,
	mov	DWORD PTR 8[rdi], eax	# this_6(D)->_M_offset, tmp103
	ret	
	.p2align 4,,10
	.p2align 3
.L112:
# /usr/include/c++/15.2.1/bits/stl_bvector.h:224: 	  --_M_p;
	sub	QWORD PTR [rdi], 8	# this_6(D)->_M_p,
# /usr/include/c++/15.2.1/bits/stl_bvector.h:223: 	  _M_offset = int(_S_word_bit) - 1;
	mov	DWORD PTR 8[rdi], 63	# this_6(D)->_M_offset,
# /usr/include/c++/15.2.1/bits/stl_bvector.h:226:     }
	ret	
	.cfi_endproc
.LFE10094:
	.size	_ZNSt18_Bit_iterator_base12_M_bump_downEv, .-_ZNSt18_Bit_iterator_base12_M_bump_downEv
	.section	.text._ZNSt13_Bit_iteratormmEv.isra.0,"axG",@progbits,_ZNSt6vectorIbSaIbEE13_M_insert_auxESt13_Bit_iteratorb,comdat
	.align 2
	.p2align 4
	.type	_ZNSt13_Bit_iteratormmEv.isra.0, @function
_ZNSt13_Bit_iteratormmEv.isra.0:
.LFB13922:
	.cfi_startproc
# /usr/include/c++/15.2.1/bits/stl_bvector.h:359:       _M_bump_down();
	jmp	_ZNSt18_Bit_iterator_base12_M_bump_downEv	#
	.cfi_endproc
.LFE13922:
	.size	_ZNSt13_Bit_iteratormmEv.isra.0, .-_ZNSt13_Bit_iteratormmEv.isra.0
	.section	.text._ZNSt18_Bit_iterator_base7_M_incrEl,"axG",@progbits,_ZNSt18_Bit_iterator_base7_M_incrEl,comdat
	.align 2
	.p2align 4
	.weak	_ZNSt18_Bit_iterator_base7_M_incrEl
	.type	_ZNSt18_Bit_iterator_base7_M_incrEl, @function
_ZNSt18_Bit_iterator_base7_M_incrEl:
.LFB10095:
	.cfi_startproc
# /usr/include/c++/15.2.1/bits/stl_bvector.h:233:       difference_type __n = __i + _M_offset;
	mov	eax, DWORD PTR 8[rdi]	# _1, MEM[(const struct _Bit_iterator_base *)this_12(D)]._M_offset
# /usr/include/c++/15.2.1/bits/stl_bvector.h:234:       _M_p += __n / int(_S_word_bit);
	mov	rcx, QWORD PTR [rdi]	# this_12(D)->_M_p, this_12(D)->_M_p
# /usr/include/c++/15.2.1/bits/stl_bvector.h:233:       difference_type __n = __i + _M_offset;
	add	rax, rsi	# __n, __i
# /usr/include/c++/15.2.1/bits/stl_bvector.h:234:       _M_p += __n / int(_S_word_bit);
	lea	rdx, 63[rax]	# tmp113,
	cmovns	rdx, rax	# tmp113,, __n, __n
	sar	rdx, 6	# _3,
# /usr/include/c++/15.2.1/bits/stl_bvector.h:234:       _M_p += __n / int(_S_word_bit);
	lea	rdx, [rcx+rdx*8]	# _6,
# /usr/include/c++/15.2.1/bits/stl_bvector.h:235:       __n = __n % int(_S_word_bit);
	mov	rcx, rax	# tmp117, __n
	sar	rcx, 63	# tmp117,
# /usr/include/c++/15.2.1/bits/stl_bvector.h:239: 	  --_M_p;
	lea	rsi, -8[rdx]	# tmp127,
# /usr/include/c++/15.2.1/bits/stl_bvector.h:235:       __n = __n % int(_S_word_bit);
	shr	rcx, 58	# tmp118,
	add	rax, rcx	# tmp119, tmp118
	and	eax, 63	# tmp120,
	sub	rax, rcx	# __n_17, tmp118
# /usr/include/c++/15.2.1/bits/stl_bvector.h:239: 	  --_M_p;
	lea	rcx, 64[rax]	# tmp125,
	cmovs	rdx, rsi	# tmp127,, _6
	cmovns	rcx, rax	# tmp125,, __n, __n_17
# /usr/include/c++/15.2.1/bits/stl_bvector.h:234:       _M_p += __n / int(_S_word_bit);
	mov	QWORD PTR [rdi], rdx	# this_12(D)->_M_p, _6
# /usr/include/c++/15.2.1/bits/stl_bvector.h:241:       _M_offset = static_cast<unsigned int>(__n);
	mov	DWORD PTR 8[rdi], ecx	# this_12(D)->_M_offset, __n
# /usr/include/c++/15.2.1/bits/stl_bvector.h:242:     }
	ret	
	.cfi_endproc
.LFE10095:
	.size	_ZNSt18_Bit_iterator_base7_M_incrEl, .-_ZNSt18_Bit_iterator_base7_M_incrEl
	.section	.text._ZNSt13_Bit_iteratorpLEl.isra.0,"axG",@progbits,_ZStplRKSt13_Bit_iteratorl,comdat
	.align 2
	.p2align 4
	.type	_ZNSt13_Bit_iteratorpLEl.isra.0, @function
_ZNSt13_Bit_iteratorpLEl.isra.0:
.LFB13923:
	.cfi_startproc
# /usr/include/c++/15.2.1/bits/stl_bvector.h:376:       _M_incr(__i);
	jmp	_ZNSt18_Bit_iterator_base7_M_incrEl	#
	.cfi_endproc
.LFE13923:
	.size	_ZNSt13_Bit_iteratorpLEl.isra.0, .-_ZNSt13_Bit_iteratorpLEl.isra.0
	.section	.text._ZNSt13_Bit_iteratorC2Ev,"axG",@progbits,_ZNSt13_Bit_iteratorC5Ev,comdat
	.align 2
	.p2align 4
	.weak	_ZNSt13_Bit_iteratorC2Ev
	.type	_ZNSt13_Bit_iteratorC2Ev, @function
_ZNSt13_Bit_iteratorC2Ev:
.LFB10104:
	.cfi_startproc
# /usr/include/c++/15.2.1/bits/stl_bvector.h:319:     _Bit_iterator() : _Bit_iterator_base(0, 0) { }
	xor	edx, edx	#
	xor	esi, esi	#
	jmp	_ZNSt18_Bit_iterator_baseC2EPmj	#
	.cfi_endproc
.LFE10104:
	.size	_ZNSt13_Bit_iteratorC2Ev, .-_ZNSt13_Bit_iteratorC2Ev
	.weak	_ZNSt13_Bit_iteratorC1Ev
	.set	_ZNSt13_Bit_iteratorC1Ev,_ZNSt13_Bit_iteratorC2Ev
	.section	.text._ZNSt13_Bit_iteratorC2EPmj,"axG",@progbits,_ZNSt13_Bit_iteratorC5EPmj,comdat
	.align 2
	.p2align 4
	.weak	_ZNSt13_Bit_iteratorC2EPmj
	.type	_ZNSt13_Bit_iteratorC2EPmj, @function
_ZNSt13_Bit_iteratorC2EPmj:
.LFB10107:
	.cfi_startproc
# /usr/include/c++/15.2.1/bits/stl_bvector.h:323:     : _Bit_iterator_base(__x, __y) { }
	jmp	_ZNSt18_Bit_iterator_baseC2EPmj	#
	.cfi_endproc
.LFE10107:
	.size	_ZNSt13_Bit_iteratorC2EPmj, .-_ZNSt13_Bit_iteratorC2EPmj
	.weak	_ZNSt13_Bit_iteratorC1EPmj
	.set	_ZNSt13_Bit_iteratorC1EPmj,_ZNSt13_Bit_iteratorC2EPmj
	.text
	.align 2
	.p2align 4
	.type	_ZNSt6vectorIbSaIbEE5beginEv.isra.0, @function
_ZNSt6vectorIbSaIbEE5beginEv.isra.0:
.LFB13924:
	.cfi_startproc
	sub	rsp, 72	#,
	.cfi_def_cfa_offset 80
# /usr/include/c++/15.2.1/bits/stl_bvector.h:1066:       { return iterator(this->_M_impl._M_start._M_p, 0); }
	xor	edx, edx	#
# /usr/include/c++/15.2.1/bits/stl_bvector.h:1065:       begin() _GLIBCXX_NOEXCEPT
	mov	rsi, QWORD PTR fs:40	# ISRA.724, MEM[(<address-space-1> long unsigned int *)40B]
	mov	QWORD PTR 56[rsp], rsi	# D.173020, ISRA.724
	mov	rsi, rdi	# ISRA.724, ISRA.724
# /usr/include/c++/15.2.1/bits/stl_bvector.h:1066:       { return iterator(this->_M_impl._M_start._M_p, 0); }
	lea	rdi, 16[rsp]	# tmp102,
	call	_ZNSt13_Bit_iteratorC1EPmj	#
# /usr/include/c++/15.2.1/bits/stl_bvector.h:1066:       { return iterator(this->_M_impl._M_start._M_p, 0); }
	mov	rax, QWORD PTR 16[rsp]	# D.173014, D.173014
	mov	rdx, QWORD PTR 24[rsp]	# D.173014, D.173014
	mov	QWORD PTR 32[rsp], rax	# D.173015, D.173014
	mov	QWORD PTR 40[rsp], rdx	# D.173015, D.173014
# /usr/include/c++/15.2.1/bits/stl_bvector.h:1066:       { return iterator(this->_M_impl._M_start._M_p, 0); }
	mov	rcx, QWORD PTR 56[rsp]	# tmp107, D.173020
	sub	rcx, QWORD PTR fs:40	# tmp107, MEM[(<address-space-1> long unsigned int *)40B]
	jne	.L123	#,
	add	rsp, 72	#,
	.cfi_remember_state
	.cfi_def_cfa_offset 8
	ret	
.L123:
	.cfi_restore_state
	call	[QWORD PTR __stack_chk_fail@GOTPCREL[rip]]	#
	.cfi_endproc
.LFE13924:
	.size	_ZNSt6vectorIbSaIbEE5beginEv.isra.0, .-_ZNSt6vectorIbSaIbEE5beginEv.isra.0
	.section	.text._ZNKSt13_Bit_iteratordeEv,"axG",@progbits,_ZNKSt13_Bit_iteratordeEv,comdat
	.align 2
	.p2align 4
	.weak	_ZNKSt13_Bit_iteratordeEv
	.type	_ZNKSt13_Bit_iteratordeEv, @function
_ZNKSt13_Bit_iteratordeEv:
.LFB10110:
	.cfi_startproc
	sub	rsp, 40	#,
	.cfi_def_cfa_offset 48
# /usr/include/c++/15.2.1/bits/stl_bvector.h:335:       return reference(_M_p, 1UL << _M_offset);
	mov	edx, 1	# tmp108,
	mov	rsi, QWORD PTR [rdi]	# this_3(D)->D.107718._M_p, this_3(D)->D.107718._M_p
	mov	rcx, QWORD PTR fs:40	# MEM[(const struct _Bit_iterator_base *)this_3(D)]._M_offset, MEM[(<address-space-1> long unsigned int *)40B]
	mov	QWORD PTR 24[rsp], rcx	# D.173024, MEM[(const struct _Bit_iterator_base *)this_3(D)]._M_offset
	mov	ecx, DWORD PTR 8[rdi]	# MEM[(const struct _Bit_iterator_base *)this_3(D)]._M_offset, MEM[(const struct _Bit_iterator_base *)this_3(D)]._M_offset
	mov	rdi, rsp	# tmp110,
	sal	rdx, cl	# _1, MEM[(const struct _Bit_iterator_base *)this_3(D)]._M_offset
	call	_ZNSt14_Bit_referenceC1EPmm	#
# /usr/include/c++/15.2.1/bits/stl_bvector.h:335:       return reference(_M_p, 1UL << _M_offset);
	mov	rax, QWORD PTR [rsp]	# D.170277, D.107776
	mov	rdx, QWORD PTR 8[rsp]	# D.170277, D.107776
# /usr/include/c++/15.2.1/bits/stl_bvector.h:336:     }
	mov	rcx, QWORD PTR 24[rsp]	# tmp114, D.173024
	sub	rcx, QWORD PTR fs:40	# tmp114, MEM[(<address-space-1> long unsigned int *)40B]
	jne	.L127	#,
	add	rsp, 40	#,
	.cfi_remember_state
	.cfi_def_cfa_offset 8
	ret	
.L127:
	.cfi_restore_state
	call	[QWORD PTR __stack_chk_fail@GOTPCREL[rip]]	#
	.cfi_endproc
.LFE10110:
	.size	_ZNKSt13_Bit_iteratordeEv, .-_ZNKSt13_Bit_iteratordeEv
	.section	.text._ZSt23__copy_move_backward_a2ILb0ESt13_Bit_iteratorS0_ET1_T0_S2_S1_.isra.0,"axG",@progbits,_ZNSt6vectorIbSaIbEE13_M_insert_auxESt13_Bit_iteratorb,comdat
	.p2align 4
	.type	_ZSt23__copy_move_backward_a2ILb0ESt13_Bit_iteratorS0_ET1_T0_S2_S1_.isra.0, @function
_ZSt23__copy_move_backward_a2ILb0ESt13_Bit_iteratorS0_ET1_T0_S2_S1_.isra.0:
.LFB13925:
	.cfi_startproc
	push	r15	#
	.cfi_def_cfa_offset 16
	.cfi_offset 15, -16
	push	r14	#
	.cfi_def_cfa_offset 24
	.cfi_offset 14, -24
	mov	r14, rdi	# __first, __first
	push	r13	#
	.cfi_def_cfa_offset 32
	.cfi_offset 13, -32
	mov	r13d, esi	# tmp128, __first
	push	r12	#
	.cfi_def_cfa_offset 40
	.cfi_offset 12, -40
	push	rbp	#
	.cfi_def_cfa_offset 48
	.cfi_offset 6, -48
	push	rbx	#
	.cfi_def_cfa_offset 56
	.cfi_offset 3, -56
	sub	rsp, 56	#,
	.cfi_def_cfa_offset 112
# /usr/include/c++/15.2.1/bits/stl_algobase.h:688:     __copy_move_backward_a2(_BI1 __first, _BI1 __last, _BI2 __result)
	mov	QWORD PTR 16[rsp], rdx	# __last, __last
# /usr/include/c++/15.2.1/bits/stl_algobase.h:737: 	  --__last;
	lea	rbp, 16[rsp]	# tmp127,
# /usr/include/c++/15.2.1/bits/stl_algobase.h:688:     __copy_move_backward_a2(_BI1 __first, _BI1 __last, _BI2 __result)
	mov	QWORD PTR 24[rsp], rcx	# __last, __last
	mov	QWORD PTR [rsp], r8	# __result, __result
	mov	QWORD PTR 8[rsp], r9	# __result, __result
	jmp	.L129	#
	.p2align 4,,10
	.p2align 3
.L130:
# /usr/include/c++/15.2.1/bits/stl_algobase.h:737: 	  --__last;
	mov	rdi, rbp	#, tmp127
	call	_ZNSt13_Bit_iteratormmEv.isra.0	#
# /usr/include/c++/15.2.1/bits/stl_algobase.h:738: 	  --__result;
	mov	rdi, rsp	#,
	call	_ZNSt13_Bit_iteratormmEv.isra.0	#
# /usr/include/c++/15.2.1/bits/stl_algobase.h:407: 	*__out = *__in;
	mov	rdi, rbp	#, tmp127
	call	_ZNKSt13_Bit_iteratordeEv	#
# /usr/include/c++/15.2.1/bits/stl_algobase.h:407: 	*__out = *__in;
	mov	rdi, rsp	#,
# /usr/include/c++/15.2.1/bits/stl_algobase.h:407: 	*__out = *__in;
	mov	r12, rax	# D.173031,
	mov	r15, rdx	# D.173031,
# /usr/include/c++/15.2.1/bits/stl_algobase.h:407: 	*__out = *__in;
	call	_ZNKSt13_Bit_iteratordeEv	#
# /usr/include/c++/15.2.1/bits/stl_algobase.h:407: 	*__out = *__in;
	mov	rcx, r15	#, D.173031
# /usr/include/c++/15.2.1/bits/stl_algobase.h:407: 	*__out = *__in;
	mov	rsi, rdx	# D.173032,
# /usr/include/c++/15.2.1/bits/stl_algobase.h:407: 	*__out = *__in;
	mov	rdi, rax	#, D.173032
	mov	rdx, r12	#, D.173031
	call	_ZNSt14_Bit_referenceaSERKS_.isra.0	#
.L129:
# /usr/include/c++/15.2.1/bits/stl_algobase.h:735:       while (__first != __last)
	mov	ecx, DWORD PTR 24[rsp]	#, MEM[(unsigned int *)&__last + 8B]
	mov	rdx, QWORD PTR 16[rsp]	#, MEM[(_Bit_type * *)&__last]
	mov	esi, r13d	#, tmp128
	mov	rdi, r14	#, __first
	call	_ZStneRKSt18_Bit_iterator_baseS1_.isra.0	#
# /usr/include/c++/15.2.1/bits/stl_algobase.h:735:       while (__first != __last)
	test	al, al	# retval.27_1
	jne	.L130	#,
# /usr/include/c++/15.2.1/bits/stl_algobase.h:742:     }
	add	rsp, 56	#,
	.cfi_def_cfa_offset 56
	pop	rbx	#
	.cfi_def_cfa_offset 48
	pop	rbp	#
	.cfi_def_cfa_offset 40
	pop	r12	#
	.cfi_def_cfa_offset 32
	pop	r13	#
	.cfi_def_cfa_offset 24
	pop	r14	#
	.cfi_def_cfa_offset 16
	pop	r15	#
	.cfi_def_cfa_offset 8
	ret	
	.cfi_endproc
.LFE13925:
	.size	_ZSt23__copy_move_backward_a2ILb0ESt13_Bit_iteratorS0_ET1_T0_S2_S1_.isra.0, .-_ZSt23__copy_move_backward_a2ILb0ESt13_Bit_iteratorS0_ET1_T0_S2_S1_.isra.0
	.section	.text._ZStplRKSt13_Bit_iteratorl,"axG",@progbits,_ZStplRKSt13_Bit_iteratorl,comdat
	.p2align 4
	.weak	_ZStplRKSt13_Bit_iteratorl
	.type	_ZStplRKSt13_Bit_iteratorl, @function
_ZStplRKSt13_Bit_iteratorl:
.LFB10118:
	.cfi_startproc
	sub	rsp, 72	#,
	.cfi_def_cfa_offset 80
# /usr/include/c++/15.2.1/bits/stl_bvector.h:397:       iterator __tmp = __x;
	movdqu	xmm0, XMMWORD PTR [rdi]	# MEM[(const struct _Bit_iterator &)__x_2(D)], MEM[(const struct _Bit_iterator &)__x_2(D)]
# /usr/include/c++/15.2.1/bits/stl_bvector.h:395:     operator+(const iterator& __x, difference_type __n)
	mov	rax, QWORD PTR fs:40	# tmp102, MEM[(<address-space-1> long unsigned int *)40B]
	mov	QWORD PTR 56[rsp], rax	# D.173042, tmp102
	xor	eax, eax	# tmp102
# /usr/include/c++/15.2.1/bits/stl_bvector.h:398:       __tmp += __n;
	lea	rdi, 16[rsp]	# tmp104,
# /usr/include/c++/15.2.1/bits/stl_bvector.h:397:       iterator __tmp = __x;
	movaps	XMMWORD PTR 16[rsp], xmm0	# __tmp, MEM[(const struct _Bit_iterator &)__x_2(D)]
# /usr/include/c++/15.2.1/bits/stl_bvector.h:398:       __tmp += __n;
	call	_ZNSt13_Bit_iteratorpLEl.isra.0	#
# /usr/include/c++/15.2.1/bits/stl_bvector.h:399:       return __tmp;
	mov	rax, QWORD PTR 16[rsp]	# __tmp, __tmp
	mov	rdx, QWORD PTR 24[rsp]	# __tmp, __tmp
	mov	QWORD PTR 32[rsp], rax	# D.170299, __tmp
	mov	QWORD PTR 40[rsp], rdx	# D.170299, __tmp
# /usr/include/c++/15.2.1/bits/stl_bvector.h:400:     }
	mov	rcx, QWORD PTR 56[rsp]	# tmp110, D.173042
	sub	rcx, QWORD PTR fs:40	# tmp110, MEM[(<address-space-1> long unsigned int *)40B]
	jne	.L135	#,
	add	rsp, 72	#,
	.cfi_remember_state
	.cfi_def_cfa_offset 8
	ret	
.L135:
	.cfi_restore_state
	call	[QWORD PTR __stack_chk_fail@GOTPCREL[rip]]	#
	.cfi_endproc
.LFE10118:
	.size	_ZStplRKSt13_Bit_iteratorl, .-_ZStplRKSt13_Bit_iteratorl
	.section	.text._ZNSt19_Bit_const_iteratorC2EPmj,"axG",@progbits,_ZNSt19_Bit_const_iteratorC5EPmj,comdat
	.align 2
	.p2align 4
	.weak	_ZNSt19_Bit_const_iteratorC2EPmj
	.type	_ZNSt19_Bit_const_iteratorC2EPmj, @function
_ZNSt19_Bit_const_iteratorC2EPmj:
.LFB10125:
	.cfi_startproc
# /usr/include/c++/15.2.1/bits/stl_bvector.h:433:     : _Bit_iterator_base(__x, __y) { }
	jmp	_ZNSt18_Bit_iterator_baseC2EPmj	#
	.cfi_endproc
.LFE10125:
	.size	_ZNSt19_Bit_const_iteratorC2EPmj, .-_ZNSt19_Bit_const_iteratorC2EPmj
	.weak	_ZNSt19_Bit_const_iteratorC1EPmj
	.set	_ZNSt19_Bit_const_iteratorC1EPmj,_ZNSt19_Bit_const_iteratorC2EPmj
	.section	.text._ZNKSt6vectorIbSaIbEE5beginEv.isra.0,"axG",@progbits,_ZNKSt6vectorIbSaIbEE4sizeEv,comdat
	.align 2
	.p2align 4
	.type	_ZNKSt6vectorIbSaIbEE5beginEv.isra.0, @function
_ZNKSt6vectorIbSaIbEE5beginEv.isra.0:
.LFB13926:
	.cfi_startproc
	sub	rsp, 72	#,
	.cfi_def_cfa_offset 80
# /usr/include/c++/15.2.1/bits/stl_bvector.h:1071:       { return const_iterator(this->_M_impl._M_start._M_p, 0); }
	xor	edx, edx	#
# /usr/include/c++/15.2.1/bits/stl_bvector.h:1070:       begin() const _GLIBCXX_NOEXCEPT
	mov	rsi, QWORD PTR fs:40	# ISRA.740, MEM[(<address-space-1> long unsigned int *)40B]
	mov	QWORD PTR 56[rsp], rsi	# D.173057, ISRA.740
	mov	rsi, rdi	# ISRA.740, ISRA.740
# /usr/include/c++/15.2.1/bits/stl_bvector.h:1071:       { return const_iterator(this->_M_impl._M_start._M_p, 0); }
	lea	rdi, 16[rsp]	# tmp102,
	call	_ZNSt19_Bit_const_iteratorC1EPmj	#
# /usr/include/c++/15.2.1/bits/stl_bvector.h:1071:       { return const_iterator(this->_M_impl._M_start._M_p, 0); }
	mov	rax, QWORD PTR 16[rsp]	# D.173051, D.173051
	mov	rdx, QWORD PTR 24[rsp]	# D.173051, D.173051
	mov	QWORD PTR 32[rsp], rax	# D.173052, D.173051
	mov	QWORD PTR 40[rsp], rdx	# D.173052, D.173051
# /usr/include/c++/15.2.1/bits/stl_bvector.h:1071:       { return const_iterator(this->_M_impl._M_start._M_p, 0); }
	mov	rcx, QWORD PTR 56[rsp]	# tmp107, D.173057
	sub	rcx, QWORD PTR fs:40	# tmp107, MEM[(<address-space-1> long unsigned int *)40B]
	jne	.L140	#,
	add	rsp, 72	#,
	.cfi_remember_state
	.cfi_def_cfa_offset 8
	ret	
.L140:
	.cfi_restore_state
	call	[QWORD PTR __stack_chk_fail@GOTPCREL[rip]]	#
	.cfi_endproc
.LFE13926:
	.size	_ZNKSt6vectorIbSaIbEE5beginEv.isra.0, .-_ZNKSt6vectorIbSaIbEE5beginEv.isra.0
	.section	.text._ZNSt19_Bit_const_iteratorC2ERKSt13_Bit_iterator,"axG",@progbits,_ZNSt19_Bit_const_iteratorC5ERKSt13_Bit_iterator,comdat
	.align 2
	.p2align 4
	.weak	_ZNSt19_Bit_const_iteratorC2ERKSt13_Bit_iterator
	.type	_ZNSt19_Bit_const_iteratorC2ERKSt13_Bit_iterator, @function
_ZNSt19_Bit_const_iteratorC2ERKSt13_Bit_iterator:
.LFB10128:
	.cfi_startproc
# /usr/include/c++/15.2.1/bits/stl_bvector.h:437:     : _Bit_iterator_base(__x._M_p, __x._M_offset) { }
	mov	edx, DWORD PTR 8[rsi]	# *__x_7(D).D.107718._M_offset, *__x_7(D).D.107718._M_offset
	mov	rsi, QWORD PTR [rsi]	# *__x_7(D).D.107718._M_p, *__x_7(D).D.107718._M_p
	jmp	_ZNSt18_Bit_iterator_baseC2EPmj	#
	.cfi_endproc
.LFE10128:
	.size	_ZNSt19_Bit_const_iteratorC2ERKSt13_Bit_iterator, .-_ZNSt19_Bit_const_iteratorC2ERKSt13_Bit_iterator
	.weak	_ZNSt19_Bit_const_iteratorC1ERKSt13_Bit_iterator
	.set	_ZNSt19_Bit_const_iteratorC1ERKSt13_Bit_iterator,_ZNSt19_Bit_const_iteratorC2ERKSt13_Bit_iterator
	.section	.text._ZNKSt19_Bit_const_iteratordeEv,"axG",@progbits,_ZNKSt19_Bit_const_iteratordeEv,comdat
	.align 2
	.p2align 4
	.weak	_ZNKSt19_Bit_const_iteratordeEv
	.type	_ZNKSt19_Bit_const_iteratordeEv, @function
_ZNKSt19_Bit_const_iteratordeEv:
.LFB10131:
	.cfi_startproc
	sub	rsp, 40	#,
	.cfi_def_cfa_offset 48
# /usr/include/c++/15.2.1/bits/stl_bvector.h:449:       return _Bit_reference(_M_p, 1UL << _M_offset);
	mov	edx, 1	# tmp109,
	mov	rsi, QWORD PTR [rdi]	# this_3(D)->D.107886._M_p, this_3(D)->D.107886._M_p
	mov	rcx, QWORD PTR fs:40	# MEM[(const struct _Bit_iterator_base *)this_3(D)]._M_offset, MEM[(<address-space-1> long unsigned int *)40B]
	mov	QWORD PTR 24[rsp], rcx	# D.173066, MEM[(const struct _Bit_iterator_base *)this_3(D)]._M_offset
	mov	ecx, DWORD PTR 8[rdi]	# MEM[(const struct _Bit_iterator_base *)this_3(D)]._M_offset, MEM[(const struct _Bit_iterator_base *)this_3(D)]._M_offset
	mov	rdi, rsp	# tmp111,
	sal	rdx, cl	# _1, MEM[(const struct _Bit_iterator_base *)this_3(D)]._M_offset
	call	_ZNSt14_Bit_referenceC1EPmm	#
# /usr/include/c++/15.2.1/bits/stl_bvector.h:449:       return _Bit_reference(_M_p, 1UL << _M_offset);
	mov	rax, QWORD PTR 24[rsp]	# tmp117, D.173066
	sub	rax, QWORD PTR fs:40	# tmp117, MEM[(<address-space-1> long unsigned int *)40B]
	jne	.L146	#,
	mov	rsi, QWORD PTR 8[rsp]	#, MEM[(long unsigned int *)&D.107899 + 8B]
	mov	rdi, QWORD PTR [rsp]	#, MEM[(_Bit_type * *)&D.107899]
# /usr/include/c++/15.2.1/bits/stl_bvector.h:450:     }
	add	rsp, 40	#,
	.cfi_remember_state
	.cfi_def_cfa_offset 8
# /usr/include/c++/15.2.1/bits/stl_bvector.h:449:       return _Bit_reference(_M_p, 1UL << _M_offset);
	jmp	_ZNKSt14_Bit_referencecvbEv.isra.0	#
.L146:
	.cfi_restore_state
	call	[QWORD PTR __stack_chk_fail@GOTPCREL[rip]]	#
	.cfi_endproc
.LFE10131:
	.size	_ZNKSt19_Bit_const_iteratordeEv, .-_ZNKSt19_Bit_const_iteratordeEv
	.section	.text._ZSt3minImERKT_S2_S2_,"axG",@progbits,_ZSt3minImERKT_S2_S2_,comdat
	.p2align 4
	.weak	_ZSt3minImERKT_S2_S2_
	.type	_ZSt3minImERKT_S2_S2_, @function
_ZSt3minImERKT_S2_S2_:
.LFB12284:
	.cfi_startproc
# /usr/include/c++/15.2.1/bits/stl_algobase.h:241:       return __a;
	mov	rax, QWORD PTR [rdi]	# tmp108, *__a_6(D)
	cmp	QWORD PTR [rsi], rax	# *__b_5(D), tmp108
	mov	rax, rdi	# __a, __a
	cmovb	rax, rsi	# __b,, __a
# /usr/include/c++/15.2.1/bits/stl_algobase.h:242:     }
	ret	
	.cfi_endproc
.LFE12284:
	.size	_ZSt3minImERKT_S2_S2_, .-_ZSt3minImERKT_S2_S2_
	.section	.text._ZNSt6vectorI6ButtonSaIS0_EE11_S_max_sizeERKS1_.isra.0,"axG",@progbits,_ZNKSt6vectorI6ButtonSaIS0_EE8max_sizeEv,comdat
	.p2align 4
	.type	_ZNSt6vectorI6ButtonSaIS0_EE11_S_max_sizeERKS1_.isra.0, @function
_ZNSt6vectorI6ButtonSaIS0_EE11_S_max_sizeERKS1_.isra.0:
.LFB13927:
	.cfi_startproc
	sub	rsp, 40	#,
	.cfi_def_cfa_offset 48
# /usr/include/c++/15.2.1/bits/stl_vector.h:2227: 	const size_t __diffmax
	mov	rax, QWORD PTR fs:40	# tmp111, MEM[(<address-space-1> long unsigned int *)40B]
	mov	QWORD PTR 24[rsp], rax	# D.173078, tmp111
	movabs	rax, 164703072086692425	# tmp111,
# /usr/include/c++/15.2.1/bits/stl_vector.h:2230: 	return (std::min)(__diffmax, __allocmax);
	lea	rsi, 16[rsp]	# tmp104,
	lea	rdi, 8[rsp]	# tmp105,
# /usr/include/c++/15.2.1/bits/stl_vector.h:2227: 	const size_t __diffmax
	mov	QWORD PTR 8[rsp], rax	# __diffmax, tmp111
# /usr/include/c++/15.2.1/bits/stl_vector.h:2229: 	const size_t __allocmax = _Alloc_traits::max_size(__a);
	mov	QWORD PTR 16[rsp], rax	# __allocmax, tmp112
# /usr/include/c++/15.2.1/bits/stl_vector.h:2230: 	return (std::min)(__diffmax, __allocmax);
	call	_ZSt3minImERKT_S2_S2_	#
# /usr/include/c++/15.2.1/bits/stl_vector.h:2230: 	return (std::min)(__diffmax, __allocmax);
	mov	rax, QWORD PTR [rax]	# <retval>, *_1
# /usr/include/c++/15.2.1/bits/stl_vector.h:2231:       }
	mov	rdx, QWORD PTR 24[rsp]	# tmp109, D.173078
	sub	rdx, QWORD PTR fs:40	# tmp109, MEM[(<address-space-1> long unsigned int *)40B]
	jne	.L153	#,
	add	rsp, 40	#,
	.cfi_remember_state
	.cfi_def_cfa_offset 8
	ret	
.L153:
	.cfi_restore_state
	call	[QWORD PTR __stack_chk_fail@GOTPCREL[rip]]	#
	.cfi_endproc
.LFE13927:
	.size	_ZNSt6vectorI6ButtonSaIS0_EE11_S_max_sizeERKS1_.isra.0, .-_ZNSt6vectorI6ButtonSaIS0_EE11_S_max_sizeERKS1_.isra.0
	.section	.text._ZN6Config14getWindowWidthEv,"axG",@progbits,_ZN6Config14getWindowWidthEv,comdat
	.p2align 4
	.weak	_ZN6Config14getWindowWidthEv
	.type	_ZN6Config14getWindowWidthEv, @function
_ZN6Config14getWindowWidthEv:
.LFB12784:
	.cfi_startproc
# ../utils/../config/config.h:42:     static int   getWindowWidth()  { return windowWidth; }
	mov	eax, DWORD PTR _ZN6Config11windowWidthE[rip]	#, windowWidth
	ret	
	.cfi_endproc
.LFE12784:
	.size	_ZN6Config14getWindowWidthEv, .-_ZN6Config14getWindowWidthEv
	.section	.text._ZN6Config15getWindowHeightEv,"axG",@progbits,_ZN6Config15getWindowHeightEv,comdat
	.p2align 4
	.weak	_ZN6Config15getWindowHeightEv
	.type	_ZN6Config15getWindowHeightEv, @function
_ZN6Config15getWindowHeightEv:
.LFB12785:
	.cfi_startproc
# ../utils/../config/config.h:43:     static int   getWindowHeight() { return windowHeight; }
	mov	eax, DWORD PTR _ZN6Config12windowHeightE[rip]	#, windowHeight
	ret	
	.cfi_endproc
.LFE12785:
	.size	_ZN6Config15getWindowHeightEv, .-_ZN6Config15getWindowHeightEv
	.section	.text._ZN6Config13getBrightnessEv,"axG",@progbits,_ZN6Config13getBrightnessEv,comdat
	.p2align 4
	.weak	_ZN6Config13getBrightnessEv
	.type	_ZN6Config13getBrightnessEv, @function
_ZN6Config13getBrightnessEv:
.LFB12786:
	.cfi_startproc
# ../utils/../config/config.h:45:     static float getBrightness()  { return brightness; }
	movss	xmm0, DWORD PTR _ZN6Config10brightnessE[rip]	#, brightness
	ret	
	.cfi_endproc
.LFE12786:
	.size	_ZN6Config13getBrightnessEv, .-_ZN6Config13getBrightnessEv
	.section	.text._ZN6Config7getFontEv,"axG",@progbits,_ZN6Config7getFontEv,comdat
	.p2align 4
	.weak	_ZN6Config7getFontEv
	.type	_ZN6Config7getFontEv, @function
_ZN6Config7getFontEv:
.LFB12795:
	.cfi_startproc
# ../utils/../config/config.h:71:     static TTF_Font* getFont()      { return font; }
	mov	rax, QWORD PTR _ZN6Config4fontE[rip]	#, font
	ret	
	.cfi_endproc
.LFE12795:
	.size	_ZN6Config7getFontEv, .-_ZN6Config7getFontEv
	.section	.text._ZN6Config12getTitleFontEv,"axG",@progbits,_ZN6Config12getTitleFontEv,comdat
	.p2align 4
	.weak	_ZN6Config12getTitleFontEv
	.type	_ZN6Config12getTitleFontEv, @function
_ZN6Config12getTitleFontEv:
.LFB12796:
	.cfi_startproc
# ../utils/../config/config.h:72:     static TTF_Font* getTitleFont() { return titleFont; }
	mov	rax, QWORD PTR _ZN6Config9titleFontE[rip]	#, titleFont
	ret	
	.cfi_endproc
.LFE12796:
	.size	_ZN6Config12getTitleFontEv, .-_ZN6Config12getTitleFontEv
	.section	.text._ZN11ObjectStateC2Ev,"axG",@progbits,_ZN11ObjectStateC5Ev,comdat
	.align 2
	.p2align 4
	.weak	_ZN11ObjectStateC2Ev
	.type	_ZN11ObjectStateC2Ev, @function
_ZN11ObjectStateC2Ev:
.LFB12814:
	.cfi_startproc
# ../utils/save_manager.h:33: struct ObjectState {
	mov	QWORD PTR [rdi], 0	# MEM <vector(2) float> [(float *)this_2(D)],
	mov	BYTE PTR 8[rdi], 1	# *this_2(D).facingRight,
	mov	DWORD PTR 12[rdi], 0x00000000	# *this_2(D).hp,
	ret	
	.cfi_endproc
.LFE12814:
	.size	_ZN11ObjectStateC2Ev, .-_ZN11ObjectStateC2Ev
	.weak	_ZN11ObjectStateC1Ev
	.set	_ZN11ObjectStateC1Ev,_ZN11ObjectStateC2Ev
	.section	.text._ZN13GameSaveStateC2Ev,"axG",@progbits,_ZN13GameSaveStateC5Ev,comdat
	.align 2
	.p2align 4
	.weak	_ZN13GameSaveStateC2Ev
	.type	_ZN13GameSaveStateC2Ev, @function
_ZN13GameSaveStateC2Ev:
.LFB12816:
	.cfi_startproc
	push	rbx	#
	.cfi_def_cfa_offset 16
	.cfi_offset 3, -16
# ../utils/save_manager.h:45: struct GameSaveState {
	mov	rbx, rdi	# this, this
	call	_ZN11ObjectStateC1Ev	#
# ../utils/save_manager.h:45: struct GameSaveState {
	lea	rdi, 16[rbx]	# _2,
	call	_ZN11ObjectStateC1Ev	#
# ../utils/save_manager.h:45: struct GameSaveState {
	pxor	xmm0, xmm0	# tmp102
	mov	rax, QWORD PTR .LC3[rip]	# tmp105,
	mov	QWORD PTR 32[rbx], 0	# MEM <unsigned long> [(void *)this_3(D) + 32B],
	movups	XMMWORD PTR 40[rbx], xmm0	# MEM <vector(4) int> [(int *)this_3(D) + 40B], tmp102
	movdqa	xmm0, XMMWORD PTR .LC1[rip]	# tmp103,
	mov	QWORD PTR 88[rbx], rax	# MEM <vector(2) int> [(int *)this_3(D) + 88B], tmp105
	movups	XMMWORD PTR 56[rbx], xmm0	# MEM <vector(4) int> [(int *)this_3(D) + 56B], tmp103
	movdqa	xmm0, XMMWORD PTR .LC2[rip]	# tmp104,
	mov	DWORD PTR 96[rbx], 2	# *this_3(D).difficulty,
	movups	XMMWORD PTR 72[rbx], xmm0	# MEM <vector(4) int> [(int *)this_3(D) + 72B], tmp104
# ../utils/save_manager.h:45: struct GameSaveState {
	pop	rbx	#
	.cfi_def_cfa_offset 8
	ret	
	.cfi_endproc
.LFE12816:
	.size	_ZN13GameSaveStateC2Ev, .-_ZN13GameSaveStateC2Ev
	.weak	_ZN13GameSaveStateC1Ev
	.set	_ZN13GameSaveStateC1Ev,_ZN13GameSaveStateC2Ev
	.section	.text._ZNK11SaveManager10getEntriesEv,"axG",@progbits,_ZNK11SaveManager10getEntriesEv,comdat
	.align 2
	.p2align 4
	.weak	_ZNK11SaveManager10getEntriesEv
	.type	_ZNK11SaveManager10getEntriesEv, @function
_ZNK11SaveManager10getEntriesEv:
.LFB12823:
	.cfi_startproc
# ../utils/save_manager.h:192:     [[nodiscard]] const std::vector<SaveEntry>& getEntries() const { return entries; }
	lea	rax, 8[rdi]	# _2,
# ../utils/save_manager.h:192:     [[nodiscard]] const std::vector<SaveEntry>& getEntries() const { return entries; }
	ret	
	.cfi_endproc
.LFE12823:
	.size	_ZNK11SaveManager10getEntriesEv, .-_ZNK11SaveManager10getEntriesEv
	.section	.text._ZN5SceneD2Ev,"axG",@progbits,_ZN5SceneD5Ev,comdat
	.align 2
	.p2align 4
	.weak	_ZN5SceneD2Ev
	.type	_ZN5SceneD2Ev, @function
_ZN5SceneD2Ev:
.LFB12833:
	.cfi_startproc
# ../utils/scene_manager.h:8:     virtual ~Scene() = default;
	ret	
	.cfi_endproc
.LFE12833:
	.size	_ZN5SceneD2Ev, .-_ZN5SceneD2Ev
	.weak	_ZN5SceneD1Ev
	.set	_ZN5SceneD1Ev,_ZN5SceneD2Ev
	.section	.text._ZN5SceneD0Ev,"axG",@progbits,_ZN5SceneD5Ev,comdat
	.align 2
	.p2align 4
	.weak	_ZN5SceneD0Ev
	.type	_ZN5SceneD0Ev, @function
_ZN5SceneD0Ev:
.LFB12835:
	.cfi_startproc
# ../utils/scene_manager.h:8:     virtual ~Scene() = default;
	mov	esi, 8	#,
	jmp	[QWORD PTR _ZdlPvm@GOTPCREL[rip]]	#
	.cfi_endproc
.LFE12835:
	.size	_ZN5SceneD0Ev, .-_ZN5SceneD0Ev
	.section	.text._ZN6ButtonD2Ev,"axG",@progbits,_ZN6ButtonD5Ev,comdat
	.align 2
	.p2align 4
	.weak	_ZN6ButtonD2Ev
	.type	_ZN6ButtonD2Ev, @function
_ZN6ButtonD2Ev:
.LFB12837:
	.cfi_startproc
# ../ui/ui.h:19: struct Button {
	add	rdi, 16	# _1,
	jmp	[QWORD PTR _ZNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEED1Ev@GOTPCREL[rip]]	#
	.cfi_endproc
.LFE12837:
	.size	_ZN6ButtonD2Ev, .-_ZN6ButtonD2Ev
	.weak	_ZN6ButtonD1Ev
	.set	_ZN6ButtonD1Ev,_ZN6ButtonD2Ev
	.text
	.align 2
	.p2align 4
	.globl	_ZN10SavesScene20rebuildButtonsLayoutEv
	.type	_ZN10SavesScene20rebuildButtonsLayoutEv, @function
_ZN10SavesScene20rebuildButtonsLayoutEv:
.LFB12868:
	.cfi_startproc
	push	r14	#
	.cfi_def_cfa_offset 16
	.cfi_offset 14, -16
	push	r13	#
	.cfi_def_cfa_offset 24
	.cfi_offset 13, -24
	push	r12	#
	.cfi_def_cfa_offset 32
	.cfi_offset 12, -32
	push	rbp	#
	.cfi_def_cfa_offset 40
	.cfi_offset 6, -40
	push	rbx	#
	.cfi_def_cfa_offset 48
	.cfi_offset 3, -48
	sub	rsp, 32	#,
	.cfi_def_cfa_offset 80
# saves_scene.cpp:97:     const size_t total = slotButtons.size();
	mov	rsi, QWORD PTR 88[rdi]	# MEM[(struct Button * *)this_27(D) + 88B], MEM[(struct Button * *)this_27(D) + 88B]
	mov	rbx, QWORD PTR fs:40	# _43, MEM[(<address-space-1> long unsigned int *)40B]
	mov	QWORD PTR 24[rsp], rbx	# D.173140, _43
	mov	rbx, QWORD PTR 80[rdi]	# _43, MEM[(struct Button * *)this_27(D) + 80B]
	mov	rdi, rbx	#, _43
	call	_ZNKSt6vectorI6ButtonSaIS0_EE4sizeEv.isra.0	#
# saves_scene.cpp:100:     for (size_t row = 0; row * PLUS_BTN_COLUMNS < total; ++row) {
	test	rax, rax	# total
	je	.L166	#,
	mov	rbp, rax	# total,
# saves_scene.cpp:96:     const int W        = Config::getWindowWidth();
	call	_ZN6Config14getWindowWidthEv	#
	mov	r10d, 180	# ivtmp.810,
# saves_scene.cpp:100:     for (size_t row = 0; row * PLUS_BTN_COLUMNS < total; ++row) {
	xor	r9d, r9d	# _19
# saves_scene.cpp:107:         const int startX = (W - rowWidth) / 2;
	lea	r14d, -300[rax]	# tmp151,
# saves_scene.cpp:96:     const int W        = Config::getWindowWidth();
	mov	r13d, eax	# W,
# saves_scene.cpp:107:         const int startX = (W - rowWidth) / 2;
	shr	r14d, 31	# tmp151,
	lea	r14d, -300[rax+r14]	# tmp152,
	.p2align 4
	.p2align 3
.L172:
# saves_scene.cpp:102:         const size_t rowCount = std::min<size_t>(PLUS_BTN_COLUMNS, total - rowStart);
	mov	rax, rbp	# tmp127, total
# saves_scene.cpp:102:         const size_t rowCount = std::min<size_t>(PLUS_BTN_COLUMNS, total - rowStart);
	lea	rsi, 16[rsp]	#,
	lea	rdi, 8[rsp]	#,
# saves_scene.cpp:102:         const size_t rowCount = std::min<size_t>(PLUS_BTN_COLUMNS, total - rowStart);
	mov	QWORD PTR 8[rsp], 3	# D.161380,
# saves_scene.cpp:102:         const size_t rowCount = std::min<size_t>(PLUS_BTN_COLUMNS, total - rowStart);
	sub	rax, r9	# tmp127, _19
	mov	QWORD PTR 16[rsp], rax	# D.161381, tmp127
# saves_scene.cpp:102:         const size_t rowCount = std::min<size_t>(PLUS_BTN_COLUMNS, total - rowStart);
	call	_ZSt3minImERKT_S2_S2_.constprop.0	#
# saves_scene.cpp:102:         const size_t rowCount = std::min<size_t>(PLUS_BTN_COLUMNS, total - rowStart);
	mov	r8, QWORD PTR [rax]	# rowCount, *_3
# saves_scene.cpp:105:             rowCount * PLUS_BTN_W +
	cmp	r8, 1	# rowCount,
	jbe	.L168	#,
	imul	edx, r8d, 300	# _5, rowCount,
# saves_scene.cpp:105:             rowCount * PLUS_BTN_W +
	lea	eax, -5[r8+r8*4]	# iftmp.48_23,
# saves_scene.cpp:105:             rowCount * PLUS_BTN_W +
	lea	edx, [rdx+rax*4]	# _47,
# saves_scene.cpp:107:         const int startX = (W - rowWidth) / 2;
	mov	eax, r13d	# _46, W
	sub	eax, edx	# _46, _47
# saves_scene.cpp:107:         const int startX = (W - rowWidth) / 2;
	mov	ecx, eax	# tmp139, _46
	shr	ecx, 31	# tmp139,
	add	ecx, eax	# tmp140, _46
	sar	ecx	# startX
.L169:
# saves_scene.cpp:109:         for (size_t col = 0; col < rowCount; ++col) {
	xor	edx, edx	# col
	.p2align 4
	.p2align 3
.L171:
# saves_scene.cpp:110:             const size_t idx = rowStart + col;
	lea	rsi, [r9+rdx]	# idx_38,
# saves_scene.cpp:111:             slotButtons[idx].rect.x = startX + static_cast<int>(col * (PLUS_BTN_W + PLUS_BTN_GAP_X));
	mov	rdi, rbx	#, _43
# saves_scene.cpp:109:         for (size_t col = 0; col < rowCount; ++col) {
	add	rdx, 1	# col,
# saves_scene.cpp:111:             slotButtons[idx].rect.x = startX + static_cast<int>(col * (PLUS_BTN_W + PLUS_BTN_GAP_X));
	call	_ZNSt6vectorI6ButtonSaIS0_EEixEm.isra.0	#
# saves_scene.cpp:111:             slotButtons[idx].rect.x = startX + static_cast<int>(col * (PLUS_BTN_W + PLUS_BTN_GAP_X));
	mov	DWORD PTR [rax], ecx	# _14->rect.x, ivtmp.803
# saves_scene.cpp:109:         for (size_t col = 0; col < rowCount; ++col) {
	add	ecx, 320	# ivtmp.803,
# saves_scene.cpp:112:             slotButtons[idx].rect.y = PLUS_BTN_Y + static_cast<int>(row * rowStepY);
	mov	DWORD PTR 4[rax], r10d	# _14->rect.y, ivtmp.810
# saves_scene.cpp:109:         for (size_t col = 0; col < rowCount; ++col) {
	cmp	rdx, r8	# col, rowCount
	jb	.L171	#,
.L170:
# saves_scene.cpp:100:     for (size_t row = 0; row * PLUS_BTN_COLUMNS < total; ++row) {
	add	r9, 3	# _19,
# saves_scene.cpp:100:     for (size_t row = 0; row * PLUS_BTN_COLUMNS < total; ++row) {
	add	r10d, 80	# ivtmp.810,
	cmp	r9, rbp	# _19, total
	jb	.L172	#,
.L166:
# saves_scene.cpp:115: }
	mov	rax, QWORD PTR 24[rsp]	# tmp160, D.173140
	sub	rax, QWORD PTR fs:40	# tmp160, MEM[(<address-space-1> long unsigned int *)40B]
	jne	.L183	#,
	add	rsp, 32	#,
	.cfi_remember_state
	.cfi_def_cfa_offset 48
	pop	rbx	#
	.cfi_def_cfa_offset 40
	pop	rbp	#
	.cfi_def_cfa_offset 32
	pop	r12	#
	.cfi_def_cfa_offset 24
	pop	r13	#
	.cfi_def_cfa_offset 16
	pop	r14	#
	.cfi_def_cfa_offset 8
	ret	
	.p2align 4,,10
	.p2align 3
.L168:
	.cfi_restore_state
# saves_scene.cpp:109:         for (size_t col = 0; col < rowCount; ++col) {
	test	r8, r8	# rowCount
	je	.L170	#,
# saves_scene.cpp:107:         const int startX = (W - rowWidth) / 2;
	mov	ecx, r14d	# startX, tmp152
	sar	ecx	# startX
	jmp	.L169	#
.L183:
# saves_scene.cpp:115: }
	call	[QWORD PTR __stack_chk_fail@GOTPCREL[rip]]	#
	.cfi_endproc
.LFE12868:
	.size	_ZN10SavesScene20rebuildButtonsLayoutEv, .-_ZN10SavesScene20rebuildButtonsLayoutEv
	.align 2
	.p2align 4
	.globl	_ZNK10SavesScene13isPointInRectEiiRK8SDL_Rect
	.type	_ZNK10SavesScene13isPointInRectEiiRK8SDL_Rect, @function
_ZNK10SavesScene13isPointInRectEiiRK8SDL_Rect:
.LFB12869:
	.cfi_startproc
# saves_scene.cpp:122:     return x >= rect.x && x <= rect.x + rect.w &&
	mov	eax, DWORD PTR [rcx]	# _1, rect_9(D)->x
# saves_scene.cpp:121: bool SavesScene::isPointInRect(int x, int y, const SDL_Rect& rect) const {
	mov	edi, edx	# y, y
# saves_scene.cpp:123:            y >= rect.y && y <= rect.y + rect.h;
	xor	edx, edx	# <retval>
# saves_scene.cpp:123:            y >= rect.y && y <= rect.y + rect.h;
	cmp	eax, esi	# _1, x
	jg	.L184	#,
# saves_scene.cpp:122:     return x >= rect.x && x <= rect.x + rect.w &&
	add	eax, DWORD PTR 8[rcx]	# _3, rect_9(D)->w
# saves_scene.cpp:122:     return x >= rect.x && x <= rect.x + rect.w &&
	cmp	eax, esi	# _3, x
	jl	.L184	#,
# saves_scene.cpp:123:            y >= rect.y && y <= rect.y + rect.h;
	mov	eax, DWORD PTR 4[rcx]	# _4, rect_9(D)->y
# saves_scene.cpp:122:     return x >= rect.x && x <= rect.x + rect.w &&
	cmp	eax, edi	# _4, y
	jg	.L184	#,
# saves_scene.cpp:123:            y >= rect.y && y <= rect.y + rect.h;
	add	eax, DWORD PTR 12[rcx]	# _6, rect_9(D)->h
# saves_scene.cpp:123:            y >= rect.y && y <= rect.y + rect.h;
	cmp	eax, edi	# _6, y
	setge	dl	#, <retval>
.L184:
# saves_scene.cpp:124: }
	mov	eax, edx	#, <retval>
	ret	
	.cfi_endproc
.LFE12869:
	.size	_ZNK10SavesScene13isPointInRectEiiRK8SDL_Rect, .-_ZNK10SavesScene13isPointInRectEiiRK8SDL_Rect
	.align 2
	.p2align 4
	.globl	_ZN10SavesScene18openInputForButtonEi
	.type	_ZN10SavesScene18openInputForButtonEi, @function
_ZN10SavesScene18openInputForButtonEi:
.LFB12871:
	.cfi_startproc
# saves_scene.cpp:157:     if (index < 0 || index >= (int)slotButtons.size()) return;
	test	esi, esi	# index
	js	.L192	#,
# saves_scene.cpp:156: void SavesScene::openInputForButton(int index) {
	sub	rsp, 8	#,
	.cfi_def_cfa_offset 16
	mov	ecx, esi	# index, index
	mov	rdx, rdi	# this, this
# saves_scene.cpp:157:     if (index < 0 || index >= (int)slotButtons.size()) return;
	mov	rsi, QWORD PTR 88[rdi]	# MEM[(struct Button * *)this_8(D) + 88B], MEM[(struct Button * *)this_8(D) + 88B]
	mov	rdi, QWORD PTR 80[rdi]	# MEM[(struct Button * *)this_8(D) + 80B], MEM[(struct Button * *)this_8(D) + 80B]
	call	_ZNKSt6vectorI6ButtonSaIS0_EE4sizeEv.isra.0	#
# saves_scene.cpp:157:     if (index < 0 || index >= (int)slotButtons.size()) return;
	cmp	ecx, eax	# index, _2
	jl	.L195	#,
# saves_scene.cpp:162: }
	add	rsp, 8	#,
	.cfi_remember_state
	.cfi_def_cfa_offset 8
	ret	
	.p2align 4,,10
	.p2align 3
.L195:
	.cfi_restore_state
# saves_scene.cpp:159:     isInputVisible  = true;
	mov	eax, 1	#,
# saves_scene.cpp:158:     activePlusIndex = index;
	mov	DWORD PTR 144[rdx], ecx	# this_8(D)->activePlusIndex, index
# saves_scene.cpp:161:     inputText.clear();
	lea	rdi, 152[rdx]	# _4,
# saves_scene.cpp:159:     isInputVisible  = true;
	mov	WORD PTR 148[rdx], ax	# MEM <vector(2) unsigned char> [(bool *)this_8(D) + 148B],
# saves_scene.cpp:162: }
	add	rsp, 8	#,
	.cfi_def_cfa_offset 8
# saves_scene.cpp:161:     inputText.clear();
	jmp	[QWORD PTR _ZNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEE5clearEv@GOTPCREL[rip]]	#
	.p2align 4,,10
	.p2align 3
.L192:
	ret	
	.cfi_endproc
.LFE12871:
	.size	_ZN10SavesScene18openInputForButtonEi, .-_ZN10SavesScene18openInputForButtonEi
	.section	.text._ZNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEE12_Alloc_hiderD2Ev,"axG",@progbits,_ZNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEE12_Alloc_hiderD5Ev,comdat
	.align 2
	.p2align 4
	.weak	_ZNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEE12_Alloc_hiderD2Ev
	.type	_ZNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEE12_Alloc_hiderD2Ev, @function
_ZNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEE12_Alloc_hiderD2Ev:
.LFB13022:
	.cfi_startproc
# /usr/include/c++/15.2.1/bits/basic_string.h:197:       struct _Alloc_hider : allocator_type // TODO check __is_final
	ret	
	.cfi_endproc
.LFE13022:
	.size	_ZNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEE12_Alloc_hiderD2Ev, .-_ZNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEE12_Alloc_hiderD2Ev
	.weak	_ZNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEE12_Alloc_hiderD1Ev
	.set	_ZNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEE12_Alloc_hiderD1Ev,_ZNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEE12_Alloc_hiderD2Ev
	.section	.text._ZSt3maxImERKT_S2_S2_,"axG",@progbits,_ZSt3maxImERKT_S2_S2_,comdat
	.p2align 4
	.weak	_ZSt3maxImERKT_S2_S2_
	.type	_ZSt3maxImERKT_S2_S2_, @function
_ZSt3maxImERKT_S2_S2_:
.LFB13218:
	.cfi_startproc
# /usr/include/c++/15.2.1/bits/stl_algobase.h:265:       return __a;
	mov	rax, QWORD PTR [rsi]	# tmp108, *__b_6(D)
	cmp	QWORD PTR [rdi], rax	# *__a_5(D), tmp108
	mov	rax, rdi	# __a, __a
	cmovb	rax, rsi	# __b,, __a
# /usr/include/c++/15.2.1/bits/stl_algobase.h:266:     }
	ret	
	.cfi_endproc
.LFE13218:
	.size	_ZSt3maxImERKT_S2_S2_, .-_ZSt3maxImERKT_S2_S2_
	.section	.text._ZNSt12_Vector_baseI9SaveEntrySaIS0_EED2Ev,"axG",@progbits,_ZNSt12_Vector_baseI9SaveEntrySaIS0_EED5Ev,comdat
	.align 2
	.p2align 4
	.weak	_ZNSt12_Vector_baseI9SaveEntrySaIS0_EED2Ev
	.type	_ZNSt12_Vector_baseI9SaveEntrySaIS0_EED2Ev, @function
_ZNSt12_Vector_baseI9SaveEntrySaIS0_EED2Ev:
.LFB13248:
	.cfi_startproc
# /usr/include/c++/15.2.1/bits/stl_vector.h:373:       ~_Vector_base() _GLIBCXX_NOEXCEPT
	mov	rax, rdi	# this, this
# /usr/include/c++/15.2.1/bits/stl_vector.h:376: 		      _M_impl._M_end_of_storage - _M_impl._M_start);
	mov	rdi, QWORD PTR [rdi]	# _2, this_7(D)->_M_impl.D.153592._M_start
# /usr/include/c++/15.2.1/bits/stl_vector.h:376: 		      _M_impl._M_end_of_storage - _M_impl._M_start);
	mov	rsi, QWORD PTR 16[rax]	# this_7(D)->_M_impl.D.153592._M_end_of_storage, this_7(D)->_M_impl.D.153592._M_end_of_storage
	movabs	rax, -8198552921648689607	# tmp109,
	sub	rsi, rdi	# _3, _2
	sar	rsi, 3	# tmp107,
	imul	rsi, rax	# _4, tmp109
# /usr/include/c++/15.2.1/bits/stl_vector.h:375: 	_M_deallocate(_M_impl._M_start,
	jmp	_ZNSt12_Vector_baseI9SaveEntrySaIS0_EE13_M_deallocateEPS0_m.isra.0	#
	.cfi_endproc
.LFE13248:
	.size	_ZNSt12_Vector_baseI9SaveEntrySaIS0_EED2Ev, .-_ZNSt12_Vector_baseI9SaveEntrySaIS0_EED2Ev
	.weak	_ZNSt12_Vector_baseI9SaveEntrySaIS0_EED1Ev
	.set	_ZNSt12_Vector_baseI9SaveEntrySaIS0_EED1Ev,_ZNSt12_Vector_baseI9SaveEntrySaIS0_EED2Ev
	.section	.text._ZNSt12_Vector_baseI6ButtonSaIS0_EED2Ev,"axG",@progbits,_ZNSt12_Vector_baseI6ButtonSaIS0_EED5Ev,comdat
	.align 2
	.p2align 4
	.weak	_ZNSt12_Vector_baseI6ButtonSaIS0_EED2Ev
	.type	_ZNSt12_Vector_baseI6ButtonSaIS0_EED2Ev, @function
_ZNSt12_Vector_baseI6ButtonSaIS0_EED2Ev:
.LFB13271:
	.cfi_startproc
# /usr/include/c++/15.2.1/bits/stl_vector.h:373:       ~_Vector_base() _GLIBCXX_NOEXCEPT
	mov	rax, rdi	# this, this
# /usr/include/c++/15.2.1/bits/stl_vector.h:376: 		      _M_impl._M_end_of_storage - _M_impl._M_start);
	mov	rdi, QWORD PTR [rdi]	# _2, this_7(D)->_M_impl.D.154943._M_start
# /usr/include/c++/15.2.1/bits/stl_vector.h:376: 		      _M_impl._M_end_of_storage - _M_impl._M_start);
	mov	rsi, QWORD PTR 16[rax]	# this_7(D)->_M_impl.D.154943._M_end_of_storage, this_7(D)->_M_impl.D.154943._M_end_of_storage
	movabs	rax, 7905747460161236407	# tmp109,
	sub	rsi, rdi	# _3, _2
	sar	rsi, 3	# tmp107,
	imul	rsi, rax	# _4, tmp109
# /usr/include/c++/15.2.1/bits/stl_vector.h:375: 	_M_deallocate(_M_impl._M_start,
	jmp	_ZNSt12_Vector_baseI6ButtonSaIS0_EE13_M_deallocateEPS0_m.isra.0	#
	.cfi_endproc
.LFE13271:
	.size	_ZNSt12_Vector_baseI6ButtonSaIS0_EED2Ev, .-_ZNSt12_Vector_baseI6ButtonSaIS0_EED2Ev
	.weak	_ZNSt12_Vector_baseI6ButtonSaIS0_EED1Ev
	.set	_ZNSt12_Vector_baseI6ButtonSaIS0_EED1Ev,_ZNSt12_Vector_baseI6ButtonSaIS0_EED2Ev
	.section	.text._ZNSt6vectorI6ButtonSaIS0_EE5beginEv,"axG",@progbits,_ZNSt6vectorI6ButtonSaIS0_EE5beginEv,comdat
	.align 2
	.p2align 4
	.weak	_ZNSt6vectorI6ButtonSaIS0_EE5beginEv
	.type	_ZNSt6vectorI6ButtonSaIS0_EE5beginEv, @function
_ZNSt6vectorI6ButtonSaIS0_EE5beginEv:
.LFB13292:
	.cfi_startproc
# /usr/include/c++/15.2.1/bits/stl_vector.h:999:       { return iterator(this->_M_impl._M_start); }
	mov	rax, QWORD PTR [rdi]	# D.170125, MEM[(struct Button * const &)this_1(D)]
# /usr/include/c++/15.2.1/bits/stl_vector.h:999:       { return iterator(this->_M_impl._M_start); }
	ret	
	.cfi_endproc
.LFE13292:
	.size	_ZNSt6vectorI6ButtonSaIS0_EE5beginEv, .-_ZNSt6vectorI6ButtonSaIS0_EE5beginEv
	.section	.text._ZNSt6vectorI6ButtonSaIS0_EE3endEv,"axG",@progbits,_ZNSt6vectorI6ButtonSaIS0_EE3endEv,comdat
	.align 2
	.p2align 4
	.weak	_ZNSt6vectorI6ButtonSaIS0_EE3endEv
	.type	_ZNSt6vectorI6ButtonSaIS0_EE3endEv, @function
_ZNSt6vectorI6ButtonSaIS0_EE3endEv:
.LFB13293:
	.cfi_startproc
# /usr/include/c++/15.2.1/bits/stl_vector.h:1019:       { return iterator(this->_M_impl._M_finish); }
	mov	rax, QWORD PTR 8[rdi]	# D.170128, MEM[(struct Button * const &)this_1(D) + 8]
# /usr/include/c++/15.2.1/bits/stl_vector.h:1019:       { return iterator(this->_M_impl._M_finish); }
	ret	
	.cfi_endproc
.LFE13293:
	.size	_ZNSt6vectorI6ButtonSaIS0_EE3endEv, .-_ZNSt6vectorI6ButtonSaIS0_EE3endEv
	.text
	.align 2
	.p2align 4
	.type	_ZNSt6vectorI6ButtonSaIS0_EE4backEv.isra.0, @function
_ZNSt6vectorI6ButtonSaIS0_EE4backEv.isra.0:
.LFB13928:
	.cfi_startproc
# /usr/include/c++/15.2.1/bits/stl_vector.h:1372:       }
	ret	
	.cfi_endproc
.LFE13928:
	.size	_ZNSt6vectorI6ButtonSaIS0_EE4backEv.isra.0, .-_ZNSt6vectorI6ButtonSaIS0_EE4backEv.isra.0
	.section	.text._ZNSt6vectorIbSaIbEE5clearEv,"axG",@progbits,_ZNSt6vectorIbSaIbEE5clearEv,comdat
	.align 2
	.p2align 4
	.weak	_ZNSt6vectorIbSaIbEE5clearEv
	.type	_ZNSt6vectorIbSaIbEE5clearEv, @function
_ZNSt6vectorIbSaIbEE5clearEv:
.LFB13298:
	.cfi_startproc
	push	rbx	#
	.cfi_def_cfa_offset 16
	.cfi_offset 3, -16
	mov	rbx, rdi	# this, this
	sub	rsp, 16	#,
	.cfi_def_cfa_offset 32
# /usr/include/c++/15.2.1/bits/stl_bvector.h:1515:       { _M_erase_at_end(begin()); }
	mov	rdi, QWORD PTR [rdi]	# MEM[(_Bit_type * *)this_2(D)], MEM[(_Bit_type * *)this_2(D)]
	call	_ZNSt6vectorIbSaIbEE5beginEv.isra.0	#
# /usr/include/c++/15.2.1/bits/stl_bvector.h:1515:       { _M_erase_at_end(begin()); }
	mov	rdi, rbx	#, this
# /usr/include/c++/15.2.1/bits/stl_bvector.h:1515:       { _M_erase_at_end(begin()); }
	mov	QWORD PTR [rsp], rax	# D.170198, tmp107
	mov	rsi, rax	# tmp104, tmp107
	mov	QWORD PTR 8[rsp], rdx	# D.170198, tmp108
# /usr/include/c++/15.2.1/bits/stl_bvector.h:1515:       { _M_erase_at_end(begin()); }
	mov	edx, DWORD PTR 8[rsp]	#, MEM <unsigned char[12]> [(struct _Bit_iterator *)&D.170198]
# /usr/include/c++/15.2.1/bits/stl_bvector.h:1515:       { _M_erase_at_end(begin()); }
	add	rsp, 16	#,
	.cfi_def_cfa_offset 16
	pop	rbx	#
	.cfi_def_cfa_offset 8
# /usr/include/c++/15.2.1/bits/stl_bvector.h:1515:       { _M_erase_at_end(begin()); }
	jmp	_ZNSt6vectorIbSaIbEE15_M_erase_at_endESt13_Bit_iterator.isra.0	#
	.cfi_endproc
.LFE13298:
	.size	_ZNSt6vectorIbSaIbEE5clearEv, .-_ZNSt6vectorIbSaIbEE5clearEv
	.section	.text._ZNKSt6vectorI9SaveEntrySaIS0_EE5beginEv,"axG",@progbits,_ZNKSt6vectorI9SaveEntrySaIS0_EE5beginEv,comdat
	.align 2
	.p2align 4
	.weak	_ZNKSt6vectorI9SaveEntrySaIS0_EE5beginEv
	.type	_ZNKSt6vectorI9SaveEntrySaIS0_EE5beginEv, @function
_ZNKSt6vectorI9SaveEntrySaIS0_EE5beginEv:
.LFB13299:
	.cfi_startproc
# /usr/include/c++/15.2.1/bits/stl_vector.h:1009:       { return const_iterator(this->_M_impl._M_start); }
	mov	rax, QWORD PTR [rdi]	# D.170204, MEM[(const struct SaveEntry * const &)this_1(D)]
# /usr/include/c++/15.2.1/bits/stl_vector.h:1009:       { return const_iterator(this->_M_impl._M_start); }
	ret	
	.cfi_endproc
.LFE13299:
	.size	_ZNKSt6vectorI9SaveEntrySaIS0_EE5beginEv, .-_ZNKSt6vectorI9SaveEntrySaIS0_EE5beginEv
	.section	.text._ZNKSt6vectorI9SaveEntrySaIS0_EE3endEv,"axG",@progbits,_ZNKSt6vectorI9SaveEntrySaIS0_EE3endEv,comdat
	.align 2
	.p2align 4
	.weak	_ZNKSt6vectorI9SaveEntrySaIS0_EE3endEv
	.type	_ZNKSt6vectorI9SaveEntrySaIS0_EE3endEv, @function
_ZNKSt6vectorI9SaveEntrySaIS0_EE3endEv:
.LFB13300:
	.cfi_startproc
# /usr/include/c++/15.2.1/bits/stl_vector.h:1029:       { return const_iterator(this->_M_impl._M_finish); }
	mov	rax, QWORD PTR 8[rdi]	# D.170207, MEM[(const struct SaveEntry * const &)this_1(D) + 8]
# /usr/include/c++/15.2.1/bits/stl_vector.h:1029:       { return const_iterator(this->_M_impl._M_finish); }
	ret	
	.cfi_endproc
.LFE13300:
	.size	_ZNKSt6vectorI9SaveEntrySaIS0_EE3endEv, .-_ZNKSt6vectorI9SaveEntrySaIS0_EE3endEv
	.section	.text._ZStplIcSt11char_traitsIcESaIcEENSt7__cxx1112basic_stringIT_T0_T1_EERKS8_PKS5_,"axG",@progbits,_ZStplIcSt11char_traitsIcESaIcEENSt7__cxx1112basic_stringIT_T0_T1_EERKS8_PKS5_,comdat
	.p2align 4
	.weak	_ZStplIcSt11char_traitsIcESaIcEENSt7__cxx1112basic_stringIT_T0_T1_EERKS8_PKS5_
	.type	_ZStplIcSt11char_traitsIcESaIcEENSt7__cxx1112basic_stringIT_T0_T1_EERKS8_PKS5_, @function
_ZStplIcSt11char_traitsIcESaIcEENSt7__cxx1112basic_stringIT_T0_T1_EERKS8_PKS5_:
.LFB13308:
	.cfi_startproc
	push	r14	#
	.cfi_def_cfa_offset 16
	.cfi_offset 14, -16
	push	r13	#
	.cfi_def_cfa_offset 24
	.cfi_offset 13, -24
	push	r12	#
	.cfi_def_cfa_offset 32
	.cfi_offset 12, -32
	mov	r12, rdi	# <retval>, .result_ptr
# /usr/include/c++/15.2.1/bits/basic_string.h:3901: 				     __lhs.get_allocator());
	mov	rdi, rdx	#, __rhs
# /usr/include/c++/15.2.1/bits/basic_string.h:3894:     operator+(const basic_string<_CharT, _Traits, _Alloc>& __lhs,
	push	rbp	#
	.cfi_def_cfa_offset 40
	.cfi_offset 6, -40
	mov	rbp, rsi	# __lhs, __lhs
	push	rbx	#
	.cfi_def_cfa_offset 48
	.cfi_offset 3, -48
	sub	rsp, 16	#,
	.cfi_def_cfa_offset 64
# /usr/include/c++/15.2.1/bits/basic_string.h:3894:     operator+(const basic_string<_CharT, _Traits, _Alloc>& __lhs,
	mov	rbx, QWORD PTR fs:40	# __rhs, MEM[(<address-space-1> long unsigned int *)40B]
	mov	QWORD PTR 8[rsp], rbx	# D.173187, __rhs
	mov	rbx, rdx	# __rhs, __rhs
# /usr/include/c++/15.2.1/bits/basic_string.h:3901: 				     __lhs.get_allocator());
	call	_ZNSt11char_traitsIcE6lengthEPKc	#
# /usr/include/c++/15.2.1/bits/basic_string.h:3901: 				     __lhs.get_allocator());
	mov	rdi, rbp	#, __lhs
# /usr/include/c++/15.2.1/bits/basic_string.h:3901: 				     __lhs.get_allocator());
	mov	r14, rax	# _7,
# /usr/include/c++/15.2.1/bits/basic_string.h:3901: 				     __lhs.get_allocator());
	call	[QWORD PTR _ZNKSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEE4sizeEv@GOTPCREL[rip]]	#
# /usr/include/c++/15.2.1/bits/basic_string.h:3901: 				     __lhs.get_allocator());
	mov	rdi, rbp	#, __lhs
# /usr/include/c++/15.2.1/bits/basic_string.h:3901: 				     __lhs.get_allocator());
	mov	r13, rax	# _1,
# /usr/include/c++/15.2.1/bits/basic_string.h:3901: 				     __lhs.get_allocator());
	call	[QWORD PTR _ZNKSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEE5c_strEv@GOTPCREL[rip]]	#
# /usr/include/c++/15.2.1/bits/basic_string.h:3901: 				     __lhs.get_allocator());
	mov	r8, r14	#, _7
	mov	rdx, r13	#, _1
	mov	rdi, r12	#, <retval>
	mov	rsi, rax	#, _2
	mov	rcx, rbx	#, __rhs
	call	_ZSt12__str_concatINSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEEEET_PKNS6_10value_typeENS6_9size_typeES9_SA_RKNS6_14allocator_typeE.isra.0	#
# /usr/include/c++/15.2.1/bits/basic_string.h:3902:     }
	mov	rax, QWORD PTR 8[rsp]	# tmp114, D.173187
	sub	rax, QWORD PTR fs:40	# tmp114, MEM[(<address-space-1> long unsigned int *)40B]
	jne	.L212	#,
	add	rsp, 16	#,
	.cfi_remember_state
	.cfi_def_cfa_offset 48
	mov	rax, r12	#, <retval>
	pop	rbx	#
	.cfi_def_cfa_offset 40
	pop	rbp	#
	.cfi_def_cfa_offset 32
	pop	r12	#
	.cfi_def_cfa_offset 24
	pop	r13	#
	.cfi_def_cfa_offset 16
	pop	r14	#
	.cfi_def_cfa_offset 8
	ret	
.L212:
	.cfi_restore_state
	call	[QWORD PTR __stack_chk_fail@GOTPCREL[rip]]	#
	.cfi_endproc
.LFE13308:
	.size	_ZStplIcSt11char_traitsIcESaIcEENSt7__cxx1112basic_stringIT_T0_T1_EERKS8_PKS5_, .-_ZStplIcSt11char_traitsIcESaIcEENSt7__cxx1112basic_stringIT_T0_T1_EERKS8_PKS5_
	.section	.text._ZNSt12_Vector_baseI9SaveEntrySaIS0_EE17_Vector_impl_dataC2Ev,"axG",@progbits,_ZNSt12_Vector_baseI9SaveEntrySaIS0_EE17_Vector_impl_dataC5Ev,comdat
	.align 2
	.p2align 4
	.weak	_ZNSt12_Vector_baseI9SaveEntrySaIS0_EE17_Vector_impl_dataC2Ev
	.type	_ZNSt12_Vector_baseI9SaveEntrySaIS0_EE17_Vector_impl_dataC2Ev, @function
_ZNSt12_Vector_baseI9SaveEntrySaIS0_EE17_Vector_impl_dataC2Ev:
.LFB13490:
	.cfi_startproc
# /usr/include/c++/15.2.1/bits/stl_vector.h:106: 	: _M_start(), _M_finish(), _M_end_of_storage()
	pxor	xmm0, xmm0	# tmp99
# /usr/include/c++/15.2.1/bits/stl_vector.h:106: 	: _M_start(), _M_finish(), _M_end_of_storage()
	mov	QWORD PTR 16[rdi], 0	# *this_2(D)._M_end_of_storage,
# /usr/include/c++/15.2.1/bits/stl_vector.h:106: 	: _M_start(), _M_finish(), _M_end_of_storage()
	movups	XMMWORD PTR [rdi], xmm0	# MEM <vector(2) long unsigned int> [(struct SaveEntry * *)this_2(D)], tmp99
# /usr/include/c++/15.2.1/bits/stl_vector.h:107: 	{ }
	ret	
	.cfi_endproc
.LFE13490:
	.size	_ZNSt12_Vector_baseI9SaveEntrySaIS0_EE17_Vector_impl_dataC2Ev, .-_ZNSt12_Vector_baseI9SaveEntrySaIS0_EE17_Vector_impl_dataC2Ev
	.weak	_ZNSt12_Vector_baseI9SaveEntrySaIS0_EE17_Vector_impl_dataC1Ev
	.set	_ZNSt12_Vector_baseI9SaveEntrySaIS0_EE17_Vector_impl_dataC1Ev,_ZNSt12_Vector_baseI9SaveEntrySaIS0_EE17_Vector_impl_dataC2Ev
	.section	.text._ZNSt12_Vector_baseI9SaveEntrySaIS0_EE12_Vector_implC2Ev,"axG",@progbits,_ZNSt12_Vector_baseI9SaveEntrySaIS0_EE12_Vector_implC5Ev,comdat
	.align 2
	.p2align 4
	.weak	_ZNSt12_Vector_baseI9SaveEntrySaIS0_EE12_Vector_implC2Ev
	.type	_ZNSt12_Vector_baseI9SaveEntrySaIS0_EE12_Vector_implC2Ev, @function
_ZNSt12_Vector_baseI9SaveEntrySaIS0_EE12_Vector_implC2Ev:
.LFB13242:
	.cfi_startproc
# /usr/include/c++/15.2.1/bits/stl_vector.h:148: 	: _Tp_alloc_type()
	jmp	_ZNSt12_Vector_baseI9SaveEntrySaIS0_EE17_Vector_impl_dataC2Ev	#
	.cfi_endproc
.LFE13242:
	.size	_ZNSt12_Vector_baseI9SaveEntrySaIS0_EE12_Vector_implC2Ev, .-_ZNSt12_Vector_baseI9SaveEntrySaIS0_EE12_Vector_implC2Ev
	.weak	_ZNSt12_Vector_baseI9SaveEntrySaIS0_EE12_Vector_implC1Ev
	.set	_ZNSt12_Vector_baseI9SaveEntrySaIS0_EE12_Vector_implC1Ev,_ZNSt12_Vector_baseI9SaveEntrySaIS0_EE12_Vector_implC2Ev
	.section	.text._ZNSt12_Vector_baseI9SaveEntrySaIS0_EEC2Ev,"axG",@progbits,_ZNSt12_Vector_baseI9SaveEntrySaIS0_EEC5Ev,comdat
	.align 2
	.p2align 4
	.weak	_ZNSt12_Vector_baseI9SaveEntrySaIS0_EEC2Ev
	.type	_ZNSt12_Vector_baseI9SaveEntrySaIS0_EEC2Ev, @function
_ZNSt12_Vector_baseI9SaveEntrySaIS0_EEC2Ev:
.LFB12808:
	.cfi_startproc
# /usr/include/c++/15.2.1/bits/stl_vector.h:321:       _Vector_base() = default;
	jmp	_ZNSt12_Vector_baseI9SaveEntrySaIS0_EE12_Vector_implC1Ev	#
	.cfi_endproc
.LFE12808:
	.size	_ZNSt12_Vector_baseI9SaveEntrySaIS0_EEC2Ev, .-_ZNSt12_Vector_baseI9SaveEntrySaIS0_EEC2Ev
	.weak	_ZNSt12_Vector_baseI9SaveEntrySaIS0_EEC1Ev
	.set	_ZNSt12_Vector_baseI9SaveEntrySaIS0_EEC1Ev,_ZNSt12_Vector_baseI9SaveEntrySaIS0_EEC2Ev
	.section	.text._ZNSt6vectorI9SaveEntrySaIS0_EEC2Ev,"axG",@progbits,_ZNSt6vectorI9SaveEntrySaIS0_EEC5Ev,comdat
	.align 2
	.p2align 4
	.weak	_ZNSt6vectorI9SaveEntrySaIS0_EEC2Ev
	.type	_ZNSt6vectorI9SaveEntrySaIS0_EEC2Ev, @function
_ZNSt6vectorI9SaveEntrySaIS0_EEC2Ev:
.LFB12810:
	.cfi_startproc
# /usr/include/c++/15.2.1/bits/stl_vector.h:561:       vector() = default;
	jmp	_ZNSt12_Vector_baseI9SaveEntrySaIS0_EEC2Ev	#
	.cfi_endproc
.LFE12810:
	.size	_ZNSt6vectorI9SaveEntrySaIS0_EEC2Ev, .-_ZNSt6vectorI9SaveEntrySaIS0_EEC2Ev
	.weak	_ZNSt6vectorI9SaveEntrySaIS0_EEC1Ev
	.set	_ZNSt6vectorI9SaveEntrySaIS0_EEC1Ev,_ZNSt6vectorI9SaveEntrySaIS0_EEC2Ev
	.section	.text._ZN11SaveManagerC2Ev,"axG",@progbits,_ZN11SaveManagerC5Ev,comdat
	.align 2
	.p2align 4
	.weak	_ZN11SaveManagerC2Ev
	.type	_ZN11SaveManagerC2Ev, @function
_ZN11SaveManagerC2Ev:
.LFB12818:
	.cfi_startproc
	push	rbx	#
	.cfi_def_cfa_offset 16
	.cfi_offset 3, -16
# ../utils/save_manager.h:112:     SaveManager() = default;
	mov	rbx, rdi	# this, this
	lea	rdi, 8[rdi]	# _1,
	mov	DWORD PTR -8[rdi], 0x00000000	# *this_5(D).autosaveTimer,
	call	_ZNSt6vectorI9SaveEntrySaIS0_EEC1Ev	#
# ../utils/save_manager.h:112:     SaveManager() = default;
	mov	DWORD PTR 32[rbx], 1	# *this_5(D).nextSaveNumber,
	lea	rdi, 36[rbx]	# _2,
	call	_ZN13GameSaveStateC1Ev	#
# ../utils/save_manager.h:112:     SaveManager() = default;
	mov	BYTE PTR 136[rbx], 0	# *this_5(D).hasAutosave,
# ../utils/save_manager.h:112:     SaveManager() = default;
	pop	rbx	#
	.cfi_def_cfa_offset 8
	ret	
	.cfi_endproc
.LFE12818:
	.size	_ZN11SaveManagerC2Ev, .-_ZN11SaveManagerC2Ev
	.weak	_ZN11SaveManagerC1Ev
	.set	_ZN11SaveManagerC1Ev,_ZN11SaveManagerC2Ev
	.section	.text._ZN11SaveManager3getEv,"axG",@progbits,_ZN11SaveManager3getEv,comdat
	.p2align 4
	.weak	_ZN11SaveManager3getEv
	.type	_ZN11SaveManager3getEv, @function
_ZN11SaveManager3getEv:
.LFB12800:
	.cfi_startproc
# ../utils/save_manager.h:117:         static SaveManager instance;
	movzx	eax, BYTE PTR _ZGVZN11SaveManager3getEvE8instance[rip]	# _1,
# ../utils/save_manager.h:117:         static SaveManager instance;
	test	al, al	# _1
	je	.L220	#,
	lea	rcx, _ZZN11SaveManager3getEvE8instance[rip]	# <retval>,
# ../utils/save_manager.h:119:     }
	mov	rax, rcx	#, <retval>
	ret	
	.p2align 4,,10
	.p2align 3
.L220:
# ../utils/save_manager.h:116:     static SaveManager& get() {
	sub	rsp, 24	#,
	.cfi_def_cfa_offset 32
# ../utils/save_manager.h:117:         static SaveManager instance;
	lea	rdi, _ZGVZN11SaveManager3getEvE8instance[rip]	#,
	call	[QWORD PTR __cxa_guard_acquire@GOTPCREL[rip]]	#
	lea	rcx, _ZZN11SaveManager3getEvE8instance[rip]	# <retval>,
# ../utils/save_manager.h:117:         static SaveManager instance;
	test	eax, eax	# _2
	jne	.L229	#,
# ../utils/save_manager.h:119:     }
	mov	rax, rcx	#, <retval>
	add	rsp, 24	#,
	.cfi_remember_state
	.cfi_def_cfa_offset 8
	ret	
	.p2align 4,,10
	.p2align 3
.L229:
	.cfi_restore_state
# ../utils/save_manager.h:117:         static SaveManager instance;
	mov	rdi, rcx	#, <retval>
	mov	QWORD PTR 8[rsp], rcx	# %sfp, <retval>
	call	_ZN11SaveManagerC1Ev	#
# ../utils/save_manager.h:117:         static SaveManager instance;
	mov	rsi, QWORD PTR 8[rsp]	#, %sfp
	lea	rdx, __dso_handle[rip]	#,
	lea	rdi, _ZN11SaveManagerD1Ev[rip]	#,
	call	[QWORD PTR __cxa_atexit@GOTPCREL[rip]]	#
# ../utils/save_manager.h:117:         static SaveManager instance;
	lea	rdi, _ZGVZN11SaveManager3getEvE8instance[rip]	#,
	call	[QWORD PTR __cxa_guard_release@GOTPCREL[rip]]	#
	mov	rcx, QWORD PTR 8[rsp]	# <retval>, %sfp
# ../utils/save_manager.h:119:     }
	add	rsp, 24	#,
	.cfi_def_cfa_offset 8
	mov	rax, rcx	#, <retval>
	ret	
	.cfi_endproc
.LFE12800:
	.size	_ZN11SaveManager3getEv, .-_ZN11SaveManager3getEv
	.section	.text._ZNSt12_Vector_baseI6ButtonSaIS0_EE17_Vector_impl_dataC2Ev,"axG",@progbits,_ZNSt12_Vector_baseI6ButtonSaIS0_EE17_Vector_impl_dataC5Ev,comdat
	.align 2
	.p2align 4
	.weak	_ZNSt12_Vector_baseI6ButtonSaIS0_EE17_Vector_impl_dataC2Ev
	.type	_ZNSt12_Vector_baseI6ButtonSaIS0_EE17_Vector_impl_dataC2Ev, @function
_ZNSt12_Vector_baseI6ButtonSaIS0_EE17_Vector_impl_dataC2Ev:
.LFB13511:
	.cfi_startproc
# /usr/include/c++/15.2.1/bits/stl_vector.h:106: 	: _M_start(), _M_finish(), _M_end_of_storage()
	pxor	xmm0, xmm0	# tmp99
# /usr/include/c++/15.2.1/bits/stl_vector.h:106: 	: _M_start(), _M_finish(), _M_end_of_storage()
	mov	QWORD PTR 16[rdi], 0	# *this_2(D)._M_end_of_storage,
# /usr/include/c++/15.2.1/bits/stl_vector.h:106: 	: _M_start(), _M_finish(), _M_end_of_storage()
	movups	XMMWORD PTR [rdi], xmm0	# MEM <vector(2) long unsigned int> [(struct Button * *)this_2(D)], tmp99
# /usr/include/c++/15.2.1/bits/stl_vector.h:107: 	{ }
	ret	
	.cfi_endproc
.LFE13511:
	.size	_ZNSt12_Vector_baseI6ButtonSaIS0_EE17_Vector_impl_dataC2Ev, .-_ZNSt12_Vector_baseI6ButtonSaIS0_EE17_Vector_impl_dataC2Ev
	.weak	_ZNSt12_Vector_baseI6ButtonSaIS0_EE17_Vector_impl_dataC1Ev
	.set	_ZNSt12_Vector_baseI6ButtonSaIS0_EE17_Vector_impl_dataC1Ev,_ZNSt12_Vector_baseI6ButtonSaIS0_EE17_Vector_impl_dataC2Ev
	.section	.text._ZNSt12_Vector_baseI6ButtonSaIS0_EE12_Vector_implC2Ev,"axG",@progbits,_ZNSt12_Vector_baseI6ButtonSaIS0_EE12_Vector_implC5Ev,comdat
	.align 2
	.p2align 4
	.weak	_ZNSt12_Vector_baseI6ButtonSaIS0_EE12_Vector_implC2Ev
	.type	_ZNSt12_Vector_baseI6ButtonSaIS0_EE12_Vector_implC2Ev, @function
_ZNSt12_Vector_baseI6ButtonSaIS0_EE12_Vector_implC2Ev:
.LFB13265:
	.cfi_startproc
# /usr/include/c++/15.2.1/bits/stl_vector.h:148: 	: _Tp_alloc_type()
	jmp	_ZNSt12_Vector_baseI6ButtonSaIS0_EE17_Vector_impl_dataC2Ev	#
	.cfi_endproc
.LFE13265:
	.size	_ZNSt12_Vector_baseI6ButtonSaIS0_EE12_Vector_implC2Ev, .-_ZNSt12_Vector_baseI6ButtonSaIS0_EE12_Vector_implC2Ev
	.weak	_ZNSt12_Vector_baseI6ButtonSaIS0_EE12_Vector_implC1Ev
	.set	_ZNSt12_Vector_baseI6ButtonSaIS0_EE12_Vector_implC1Ev,_ZNSt12_Vector_baseI6ButtonSaIS0_EE12_Vector_implC2Ev
	.section	.text._ZNSt12_Vector_baseI6ButtonSaIS0_EEC2Ev,"axG",@progbits,_ZNSt12_Vector_baseI6ButtonSaIS0_EEC5Ev,comdat
	.align 2
	.p2align 4
	.weak	_ZNSt12_Vector_baseI6ButtonSaIS0_EEC2Ev
	.type	_ZNSt12_Vector_baseI6ButtonSaIS0_EEC2Ev, @function
_ZNSt12_Vector_baseI6ButtonSaIS0_EEC2Ev:
.LFB12845:
	.cfi_startproc
# /usr/include/c++/15.2.1/bits/stl_vector.h:321:       _Vector_base() = default;
	jmp	_ZNSt12_Vector_baseI6ButtonSaIS0_EE12_Vector_implC1Ev	#
	.cfi_endproc
.LFE12845:
	.size	_ZNSt12_Vector_baseI6ButtonSaIS0_EEC2Ev, .-_ZNSt12_Vector_baseI6ButtonSaIS0_EEC2Ev
	.weak	_ZNSt12_Vector_baseI6ButtonSaIS0_EEC1Ev
	.set	_ZNSt12_Vector_baseI6ButtonSaIS0_EEC1Ev,_ZNSt12_Vector_baseI6ButtonSaIS0_EEC2Ev
	.section	.text._ZNSt6vectorI6ButtonSaIS0_EEC2Ev,"axG",@progbits,_ZNSt6vectorI6ButtonSaIS0_EEC5Ev,comdat
	.align 2
	.p2align 4
	.weak	_ZNSt6vectorI6ButtonSaIS0_EEC2Ev
	.type	_ZNSt6vectorI6ButtonSaIS0_EEC2Ev, @function
_ZNSt6vectorI6ButtonSaIS0_EEC2Ev:
.LFB12847:
	.cfi_startproc
# /usr/include/c++/15.2.1/bits/stl_vector.h:561:       vector() = default;
	jmp	_ZNSt12_Vector_baseI6ButtonSaIS0_EEC2Ev	#
	.cfi_endproc
.LFE12847:
	.size	_ZNSt6vectorI6ButtonSaIS0_EEC2Ev, .-_ZNSt6vectorI6ButtonSaIS0_EEC2Ev
	.weak	_ZNSt6vectorI6ButtonSaIS0_EEC1Ev
	.set	_ZNSt6vectorI6ButtonSaIS0_EEC1Ev,_ZNSt6vectorI6ButtonSaIS0_EEC2Ev
	.section	.text._ZNSt12_Vector_baseI6ButtonSaIS0_EE19_M_get_Tp_allocatorEv,"axG",@progbits,_ZNSt12_Vector_baseI6ButtonSaIS0_EE19_M_get_Tp_allocatorEv,comdat
	.align 2
	.p2align 4
	.weak	_ZNSt12_Vector_baseI6ButtonSaIS0_EE19_M_get_Tp_allocatorEv
	.type	_ZNSt12_Vector_baseI6ButtonSaIS0_EE19_M_get_Tp_allocatorEv, @function
_ZNSt12_Vector_baseI6ButtonSaIS0_EE19_M_get_Tp_allocatorEv:
.LFB13517:
	.cfi_startproc
# /usr/include/c++/15.2.1/bits/stl_vector.h:307:       _M_get_Tp_allocator() _GLIBCXX_NOEXCEPT
	mov	rax, rdi	# this, this
# /usr/include/c++/15.2.1/bits/stl_vector.h:308:       { return this->_M_impl; }
	ret	
	.cfi_endproc
.LFE13517:
	.size	_ZNSt12_Vector_baseI6ButtonSaIS0_EE19_M_get_Tp_allocatorEv, .-_ZNSt12_Vector_baseI6ButtonSaIS0_EE19_M_get_Tp_allocatorEv
	.section	.text._ZNSt13_Bvector_baseISaIbEE18_Bvector_impl_dataC2Ev,"axG",@progbits,_ZNSt13_Bvector_baseISaIbEE18_Bvector_impl_dataC5Ev,comdat
	.align 2
	.p2align 4
	.weak	_ZNSt13_Bvector_baseISaIbEE18_Bvector_impl_dataC2Ev
	.type	_ZNSt13_Bvector_baseISaIbEE18_Bvector_impl_dataC2Ev, @function
_ZNSt13_Bvector_baseISaIbEE18_Bvector_impl_dataC2Ev:
.LFB13523:
	.cfi_startproc
	push	rbx	#
	.cfi_def_cfa_offset 16
	.cfi_offset 3, -16
# /usr/include/c++/15.2.1/bits/stl_bvector.h:557: 	_Bvector_impl_data() _GLIBCXX_NOEXCEPT
	mov	rbx, rdi	# this, this
# /usr/include/c++/15.2.1/bits/stl_bvector.h:558: 	: _M_start(), _M_finish(), _M_end_of_storage()
	call	_ZNSt13_Bit_iteratorC1Ev	#
# /usr/include/c++/15.2.1/bits/stl_bvector.h:558: 	: _M_start(), _M_finish(), _M_end_of_storage()
	lea	rdi, 16[rbx]	# _2,
	call	_ZNSt13_Bit_iteratorC1Ev	#
# /usr/include/c++/15.2.1/bits/stl_bvector.h:558: 	: _M_start(), _M_finish(), _M_end_of_storage()
	mov	QWORD PTR 32[rbx], 0	# *this_4(D)._M_end_of_storage,
# /usr/include/c++/15.2.1/bits/stl_bvector.h:559: 	{ }
	pop	rbx	#
	.cfi_def_cfa_offset 8
	ret	
	.cfi_endproc
.LFE13523:
	.size	_ZNSt13_Bvector_baseISaIbEE18_Bvector_impl_dataC2Ev, .-_ZNSt13_Bvector_baseISaIbEE18_Bvector_impl_dataC2Ev
	.weak	_ZNSt13_Bvector_baseISaIbEE18_Bvector_impl_dataC1Ev
	.set	_ZNSt13_Bvector_baseISaIbEE18_Bvector_impl_dataC1Ev,_ZNSt13_Bvector_baseISaIbEE18_Bvector_impl_dataC2Ev
	.section	.text._ZNSt13_Bvector_baseISaIbEE13_Bvector_implC2Ev,"axG",@progbits,_ZNSt13_Bvector_baseISaIbEE13_Bvector_implC5Ev,comdat
	.align 2
	.p2align 4
	.weak	_ZNSt13_Bvector_baseISaIbEE13_Bvector_implC2Ev
	.type	_ZNSt13_Bvector_baseISaIbEE13_Bvector_implC2Ev, @function
_ZNSt13_Bvector_baseISaIbEE13_Bvector_implC2Ev:
.LFB13277:
	.cfi_startproc
# /usr/include/c++/15.2.1/bits/stl_bvector.h:605: 	: _Bit_alloc_type()
	jmp	_ZNSt13_Bvector_baseISaIbEE18_Bvector_impl_dataC2Ev	#
	.cfi_endproc
.LFE13277:
	.size	_ZNSt13_Bvector_baseISaIbEE13_Bvector_implC2Ev, .-_ZNSt13_Bvector_baseISaIbEE13_Bvector_implC2Ev
	.weak	_ZNSt13_Bvector_baseISaIbEE13_Bvector_implC1Ev
	.set	_ZNSt13_Bvector_baseISaIbEE13_Bvector_implC1Ev,_ZNSt13_Bvector_baseISaIbEE13_Bvector_implC2Ev
	.section	.text._ZNSt13_Bvector_baseISaIbEEC2Ev,"axG",@progbits,_ZNSt13_Bvector_baseISaIbEEC5Ev,comdat
	.align 2
	.p2align 4
	.weak	_ZNSt13_Bvector_baseISaIbEEC2Ev
	.type	_ZNSt13_Bvector_baseISaIbEEC2Ev, @function
_ZNSt13_Bvector_baseISaIbEEC2Ev:
.LFB12855:
	.cfi_startproc
# /usr/include/c++/15.2.1/bits/stl_bvector.h:656:       _Bvector_base() = default;
	jmp	_ZNSt13_Bvector_baseISaIbEE13_Bvector_implC1Ev	#
	.cfi_endproc
.LFE12855:
	.size	_ZNSt13_Bvector_baseISaIbEEC2Ev, .-_ZNSt13_Bvector_baseISaIbEEC2Ev
	.weak	_ZNSt13_Bvector_baseISaIbEEC1Ev
	.set	_ZNSt13_Bvector_baseISaIbEEC1Ev,_ZNSt13_Bvector_baseISaIbEEC2Ev
	.section	.text._ZNSt6vectorIbSaIbEEC2Ev,"axG",@progbits,_ZNSt6vectorIbSaIbEEC5Ev,comdat
	.align 2
	.p2align 4
	.weak	_ZNSt6vectorIbSaIbEEC2Ev
	.type	_ZNSt6vectorIbSaIbEEC2Ev, @function
_ZNSt6vectorIbSaIbEEC2Ev:
.LFB12857:
	.cfi_startproc
# /usr/include/c++/15.2.1/bits/stl_bvector.h:787:       vector() = default;
	jmp	_ZNSt13_Bvector_baseISaIbEEC2Ev	#
	.cfi_endproc
.LFE12857:
	.size	_ZNSt6vectorIbSaIbEEC2Ev, .-_ZNSt6vectorIbSaIbEEC2Ev
	.weak	_ZNSt6vectorIbSaIbEEC1Ev
	.set	_ZNSt6vectorIbSaIbEEC1Ev,_ZNSt6vectorIbSaIbEEC2Ev
	.section	.text._ZNSt6vectorIbSaIbEE3endEv,"axG",@progbits,_ZNSt6vectorIbSaIbEE3endEv,comdat
	.align 2
	.p2align 4
	.weak	_ZNSt6vectorIbSaIbEE3endEv
	.type	_ZNSt6vectorIbSaIbEE3endEv, @function
_ZNSt6vectorIbSaIbEE3endEv:
.LFB13557:
	.cfi_startproc
# /usr/include/c++/15.2.1/bits/stl_bvector.h:1076:       { return this->_M_impl._M_finish; }
	mov	rax, QWORD PTR 16[rdi]	# this_2(D)->D.156758._M_impl.D.156243._M_finish, this_2(D)->D.156758._M_impl.D.156243._M_finish
	mov	rdx, QWORD PTR 24[rdi]	# this_2(D)->D.156758._M_impl.D.156243._M_finish, this_2(D)->D.156758._M_impl.D.156243._M_finish
# /usr/include/c++/15.2.1/bits/stl_bvector.h:1076:       { return this->_M_impl._M_finish; }
	ret	
	.cfi_endproc
.LFE13557:
	.size	_ZNSt6vectorIbSaIbEE3endEv, .-_ZNSt6vectorIbSaIbEE3endEv
	.section	.text._ZNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEE13_S_copy_charsIPKcEEvPcT_S9_,"axG",@progbits,_ZNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEE13_S_copy_charsIPKcEEvPcT_S9_,comdat
	.p2align 4
	.weak	_ZNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEE13_S_copy_charsIPKcEEvPcT_S9_
	.type	_ZNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEE13_S_copy_charsIPKcEEvPcT_S9_, @function
_ZNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEE13_S_copy_charsIPKcEEvPcT_S9_:
.LFB13616:
	.cfi_startproc
# /usr/include/c++/15.2.1/bits/basic_string.h:489: 	    _S_copy(__p, std::__niter_base(__k1), __k2 - __k1);
	sub	rdx, rsi	# _1, __k1
# /usr/include/c++/15.2.1/bits/basic_string.h:489: 	    _S_copy(__p, std::__niter_base(__k1), __k2 - __k1);
	jmp	[QWORD PTR _ZNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEE7_S_copyEPcPKcm@GOTPCREL[rip]]	#
	.cfi_endproc
.LFE13616:
	.size	_ZNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEE13_S_copy_charsIPKcEEvPcT_S9_, .-_ZNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEE13_S_copy_charsIPKcEEvPcT_S9_
	.section	.text._ZNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEE12_M_constructIPKcEEvT_S8_St20forward_iterator_tag.isra.0,"axG",@progbits,_ZNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEEC5IS3_EEPKcRKS3_,comdat
	.align 2
	.p2align 4
	.type	_ZNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEE12_M_constructIPKcEEvT_S8_St20forward_iterator_tag.isra.0, @function
_ZNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEE12_M_constructIPKcEEvT_S8_St20forward_iterator_tag.isra.0:
.LFB13929:
	.cfi_startproc
	push	r12	#
	.cfi_def_cfa_offset 16
	.cfi_offset 12, -16
# /usr/include/c++/15.2.1/bits/stl_iterator_base_funcs.h:108:       return __last - __first;
	mov	rax, rdx	# _4, __end
# /usr/include/c++/15.2.1/bits/basic_string.tcc:227:       basic_string<_CharT, _Traits, _Alloc>::
	push	rbp	#
	.cfi_def_cfa_offset 24
	.cfi_offset 6, -24
# /usr/include/c++/15.2.1/bits/stl_iterator_base_funcs.h:108:       return __last - __first;
	sub	rax, rsi	# _4, __beg
# /usr/include/c++/15.2.1/bits/basic_string.tcc:227:       basic_string<_CharT, _Traits, _Alloc>::
	mov	rbp, rsi	# __beg, __beg
	push	rbx	#
	.cfi_def_cfa_offset 32
	.cfi_offset 3, -32
	mov	rbx, rdi	# this, this
	sub	rsp, 16	#,
	.cfi_def_cfa_offset 48
# /usr/include/c++/15.2.1/bits/basic_string.tcc:227:       basic_string<_CharT, _Traits, _Alloc>::
	mov	r12, QWORD PTR fs:40	# __end, MEM[(<address-space-1> long unsigned int *)40B]
	mov	QWORD PTR 8[rsp], r12	# D.173284, __end
	mov	r12, rdx	# __end, __end
# /usr/include/c++/15.2.1/bits/basic_string.tcc:231: 	size_type __dnew = static_cast<size_type>(std::distance(__beg, __end));
	mov	QWORD PTR [rsp], rax	# __dnew, _4
# /usr/include/c++/15.2.1/bits/basic_string.tcc:233: 	if (__dnew > size_type(_S_local_capacity))
	cmp	rax, 15	# _4,
	ja	.L246	#,
.L243:
# /usr/include/c++/15.2.1/bits/basic_string.tcc:253: 	this->_S_copy_chars(_M_data(), __beg, __end);
	mov	rdi, rbx	#, this
	call	[QWORD PTR _ZNKSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEE7_M_dataEv@GOTPCREL[rip]]	#
# /usr/include/c++/15.2.1/bits/basic_string.tcc:253: 	this->_S_copy_chars(_M_data(), __beg, __end);
	mov	rsi, rbp	#, __beg
	mov	rdx, r12	#, __end
	mov	rdi, rax	#, _8
	call	_ZNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEE13_S_copy_charsIPKcEEvPcT_S9_	#
# /usr/include/c++/15.2.1/bits/basic_string.tcc:257: 	_M_set_length(__dnew);
	mov	rsi, QWORD PTR [rsp]	#, __dnew
	mov	rdi, rbx	#, this
	call	[QWORD PTR _ZNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEE13_M_set_lengthEm@GOTPCREL[rip]]	#
# /usr/include/c++/15.2.1/bits/basic_string.tcc:258:       }
	mov	rax, QWORD PTR 8[rsp]	# tmp118, D.173284
	sub	rax, QWORD PTR fs:40	# tmp118, MEM[(<address-space-1> long unsigned int *)40B]
	jne	.L247	#,
	add	rsp, 16	#,
	.cfi_remember_state
	.cfi_def_cfa_offset 32
	pop	rbx	#
	.cfi_def_cfa_offset 24
	pop	rbp	#
	.cfi_def_cfa_offset 16
	pop	r12	#
	.cfi_def_cfa_offset 8
	ret	
	.p2align 4,,10
	.p2align 3
.L246:
	.cfi_restore_state
# /usr/include/c++/15.2.1/bits/basic_string.tcc:235: 	    _M_data(_M_create(__dnew, size_type(0)));
	mov	rsi, rsp	# tmp109,
	xor	edx, edx	#
	call	[QWORD PTR _ZNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEE9_M_createERmm@GOTPCREL[rip]]	#
# /usr/include/c++/15.2.1/bits/basic_string.tcc:235: 	    _M_data(_M_create(__dnew, size_type(0)));
	mov	rdi, rbx	#, this
	mov	rsi, rax	#, _6
	call	[QWORD PTR _ZNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEE7_M_dataEPc@GOTPCREL[rip]]	#
# /usr/include/c++/15.2.1/bits/basic_string.tcc:236: 	    _M_capacity(__dnew);
	mov	rsi, QWORD PTR [rsp]	#, __dnew
	mov	rdi, rbx	#, this
	call	[QWORD PTR _ZNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEE11_M_capacityEm@GOTPCREL[rip]]	#
	jmp	.L243	#
.L247:
# /usr/include/c++/15.2.1/bits/basic_string.tcc:258:       }
	call	[QWORD PTR __stack_chk_fail@GOTPCREL[rip]]	#
	.cfi_endproc
.LFE13929:
	.size	_ZNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEE12_M_constructIPKcEEvT_S8_St20forward_iterator_tag.isra.0, .-_ZNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEE12_M_constructIPKcEEvT_S8_St20forward_iterator_tag.isra.0
	.section	.rodata._ZNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEEC2IS3_EEPKcRKS3_.str1.8,"aMS",@progbits,1
	.align 8
.LC6:
	.string	"basic_string: construction from null is not valid"
	.section	.text._ZNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEEC2IS3_EEPKcRKS3_,"axG",@progbits,_ZNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEEC5IS3_EEPKcRKS3_,comdat
	.align 2
	.p2align 4
	.weak	_ZNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEEC2IS3_EEPKcRKS3_
	.type	_ZNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEEC2IS3_EEPKcRKS3_, @function
_ZNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEEC2IS3_EEPKcRKS3_:
.LFB13203:
	.cfi_startproc
	push	rbp	#
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	mov	rbp, rdi	# this, this
	push	rbx	#
	.cfi_def_cfa_offset 24
	.cfi_offset 3, -24
	mov	rbx, rsi	# __s, __s
	sub	rsp, 8	#,
	.cfi_def_cfa_offset 32
# /usr/include/c++/15.2.1/bits/basic_string.h:707:       : _M_dataplus(_M_local_data(), __a)
	call	[QWORD PTR _ZNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEE13_M_local_dataEv@GOTPCREL[rip]]	#
# /usr/include/c++/15.2.1/bits/basic_string.h:707:       : _M_dataplus(_M_local_data(), __a)
	mov	rdi, rbp	#, this
	mov	rsi, rax	#, _2
	call	_ZNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEE12_Alloc_hiderC2EPcRKS3_.isra.0	#
# /usr/include/c++/15.2.1/bits/basic_string.h:710: 	if (__s == 0)
	test	rbx, rbx	# __s
	je	.L251	#,
# /usr/include/c++/15.2.1/bits/basic_string.h:713: 	const _CharT* __end = __s + traits_type::length(__s);
	mov	rdi, rbx	#, __s
	call	_ZNSt11char_traitsIcE6lengthEPKc	#
# /usr/include/c++/15.2.1/bits/basic_string.h:714: 	_M_construct(__s, __end, forward_iterator_tag());
	mov	rsi, rbx	#, __s
	mov	rdi, rbp	#, this
# /usr/include/c++/15.2.1/bits/basic_string.h:713: 	const _CharT* __end = __s + traits_type::length(__s);
	lea	rdx, [rbx+rax]	# __end_11,
# /usr/include/c++/15.2.1/bits/basic_string.h:714: 	_M_construct(__s, __end, forward_iterator_tag());
	call	_ZNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEE12_M_constructIPKcEEvT_S8_St20forward_iterator_tag.isra.0	#
# /usr/include/c++/15.2.1/bits/basic_string.h:715:       }
	add	rsp, 8	#,
	.cfi_remember_state
	.cfi_def_cfa_offset 24
	pop	rbx	#
	.cfi_def_cfa_offset 16
	pop	rbp	#
	.cfi_def_cfa_offset 8
	ret	
.L251:
	.cfi_restore_state
# /usr/include/c++/15.2.1/bits/basic_string.h:711: 	  std::__throw_logic_error(__N("basic_string: "
	lea	rdi, .LC6[rip]	#,
	call	[QWORD PTR _ZSt19__throw_logic_errorPKc@GOTPCREL[rip]]	#
	.cfi_endproc
.LFE13203:
	.size	_ZNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEEC2IS3_EEPKcRKS3_, .-_ZNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEEC2IS3_EEPKcRKS3_
	.weak	_ZNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEEC1IS3_EEPKcRKS3_
	.set	_ZNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEEC1IS3_EEPKcRKS3_,_ZNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEEC2IS3_EEPKcRKS3_
	.section	.rodata.str1.8,"aMS",@progbits,1
	.align 8
.LC7:
	.base64	"0JDQstGC0L7RgdC+0YXRgNCw0L3QtdC90LjQtSDQvdCw0LnQtNC10L3QvgA="
	.align 8
.LC8:
	.base64	"0JDQstGC0L7RgdC+0YXRgNCw0L3QtdC90LjRjyDQvdC10YIgKNGB0L3QsNGH0LDQu9CwINC/0L7QuNCz0YDQsNC50YLQtSkA"
	.align 8
.LC9:
	.base64	"RW50ZXIg4oCUINGB0L7RhdGA0LDQvdC40YLRjCwgRXNjIOKAlCDQvtGC0LzQtdC90LAA"
	.align 8
.LC10:
	.base64	"0JrQu9C40LrQvdC40YLQtSDQtNC70Y8g0LLQstC+0LTQsAA="
	.section	.rodata.str1.1,"aMS",@progbits,1
.LC11:
	.base64	"0KHQvtGF0YDQsNC90LXQvdC40Y8A"
.LC12:
	.string	"_"
.LC13:
	.string	"%zu/%d"
.LC14:
	.base64	"RXNjIOKAlCDQt9Cw0LrRgNGL0YLRjAA="
	.section	.text.unlikely,"ax",@progbits
	.align 2
.LCOLDB15:
	.text
.LHOTB15:
	.align 2
	.p2align 4
	.globl	_ZN10SavesScene6renderEP12SDL_Renderer
	.type	_ZN10SavesScene6renderEP12SDL_Renderer, @function
_ZN10SavesScene6renderEP12SDL_Renderer:
.LFB12874:
	.cfi_startproc
	.cfi_personality 0x9b,DW.ref.__gxx_personality_v0
	.cfi_lsda 0x1b,.LLSDA12874
	push	rbp	#
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	mov	rbp, rsp	#,
	.cfi_def_cfa_register 6
	push	r15	#
	push	r14	#
	.cfi_offset 15, -24
	.cfi_offset 14, -32
# saves_scene.cpp:302:     drawText(renderer, Config::getFont(), "Сохранения", 0, TITLE_Y,
	lea	r15, -128[rbp]	# tmp243,
# saves_scene.cpp:298: void SavesScene::render(SDL_Renderer* renderer) {
	push	r13	#
	.cfi_offset 13, -40
# saves_scene.cpp:302:     drawText(renderer, Config::getFont(), "Сохранения", 0, TITLE_Y,
	lea	r13, -176[rbp]	# tmp241,
# saves_scene.cpp:298: void SavesScene::render(SDL_Renderer* renderer) {
	push	r12	#
	.cfi_offset 12, -48
	mov	r12, rdi	# this, this
	push	rbx	#
	sub	rsp, 184	#,
	.cfi_offset 3, -56
# saves_scene.cpp:298: void SavesScene::render(SDL_Renderer* renderer) {
	mov	rbx, QWORD PTR fs:40	# renderer, MEM[(<address-space-1> long unsigned int *)40B]
	mov	QWORD PTR -56[rbp], rbx	# D.173322, renderer
	mov	rbx, rsi	# renderer, renderer
# saves_scene.cpp:299:     drawForestBackground(renderer, Config::getBrightness());
	call	_ZN6Config13getBrightnessEv	#
# saves_scene.cpp:299:     drawForestBackground(renderer, Config::getBrightness());
	mov	rdi, rbx	#, renderer
.LEHB2:
	call	[QWORD PTR _Z20drawForestBackgroundP12SDL_Rendererf@GOTPCREL[rip]]	#
# saves_scene.cpp:300:     drawUIOverlay(renderer, OVERLAY_ALPHA);
	mov	esi, 80	#,
	mov	rdi, rbx	#, renderer
	call	[QWORD PTR _Z13drawUIOverlayP12SDL_Rendereri@GOTPCREL[rip]]	#
# saves_scene.cpp:302:     drawText(renderer, Config::getFont(), "Сохранения", 0, TITLE_Y,
	call	_ZN6Config12getTitleFontEv	#
# saves_scene.cpp:302:     drawText(renderer, Config::getFont(), "Сохранения", 0, TITLE_Y,
	mov	rdx, r13	#, tmp241
	mov	rdi, r15	#, tmp243
	lea	rsi, .LC11[rip]	#,
# saves_scene.cpp:302:     drawText(renderer, Config::getFont(), "Сохранения", 0, TITLE_Y,
	mov	r14, rax	# _2, _2
# saves_scene.cpp:302:     drawText(renderer, Config::getFont(), "Сохранения", 0, TITLE_Y,
	mov	QWORD PTR -200[rbp], r15	# %sfp, tmp243
	call	_ZNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEEC1IS3_EEPKcRKS3_	#
.LEHE2:
# saves_scene.cpp:302:     drawText(renderer, Config::getFont(), "Сохранения", 0, TITLE_Y,
	call	_ZN6Config7getFontEv	#
# saves_scene.cpp:302:     drawText(renderer, Config::getFont(), "Сохранения", 0, TITLE_Y,
	push	r14	# _2
	mov	r9d, -6887681	#,
	xor	ecx, ecx	#
	push	1	#
	mov	r8d, 80	#,
	mov	rdx, r15	#, tmp243
	mov	rsi, rax	#, _3
	mov	rdi, rbx	#, renderer
.LEHB3:
	.cfi_escape 0x2e,0x10
	call	[QWORD PTR _Z8drawTextP12SDL_RendererP8TTF_FontRKNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEEEii9SDL_ColorbS2_@GOTPCREL[rip]]	#
.LEHE3:
	pop	rax	#
	pop	rdx	#
# saves_scene.cpp:302:     drawText(renderer, Config::getFont(), "Сохранения", 0, TITLE_Y,
	mov	rdi, r15	#, tmp243
	call	[QWORD PTR _ZNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEED1Ev@GOTPCREL[rip]]	#
# saves_scene.cpp:306:     const char* autoMsg = SaveManager::get().hasAutosaveFile()
	call	_ZN11SaveManager3getEv	#
# saves_scene.cpp:306:     const char* autoMsg = SaveManager::get().hasAutosaveFile()
	mov	rdi, rax	#, _4
.LEHB4:
	call	[QWORD PTR _ZNK11SaveManager15hasAutosaveFileEv@GOTPCREL[rip]]	#
# saves_scene.cpp:308:                               : "Автосохранения нет (сначала поиграйте)";
	lea	rsi, .LC8[rip]	# autoMsg,
# saves_scene.cpp:309:     drawText(renderer, Config::getFont(), autoMsg, 0, MESSAGE_Y,
	mov	rdx, r13	#, tmp241
	mov	rdi, r15	#, tmp243
# saves_scene.cpp:308:                               : "Автосохранения нет (сначала поиграйте)";
	test	al, al	# _65
	lea	rax, .LC7[rip]	# tmp260,
	cmovne	rsi, rax	# autoMsg,, autoMsg, tmp260
# saves_scene.cpp:309:     drawText(renderer, Config::getFont(), autoMsg, 0, MESSAGE_Y,
	call	_ZNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEEC1IS3_EEPKcRKS3_	#
.LEHE4:
# saves_scene.cpp:309:     drawText(renderer, Config::getFont(), autoMsg, 0, MESSAGE_Y,
	call	_ZN6Config7getFontEv	#
# saves_scene.cpp:309:     drawText(renderer, Config::getFont(), autoMsg, 0, MESSAGE_Y,
	push	0	#
	mov	r9d, -4924236	#,
	xor	ecx, ecx	#
	push	1	#
	mov	r8d, 140	#,
	mov	rdx, r15	#, tmp243
	mov	rsi, rax	#, _5
	mov	rdi, rbx	#, renderer
.LEHB5:
	call	[QWORD PTR _Z8drawTextP12SDL_RendererP8TTF_FontRKNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEEEii9SDL_ColorbS2_@GOTPCREL[rip]]	#
.LEHE5:
	pop	r11	#
	pop	r14	#
# saves_scene.cpp:309:     drawText(renderer, Config::getFont(), autoMsg, 0, MESSAGE_Y,
	mov	rdi, r15	#, tmp243
	call	[QWORD PTR _ZNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEED1Ev@GOTPCREL[rip]]	#
# saves_scene.cpp:312:     drawButton(renderer, Config::getFont(), backBtn);
	call	_ZN6Config7getFontEv	#
# saves_scene.cpp:312:     drawButton(renderer, Config::getFont(), backBtn);
	lea	rdx, 24[r12]	# _6,
# saves_scene.cpp:312:     drawButton(renderer, Config::getFont(), backBtn);
	xor	ecx, ecx	#
	mov	rdi, rbx	#, renderer
	mov	rsi, rax	#, _7
.LEHB6:
	call	[QWORD PTR _Z10drawButtonP12SDL_RendererP8TTF_FontR6ButtonP12SoundManager@GOTPCREL[rip]]	#
# saves_scene.cpp:314:     for (auto& btn : slotButtons)
	lea	rdi, 80[r12]	#,
	call	_ZNSt6vectorI6ButtonSaIS0_EE5beginEv	#
# saves_scene.cpp:314:     for (auto& btn : slotButtons)
	lea	rdi, 80[r12]	#,
# saves_scene.cpp:314:     for (auto& btn : slotButtons)
	mov	r14, rax	# __for_begin,
# saves_scene.cpp:314:     for (auto& btn : slotButtons)
	call	_ZNSt6vectorI6ButtonSaIS0_EE3endEv	#
	mov	r15, rax	# SR.918,
# saves_scene.cpp:314:     for (auto& btn : slotButtons)
	cmp	r14, rax	# __for_begin, SR.918
	je	.L254	#,
	.p2align 4
	.p2align 3
.L255:
# saves_scene.cpp:315:         drawButton(renderer, Config::getFont(), btn);
	call	_ZN6Config7getFontEv	#
# saves_scene.cpp:315:         drawButton(renderer, Config::getFont(), btn);
	mov	rdx, r14	#, ivtmp.930
# saves_scene.cpp:314:     for (auto& btn : slotButtons)
	add	r14, 56	# ivtmp.930,
# saves_scene.cpp:315:         drawButton(renderer, Config::getFont(), btn);
	xor	ecx, ecx	#
	mov	rsi, rax	#, _8
	mov	rdi, rbx	#, renderer
	call	[QWORD PTR _Z10drawButtonP12SDL_RendererP8TTF_FontR6ButtonP12SoundManager@GOTPCREL[rip]]	#
# saves_scene.cpp:314:     for (auto& btn : slotButtons)
	cmp	r15, r14	# SR.918, ivtmp.930
	jne	.L255	#,
.L254:
# saves_scene.cpp:318:     if (isInputVisible) {
	cmp	BYTE PTR 148[r12], 0	# this_75(D)->isInputVisible,
	jne	.L287	#,
# saves_scene.cpp:355:     if (isMenuVisible) {
	cmp	BYTE PTR 200[r12], 0	# this_75(D)->isMenuVisible,
	jne	.L288	#,
.L252:
# saves_scene.cpp:368: }
	mov	rax, QWORD PTR -56[rbp]	# tmp304, D.173322
	sub	rax, QWORD PTR fs:40	# tmp304, MEM[(<address-space-1> long unsigned int *)40B]
	jne	.L289	#,
	lea	rsp, -40[rbp]	#,
	pop	rbx	#
	pop	r12	#
	pop	r13	#
	pop	r14	#
	pop	r15	#
	pop	rbp	#
	.cfi_remember_state
	.cfi_def_cfa 7, 8
	ret	
	.p2align 4,,10
	.p2align 3
.L287:
	.cfi_restore_state
# saves_scene.cpp:319:         SDL_SetRenderDrawBlendMode(renderer, SDL_BLENDMODE_BLEND);
	mov	esi, 1	#,
	mov	rdi, rbx	#, renderer
# saves_scene.cpp:329:         std::string displayText = inputText;
	lea	r14, 152[r12]	# _13,
# saves_scene.cpp:319:         SDL_SetRenderDrawBlendMode(renderer, SDL_BLENDMODE_BLEND);
	call	[QWORD PTR SDL_SetRenderDrawBlendMode@GOTPCREL[rip]]	#
# saves_scene.cpp:320:         SDL_SetRenderDrawColor(renderer, 0, 0, 0, 180);
	xor	ecx, ecx	#
	xor	edx, edx	#
	mov	r8d, 180	#,
	xor	esi, esi	#
	mov	rdi, rbx	#, renderer
# saves_scene.cpp:329:         std::string displayText = inputText;
	lea	r15, -160[rbp]	# tmp242,
# saves_scene.cpp:320:         SDL_SetRenderDrawColor(renderer, 0, 0, 0, 180);
	call	[QWORD PTR SDL_SetRenderDrawColor@GOTPCREL[rip]]	#
# saves_scene.cpp:321:         SDL_Rect overlay = {0, 0, Config::getWindowWidth(), Config::getWindowHeight()};
	pxor	xmm0, xmm0	# tmp266
	movaps	XMMWORD PTR -176[rbp], xmm0	# MEM[(struct SDL_Rect *)_68], tmp266
# saves_scene.cpp:321:         SDL_Rect overlay = {0, 0, Config::getWindowWidth(), Config::getWindowHeight()};
	call	_ZN6Config14getWindowWidthEv	#
# saves_scene.cpp:321:         SDL_Rect overlay = {0, 0, Config::getWindowWidth(), Config::getWindowHeight()};
	mov	DWORD PTR -168[rbp], eax	# MEM[(struct SDL_Rect *)_68].w, _10
# saves_scene.cpp:321:         SDL_Rect overlay = {0, 0, Config::getWindowWidth(), Config::getWindowHeight()};
	call	_ZN6Config15getWindowHeightEv	#
# saves_scene.cpp:322:         SDL_RenderFillRect(renderer, &overlay);
	mov	rsi, r13	#, tmp241
	mov	rdi, rbx	#, renderer
# saves_scene.cpp:321:         SDL_Rect overlay = {0, 0, Config::getWindowWidth(), Config::getWindowHeight()};
	mov	DWORD PTR -164[rbp], eax	# MEM[(struct SDL_Rect *)_68].h, _11
# saves_scene.cpp:322:         SDL_RenderFillRect(renderer, &overlay);
	call	[QWORD PTR SDL_RenderFillRect@GOTPCREL[rip]]	#
# saves_scene.cpp:324:         SDL_SetRenderDrawColor(renderer, 50, 100, 200, 255);
	mov	r8d, 255	#,
	mov	ecx, 200	#,
	mov	rdi, rbx	#, renderer
	mov	edx, 100	#,
	mov	esi, 50	#,
	call	[QWORD PTR SDL_SetRenderDrawColor@GOTPCREL[rip]]	#
# saves_scene.cpp:325:         SDL_RenderDrawRect(renderer, &inputRect);
	lea	rsi, 184[r12]	#,
	mov	rdi, rbx	#, renderer
	call	[QWORD PTR SDL_RenderDrawRect@GOTPCREL[rip]]	#
# saves_scene.cpp:326:         SDL_SetRenderDrawColor(renderer, 25, 50, 100, 200);
	mov	r8d, 200	#,
	mov	ecx, 100	#,
	mov	rdi, rbx	#, renderer
	mov	edx, 50	#,
	mov	esi, 25	#,
	call	[QWORD PTR SDL_SetRenderDrawColor@GOTPCREL[rip]]	#
# saves_scene.cpp:327:         SDL_RenderFillRect(renderer, &inputRect);
	lea	rsi, 184[r12]	#,
	mov	rdi, rbx	#, renderer
	call	[QWORD PTR SDL_RenderFillRect@GOTPCREL[rip]]	#
# saves_scene.cpp:329:         std::string displayText = inputText;
	mov	rsi, r14	#, _13
	mov	rdi, r15	#, tmp242
	call	[QWORD PTR _ZNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEEC1ERKS4_@GOTPCREL[rip]]	#
.LEHE6:
# saves_scene.cpp:330:         if (isInputFocused && (SDL_GetTicks() / 500 % 2 == 0))
	cmp	BYTE PTR 149[r12], 0	# this_75(D)->isInputFocused,
	jne	.L257	#,
.L259:
# saves_scene.cpp:333:         drawText(renderer, Config::getFont(), displayText,
	call	_ZN6Config7getFontEv	#
	mov	edx, DWORD PTR 188[r12]	# this_75(D)->inputRect.y, this_75(D)->inputRect.y
	mov	ecx, DWORD PTR 184[r12]	# tmp307, this_75(D)->inputRect.x
# saves_scene.cpp:333:         drawText(renderer, Config::getFont(), displayText,
	mov	rdi, rbx	#, renderer
	push	0	#
	mov	r9d, -1	#,
	mov	rsi, rax	#, _21
	lea	r8d, 13[rdx]	#,
	push	0	#
# saves_scene.cpp:333:         drawText(renderer, Config::getFont(), displayText,
	add	ecx, 10	# _20,
# saves_scene.cpp:333:         drawText(renderer, Config::getFont(), displayText,
	mov	rdx, r15	#, tmp242
.LEHB7:
	call	[QWORD PTR _Z8drawTextP12SDL_RendererP8TTF_FontRKNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEEEii9SDL_ColorbS2_@GOTPCREL[rip]]	#
	pop	r9	#
# saves_scene.cpp:339:         std::snprintf(counter, sizeof(counter), "%zu/%d",
	mov	rdi, r14	#, _13
# saves_scene.cpp:333:         drawText(renderer, Config::getFont(), displayText,
	pop	r10	#
# saves_scene.cpp:339:         std::snprintf(counter, sizeof(counter), "%zu/%d",
	call	_ZL14countUTF8CharsRKNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEEE	#
# saves_scene.cpp:339:         std::snprintf(counter, sizeof(counter), "%zu/%d",
	lea	rdx, .LC13[rip]	#,
	mov	esi, 32	#,
	lea	rdi, -96[rbp]	#,
	mov	rcx, rax	#, _22
	mov	r8d, 16	#,
	xor	eax, eax	#
	call	[QWORD PTR snprintf@GOTPCREL[rip]]	#
# saves_scene.cpp:341:         drawText(renderer, Config::getFont(), counter,
	mov	rdi, QWORD PTR -200[rbp]	#, %sfp
	lea	rsi, -96[rbp]	#,
# saves_scene.cpp:341:         drawText(renderer, Config::getFont(), counter,
	mov	eax, DWORD PTR 188[r12]	# tmp309, this_75(D)->inputRect.y
	add	eax, 13	# _24,
	mov	DWORD PTR -204[rbp], eax	# %sfp, _24
# saves_scene.cpp:342:                  inputRect.x + inputRect.w - 55,
	mov	eax, DWORD PTR 192[r12]	# this_75(D)->inputRect.w, this_75(D)->inputRect.w
	add	eax, DWORD PTR 184[r12]	# _27, this_75(D)->inputRect.x
# saves_scene.cpp:341:         drawText(renderer, Config::getFont(), counter,
	sub	eax, 55	# _28,
	mov	DWORD PTR -208[rbp], eax	# %sfp, _28
# saves_scene.cpp:341:         drawText(renderer, Config::getFont(), counter,
	lea	rax, -177[rbp]	# tmp240,
	mov	rdx, rax	#, tmp240
	mov	QWORD PTR -216[rbp], rax	# %sfp, tmp240
	.cfi_escape 0x2e,0
	call	_ZNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEEC1IS3_EEPKcRKS3_	#
.LEHE7:
# saves_scene.cpp:341:         drawText(renderer, Config::getFont(), counter,
	call	_ZN6Config7getFontEv	#
# saves_scene.cpp:341:         drawText(renderer, Config::getFont(), counter,
	push	0	#
	mov	ecx, DWORD PTR -208[rbp]	#, %sfp
	mov	rdi, rbx	#, renderer
	mov	r14, QWORD PTR -200[rbp]	# tmp243, %sfp
	push	0	#
	mov	r9d, -4934476	#,
	mov	rsi, rax	#, _29
	mov	r8d, DWORD PTR -204[rbp]	#, %sfp
	mov	rdx, r14	#, tmp243
.LEHB8:
	.cfi_escape 0x2e,0x10
	call	[QWORD PTR _Z8drawTextP12SDL_RendererP8TTF_FontRKNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEEEii9SDL_ColorbS2_@GOTPCREL[rip]]	#
.LEHE8:
	pop	rdi	#
# saves_scene.cpp:341:         drawText(renderer, Config::getFont(), counter,
	mov	rdi, r14	#, tmp243
# saves_scene.cpp:341:         drawText(renderer, Config::getFont(), counter,
	pop	r8	#
# saves_scene.cpp:341:         drawText(renderer, Config::getFont(), counter,
	mov	QWORD PTR -200[rbp], r14	# %sfp, tmp243
	call	[QWORD PTR _ZNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEED1Ev@GOTPCREL[rip]]	#
# saves_scene.cpp:346:         const char* hint = isInputFocused
	lea	rax, .LC9[rip]	# tmp265,
	lea	rsi, .LC10[rip]	# hint,
	cmp	BYTE PTR 149[r12], 0	# this_75(D)->isInputFocused,
	cmovne	rsi, rax	# hint,, hint, tmp265
# saves_scene.cpp:349:         drawText(renderer, Config::getFont(), hint,
	mov	rdx, QWORD PTR -216[rbp]	#, %sfp
# saves_scene.cpp:349:         drawText(renderer, Config::getFont(), hint,
	mov	eax, DWORD PTR 188[r12]	# tmp312, this_75(D)->inputRect.y
# saves_scene.cpp:349:         drawText(renderer, Config::getFont(), hint,
	mov	rdi, QWORD PTR -200[rbp]	#, %sfp
# saves_scene.cpp:349:         drawText(renderer, Config::getFont(), hint,
	lea	r14d, 70[rax]	# _32,
.LEHB9:
	.cfi_escape 0x2e,0
# saves_scene.cpp:349:         drawText(renderer, Config::getFont(), hint,
	call	_ZNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEEC1IS3_EEPKcRKS3_	#
.LEHE9:
# saves_scene.cpp:349:         drawText(renderer, Config::getFont(), hint,
	call	_ZN6Config7getFontEv	#
# saves_scene.cpp:349:         drawText(renderer, Config::getFont(), hint,
	mov	r8d, r14d	#, _32
	push	0	#
	mov	r9d, -3618616	#,
	mov	r14, QWORD PTR -200[rbp]	# tmp243, %sfp
	push	1	#
	xor	ecx, ecx	#
	mov	rsi, rax	#, _33
	mov	rdi, rbx	#, renderer
	mov	rdx, r14	#, tmp243
.LEHB10:
	.cfi_escape 0x2e,0x10
	call	[QWORD PTR _Z8drawTextP12SDL_RendererP8TTF_FontRKNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEEEii9SDL_ColorbS2_@GOTPCREL[rip]]	#
.LEHE10:
	pop	rcx	#
# saves_scene.cpp:349:         drawText(renderer, Config::getFont(), hint,
	mov	rdi, r14	#, tmp243
# saves_scene.cpp:349:         drawText(renderer, Config::getFont(), hint,
	pop	rsi	#
# saves_scene.cpp:349:         drawText(renderer, Config::getFont(), hint,
	call	[QWORD PTR _ZNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEED1Ev@GOTPCREL[rip]]	#
# saves_scene.cpp:352:     }
	mov	rdi, r15	#, tmp242
	call	[QWORD PTR _ZNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEED1Ev@GOTPCREL[rip]]	#
# saves_scene.cpp:355:     if (isMenuVisible) {
	cmp	BYTE PTR 200[r12], 0	# this_75(D)->isMenuVisible,
	je	.L252	#,
.L288:
# saves_scene.cpp:356:         SDL_SetRenderDrawBlendMode(renderer, SDL_BLENDMODE_BLEND);
	mov	esi, 1	#,
	mov	rdi, rbx	#, renderer
.LEHB11:
	call	[QWORD PTR SDL_SetRenderDrawBlendMode@GOTPCREL[rip]]	#
# saves_scene.cpp:357:         SDL_SetRenderDrawColor(renderer, 0, 0, 0, 180);
	mov	r8d, 180	#,
	xor	ecx, ecx	#
	xor	edx, edx	#
	xor	esi, esi	#
	mov	rdi, rbx	#, renderer
	call	[QWORD PTR SDL_SetRenderDrawColor@GOTPCREL[rip]]	#
# saves_scene.cpp:358:         SDL_Rect overlay = {0, 0, Config::getWindowWidth(), Config::getWindowHeight()};
	pxor	xmm0, xmm0	# tmp267
	movaps	XMMWORD PTR -176[rbp], xmm0	# MEM[(struct SDL_Rect *)_68], tmp267
# saves_scene.cpp:358:         SDL_Rect overlay = {0, 0, Config::getWindowWidth(), Config::getWindowHeight()};
	call	_ZN6Config14getWindowWidthEv	#
# saves_scene.cpp:358:         SDL_Rect overlay = {0, 0, Config::getWindowWidth(), Config::getWindowHeight()};
	mov	DWORD PTR -168[rbp], eax	# MEM[(struct SDL_Rect *)_68].w, _35
# saves_scene.cpp:358:         SDL_Rect overlay = {0, 0, Config::getWindowWidth(), Config::getWindowHeight()};
	call	_ZN6Config15getWindowHeightEv	#
# saves_scene.cpp:359:         SDL_RenderFillRect(renderer, &overlay);
	mov	rsi, r13	#, tmp241
	mov	rdi, rbx	#, renderer
# saves_scene.cpp:358:         SDL_Rect overlay = {0, 0, Config::getWindowWidth(), Config::getWindowHeight()};
	mov	DWORD PTR -164[rbp], eax	# MEM[(struct SDL_Rect *)_68].h, _36
# saves_scene.cpp:359:         SDL_RenderFillRect(renderer, &overlay);
	call	[QWORD PTR SDL_RenderFillRect@GOTPCREL[rip]]	#
# saves_scene.cpp:361:         for (auto& btn : menuButtons)
	lea	rdi, 208[r12]	#,
	call	_ZNSt6vectorI6ButtonSaIS0_EE5beginEv	#
# saves_scene.cpp:361:         for (auto& btn : menuButtons)
	lea	rdi, 208[r12]	#,
# saves_scene.cpp:361:         for (auto& btn : menuButtons)
	mov	r12, rax	# __for_begin,
# saves_scene.cpp:361:         for (auto& btn : menuButtons)
	call	_ZNSt6vectorI6ButtonSaIS0_EE3endEv	#
	mov	r13, rax	# SR.919,
# saves_scene.cpp:361:         for (auto& btn : menuButtons)
	cmp	r12, rax	# __for_begin, SR.919
	je	.L262	#,
	.p2align 4
	.p2align 3
.L263:
# saves_scene.cpp:362:             drawButton(renderer, Config::getFont(), btn);
	call	_ZN6Config7getFontEv	#
# saves_scene.cpp:362:             drawButton(renderer, Config::getFont(), btn);
	mov	rdx, r12	#, ivtmp.925
# saves_scene.cpp:361:         for (auto& btn : menuButtons)
	add	r12, 56	# ivtmp.925,
# saves_scene.cpp:362:             drawButton(renderer, Config::getFont(), btn);
	xor	ecx, ecx	#
	mov	rsi, rax	#, _37
	mov	rdi, rbx	#, renderer
	call	[QWORD PTR _Z10drawButtonP12SDL_RendererP8TTF_FontR6ButtonP12SoundManager@GOTPCREL[rip]]	#
# saves_scene.cpp:361:         for (auto& btn : menuButtons)
	cmp	r13, r12	# SR.919, ivtmp.925
	jne	.L263	#,
.L262:
# saves_scene.cpp:365:                  0, Config::getWindowHeight() - 50,
	call	_ZN6Config15getWindowHeightEv	#
# saves_scene.cpp:364:         drawText(renderer, Config::getFont(), "Esc — закрыть",
	mov	r15, QWORD PTR -200[rbp]	# tmp243, %sfp
	lea	rdx, -177[rbp]	# tmp214,
	lea	rsi, .LC14[rip]	#,
# saves_scene.cpp:365:                  0, Config::getWindowHeight() - 50,
	mov	r12d, eax	# _38,
# saves_scene.cpp:364:         drawText(renderer, Config::getFont(), "Esc — закрыть",
	mov	rdi, r15	#, tmp243
	call	_ZNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEEC1IS3_EEPKcRKS3_	#
.LEHE11:
# saves_scene.cpp:364:         drawText(renderer, Config::getFont(), "Esc — закрыть",
	call	_ZN6Config7getFontEv	#
# saves_scene.cpp:364:         drawText(renderer, Config::getFont(), "Esc — закрыть",
	push	0	#
	mov	r9d, -3618616	#,
	xor	ecx, ecx	#
	push	1	#
	lea	r8d, -50[r12]	#,
	mov	rdx, r15	#, tmp243
	mov	rsi, rax	#, _40
	mov	rdi, rbx	#, renderer
.LEHB12:
	call	[QWORD PTR _Z8drawTextP12SDL_RendererP8TTF_FontRKNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEEEii9SDL_ColorbS2_@GOTPCREL[rip]]	#
.LEHE12:
	pop	rax	#
# saves_scene.cpp:364:         drawText(renderer, Config::getFont(), "Esc — закрыть",
	mov	rdi, r15	#, tmp243
# saves_scene.cpp:364:         drawText(renderer, Config::getFont(), "Esc — закрыть",
	pop	rdx	#
# saves_scene.cpp:364:         drawText(renderer, Config::getFont(), "Esc — закрыть",
	call	[QWORD PTR _ZNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEED1Ev@GOTPCREL[rip]]	#
# saves_scene.cpp:368: }
	jmp	.L252	#
	.p2align 4,,10
	.p2align 3
.L257:
.LEHB13:
	.cfi_escape 0x2e,0
# saves_scene.cpp:330:         if (isInputFocused && (SDL_GetTicks() / 500 % 2 == 0))
	call	[QWORD PTR SDL_GetTicks@GOTPCREL[rip]]	#
# saves_scene.cpp:330:         if (isInputFocused && (SDL_GetTicks() / 500 % 2 == 0))
	mov	eax, eax	# _93, _93
	imul	rax, rax, 274877907	# tmp191, _93,
# saves_scene.cpp:330:         if (isInputFocused && (SDL_GetTicks() / 500 % 2 == 0))
	bt	rax, 37	# tmp191,
	jc	.L259	#,
# saves_scene.cpp:331:             displayText += "_";
	lea	rsi, .LC12[rip]	#,
	mov	rdi, r15	#, tmp242
	call	[QWORD PTR _ZNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEEpLEPKc@GOTPCREL[rip]]	#
.LEHE13:
	jmp	.L259	#
.L289:
# saves_scene.cpp:368: }
	call	[QWORD PTR __stack_chk_fail@GOTPCREL[rip]]	#
.L279:
# saves_scene.cpp:352:     }
	mov	rbx, rax	# tmp227, tmp298
	jmp	.L269	#
.L280:
# saves_scene.cpp:341:         drawText(renderer, Config::getFont(), counter,
	mov	rbx, rax	# tmp296,
	jmp	.L268	#
.L281:
# saves_scene.cpp:349:         drawText(renderer, Config::getFont(), hint,
	mov	rbx, rax	# tmp297,
	jmp	.L270	#
.L282:
# saves_scene.cpp:364:         drawText(renderer, Config::getFont(), "Esc — закрыть",
	mov	rbx, rax	# tmp299,
	jmp	.L272	#
.L278:
# saves_scene.cpp:309:     drawText(renderer, Config::getFont(), autoMsg, 0, MESSAGE_Y,
	mov	rbx, rax	# tmp295,
	jmp	.L266	#
.L277:
# saves_scene.cpp:302:     drawText(renderer, Config::getFont(), "Сохранения", 0, TITLE_Y,
	mov	rbx, rax	# tmp294,
	jmp	.L264	#
	.section	.gcc_except_table,"a",@progbits
.LLSDA12874:
	.byte	0xff
	.byte	0xff
	.byte	0x1
	.uleb128 .LLSDACSE12874-.LLSDACSB12874
.LLSDACSB12874:
	.uleb128 .LEHB2-.LFB12874
	.uleb128 .LEHE2-.LEHB2
	.uleb128 0
	.uleb128 0
	.uleb128 .LEHB3-.LFB12874
	.uleb128 .LEHE3-.LEHB3
	.uleb128 .L277-.LFB12874
	.uleb128 0
	.uleb128 .LEHB4-.LFB12874
	.uleb128 .LEHE4-.LEHB4
	.uleb128 0
	.uleb128 0
	.uleb128 .LEHB5-.LFB12874
	.uleb128 .LEHE5-.LEHB5
	.uleb128 .L278-.LFB12874
	.uleb128 0
	.uleb128 .LEHB6-.LFB12874
	.uleb128 .LEHE6-.LEHB6
	.uleb128 0
	.uleb128 0
	.uleb128 .LEHB7-.LFB12874
	.uleb128 .LEHE7-.LEHB7
	.uleb128 .L279-.LFB12874
	.uleb128 0
	.uleb128 .LEHB8-.LFB12874
	.uleb128 .LEHE8-.LEHB8
	.uleb128 .L280-.LFB12874
	.uleb128 0
	.uleb128 .LEHB9-.LFB12874
	.uleb128 .LEHE9-.LEHB9
	.uleb128 .L279-.LFB12874
	.uleb128 0
	.uleb128 .LEHB10-.LFB12874
	.uleb128 .LEHE10-.LEHB10
	.uleb128 .L281-.LFB12874
	.uleb128 0
	.uleb128 .LEHB11-.LFB12874
	.uleb128 .LEHE11-.LEHB11
	.uleb128 0
	.uleb128 0
	.uleb128 .LEHB12-.LFB12874
	.uleb128 .LEHE12-.LEHB12
	.uleb128 .L282-.LFB12874
	.uleb128 0
	.uleb128 .LEHB13-.LFB12874
	.uleb128 .LEHE13-.LEHB13
	.uleb128 .L279-.LFB12874
	.uleb128 0
.LLSDACSE12874:
	.text
	.cfi_endproc
	.section	.text.unlikely
	.cfi_startproc
	.cfi_personality 0x9b,DW.ref.__gxx_personality_v0
	.cfi_lsda 0x1b,.LLSDAC12874
	.type	_ZN10SavesScene6renderEP12SDL_Renderer.cold, @function
_ZN10SavesScene6renderEP12SDL_Renderer.cold:
.LFSB12874:
.L268:
	.cfi_def_cfa 6, 16
	.cfi_offset 3, -56
	.cfi_offset 6, -16
	.cfi_offset 12, -48
	.cfi_offset 13, -40
	.cfi_offset 14, -32
	.cfi_offset 15, -24
# saves_scene.cpp:341:         drawText(renderer, Config::getFont(), counter,
	mov	rdi, QWORD PTR -200[rbp]	#, %sfp
	call	[QWORD PTR _ZNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEED1Ev@GOTPCREL[rip]]	#
.L269:
# saves_scene.cpp:352:     }
	mov	rdi, r15	#, tmp242
	call	[QWORD PTR _ZNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEED1Ev@GOTPCREL[rip]]	#
	mov	rax, QWORD PTR -56[rbp]	# tmp302, D.173322
	sub	rax, QWORD PTR fs:40	# tmp302, MEM[(<address-space-1> long unsigned int *)40B]
	jne	.L290	#,
	mov	rdi, rbx	#, tmp227
.LEHB14:
	call	[QWORD PTR _Unwind_Resume@GOTPCREL[rip]]	#
.L290:
	call	[QWORD PTR __stack_chk_fail@GOTPCREL[rip]]	#
.L270:
# saves_scene.cpp:349:         drawText(renderer, Config::getFont(), hint,
	mov	rdi, QWORD PTR -200[rbp]	#, %sfp
	call	[QWORD PTR _ZNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEED1Ev@GOTPCREL[rip]]	#
	jmp	.L269	#
.L272:
# saves_scene.cpp:364:         drawText(renderer, Config::getFont(), "Esc — закрыть",
	mov	rdi, QWORD PTR -200[rbp]	#, %sfp
	call	[QWORD PTR _ZNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEED1Ev@GOTPCREL[rip]]	#
	mov	rax, QWORD PTR -56[rbp]	# tmp303, D.173322
	sub	rax, QWORD PTR fs:40	# tmp303, MEM[(<address-space-1> long unsigned int *)40B]
	jne	.L291	#,
	mov	rdi, rbx	#, tmp299
	call	[QWORD PTR _Unwind_Resume@GOTPCREL[rip]]	#
.L266:
# saves_scene.cpp:309:     drawText(renderer, Config::getFont(), autoMsg, 0, MESSAGE_Y,
	mov	rdi, QWORD PTR -200[rbp]	#, %sfp
	call	[QWORD PTR _ZNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEED1Ev@GOTPCREL[rip]]	#
	mov	rax, QWORD PTR -56[rbp]	# tmp301, D.173322
	sub	rax, QWORD PTR fs:40	# tmp301, MEM[(<address-space-1> long unsigned int *)40B]
	jne	.L292	#,
	mov	rdi, rbx	#, tmp295
	call	[QWORD PTR _Unwind_Resume@GOTPCREL[rip]]	#
.L264:
# saves_scene.cpp:302:     drawText(renderer, Config::getFont(), "Сохранения", 0, TITLE_Y,
	mov	rdi, QWORD PTR -200[rbp]	#, %sfp
	call	[QWORD PTR _ZNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEED1Ev@GOTPCREL[rip]]	#
	mov	rax, QWORD PTR -56[rbp]	# tmp300, D.173322
	sub	rax, QWORD PTR fs:40	# tmp300, MEM[(<address-space-1> long unsigned int *)40B]
	jne	.L293	#,
	mov	rdi, rbx	#, tmp294
	call	[QWORD PTR _Unwind_Resume@GOTPCREL[rip]]	#
.LEHE14:
.L292:
	call	[QWORD PTR __stack_chk_fail@GOTPCREL[rip]]	#
.L291:
	call	[QWORD PTR __stack_chk_fail@GOTPCREL[rip]]	#
.L293:
	call	[QWORD PTR __stack_chk_fail@GOTPCREL[rip]]	#
	.cfi_endproc
.LFE12874:
	.section	.gcc_except_table
.LLSDAC12874:
	.byte	0xff
	.byte	0xff
	.byte	0x1
	.uleb128 .LLSDACSEC12874-.LLSDACSBC12874
.LLSDACSBC12874:
	.uleb128 .LEHB14-.LCOLDB15
	.uleb128 .LEHE14-.LEHB14
	.uleb128 0
	.uleb128 0
.LLSDACSEC12874:
	.section	.text.unlikely
	.text
	.size	_ZN10SavesScene6renderEP12SDL_Renderer, .-_ZN10SavesScene6renderEP12SDL_Renderer
	.section	.text.unlikely
	.size	_ZN10SavesScene6renderEP12SDL_Renderer.cold, .-_ZN10SavesScene6renderEP12SDL_Renderer.cold
.LCOLDE15:
	.text
.LHOTE15:
	.section	.text._ZNSt13_Bvector_baseISaIbEE18_Bvector_impl_data8_M_resetEv,"axG",@progbits,_ZNSt13_Bvector_baseISaIbEE18_Bvector_impl_data8_M_resetEv,comdat
	.align 2
	.p2align 4
	.weak	_ZNSt13_Bvector_baseISaIbEE18_Bvector_impl_data8_M_resetEv
	.type	_ZNSt13_Bvector_baseISaIbEE18_Bvector_impl_data8_M_resetEv, @function
_ZNSt13_Bvector_baseISaIbEE18_Bvector_impl_data8_M_resetEv:
.LFB13679:
	.cfi_startproc
	push	rbx	#
	.cfi_def_cfa_offset 16
	.cfi_offset 3, -16
	sub	rsp, 48	#,
	.cfi_def_cfa_offset 64
# /usr/include/c++/15.2.1/bits/stl_bvector.h:583: 	_M_reset() _GLIBCXX_NOEXCEPT
	mov	rbx, QWORD PTR fs:40	# this, MEM[(<address-space-1> long unsigned int *)40B]
	mov	QWORD PTR 40[rsp], rbx	# D.173334, this
	mov	rbx, rdi	# this, this
# /usr/include/c++/15.2.1/bits/stl_bvector.h:584: 	{ *this = _Bvector_impl_data(); }
	mov	rdi, rsp	# tmp101,
	call	_ZNSt13_Bvector_baseISaIbEE18_Bvector_impl_dataC1Ev	#
# /usr/include/c++/15.2.1/bits/stl_bvector.h:584: 	{ *this = _Bvector_impl_data(); }
	movdqa	xmm0, XMMWORD PTR [rsp]	# D.168337, D.168337
	mov	rax, QWORD PTR 32[rsp]	# D.168337, D.168337
	movups	XMMWORD PTR [rbx], xmm0	# *this_3(D), D.168337
	movdqa	xmm0, XMMWORD PTR 16[rsp]	# D.168337, D.168337
	mov	QWORD PTR 32[rbx], rax	# *this_3(D), D.168337
	movups	XMMWORD PTR 16[rbx], xmm0	# *this_3(D), D.168337
# /usr/include/c++/15.2.1/bits/stl_bvector.h:584: 	{ *this = _Bvector_impl_data(); }
	mov	rax, QWORD PTR 40[rsp]	# tmp107, D.173334
	sub	rax, QWORD PTR fs:40	# tmp107, MEM[(<address-space-1> long unsigned int *)40B]
	jne	.L297	#,
	add	rsp, 48	#,
	.cfi_remember_state
	.cfi_def_cfa_offset 16
	pop	rbx	#
	.cfi_def_cfa_offset 8
	ret	
.L297:
	.cfi_restore_state
	call	[QWORD PTR __stack_chk_fail@GOTPCREL[rip]]	#
	.cfi_endproc
.LFE13679:
	.size	_ZNSt13_Bvector_baseISaIbEE18_Bvector_impl_data8_M_resetEv, .-_ZNSt13_Bvector_baseISaIbEE18_Bvector_impl_data8_M_resetEv
	.section	.text._ZNSt13_Bvector_baseISaIbEE13_M_deallocateEv,"axG",@progbits,_ZNSt13_Bvector_baseISaIbEE13_M_deallocateEv,comdat
	.align 2
	.p2align 4
	.weak	_ZNSt13_Bvector_baseISaIbEE13_M_deallocateEv
	.type	_ZNSt13_Bvector_baseISaIbEE13_M_deallocateEv, @function
_ZNSt13_Bvector_baseISaIbEE13_M_deallocateEv:
.LFB13528:
	.cfi_startproc
# /usr/include/c++/15.2.1/bits/stl_bvector.h:701: 	if (_M_impl._M_start._M_p)
	mov	rcx, QWORD PTR [rdi]	# _1, this_13(D)->_M_impl.D.156243._M_start.D.107718._M_p
# /usr/include/c++/15.2.1/bits/stl_bvector.h:701: 	if (_M_impl._M_start._M_p)
	test	rcx, rcx	# _1
	je	.L298	#,
# /usr/include/c++/15.2.1/bits/stl_bvector.h:699:       _M_deallocate()
	sub	rsp, 24	#,
	.cfi_def_cfa_offset 32
	mov	rdx, rdi	# this, this
	mov	rdi, QWORD PTR 32[rdi]	# _17, MEM[(long unsigned int * *)this_13(D) + 32B]
	mov	QWORD PTR 8[rsp], rdx	# %sfp, this
# /usr/include/c++/15.2.1/bits/stl_bvector.h:703: 	    const size_t __n = _M_impl._M_end_addr() - _M_impl._M_start._M_p;
	call	_ZNKSt13_Bvector_baseISaIbEE13_Bvector_impl11_M_end_addrEv.isra.0	#
# /usr/include/c++/15.2.1/bits/stl_bvector.h:703: 	    const size_t __n = _M_impl._M_end_addr() - _M_impl._M_start._M_p;
	sub	rax, rcx	# _4, _1
	mov	rsi, rax	# _5, _4
# /usr/include/c++/15.2.1/bits/stl_bvector.h:704: 	    _Bit_alloc_traits::deallocate(_M_impl,
	sub	rdi, rax	# _9, _4
# /usr/include/c++/15.2.1/bits/stl_bvector.h:703: 	    const size_t __n = _M_impl._M_end_addr() - _M_impl._M_start._M_p;
	sar	rsi, 3	# _5,
# /usr/include/c++/15.2.1/bits/alloc_traits.h:649:       { __a.deallocate(__p, __n); }
	call	_ZNSt15__new_allocatorImE10deallocateEPmm.isra.0	#
# /usr/include/c++/15.2.1/bits/stl_bvector.h:707: 	    _M_impl._M_reset();
	mov	rdi, QWORD PTR 8[rsp]	#, %sfp
# /usr/include/c++/15.2.1/bits/stl_bvector.h:709:       }
	add	rsp, 24	#,
	.cfi_def_cfa_offset 8
# /usr/include/c++/15.2.1/bits/stl_bvector.h:707: 	    _M_impl._M_reset();
	jmp	_ZNSt13_Bvector_baseISaIbEE18_Bvector_impl_data8_M_resetEv	#
	.p2align 4,,10
	.p2align 3
.L298:
	ret	
	.cfi_endproc
.LFE13528:
	.size	_ZNSt13_Bvector_baseISaIbEE13_M_deallocateEv, .-_ZNSt13_Bvector_baseISaIbEE13_M_deallocateEv
	.section	.text._ZNSt13_Bvector_baseISaIbEED2Ev,"axG",@progbits,_ZNSt13_Bvector_baseISaIbEED5Ev,comdat
	.align 2
	.p2align 4
	.weak	_ZNSt13_Bvector_baseISaIbEED2Ev
	.type	_ZNSt13_Bvector_baseISaIbEED2Ev, @function
_ZNSt13_Bvector_baseISaIbEED2Ev:
.LFB13283:
	.cfi_startproc
# /usr/include/c++/15.2.1/bits/stl_bvector.h:676:       { this->_M_deallocate(); }
	jmp	_ZNSt13_Bvector_baseISaIbEE13_M_deallocateEv	#
	.cfi_endproc
.LFE13283:
	.size	_ZNSt13_Bvector_baseISaIbEED2Ev, .-_ZNSt13_Bvector_baseISaIbEED2Ev
	.weak	_ZNSt13_Bvector_baseISaIbEED1Ev
	.set	_ZNSt13_Bvector_baseISaIbEED1Ev,_ZNSt13_Bvector_baseISaIbEED2Ev
	.section	.text._ZNSt6vectorIbSaIbEED2Ev,"axG",@progbits,_ZNSt6vectorIbSaIbEED5Ev,comdat
	.align 2
	.p2align 4
	.weak	_ZNSt6vectorIbSaIbEED2Ev
	.type	_ZNSt6vectorIbSaIbEED2Ev, @function
_ZNSt6vectorIbSaIbEED2Ev:
.LFB13286:
	.cfi_startproc
# /usr/include/c++/15.2.1/bits/stl_bvector.h:926:       ~vector() _GLIBCXX_NOEXCEPT { }
	jmp	_ZNSt13_Bvector_baseISaIbEED2Ev	#
	.cfi_endproc
.LFE13286:
	.size	_ZNSt6vectorIbSaIbEED2Ev, .-_ZNSt6vectorIbSaIbEED2Ev
	.weak	_ZNSt6vectorIbSaIbEED1Ev
	.set	_ZNSt6vectorIbSaIbEED1Ev,_ZNSt6vectorIbSaIbEED2Ev
	.section	.text._ZNSt6vectorI6ButtonSaIS0_EE12_Guard_allocC2EPS0_mRSt12_Vector_baseIS0_S1_E,"axG",@progbits,_ZNSt6vectorI6ButtonSaIS0_EE12_Guard_allocC5EPS0_mRSt12_Vector_baseIS0_S1_E,comdat
	.align 2
	.p2align 4
	.weak	_ZNSt6vectorI6ButtonSaIS0_EE12_Guard_allocC2EPS0_mRSt12_Vector_baseIS0_S1_E
	.type	_ZNSt6vectorI6ButtonSaIS0_EE12_Guard_allocC2EPS0_mRSt12_Vector_baseIS0_S1_E, @function
_ZNSt6vectorI6ButtonSaIS0_EE12_Guard_allocC2EPS0_mRSt12_Vector_baseIS0_S1_E:
.LFB13685:
	.cfi_startproc
# /usr/include/c++/15.2.1/bits/stl_vector.h:1876: 	: _M_storage(__s), _M_len(__l), _M_vect(__vect)
	mov	QWORD PTR [rdi], rsi	# *this_2(D)._M_storage, __s
# /usr/include/c++/15.2.1/bits/stl_vector.h:1876: 	: _M_storage(__s), _M_len(__l), _M_vect(__vect)
	mov	QWORD PTR 8[rdi], rdx	# *this_2(D)._M_len, __l
# /usr/include/c++/15.2.1/bits/stl_vector.h:1876: 	: _M_storage(__s), _M_len(__l), _M_vect(__vect)
	mov	QWORD PTR 16[rdi], rcx	# *this_2(D)._M_vect, __vect
# /usr/include/c++/15.2.1/bits/stl_vector.h:1877: 	{ }
	ret	
	.cfi_endproc
.LFE13685:
	.size	_ZNSt6vectorI6ButtonSaIS0_EE12_Guard_allocC2EPS0_mRSt12_Vector_baseIS0_S1_E, .-_ZNSt6vectorI6ButtonSaIS0_EE12_Guard_allocC2EPS0_mRSt12_Vector_baseIS0_S1_E
	.weak	_ZNSt6vectorI6ButtonSaIS0_EE12_Guard_allocC1EPS0_mRSt12_Vector_baseIS0_S1_E
	.set	_ZNSt6vectorI6ButtonSaIS0_EE12_Guard_allocC1EPS0_mRSt12_Vector_baseIS0_S1_E,_ZNSt6vectorI6ButtonSaIS0_EE12_Guard_allocC2EPS0_mRSt12_Vector_baseIS0_S1_E
	.section	.text._ZNSt6vectorI6ButtonSaIS0_EE12_Guard_allocD2Ev,"axG",@progbits,_ZNSt6vectorI6ButtonSaIS0_EE12_Guard_allocD5Ev,comdat
	.align 2
	.p2align 4
	.weak	_ZNSt6vectorI6ButtonSaIS0_EE12_Guard_allocD2Ev
	.type	_ZNSt6vectorI6ButtonSaIS0_EE12_Guard_allocD2Ev, @function
_ZNSt6vectorI6ButtonSaIS0_EE12_Guard_allocD2Ev:
.LFB13688:
	.cfi_startproc
# /usr/include/c++/15.2.1/bits/stl_vector.h:1880: 	~_Guard_alloc()
	mov	rax, rdi	# this, this
# /usr/include/c++/15.2.1/bits/stl_vector.h:1882: 	  if (_M_storage)
	mov	rdi, QWORD PTR [rdi]	# _1, this_6(D)->_M_storage
# /usr/include/c++/15.2.1/bits/stl_vector.h:1882: 	  if (_M_storage)
	test	rdi, rdi	# _1
	je	.L306	#,
# /usr/include/c++/15.2.1/bits/stl_vector.h:1883: 	    _M_vect._M_deallocate(_M_storage, _M_len);
	mov	rsi, QWORD PTR 8[rax]	# this_6(D)->_M_len, this_6(D)->_M_len
	jmp	_ZNSt12_Vector_baseI6ButtonSaIS0_EE13_M_deallocateEPS0_m.isra.0	#
	.p2align 4,,10
	.p2align 3
.L306:
# /usr/include/c++/15.2.1/bits/stl_vector.h:1884: 	}
	ret	
	.cfi_endproc
.LFE13688:
	.size	_ZNSt6vectorI6ButtonSaIS0_EE12_Guard_allocD2Ev, .-_ZNSt6vectorI6ButtonSaIS0_EE12_Guard_allocD2Ev
	.weak	_ZNSt6vectorI6ButtonSaIS0_EE12_Guard_allocD1Ev
	.set	_ZNSt6vectorI6ButtonSaIS0_EE12_Guard_allocD1Ev,_ZNSt6vectorI6ButtonSaIS0_EE12_Guard_allocD2Ev
	.section	.text._ZNSt13_Bvector_baseISaIbEE8_S_nwordEm,"axG",@progbits,_ZNSt13_Bvector_baseISaIbEE8_S_nwordEm,comdat
	.p2align 4
	.weak	_ZNSt13_Bvector_baseISaIbEE8_S_nwordEm
	.type	_ZNSt13_Bvector_baseISaIbEE8_S_nwordEm, @function
_ZNSt13_Bvector_baseISaIbEE8_S_nwordEm:
.LFB13703:
	.cfi_startproc
# /usr/include/c++/15.2.1/bits/stl_bvector.h:721:       { return (__n + int(_S_word_bit) - 1) / int(_S_word_bit); }
	lea	rax, 63[rdi]	# _1,
# /usr/include/c++/15.2.1/bits/stl_bvector.h:721:       { return (__n + int(_S_word_bit) - 1) / int(_S_word_bit); }
	shr	rax, 6	# _3,
# /usr/include/c++/15.2.1/bits/stl_bvector.h:721:       { return (__n + int(_S_word_bit) - 1) / int(_S_word_bit); }
	ret	
	.cfi_endproc
.LFE13703:
	.size	_ZNSt13_Bvector_baseISaIbEE8_S_nwordEm, .-_ZNSt13_Bvector_baseISaIbEE8_S_nwordEm
	.section	.text._ZNSt13_Bvector_baseISaIbEE11_M_allocateEm.isra.0,"axG",@progbits,_ZNSt6vectorIbSaIbEE13_M_insert_auxESt13_Bit_iteratorb,comdat
	.align 2
	.p2align 4
	.type	_ZNSt13_Bvector_baseISaIbEE11_M_allocateEm.isra.0, @function
_ZNSt13_Bvector_baseISaIbEE11_M_allocateEm.isra.0:
.LFB13930:
	.cfi_startproc
	sub	rsp, 8	#,
	.cfi_def_cfa_offset 16
# /usr/include/c++/15.2.1/bits/stl_bvector.h:685: 	_Bit_pointer __p = _Bit_alloc_traits::allocate(_M_impl, _S_nword(__n));
	call	_ZNSt13_Bvector_baseISaIbEE8_S_nwordEm	#
# /usr/include/c++/15.2.1/bits/stl_bvector.h:695:       }
	add	rsp, 8	#,
	.cfi_def_cfa_offset 8
# /usr/include/c++/15.2.1/bits/alloc_traits.h:614:       { return __a.allocate(__n); }
	mov	rdi, rax	#, _2
	jmp	_ZNSt15__new_allocatorImE8allocateEmPKv.isra.0	#
	.cfi_endproc
.LFE13930:
	.size	_ZNSt13_Bvector_baseISaIbEE11_M_allocateEm.isra.0, .-_ZNSt13_Bvector_baseISaIbEE11_M_allocateEm.isra.0
	.section	.text._ZNKSt6vectorIbSaIbEE3endEv,"axG",@progbits,_ZNKSt6vectorIbSaIbEE3endEv,comdat
	.align 2
	.p2align 4
	.weak	_ZNKSt6vectorIbSaIbEE3endEv
	.type	_ZNKSt6vectorIbSaIbEE3endEv, @function
_ZNKSt6vectorIbSaIbEE3endEv:
.LFB13705:
	.cfi_startproc
	sub	rsp, 72	#,
	.cfi_def_cfa_offset 80
# /usr/include/c++/15.2.1/bits/stl_bvector.h:1081:       { return this->_M_impl._M_finish; }
	mov	rsi, QWORD PTR fs:40	# _1, MEM[(<address-space-1> long unsigned int *)40B]
	mov	QWORD PTR 56[rsp], rsi	# D.173367, _1
	lea	rsi, 16[rdi]	# _1,
	lea	rdi, 16[rsp]	# tmp104,
	call	_ZNSt19_Bit_const_iteratorC1ERKSt13_Bit_iterator	#
# /usr/include/c++/15.2.1/bits/stl_bvector.h:1081:       { return this->_M_impl._M_finish; }
	mov	rax, QWORD PTR 16[rsp]	# D.168615, D.168615
	mov	rdx, QWORD PTR 24[rsp]	# D.168615, D.168615
	mov	QWORD PTR 32[rsp], rax	# D.170365, D.168615
	mov	QWORD PTR 40[rsp], rdx	# D.170365, D.168615
# /usr/include/c++/15.2.1/bits/stl_bvector.h:1081:       { return this->_M_impl._M_finish; }
	mov	rcx, QWORD PTR 56[rsp]	# tmp109, D.173367
	sub	rcx, QWORD PTR fs:40	# tmp109, MEM[(<address-space-1> long unsigned int *)40B]
	jne	.L314	#,
	add	rsp, 72	#,
	.cfi_remember_state
	.cfi_def_cfa_offset 8
	ret	
.L314:
	.cfi_restore_state
	call	[QWORD PTR __stack_chk_fail@GOTPCREL[rip]]	#
	.cfi_endproc
.LFE13705:
	.size	_ZNKSt6vectorIbSaIbEE3endEv, .-_ZNKSt6vectorIbSaIbEE3endEv
	.section	.text._ZNKSt6vectorIbSaIbEE4sizeEv,"axG",@progbits,_ZNKSt6vectorIbSaIbEE4sizeEv,comdat
	.align 2
	.p2align 4
	.weak	_ZNKSt6vectorIbSaIbEE4sizeEv
	.type	_ZNKSt6vectorIbSaIbEE4sizeEv, @function
_ZNKSt6vectorIbSaIbEE4sizeEv:
.LFB13561:
	.cfi_startproc
	push	rbx	#
	.cfi_def_cfa_offset 16
	.cfi_offset 3, -16
	mov	rbx, rdi	# this, this
	sub	rsp, 32	#,
	.cfi_def_cfa_offset 48
# /usr/include/c++/15.2.1/bits/stl_bvector.h:1128:       { return size_type(end() - begin()); }
	mov	rdi, QWORD PTR [rdi]	# MEM[(_Bit_type * *)this_3(D)], MEM[(_Bit_type * *)this_3(D)]
	call	_ZNKSt6vectorIbSaIbEE5beginEv.isra.0	#
# /usr/include/c++/15.2.1/bits/stl_bvector.h:1128:       { return size_type(end() - begin()); }
	mov	rdi, rbx	#, this
# /usr/include/c++/15.2.1/bits/stl_bvector.h:1128:       { return size_type(end() - begin()); }
	mov	QWORD PTR 24[rsp], rdx	# D.167026,
	mov	QWORD PTR 16[rsp], rax	# D.167026, tmp114
# /usr/include/c++/15.2.1/bits/stl_bvector.h:1128:       { return size_type(end() - begin()); }
	call	_ZNKSt6vectorIbSaIbEE3endEv	#
# /usr/include/c++/15.2.1/bits/stl_bvector.h:1128:       { return size_type(end() - begin()); }
	mov	ecx, DWORD PTR 24[rsp]	#, MEM[(unsigned int *)&D.167026 + 8B]
# /usr/include/c++/15.2.1/bits/stl_bvector.h:1128:       { return size_type(end() - begin()); }
	mov	QWORD PTR [rsp], rax	# D.167025, tmp115
# /usr/include/c++/15.2.1/bits/stl_bvector.h:1128:       { return size_type(end() - begin()); }
	mov	rdi, QWORD PTR [rsp]	#, MEM[(_Bit_type * *)&D.167025]
# /usr/include/c++/15.2.1/bits/stl_bvector.h:1128:       { return size_type(end() - begin()); }
	mov	QWORD PTR 8[rsp], rdx	# D.167025,
# /usr/include/c++/15.2.1/bits/stl_bvector.h:1128:       { return size_type(end() - begin()); }
	mov	rdx, QWORD PTR 16[rsp]	#, MEM[(_Bit_type * *)&D.167026]
	mov	esi, DWORD PTR 8[rsp]	#, MEM[(unsigned int *)&D.167025 + 8B]
# /usr/include/c++/15.2.1/bits/stl_bvector.h:1128:       { return size_type(end() - begin()); }
	add	rsp, 32	#,
	.cfi_def_cfa_offset 16
	pop	rbx	#
	.cfi_def_cfa_offset 8
# /usr/include/c++/15.2.1/bits/stl_bvector.h:1128:       { return size_type(end() - begin()); }
	jmp	_ZStmiRKSt18_Bit_iterator_baseS1_.isra.0	#
	.cfi_endproc
.LFE13561:
	.size	_ZNKSt6vectorIbSaIbEE4sizeEv, .-_ZNKSt6vectorIbSaIbEE4sizeEv
	.section	.text._ZNKSt6vectorIbSaIbEE12_M_check_lenEmPKc,"axG",@progbits,_ZNKSt6vectorIbSaIbEE12_M_check_lenEmPKc,comdat
	.align 2
	.p2align 4
	.weak	_ZNKSt6vectorIbSaIbEE12_M_check_lenEmPKc
	.type	_ZNKSt6vectorIbSaIbEE12_M_check_lenEmPKc, @function
_ZNKSt6vectorIbSaIbEE12_M_check_lenEmPKc:
.LFB13699:
	.cfi_startproc
	push	r14	#
	.cfi_def_cfa_offset 16
	.cfi_offset 14, -16
	push	rbp	#
	.cfi_def_cfa_offset 24
	.cfi_offset 6, -24
# /usr/include/c++/15.2.1/bits/stl_bvector.h:1737: 	if (max_size() - size() < __n)
	movabs	rbp, 9223372036854775744	# tmp113,
# /usr/include/c++/15.2.1/bits/stl_bvector.h:1735:       _M_check_len(size_type __n, const char* __s) const
	push	rbx	#
	.cfi_def_cfa_offset 32
	.cfi_offset 3, -32
	sub	rsp, 32	#,
	.cfi_def_cfa_offset 64
# /usr/include/c++/15.2.1/bits/stl_bvector.h:1735:       _M_check_len(size_type __n, const char* __s) const
	mov	QWORD PTR 8[rsp], rsi	# __n, __n
	mov	r14, QWORD PTR fs:40	# __s, MEM[(<address-space-1> long unsigned int *)40B]
	mov	QWORD PTR 24[rsp], r14	# D.173374, __s
	mov	r14, rdx	# __s, __s
# /usr/include/c++/15.2.1/bits/stl_bvector.h:1737: 	if (max_size() - size() < __n)
	call	_ZNKSt6vectorIbSaIbEE4sizeEv	#
	mov	rbx, rax	# _1,
# /usr/include/c++/15.2.1/bits/stl_bvector.h:1737: 	if (max_size() - size() < __n)
	mov	rax, rbp	# _2, tmp113
	sub	rax, rbx	# _2, _1
# /usr/include/c++/15.2.1/bits/stl_bvector.h:1737: 	if (max_size() - size() < __n)
	cmp	rax, QWORD PTR 8[rsp]	# _2, __n
	jb	.L327	#,
# /usr/include/c++/15.2.1/bits/stl_bvector.h:1740: 	const size_type __len = size() + std::max(size(), __n);
	lea	rsi, 8[rsp]	# tmp115,
	lea	rdi, 16[rsp]	# tmp116,
# /usr/include/c++/15.2.1/bits/stl_bvector.h:1740: 	const size_type __len = size() + std::max(size(), __n);
	mov	QWORD PTR 16[rsp], rbx	# D.168571, _1
# /usr/include/c++/15.2.1/bits/stl_bvector.h:1740: 	const size_type __len = size() + std::max(size(), __n);
	call	_ZSt3maxImERKT_S2_S2_	#
	add	rbx, QWORD PTR [rax]	# tmp117, *_4
	jc	.L321	#,
# /usr/include/c++/15.2.1/bits/stl_bvector.h:1741: 	return (__len < size() || __len > max_size()) ? max_size() : __len;
	movabs	rax, 9223372036854775744	# tmp129,
	cmp	rbx, rax	# tmp117, tmp129
	cmovbe	rax, rbx	# tmp117,, <retval>
.L317:
# /usr/include/c++/15.2.1/bits/stl_bvector.h:1742:       }
	mov	rdx, QWORD PTR 24[rsp]	# tmp131, D.173374
	sub	rdx, QWORD PTR fs:40	# tmp131, MEM[(<address-space-1> long unsigned int *)40B]
	jne	.L326	#,
	add	rsp, 32	#,
	.cfi_remember_state
	.cfi_def_cfa_offset 32
	pop	rbx	#
	.cfi_def_cfa_offset 24
	pop	rbp	#
	.cfi_def_cfa_offset 16
	pop	r14	#
	.cfi_def_cfa_offset 8
	ret	
.L321:
	.cfi_restore_state
# /usr/include/c++/15.2.1/bits/stl_bvector.h:1741: 	return (__len < size() || __len > max_size()) ? max_size() : __len;
	mov	rax, rbp	# <retval>, tmp113
# /usr/include/c++/15.2.1/bits/stl_bvector.h:1741: 	return (__len < size() || __len > max_size()) ? max_size() : __len;
	jmp	.L317	#
.L327:
# /usr/include/c++/15.2.1/bits/stl_bvector.h:1738: 	  __throw_length_error(__N(__s));
	mov	rax, QWORD PTR 24[rsp]	# tmp130, D.173374
	sub	rax, QWORD PTR fs:40	# tmp130, MEM[(<address-space-1> long unsigned int *)40B]
	je	.L319	#,
.L326:
# /usr/include/c++/15.2.1/bits/stl_bvector.h:1742:       }
	call	[QWORD PTR __stack_chk_fail@GOTPCREL[rip]]	#
.L319:
# /usr/include/c++/15.2.1/bits/stl_bvector.h:1738: 	  __throw_length_error(__N(__s));
	mov	rdi, r14	#, __s
	call	[QWORD PTR _ZSt20__throw_length_errorPKc@GOTPCREL[rip]]	#
	.cfi_endproc
.LFE13699:
	.size	_ZNKSt6vectorIbSaIbEE12_M_check_lenEmPKc, .-_ZNKSt6vectorIbSaIbEE12_M_check_lenEmPKc
	.section	.text._ZN9SaveEntryD2Ev,"axG",@progbits,_ZN9SaveEntryD5Ev,comdat
	.align 2
	.p2align 4
	.weak	_ZN9SaveEntryD2Ev
	.type	_ZN9SaveEntryD2Ev, @function
_ZN9SaveEntryD2Ev:
.LFB13780:
	.cfi_startproc
	push	rbx	#
	.cfi_def_cfa_offset 16
	.cfi_offset 3, -16
# ../utils/save_manager.h:77: struct SaveEntry {
	mov	rbx, rdi	# this, this
	lea	rdi, 40[rdi]	# _1,
	call	[QWORD PTR _ZNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEED1Ev@GOTPCREL[rip]]	#
# ../utils/save_manager.h:77: struct SaveEntry {
	lea	rdi, 8[rbx]	# _2,
# ../utils/save_manager.h:77: struct SaveEntry {
	pop	rbx	#
	.cfi_def_cfa_offset 8
# ../utils/save_manager.h:77: struct SaveEntry {
	jmp	[QWORD PTR _ZNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEED1Ev@GOTPCREL[rip]]	#
	.cfi_endproc
.LFE13780:
	.size	_ZN9SaveEntryD2Ev, .-_ZN9SaveEntryD2Ev
	.weak	_ZN9SaveEntryD1Ev
	.set	_ZN9SaveEntryD1Ev,_ZN9SaveEntryD2Ev
	.section	.text._ZSt8_DestroyI9SaveEntryEvPT_,"axG",@progbits,_ZSt8_DestroyI9SaveEntryEvPT_,comdat
	.p2align 4
	.weak	_ZSt8_DestroyI9SaveEntryEvPT_
	.type	_ZSt8_DestroyI9SaveEntryEvPT_, @function
_ZSt8_DestroyI9SaveEntryEvPT_:
.LFB13778:
	.cfi_startproc
# /usr/include/c++/15.2.1/bits/stl_construct.h:166:       __pointer->~_Tp();
	jmp	_ZN9SaveEntryD1Ev	#
	.cfi_endproc
.LFE13778:
	.size	_ZSt8_DestroyI9SaveEntryEvPT_, .-_ZSt8_DestroyI9SaveEntryEvPT_
	.section	.text._ZSt8_DestroyIP9SaveEntryEvT_S2_,"axG",@progbits,_ZSt8_DestroyIP9SaveEntryEvT_S2_,comdat
	.p2align 4
	.weak	_ZSt8_DestroyIP9SaveEntryEvT_S2_
	.type	_ZSt8_DestroyIP9SaveEntryEvT_S2_, @function
_ZSt8_DestroyIP9SaveEntryEvT_S2_:
.LFB13665:
	.cfi_startproc
# /usr/include/c++/15.2.1/bits/stl_construct.h:225: 	for (; __first != __last; ++__first)
	cmp	rdi, rsi	# __first, __last
	je	.L336	#,
# /usr/include/c++/15.2.1/bits/stl_construct.h:219:     _Destroy(_ForwardIterator __first, _ForwardIterator __last)
	push	rbp	#
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	mov	rbp, rsi	# __last, __last
	push	rbx	#
	.cfi_def_cfa_offset 24
	.cfi_offset 3, -24
	mov	rbx, rdi	# __first, __first
	sub	rsp, 8	#,
	.cfi_def_cfa_offset 32
	.p2align 4
	.p2align 3
.L333:
# /usr/include/c++/15.2.1/bits/stl_construct.h:226: 	  std::_Destroy(std::__addressof(*__first));
	mov	rdi, rbx	#, __first
# /usr/include/c++/15.2.1/bits/stl_construct.h:225: 	for (; __first != __last; ++__first)
	add	rbx, 72	# __first,
# /usr/include/c++/15.2.1/bits/stl_construct.h:226: 	  std::_Destroy(std::__addressof(*__first));
	call	_ZSt8_DestroyI9SaveEntryEvPT_	#
# /usr/include/c++/15.2.1/bits/stl_construct.h:225: 	for (; __first != __last; ++__first)
	cmp	rbp, rbx	# __last, __first
	jne	.L333	#,
# /usr/include/c++/15.2.1/bits/stl_construct.h:236:     }
	add	rsp, 8	#,
	.cfi_def_cfa_offset 24
	pop	rbx	#
	.cfi_def_cfa_offset 16
	pop	rbp	#
	.cfi_def_cfa_offset 8
	ret	
	.p2align 4,,10
	.p2align 3
.L336:
	.cfi_restore 3
	.cfi_restore 6
	ret	
	.cfi_endproc
.LFE13665:
	.size	_ZSt8_DestroyIP9SaveEntryEvT_S2_, .-_ZSt8_DestroyIP9SaveEntryEvT_S2_
	.section	.text._ZNSt6vectorI9SaveEntrySaIS0_EED2Ev,"axG",@progbits,_ZNSt6vectorI9SaveEntrySaIS0_EED5Ev,comdat
	.align 2
	.p2align 4
	.weak	_ZNSt6vectorI9SaveEntrySaIS0_EED2Ev
	.type	_ZNSt6vectorI9SaveEntrySaIS0_EED2Ev, @function
_ZNSt6vectorI9SaveEntrySaIS0_EED2Ev:
.LFB13251:
	.cfi_startproc
	push	rbx	#
	.cfi_def_cfa_offset 16
	.cfi_offset 3, -16
# /usr/include/c++/15.2.1/bits/stl_vector.h:800:       ~vector() _GLIBCXX_NOEXCEPT
	mov	rbx, rdi	# this, this
# /usr/include/c++/15.2.1/bits/alloc_traits.h:1045:       std::_Destroy(__first, __last);
	mov	rsi, QWORD PTR 8[rdi]	# this_4(D)->D.154257._M_impl.D.153592._M_finish, this_4(D)->D.154257._M_impl.D.153592._M_finish
	mov	rdi, QWORD PTR [rdi]	# this_4(D)->D.154257._M_impl.D.153592._M_start, this_4(D)->D.154257._M_impl.D.153592._M_start
	call	_ZSt8_DestroyIP9SaveEntryEvT_S2_	#
# /usr/include/c++/15.2.1/bits/stl_vector.h:805:       }
	mov	rdi, rbx	#, this
	pop	rbx	#
	.cfi_def_cfa_offset 8
	jmp	_ZNSt12_Vector_baseI9SaveEntrySaIS0_EED2Ev	#
	.cfi_endproc
.LFE13251:
	.size	_ZNSt6vectorI9SaveEntrySaIS0_EED2Ev, .-_ZNSt6vectorI9SaveEntrySaIS0_EED2Ev
	.weak	_ZNSt6vectorI9SaveEntrySaIS0_EED1Ev
	.set	_ZNSt6vectorI9SaveEntrySaIS0_EED1Ev,_ZNSt6vectorI9SaveEntrySaIS0_EED2Ev
	.section	.text._ZN11SaveManagerD2Ev,"axG",@progbits,_ZN11SaveManagerD5Ev,comdat
	.align 2
	.p2align 4
	.weak	_ZN11SaveManagerD2Ev
	.type	_ZN11SaveManagerD2Ev, @function
_ZN11SaveManagerD2Ev:
.LFB12821:
	.cfi_startproc
# ../utils/save_manager.h:93: class SaveManager {
	add	rdi, 8	# _1,
	jmp	_ZNSt6vectorI9SaveEntrySaIS0_EED1Ev	#
	.cfi_endproc
.LFE12821:
	.size	_ZN11SaveManagerD2Ev, .-_ZN11SaveManagerD2Ev
	.weak	_ZN11SaveManagerD1Ev
	.set	_ZN11SaveManagerD1Ev,_ZN11SaveManagerD2Ev
	.section	.text._ZSt8_DestroyI6ButtonEvPT_,"axG",@progbits,_ZSt8_DestroyI6ButtonEvPT_,comdat
	.p2align 4
	.weak	_ZSt8_DestroyI6ButtonEvPT_
	.type	_ZSt8_DestroyI6ButtonEvPT_, @function
_ZSt8_DestroyI6ButtonEvPT_:
.LFB13785:
	.cfi_startproc
# /usr/include/c++/15.2.1/bits/stl_construct.h:166:       __pointer->~_Tp();
	jmp	_ZN6ButtonD1Ev	#
	.cfi_endproc
.LFE13785:
	.size	_ZSt8_DestroyI6ButtonEvPT_, .-_ZSt8_DestroyI6ButtonEvPT_
	.section	.text._ZSt8_DestroyIP6ButtonEvT_S2_,"axG",@progbits,_ZSt8_DestroyIP6ButtonEvT_S2_,comdat
	.p2align 4
	.weak	_ZSt8_DestroyIP6ButtonEvT_S2_
	.type	_ZSt8_DestroyIP6ButtonEvT_S2_, @function
_ZSt8_DestroyIP6ButtonEvT_S2_:
.LFB13674:
	.cfi_startproc
# /usr/include/c++/15.2.1/bits/stl_construct.h:225: 	for (; __first != __last; ++__first)
	cmp	rdi, rsi	# __first, __last
	je	.L348	#,
# /usr/include/c++/15.2.1/bits/stl_construct.h:219:     _Destroy(_ForwardIterator __first, _ForwardIterator __last)
	push	rbp	#
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	mov	rbp, rsi	# __last, __last
	push	rbx	#
	.cfi_def_cfa_offset 24
	.cfi_offset 3, -24
	mov	rbx, rdi	# __first, __first
	sub	rsp, 8	#,
	.cfi_def_cfa_offset 32
	.p2align 4
	.p2align 3
.L345:
# /usr/include/c++/15.2.1/bits/stl_construct.h:226: 	  std::_Destroy(std::__addressof(*__first));
	mov	rdi, rbx	#, __first
# /usr/include/c++/15.2.1/bits/stl_construct.h:225: 	for (; __first != __last; ++__first)
	add	rbx, 56	# __first,
# /usr/include/c++/15.2.1/bits/stl_construct.h:226: 	  std::_Destroy(std::__addressof(*__first));
	call	_ZSt8_DestroyI6ButtonEvPT_	#
# /usr/include/c++/15.2.1/bits/stl_construct.h:225: 	for (; __first != __last; ++__first)
	cmp	rbp, rbx	# __last, __first
	jne	.L345	#,
# /usr/include/c++/15.2.1/bits/stl_construct.h:236:     }
	add	rsp, 8	#,
	.cfi_def_cfa_offset 24
	pop	rbx	#
	.cfi_def_cfa_offset 16
	pop	rbp	#
	.cfi_def_cfa_offset 8
	ret	
	.p2align 4,,10
	.p2align 3
.L348:
	.cfi_restore 3
	.cfi_restore 6
	ret	
	.cfi_endproc
.LFE13674:
	.size	_ZSt8_DestroyIP6ButtonEvT_S2_, .-_ZSt8_DestroyIP6ButtonEvT_S2_
	.section	.text._ZNSt6vectorI6ButtonSaIS0_EED2Ev,"axG",@progbits,_ZNSt6vectorI6ButtonSaIS0_EED5Ev,comdat
	.align 2
	.p2align 4
	.weak	_ZNSt6vectorI6ButtonSaIS0_EED2Ev
	.type	_ZNSt6vectorI6ButtonSaIS0_EED2Ev, @function
_ZNSt6vectorI6ButtonSaIS0_EED2Ev:
.LFB13274:
	.cfi_startproc
	push	rbx	#
	.cfi_def_cfa_offset 16
	.cfi_offset 3, -16
# /usr/include/c++/15.2.1/bits/stl_vector.h:800:       ~vector() _GLIBCXX_NOEXCEPT
	mov	rbx, rdi	# this, this
# /usr/include/c++/15.2.1/bits/alloc_traits.h:1045:       std::_Destroy(__first, __last);
	mov	rsi, QWORD PTR 8[rdi]	# this_4(D)->D.155608._M_impl.D.154943._M_finish, this_4(D)->D.155608._M_impl.D.154943._M_finish
	mov	rdi, QWORD PTR [rdi]	# this_4(D)->D.155608._M_impl.D.154943._M_start, this_4(D)->D.155608._M_impl.D.154943._M_start
	call	_ZSt8_DestroyIP6ButtonEvT_S2_	#
# /usr/include/c++/15.2.1/bits/stl_vector.h:805:       }
	mov	rdi, rbx	#, this
	pop	rbx	#
	.cfi_def_cfa_offset 8
	jmp	_ZNSt12_Vector_baseI6ButtonSaIS0_EED2Ev	#
	.cfi_endproc
.LFE13274:
	.size	_ZNSt6vectorI6ButtonSaIS0_EED2Ev, .-_ZNSt6vectorI6ButtonSaIS0_EED2Ev
	.weak	_ZNSt6vectorI6ButtonSaIS0_EED1Ev
	.set	_ZNSt6vectorI6ButtonSaIS0_EED1Ev,_ZNSt6vectorI6ButtonSaIS0_EED2Ev
	.section	.text._ZN10SavesSceneD2Ev,"axG",@progbits,_ZN10SavesSceneD5Ev,comdat
	.align 2
	.p2align 4
	.weak	_ZN10SavesSceneD2Ev
	.type	_ZN10SavesSceneD2Ev, @function
_ZN10SavesSceneD2Ev:
.LFB13890:
	.cfi_startproc
	lea	rax, _ZTV10SavesScene[rip+16]	# tmp112,
	push	rbx	#
	.cfi_def_cfa_offset 16
	.cfi_offset 3, -16
# saves_scene.h:14: class SavesScene : public Scene {
	mov	rbx, rdi	# this, this
	lea	rdi, 208[rdi]	# _1,
	mov	QWORD PTR -208[rdi], rax	# this_7(D)->D.156845._vptr.Scene, tmp112
	call	_ZNSt6vectorI6ButtonSaIS0_EED1Ev	#
# saves_scene.h:14: class SavesScene : public Scene {
	lea	rdi, 152[rbx]	# _2,
	call	[QWORD PTR _ZNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEED1Ev@GOTPCREL[rip]]	#
# saves_scene.h:14: class SavesScene : public Scene {
	lea	rdi, 104[rbx]	# _3,
	call	_ZNSt6vectorIbSaIbEED1Ev	#
# saves_scene.h:14: class SavesScene : public Scene {
	lea	rdi, 80[rbx]	# _4,
	call	_ZNSt6vectorI6ButtonSaIS0_EED1Ev	#
# saves_scene.h:14: class SavesScene : public Scene {
	lea	rdi, 24[rbx]	# _5,
# saves_scene.h:14: class SavesScene : public Scene {
	pop	rbx	#
	.cfi_def_cfa_offset 8
# saves_scene.h:14: class SavesScene : public Scene {
	jmp	_ZN6ButtonD1Ev	#
	.cfi_endproc
.LFE13890:
	.size	_ZN10SavesSceneD2Ev, .-_ZN10SavesSceneD2Ev
	.weak	_ZN10SavesSceneD1Ev
	.set	_ZN10SavesSceneD1Ev,_ZN10SavesSceneD2Ev
	.section	.text._ZN10SavesSceneD0Ev,"axG",@progbits,_ZN10SavesSceneD5Ev,comdat
	.align 2
	.p2align 4
	.weak	_ZN10SavesSceneD0Ev
	.type	_ZN10SavesSceneD0Ev, @function
_ZN10SavesSceneD0Ev:
.LFB13892:
	.cfi_startproc
	sub	rsp, 24	#,
	.cfi_def_cfa_offset 32
# saves_scene.h:14: class SavesScene : public Scene {
	mov	QWORD PTR 8[rsp], rdi	# %sfp, this
	call	_ZN10SavesSceneD1Ev	#
# saves_scene.h:14: class SavesScene : public Scene {
	mov	rdi, QWORD PTR 8[rsp]	# this, %sfp
	mov	esi, 232	#,
# saves_scene.h:14: class SavesScene : public Scene {
	add	rsp, 24	#,
	.cfi_def_cfa_offset 8
# saves_scene.h:14: class SavesScene : public Scene {
	jmp	[QWORD PTR _ZdlPvm@GOTPCREL[rip]]	#
	.cfi_endproc
.LFE13892:
	.size	_ZN10SavesSceneD0Ev, .-_ZN10SavesSceneD0Ev
	.section	.text._ZNSt6vectorI6ButtonSaIS0_EE15_M_erase_at_endEPS0_,"axG",@progbits,_ZNSt6vectorI6ButtonSaIS0_EE15_M_erase_at_endEPS0_,comdat
	.align 2
	.p2align 4
	.weak	_ZNSt6vectorI6ButtonSaIS0_EE15_M_erase_at_endEPS0_
	.type	_ZNSt6vectorI6ButtonSaIS0_EE15_M_erase_at_endEPS0_, @function
_ZNSt6vectorI6ButtonSaIS0_EE15_M_erase_at_endEPS0_:
.LFB13546:
	.cfi_startproc
# /usr/include/c++/15.2.1/bits/stl_vector.h:2241: 	if (size_type __n = this->_M_impl._M_finish - __pos)
	mov	rcx, QWORD PTR 8[rdi]	# _1, this_4(D)->D.155608._M_impl.D.154943._M_finish
# /usr/include/c++/15.2.1/bits/stl_vector.h:2241: 	if (size_type __n = this->_M_impl._M_finish - __pos)
	cmp	rcx, rsi	# _1, __pos
	je	.L360	#,
# /usr/include/c++/15.2.1/bits/stl_vector.h:2239:       _M_erase_at_end(pointer __pos) _GLIBCXX_NOEXCEPT
	sub	rsp, 24	#,
	.cfi_def_cfa_offset 32
	mov	QWORD PTR 8[rsp], rdi	# %sfp, this
# /usr/include/c++/15.2.1/bits/alloc_traits.h:1045:       std::_Destroy(__first, __last);
	mov	rdi, rsi	#, __pos
	mov	QWORD PTR [rsp], rsi	# %sfp, __pos
	mov	rsi, rcx	#, _1
	call	_ZSt8_DestroyIP6ButtonEvT_S2_	#
# /usr/include/c++/15.2.1/bits/stl_vector.h:2245: 	    this->_M_impl._M_finish = __pos;
	mov	rax, QWORD PTR [rsp]	# __pos, %sfp
	mov	rdx, QWORD PTR 8[rsp]	# this, %sfp
	mov	QWORD PTR 8[rdx], rax	# this_4(D)->D.155608._M_impl.D.154943._M_finish, __pos
# /usr/include/c++/15.2.1/bits/stl_vector.h:2248:       }
	add	rsp, 24	#,
	.cfi_def_cfa_offset 8
	ret	
	.p2align 4,,10
	.p2align 3
.L360:
	ret	
	.cfi_endproc
.LFE13546:
	.size	_ZNSt6vectorI6ButtonSaIS0_EE15_M_erase_at_endEPS0_, .-_ZNSt6vectorI6ButtonSaIS0_EE15_M_erase_at_endEPS0_
	.section	.text._ZNSt6vectorI6ButtonSaIS0_EE5clearEv,"axG",@progbits,_ZNSt6vectorI6ButtonSaIS0_EE5clearEv,comdat
	.align 2
	.p2align 4
	.weak	_ZNSt6vectorI6ButtonSaIS0_EE5clearEv
	.type	_ZNSt6vectorI6ButtonSaIS0_EE5clearEv, @function
_ZNSt6vectorI6ButtonSaIS0_EE5clearEv:
.LFB13297:
	.cfi_startproc
# /usr/include/c++/15.2.1/bits/stl_vector.h:1864:       { _M_erase_at_end(this->_M_impl._M_start); }
	mov	rsi, QWORD PTR [rdi]	# this_3(D)->D.155608._M_impl.D.154943._M_start, this_3(D)->D.155608._M_impl.D.154943._M_start
	jmp	_ZNSt6vectorI6ButtonSaIS0_EE15_M_erase_at_endEPS0_	#
	.cfi_endproc
.LFE13297:
	.size	_ZNSt6vectorI6ButtonSaIS0_EE5clearEv, .-_ZNSt6vectorI6ButtonSaIS0_EE5clearEv
	.section	.text._ZSt12__miter_baseISt13_Bit_iteratorET_S1_,"axG",@progbits,_ZSt12__miter_baseISt13_Bit_iteratorET_S1_,comdat
	.p2align 4
	.weak	_ZSt12__miter_baseISt13_Bit_iteratorET_S1_
	.type	_ZSt12__miter_baseISt13_Bit_iteratorET_S1_, @function
_ZSt12__miter_baseISt13_Bit_iteratorET_S1_:
.LFB13793:
	.cfi_startproc
# /usr/include/c++/15.2.1/bits/cpp_type_traits.h:705:     __miter_base(_Iterator __it)
	mov	QWORD PTR -40[rsp], rdi	# __it, __it
# /usr/include/c++/15.2.1/bits/cpp_type_traits.h:706:     { return __it; }
	mov	rax, QWORD PTR -40[rsp]	#, __it
# /usr/include/c++/15.2.1/bits/cpp_type_traits.h:705:     __miter_base(_Iterator __it)
	mov	QWORD PTR -32[rsp], rsi	# __it, __it
# /usr/include/c++/15.2.1/bits/cpp_type_traits.h:706:     { return __it; }
	mov	rdx, QWORD PTR -32[rsp]	#, __it
	ret	
	.cfi_endproc
.LFE13793:
	.size	_ZSt12__miter_baseISt13_Bit_iteratorET_S1_, .-_ZSt12__miter_baseISt13_Bit_iteratorET_S1_
	.section	.text._ZNKSt12_Vector_baseI6ButtonSaIS0_EE19_M_get_Tp_allocatorEv,"axG",@progbits,_ZNKSt12_Vector_baseI6ButtonSaIS0_EE19_M_get_Tp_allocatorEv,comdat
	.align 2
	.p2align 4
	.weak	_ZNKSt12_Vector_baseI6ButtonSaIS0_EE19_M_get_Tp_allocatorEv
	.type	_ZNKSt12_Vector_baseI6ButtonSaIS0_EE19_M_get_Tp_allocatorEv, @function
_ZNKSt12_Vector_baseI6ButtonSaIS0_EE19_M_get_Tp_allocatorEv:
.LFB13824:
	.cfi_startproc
# /usr/include/c++/15.2.1/bits/stl_vector.h:312:       _M_get_Tp_allocator() const _GLIBCXX_NOEXCEPT
	mov	rax, rdi	# this, this
# /usr/include/c++/15.2.1/bits/stl_vector.h:313:       { return this->_M_impl; }
	ret	
	.cfi_endproc
.LFE13824:
	.size	_ZNKSt12_Vector_baseI6ButtonSaIS0_EE19_M_get_Tp_allocatorEv, .-_ZNKSt12_Vector_baseI6ButtonSaIS0_EE19_M_get_Tp_allocatorEv
	.section	.text._ZNKSt6vectorI6ButtonSaIS0_EE8max_sizeEv,"axG",@progbits,_ZNKSt6vectorI6ButtonSaIS0_EE8max_sizeEv,comdat
	.align 2
	.p2align 4
	.weak	_ZNKSt6vectorI6ButtonSaIS0_EE8max_sizeEv
	.type	_ZNKSt6vectorI6ButtonSaIS0_EE8max_sizeEv, @function
_ZNKSt6vectorI6ButtonSaIS0_EE8max_sizeEv:
.LFB13787:
	.cfi_startproc
# /usr/include/c++/15.2.1/bits/stl_vector.h:1129:       { return _S_max_size(_M_get_Tp_allocator()); }
	jmp	_ZNSt6vectorI6ButtonSaIS0_EE11_S_max_sizeERKS1_.isra.0	#
	.cfi_endproc
.LFE13787:
	.size	_ZNKSt6vectorI6ButtonSaIS0_EE8max_sizeEv, .-_ZNKSt6vectorI6ButtonSaIS0_EE8max_sizeEv
	.section	.text._ZNKSt6vectorI6ButtonSaIS0_EE12_M_check_lenEmPKc,"axG",@progbits,_ZNKSt6vectorI6ButtonSaIS0_EE12_M_check_lenEmPKc,comdat
	.align 2
	.p2align 4
	.weak	_ZNKSt6vectorI6ButtonSaIS0_EE12_M_check_lenEmPKc
	.type	_ZNKSt6vectorI6ButtonSaIS0_EE12_M_check_lenEmPKc, @function
_ZNKSt6vectorI6ButtonSaIS0_EE12_M_check_lenEmPKc:
.LFB13681:
	.cfi_startproc
	push	r12	#
	.cfi_def_cfa_offset 16
	.cfi_offset 12, -16
	push	rbp	#
	.cfi_def_cfa_offset 24
	.cfi_offset 6, -24
	mov	rbp, rdi	# this, this
	push	rbx	#
	.cfi_def_cfa_offset 32
	.cfi_offset 3, -32
	sub	rsp, 32	#,
	.cfi_def_cfa_offset 64
# /usr/include/c++/15.2.1/bits/stl_vector.h:2202:       _M_check_len(size_type __n, const char* __s) const
	mov	QWORD PTR 8[rsp], rsi	# __n, __n
	mov	r12, QWORD PTR fs:40	# __s, MEM[(<address-space-1> long unsigned int *)40B]
	mov	QWORD PTR 24[rsp], r12	# D.173435, __s
	mov	r12, rdx	# __s, __s
# /usr/include/c++/15.2.1/bits/stl_vector.h:2204: 	if (max_size() - size() < __n)
	call	_ZNKSt6vectorI6ButtonSaIS0_EE8max_sizeEv	#
# /usr/include/c++/15.2.1/bits/stl_vector.h:2204: 	if (max_size() - size() < __n)
	mov	rsi, QWORD PTR 8[rbp]	# MEM[(struct Button * *)this_10(D) + 8B], MEM[(struct Button * *)this_10(D) + 8B]
	mov	rdi, QWORD PTR 0[rbp]	# MEM[(struct Button * *)this_10(D)], MEM[(struct Button * *)this_10(D)]
# /usr/include/c++/15.2.1/bits/stl_vector.h:2204: 	if (max_size() - size() < __n)
	mov	rdx, rax	# _1,
# /usr/include/c++/15.2.1/bits/stl_vector.h:2204: 	if (max_size() - size() < __n)
	call	_ZNKSt6vectorI6ButtonSaIS0_EE4sizeEv.isra.0	#
# /usr/include/c++/15.2.1/bits/stl_vector.h:2204: 	if (max_size() - size() < __n)
	sub	rdx, rax	# _3, _2
# /usr/include/c++/15.2.1/bits/stl_vector.h:2204: 	if (max_size() - size() < __n)
	cmp	rdx, QWORD PTR 8[rsp]	# _3, __n
	jb	.L376	#,
# /usr/include/c++/15.2.1/bits/stl_vector.h:2207: 	const size_type __len = size() + (std::max)(size(), __n);
	lea	rsi, 8[rsp]	# tmp119,
	lea	rdi, 16[rsp]	# tmp120,
	mov	rbx, rax	# _2,
	xor	r12d, r12d	# _19
# /usr/include/c++/15.2.1/bits/stl_vector.h:2207: 	const size_type __len = size() + (std::max)(size(), __n);
	mov	QWORD PTR 16[rsp], rax	# D.168354, _2
# /usr/include/c++/15.2.1/bits/stl_vector.h:2207: 	const size_type __len = size() + (std::max)(size(), __n);
	call	_ZSt3maxImERKT_S2_S2_	#
# /usr/include/c++/15.2.1/bits/stl_vector.h:2208: 	return (__len < size() || __len > max_size()) ? max_size() : __len;
	mov	rdi, rbp	#, this
	add	rbx, QWORD PTR [rax]	# tmp121, *_5
	setc	r12b	#, _19
	call	_ZNKSt6vectorI6ButtonSaIS0_EE8max_sizeEv	#
# /usr/include/c++/15.2.1/bits/stl_vector.h:2208: 	return (__len < size() || __len > max_size()) ? max_size() : __len;
	cmp	rax, rbx	# <retval>, tmp121
	cmovbe	rbx, rax	# <retval>,, tmp125
	test	r12, r12	# _19
	cmove	rax, rbx	# tmp125,, <retval>
# /usr/include/c++/15.2.1/bits/stl_vector.h:2209:       }
	mov	rdx, QWORD PTR 24[rsp]	# tmp134, D.173435
	sub	rdx, QWORD PTR fs:40	# tmp134, MEM[(<address-space-1> long unsigned int *)40B]
	jne	.L375	#,
	add	rsp, 32	#,
	.cfi_remember_state
	.cfi_def_cfa_offset 32
	pop	rbx	#
	.cfi_def_cfa_offset 24
	pop	rbp	#
	.cfi_def_cfa_offset 16
	pop	r12	#
	.cfi_def_cfa_offset 8
	ret	
.L376:
	.cfi_restore_state
# /usr/include/c++/15.2.1/bits/stl_vector.h:2205: 	  __throw_length_error(__N(__s));
	mov	rax, QWORD PTR 24[rsp]	# tmp133, D.173435
	sub	rax, QWORD PTR fs:40	# tmp133, MEM[(<address-space-1> long unsigned int *)40B]
	je	.L369	#,
.L375:
# /usr/include/c++/15.2.1/bits/stl_vector.h:2209:       }
	call	[QWORD PTR __stack_chk_fail@GOTPCREL[rip]]	#
.L369:
# /usr/include/c++/15.2.1/bits/stl_vector.h:2205: 	  __throw_length_error(__N(__s));
	mov	rdi, r12	#, __s
	call	[QWORD PTR _ZSt20__throw_length_errorPKc@GOTPCREL[rip]]	#
	.cfi_endproc
.LFE13681:
	.size	_ZNKSt6vectorI6ButtonSaIS0_EE12_M_check_lenEmPKc, .-_ZNKSt6vectorI6ButtonSaIS0_EE12_M_check_lenEmPKc
	.section	.text._ZSt12__miter_baseIPmET_S1_,"axG",@progbits,_ZSt12__miter_baseIPmET_S1_,comdat
	.p2align 4
	.weak	_ZSt12__miter_baseIPmET_S1_
	.type	_ZSt12__miter_baseIPmET_S1_, @function
_ZSt12__miter_baseIPmET_S1_:
.LFB13838:
	.cfi_startproc
# /usr/include/c++/15.2.1/bits/cpp_type_traits.h:705:     __miter_base(_Iterator __it)
	mov	rax, rdi	# __it, __it
# /usr/include/c++/15.2.1/bits/cpp_type_traits.h:706:     { return __it; }
	ret	
	.cfi_endproc
.LFE13838:
	.size	_ZSt12__miter_baseIPmET_S1_, .-_ZSt12__miter_baseIPmET_S1_
	.section	.text._ZSt12__miter_baseISt19_Bit_const_iteratorET_S1_,"axG",@progbits,_ZSt12__miter_baseISt19_Bit_const_iteratorET_S1_,comdat
	.p2align 4
	.weak	_ZSt12__miter_baseISt19_Bit_const_iteratorET_S1_
	.type	_ZSt12__miter_baseISt19_Bit_const_iteratorET_S1_, @function
_ZSt12__miter_baseISt19_Bit_const_iteratorET_S1_:
.LFB13841:
	.cfi_startproc
# /usr/include/c++/15.2.1/bits/cpp_type_traits.h:705:     __miter_base(_Iterator __it)
	mov	QWORD PTR -40[rsp], rdi	# __it, __it
# /usr/include/c++/15.2.1/bits/cpp_type_traits.h:706:     { return __it; }
	mov	rax, QWORD PTR -40[rsp]	#, __it
# /usr/include/c++/15.2.1/bits/cpp_type_traits.h:705:     __miter_base(_Iterator __it)
	mov	QWORD PTR -32[rsp], rsi	# __it, __it
# /usr/include/c++/15.2.1/bits/cpp_type_traits.h:706:     { return __it; }
	mov	rdx, QWORD PTR -32[rsp]	#, __it
	ret	
	.cfi_endproc
.LFE13841:
	.size	_ZSt12__miter_baseISt19_Bit_const_iteratorET_S1_, .-_ZSt12__miter_baseISt19_Bit_const_iteratorET_S1_
	.section	.text._ZSt14__copy_move_a2ILb0ESt13_Bit_iteratorS0_S0_ET2_T0_T1_S1_,"axG",@progbits,_ZSt14__copy_move_a2ILb0ESt13_Bit_iteratorS0_S0_ET2_T0_T1_S1_,comdat
	.p2align 4
	.weak	_ZSt14__copy_move_a2ILb0ESt13_Bit_iteratorS0_S0_ET2_T0_T1_S1_
	.type	_ZSt14__copy_move_a2ILb0ESt13_Bit_iteratorS0_S0_ET2_T0_T1_S1_, @function
_ZSt14__copy_move_a2ILb0ESt13_Bit_iteratorS0_S0_ET2_T0_T1_S1_:
.LFB13865:
	.cfi_startproc
	push	r15	#
	.cfi_def_cfa_offset 16
	.cfi_offset 15, -16
	push	r14	#
	.cfi_def_cfa_offset 24
	.cfi_offset 14, -24
	mov	r14, rdx	# tmp131, __last
	push	r13	#
	.cfi_def_cfa_offset 32
	.cfi_offset 13, -32
	push	r12	#
	.cfi_def_cfa_offset 40
	.cfi_offset 12, -40
	push	rbp	#
	.cfi_def_cfa_offset 48
	.cfi_offset 6, -48
	push	rbx	#
	.cfi_def_cfa_offset 56
	.cfi_offset 3, -56
	sub	rsp, 88	#,
	.cfi_def_cfa_offset 144
# /usr/include/c++/15.2.1/bits/stl_algobase.h:413:     __copy_move_a2(_InIter __first, _Sent __last, _OutIter __result)
	mov	QWORD PTR 40[rsp], rcx	# __last, __last
# /usr/include/c++/15.2.1/bits/stl_algobase.h:407: 	*__out = *__in;
	lea	rbp, 48[rsp]	# tmp130,
	mov	r13d, DWORD PTR 40[rsp]	# pretmp_26, MEM[(unsigned int *)&__last + 8B]
# /usr/include/c++/15.2.1/bits/stl_algobase.h:413:     __copy_move_a2(_InIter __first, _Sent __last, _OutIter __result)
	mov	QWORD PTR 48[rsp], rdi	# __first, __first
	mov	QWORD PTR 56[rsp], rsi	# __first, __first
	mov	QWORD PTR 32[rsp], rdx	# __last, __last
	mov	QWORD PTR 16[rsp], r8	# __result, __result
	mov	QWORD PTR 24[rsp], r9	# __result, __result
# /usr/include/c++/15.2.1/bits/stl_algobase.h:461:       for (; __first != __last; ++__result, (void)++__first)
	jmp	.L380	#
	.p2align 4,,10
	.p2align 3
.L381:
# /usr/include/c++/15.2.1/bits/stl_algobase.h:407: 	*__out = *__in;
	mov	rdi, rbp	#, tmp130
	call	_ZNKSt13_Bit_iteratordeEv	#
# /usr/include/c++/15.2.1/bits/stl_algobase.h:407: 	*__out = *__in;
	lea	rdi, 16[rsp]	#,
# /usr/include/c++/15.2.1/bits/stl_algobase.h:407: 	*__out = *__in;
	mov	r12, rax	# D.172042,
	mov	r15, rdx	# D.172042,
# /usr/include/c++/15.2.1/bits/stl_algobase.h:407: 	*__out = *__in;
	call	_ZNKSt13_Bit_iteratordeEv	#
# /usr/include/c++/15.2.1/bits/stl_algobase.h:407: 	*__out = *__in;
	mov	rcx, r15	#, D.172042
# /usr/include/c++/15.2.1/bits/stl_algobase.h:407: 	*__out = *__in;
	mov	rsi, rdx	# D.172041,
# /usr/include/c++/15.2.1/bits/stl_algobase.h:407: 	*__out = *__in;
	mov	rdi, rax	#, D.172041
	mov	rdx, r12	#, D.172042
	call	_ZNSt14_Bit_referenceaSERKS_.isra.0	#
# /usr/include/c++/15.2.1/bits/stl_algobase.h:461:       for (; __first != __last; ++__result, (void)++__first)
	lea	rdi, 16[rsp]	#,
	call	_ZNSt13_Bit_iteratorppEv.isra.0	#
# /usr/include/c++/15.2.1/bits/stl_algobase.h:461:       for (; __first != __last; ++__result, (void)++__first)
	mov	rdi, rbp	#, tmp130
	call	_ZNSt13_Bit_iteratorppEv.isra.0	#
.L380:
# /usr/include/c++/15.2.1/bits/stl_algobase.h:461:       for (; __first != __last; ++__result, (void)++__first)
	mov	esi, DWORD PTR 56[rsp]	#, MEM[(unsigned int *)&__first + 8B]
	mov	rdi, QWORD PTR 48[rsp]	#, MEM[(_Bit_type * *)&__first]
	mov	ecx, r13d	#, pretmp_26
	mov	rdx, r14	#, tmp131
	call	_ZStneRKSt18_Bit_iterator_baseS1_.isra.0	#
# /usr/include/c++/15.2.1/bits/stl_algobase.h:461:       for (; __first != __last; ++__result, (void)++__first)
	test	al, al	# retval.47_4
	jne	.L381	#,
# /usr/include/c++/15.2.1/bits/stl_algobase.h:464:     }
	mov	rax, QWORD PTR 16[rsp]	#, __result
	mov	rdx, QWORD PTR 24[rsp]	#, __result
	add	rsp, 88	#,
	.cfi_def_cfa_offset 56
	pop	rbx	#
	.cfi_def_cfa_offset 48
	pop	rbp	#
	.cfi_def_cfa_offset 40
	pop	r12	#
	.cfi_def_cfa_offset 32
	pop	r13	#
	.cfi_def_cfa_offset 24
	pop	r14	#
	.cfi_def_cfa_offset 16
	pop	r15	#
	.cfi_def_cfa_offset 8
	ret	
	.cfi_endproc
.LFE13865:
	.size	_ZSt14__copy_move_a2ILb0ESt13_Bit_iteratorS0_S0_ET2_T0_T1_S1_, .-_ZSt14__copy_move_a2ILb0ESt13_Bit_iteratorS0_S0_ET2_T0_T1_S1_
	.section	.text._ZSt4copyISt13_Bit_iteratorS0_ET0_T_S2_S1_.isra.0,"axG",@progbits,_ZNSt6vectorIbSaIbEE13_M_insert_auxESt13_Bit_iteratorb,comdat
	.p2align 4
	.type	_ZSt4copyISt13_Bit_iteratorS0_ET0_T_S2_S1_.isra.0, @function
_ZSt4copyISt13_Bit_iteratorS0_ET0_T_S2_S1_.isra.0:
.LFB13931:
	.cfi_startproc
	push	r13	#
	.cfi_def_cfa_offset 16
	.cfi_offset 13, -16
	mov	r13, rdi	# __first, __first
	mov	rdi, rdx	# tmp123, __last
	push	r12	#
	.cfi_def_cfa_offset 24
	.cfi_offset 12, -24
	mov	r12, rsi	# __first, __first
# /usr/include/c++/15.2.1/bits/stl_algobase.h:642: 	     (std::__miter_base(__first), std::__miter_base(__last), __result);
	mov	rsi, rcx	#, __last
# /usr/include/c++/15.2.1/bits/stl_algobase.h:633:     copy(_II __first, _II __last, _OI __result)
	push	rbp	#
	.cfi_def_cfa_offset 32
	.cfi_offset 6, -32
	mov	rbp, r8	# ISRA.1034, ISRA.1034
	push	rbx	#
	.cfi_def_cfa_offset 40
	.cfi_offset 3, -40
	mov	ebx, r9d	# ISRA.1035, ISRA.1035
	sub	rsp, 152	#,
	.cfi_def_cfa_offset 192
# /usr/include/c++/15.2.1/bits/stl_algobase.h:633:     copy(_II __first, _II __last, _OI __result)
	mov	QWORD PTR 16[rsp], rdx	# __last, __last
	mov	QWORD PTR 24[rsp], rcx	# __last, __last
# /usr/include/c++/15.2.1/bits/stl_algobase.h:642: 	     (std::__miter_base(__first), std::__miter_base(__last), __result);
	call	_ZSt12__miter_baseISt13_Bit_iteratorET_S1_	#
# /usr/include/c++/15.2.1/bits/stl_algobase.h:642: 	     (std::__miter_base(__first), std::__miter_base(__last), __result);
	mov	rdi, r13	#, __first
	mov	rsi, r12	#, __first
# /usr/include/c++/15.2.1/bits/stl_algobase.h:642: 	     (std::__miter_base(__first), std::__miter_base(__last), __result);
	mov	QWORD PTR 112[rsp], rax	# D.173467, tmp130
	mov	QWORD PTR 120[rsp], rdx	# D.173467,
# /usr/include/c++/15.2.1/bits/stl_algobase.h:642: 	     (std::__miter_base(__first), std::__miter_base(__last), __result);
	call	_ZSt12__miter_baseISt13_Bit_iteratorET_S1_	#
	mov	QWORD PTR 128[rsp], rbp	# MEM <_Bit_type *> [(struct _Bit_iterator *)_6], ISRA.1034
# /usr/include/c++/15.2.1/bits/stl_algobase.h:492:     { return std::__copy_move_a2<_IsMove>(__first, __last, __result); }
	mov	r8, QWORD PTR 128[rsp]	#, MEM[(struct _Bit_iterator *)_6]
# /usr/include/c++/15.2.1/bits/stl_algobase.h:642: 	     (std::__miter_base(__first), std::__miter_base(__last), __result);
	mov	QWORD PTR 96[rsp], rax	# D.173466, tmp131
# /usr/include/c++/15.2.1/bits/stl_algobase.h:492:     { return std::__copy_move_a2<_IsMove>(__first, __last, __result); }
	mov	rdi, QWORD PTR 96[rsp]	#, MEM <_Bit_type *> [(struct _Bit_iterator *)&D.173466]
# /usr/include/c++/15.2.1/bits/stl_algobase.h:642: 	     (std::__miter_base(__first), std::__miter_base(__last), __result);
	mov	QWORD PTR 104[rsp], rdx	# D.173466,
	mov	eax, DWORD PTR 104[rsp]	# __first$8, MEM <unsigned int> [(struct _Bit_iterator *)&D.173466 + 8B]
	mov	DWORD PTR 136[rsp], ebx	# MEM <unsigned int> [(struct _Bit_iterator *)_6 + 8B], ISRA.1035
# /usr/include/c++/15.2.1/bits/stl_algobase.h:492:     { return std::__copy_move_a2<_IsMove>(__first, __last, __result); }
	mov	r9, QWORD PTR 136[rsp]	#, MEM[(struct _Bit_iterator *)_6]
	mov	DWORD PTR 56[rsp], eax	# MEM <unsigned int> [(struct _Bit_iterator *)&__first + 8B], __first$8
	mov	rax, QWORD PTR 112[rsp]	# __last, MEM <_Bit_type *> [(struct _Bit_iterator *)&D.173467]
	mov	rsi, QWORD PTR 56[rsp]	#, __first
	mov	QWORD PTR 64[rsp], rax	# MEM <_Bit_type *> [(struct _Bit_iterator *)&__last], __last
	mov	eax, DWORD PTR 120[rsp]	# __last$8, MEM <unsigned int> [(struct _Bit_iterator *)&D.173467 + 8B]
	mov	rdx, QWORD PTR 64[rsp]	#, __last
	mov	DWORD PTR 72[rsp], eax	# MEM <unsigned int> [(struct _Bit_iterator *)&__last + 8B], __last$8
	mov	rcx, QWORD PTR 72[rsp]	#, __last
	call	_ZSt14__copy_move_a2ILb0ESt13_Bit_iteratorS0_S0_ET2_T0_T1_S1_	#
	mov	QWORD PTR 88[rsp], rdx	# D.173463, tmp136
	mov	QWORD PTR 128[rsp], rax	# MEM <_Bit_type *> [(struct _Bit_iterator *)_6], tmp124
	mov	QWORD PTR 80[rsp], rax	# D.173463, tmp135
	mov	eax, DWORD PTR 88[rsp]	# SR.447, MEM <unsigned int> [(struct _Bit_iterator *)&D.173463 + 8B]
	mov	DWORD PTR 136[rsp], eax	# MEM <unsigned int> [(struct _Bit_iterator *)_6 + 8B], SR.447
# /usr/include/c++/15.2.1/bits/stl_algobase.h:643:     }
	mov	rax, QWORD PTR 128[rsp]	#, MEM[(struct _Bit_iterator *)_6]
	mov	rdx, QWORD PTR 136[rsp]	#, MEM[(struct _Bit_iterator *)_6]
	add	rsp, 152	#,
	.cfi_def_cfa_offset 40
	pop	rbx	#
	.cfi_def_cfa_offset 32
	pop	rbp	#
	.cfi_def_cfa_offset 24
	pop	r12	#
	.cfi_def_cfa_offset 16
	pop	r13	#
	.cfi_def_cfa_offset 8
	ret	
	.cfi_endproc
.LFE13931:
	.size	_ZSt4copyISt13_Bit_iteratorS0_ET0_T_S2_S1_.isra.0, .-_ZSt4copyISt13_Bit_iteratorS0_ET0_T_S2_S1_.isra.0
	.section	.text._ZSt14__copy_move_a2ILb0EPmS0_S0_ET2_T0_T1_S1_,"axG",@progbits,_ZSt14__copy_move_a2ILb0EPmS0_S0_ET2_T0_T1_S1_,comdat
	.p2align 4
	.weak	_ZSt14__copy_move_a2ILb0EPmS0_S0_ET2_T0_T1_S1_
	.type	_ZSt14__copy_move_a2ILb0EPmS0_S0_ET2_T0_T1_S1_, @function
_ZSt14__copy_move_a2ILb0EPmS0_S0_ET2_T0_T1_S1_:
.LFB13876:
	.cfi_startproc
	push	rbx	#
	.cfi_def_cfa_offset 16
	.cfi_offset 3, -16
# /usr/include/c++/15.2.1/bits/stl_iterator_base_funcs.h:108:       return __last - __first;
	mov	rbx, rsi	# __last, __last
	sub	rbx, rdi	# __last, __first
# /usr/include/c++/15.2.1/bits/stl_algobase.h:424: 	  if (__builtin_expect(__n > 1, true))
	cmp	rbx, 8	# _10,
	jle	.L386	#,
	mov	rsi, rdi	# __first, __first
# /usr/include/c++/15.2.1/bits/stl_algobase.h:426: 	      __builtin_memmove(_GLIBCXX_TO_ADDR(__result),
	mov	rdi, rdx	#, __result
	mov	rdx, rbx	#, _10
	call	[QWORD PTR memmove@GOTPCREL[rip]]	#
# /usr/include/c++/15.2.1/bits/stl_algobase.h:429: 	      _GLIBCXX_ADVANCE(__result, __n);
	add	rax, rbx	# <retval>, _10
.L385:
# /usr/include/c++/15.2.1/bits/stl_algobase.h:464:     }
	pop	rbx	#
	.cfi_remember_state
	.cfi_def_cfa_offset 8
	ret	
	.p2align 4,,10
	.p2align 3
.L386:
	.cfi_restore_state
	mov	rax, rdx	# <retval>, __result
# /usr/include/c++/15.2.1/bits/stl_algobase.h:431: 	  else if (__n == 1)
	jne	.L385	#,
# /usr/include/c++/15.2.1/bits/stl_algobase.h:407: 	*__out = *__in;
	mov	rdx, QWORD PTR [rdi]	# _12, *__first_15(D)
# /usr/include/c++/15.2.1/bits/stl_algobase.h:434: 	      ++__result;
	add	rax, 8	# <retval>,
# /usr/include/c++/15.2.1/bits/stl_algobase.h:407: 	*__out = *__in;
	mov	QWORD PTR -8[rax], rdx	# *__result_16(D), _12
# /usr/include/c++/15.2.1/bits/stl_algobase.h:464:     }
	pop	rbx	#
	.cfi_def_cfa_offset 8
	ret	
	.cfi_endproc
.LFE13876:
	.size	_ZSt14__copy_move_a2ILb0EPmS0_S0_ET2_T0_T1_S1_, .-_ZSt14__copy_move_a2ILb0EPmS0_S0_ET2_T0_T1_S1_
	.section	.text._ZSt4copyIPmS0_ET0_T_S2_S1_,"axG",@progbits,_ZSt4copyIPmS0_ET0_T_S2_S1_,comdat
	.p2align 4
	.weak	_ZSt4copyIPmS0_ET0_T_S2_S1_
	.type	_ZSt4copyIPmS0_ET0_T_S2_S1_, @function
_ZSt4copyIPmS0_ET0_T_S2_S1_:
.LFB13798:
	.cfi_startproc
	push	rbp	#
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	mov	rbp, rdi	# __first, __first
# /usr/include/c++/15.2.1/bits/stl_algobase.h:642: 	     (std::__miter_base(__first), std::__miter_base(__last), __result);
	mov	rdi, rsi	#, __last
# /usr/include/c++/15.2.1/bits/stl_algobase.h:633:     copy(_II __first, _II __last, _OI __result)
	push	rbx	#
	.cfi_def_cfa_offset 24
	.cfi_offset 3, -24
	sub	rsp, 24	#,
	.cfi_def_cfa_offset 48
# /usr/include/c++/15.2.1/bits/stl_algobase.h:633:     copy(_II __first, _II __last, _OI __result)
	mov	QWORD PTR 8[rsp], rdx	# %sfp, __result
# /usr/include/c++/15.2.1/bits/stl_algobase.h:642: 	     (std::__miter_base(__first), std::__miter_base(__last), __result);
	call	_ZSt12__miter_baseIPmET_S1_	#
# /usr/include/c++/15.2.1/bits/stl_algobase.h:642: 	     (std::__miter_base(__first), std::__miter_base(__last), __result);
	mov	rdi, rbp	#, __first
# /usr/include/c++/15.2.1/bits/stl_algobase.h:642: 	     (std::__miter_base(__first), std::__miter_base(__last), __result);
	mov	rbx, rax	# _1,
# /usr/include/c++/15.2.1/bits/stl_algobase.h:642: 	     (std::__miter_base(__first), std::__miter_base(__last), __result);
	call	_ZSt12__miter_baseIPmET_S1_	#
# /usr/include/c++/15.2.1/bits/stl_algobase.h:492:     { return std::__copy_move_a2<_IsMove>(__first, __last, __result); }
	mov	rdx, QWORD PTR 8[rsp]	# __result, %sfp
# /usr/include/c++/15.2.1/bits/stl_algobase.h:643:     }
	add	rsp, 24	#,
	.cfi_def_cfa_offset 24
# /usr/include/c++/15.2.1/bits/stl_algobase.h:492:     { return std::__copy_move_a2<_IsMove>(__first, __last, __result); }
	mov	rsi, rbx	#, _1
	mov	rdi, rax	#, _2
# /usr/include/c++/15.2.1/bits/stl_algobase.h:643:     }
	pop	rbx	#
	.cfi_def_cfa_offset 16
	pop	rbp	#
	.cfi_def_cfa_offset 8
# /usr/include/c++/15.2.1/bits/stl_algobase.h:492:     { return std::__copy_move_a2<_IsMove>(__first, __last, __result); }
	jmp	_ZSt14__copy_move_a2ILb0EPmS0_S0_ET2_T0_T1_S1_	#
	.cfi_endproc
.LFE13798:
	.size	_ZSt4copyIPmS0_ET0_T_S2_S1_, .-_ZSt4copyIPmS0_ET0_T_S2_S1_
	.section	.text._ZSt14__copy_move_a2ILb0ESt19_Bit_const_iteratorS0_St13_Bit_iteratorET2_T0_T1_S2_,"axG",@progbits,_ZSt14__copy_move_a2ILb0ESt19_Bit_const_iteratorS0_St13_Bit_iteratorET2_T0_T1_S2_,comdat
	.p2align 4
	.weak	_ZSt14__copy_move_a2ILb0ESt19_Bit_const_iteratorS0_St13_Bit_iteratorET2_T0_T1_S2_
	.type	_ZSt14__copy_move_a2ILb0ESt19_Bit_const_iteratorS0_St13_Bit_iteratorET2_T0_T1_S2_, @function
_ZSt14__copy_move_a2ILb0ESt19_Bit_const_iteratorS0_St13_Bit_iteratorET2_T0_T1_S2_:
.LFB13877:
	.cfi_startproc
	push	r14	#
	.cfi_def_cfa_offset 16
	.cfi_offset 14, -16
	mov	r14, rdx	# tmp127, __last
	push	r13	#
	.cfi_def_cfa_offset 24
	.cfi_offset 13, -24
	push	r12	#
	.cfi_def_cfa_offset 32
	.cfi_offset 12, -32
	push	rbp	#
	.cfi_def_cfa_offset 40
	.cfi_offset 6, -40
	push	rbx	#
	.cfi_def_cfa_offset 48
	.cfi_offset 3, -48
	sub	rsp, 80	#,
	.cfi_def_cfa_offset 128
# /usr/include/c++/15.2.1/bits/stl_algobase.h:413:     __copy_move_a2(_InIter __first, _Sent __last, _OutIter __result)
	mov	QWORD PTR 40[rsp], rcx	# __last, __last
	mov	r13d, DWORD PTR 40[rsp]	# pretmp_25, MEM[(unsigned int *)&__last + 8B]
	mov	QWORD PTR 48[rsp], rdi	# __first, __first
	mov	QWORD PTR 56[rsp], rsi	# __first, __first
	mov	QWORD PTR 32[rsp], rdx	# __last, __last
	mov	QWORD PTR 16[rsp], r8	# __result, __result
	mov	QWORD PTR 24[rsp], r9	# __result, __result
# /usr/include/c++/15.2.1/bits/stl_algobase.h:461:       for (; __first != __last; ++__result, (void)++__first)
	jmp	.L393	#
	.p2align 4,,10
	.p2align 3
.L394:
# /usr/include/c++/15.2.1/bits/stl_algobase.h:407: 	*__out = *__in;
	lea	rdi, 48[rsp]	#,
# /usr/include/c++/15.2.1/bits/stl_algobase.h:407: 	*__out = *__in;
	lea	rbp, 16[rsp]	# tmp114,
# /usr/include/c++/15.2.1/bits/stl_algobase.h:407: 	*__out = *__in;
	call	_ZNKSt19_Bit_const_iteratordeEv	#
# /usr/include/c++/15.2.1/bits/stl_algobase.h:407: 	*__out = *__in;
	mov	rdi, rbp	#, tmp114
# /usr/include/c++/15.2.1/bits/stl_algobase.h:407: 	*__out = *__in;
	mov	ebx, eax	# _3,
# /usr/include/c++/15.2.1/bits/stl_algobase.h:407: 	*__out = *__in;
	call	_ZNKSt13_Bit_iteratordeEv	#
	mov	rsi, rdx	# D.172440,
# /usr/include/c++/15.2.1/bits/stl_algobase.h:407: 	*__out = *__in;
	mov	rdi, rax	#, D.172440
# /usr/include/c++/15.2.1/bits/stl_algobase.h:407: 	*__out = *__in;
	movzx	edx, bl	# _8, _3
# /usr/include/c++/15.2.1/bits/stl_algobase.h:407: 	*__out = *__in;
	call	_ZNSt14_Bit_referenceaSEb.isra.0	#
# /usr/include/c++/15.2.1/bits/stl_algobase.h:461:       for (; __first != __last; ++__result, (void)++__first)
	mov	rdi, rbp	#, tmp114
	call	_ZNSt13_Bit_iteratorppEv.isra.0	#
# /usr/include/c++/15.2.1/bits/stl_algobase.h:461:       for (; __first != __last; ++__result, (void)++__first)
	lea	rdi, 48[rsp]	#,
	call	_ZNSt19_Bit_const_iteratorppEv.isra.0	#
.L393:
# /usr/include/c++/15.2.1/bits/stl_algobase.h:461:       for (; __first != __last; ++__result, (void)++__first)
	mov	esi, DWORD PTR 56[rsp]	#, MEM[(unsigned int *)&__first + 8B]
	mov	rdi, QWORD PTR 48[rsp]	#, MEM[(_Bit_type * *)&__first]
	mov	ecx, r13d	#, pretmp_25
	mov	rdx, r14	#, tmp127
	call	_ZStneRKSt18_Bit_iterator_baseS1_.isra.0	#
# /usr/include/c++/15.2.1/bits/stl_algobase.h:461:       for (; __first != __last; ++__result, (void)++__first)
	test	al, al	# retval.46_4
	jne	.L394	#,
# /usr/include/c++/15.2.1/bits/stl_algobase.h:464:     }
	mov	rax, QWORD PTR 16[rsp]	#, __result
	mov	rdx, QWORD PTR 24[rsp]	#, __result
	add	rsp, 80	#,
	.cfi_def_cfa_offset 48
	pop	rbx	#
	.cfi_def_cfa_offset 40
	pop	rbp	#
	.cfi_def_cfa_offset 32
	pop	r12	#
	.cfi_def_cfa_offset 24
	pop	r13	#
	.cfi_def_cfa_offset 16
	pop	r14	#
	.cfi_def_cfa_offset 8
	ret	
	.cfi_endproc
.LFE13877:
	.size	_ZSt14__copy_move_a2ILb0ESt19_Bit_const_iteratorS0_St13_Bit_iteratorET2_T0_T1_S2_, .-_ZSt14__copy_move_a2ILb0ESt19_Bit_const_iteratorS0_St13_Bit_iteratorET2_T0_T1_S2_
	.section	.text._ZSt4copyISt19_Bit_const_iteratorSt13_Bit_iteratorET0_T_S3_S2_.isra.0,"axG",@progbits,_ZNSt6vectorIbSaIbEE13_M_insert_auxESt13_Bit_iteratorb,comdat
	.p2align 4
	.type	_ZSt4copyISt19_Bit_const_iteratorSt13_Bit_iteratorET0_T_S3_S2_.isra.0, @function
_ZSt4copyISt19_Bit_const_iteratorSt13_Bit_iteratorET0_T_S3_S2_.isra.0:
.LFB13932:
	.cfi_startproc
	push	r13	#
	.cfi_def_cfa_offset 16
	.cfi_offset 13, -16
	mov	r13, rdi	# __first, __first
	mov	rdi, rdx	# tmp123, __last
	push	r12	#
	.cfi_def_cfa_offset 24
	.cfi_offset 12, -24
	mov	r12, rsi	# __first, __first
# /usr/include/c++/15.2.1/bits/stl_algobase.h:642: 	     (std::__miter_base(__first), std::__miter_base(__last), __result);
	mov	rsi, rcx	#, __last
# /usr/include/c++/15.2.1/bits/stl_algobase.h:633:     copy(_II __first, _II __last, _OI __result)
	push	rbp	#
	.cfi_def_cfa_offset 32
	.cfi_offset 6, -32
	mov	rbp, r8	# ISRA.1048, ISRA.1048
	push	rbx	#
	.cfi_def_cfa_offset 40
	.cfi_offset 3, -40
	mov	ebx, r9d	# ISRA.1049, ISRA.1049
	sub	rsp, 152	#,
	.cfi_def_cfa_offset 192
# /usr/include/c++/15.2.1/bits/stl_algobase.h:633:     copy(_II __first, _II __last, _OI __result)
	mov	QWORD PTR 16[rsp], rdx	# __last, __last
	mov	QWORD PTR 24[rsp], rcx	# __last, __last
# /usr/include/c++/15.2.1/bits/stl_algobase.h:642: 	     (std::__miter_base(__first), std::__miter_base(__last), __result);
	call	_ZSt12__miter_baseISt19_Bit_const_iteratorET_S1_	#
# /usr/include/c++/15.2.1/bits/stl_algobase.h:642: 	     (std::__miter_base(__first), std::__miter_base(__last), __result);
	mov	rdi, r13	#, __first
	mov	rsi, r12	#, __first
# /usr/include/c++/15.2.1/bits/stl_algobase.h:642: 	     (std::__miter_base(__first), std::__miter_base(__last), __result);
	mov	QWORD PTR 112[rsp], rax	# D.173505, tmp130
	mov	QWORD PTR 120[rsp], rdx	# D.173505,
# /usr/include/c++/15.2.1/bits/stl_algobase.h:642: 	     (std::__miter_base(__first), std::__miter_base(__last), __result);
	call	_ZSt12__miter_baseISt19_Bit_const_iteratorET_S1_	#
	mov	QWORD PTR 128[rsp], rbp	# MEM <_Bit_type *> [(struct _Bit_iterator *)_6], ISRA.1048
# /usr/include/c++/15.2.1/bits/stl_algobase.h:492:     { return std::__copy_move_a2<_IsMove>(__first, __last, __result); }
	mov	r8, QWORD PTR 128[rsp]	#, MEM[(struct _Bit_iterator *)_6]
# /usr/include/c++/15.2.1/bits/stl_algobase.h:642: 	     (std::__miter_base(__first), std::__miter_base(__last), __result);
	mov	QWORD PTR 96[rsp], rax	# D.173504, tmp131
# /usr/include/c++/15.2.1/bits/stl_algobase.h:492:     { return std::__copy_move_a2<_IsMove>(__first, __last, __result); }
	mov	rdi, QWORD PTR 96[rsp]	#, MEM <_Bit_type *> [(struct _Bit_const_iterator *)&D.173504]
# /usr/include/c++/15.2.1/bits/stl_algobase.h:642: 	     (std::__miter_base(__first), std::__miter_base(__last), __result);
	mov	QWORD PTR 104[rsp], rdx	# D.173504,
	mov	eax, DWORD PTR 104[rsp]	# __first$8, MEM <unsigned int> [(struct _Bit_const_iterator *)&D.173504 + 8B]
	mov	DWORD PTR 136[rsp], ebx	# MEM <unsigned int> [(struct _Bit_iterator *)_6 + 8B], ISRA.1049
# /usr/include/c++/15.2.1/bits/stl_algobase.h:492:     { return std::__copy_move_a2<_IsMove>(__first, __last, __result); }
	mov	r9, QWORD PTR 136[rsp]	#, MEM[(struct _Bit_iterator *)_6]
	mov	DWORD PTR 56[rsp], eax	# MEM <unsigned int> [(struct _Bit_const_iterator *)&__first + 8B], __first$8
	mov	rax, QWORD PTR 112[rsp]	# __last, MEM <_Bit_type *> [(struct _Bit_const_iterator *)&D.173505]
	mov	rsi, QWORD PTR 56[rsp]	#, __first
	mov	QWORD PTR 64[rsp], rax	# MEM <_Bit_type *> [(struct _Bit_const_iterator *)&__last], __last
	mov	eax, DWORD PTR 120[rsp]	# __last$8, MEM <unsigned int> [(struct _Bit_const_iterator *)&D.173505 + 8B]
	mov	rdx, QWORD PTR 64[rsp]	#, __last
	mov	DWORD PTR 72[rsp], eax	# MEM <unsigned int> [(struct _Bit_const_iterator *)&__last + 8B], __last$8
	mov	rcx, QWORD PTR 72[rsp]	#, __last
	call	_ZSt14__copy_move_a2ILb0ESt19_Bit_const_iteratorS0_St13_Bit_iteratorET2_T0_T1_S2_	#
	mov	QWORD PTR 88[rsp], rdx	# D.173501, tmp136
	mov	QWORD PTR 128[rsp], rax	# MEM <_Bit_type *> [(struct _Bit_iterator *)_6], tmp124
	mov	QWORD PTR 80[rsp], rax	# D.173501, tmp135
	mov	eax, DWORD PTR 88[rsp]	# SR.505, MEM <unsigned int> [(struct _Bit_iterator *)&D.173501 + 8B]
	mov	DWORD PTR 136[rsp], eax	# MEM <unsigned int> [(struct _Bit_iterator *)_6 + 8B], SR.505
# /usr/include/c++/15.2.1/bits/stl_algobase.h:643:     }
	mov	rax, QWORD PTR 128[rsp]	#, MEM[(struct _Bit_iterator *)_6]
	mov	rdx, QWORD PTR 136[rsp]	#, MEM[(struct _Bit_iterator *)_6]
	add	rsp, 152	#,
	.cfi_def_cfa_offset 40
	pop	rbx	#
	.cfi_def_cfa_offset 32
	pop	rbp	#
	.cfi_def_cfa_offset 24
	pop	r12	#
	.cfi_def_cfa_offset 16
	pop	r13	#
	.cfi_def_cfa_offset 8
	ret	
	.cfi_endproc
.LFE13932:
	.size	_ZSt4copyISt19_Bit_const_iteratorSt13_Bit_iteratorET0_T_S3_S2_.isra.0, .-_ZSt4copyISt19_Bit_const_iteratorSt13_Bit_iteratorET0_T_S3_S2_.isra.0
	.section	.text._ZNSt6vectorIbSaIbEE15_M_copy_alignedESt19_Bit_const_iteratorS2_St13_Bit_iterator.isra.0,"axG",@progbits,_ZNSt6vectorIbSaIbEE13_M_insert_auxESt13_Bit_iteratorb,comdat
	.align 2
	.p2align 4
	.type	_ZNSt6vectorIbSaIbEE15_M_copy_alignedESt19_Bit_const_iteratorS2_St13_Bit_iterator.isra.0, @function
_ZNSt6vectorIbSaIbEE15_M_copy_alignedESt19_Bit_const_iteratorS2_St13_Bit_iterator.isra.0:
.LFB13933:
	.cfi_startproc
	push	rbx	#
	.cfi_def_cfa_offset 16
	.cfi_offset 3, -16
	mov	rax, rdx	# __last, __last
	mov	rdx, rcx	# ISRA.1054, ISRA.1054
	mov	rbx, rsi	# __last, __last
	sub	rsp, 96	#,
	.cfi_def_cfa_offset 112
# /usr/include/c++/15.2.1/bits/stl_bvector.h:1544:       _M_copy_aligned(const_iterator __first, const_iterator __last,
	mov	QWORD PTR 16[rsp], rsi	# __last, __last
	mov	QWORD PTR 24[rsp], rax	# __last, __last
	mov	rax, QWORD PTR fs:40	# tmp108, MEM[(<address-space-1> long unsigned int *)40B]
	mov	QWORD PTR 88[rsp], rax	# D.173527, tmp108
	xor	eax, eax	# tmp108
# /usr/include/c++/15.2.1/bits/stl_bvector.h:1547: 	_Bit_type* __q = std::copy(__first._M_p, __last._M_p, __result._M_p);
	call	_ZSt4copyIPmS0_ET0_T_S2_S1_	#
# /usr/include/c++/15.2.1/bits/stl_bvector.h:1549: 			 iterator(__q, 0));
	lea	rdi, 48[rsp]	# tmp109,
	xor	edx, edx	#
	mov	rsi, rax	#, _4
	call	_ZNSt13_Bit_iteratorC1EPmj	#
# /usr/include/c++/15.2.1/bits/stl_bvector.h:1548: 	return std::copy(const_iterator(__last._M_p, 0), __last,
	lea	rdi, 32[rsp]	# tmp110,
	xor	edx, edx	#
	mov	rsi, rbx	#, __last
	call	_ZNSt19_Bit_const_iteratorC1EPmj	#
# /usr/include/c++/15.2.1/bits/stl_bvector.h:1548: 	return std::copy(const_iterator(__last._M_p, 0), __last,
	mov	rdx, QWORD PTR 16[rsp]	#, __last
	mov	r9d, DWORD PTR 56[rsp]	#, MEM <unsigned int> [(struct _Bit_iterator *)&D.173521 + 8B]
	mov	r8, QWORD PTR 48[rsp]	#, MEM <_Bit_type *> [(struct _Bit_iterator *)&D.173521]
	mov	rcx, QWORD PTR 24[rsp]	#, __last
	mov	rdi, QWORD PTR 32[rsp]	#, D.173520
	mov	rsi, QWORD PTR 40[rsp]	#, D.173520
	call	_ZSt4copyISt19_Bit_const_iteratorSt13_Bit_iteratorET0_T_S3_S2_.isra.0	#
	mov	QWORD PTR 64[rsp], rax	# D.173522, tmp124
	mov	QWORD PTR 72[rsp], rdx	# D.173522,
# /usr/include/c++/15.2.1/bits/stl_bvector.h:1550:       }
	mov	rcx, QWORD PTR 88[rsp]	# tmp125, D.173527
	sub	rcx, QWORD PTR fs:40	# tmp125, MEM[(<address-space-1> long unsigned int *)40B]
	jne	.L401	#,
	add	rsp, 96	#,
	.cfi_remember_state
	.cfi_def_cfa_offset 16
	pop	rbx	#
	.cfi_def_cfa_offset 8
	ret	
.L401:
	.cfi_restore_state
	call	[QWORD PTR __stack_chk_fail@GOTPCREL[rip]]	#
	.cfi_endproc
.LFE13933:
	.size	_ZNSt6vectorIbSaIbEE15_M_copy_alignedESt19_Bit_const_iteratorS2_St13_Bit_iterator.isra.0, .-_ZNSt6vectorIbSaIbEE15_M_copy_alignedESt19_Bit_const_iteratorS2_St13_Bit_iterator.isra.0
	.section	.rodata._ZNSt6vectorIbSaIbEE13_M_insert_auxESt13_Bit_iteratorb.str1.1,"aMS",@progbits,1
.LC16:
	.string	"vector<bool>::_M_insert_aux"
	.section	.text._ZNSt6vectorIbSaIbEE13_M_insert_auxESt13_Bit_iteratorb,"axG",@progbits,_ZNSt6vectorIbSaIbEE13_M_insert_auxESt13_Bit_iteratorb,comdat
	.align 2
	.p2align 4
	.weak	_ZNSt6vectorIbSaIbEE13_M_insert_auxESt13_Bit_iteratorb
	.type	_ZNSt6vectorIbSaIbEE13_M_insert_auxESt13_Bit_iteratorb, @function
_ZNSt6vectorIbSaIbEE13_M_insert_auxESt13_Bit_iteratorb:
.LFB13556:
	.cfi_startproc
	push	r13	#
	.cfi_def_cfa_offset 16
	.cfi_offset 13, -16
	push	r12	#
	.cfi_def_cfa_offset 24
	.cfi_offset 12, -24
	push	rbp	#
	.cfi_def_cfa_offset 32
	.cfi_offset 6, -32
# /usr/include/c++/15.2.1/bits/vector.tcc:1263: 	  *__position = __x;
	movzx	ebp, cl	# _2, __x
# /usr/include/c++/15.2.1/bits/vector.tcc:1256:     vector<bool, _Alloc>::
	push	rbx	#
	.cfi_def_cfa_offset 40
	.cfi_offset 3, -40
	mov	rbx, rdi	# this, this
	sub	rsp, 184	#,
	.cfi_def_cfa_offset 224
# /usr/include/c++/15.2.1/bits/vector.tcc:1256:     vector<bool, _Alloc>::
	mov	QWORD PTR 16[rsp], rsi	# __position, __position
	mov	QWORD PTR 24[rsp], rdx	# __position, __position
# /usr/include/c++/15.2.1/bits/vector.tcc:1259:       if (this->_M_impl._M_finish._M_p != this->_M_impl._M_end_addr())
	mov	rdx, QWORD PTR fs:40	# _1, MEM[(<address-space-1> long unsigned int *)40B]
	mov	QWORD PTR 168[rsp], rdx	# D.173534, _1
	mov	rdx, QWORD PTR 16[rdi]	# _1, this_13(D)->D.156758._M_impl.D.156243._M_finish.D.107718._M_p
# /usr/include/c++/15.2.1/bits/vector.tcc:1259:       if (this->_M_impl._M_finish._M_p != this->_M_impl._M_end_addr())
	mov	rdi, QWORD PTR 32[rdi]	# MEM[(long unsigned int * *)this_13(D) + 32B], MEM[(long unsigned int * *)this_13(D) + 32B]
	call	_ZNKSt13_Bvector_baseISaIbEE13_Bvector_impl11_M_end_addrEv.isra.0	#
# /usr/include/c++/15.2.1/bits/vector.tcc:1259:       if (this->_M_impl._M_finish._M_p != this->_M_impl._M_end_addr())
	cmp	rdx, rax	# _1, _3
	je	.L403	#,
# /usr/include/c++/15.2.1/bits/vector.tcc:1261: 	  std::copy_backward(__position, this->_M_impl._M_finish, 
	mov	esi, 1	#,
	lea	rdi, 16[rbx]	#,
	call	_ZStplRKSt13_Bit_iteratorl	#
	movdqu	xmm0, XMMWORD PTR 16[rsp]	# __position, __position
	mov	r13, rax	# tmp188, tmp211
	mov	QWORD PTR 32[rsp], rax	# D.170290, tmp211
	movaps	XMMWORD PTR 48[rsp], xmm0	# __first, __position
	movdqu	xmm0, XMMWORD PTR 16[rbx]	# this_13(D)->D.156758._M_impl.D.156243._M_finish, this_13(D)->D.156758._M_impl.D.156243._M_finish
	mov	QWORD PTR 40[rsp], rdx	# D.170290, tmp212
	movaps	XMMWORD PTR 64[rsp], xmm0	# __last, this_13(D)->D.156758._M_impl.D.156243._M_finish
# /usr/include/c++/15.2.1/bits/stl_algobase.h:847: 	     (std::__miter_base(__first), std::__miter_base(__last), __result);
	mov	rsi, QWORD PTR 72[rsp]	#, __last
	movq	rdi, xmm0	# tmp189, this_13(D)->D.156758._M_impl.D.156243._M_finish
	call	_ZSt12__miter_baseISt13_Bit_iteratorET_S1_	#
# /usr/include/c++/15.2.1/bits/stl_algobase.h:847: 	     (std::__miter_base(__first), std::__miter_base(__last), __result);
	mov	rdi, QWORD PTR 48[rsp]	#, __first
	mov	rsi, QWORD PTR 56[rsp]	#, __first
# /usr/include/c++/15.2.1/bits/stl_algobase.h:847: 	     (std::__miter_base(__first), std::__miter_base(__last), __result);
	mov	QWORD PTR 144[rsp], rax	# MEM[(struct _Bit_iterator *)_7], tmp197
	mov	QWORD PTR 152[rsp], rdx	# MEM[(struct _Bit_iterator *)_7],
# /usr/include/c++/15.2.1/bits/stl_algobase.h:847: 	     (std::__miter_base(__first), std::__miter_base(__last), __result);
	call	_ZSt12__miter_baseISt13_Bit_iteratorET_S1_	#
	mov	QWORD PTR 112[rsp], r13	# MEM <_Bit_type *> [(struct _Bit_iterator *)_82], tmp188
# /usr/include/c++/15.2.1/bits/stl_algobase.h:753:     { return std::__copy_move_backward_a2<_IsMove>(__first, __last, __result); }
	mov	r8, QWORD PTR 112[rsp]	#, MEM[(struct _Bit_iterator *)_82]
# /usr/include/c++/15.2.1/bits/stl_algobase.h:847: 	     (std::__miter_base(__first), std::__miter_base(__last), __result);
	mov	QWORD PTR 128[rsp], rax	# MEM[(struct _Bit_iterator *)_5], tmp198
	mov	rdi, QWORD PTR 128[rsp]	# MEM <_Bit_type *> [(struct _Bit_iterator *)_5], MEM <_Bit_type *> [(struct _Bit_iterator *)_5]
	mov	QWORD PTR 136[rsp], rdx	# MEM[(struct _Bit_iterator *)_5],
	mov	eax, DWORD PTR 136[rsp]	# __first$8, MEM <unsigned int> [(struct _Bit_iterator *)_5 + 8B]
	mov	QWORD PTR 80[rsp], rdi	# MEM <_Bit_type *> [(struct _Bit_iterator *)_80], MEM <_Bit_type *> [(struct _Bit_iterator *)_5]
	mov	DWORD PTR 88[rsp], eax	# MEM <unsigned int> [(struct _Bit_iterator *)_80 + 8B], __first$8
	mov	rax, QWORD PTR 144[rsp]	# __last, MEM <_Bit_type *> [(struct _Bit_iterator *)_7]
# /usr/include/c++/15.2.1/bits/stl_algobase.h:753:     { return std::__copy_move_backward_a2<_IsMove>(__first, __last, __result); }
	mov	rsi, QWORD PTR 88[rsp]	#, MEM[(struct _Bit_iterator *)_80]
	mov	QWORD PTR 96[rsp], rax	# MEM <_Bit_type *> [(struct _Bit_iterator *)_81], __last
	mov	eax, DWORD PTR 152[rsp]	# __last$8, MEM <unsigned int> [(struct _Bit_iterator *)_7 + 8B]
	mov	rdx, QWORD PTR 96[rsp]	#, MEM[(struct _Bit_iterator *)_81]
	mov	DWORD PTR 104[rsp], eax	# MEM <unsigned int> [(struct _Bit_iterator *)_81 + 8B], __last$8
	mov	eax, DWORD PTR 40[rsp]	# __result$8, MEM <unsigned int> [(struct _Bit_iterator *)&D.170290 + 8B]
	mov	rcx, QWORD PTR 104[rsp]	#, MEM[(struct _Bit_iterator *)_81]
	mov	DWORD PTR 120[rsp], eax	# MEM <unsigned int> [(struct _Bit_iterator *)_82 + 8B], __result$8
	mov	r9, QWORD PTR 120[rsp]	#, MEM[(struct _Bit_iterator *)_82]
	call	_ZSt23__copy_move_backward_a2ILb0ESt13_Bit_iteratorS0_ET1_T0_S2_S1_.isra.0	#
# /usr/include/c++/15.2.1/bits/vector.tcc:1263: 	  *__position = __x;
	lea	rdi, 16[rsp]	# tmp148,
	call	_ZNKSt13_Bit_iteratordeEv	#
	mov	rsi, rdx	# D.166978,
# /usr/include/c++/15.2.1/bits/vector.tcc:1263: 	  *__position = __x;
	mov	rdi, rax	#, D.166978
	mov	edx, ebp	#, _2
	call	_ZNSt14_Bit_referenceaSEb.isra.0	#
# /usr/include/c++/15.2.1/bits/vector.tcc:1264: 	  ++this->_M_impl._M_finish;
	lea	rdi, 16[rbx]	#,
	call	_ZNSt13_Bit_iteratorppEv.isra.0	#
.L402:
# /usr/include/c++/15.2.1/bits/vector.tcc:1280:     }
	mov	rax, QWORD PTR 168[rsp]	# tmp213, D.173534
	sub	rax, QWORD PTR fs:40	# tmp213, MEM[(<address-space-1> long unsigned int *)40B]
	jne	.L407	#,
	add	rsp, 184	#,
	.cfi_remember_state
	.cfi_def_cfa_offset 40
	pop	rbx	#
	.cfi_def_cfa_offset 32
	pop	rbp	#
	.cfi_def_cfa_offset 24
	pop	r12	#
	.cfi_def_cfa_offset 16
	pop	r13	#
	.cfi_def_cfa_offset 8
	ret	
	.p2align 4,,10
	.p2align 3
.L403:
	.cfi_restore_state
# /usr/include/c++/15.2.1/bits/vector.tcc:1269: 	    _M_check_len(size_type(1), "vector<bool>::_M_insert_aux");
	lea	rdx, .LC16[rip]	#,
	mov	esi, 1	#,
	mov	rdi, rbx	#, this
	call	_ZNKSt6vectorIbSaIbEE12_M_check_lenEmPKc	#
# /usr/include/c++/15.2.1/bits/vector.tcc:1270: 	  _Bit_pointer __q = this->_M_allocate(__len);
	mov	rdi, rax	#, _17
# /usr/include/c++/15.2.1/bits/vector.tcc:1269: 	    _M_check_len(size_type(1), "vector<bool>::_M_insert_aux");
	mov	r13, rax	# _17,
# /usr/include/c++/15.2.1/bits/vector.tcc:1270: 	  _Bit_pointer __q = this->_M_allocate(__len);
	call	_ZNSt13_Bvector_baseISaIbEE11_M_allocateEm.isra.0	#
# /usr/include/c++/15.2.1/bits/vector.tcc:1271: 	  iterator __start(std::__addressof(*__q), 0);
	xor	edx, edx	#
	lea	rdi, 80[rsp]	# tmp153,
	mov	rsi, rax	#, tmp202
# /usr/include/c++/15.2.1/bits/vector.tcc:1270: 	  _Bit_pointer __q = this->_M_allocate(__len);
	mov	r12, rax	# tmp202,
# /usr/include/c++/15.2.1/bits/vector.tcc:1271: 	  iterator __start(std::__addressof(*__q), 0);
	call	_ZNSt13_Bit_iteratorC1EPmj	#
# /usr/include/c++/15.2.1/bits/vector.tcc:1272: 	  iterator __i = _M_copy_aligned(begin(), __position, __start);
	lea	r8, 144[rsp]	# tmp155,
	lea	rsi, 16[rsp]	# tmp154,
	mov	rdi, r8	#, tmp155
	mov	QWORD PTR 8[rsp], r8	# %sfp, tmp155
	call	_ZNSt19_Bit_const_iteratorC1ERKSt13_Bit_iterator	#
# /usr/include/c++/15.2.1/bits/vector.tcc:1272: 	  iterator __i = _M_copy_aligned(begin(), __position, __start);
	mov	rdi, QWORD PTR [rbx]	# MEM[(_Bit_type * *)this_13(D)], MEM[(_Bit_type * *)this_13(D)]
	call	_ZNSt6vectorIbSaIbEE5beginEv.isra.0	#
# /usr/include/c++/15.2.1/bits/vector.tcc:1272: 	  iterator __i = _M_copy_aligned(begin(), __position, __start);
	lea	rsi, 112[rsp]	# tmp158,
	lea	rdi, 128[rsp]	# tmp159,
# /usr/include/c++/15.2.1/bits/vector.tcc:1272: 	  iterator __i = _M_copy_aligned(begin(), __position, __start);
	mov	QWORD PTR 112[rsp], rax	# MEM[(struct _Bit_iterator *)_82], tmp203
	mov	QWORD PTR 120[rsp], rdx	# MEM[(struct _Bit_iterator *)_82],
# /usr/include/c++/15.2.1/bits/vector.tcc:1272: 	  iterator __i = _M_copy_aligned(begin(), __position, __start);
	call	_ZNSt19_Bit_const_iteratorC1ERKSt13_Bit_iterator	#
# /usr/include/c++/15.2.1/bits/vector.tcc:1272: 	  iterator __i = _M_copy_aligned(begin(), __position, __start);
	mov	rcx, QWORD PTR 80[rsp]	#, MEM[(_Bit_type * *)_80]
	mov	rdx, QWORD PTR 152[rsp]	#, MEM[(struct _Bit_const_iterator *)_7]
	mov	rsi, QWORD PTR 144[rsp]	#, MEM[(struct _Bit_const_iterator *)_7]
	mov	rdi, QWORD PTR 128[rsp]	#, MEM[(_Bit_type * *)_5]
	call	_ZNSt6vectorIbSaIbEE15_M_copy_alignedESt19_Bit_const_iteratorS2_St13_Bit_iterator.isra.0	#
# /usr/include/c++/15.2.1/bits/vector.tcc:1273: 	  *__i++ = __x;
	lea	rdi, 96[rsp]	# tmp165,
# /usr/include/c++/15.2.1/bits/vector.tcc:1272: 	  iterator __i = _M_copy_aligned(begin(), __position, __start);
	mov	QWORD PTR 96[rsp], rax	# MEM[(struct _Bit_iterator *)_81], tmp204
	mov	QWORD PTR 104[rsp], rdx	# MEM[(struct _Bit_iterator *)_81],
# /usr/include/c++/15.2.1/bits/vector.tcc:1273: 	  *__i++ = __x;
	call	_ZNSt13_Bit_iteratorppEi.isra.0	#
# /usr/include/c++/15.2.1/bits/vector.tcc:1273: 	  *__i++ = __x;
	mov	rdi, QWORD PTR 8[rsp]	#, %sfp
# /usr/include/c++/15.2.1/bits/vector.tcc:1273: 	  *__i++ = __x;
	mov	QWORD PTR 144[rsp], rax	# MEM[(struct _Bit_iterator *)_7], tmp205
	mov	QWORD PTR 152[rsp], rdx	# MEM[(struct _Bit_iterator *)_7],
# /usr/include/c++/15.2.1/bits/vector.tcc:1273: 	  *__i++ = __x;
	call	_ZNKSt13_Bit_iteratordeEv	#
# /usr/include/c++/15.2.1/bits/vector.tcc:1273: 	  *__i++ = __x;
	mov	rdi, rax	#, D.166989
# /usr/include/c++/15.2.1/bits/vector.tcc:1273: 	  *__i++ = __x;
	mov	rsi, rdx	# D.166989,
# /usr/include/c++/15.2.1/bits/vector.tcc:1273: 	  *__i++ = __x;
	mov	edx, ebp	#, _2
	call	_ZNSt14_Bit_referenceaSEb.isra.0	#
# /usr/include/c++/15.2.1/bits/vector.tcc:1274: 	  iterator __finish = std::copy(__position, end(), __i);
	mov	rdi, rbx	#, this
	call	_ZNSt6vectorIbSaIbEE3endEv	#
# /usr/include/c++/15.2.1/bits/vector.tcc:1274: 	  iterator __finish = std::copy(__position, end(), __i);
	mov	r9d, DWORD PTR 104[rsp]	#, MEM <unsigned int> [(struct _Bit_iterator *)_81 + 8B]
	mov	r8, QWORD PTR 96[rsp]	#, MEM <_Bit_type *> [(struct _Bit_iterator *)_81]
	mov	rsi, QWORD PTR 24[rsp]	#, __position
	mov	rdi, QWORD PTR 16[rsp]	#, __position
	mov	rcx, rdx	#,
# /usr/include/c++/15.2.1/bits/vector.tcc:1274: 	  iterator __finish = std::copy(__position, end(), __i);
	mov	QWORD PTR 120[rsp], rdx	# MEM[(struct _Bit_iterator *)_82],
# /usr/include/c++/15.2.1/bits/vector.tcc:1274: 	  iterator __finish = std::copy(__position, end(), __i);
	mov	rdx, rax	#, tmp208
# /usr/include/c++/15.2.1/bits/vector.tcc:1274: 	  iterator __finish = std::copy(__position, end(), __i);
	mov	QWORD PTR 112[rsp], rax	# MEM[(struct _Bit_iterator *)_82], tmp208
# /usr/include/c++/15.2.1/bits/vector.tcc:1274: 	  iterator __finish = std::copy(__position, end(), __i);
	call	_ZSt4copyISt13_Bit_iteratorS0_ET0_T_S2_S1_.isra.0	#
# /usr/include/c++/15.2.1/bits/vector.tcc:1275: 	  this->_M_deallocate();
	mov	rdi, rbx	#, this
# /usr/include/c++/15.2.1/bits/vector.tcc:1274: 	  iterator __finish = std::copy(__position, end(), __i);
	mov	QWORD PTR 144[rsp], rax	# MEM[(struct _Bit_iterator *)_7], tmp209
	mov	QWORD PTR 152[rsp], rdx	# MEM[(struct _Bit_iterator *)_7],
# /usr/include/c++/15.2.1/bits/vector.tcc:1275: 	  this->_M_deallocate();
	call	_ZNSt13_Bvector_baseISaIbEE13_M_deallocateEv	#
# /usr/include/c++/15.2.1/bits/vector.tcc:1276: 	  this->_M_impl._M_end_of_storage = __q + _S_nword(__len);
	mov	rdi, r13	#, _17
	call	_ZNSt13_Bvector_baseISaIbEE8_S_nwordEm	#
# /usr/include/c++/15.2.1/bits/vector.tcc:1276: 	  this->_M_impl._M_end_of_storage = __q + _S_nword(__len);
	lea	rax, [r12+rax*8]	# tmp178,
	mov	QWORD PTR 32[rbx], rax	# this_13(D)->D.156758._M_impl.D.156243._M_end_of_storage, tmp178
# /usr/include/c++/15.2.1/bits/vector.tcc:1277: 	  this->_M_impl._M_start = __start;
	mov	rax, QWORD PTR 80[rsp]	# MEM <unsigned char[12]> [(struct _Bit_iterator *)_80], MEM <unsigned char[12]> [(struct _Bit_iterator *)_80]
	mov	QWORD PTR [rbx], rax	# MEM <unsigned char[12]> [(struct _Bit_iterator *)this_13(D)], MEM <unsigned char[12]> [(struct _Bit_iterator *)_80]
	mov	eax, DWORD PTR 88[rsp]	# MEM <unsigned char[12]> [(struct _Bit_iterator *)_80], MEM <unsigned char[12]> [(struct _Bit_iterator *)_80]
	mov	DWORD PTR 8[rbx], eax	# MEM <unsigned char[12]> [(struct _Bit_iterator *)this_13(D)], MEM <unsigned char[12]> [(struct _Bit_iterator *)_80]
# /usr/include/c++/15.2.1/bits/vector.tcc:1278: 	  this->_M_impl._M_finish = __finish;
	mov	rax, QWORD PTR 144[rsp]	# MEM <unsigned char[12]> [(struct _Bit_iterator *)_7], MEM <unsigned char[12]> [(struct _Bit_iterator *)_7]
	mov	QWORD PTR 16[rbx], rax	# MEM <unsigned char[12]> [(struct _Bit_iterator *)this_13(D) + 16B], MEM <unsigned char[12]> [(struct _Bit_iterator *)_7]
	mov	eax, DWORD PTR 152[rsp]	# MEM <unsigned char[12]> [(struct _Bit_iterator *)_7], MEM <unsigned char[12]> [(struct _Bit_iterator *)_7]
	mov	DWORD PTR 24[rbx], eax	# MEM <unsigned char[12]> [(struct _Bit_iterator *)this_13(D) + 16B], MEM <unsigned char[12]> [(struct _Bit_iterator *)_7]
# /usr/include/c++/15.2.1/bits/vector.tcc:1280:     }
	jmp	.L402	#
.L407:
	call	[QWORD PTR __stack_chk_fail@GOTPCREL[rip]]	#
	.cfi_endproc
.LFE13556:
	.size	_ZNSt6vectorIbSaIbEE13_M_insert_auxESt13_Bit_iteratorb, .-_ZNSt6vectorIbSaIbEE13_M_insert_auxESt13_Bit_iteratorb
	.section	.text._ZNSt6vectorIbSaIbEE9push_backEb,"axG",@progbits,_ZNSt6vectorIbSaIbEE9push_backEb,comdat
	.align 2
	.p2align 4
	.weak	_ZNSt6vectorIbSaIbEE9push_backEb
	.type	_ZNSt6vectorIbSaIbEE9push_backEb, @function
_ZNSt6vectorIbSaIbEE9push_backEb:
.LFB13303:
	.cfi_startproc
	push	rbp	#
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
# /usr/include/c++/15.2.1/bits/stl_bvector.h:1250: 	  *this->_M_impl._M_finish++ = __x;
	movzx	ebp, sil	# _2, __x
# /usr/include/c++/15.2.1/bits/stl_bvector.h:1247:       push_back(bool __x)
	push	rbx	#
	.cfi_def_cfa_offset 24
	.cfi_offset 3, -24
	sub	rsp, 40	#,
	.cfi_def_cfa_offset 64
# /usr/include/c++/15.2.1/bits/stl_bvector.h:1249: 	if (this->_M_impl._M_finish._M_p != this->_M_impl._M_end_addr())
	mov	rdx, QWORD PTR 16[rdi]	# _1, this_9(D)->D.156758._M_impl.D.156243._M_finish.D.107718._M_p
# /usr/include/c++/15.2.1/bits/stl_bvector.h:1247:       push_back(bool __x)
	mov	rbx, QWORD PTR fs:40	# this, MEM[(<address-space-1> long unsigned int *)40B]
	mov	QWORD PTR 24[rsp], rbx	# D.173541, this
	mov	rbx, rdi	# this, this
# /usr/include/c++/15.2.1/bits/stl_bvector.h:1249: 	if (this->_M_impl._M_finish._M_p != this->_M_impl._M_end_addr())
	mov	rdi, QWORD PTR 32[rdi]	# MEM[(long unsigned int * *)this_9(D) + 32B], MEM[(long unsigned int * *)this_9(D) + 32B]
	call	_ZNKSt13_Bvector_baseISaIbEE13_Bvector_impl11_M_end_addrEv.isra.0	#
# /usr/include/c++/15.2.1/bits/stl_bvector.h:1249: 	if (this->_M_impl._M_finish._M_p != this->_M_impl._M_end_addr())
	cmp	rdx, rax	# _1, _3
	je	.L409	#,
# /usr/include/c++/15.2.1/bits/stl_bvector.h:1250: 	  *this->_M_impl._M_finish++ = __x;
	lea	rdi, 16[rbx]	# _5,
	call	_ZNSt13_Bit_iteratorppEi.isra.0	#
# /usr/include/c++/15.2.1/bits/stl_bvector.h:1250: 	  *this->_M_impl._M_finish++ = __x;
	mov	rdi, rsp	# tmp114,
# /usr/include/c++/15.2.1/bits/stl_bvector.h:1250: 	  *this->_M_impl._M_finish++ = __x;
	mov	QWORD PTR [rsp], rax	# MEM[(struct _Bit_iterator *)_6], tmp128
	mov	QWORD PTR 8[rsp], rdx	# MEM[(struct _Bit_iterator *)_6],
# /usr/include/c++/15.2.1/bits/stl_bvector.h:1250: 	  *this->_M_impl._M_finish++ = __x;
	call	_ZNKSt13_Bit_iteratordeEv	#
	mov	rsi, rdx	# D.164637,
# /usr/include/c++/15.2.1/bits/stl_bvector.h:1250: 	  *this->_M_impl._M_finish++ = __x;
	mov	rdx, QWORD PTR 24[rsp]	# tmp132, D.173541
	sub	rdx, QWORD PTR fs:40	# tmp132, MEM[(<address-space-1> long unsigned int *)40B]
	jne	.L414	#,
# /usr/include/c++/15.2.1/bits/stl_bvector.h:1253:       }
	add	rsp, 40	#,
	.cfi_remember_state
	.cfi_def_cfa_offset 24
# /usr/include/c++/15.2.1/bits/stl_bvector.h:1250: 	  *this->_M_impl._M_finish++ = __x;
	mov	edx, ebp	#, _2
	mov	rdi, rax	#, D.164637
# /usr/include/c++/15.2.1/bits/stl_bvector.h:1253:       }
	pop	rbx	#
	.cfi_def_cfa_offset 16
	pop	rbp	#
	.cfi_def_cfa_offset 8
# /usr/include/c++/15.2.1/bits/stl_bvector.h:1250: 	  *this->_M_impl._M_finish++ = __x;
	jmp	_ZNSt14_Bit_referenceaSEb.isra.0	#
	.p2align 4,,10
	.p2align 3
.L409:
	.cfi_restore_state
# /usr/include/c++/15.2.1/bits/stl_bvector.h:1252: 	  _M_insert_aux(end(), __x);
	mov	rdi, rbx	#, this
	call	_ZNSt6vectorIbSaIbEE3endEv	#
	mov	QWORD PTR [rsp], rax	# MEM[(struct _Bit_iterator *)_6], tmp131
	mov	QWORD PTR 8[rsp], rdx	# MEM[(struct _Bit_iterator *)_6],
# /usr/include/c++/15.2.1/bits/stl_bvector.h:1252: 	  _M_insert_aux(end(), __x);
	mov	rax, QWORD PTR 24[rsp]	# tmp133, D.173541
	sub	rax, QWORD PTR fs:40	# tmp133, MEM[(<address-space-1> long unsigned int *)40B]
	jne	.L414	#,
	mov	rsi, QWORD PTR [rsp]	#, MEM[(struct _Bit_iterator *)_6]
	mov	rdx, QWORD PTR 8[rsp]	#, MEM[(struct _Bit_iterator *)_6]
# /usr/include/c++/15.2.1/bits/stl_bvector.h:1253:       }
	add	rsp, 40	#,
	.cfi_remember_state
	.cfi_def_cfa_offset 24
# /usr/include/c++/15.2.1/bits/stl_bvector.h:1252: 	  _M_insert_aux(end(), __x);
	mov	ecx, ebp	#, _2
	mov	rdi, rbx	#, this
# /usr/include/c++/15.2.1/bits/stl_bvector.h:1253:       }
	pop	rbx	#
	.cfi_def_cfa_offset 16
	pop	rbp	#
	.cfi_def_cfa_offset 8
# /usr/include/c++/15.2.1/bits/stl_bvector.h:1252: 	  _M_insert_aux(end(), __x);
	jmp	_ZNSt6vectorIbSaIbEE13_M_insert_auxESt13_Bit_iteratorb	#
.L414:
	.cfi_restore_state
	call	[QWORD PTR __stack_chk_fail@GOTPCREL[rip]]	#
	.cfi_endproc
.LFE13303:
	.size	_ZNSt6vectorIbSaIbEE9push_backEb, .-_ZNSt6vectorIbSaIbEE9push_backEb
	.section	.text._ZN6ButtonC2EOS_,"axG",@progbits,_ZN6ButtonC5EOS_,comdat
	.align 2
	.p2align 4
	.weak	_ZN6ButtonC2EOS_
	.type	_ZN6ButtonC2EOS_, @function
_ZN6ButtonC2EOS_:
.LFB13881:
	.cfi_startproc
	push	rbp	#
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	mov	rbp, rsi	# D.156905, D.156905
	lea	rsi, 16[rsi]	# _2,
	push	rbx	#
	.cfi_def_cfa_offset 24
	.cfi_offset 3, -24
	mov	rbx, rdi	# this, this
	lea	rdi, 16[rdi]	# _1,
	sub	rsp, 8	#,
	.cfi_def_cfa_offset 32
# ../ui/ui.h:19: struct Button {
	movdqu	xmm0, XMMWORD PTR -16[rsi]	# *_9(D).rect, *_9(D).rect
	movups	XMMWORD PTR -16[rdi], xmm0	# *this_7(D).rect, *_9(D).rect
	call	[QWORD PTR _ZNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEEC1EOS4_@GOTPCREL[rip]]	#
# ../ui/ui.h:19: struct Button {
	movzx	eax, WORD PTR 48[rbp]	# MEM <vector(2) unsigned char> [(bool *)_9(D) + 48B], MEM <vector(2) unsigned char> [(bool *)_9(D) + 48B]
	mov	WORD PTR 48[rbx], ax	# MEM <vector(2) unsigned char> [(bool *)this_7(D) + 48B], MEM <vector(2) unsigned char> [(bool *)_9(D) + 48B]
# ../ui/ui.h:19: struct Button {
	add	rsp, 8	#,
	.cfi_def_cfa_offset 24
	pop	rbx	#
	.cfi_def_cfa_offset 16
	pop	rbp	#
	.cfi_def_cfa_offset 8
	ret	
	.cfi_endproc
.LFE13881:
	.size	_ZN6ButtonC2EOS_, .-_ZN6ButtonC2EOS_
	.weak	_ZN6ButtonC1EOS_
	.set	_ZN6ButtonC1EOS_,_ZN6ButtonC2EOS_
	.text
	.p2align 4
	.type	_ZSt19__relocate_object_aI6ButtonS0_SaIS0_EEvPT_PT0_RT1_.isra.0, @function
_ZSt19__relocate_object_aI6ButtonS0_SaIS0_EEvPT_PT0_RT1_.isra.0:
.LFB13934:
	.cfi_startproc
	push	rbx	#
	.cfi_def_cfa_offset 16
	.cfi_offset 3, -16
# /usr/include/c++/15.2.1/bits/stl_uninitialized.h:1280:     __relocate_object_a(_Tp* __restrict __dest, _Up* __restrict __orig,
	mov	rbx, rsi	# __orig, __orig
# /usr/include/c++/15.2.1/bits/new_allocator.h:191: 	{ ::new((void *)__p) _Up(std::forward<_Args>(__args)...); }
	call	_ZnwmPv.isra.0	#
# /usr/include/c++/15.2.1/bits/new_allocator.h:191: 	{ ::new((void *)__p) _Up(std::forward<_Args>(__args)...); }
	mov	rdi, rax	#, _2
	call	_ZN6ButtonC1EOS_	#
# /usr/include/c++/15.2.1/bits/new_allocator.h:198: 	{ __p->~_Up(); }
	mov	rdi, rbx	#, __orig
# /usr/include/c++/15.2.1/bits/stl_uninitialized.h:1290:     }
	pop	rbx	#
	.cfi_def_cfa_offset 8
# /usr/include/c++/15.2.1/bits/new_allocator.h:198: 	{ __p->~_Up(); }
	jmp	_ZN6ButtonD1Ev	#
	.cfi_endproc
.LFE13934:
	.size	_ZSt19__relocate_object_aI6ButtonS0_SaIS0_EEvPT_PT0_RT1_.isra.0, .-_ZSt19__relocate_object_aI6ButtonS0_SaIS0_EEvPT_PT0_RT1_.isra.0
	.p2align 4
	.type	_ZSt14__relocate_a_1IP6ButtonS1_SaIS0_EET0_T_S4_S3_RT1_.isra.0, @function
_ZSt14__relocate_a_1IP6ButtonS1_SaIS0_EET0_T_S4_S3_RT1_.isra.0:
.LFB13935:
	.cfi_startproc
	push	r12	#
	.cfi_def_cfa_offset 16
	.cfi_offset 12, -16
	push	rbp	#
	.cfi_def_cfa_offset 24
	.cfi_offset 6, -24
	mov	rbp, rdx	# __result, __result
	push	rbx	#
	.cfi_def_cfa_offset 32
	.cfi_offset 3, -32
# /usr/include/c++/15.2.1/bits/stl_uninitialized.h:1316:       for (; __first != __last; ++__first, (void)++__cur)
	cmp	rsi, rdi	# __last, __first
	je	.L420	#,
	mov	rbx, rdi	# __first, __first
	mov	r12, rsi	# __last, __last
	.p2align 4
	.p2align 3
.L421:
# /usr/include/c++/15.2.1/bits/stl_uninitialized.h:1317: 	std::__relocate_object_a(std::__addressof(*__cur),
	mov	rsi, rbx	#, __first
	mov	rdi, rbp	#, __result
# /usr/include/c++/15.2.1/bits/stl_uninitialized.h:1316:       for (; __first != __last; ++__first, (void)++__cur)
	add	rbx, 56	# __first,
# /usr/include/c++/15.2.1/bits/stl_uninitialized.h:1316:       for (; __first != __last; ++__first, (void)++__cur)
	add	rbp, 56	# __result,
# /usr/include/c++/15.2.1/bits/stl_uninitialized.h:1317: 	std::__relocate_object_a(std::__addressof(*__cur),
	call	_ZSt19__relocate_object_aI6ButtonS0_SaIS0_EEvPT_PT0_RT1_.isra.0	#
# /usr/include/c++/15.2.1/bits/stl_uninitialized.h:1316:       for (; __first != __last; ++__first, (void)++__cur)
	cmp	rbx, r12	# __first, __last
	jne	.L421	#,
.L420:
# /usr/include/c++/15.2.1/bits/stl_uninitialized.h:1320:     }
	mov	rax, rbp	#, __result
	pop	rbx	#
	.cfi_def_cfa_offset 24
	pop	rbp	#
	.cfi_def_cfa_offset 16
	pop	r12	#
	.cfi_def_cfa_offset 8
	ret	
	.cfi_endproc
.LFE13935:
	.size	_ZSt14__relocate_a_1IP6ButtonS1_SaIS0_EET0_T_S4_S3_RT1_.isra.0, .-_ZSt14__relocate_a_1IP6ButtonS1_SaIS0_EET0_T_S4_S3_RT1_.isra.0
	.p2align 4
	.type	_ZSt12__relocate_aIP6ButtonS1_SaIS0_EET0_T_S4_S3_RT1_.isra.0, @function
_ZSt12__relocate_aIP6ButtonS1_SaIS0_EET0_T_S4_S3_RT1_.isra.0:
.LFB13936:
	.cfi_startproc
# /usr/include/c++/15.2.1/bits/stl_uninitialized.h:1359:       return std::__relocate_a_1(std::__niter_base(__first),
	jmp	_ZSt14__relocate_a_1IP6ButtonS1_SaIS0_EET0_T_S4_S3_RT1_.isra.0	#
	.cfi_endproc
.LFE13936:
	.size	_ZSt12__relocate_aIP6ButtonS1_SaIS0_EET0_T_S4_S3_RT1_.isra.0, .-_ZSt12__relocate_aIP6ButtonS1_SaIS0_EET0_T_S4_S3_RT1_.isra.0
	.p2align 4
	.type	_ZNSt6vectorI6ButtonSaIS0_EE11_S_relocateEPS0_S3_S3_RS1_.isra.0, @function
_ZNSt6vectorI6ButtonSaIS0_EE11_S_relocateEPS0_S3_S3_RS1_.isra.0:
.LFB13937:
	.cfi_startproc
# /usr/include/c++/15.2.1/bits/stl_vector.h:539: 	return std::__relocate_a(__first, __last, __result, __alloc);
	jmp	_ZSt12__relocate_aIP6ButtonS1_SaIS0_EET0_T_S4_S3_RT1_.isra.0	#
	.cfi_endproc
.LFE13937:
	.size	_ZNSt6vectorI6ButtonSaIS0_EE11_S_relocateEPS0_S3_S3_RS1_.isra.0, .-_ZNSt6vectorI6ButtonSaIS0_EE11_S_relocateEPS0_S3_S3_RS1_.isra.0
	.section	.rodata._ZNSt6vectorI6ButtonSaIS0_EE17_M_realloc_appendIJiRKiS5_S5_RA2_KcEEEvDpOT_.str1.1,"aMS",@progbits,1
.LC17:
	.string	"vector::_M_realloc_append"
	.section	.text._ZNSt6vectorI6ButtonSaIS0_EE17_M_realloc_appendIJiRKiS5_S5_RA2_KcEEEvDpOT_,"axG",@progbits,_ZNSt6vectorI6ButtonSaIS0_EE17_M_realloc_appendIJiRKiS5_S5_RA2_KcEEEvDpOT_,comdat
	.align 2
	.p2align 4
	.weak	_ZNSt6vectorI6ButtonSaIS0_EE17_M_realloc_appendIJiRKiS5_S5_RA2_KcEEEvDpOT_
	.type	_ZNSt6vectorI6ButtonSaIS0_EE17_M_realloc_appendIJiRKiS5_S5_RA2_KcEEEvDpOT_, @function
_ZNSt6vectorI6ButtonSaIS0_EE17_M_realloc_appendIJiRKiS5_S5_RA2_KcEEEvDpOT_:
.LFB13560:
	.cfi_startproc
	.cfi_personality 0x9b,DW.ref.__gxx_personality_v0
	.cfi_lsda 0x1b,.LLSDA13560
	push	r15	#
	.cfi_def_cfa_offset 16
	.cfi_offset 15, -16
	push	r14	#
	.cfi_def_cfa_offset 24
	.cfi_offset 14, -24
	push	r13	#
	.cfi_def_cfa_offset 32
	.cfi_offset 13, -32
	push	r12	#
	.cfi_def_cfa_offset 40
	.cfi_offset 12, -40
	push	rbp	#
	.cfi_def_cfa_offset 48
	.cfi_offset 6, -48
	push	rbx	#
	.cfi_def_cfa_offset 56
	.cfi_offset 3, -56
	mov	rbx, rdi	# this, this
	sub	rsp, 168	#,
	.cfi_def_cfa_offset 224
# /usr/include/c++/15.2.1/bits/vector.tcc:557:       vector<_Tp, _Alloc>::
	mov	QWORD PTR 32[rsp], rcx	# %sfp, __args#2
	mov	QWORD PTR 56[rsp], r8	# %sfp, __args#3
	mov	QWORD PTR 48[rsp], r9	# %sfp, __args#4
	mov	QWORD PTR 16[rsp], rsi	# %sfp, __args#0
# /usr/include/c++/15.2.1/bits/vector.tcc:566:       const size_type __len = _M_check_len(1u, "vector::_M_realloc_append");
	mov	esi, 1	#,
# /usr/include/c++/15.2.1/bits/vector.tcc:557:       vector<_Tp, _Alloc>::
	mov	QWORD PTR 24[rsp], rdx	# %sfp, __args#1
# /usr/include/c++/15.2.1/bits/vector.tcc:566:       const size_type __len = _M_check_len(1u, "vector::_M_realloc_append");
	mov	rdx, QWORD PTR fs:40	#, MEM[(<address-space-1> long unsigned int *)40B]
	mov	QWORD PTR 152[rsp], rdx	# D.173612,
	lea	rdx, .LC17[rip]	#,
.LEHB15:
	call	_ZNKSt6vectorI6ButtonSaIS0_EE12_M_check_lenEmPKc	#
# /usr/include/c++/15.2.1/bits/vector.tcc:571:       const size_type __elems = end() - begin();
	mov	rdi, rbx	#, this
# /usr/include/c++/15.2.1/bits/vector.tcc:569:       pointer __old_start = this->_M_impl._M_start;
	mov	r14, QWORD PTR [rbx]	# __old_start, this_12(D)->D.155608._M_impl.D.154943._M_start
# /usr/include/c++/15.2.1/bits/vector.tcc:566:       const size_type __len = _M_check_len(1u, "vector::_M_realloc_append");
	mov	r12, rax	# _14,
# /usr/include/c++/15.2.1/bits/vector.tcc:570:       pointer __old_finish = this->_M_impl._M_finish;
	mov	rax, QWORD PTR 8[rbx]	# __old_finish, this_12(D)->D.155608._M_impl.D.154943._M_finish
	mov	QWORD PTR 8[rsp], rax	# %sfp, __old_finish
# /usr/include/c++/15.2.1/bits/vector.tcc:571:       const size_type __elems = end() - begin();
	call	_ZNSt6vectorI6ButtonSaIS0_EE5beginEv	#
# /usr/include/c++/15.2.1/bits/vector.tcc:571:       const size_type __elems = end() - begin();
	mov	rdi, rbx	#, this
# /usr/include/c++/15.2.1/bits/vector.tcc:571:       const size_type __elems = end() - begin();
	mov	rbp, rax	# D.167020,
# /usr/include/c++/15.2.1/bits/vector.tcc:571:       const size_type __elems = end() - begin();
	call	_ZNSt6vectorI6ButtonSaIS0_EE3endEv	#
# /usr/include/c++/15.2.1/bits/vector.tcc:572:       pointer __new_start(this->_M_allocate(__len));
	mov	rdi, r12	#, _14
# /usr/include/c++/15.2.1/bits/stl_iterator.h:1340:     { return __lhs.base() - __rhs.base(); }
	sub	rax, rbp	# D.167019, D.167020
	mov	r13, rax	# _19, D.167019
# /usr/include/c++/15.2.1/bits/vector.tcc:572:       pointer __new_start(this->_M_allocate(__len));
	call	_ZNSt12_Vector_baseI6ButtonSaIS0_EE11_M_allocateEm.isra.0	#
.LEHE15:
# /usr/include/c++/15.2.1/bits/vector.tcc:576: 	_Guard_alloc __guard(__new_start, __len, *this);
	mov	rdx, r12	#, _14
	lea	rdi, 80[rsp]	#,
	mov	rcx, rbx	#, this
# /usr/include/c++/15.2.1/bits/vector.tcc:572:       pointer __new_start(this->_M_allocate(__len));
	mov	rbp, rax	# _23,
# /usr/include/c++/15.2.1/bits/vector.tcc:576: 	_Guard_alloc __guard(__new_start, __len, *this);
	mov	rsi, rax	#, _23
	call	_ZNSt6vectorI6ButtonSaIS0_EE12_Guard_allocC1EPS0_mRSt12_Vector_baseIS0_S1_E	#
# /usr/include/c++/15.2.1/bits/vector.tcc:586: 	_Alloc_traits::construct(this->_M_impl,
	lea	rdi, 0[rbp+r13]	# _3,
# /usr/include/c++/15.2.1/bits/new_allocator.h:191: 	{ ::new((void *)__p) _Up(std::forward<_Args>(__args)...); }
	lea	rdx, 79[rsp]	# tmp136,
# /usr/include/c++/15.2.1/bits/new_allocator.h:191: 	{ ::new((void *)__p) _Up(std::forward<_Args>(__args)...); }
	call	_ZnwmPv.isra.0	#
# /usr/include/c++/15.2.1/bits/new_allocator.h:191: 	{ ::new((void *)__p) _Up(std::forward<_Args>(__args)...); }
	mov	rsi, QWORD PTR 48[rsp]	#, %sfp
	lea	rdi, 112[rsp]	#,
# /usr/include/c++/15.2.1/bits/new_allocator.h:191: 	{ ::new((void *)__p) _Up(std::forward<_Args>(__args)...); }
	mov	QWORD PTR 40[rsp], rax	# %sfp,
.LEHB16:
# /usr/include/c++/15.2.1/bits/new_allocator.h:191: 	{ ::new((void *)__p) _Up(std::forward<_Args>(__args)...); }
	call	_ZNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEEC1IS3_EEPKcRKS3_	#
.LEHE16:
# /usr/include/c++/15.2.1/bits/new_allocator.h:191: 	{ ::new((void *)__p) _Up(std::forward<_Args>(__args)...); }
	mov	rcx, QWORD PTR 32[rsp]	# __args#2, %sfp
	mov	rdx, QWORD PTR 24[rsp]	# __args#1, %sfp
	lea	r9, 112[rsp]	#,
	mov	r10, QWORD PTR 16[rsp]	# __args#0, %sfp
	mov	r8, QWORD PTR 56[rsp]	# __args#3, %sfp
	mov	ecx, DWORD PTR [rcx]	# *__args#2_29(D), *__args#2_29(D)
	mov	edx, DWORD PTR [rdx]	# *__args#1_31(D), *__args#1_31(D)
	mov	esi, DWORD PTR [r10]	# *__args#0_33(D), *__args#0_33(D)
	mov	r8d, DWORD PTR [r8]	#, *__args#3_27(D)
	mov	rdi, QWORD PTR 40[rsp]	#, %sfp
.LEHB17:
	call	[QWORD PTR _ZN6ButtonC1EiiiiRKNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEEE@GOTPCREL[rip]]	#
.LEHE17:
# /usr/include/c++/15.2.1/bits/vector.tcc:646:       this->_M_impl._M_end_of_storage = __new_start + __len;
	imul	r12, r12, 56	# _9, _14,
# /usr/include/c++/15.2.1/bits/new_allocator.h:191: 	{ ::new((void *)__p) _Up(std::forward<_Args>(__args)...); }
	lea	rdi, 112[rsp]	#,
	call	[QWORD PTR _ZNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEED1Ev@GOTPCREL[rip]]	#
# /usr/include/c++/15.2.1/bits/vector.tcc:599: 	    __new_finish = _S_relocate(__old_start, __old_finish,
	mov	rsi, QWORD PTR 8[rsp]	#, %sfp
	mov	rdx, rbp	#, _23
	mov	rdi, r14	#, __old_start
	call	_ZNSt6vectorI6ButtonSaIS0_EE11_S_relocateEPS0_S3_S3_RS1_.isra.0	#
# /usr/include/c++/15.2.1/bits/vector.tcc:640:       }
	lea	rdi, 80[rsp]	#,
# /usr/include/c++/15.2.1/bits/vector.tcc:638: 	__guard._M_storage = __old_start;
	mov	QWORD PTR 80[rsp], r14	# __guard._M_storage, __old_start
# /usr/include/c++/15.2.1/bits/vector.tcc:639: 	__guard._M_len = this->_M_impl._M_end_of_storage - __old_start;
	movabs	rdx, 7905747460161236407	# tmp148,
# /usr/include/c++/15.2.1/bits/vector.tcc:599: 	    __new_finish = _S_relocate(__old_start, __old_finish,
	mov	r13, rax	# __new_finish,
# /usr/include/c++/15.2.1/bits/vector.tcc:639: 	__guard._M_len = this->_M_impl._M_end_of_storage - __old_start;
	mov	rax, QWORD PTR 16[rbx]	# _6, this_12(D)->D.155608._M_impl.D.154943._M_end_of_storage
# /usr/include/c++/15.2.1/bits/vector.tcc:601: 	    ++__new_finish;
	add	r13, 56	# tmp150,
# /usr/include/c++/15.2.1/bits/vector.tcc:639: 	__guard._M_len = this->_M_impl._M_end_of_storage - __old_start;
	sub	rax, r14	# _6, __old_start
	sar	rax, 3	# tmp146,
	imul	rax, rdx	# _7, tmp148
# /usr/include/c++/15.2.1/bits/vector.tcc:639: 	__guard._M_len = this->_M_impl._M_end_of_storage - __old_start;
	mov	QWORD PTR 88[rsp], rax	# __guard._M_len, _7
# /usr/include/c++/15.2.1/bits/vector.tcc:640:       }
	call	_ZNSt6vectorI6ButtonSaIS0_EE12_Guard_allocD1Ev	#
# /usr/include/c++/15.2.1/bits/vector.tcc:644:       this->_M_impl._M_start = __new_start;
	mov	QWORD PTR [rbx], rbp	# this_12(D)->D.155608._M_impl.D.154943._M_start, _23
# /usr/include/c++/15.2.1/bits/vector.tcc:646:       this->_M_impl._M_end_of_storage = __new_start + __len;
	add	rbp, r12	# tmp152, _9
# /usr/include/c++/15.2.1/bits/vector.tcc:601: 	    ++__new_finish;
	mov	QWORD PTR 8[rbx], r13	# this_12(D)->D.155608._M_impl.D.154943._M_finish, tmp150
# /usr/include/c++/15.2.1/bits/vector.tcc:646:       this->_M_impl._M_end_of_storage = __new_start + __len;
	mov	QWORD PTR 16[rbx], rbp	# this_12(D)->D.155608._M_impl.D.154943._M_end_of_storage, tmp152
# /usr/include/c++/15.2.1/bits/vector.tcc:647:     }
	mov	rax, QWORD PTR 152[rsp]	# tmp177, D.173612
	sub	rax, QWORD PTR fs:40	# tmp177, MEM[(<address-space-1> long unsigned int *)40B]
	jne	.L433	#,
	add	rsp, 168	#,
	.cfi_remember_state
	.cfi_def_cfa_offset 56
	pop	rbx	#
	.cfi_def_cfa_offset 48
	pop	rbp	#
	.cfi_def_cfa_offset 40
	pop	r12	#
	.cfi_def_cfa_offset 32
	pop	r13	#
	.cfi_def_cfa_offset 24
	pop	r14	#
	.cfi_def_cfa_offset 16
	pop	r15	#
	.cfi_def_cfa_offset 8
	ret	
.L427:
	.cfi_restore_state
# /usr/include/c++/15.2.1/bits/new_allocator.h:191: 	{ ::new((void *)__p) _Up(std::forward<_Args>(__args)...); }
	lea	rdi, 112[rsp]	#,
	call	[QWORD PTR _ZNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEED1Ev@GOTPCREL[rip]]	#
.L428:
# /usr/include/c++/15.2.1/bits/vector.tcc:640:       }
	lea	rdi, 80[rsp]	#,
	call	_ZNSt6vectorI6ButtonSaIS0_EE12_Guard_allocD1Ev	#
	mov	rax, QWORD PTR 152[rsp]	# tmp178, D.173612
	sub	rax, QWORD PTR fs:40	# tmp178, MEM[(<address-space-1> long unsigned int *)40B]
	je	.L429	#,
.L433:
# /usr/include/c++/15.2.1/bits/vector.tcc:647:     }
	call	[QWORD PTR __stack_chk_fail@GOTPCREL[rip]]	#
.L432:
# /usr/include/c++/15.2.1/bits/new_allocator.h:191: 	{ ::new((void *)__p) _Up(std::forward<_Args>(__args)...); }
	mov	rbx, rax	# tmp175,
	jmp	.L427	#
.L431:
# /usr/include/c++/15.2.1/bits/vector.tcc:640:       }
	mov	rbx, rax	# tmp154, tmp176
	jmp	.L428	#
.L429:
	mov	rdi, rbx	#, tmp154
.LEHB18:
	call	[QWORD PTR _Unwind_Resume@GOTPCREL[rip]]	#
.LEHE18:
	.cfi_endproc
.LFE13560:
	.section	.gcc_except_table
.LLSDA13560:
	.byte	0xff
	.byte	0xff
	.byte	0x1
	.uleb128 .LLSDACSE13560-.LLSDACSB13560
.LLSDACSB13560:
	.uleb128 .LEHB15-.LFB13560
	.uleb128 .LEHE15-.LEHB15
	.uleb128 0
	.uleb128 0
	.uleb128 .LEHB16-.LFB13560
	.uleb128 .LEHE16-.LEHB16
	.uleb128 .L431-.LFB13560
	.uleb128 0
	.uleb128 .LEHB17-.LFB13560
	.uleb128 .LEHE17-.LEHB17
	.uleb128 .L432-.LFB13560
	.uleb128 0
	.uleb128 .LEHB18-.LFB13560
	.uleb128 .LEHE18-.LEHB18
	.uleb128 0
	.uleb128 0
.LLSDACSE13560:
	.section	.text._ZNSt6vectorI6ButtonSaIS0_EE17_M_realloc_appendIJiRKiS5_S5_RA2_KcEEEvDpOT_,"axG",@progbits,_ZNSt6vectorI6ButtonSaIS0_EE17_M_realloc_appendIJiRKiS5_S5_RA2_KcEEEvDpOT_,comdat
	.size	_ZNSt6vectorI6ButtonSaIS0_EE17_M_realloc_appendIJiRKiS5_S5_RA2_KcEEEvDpOT_, .-_ZNSt6vectorI6ButtonSaIS0_EE17_M_realloc_appendIJiRKiS5_S5_RA2_KcEEEvDpOT_
	.section	.text.unlikely
	.align 2
.LCOLDB18:
	.text
.LHOTB18:
	.align 2
	.p2align 4
	.type	_ZNSt6vectorI6ButtonSaIS0_EE12emplace_backIJiRKiS5_S5_RA2_KcEEERS0_DpOT_.isra.0, @function
_ZNSt6vectorI6ButtonSaIS0_EE12emplace_backIJiRKiS5_S5_RA2_KcEEERS0_DpOT_.isra.0:
.LFB13938:
	.cfi_startproc
	.cfi_personality 0x9b,DW.ref.__gxx_personality_v0
	.cfi_lsda 0x1b,.LLSDA13938
	push	r14	#
	.cfi_def_cfa_offset 16
	.cfi_offset 14, -16
	push	r13	#
	.cfi_def_cfa_offset 24
	.cfi_offset 13, -24
	push	r12	#
	.cfi_def_cfa_offset 32
	.cfi_offset 12, -32
	mov	r12, rsi	# __args#0, __args#0
	push	rbp	#
	.cfi_def_cfa_offset 40
	.cfi_offset 6, -40
	push	rbx	#
	.cfi_def_cfa_offset 48
	.cfi_offset 3, -48
	mov	rbx, rdi	# this, this
	sub	rsp, 80	#,
	.cfi_def_cfa_offset 128
# /usr/include/c++/15.2.1/bits/vector.tcc:114: 	if (this->_M_impl._M_finish != this->_M_impl._M_end_of_storage)
	mov	rdi, QWORD PTR 8[rdi]	# _2, this_1(D)->D.155608._M_impl.D.154943._M_finish
# /usr/include/c++/15.2.1/bits/vector.tcc:111:       vector<_Tp, _Alloc>::
	mov	r13, QWORD PTR fs:40	# __args#1, MEM[(<address-space-1> long unsigned int *)40B]
	mov	QWORD PTR 72[rsp], r13	# D.173630, __args#1
	mov	r13, rdx	# __args#1, __args#1
# /usr/include/c++/15.2.1/bits/vector.tcc:114: 	if (this->_M_impl._M_finish != this->_M_impl._M_end_of_storage)
	cmp	rdi, QWORD PTR 16[rbx]	# _2, this_1(D)->D.155608._M_impl.D.154943._M_end_of_storage
	je	.L436	#,
# /usr/include/c++/15.2.1/bits/new_allocator.h:191: 	{ ::new((void *)__p) _Up(std::forward<_Args>(__args)...); }
	lea	rbp, 32[rsp]	# tmp129,
	mov	QWORD PTR 8[rsp], r8	# %sfp, __args#3
	mov	rsi, r9	#, __args#4
	lea	rdx, 31[rsp]	# tmp116,
	mov	QWORD PTR [rsp], rcx	# %sfp, __args#2
# /usr/include/c++/15.2.1/bits/new_allocator.h:191: 	{ ::new((void *)__p) _Up(std::forward<_Args>(__args)...); }
	call	_ZnwmPv.isra.0	#
# /usr/include/c++/15.2.1/bits/new_allocator.h:191: 	{ ::new((void *)__p) _Up(std::forward<_Args>(__args)...); }
	mov	rdi, rbp	#, tmp129
# /usr/include/c++/15.2.1/bits/new_allocator.h:191: 	{ ::new((void *)__p) _Up(std::forward<_Args>(__args)...); }
	mov	r14, rax	# _4,
.LEHB19:
# /usr/include/c++/15.2.1/bits/new_allocator.h:191: 	{ ::new((void *)__p) _Up(std::forward<_Args>(__args)...); }
	call	_ZNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEEC1IS3_EEPKcRKS3_	#
.LEHE19:
# /usr/include/c++/15.2.1/bits/new_allocator.h:191: 	{ ::new((void *)__p) _Up(std::forward<_Args>(__args)...); }
	mov	rcx, QWORD PTR [rsp]	# __args#2, %sfp
	mov	edx, DWORD PTR 0[r13]	# *__args#1_10(D), *__args#1_10(D)
	mov	r9, rbp	#, tmp129
	mov	r8, QWORD PTR 8[rsp]	# __args#3, %sfp
	mov	esi, DWORD PTR [r12]	# *__args#0_12(D), *__args#0_12(D)
	mov	rdi, r14	#, _4
	mov	ecx, DWORD PTR [rcx]	# *__args#2_8(D), *__args#2_8(D)
	mov	r8d, DWORD PTR [r8]	#, *__args#3_6(D)
.LEHB20:
	call	[QWORD PTR _ZN6ButtonC1EiiiiRKNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEEE@GOTPCREL[rip]]	#
.LEHE20:
# /usr/include/c++/15.2.1/bits/new_allocator.h:191: 	{ ::new((void *)__p) _Up(std::forward<_Args>(__args)...); }
	mov	rdi, rbp	#, tmp129
	call	[QWORD PTR _ZNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEED1Ev@GOTPCREL[rip]]	#
# /usr/include/c++/15.2.1/bits/vector.tcc:119: 	    ++this->_M_impl._M_finish;
	add	QWORD PTR 8[rbx], 56	# this_1(D)->D.155608._M_impl.D.154943._M_finish,
# /usr/include/c++/15.2.1/bits/vector.tcc:127:       }
	mov	rax, QWORD PTR 72[rsp]	# tmp138, D.173630
	sub	rax, QWORD PTR fs:40	# tmp138, MEM[(<address-space-1> long unsigned int *)40B]
	jne	.L443	#,
	add	rsp, 80	#,
	.cfi_remember_state
	.cfi_def_cfa_offset 48
	pop	rbx	#
	.cfi_def_cfa_offset 40
	pop	rbp	#
	.cfi_def_cfa_offset 32
	pop	r12	#
	.cfi_def_cfa_offset 24
	pop	r13	#
	.cfi_def_cfa_offset 16
	pop	r14	#
	.cfi_def_cfa_offset 8
	ret	
	.p2align 4,,10
	.p2align 3
.L436:
	.cfi_restore_state
# /usr/include/c++/15.2.1/bits/vector.tcc:123: 	  _M_realloc_append(std::forward<_Args>(__args)...);
	mov	rax, QWORD PTR 72[rsp]	# tmp140, D.173630
	sub	rax, QWORD PTR fs:40	# tmp140, MEM[(<address-space-1> long unsigned int *)40B]
	jne	.L443	#,
# /usr/include/c++/15.2.1/bits/vector.tcc:127:       }
	add	rsp, 80	#,
	.cfi_remember_state
	.cfi_def_cfa_offset 48
# /usr/include/c++/15.2.1/bits/vector.tcc:123: 	  _M_realloc_append(std::forward<_Args>(__args)...);
	mov	rdx, r13	#, __args#1
	mov	rdi, rbx	#, this
# /usr/include/c++/15.2.1/bits/vector.tcc:127:       }
	pop	rbx	#
	.cfi_def_cfa_offset 40
	pop	rbp	#
	.cfi_def_cfa_offset 32
	pop	r12	#
	.cfi_def_cfa_offset 24
	pop	r13	#
	.cfi_def_cfa_offset 16
	pop	r14	#
	.cfi_def_cfa_offset 8
.LEHB21:
# /usr/include/c++/15.2.1/bits/vector.tcc:123: 	  _M_realloc_append(std::forward<_Args>(__args)...);
	jmp	_ZNSt6vectorI6ButtonSaIS0_EE17_M_realloc_appendIJiRKiS5_S5_RA2_KcEEEvDpOT_	#
.LEHE21:
.L443:
	.cfi_restore_state
# /usr/include/c++/15.2.1/bits/vector.tcc:127:       }
	call	[QWORD PTR __stack_chk_fail@GOTPCREL[rip]]	#
.L442:
# /usr/include/c++/15.2.1/bits/new_allocator.h:191: 	{ ::new((void *)__p) _Up(std::forward<_Args>(__args)...); }
	mov	rbx, rax	# tmp137,
	jmp	.L438	#
	.section	.gcc_except_table
.LLSDA13938:
	.byte	0xff
	.byte	0xff
	.byte	0x1
	.uleb128 .LLSDACSE13938-.LLSDACSB13938
.LLSDACSB13938:
	.uleb128 .LEHB19-.LFB13938
	.uleb128 .LEHE19-.LEHB19
	.uleb128 0
	.uleb128 0
	.uleb128 .LEHB20-.LFB13938
	.uleb128 .LEHE20-.LEHB20
	.uleb128 .L442-.LFB13938
	.uleb128 0
	.uleb128 .LEHB21-.LFB13938
	.uleb128 .LEHE21-.LEHB21
	.uleb128 0
	.uleb128 0
.LLSDACSE13938:
	.text
	.cfi_endproc
	.section	.text.unlikely
	.cfi_startproc
	.cfi_personality 0x9b,DW.ref.__gxx_personality_v0
	.cfi_lsda 0x1b,.LLSDAC13938
	.type	_ZNSt6vectorI6ButtonSaIS0_EE12emplace_backIJiRKiS5_S5_RA2_KcEEERS0_DpOT_.isra.0.cold, @function
_ZNSt6vectorI6ButtonSaIS0_EE12emplace_backIJiRKiS5_S5_RA2_KcEEERS0_DpOT_.isra.0.cold:
.LFSB13938:
.L438:
	.cfi_def_cfa_offset 128
	.cfi_offset 3, -48
	.cfi_offset 6, -40
	.cfi_offset 12, -32
	.cfi_offset 13, -24
	.cfi_offset 14, -16
	mov	rdi, rbp	#, tmp129
	call	[QWORD PTR _ZNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEED1Ev@GOTPCREL[rip]]	#
	mov	rax, QWORD PTR 72[rsp]	# tmp139, D.173630
	sub	rax, QWORD PTR fs:40	# tmp139, MEM[(<address-space-1> long unsigned int *)40B]
	jne	.L445	#,
	mov	rdi, rbx	#, tmp137
.LEHB22:
	call	[QWORD PTR _Unwind_Resume@GOTPCREL[rip]]	#
.LEHE22:
.L445:
	call	[QWORD PTR __stack_chk_fail@GOTPCREL[rip]]	#
	.cfi_endproc
.LFE13938:
	.section	.gcc_except_table
.LLSDAC13938:
	.byte	0xff
	.byte	0xff
	.byte	0x1
	.uleb128 .LLSDACSEC13938-.LLSDACSBC13938
.LLSDACSBC13938:
	.uleb128 .LEHB22-.LCOLDB18
	.uleb128 .LEHE22-.LEHB22
	.uleb128 0
	.uleb128 0
.LLSDACSEC13938:
	.section	.text.unlikely
	.text
	.size	_ZNSt6vectorI6ButtonSaIS0_EE12emplace_backIJiRKiS5_S5_RA2_KcEEERS0_DpOT_.isra.0, .-_ZNSt6vectorI6ButtonSaIS0_EE12emplace_backIJiRKiS5_S5_RA2_KcEEERS0_DpOT_.isra.0
	.section	.text.unlikely
	.size	_ZNSt6vectorI6ButtonSaIS0_EE12emplace_backIJiRKiS5_S5_RA2_KcEEERS0_DpOT_.isra.0.cold, .-_ZNSt6vectorI6ButtonSaIS0_EE12emplace_backIJiRKiS5_S5_RA2_KcEEERS0_DpOT_.isra.0.cold
.LCOLDE18:
	.text
.LHOTE18:
	.section	.text._ZNSt6vectorI6ButtonSaIS0_EE17_M_realloc_appendIJiRKiS5_S5_RKNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEEEEEEvDpOT_,"axG",@progbits,_ZNSt6vectorI6ButtonSaIS0_EE17_M_realloc_appendIJiRKiS5_S5_RKNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEEEEEEvDpOT_,comdat
	.align 2
	.p2align 4
	.weak	_ZNSt6vectorI6ButtonSaIS0_EE17_M_realloc_appendIJiRKiS5_S5_RKNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEEEEEEvDpOT_
	.type	_ZNSt6vectorI6ButtonSaIS0_EE17_M_realloc_appendIJiRKiS5_S5_RKNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEEEEEEvDpOT_, @function
_ZNSt6vectorI6ButtonSaIS0_EE17_M_realloc_appendIJiRKiS5_S5_RKNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEEEEEEvDpOT_:
.LFB13554:
	.cfi_startproc
	.cfi_personality 0x9b,DW.ref.__gxx_personality_v0
	.cfi_lsda 0x1b,.LLSDA13554
	push	r15	#
	.cfi_def_cfa_offset 16
	.cfi_offset 15, -16
	push	r14	#
	.cfi_def_cfa_offset 24
	.cfi_offset 14, -24
	push	r13	#
	.cfi_def_cfa_offset 32
	.cfi_offset 13, -32
	push	r12	#
	.cfi_def_cfa_offset 40
	.cfi_offset 12, -40
	push	rbp	#
	.cfi_def_cfa_offset 48
	.cfi_offset 6, -48
	push	rbx	#
	.cfi_def_cfa_offset 56
	.cfi_offset 3, -56
	mov	rbx, rdi	# this, this
	sub	rsp, 88	#,
	.cfi_def_cfa_offset 144
# /usr/include/c++/15.2.1/bits/vector.tcc:557:       vector<_Tp, _Alloc>::
	mov	QWORD PTR 40[rsp], r8	# %sfp, __args#3
	mov	QWORD PTR 32[rsp], r9	# %sfp, __args#4
	mov	QWORD PTR 24[rsp], rcx	# %sfp, __args#2
	mov	QWORD PTR 8[rsp], rsi	# %sfp, __args#0
# /usr/include/c++/15.2.1/bits/vector.tcc:566:       const size_type __len = _M_check_len(1u, "vector::_M_realloc_append");
	mov	esi, 1	#,
# /usr/include/c++/15.2.1/bits/vector.tcc:557:       vector<_Tp, _Alloc>::
	mov	QWORD PTR 16[rsp], rdx	# %sfp, __args#1
# /usr/include/c++/15.2.1/bits/vector.tcc:566:       const size_type __len = _M_check_len(1u, "vector::_M_realloc_append");
	mov	rdx, QWORD PTR fs:40	#, MEM[(<address-space-1> long unsigned int *)40B]
	mov	QWORD PTR 72[rsp], rdx	# D.173637,
	lea	rdx, .LC17[rip]	#,
.LEHB23:
	call	_ZNKSt6vectorI6ButtonSaIS0_EE12_M_check_lenEmPKc	#
# /usr/include/c++/15.2.1/bits/vector.tcc:571:       const size_type __elems = end() - begin();
	mov	rdi, rbx	#, this
# /usr/include/c++/15.2.1/bits/vector.tcc:569:       pointer __old_start = this->_M_impl._M_start;
	mov	r14, QWORD PTR [rbx]	# __old_start, this_12(D)->D.155608._M_impl.D.154943._M_start
# /usr/include/c++/15.2.1/bits/vector.tcc:566:       const size_type __len = _M_check_len(1u, "vector::_M_realloc_append");
	mov	r12, rax	# _14,
# /usr/include/c++/15.2.1/bits/vector.tcc:570:       pointer __old_finish = this->_M_impl._M_finish;
	mov	rax, QWORD PTR 8[rbx]	# __old_finish, this_12(D)->D.155608._M_impl.D.154943._M_finish
	mov	QWORD PTR [rsp], rax	# %sfp, __old_finish
# /usr/include/c++/15.2.1/bits/vector.tcc:571:       const size_type __elems = end() - begin();
	call	_ZNSt6vectorI6ButtonSaIS0_EE5beginEv	#
# /usr/include/c++/15.2.1/bits/vector.tcc:571:       const size_type __elems = end() - begin();
	mov	rdi, rbx	#, this
# /usr/include/c++/15.2.1/bits/vector.tcc:571:       const size_type __elems = end() - begin();
	mov	rbp, rax	# D.166960,
# /usr/include/c++/15.2.1/bits/vector.tcc:571:       const size_type __elems = end() - begin();
	call	_ZNSt6vectorI6ButtonSaIS0_EE3endEv	#
# /usr/include/c++/15.2.1/bits/vector.tcc:572:       pointer __new_start(this->_M_allocate(__len));
	mov	rdi, r12	#, _14
# /usr/include/c++/15.2.1/bits/stl_iterator.h:1340:     { return __lhs.base() - __rhs.base(); }
	sub	rax, rbp	# D.166959, D.166960
	mov	r13, rax	# _19, D.166959
# /usr/include/c++/15.2.1/bits/vector.tcc:572:       pointer __new_start(this->_M_allocate(__len));
	call	_ZNSt12_Vector_baseI6ButtonSaIS0_EE11_M_allocateEm.isra.0	#
.LEHE23:
# /usr/include/c++/15.2.1/bits/vector.tcc:576: 	_Guard_alloc __guard(__new_start, __len, *this);
	mov	rcx, rbx	#, this
	mov	rdx, r12	#, _14
	lea	rdi, 48[rsp]	#,
# /usr/include/c++/15.2.1/bits/vector.tcc:572:       pointer __new_start(this->_M_allocate(__len));
	mov	rbp, rax	# _23,
# /usr/include/c++/15.2.1/bits/vector.tcc:576: 	_Guard_alloc __guard(__new_start, __len, *this);
	mov	rsi, rax	#, _23
	call	_ZNSt6vectorI6ButtonSaIS0_EE12_Guard_allocC1EPS0_mRSt12_Vector_baseIS0_S1_E	#
# /usr/include/c++/15.2.1/bits/vector.tcc:586: 	_Alloc_traits::construct(this->_M_impl,
	lea	rdi, 0[rbp+r13]	# _3,
# /usr/include/c++/15.2.1/bits/new_allocator.h:191: 	{ ::new((void *)__p) _Up(std::forward<_Args>(__args)...); }
	call	_ZnwmPv.isra.0	#
# /usr/include/c++/15.2.1/bits/new_allocator.h:191: 	{ ::new((void *)__p) _Up(std::forward<_Args>(__args)...); }
	mov	rdi, QWORD PTR 8[rsp]	# __args#0, %sfp
	mov	rcx, QWORD PTR 24[rsp]	# __args#2, %sfp
	mov	rdx, QWORD PTR 16[rsp]	# __args#1, %sfp
	mov	r8, QWORD PTR 40[rsp]	# __args#3, %sfp
	mov	esi, DWORD PTR [rdi]	# *__args#0_33(D), *__args#0_33(D)
	mov	ecx, DWORD PTR [rcx]	# *__args#2_29(D), *__args#2_29(D)
	mov	rdi, rax	#, _36
	mov	edx, DWORD PTR [rdx]	# *__args#1_31(D), *__args#1_31(D)
	mov	r9, QWORD PTR 32[rsp]	# __args#4, %sfp
	mov	r8d, DWORD PTR [r8]	#, *__args#3_27(D)
.LEHB24:
	call	[QWORD PTR _ZN6ButtonC1EiiiiRKNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEEE@GOTPCREL[rip]]	#
.LEHE24:
# /usr/include/c++/15.2.1/bits/vector.tcc:599: 	    __new_finish = _S_relocate(__old_start, __old_finish,
	mov	rsi, QWORD PTR [rsp]	#, %sfp
	mov	rdx, rbp	#, _23
# /usr/include/c++/15.2.1/bits/vector.tcc:646:       this->_M_impl._M_end_of_storage = __new_start + __len;
	imul	r12, r12, 56	# _9, _14,
# /usr/include/c++/15.2.1/bits/vector.tcc:599: 	    __new_finish = _S_relocate(__old_start, __old_finish,
	mov	rdi, r14	#, __old_start
	call	_ZNSt6vectorI6ButtonSaIS0_EE11_S_relocateEPS0_S3_S3_RS1_.isra.0	#
# /usr/include/c++/15.2.1/bits/vector.tcc:640:       }
	lea	rdi, 48[rsp]	#,
# /usr/include/c++/15.2.1/bits/vector.tcc:638: 	__guard._M_storage = __old_start;
	mov	QWORD PTR 48[rsp], r14	# __guard._M_storage, __old_start
# /usr/include/c++/15.2.1/bits/vector.tcc:639: 	__guard._M_len = this->_M_impl._M_end_of_storage - __old_start;
	movabs	rdx, 7905747460161236407	# tmp144,
# /usr/include/c++/15.2.1/bits/vector.tcc:599: 	    __new_finish = _S_relocate(__old_start, __old_finish,
	mov	r13, rax	# __new_finish,
# /usr/include/c++/15.2.1/bits/vector.tcc:639: 	__guard._M_len = this->_M_impl._M_end_of_storage - __old_start;
	mov	rax, QWORD PTR 16[rbx]	# _6, this_12(D)->D.155608._M_impl.D.154943._M_end_of_storage
# /usr/include/c++/15.2.1/bits/vector.tcc:601: 	    ++__new_finish;
	add	r13, 56	# tmp146,
# /usr/include/c++/15.2.1/bits/vector.tcc:639: 	__guard._M_len = this->_M_impl._M_end_of_storage - __old_start;
	sub	rax, r14	# _6, __old_start
	sar	rax, 3	# tmp142,
	imul	rax, rdx	# _7, tmp144
# /usr/include/c++/15.2.1/bits/vector.tcc:639: 	__guard._M_len = this->_M_impl._M_end_of_storage - __old_start;
	mov	QWORD PTR 56[rsp], rax	# __guard._M_len, _7
# /usr/include/c++/15.2.1/bits/vector.tcc:640:       }
	call	_ZNSt6vectorI6ButtonSaIS0_EE12_Guard_allocD1Ev	#
# /usr/include/c++/15.2.1/bits/vector.tcc:644:       this->_M_impl._M_start = __new_start;
	mov	QWORD PTR [rbx], rbp	# this_12(D)->D.155608._M_impl.D.154943._M_start, _23
# /usr/include/c++/15.2.1/bits/vector.tcc:646:       this->_M_impl._M_end_of_storage = __new_start + __len;
	add	rbp, r12	# tmp148, _9
# /usr/include/c++/15.2.1/bits/vector.tcc:601: 	    ++__new_finish;
	mov	QWORD PTR 8[rbx], r13	# this_12(D)->D.155608._M_impl.D.154943._M_finish, tmp146
# /usr/include/c++/15.2.1/bits/vector.tcc:646:       this->_M_impl._M_end_of_storage = __new_start + __len;
	mov	QWORD PTR 16[rbx], rbp	# this_12(D)->D.155608._M_impl.D.154943._M_end_of_storage, tmp148
# /usr/include/c++/15.2.1/bits/vector.tcc:647:     }
	mov	rax, QWORD PTR 72[rsp]	# tmp167, D.173637
	sub	rax, QWORD PTR fs:40	# tmp167, MEM[(<address-space-1> long unsigned int *)40B]
	jne	.L451	#,
	add	rsp, 88	#,
	.cfi_remember_state
	.cfi_def_cfa_offset 56
	pop	rbx	#
	.cfi_def_cfa_offset 48
	pop	rbp	#
	.cfi_def_cfa_offset 40
	pop	r12	#
	.cfi_def_cfa_offset 32
	pop	r13	#
	.cfi_def_cfa_offset 24
	pop	r14	#
	.cfi_def_cfa_offset 16
	pop	r15	#
	.cfi_def_cfa_offset 8
	ret	
.L447:
	.cfi_restore_state
# /usr/include/c++/15.2.1/bits/vector.tcc:640:       }
	lea	rdi, 48[rsp]	#,
	call	_ZNSt6vectorI6ButtonSaIS0_EE12_Guard_allocD1Ev	#
	mov	rax, QWORD PTR 72[rsp]	# tmp168, D.173637
	sub	rax, QWORD PTR fs:40	# tmp168, MEM[(<address-space-1> long unsigned int *)40B]
	je	.L448	#,
.L451:
# /usr/include/c++/15.2.1/bits/vector.tcc:647:     }
	call	[QWORD PTR __stack_chk_fail@GOTPCREL[rip]]	#
.L450:
# /usr/include/c++/15.2.1/bits/vector.tcc:640:       }
	mov	rbx, rax	# tmp166,
	jmp	.L447	#
.L448:
	mov	rdi, rbx	#, tmp166
.LEHB25:
	call	[QWORD PTR _Unwind_Resume@GOTPCREL[rip]]	#
.LEHE25:
	.cfi_endproc
.LFE13554:
	.section	.gcc_except_table
.LLSDA13554:
	.byte	0xff
	.byte	0xff
	.byte	0x1
	.uleb128 .LLSDACSE13554-.LLSDACSB13554
.LLSDACSB13554:
	.uleb128 .LEHB23-.LFB13554
	.uleb128 .LEHE23-.LEHB23
	.uleb128 0
	.uleb128 0
	.uleb128 .LEHB24-.LFB13554
	.uleb128 .LEHE24-.LEHB24
	.uleb128 .L450-.LFB13554
	.uleb128 0
	.uleb128 .LEHB25-.LFB13554
	.uleb128 .LEHE25-.LEHB25
	.uleb128 0
	.uleb128 0
.LLSDACSE13554:
	.section	.text._ZNSt6vectorI6ButtonSaIS0_EE17_M_realloc_appendIJiRKiS5_S5_RKNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEEEEEEvDpOT_,"axG",@progbits,_ZNSt6vectorI6ButtonSaIS0_EE17_M_realloc_appendIJiRKiS5_S5_RKNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEEEEEEvDpOT_,comdat
	.size	_ZNSt6vectorI6ButtonSaIS0_EE17_M_realloc_appendIJiRKiS5_S5_RKNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEEEEEEvDpOT_, .-_ZNSt6vectorI6ButtonSaIS0_EE17_M_realloc_appendIJiRKiS5_S5_RKNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEEEEEEvDpOT_
	.text
	.align 2
	.p2align 4
	.type	_ZNSt6vectorI6ButtonSaIS0_EE12emplace_backIJiRKiS5_S5_RKNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEEEEEERS0_DpOT_.isra.0, @function
_ZNSt6vectorI6ButtonSaIS0_EE12emplace_backIJiRKiS5_S5_RKNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEEEEEERS0_DpOT_.isra.0:
.LFB13939:
	.cfi_startproc
# /usr/include/c++/15.2.1/bits/vector.tcc:114: 	if (this->_M_impl._M_finish != this->_M_impl._M_end_of_storage)
	mov	rax, QWORD PTR 8[rdi]	# _2, this_1(D)->D.155608._M_impl.D.154943._M_finish
# /usr/include/c++/15.2.1/bits/vector.tcc:114: 	if (this->_M_impl._M_finish != this->_M_impl._M_end_of_storage)
	cmp	rax, QWORD PTR 16[rdi]	# _2, this_1(D)->D.155608._M_impl.D.154943._M_end_of_storage
	je	.L454	#,
# /usr/include/c++/15.2.1/bits/vector.tcc:111:       vector<_Tp, _Alloc>::
	push	rbx	#
	.cfi_def_cfa_offset 16
	.cfi_offset 3, -16
	mov	rbx, rdi	# this, this
# /usr/include/c++/15.2.1/bits/new_allocator.h:191: 	{ ::new((void *)__p) _Up(std::forward<_Args>(__args)...); }
	mov	rdi, rax	#, _2
	call	_ZnwmPv.isra.0	#
# /usr/include/c++/15.2.1/bits/new_allocator.h:191: 	{ ::new((void *)__p) _Up(std::forward<_Args>(__args)...); }
	mov	ecx, DWORD PTR [rcx]	# *__args#2_7(D), *__args#2_7(D)
	mov	edx, DWORD PTR [rdx]	# *__args#1_9(D), *__args#1_9(D)
	mov	esi, DWORD PTR [rsi]	# *__args#0_11(D), *__args#0_11(D)
	mov	r8d, DWORD PTR [r8]	#, *__args#3_5(D)
	mov	rdi, rax	#, _4
	call	[QWORD PTR _ZN6ButtonC1EiiiiRKNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEEE@GOTPCREL[rip]]	#
# /usr/include/c++/15.2.1/bits/vector.tcc:119: 	    ++this->_M_impl._M_finish;
	add	QWORD PTR 8[rbx], 56	# this_1(D)->D.155608._M_impl.D.154943._M_finish,
# /usr/include/c++/15.2.1/bits/vector.tcc:127:       }
	pop	rbx	#
	.cfi_def_cfa_offset 8
	ret	
	.p2align 4,,10
	.p2align 3
.L454:
	.cfi_restore 3
# /usr/include/c++/15.2.1/bits/vector.tcc:123: 	  _M_realloc_append(std::forward<_Args>(__args)...);
	jmp	_ZNSt6vectorI6ButtonSaIS0_EE17_M_realloc_appendIJiRKiS5_S5_RKNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEEEEEEvDpOT_	#
	.cfi_endproc
.LFE13939:
	.size	_ZNSt6vectorI6ButtonSaIS0_EE12emplace_backIJiRKiS5_S5_RKNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEEEEEERS0_DpOT_.isra.0, .-_ZNSt6vectorI6ButtonSaIS0_EE12emplace_backIJiRKiS5_S5_RKNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEEEEEERS0_DpOT_.isra.0
	.section	.rodata.str1.1
.LC19:
	.string	"+"
	.text
	.align 2
	.p2align 4
	.globl	_ZN10SavesScene12rebuildSlotsEv
	.type	_ZN10SavesScene12rebuildSlotsEv, @function
_ZN10SavesScene12rebuildSlotsEv:
.LFB12864:
	.cfi_startproc
	push	r15	#
	.cfi_def_cfa_offset 16
	.cfi_offset 15, -16
	push	r14	#
	.cfi_def_cfa_offset 24
	.cfi_offset 14, -24
	push	r13	#
	.cfi_def_cfa_offset 32
	.cfi_offset 13, -32
	push	r12	#
	.cfi_def_cfa_offset 40
	.cfi_offset 12, -40
	push	rbp	#
	.cfi_def_cfa_offset 48
	.cfi_offset 6, -48
	push	rbx	#
	.cfi_def_cfa_offset 56
	.cfi_offset 3, -56
	sub	rsp, 24	#,
	.cfi_def_cfa_offset 80
# saves_scene.cpp:76: void SavesScene::rebuildSlots() {
	mov	r14, QWORD PTR fs:40	# this, MEM[(<address-space-1> long unsigned int *)40B]
	mov	QWORD PTR 8[rsp], r14	# D.173662, this
	mov	r14, rdi	# this, this
# saves_scene.cpp:77:     slotButtons.clear();
	add	rdi, 80	#,
	call	_ZNSt6vectorI6ButtonSaIS0_EE5clearEv	#
# saves_scene.cpp:78:     slotIsNew.clear();
	lea	rbp, 104[r14]	# _2,
	mov	rdi, rbp	#, _2
	call	_ZNSt6vectorIbSaIbEE5clearEv	#
# saves_scene.cpp:81:     for (const auto& entry : SaveManager::get().getEntries()) {
	call	_ZN11SaveManager3getEv	#
# saves_scene.cpp:81:     for (const auto& entry : SaveManager::get().getEntries()) {
	mov	rdi, rax	#, _3
	call	_ZNK11SaveManager10getEntriesEv	#
	mov	r13, rax	# __for_range,
# saves_scene.cpp:81:     for (const auto& entry : SaveManager::get().getEntries()) {
	mov	rdi, rax	#, __for_range
	call	_ZNKSt6vectorI9SaveEntrySaIS0_EE5beginEv	#
# saves_scene.cpp:81:     for (const auto& entry : SaveManager::get().getEntries()) {
	mov	rdi, r13	#, __for_range
# saves_scene.cpp:81:     for (const auto& entry : SaveManager::get().getEntries()) {
	mov	rbx, rax	# SR.547, SR.547
# saves_scene.cpp:81:     for (const auto& entry : SaveManager::get().getEntries()) {
	call	_ZNKSt6vectorI9SaveEntrySaIS0_EE3endEv	#
# saves_scene.cpp:81:     for (const auto& entry : SaveManager::get().getEntries()) {
	cmp	rbx, rax	# SR.547, SR.1106
	je	.L461	#,
	mov	r13, rax	# SR.1106,
	.p2align 4
	.p2align 3
.L462:
# saves_scene.cpp:82:         slotButtons.emplace_back(0, PLUS_BTN_Y, PLUS_BTN_W, PLUS_BTN_H, entry.name);
	lea	r9, 8[rbx]	#,
	lea	rsi, 4[rsp]	#,
# /usr/include/c++/15.2.1/bits/stl_iterator.h:1103: 	++_M_current;
	add	rbx, 72	# SR.547,
# saves_scene.cpp:82:         slotButtons.emplace_back(0, PLUS_BTN_Y, PLUS_BTN_W, PLUS_BTN_H, entry.name);
	mov	DWORD PTR 4[rsp], 0	# MEM[(int *)_36],
# saves_scene.cpp:82:         slotButtons.emplace_back(0, PLUS_BTN_Y, PLUS_BTN_W, PLUS_BTN_H, entry.name);
	lea	r8, _ZN10SavesScene10PLUS_BTN_HE[rip]	#,
	lea	rcx, _ZN10SavesScene10PLUS_BTN_WE[rip]	#,
	lea	rdx, _ZN10SavesScene10PLUS_BTN_YE[rip]	#,
	lea	rdi, 80[r14]	#,
	call	_ZNSt6vectorI6ButtonSaIS0_EE12emplace_backIJiRKiS5_S5_RKNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEEEEEERS0_DpOT_.isra.0	#
# saves_scene.cpp:83:         slotIsNew.push_back(false);
	xor	esi, esi	#
	mov	rdi, rbp	#, _2
	call	_ZNSt6vectorIbSaIbEE9push_backEb	#
# saves_scene.cpp:81:     for (const auto& entry : SaveManager::get().getEntries()) {
	cmp	rbx, r13	# SR.547, SR.1106
	jne	.L462	#,
.L461:
# saves_scene.cpp:87:     if ((int)slotButtons.size() < MAX_SAVES) {
	mov	rsi, QWORD PTR 88[r14]	# MEM[(struct Button * *)this_9(D) + 88B], MEM[(struct Button * *)this_9(D) + 88B]
	mov	rdi, QWORD PTR 80[r14]	# MEM[(struct Button * *)this_9(D) + 80B], MEM[(struct Button * *)this_9(D) + 80B]
	call	_ZNKSt6vectorI6ButtonSaIS0_EE4sizeEv.isra.0	#
# saves_scene.cpp:87:     if ((int)slotButtons.size() < MAX_SAVES) {
	cmp	eax, 11	# _5,
	jle	.L468	#,
.L463:
# saves_scene.cpp:92:     rebuildButtonsLayout();
	mov	rax, QWORD PTR 8[rsp]	# tmp140, D.173662
	sub	rax, QWORD PTR fs:40	# tmp140, MEM[(<address-space-1> long unsigned int *)40B]
	jne	.L469	#,
# saves_scene.cpp:93: }
	add	rsp, 24	#,
	.cfi_remember_state
	.cfi_def_cfa_offset 56
# saves_scene.cpp:92:     rebuildButtonsLayout();
	mov	rdi, r14	#, this
# saves_scene.cpp:93: }
	pop	rbx	#
	.cfi_def_cfa_offset 48
	pop	rbp	#
	.cfi_def_cfa_offset 40
	pop	r12	#
	.cfi_def_cfa_offset 32
	pop	r13	#
	.cfi_def_cfa_offset 24
	pop	r14	#
	.cfi_def_cfa_offset 16
	pop	r15	#
	.cfi_def_cfa_offset 8
# saves_scene.cpp:92:     rebuildButtonsLayout();
	jmp	_ZN10SavesScene20rebuildButtonsLayoutEv	#
	.p2align 4,,10
	.p2align 3
.L468:
	.cfi_restore_state
# saves_scene.cpp:88:         slotButtons.emplace_back(0, PLUS_BTN_Y, PLUS_BTN_W, PLUS_BTN_H, "+");
	lea	rsi, 4[rsp]	# tmp127,
	lea	rdi, 80[r14]	#,
# saves_scene.cpp:88:         slotButtons.emplace_back(0, PLUS_BTN_Y, PLUS_BTN_W, PLUS_BTN_H, "+");
	mov	DWORD PTR 4[rsp], 0	# MEM[(int *)_36],
# saves_scene.cpp:88:         slotButtons.emplace_back(0, PLUS_BTN_Y, PLUS_BTN_W, PLUS_BTN_H, "+");
	lea	r9, .LC19[rip]	#,
	lea	r8, _ZN10SavesScene10PLUS_BTN_HE[rip]	#,
	lea	rcx, _ZN10SavesScene10PLUS_BTN_WE[rip]	#,
	lea	rdx, _ZN10SavesScene10PLUS_BTN_YE[rip]	#,
	call	_ZNSt6vectorI6ButtonSaIS0_EE12emplace_backIJiRKiS5_S5_RA2_KcEEERS0_DpOT_.isra.0	#
# saves_scene.cpp:89:         slotIsNew.push_back(true);
	mov	esi, 1	#,
	mov	rdi, rbp	#, _2
	call	_ZNSt6vectorIbSaIbEE9push_backEb	#
	jmp	.L463	#
.L469:
# saves_scene.cpp:92:     rebuildButtonsLayout();
	call	[QWORD PTR __stack_chk_fail@GOTPCREL[rip]]	#
	.cfi_endproc
.LFE12864:
	.size	_ZN10SavesScene12rebuildSlotsEv, .-_ZN10SavesScene12rebuildSlotsEv
	.align 2
	.p2align 4
	.globl	_ZN10SavesScene10closeInputEb
	.type	_ZN10SavesScene10closeInputEb, @function
_ZN10SavesScene10closeInputEb:
.LFB12870:
	.cfi_startproc
	push	r15	#
	.cfi_def_cfa_offset 16
	.cfi_offset 15, -16
	push	r14	#
	.cfi_def_cfa_offset 24
	.cfi_offset 14, -24
	push	rbp	#
	.cfi_def_cfa_offset 32
	.cfi_offset 6, -32
	lea	rbp, 152[rdi]	# _12,
	push	rbx	#
	.cfi_def_cfa_offset 40
	.cfi_offset 3, -40
	mov	rbx, rdi	# this, this
	sub	rsp, 24	#,
	.cfi_def_cfa_offset 64
# saves_scene.cpp:127:     if (accept && activePlusIndex >= 0 && !inputText.empty()) {
	test	sil, sil	# accept
	je	.L472	#,
# saves_scene.cpp:127:     if (accept && activePlusIndex >= 0 && !inputText.empty()) {
	mov	edx, DWORD PTR 144[rdi]	# _1, this_16(D)->activePlusIndex
	lea	rbp, 152[rdi]	# _12,
# saves_scene.cpp:127:     if (accept && activePlusIndex >= 0 && !inputText.empty()) {
	test	edx, edx	# _1
	js	.L472	#,
# saves_scene.cpp:127:     if (accept && activePlusIndex >= 0 && !inputText.empty()) {
	mov	DWORD PTR 12[rsp], edx	# %sfp, _1
	mov	rdi, rbp	#, _12
	call	[QWORD PTR _ZNKSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEE5emptyEv@GOTPCREL[rip]]	#
# saves_scene.cpp:127:     if (accept && activePlusIndex >= 0 && !inputText.empty()) {
	test	al, al	# _3
	jne	.L472	#,
	mov	rax, QWORD PTR 80[rbx]	# _34, MEM[(struct Button * *)this_16(D) + 80B]
# saves_scene.cpp:130:         if (idx >= 0 && idx < (int)slotButtons.size()) {
	mov	rsi, QWORD PTR 88[rbx]	# MEM[(struct Button * *)this_16(D) + 88B], MEM[(struct Button * *)this_16(D) + 88B]
	mov	rdi, rax	#, _34
	mov	r14, rax	# _34, _34
	call	_ZNKSt6vectorI6ButtonSaIS0_EE4sizeEv.isra.0	#
# saves_scene.cpp:130:         if (idx >= 0 && idx < (int)slotButtons.size()) {
	mov	edx, DWORD PTR 12[rsp]	# _1, %sfp
	cmp	edx, eax	# _1, _5
	jge	.L472	#,
# saves_scene.cpp:131:             if (slotIsNew[idx]) {
	mov	rdi, QWORD PTR 104[rbx]	# MEM[(_Bit_type * *)this_16(D) + 104B], MEM[(_Bit_type * *)this_16(D) + 104B]
	movsxd	rsi, edx	#, _1
	movsxd	r15, edx	# _8, _1
	call	_ZNSt6vectorIbSaIbEEixEm.isra.0	#
# saves_scene.cpp:131:             if (slotIsNew[idx]) {
	mov	rsi, rdx	#, D.161407
	mov	rdi, rax	#, D.161407
	call	_ZNKSt14_Bit_referencecvbEv.isra.0	#
# saves_scene.cpp:131:             if (slotIsNew[idx]) {
	test	al, al	# retval.54_18
	je	.L474	#,
# saves_scene.cpp:133:                 int result = SaveManager::get().createNamedSave(inputText);
	call	_ZN11SaveManager3getEv	#
# saves_scene.cpp:133:                 int result = SaveManager::get().createNamedSave(inputText);
	mov	rsi, rbp	#, _12
	mov	rdi, rax	#, _9
	call	[QWORD PTR _ZN11SaveManager15createNamedSaveERKNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEEE@GOTPCREL[rip]]	#
# saves_scene.cpp:134:                 if (result >= 0) {
	test	eax, eax	# _23
	js	.L472	#,
# saves_scene.cpp:136:                     rebuildSlots();
	mov	rdi, rbx	#, this
	call	_ZN10SavesScene12rebuildSlotsEv	#
.L472:
# saves_scene.cpp:149:     activePlusIndex = -1;
	mov	DWORD PTR 144[rbx], -1	# this_16(D)->activePlusIndex,
# saves_scene.cpp:150:     isInputVisible  = false;
	xor	eax, eax	#
# saves_scene.cpp:152:     inputText.clear();
	mov	rdi, rbp	#, _12
# saves_scene.cpp:150:     isInputVisible  = false;
	mov	WORD PTR 148[rbx], ax	# MEM <vector(2) unsigned char> [(bool *)this_16(D) + 148B],
# saves_scene.cpp:152:     inputText.clear();
	call	[QWORD PTR _ZNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEE5clearEv@GOTPCREL[rip]]	#
# saves_scene.cpp:154: }
	add	rsp, 24	#,
	.cfi_remember_state
	.cfi_def_cfa_offset 40
	pop	rbx	#
	.cfi_def_cfa_offset 32
	pop	rbp	#
	.cfi_def_cfa_offset 24
	pop	r14	#
	.cfi_def_cfa_offset 16
	pop	r15	#
	.cfi_def_cfa_offset 8
# saves_scene.cpp:153:     SDL_StopTextInput();
	jmp	[QWORD PTR SDL_StopTextInput@GOTPCREL[rip]]	#
	.p2align 4,,10
	.p2align 3
.L474:
	.cfi_restore_state
# saves_scene.cpp:143:                 slotButtons[idx].text = inputText;
	mov	rsi, r15	#, _8
	mov	rdi, r14	#, _34
	call	_ZNSt6vectorI6ButtonSaIS0_EEixEm.isra.0	#
# saves_scene.cpp:143:                 slotButtons[idx].text = inputText;
	mov	rsi, rbp	#, _12
	lea	rdi, 16[rax]	# _11,
	call	[QWORD PTR _ZNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEEaSERKS4_@GOTPCREL[rip]]	#
	jmp	.L472	#
	.cfi_endproc
.LFE12870:
	.size	_ZN10SavesScene10closeInputEb, .-_ZN10SavesScene10closeInputEb
	.section	.text.unlikely
	.align 2
.LCOLDB20:
	.text
.LHOTB20:
	.align 2
	.p2align 4
	.globl	_ZN10SavesScene11handleInputER9SDL_Eventiibb
	.type	_ZN10SavesScene11handleInputER9SDL_Eventiibb, @function
_ZN10SavesScene11handleInputER9SDL_Eventiibb:
.LFB12872:
	.cfi_startproc
	.cfi_personality 0x9b,DW.ref.__gxx_personality_v0
	.cfi_lsda 0x1b,.LLSDA12872
	push	r15	#
	.cfi_def_cfa_offset 16
	.cfi_offset 15, -16
	mov	r15, rdi	# this, this
	push	r14	#
	.cfi_def_cfa_offset 24
	.cfi_offset 14, -24
	push	r13	#
	.cfi_def_cfa_offset 32
	.cfi_offset 13, -32
	push	r12	#
	.cfi_def_cfa_offset 40
	.cfi_offset 12, -40
	push	rbp	#
	.cfi_def_cfa_offset 48
	.cfi_offset 6, -48
	mov	ebp, edx	# mx, mx
	push	rbx	#
	.cfi_def_cfa_offset 56
	.cfi_offset 3, -56
	sub	rsp, 152	#,
	.cfi_def_cfa_offset 208
# saves_scene.cpp:172:         if (isInputVisible) closeInput(false);
	movzx	edx, BYTE PTR 148[rdi]	# pretmp_130, this_61(D)->isInputVisible
# saves_scene.cpp:169:                              bool mouseClicked, bool /*mouseDown*/) {
	mov	DWORD PTR 12[rsp], r8d	# %sfp, mouseClicked
# saves_scene.cpp:171:     if (event.type == SDL_APP_WILLENTERBACKGROUND) {
	mov	rax, QWORD PTR fs:40	# _1, MEM[(<address-space-1> long unsigned int *)40B]
	mov	QWORD PTR 136[rsp], rax	# D.173693, _1
	mov	eax, DWORD PTR [rsi]	# _1, event_60(D)->type
# saves_scene.cpp:171:     if (event.type == SDL_APP_WILLENTERBACKGROUND) {
	cmp	eax, 259	# _1,
	je	.L547	#,
	mov	r14, rsi	# event, event
	mov	r12d, ecx	# my, my
# saves_scene.cpp:178:     if (isInputVisible) {
	test	dl, dl	# pretmp_130
	jne	.L548	#,
# saves_scene.cpp:230:             if (updateButton(menuButtons[i], mx, my, mouseClicked, soundMgr)) {
	movzx	r13d, BYTE PTR 12[rsp]	# _17, %sfp
# saves_scene.cpp:229:         for (size_t i = 0; i < menuButtons.size(); ++i) {
	xor	ebx, ebx	# i
# saves_scene.cpp:226:     if (isMenuVisible) {
	cmp	BYTE PTR 200[rdi], 0	# this_61(D)->isMenuVisible,
	jne	.L499	#,
	jmp	.L549	#
	.p2align 4,,10
	.p2align 3
.L507:
# saves_scene.cpp:230:             if (updateButton(menuButtons[i], mx, my, mouseClicked, soundMgr)) {
	mov	rsi, rbx	#, i
# saves_scene.cpp:230:             if (updateButton(menuButtons[i], mx, my, mouseClicked, soundMgr)) {
	mov	r8, QWORD PTR 16[r15]	# _16, this_61(D)->soundMgr
# saves_scene.cpp:230:             if (updateButton(menuButtons[i], mx, my, mouseClicked, soundMgr)) {
	mov	ecx, r13d	#, _17
	mov	edx, r12d	#, my
# saves_scene.cpp:230:             if (updateButton(menuButtons[i], mx, my, mouseClicked, soundMgr)) {
	call	_ZNSt6vectorI6ButtonSaIS0_EEixEm.isra.0	#
# saves_scene.cpp:230:             if (updateButton(menuButtons[i], mx, my, mouseClicked, soundMgr)) {
	mov	esi, ebp	#, mx
	mov	rdi, rax	#, _18
.LEHB26:
	call	[QWORD PTR _Z12updateButtonR6ButtoniibP12SoundManager@GOTPCREL[rip]]	#
# saves_scene.cpp:230:             if (updateButton(menuButtons[i], mx, my, mouseClicked, soundMgr)) {
	test	al, al	# _78
	jne	.L550	#,
# saves_scene.cpp:229:         for (size_t i = 0; i < menuButtons.size(); ++i) {
	add	rbx, 1	# i,
.L499:
	mov	rdi, QWORD PTR 208[r15]	# _128, MEM[(struct Button * *)this_61(D) + 208B]
# saves_scene.cpp:229:         for (size_t i = 0; i < menuButtons.size(); ++i) {
	mov	rsi, QWORD PTR 216[r15]	# MEM[(struct Button * *)this_61(D) + 216B], MEM[(struct Button * *)this_61(D) + 216B]
	call	_ZNKSt6vectorI6ButtonSaIS0_EE4sizeEv.isra.0	#
# saves_scene.cpp:229:         for (size_t i = 0; i < menuButtons.size(); ++i) {
	cmp	rbx, rax	# i, _27
	jb	.L507	#,
# saves_scene.cpp:260:         if (!anyClicked && mouseClicked)  isMenuVisible = false;
	cmp	BYTE PTR 12[rsp], 0	# %sfp,
	je	.L503	#,
# saves_scene.cpp:260:         if (!anyClicked && mouseClicked)  isMenuVisible = false;
	mov	BYTE PTR 200[r15], 0	# this_61(D)->isMenuVisible,
.L503:
# saves_scene.cpp:261:         if (event.type == SDL_KEYDOWN &&
	cmp	DWORD PTR [r14], 768	# event_60(D)->type,
	jne	.L477	#,
# saves_scene.cpp:261:         if (event.type == SDL_KEYDOWN &&
	cmp	DWORD PTR 16[r14], 41	# event_60(D)->key.keysym.scancode,
	je	.L480	#,
	.p2align 4
	.p2align 3
.L477:
# saves_scene.cpp:284: }
	mov	rax, QWORD PTR 136[rsp]	# tmp245, D.173693
	sub	rax, QWORD PTR fs:40	# tmp245, MEM[(<address-space-1> long unsigned int *)40B]
	jne	.L545	#,
	add	rsp, 152	#,
	.cfi_remember_state
	.cfi_def_cfa_offset 56
	pop	rbx	#
	.cfi_def_cfa_offset 48
	pop	rbp	#
	.cfi_def_cfa_offset 40
	pop	r12	#
	.cfi_def_cfa_offset 32
	pop	r13	#
	.cfi_def_cfa_offset 24
	pop	r14	#
	.cfi_def_cfa_offset 16
	pop	r15	#
	.cfi_def_cfa_offset 8
	ret	
	.p2align 4,,10
	.p2align 3
.L548:
	.cfi_restore_state
# saves_scene.cpp:179:         if (!isInputFocused && mouseClicked) {
	cmp	BYTE PTR 149[rdi], 0	# this_61(D)->isInputFocused,
	je	.L551	#,
# saves_scene.cpp:188:             if (event.type == SDL_KEYDOWN) {
	cmp	eax, 768	# _1,
	je	.L552	#,
# saves_scene.cpp:205:             if (event.type == SDL_TEXTINPUT) {
	cmp	eax, 771	# _1,
	je	.L553	#,
.L491:
# saves_scene.cpp:217:             if (mouseClicked && !isPointInRect(mx, my, inputRect)) {
	cmp	BYTE PTR 12[rsp], 0	# %sfp,
	je	.L477	#,
# saves_scene.cpp:217:             if (mouseClicked && !isPointInRect(mx, my, inputRect)) {
	lea	rcx, 184[r15]	# _13,
# saves_scene.cpp:217:             if (mouseClicked && !isPointInRect(mx, my, inputRect)) {
	mov	edx, r12d	#, my
	mov	esi, ebp	#, mx
	mov	rdi, r15	#, this
	call	_ZNK10SavesScene13isPointInRectEiiRK8SDL_Rect	#
# saves_scene.cpp:217:             if (mouseClicked && !isPointInRect(mx, my, inputRect)) {
	test	al, al	# _14
	jne	.L477	#,
.L546:
# saves_scene.cpp:218:                 closeInput(false);
	mov	rax, QWORD PTR 136[rsp]	# tmp243, D.173693
	sub	rax, QWORD PTR fs:40	# tmp243, MEM[(<address-space-1> long unsigned int *)40B]
	jne	.L545	#,
	xor	esi, esi	#
.L544:
# saves_scene.cpp:284: }
	add	rsp, 152	#,
	.cfi_remember_state
	.cfi_def_cfa_offset 56
# saves_scene.cpp:218:                 closeInput(false);
	mov	rdi, r15	#, this
# saves_scene.cpp:284: }
	pop	rbx	#
	.cfi_def_cfa_offset 48
	pop	rbp	#
	.cfi_def_cfa_offset 40
	pop	r12	#
	.cfi_def_cfa_offset 32
	pop	r13	#
	.cfi_def_cfa_offset 24
	pop	r14	#
	.cfi_def_cfa_offset 16
	pop	r15	#
	.cfi_def_cfa_offset 8
# saves_scene.cpp:218:                 closeInput(false);
	jmp	_ZN10SavesScene10closeInputEb	#
	.p2align 4,,10
	.p2align 3
.L547:
	.cfi_restore_state
# saves_scene.cpp:172:         if (isInputVisible) closeInput(false);
	test	dl, dl	# pretmp_130
	jne	.L554	#,
.L479:
# saves_scene.cpp:173:         if (isMenuVisible)  isMenuVisible = false;
	cmp	BYTE PTR 200[r15], 0	# this_61(D)->isMenuVisible,
	je	.L477	#,
.L480:
# saves_scene.cpp:173:         if (isMenuVisible)  isMenuVisible = false;
	mov	BYTE PTR 200[r15], 0	# this_61(D)->isMenuVisible,
	jmp	.L477	#
	.p2align 4,,10
	.p2align 3
.L551:
# saves_scene.cpp:179:         if (!isInputFocused && mouseClicked) {
	cmp	BYTE PTR 12[rsp], 0	# %sfp,
	je	.L477	#,
# saves_scene.cpp:180:             if (isPointInRect(mx, my, inputRect)) {
	lea	rcx, 184[rdi]	# _6,
# saves_scene.cpp:180:             if (isPointInRect(mx, my, inputRect)) {
	mov	edx, r12d	#, my
	mov	esi, ebp	#, mx
	call	_ZNK10SavesScene13isPointInRectEiiRK8SDL_Rect	#
# saves_scene.cpp:180:             if (isPointInRect(mx, my, inputRect)) {
	test	al, al	# retval.64_94
	je	.L477	#,
# saves_scene.cpp:181:                 isInputFocused = true;
	mov	BYTE PTR 149[r15], 1	# this_61(D)->isInputFocused,
# saves_scene.cpp:182:                 SDL_StartTextInput();
	mov	rax, QWORD PTR 136[rsp]	# tmp239, D.173693
	sub	rax, QWORD PTR fs:40	# tmp239, MEM[(<address-space-1> long unsigned int *)40B]
	jne	.L545	#,
# saves_scene.cpp:284: }
	add	rsp, 152	#,
	.cfi_remember_state
	.cfi_def_cfa_offset 56
	pop	rbx	#
	.cfi_def_cfa_offset 48
	pop	rbp	#
	.cfi_def_cfa_offset 40
	pop	r12	#
	.cfi_def_cfa_offset 32
	pop	r13	#
	.cfi_def_cfa_offset 24
	pop	r14	#
	.cfi_def_cfa_offset 16
	pop	r15	#
	.cfi_def_cfa_offset 8
# saves_scene.cpp:182:                 SDL_StartTextInput();
	jmp	[QWORD PTR SDL_StartTextInput@GOTPCREL[rip]]	#
	.p2align 4,,10
	.p2align 3
.L554:
	.cfi_restore_state
# saves_scene.cpp:172:         if (isInputVisible) closeInput(false);
	xor	esi, esi	#
	call	_ZN10SavesScene10closeInputEb	#
	jmp	.L479	#
	.p2align 4,,10
	.p2align 3
.L549:
# saves_scene.cpp:269:     if (updateButton(backBtn, mx, my, mouseClicked, soundMgr))
	movzx	r13d, BYTE PTR 12[rsp]	# _33, %sfp
	mov	r8, QWORD PTR 16[r15]	#, this_61(D)->soundMgr
# saves_scene.cpp:269:     if (updateButton(backBtn, mx, my, mouseClicked, soundMgr))
	lea	rdi, 24[rdi]	# _34,
# saves_scene.cpp:269:     if (updateButton(backBtn, mx, my, mouseClicked, soundMgr))
	mov	esi, ebp	#, mx
	mov	edx, r12d	#, my
	mov	ecx, r13d	#, _33
	call	[QWORD PTR _Z12updateButtonR6ButtoniibP12SoundManager@GOTPCREL[rip]]	#
# saves_scene.cpp:269:     if (updateButton(backBtn, mx, my, mouseClicked, soundMgr))
	test	al, al	# _66
	je	.L509	#,
# saves_scene.cpp:270:         nextScene = SceneType::MAIN_MENU;
	mov	DWORD PTR 8[r15], 1	# this_61(D)->nextScene,
.L509:
# saves_scene.cpp:229:         for (size_t i = 0; i < menuButtons.size(); ++i) {
	xor	ebx, ebx	# i
	jmp	.L510	#
	.p2align 4,,10
	.p2align 3
.L512:
# saves_scene.cpp:279:                 menuTargetIndex = static_cast<int>(i);
	mov	DWORD PTR 204[r15], ebx	# this_61(D)->menuTargetIndex, i
# saves_scene.cpp:280:                 isMenuVisible   = true;
	mov	BYTE PTR 200[r15], 1	# this_61(D)->isMenuVisible,
.L511:
# saves_scene.cpp:272:     for (size_t i = 0; i < slotButtons.size(); ++i) {
	add	rbx, 1	# i,
.L510:
	mov	rdi, QWORD PTR 80[r15]	# _122, MEM[(struct Button * *)this_61(D) + 80B]
# saves_scene.cpp:272:     for (size_t i = 0; i < slotButtons.size(); ++i) {
	mov	rsi, QWORD PTR 88[r15]	# MEM[(struct Button * *)this_61(D) + 88B], MEM[(struct Button * *)this_61(D) + 88B]
	call	_ZNKSt6vectorI6ButtonSaIS0_EE4sizeEv.isra.0	#
# saves_scene.cpp:272:     for (size_t i = 0; i < slotButtons.size(); ++i) {
	cmp	rbx, rax	# i, _41
	jnb	.L477	#,
# saves_scene.cpp:273:         if (updateButton(slotButtons[i], mx, my, mouseClicked, soundMgr)) {
	mov	rsi, rbx	#, i
# saves_scene.cpp:273:         if (updateButton(slotButtons[i], mx, my, mouseClicked, soundMgr)) {
	mov	r8, QWORD PTR 16[r15]	# _35, this_61(D)->soundMgr
# saves_scene.cpp:273:         if (updateButton(slotButtons[i], mx, my, mouseClicked, soundMgr)) {
	mov	ecx, r13d	#, _33
	mov	edx, r12d	#, my
# saves_scene.cpp:273:         if (updateButton(slotButtons[i], mx, my, mouseClicked, soundMgr)) {
	call	_ZNSt6vectorI6ButtonSaIS0_EEixEm.isra.0	#
# saves_scene.cpp:273:         if (updateButton(slotButtons[i], mx, my, mouseClicked, soundMgr)) {
	mov	esi, ebp	#, mx
	mov	rdi, rax	#, _36
	call	[QWORD PTR _Z12updateButtonR6ButtoniibP12SoundManager@GOTPCREL[rip]]	#
# saves_scene.cpp:273:         if (updateButton(slotButtons[i], mx, my, mouseClicked, soundMgr)) {
	test	al, al	# _69
	je	.L511	#,
# saves_scene.cpp:274:             if (slotIsNew[i]) {
	mov	rdi, QWORD PTR 104[r15]	# MEM[(_Bit_type * *)this_61(D) + 104B], MEM[(_Bit_type * *)this_61(D) + 104B]
	mov	rsi, rbx	#, i
	call	_ZNSt6vectorIbSaIbEEixEm.isra.0	#
# saves_scene.cpp:274:             if (slotIsNew[i]) {
	mov	rsi, rdx	#, D.161467
	mov	rdi, rax	#, D.161467
	call	_ZNKSt14_Bit_referencecvbEv.isra.0	#
# saves_scene.cpp:276:                 openInputForButton(static_cast<int>(i));
	mov	esi, ebx	# _127, i
# saves_scene.cpp:274:             if (slotIsNew[i]) {
	test	al, al	# retval.72_71
	je	.L512	#,
# saves_scene.cpp:276:                 openInputForButton(static_cast<int>(i));
	mov	rdi, r15	#, this
	call	_ZN10SavesScene18openInputForButtonEi	#
	jmp	.L511	#
	.p2align 4,,10
	.p2align 3
.L550:
# saves_scene.cpp:233:                 if (i == 0) {
	test	rbx, rbx	# i
	je	.L555	#,
# saves_scene.cpp:238:                 } else if (i == 1) {
	cmp	rbx, 1	# i,
	je	.L556	#,
# saves_scene.cpp:245:                 } else if (i == 2) {
	cmp	rbx, 2	# i,
	je	.L557	#,
# saves_scene.cpp:251:                 } else if (i == 3) {
	cmp	rbx, 3	# i,
	jne	.L503	#,
# saves_scene.cpp:253:                     isMenuVisible = false;
	mov	BYTE PTR 200[r15], 0	# this_61(D)->isMenuVisible,
# saves_scene.cpp:254:                     openInputForButton(menuTargetIndex);
	mov	esi, DWORD PTR 204[r15]	# this_61(D)->menuTargetIndex, this_61(D)->menuTargetIndex
	mov	rdi, r15	#, this
	call	_ZN10SavesScene18openInputForButtonEi	#
	jmp	.L503	#
	.p2align 4,,10
	.p2align 3
.L552:
# saves_scene.cpp:189:                 switch (event.key.keysym.scancode) {
	mov	eax, DWORD PTR 16[rsi]	# _7, event_60(D)->key.keysym.scancode
# saves_scene.cpp:189:                 switch (event.key.keysym.scancode) {
	cmp	eax, 42	# _7,
	je	.L487	#,
	ja	.L488	#,
	cmp	eax, 40	# _7,
	je	.L489	#,
	cmp	eax, 41	# _7,
	je	.L546	#,
	jmp	.L491	#
	.p2align 4,,10
	.p2align 3
.L488:
	cmp	eax, 88	# _7,
	jne	.L491	#,
.L489:
# saves_scene.cpp:192:                     closeInput(true);
	mov	rax, QWORD PTR 136[rsp]	# tmp240, D.173693
	sub	rax, QWORD PTR fs:40	# tmp240, MEM[(<address-space-1> long unsigned int *)40B]
	jne	.L545	#,
	mov	esi, 1	#,
	jmp	.L544	#
.L557:
# saves_scene.cpp:247:                     SaveManager::get().deleteNamedSave(menuTargetIndex);
	call	_ZN11SaveManager3getEv	#
# saves_scene.cpp:247:                     SaveManager::get().deleteNamedSave(menuTargetIndex);
	mov	esi, DWORD PTR 204[r15]	# this_61(D)->menuTargetIndex, this_61(D)->menuTargetIndex
	mov	rdi, rax	#, _23
	call	[QWORD PTR _ZN11SaveManager15deleteNamedSaveEi@GOTPCREL[rip]]	#
# saves_scene.cpp:248:                     rebuildSlots();  // кнопки сдвигаются
	mov	rdi, r15	#, this
	call	_ZN10SavesScene12rebuildSlotsEv	#
# saves_scene.cpp:249:                     isMenuVisible = false;
	mov	BYTE PTR 200[r15], 0	# this_61(D)->isMenuVisible,
	jmp	.L503	#
	.p2align 4,,10
	.p2align 3
.L553:
# saves_scene.cpp:206:                 std::string newText = inputText + event.text.text;
	add	r15, 152	# _10,
# saves_scene.cpp:206:                 std::string newText = inputText + event.text.text;
	lea	rbx, 32[rsp]	# tmp204,
	lea	rdx, 12[rsi]	#,
	mov	rdi, rbx	#, tmp204
	mov	rsi, r15	#, _10
	call	_ZStplIcSt11char_traitsIcESaIcEENSt7__cxx1112basic_stringIT_T0_T1_EERKS8_PKS5_	#
.LEHE26:
# saves_scene.cpp:207:                 if (countUTF8Chars(newText) <= static_cast<size_t>(MAX_NAME_LENGTH)) {
	mov	rdi, rbx	#, tmp204
	call	_ZL14countUTF8CharsRKNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEEE	#
# saves_scene.cpp:207:                 if (countUTF8Chars(newText) <= static_cast<size_t>(MAX_NAME_LENGTH)) {
	cmp	rax, 16	# _11,
	jbe	.L558	#,
# saves_scene.cpp:210:                     size_t available = MAX_NAME_LENGTH - countUTF8Chars(inputText);
	mov	rdi, r15	#, _10
	call	_ZL14countUTF8CharsRKNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEEE	#
# saves_scene.cpp:211:                     if (available > 0)
	cmp	rax, 16	# _12,
	je	.L496	#,
# saves_scene.cpp:210:                     size_t available = MAX_NAME_LENGTH - countUTF8Chars(inputText);
	mov	r13d, 16	# tmp168,
# saves_scene.cpp:212:                         inputText += truncateUTF8(event.text.text, available);
	lea	rdx, 31[rsp]	# tmp169,
	lea	rsi, 12[r14]	#,
	lea	rdi, 64[rsp]	#,
# saves_scene.cpp:210:                     size_t available = MAX_NAME_LENGTH - countUTF8Chars(inputText);
	sub	r13, rax	# available, _12
.LEHB27:
# saves_scene.cpp:212:                         inputText += truncateUTF8(event.text.text, available);
	call	_ZNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEEC1IS3_EEPKcRKS3_	#
.LEHE27:
# saves_scene.cpp:212:                         inputText += truncateUTF8(event.text.text, available);
	mov	rdx, r13	#, available
	lea	rsi, 64[rsp]	#,
	lea	rdi, 96[rsp]	#,
.LEHB28:
	call	_ZL12truncateUTF8RKNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEEEm	#
.LEHE28:
# saves_scene.cpp:212:                         inputText += truncateUTF8(event.text.text, available);
	lea	rsi, 96[rsp]	#,
	mov	rdi, r15	#, _10
.LEHB29:
	call	[QWORD PTR _ZNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEEpLERKS4_@GOTPCREL[rip]]	#
.LEHE29:
# saves_scene.cpp:212:                         inputText += truncateUTF8(event.text.text, available);
	lea	rdi, 96[rsp]	#,
	call	[QWORD PTR _ZNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEED1Ev@GOTPCREL[rip]]	#
# saves_scene.cpp:212:                         inputText += truncateUTF8(event.text.text, available);
	lea	rdi, 64[rsp]	#,
	call	[QWORD PTR _ZNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEED1Ev@GOTPCREL[rip]]	#
.L496:
# saves_scene.cpp:215:             }
	mov	rdi, rbx	#, tmp204
	call	[QWORD PTR _ZNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEED1Ev@GOTPCREL[rip]]	#
	jmp	.L477	#
	.p2align 4,,10
	.p2align 3
.L555:
# saves_scene.cpp:235:                     SaveManager::get().overwriteNamedSave(menuTargetIndex);
	call	_ZN11SaveManager3getEv	#
# saves_scene.cpp:235:                     SaveManager::get().overwriteNamedSave(menuTargetIndex);
	mov	esi, DWORD PTR 204[r15]	# this_61(D)->menuTargetIndex, this_61(D)->menuTargetIndex
	mov	rdi, rax	#, _19
.LEHB30:
	call	[QWORD PTR _ZN11SaveManager18overwriteNamedSaveEi@GOTPCREL[rip]]	#
# saves_scene.cpp:236:                     isMenuVisible = false;
	mov	BYTE PTR 200[r15], 0	# this_61(D)->isMenuVisible,
	jmp	.L503	#
	.p2align 4,,10
	.p2align 3
.L487:
# saves_scene.cpp:198:                     popLastUTF8Char(inputText);
	mov	rax, QWORD PTR 136[rsp]	# tmp242, D.173693
	sub	rax, QWORD PTR fs:40	# tmp242, MEM[(<address-space-1> long unsigned int *)40B]
	jne	.L545	#,
# saves_scene.cpp:284: }
	add	rsp, 152	#,
	.cfi_remember_state
	.cfi_def_cfa_offset 56
# saves_scene.cpp:198:                     popLastUTF8Char(inputText);
	lea	rdi, 152[rdi]	# _8,
# saves_scene.cpp:284: }
	pop	rbx	#
	.cfi_def_cfa_offset 48
	pop	rbp	#
	.cfi_def_cfa_offset 40
	pop	r12	#
	.cfi_def_cfa_offset 32
	pop	r13	#
	.cfi_def_cfa_offset 24
	pop	r14	#
	.cfi_def_cfa_offset 16
	pop	r15	#
	.cfi_def_cfa_offset 8
# saves_scene.cpp:198:                     popLastUTF8Char(inputText);
	jmp	_ZL15popLastUTF8CharRNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEEE	#
.L556:
	.cfi_restore_state
# saves_scene.cpp:240:                     SaveManager::get().loadNamedSave(menuTargetIndex);
	call	_ZN11SaveManager3getEv	#
# saves_scene.cpp:240:                     SaveManager::get().loadNamedSave(menuTargetIndex);
	mov	esi, DWORD PTR 204[r15]	# this_61(D)->menuTargetIndex, this_61(D)->menuTargetIndex
	mov	rdi, rax	#, _21
	call	[QWORD PTR _ZN11SaveManager13loadNamedSaveEi@GOTPCREL[rip]]	#
.LEHE30:
# saves_scene.cpp:241:                     isMenuVisible = false;
	mov	BYTE PTR 200[r15], 0	# this_61(D)->isMenuVisible,
	jmp	.L503	#
.L558:
# saves_scene.cpp:208:                     inputText = newText;
	mov	rsi, rbx	#, tmp204
	mov	rdi, r15	#, _10
.LEHB31:
	call	[QWORD PTR _ZNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEEaSERKS4_@GOTPCREL[rip]]	#
.LEHE31:
	jmp	.L496	#
.L545:
# saves_scene.cpp:284: }
	call	[QWORD PTR __stack_chk_fail@GOTPCREL[rip]]	#
.L522:
# saves_scene.cpp:212:                         inputText += truncateUTF8(event.text.text, available);
	mov	rbp, rax	# tmp233,
	jmp	.L514	#
.L521:
# saves_scene.cpp:212:                         inputText += truncateUTF8(event.text.text, available);
	mov	rbp, rax	# tmp192, tmp234
	jmp	.L515	#
.L520:
# saves_scene.cpp:215:             }
	mov	rbp, rax	# tmp197, tmp235
	jmp	.L516	#
	.section	.gcc_except_table
.LLSDA12872:
	.byte	0xff
	.byte	0xff
	.byte	0x1
	.uleb128 .LLSDACSE12872-.LLSDACSB12872
.LLSDACSB12872:
	.uleb128 .LEHB26-.LFB12872
	.uleb128 .LEHE26-.LEHB26
	.uleb128 0
	.uleb128 0
	.uleb128 .LEHB27-.LFB12872
	.uleb128 .LEHE27-.LEHB27
	.uleb128 .L520-.LFB12872
	.uleb128 0
	.uleb128 .LEHB28-.LFB12872
	.uleb128 .LEHE28-.LEHB28
	.uleb128 .L521-.LFB12872
	.uleb128 0
	.uleb128 .LEHB29-.LFB12872
	.uleb128 .LEHE29-.LEHB29
	.uleb128 .L522-.LFB12872
	.uleb128 0
	.uleb128 .LEHB30-.LFB12872
	.uleb128 .LEHE30-.LEHB30
	.uleb128 0
	.uleb128 0
	.uleb128 .LEHB31-.LFB12872
	.uleb128 .LEHE31-.LEHB31
	.uleb128 .L520-.LFB12872
	.uleb128 0
.LLSDACSE12872:
	.text
	.cfi_endproc
	.section	.text.unlikely
	.cfi_startproc
	.cfi_personality 0x9b,DW.ref.__gxx_personality_v0
	.cfi_lsda 0x1b,.LLSDAC12872
	.type	_ZN10SavesScene11handleInputER9SDL_Eventiibb.cold, @function
_ZN10SavesScene11handleInputER9SDL_Eventiibb.cold:
.LFSB12872:
.L514:
	.cfi_def_cfa_offset 208
	.cfi_offset 3, -56
	.cfi_offset 6, -48
	.cfi_offset 12, -40
	.cfi_offset 13, -32
	.cfi_offset 14, -24
	.cfi_offset 15, -16
# saves_scene.cpp:212:                         inputText += truncateUTF8(event.text.text, available);
	lea	rdi, 96[rsp]	#,
	call	[QWORD PTR _ZNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEED1Ev@GOTPCREL[rip]]	#
.L515:
# saves_scene.cpp:212:                         inputText += truncateUTF8(event.text.text, available);
	lea	rdi, 64[rsp]	#,
	call	[QWORD PTR _ZNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEED1Ev@GOTPCREL[rip]]	#
.L516:
# saves_scene.cpp:215:             }
	mov	rdi, rbx	#, tmp204
	call	[QWORD PTR _ZNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEED1Ev@GOTPCREL[rip]]	#
	mov	rax, QWORD PTR 136[rsp]	# tmp244, D.173693
	sub	rax, QWORD PTR fs:40	# tmp244, MEM[(<address-space-1> long unsigned int *)40B]
	jne	.L559	#,
	mov	rdi, rbp	#, tmp197
.LEHB32:
	call	[QWORD PTR _Unwind_Resume@GOTPCREL[rip]]	#
.LEHE32:
.L559:
	call	[QWORD PTR __stack_chk_fail@GOTPCREL[rip]]	#
	.cfi_endproc
.LFE12872:
	.section	.gcc_except_table
.LLSDAC12872:
	.byte	0xff
	.byte	0xff
	.byte	0x1
	.uleb128 .LLSDACSEC12872-.LLSDACSBC12872
.LLSDACSBC12872:
	.uleb128 .LEHB32-.LCOLDB20
	.uleb128 .LEHE32-.LEHB32
	.uleb128 0
	.uleb128 0
.LLSDACSEC12872:
	.section	.text.unlikely
	.text
	.size	_ZN10SavesScene11handleInputER9SDL_Eventiibb, .-_ZN10SavesScene11handleInputER9SDL_Eventiibb
	.section	.text.unlikely
	.size	_ZN10SavesScene11handleInputER9SDL_Eventiibb.cold, .-_ZN10SavesScene11handleInputER9SDL_Eventiibb.cold
.LCOLDE20:
	.text
.LHOTE20:
	.section	.text._ZNSt6vectorI6ButtonSaIS0_EE17_M_realloc_appendIJiiRKiS5_RA27_KcEEEvDpOT_,"axG",@progbits,_ZNSt6vectorI6ButtonSaIS0_EE17_M_realloc_appendIJiiRKiS5_RA27_KcEEEvDpOT_,comdat
	.align 2
	.p2align 4
	.weak	_ZNSt6vectorI6ButtonSaIS0_EE17_M_realloc_appendIJiiRKiS5_RA27_KcEEEvDpOT_
	.type	_ZNSt6vectorI6ButtonSaIS0_EE17_M_realloc_appendIJiiRKiS5_RA27_KcEEEvDpOT_, @function
_ZNSt6vectorI6ButtonSaIS0_EE17_M_realloc_appendIJiiRKiS5_RA27_KcEEEvDpOT_:
.LFB13542:
	.cfi_startproc
	.cfi_personality 0x9b,DW.ref.__gxx_personality_v0
	.cfi_lsda 0x1b,.LLSDA13542
	push	r15	#
	.cfi_def_cfa_offset 16
	.cfi_offset 15, -16
	push	r14	#
	.cfi_def_cfa_offset 24
	.cfi_offset 14, -24
	push	r13	#
	.cfi_def_cfa_offset 32
	.cfi_offset 13, -32
	push	r12	#
	.cfi_def_cfa_offset 40
	.cfi_offset 12, -40
	push	rbp	#
	.cfi_def_cfa_offset 48
	.cfi_offset 6, -48
	push	rbx	#
	.cfi_def_cfa_offset 56
	.cfi_offset 3, -56
	mov	rbx, rdi	# this, this
	sub	rsp, 168	#,
	.cfi_def_cfa_offset 224
# /usr/include/c++/15.2.1/bits/vector.tcc:557:       vector<_Tp, _Alloc>::
	mov	QWORD PTR 32[rsp], rcx	# %sfp, __args#2
	mov	QWORD PTR 56[rsp], r8	# %sfp, __args#3
	mov	QWORD PTR 48[rsp], r9	# %sfp, __args#4
	mov	QWORD PTR 16[rsp], rsi	# %sfp, __args#0
# /usr/include/c++/15.2.1/bits/vector.tcc:566:       const size_type __len = _M_check_len(1u, "vector::_M_realloc_append");
	mov	esi, 1	#,
# /usr/include/c++/15.2.1/bits/vector.tcc:557:       vector<_Tp, _Alloc>::
	mov	QWORD PTR 24[rsp], rdx	# %sfp, __args#1
# /usr/include/c++/15.2.1/bits/vector.tcc:566:       const size_type __len = _M_check_len(1u, "vector::_M_realloc_append");
	mov	rdx, QWORD PTR fs:40	#, MEM[(<address-space-1> long unsigned int *)40B]
	mov	QWORD PTR 152[rsp], rdx	# D.173706,
	lea	rdx, .LC17[rip]	#,
.LEHB33:
	call	_ZNKSt6vectorI6ButtonSaIS0_EE12_M_check_lenEmPKc	#
# /usr/include/c++/15.2.1/bits/vector.tcc:571:       const size_type __elems = end() - begin();
	mov	rdi, rbx	#, this
# /usr/include/c++/15.2.1/bits/vector.tcc:569:       pointer __old_start = this->_M_impl._M_start;
	mov	r14, QWORD PTR [rbx]	# __old_start, this_12(D)->D.155608._M_impl.D.154943._M_start
# /usr/include/c++/15.2.1/bits/vector.tcc:566:       const size_type __len = _M_check_len(1u, "vector::_M_realloc_append");
	mov	r12, rax	# _14,
# /usr/include/c++/15.2.1/bits/vector.tcc:570:       pointer __old_finish = this->_M_impl._M_finish;
	mov	rax, QWORD PTR 8[rbx]	# __old_finish, this_12(D)->D.155608._M_impl.D.154943._M_finish
	mov	QWORD PTR 8[rsp], rax	# %sfp, __old_finish
# /usr/include/c++/15.2.1/bits/vector.tcc:571:       const size_type __elems = end() - begin();
	call	_ZNSt6vectorI6ButtonSaIS0_EE5beginEv	#
# /usr/include/c++/15.2.1/bits/vector.tcc:571:       const size_type __elems = end() - begin();
	mov	rdi, rbx	#, this
# /usr/include/c++/15.2.1/bits/vector.tcc:571:       const size_type __elems = end() - begin();
	mov	rbp, rax	# D.166912,
# /usr/include/c++/15.2.1/bits/vector.tcc:571:       const size_type __elems = end() - begin();
	call	_ZNSt6vectorI6ButtonSaIS0_EE3endEv	#
# /usr/include/c++/15.2.1/bits/vector.tcc:572:       pointer __new_start(this->_M_allocate(__len));
	mov	rdi, r12	#, _14
# /usr/include/c++/15.2.1/bits/stl_iterator.h:1340:     { return __lhs.base() - __rhs.base(); }
	sub	rax, rbp	# D.166911, D.166912
	mov	r13, rax	# _19, D.166911
# /usr/include/c++/15.2.1/bits/vector.tcc:572:       pointer __new_start(this->_M_allocate(__len));
	call	_ZNSt12_Vector_baseI6ButtonSaIS0_EE11_M_allocateEm.isra.0	#
.LEHE33:
# /usr/include/c++/15.2.1/bits/vector.tcc:576: 	_Guard_alloc __guard(__new_start, __len, *this);
	mov	rdx, r12	#, _14
	lea	rdi, 80[rsp]	#,
	mov	rcx, rbx	#, this
# /usr/include/c++/15.2.1/bits/vector.tcc:572:       pointer __new_start(this->_M_allocate(__len));
	mov	rbp, rax	# _23,
# /usr/include/c++/15.2.1/bits/vector.tcc:576: 	_Guard_alloc __guard(__new_start, __len, *this);
	mov	rsi, rax	#, _23
	call	_ZNSt6vectorI6ButtonSaIS0_EE12_Guard_allocC1EPS0_mRSt12_Vector_baseIS0_S1_E	#
# /usr/include/c++/15.2.1/bits/vector.tcc:586: 	_Alloc_traits::construct(this->_M_impl,
	lea	rdi, 0[rbp+r13]	# _3,
# /usr/include/c++/15.2.1/bits/new_allocator.h:191: 	{ ::new((void *)__p) _Up(std::forward<_Args>(__args)...); }
	lea	rdx, 79[rsp]	# tmp136,
# /usr/include/c++/15.2.1/bits/new_allocator.h:191: 	{ ::new((void *)__p) _Up(std::forward<_Args>(__args)...); }
	call	_ZnwmPv.isra.0	#
# /usr/include/c++/15.2.1/bits/new_allocator.h:191: 	{ ::new((void *)__p) _Up(std::forward<_Args>(__args)...); }
	mov	rsi, QWORD PTR 48[rsp]	#, %sfp
	lea	rdi, 112[rsp]	#,
# /usr/include/c++/15.2.1/bits/new_allocator.h:191: 	{ ::new((void *)__p) _Up(std::forward<_Args>(__args)...); }
	mov	QWORD PTR 40[rsp], rax	# %sfp,
.LEHB34:
# /usr/include/c++/15.2.1/bits/new_allocator.h:191: 	{ ::new((void *)__p) _Up(std::forward<_Args>(__args)...); }
	call	_ZNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEEC1IS3_EEPKcRKS3_	#
.LEHE34:
# /usr/include/c++/15.2.1/bits/new_allocator.h:191: 	{ ::new((void *)__p) _Up(std::forward<_Args>(__args)...); }
	mov	rcx, QWORD PTR 32[rsp]	# __args#2, %sfp
	mov	rdx, QWORD PTR 24[rsp]	# __args#1, %sfp
	lea	r9, 112[rsp]	#,
	mov	r10, QWORD PTR 16[rsp]	# __args#0, %sfp
	mov	r8, QWORD PTR 56[rsp]	# __args#3, %sfp
	mov	ecx, DWORD PTR [rcx]	# *__args#2_29(D), *__args#2_29(D)
	mov	edx, DWORD PTR [rdx]	# *__args#1_31(D), *__args#1_31(D)
	mov	esi, DWORD PTR [r10]	# *__args#0_33(D), *__args#0_33(D)
	mov	r8d, DWORD PTR [r8]	#, *__args#3_27(D)
	mov	rdi, QWORD PTR 40[rsp]	#, %sfp
.LEHB35:
	call	[QWORD PTR _ZN6ButtonC1EiiiiRKNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEEE@GOTPCREL[rip]]	#
.LEHE35:
# /usr/include/c++/15.2.1/bits/vector.tcc:646:       this->_M_impl._M_end_of_storage = __new_start + __len;
	imul	r12, r12, 56	# _9, _14,
# /usr/include/c++/15.2.1/bits/new_allocator.h:191: 	{ ::new((void *)__p) _Up(std::forward<_Args>(__args)...); }
	lea	rdi, 112[rsp]	#,
	call	[QWORD PTR _ZNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEED1Ev@GOTPCREL[rip]]	#
# /usr/include/c++/15.2.1/bits/vector.tcc:599: 	    __new_finish = _S_relocate(__old_start, __old_finish,
	mov	rsi, QWORD PTR 8[rsp]	#, %sfp
	mov	rdx, rbp	#, _23
	mov	rdi, r14	#, __old_start
	call	_ZNSt6vectorI6ButtonSaIS0_EE11_S_relocateEPS0_S3_S3_RS1_.isra.0	#
# /usr/include/c++/15.2.1/bits/vector.tcc:640:       }
	lea	rdi, 80[rsp]	#,
# /usr/include/c++/15.2.1/bits/vector.tcc:638: 	__guard._M_storage = __old_start;
	mov	QWORD PTR 80[rsp], r14	# __guard._M_storage, __old_start
# /usr/include/c++/15.2.1/bits/vector.tcc:639: 	__guard._M_len = this->_M_impl._M_end_of_storage - __old_start;
	movabs	rdx, 7905747460161236407	# tmp148,
# /usr/include/c++/15.2.1/bits/vector.tcc:599: 	    __new_finish = _S_relocate(__old_start, __old_finish,
	mov	r13, rax	# __new_finish,
# /usr/include/c++/15.2.1/bits/vector.tcc:639: 	__guard._M_len = this->_M_impl._M_end_of_storage - __old_start;
	mov	rax, QWORD PTR 16[rbx]	# _6, this_12(D)->D.155608._M_impl.D.154943._M_end_of_storage
# /usr/include/c++/15.2.1/bits/vector.tcc:601: 	    ++__new_finish;
	add	r13, 56	# tmp150,
# /usr/include/c++/15.2.1/bits/vector.tcc:639: 	__guard._M_len = this->_M_impl._M_end_of_storage - __old_start;
	sub	rax, r14	# _6, __old_start
	sar	rax, 3	# tmp146,
	imul	rax, rdx	# _7, tmp148
# /usr/include/c++/15.2.1/bits/vector.tcc:639: 	__guard._M_len = this->_M_impl._M_end_of_storage - __old_start;
	mov	QWORD PTR 88[rsp], rax	# __guard._M_len, _7
# /usr/include/c++/15.2.1/bits/vector.tcc:640:       }
	call	_ZNSt6vectorI6ButtonSaIS0_EE12_Guard_allocD1Ev	#
# /usr/include/c++/15.2.1/bits/vector.tcc:644:       this->_M_impl._M_start = __new_start;
	mov	QWORD PTR [rbx], rbp	# this_12(D)->D.155608._M_impl.D.154943._M_start, _23
# /usr/include/c++/15.2.1/bits/vector.tcc:646:       this->_M_impl._M_end_of_storage = __new_start + __len;
	add	rbp, r12	# tmp152, _9
# /usr/include/c++/15.2.1/bits/vector.tcc:601: 	    ++__new_finish;
	mov	QWORD PTR 8[rbx], r13	# this_12(D)->D.155608._M_impl.D.154943._M_finish, tmp150
# /usr/include/c++/15.2.1/bits/vector.tcc:646:       this->_M_impl._M_end_of_storage = __new_start + __len;
	mov	QWORD PTR 16[rbx], rbp	# this_12(D)->D.155608._M_impl.D.154943._M_end_of_storage, tmp152
# /usr/include/c++/15.2.1/bits/vector.tcc:647:     }
	mov	rax, QWORD PTR 152[rsp]	# tmp177, D.173706
	sub	rax, QWORD PTR fs:40	# tmp177, MEM[(<address-space-1> long unsigned int *)40B]
	jne	.L567	#,
	add	rsp, 168	#,
	.cfi_remember_state
	.cfi_def_cfa_offset 56
	pop	rbx	#
	.cfi_def_cfa_offset 48
	pop	rbp	#
	.cfi_def_cfa_offset 40
	pop	r12	#
	.cfi_def_cfa_offset 32
	pop	r13	#
	.cfi_def_cfa_offset 24
	pop	r14	#
	.cfi_def_cfa_offset 16
	pop	r15	#
	.cfi_def_cfa_offset 8
	ret	
.L561:
	.cfi_restore_state
# /usr/include/c++/15.2.1/bits/new_allocator.h:191: 	{ ::new((void *)__p) _Up(std::forward<_Args>(__args)...); }
	lea	rdi, 112[rsp]	#,
	call	[QWORD PTR _ZNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEED1Ev@GOTPCREL[rip]]	#
.L562:
# /usr/include/c++/15.2.1/bits/vector.tcc:640:       }
	lea	rdi, 80[rsp]	#,
	call	_ZNSt6vectorI6ButtonSaIS0_EE12_Guard_allocD1Ev	#
	mov	rax, QWORD PTR 152[rsp]	# tmp178, D.173706
	sub	rax, QWORD PTR fs:40	# tmp178, MEM[(<address-space-1> long unsigned int *)40B]
	je	.L563	#,
.L567:
# /usr/include/c++/15.2.1/bits/vector.tcc:647:     }
	call	[QWORD PTR __stack_chk_fail@GOTPCREL[rip]]	#
.L566:
# /usr/include/c++/15.2.1/bits/new_allocator.h:191: 	{ ::new((void *)__p) _Up(std::forward<_Args>(__args)...); }
	mov	rbx, rax	# tmp175,
	jmp	.L561	#
.L565:
# /usr/include/c++/15.2.1/bits/vector.tcc:640:       }
	mov	rbx, rax	# tmp154, tmp176
	jmp	.L562	#
.L563:
	mov	rdi, rbx	#, tmp154
.LEHB36:
	call	[QWORD PTR _Unwind_Resume@GOTPCREL[rip]]	#
.LEHE36:
	.cfi_endproc
.LFE13542:
	.section	.gcc_except_table
.LLSDA13542:
	.byte	0xff
	.byte	0xff
	.byte	0x1
	.uleb128 .LLSDACSE13542-.LLSDACSB13542
.LLSDACSB13542:
	.uleb128 .LEHB33-.LFB13542
	.uleb128 .LEHE33-.LEHB33
	.uleb128 0
	.uleb128 0
	.uleb128 .LEHB34-.LFB13542
	.uleb128 .LEHE34-.LEHB34
	.uleb128 .L565-.LFB13542
	.uleb128 0
	.uleb128 .LEHB35-.LFB13542
	.uleb128 .LEHE35-.LEHB35
	.uleb128 .L566-.LFB13542
	.uleb128 0
	.uleb128 .LEHB36-.LFB13542
	.uleb128 .LEHE36-.LEHB36
	.uleb128 0
	.uleb128 0
.LLSDACSE13542:
	.section	.text._ZNSt6vectorI6ButtonSaIS0_EE17_M_realloc_appendIJiiRKiS5_RA27_KcEEEvDpOT_,"axG",@progbits,_ZNSt6vectorI6ButtonSaIS0_EE17_M_realloc_appendIJiiRKiS5_RA27_KcEEEvDpOT_,comdat
	.size	_ZNSt6vectorI6ButtonSaIS0_EE17_M_realloc_appendIJiiRKiS5_RA27_KcEEEvDpOT_, .-_ZNSt6vectorI6ButtonSaIS0_EE17_M_realloc_appendIJiiRKiS5_RA27_KcEEEvDpOT_
	.section	.text.unlikely
	.align 2
.LCOLDB21:
	.text
.LHOTB21:
	.align 2
	.p2align 4
	.type	_ZNSt6vectorI6ButtonSaIS0_EE12emplace_backIJiiRKiS5_RA27_KcEEERS0_DpOT_.isra.0, @function
_ZNSt6vectorI6ButtonSaIS0_EE12emplace_backIJiiRKiS5_RA27_KcEEERS0_DpOT_.isra.0:
.LFB13940:
	.cfi_startproc
	.cfi_personality 0x9b,DW.ref.__gxx_personality_v0
	.cfi_lsda 0x1b,.LLSDA13940
	push	r14	#
	.cfi_def_cfa_offset 16
	.cfi_offset 14, -16
	push	r13	#
	.cfi_def_cfa_offset 24
	.cfi_offset 13, -24
	push	r12	#
	.cfi_def_cfa_offset 32
	.cfi_offset 12, -32
	mov	r12, rsi	# __args#0, __args#0
	push	rbp	#
	.cfi_def_cfa_offset 40
	.cfi_offset 6, -40
	push	rbx	#
	.cfi_def_cfa_offset 48
	.cfi_offset 3, -48
	mov	rbx, rdi	# this, this
	sub	rsp, 80	#,
	.cfi_def_cfa_offset 128
# /usr/include/c++/15.2.1/bits/vector.tcc:114: 	if (this->_M_impl._M_finish != this->_M_impl._M_end_of_storage)
	mov	rdi, QWORD PTR 8[rdi]	# _2, this_1(D)->D.155608._M_impl.D.154943._M_finish
# /usr/include/c++/15.2.1/bits/vector.tcc:111:       vector<_Tp, _Alloc>::
	mov	r13, QWORD PTR fs:40	# __args#1, MEM[(<address-space-1> long unsigned int *)40B]
	mov	QWORD PTR 72[rsp], r13	# D.173723, __args#1
	mov	r13, rdx	# __args#1, __args#1
# /usr/include/c++/15.2.1/bits/vector.tcc:114: 	if (this->_M_impl._M_finish != this->_M_impl._M_end_of_storage)
	cmp	rdi, QWORD PTR 16[rbx]	# _2, this_1(D)->D.155608._M_impl.D.154943._M_end_of_storage
	je	.L570	#,
# /usr/include/c++/15.2.1/bits/new_allocator.h:191: 	{ ::new((void *)__p) _Up(std::forward<_Args>(__args)...); }
	lea	rbp, 32[rsp]	# tmp129,
	mov	QWORD PTR 8[rsp], r8	# %sfp, __args#3
	mov	rsi, r9	#, __args#4
	lea	rdx, 31[rsp]	# tmp116,
	mov	QWORD PTR [rsp], rcx	# %sfp, __args#2
# /usr/include/c++/15.2.1/bits/new_allocator.h:191: 	{ ::new((void *)__p) _Up(std::forward<_Args>(__args)...); }
	call	_ZnwmPv.isra.0	#
# /usr/include/c++/15.2.1/bits/new_allocator.h:191: 	{ ::new((void *)__p) _Up(std::forward<_Args>(__args)...); }
	mov	rdi, rbp	#, tmp129
# /usr/include/c++/15.2.1/bits/new_allocator.h:191: 	{ ::new((void *)__p) _Up(std::forward<_Args>(__args)...); }
	mov	r14, rax	# _4,
.LEHB37:
# /usr/include/c++/15.2.1/bits/new_allocator.h:191: 	{ ::new((void *)__p) _Up(std::forward<_Args>(__args)...); }
	call	_ZNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEEC1IS3_EEPKcRKS3_	#
.LEHE37:
# /usr/include/c++/15.2.1/bits/new_allocator.h:191: 	{ ::new((void *)__p) _Up(std::forward<_Args>(__args)...); }
	mov	rcx, QWORD PTR [rsp]	# __args#2, %sfp
	mov	edx, DWORD PTR 0[r13]	# *__args#1_10(D), *__args#1_10(D)
	mov	r9, rbp	#, tmp129
	mov	r8, QWORD PTR 8[rsp]	# __args#3, %sfp
	mov	esi, DWORD PTR [r12]	# *__args#0_12(D), *__args#0_12(D)
	mov	rdi, r14	#, _4
	mov	ecx, DWORD PTR [rcx]	# *__args#2_8(D), *__args#2_8(D)
	mov	r8d, DWORD PTR [r8]	#, *__args#3_6(D)
.LEHB38:
	call	[QWORD PTR _ZN6ButtonC1EiiiiRKNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEEE@GOTPCREL[rip]]	#
.LEHE38:
# /usr/include/c++/15.2.1/bits/new_allocator.h:191: 	{ ::new((void *)__p) _Up(std::forward<_Args>(__args)...); }
	mov	rdi, rbp	#, tmp129
	call	[QWORD PTR _ZNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEED1Ev@GOTPCREL[rip]]	#
# /usr/include/c++/15.2.1/bits/vector.tcc:119: 	    ++this->_M_impl._M_finish;
	add	QWORD PTR 8[rbx], 56	# this_1(D)->D.155608._M_impl.D.154943._M_finish,
# /usr/include/c++/15.2.1/bits/vector.tcc:127:       }
	mov	rax, QWORD PTR 72[rsp]	# tmp138, D.173723
	sub	rax, QWORD PTR fs:40	# tmp138, MEM[(<address-space-1> long unsigned int *)40B]
	jne	.L577	#,
	add	rsp, 80	#,
	.cfi_remember_state
	.cfi_def_cfa_offset 48
	pop	rbx	#
	.cfi_def_cfa_offset 40
	pop	rbp	#
	.cfi_def_cfa_offset 32
	pop	r12	#
	.cfi_def_cfa_offset 24
	pop	r13	#
	.cfi_def_cfa_offset 16
	pop	r14	#
	.cfi_def_cfa_offset 8
	ret	
	.p2align 4,,10
	.p2align 3
.L570:
	.cfi_restore_state
# /usr/include/c++/15.2.1/bits/vector.tcc:123: 	  _M_realloc_append(std::forward<_Args>(__args)...);
	mov	rax, QWORD PTR 72[rsp]	# tmp140, D.173723
	sub	rax, QWORD PTR fs:40	# tmp140, MEM[(<address-space-1> long unsigned int *)40B]
	jne	.L577	#,
# /usr/include/c++/15.2.1/bits/vector.tcc:127:       }
	add	rsp, 80	#,
	.cfi_remember_state
	.cfi_def_cfa_offset 48
# /usr/include/c++/15.2.1/bits/vector.tcc:123: 	  _M_realloc_append(std::forward<_Args>(__args)...);
	mov	rdx, r13	#, __args#1
	mov	rdi, rbx	#, this
# /usr/include/c++/15.2.1/bits/vector.tcc:127:       }
	pop	rbx	#
	.cfi_def_cfa_offset 40
	pop	rbp	#
	.cfi_def_cfa_offset 32
	pop	r12	#
	.cfi_def_cfa_offset 24
	pop	r13	#
	.cfi_def_cfa_offset 16
	pop	r14	#
	.cfi_def_cfa_offset 8
.LEHB39:
# /usr/include/c++/15.2.1/bits/vector.tcc:123: 	  _M_realloc_append(std::forward<_Args>(__args)...);
	jmp	_ZNSt6vectorI6ButtonSaIS0_EE17_M_realloc_appendIJiiRKiS5_RA27_KcEEEvDpOT_	#
.LEHE39:
.L577:
	.cfi_restore_state
# /usr/include/c++/15.2.1/bits/vector.tcc:127:       }
	call	[QWORD PTR __stack_chk_fail@GOTPCREL[rip]]	#
.L576:
# /usr/include/c++/15.2.1/bits/new_allocator.h:191: 	{ ::new((void *)__p) _Up(std::forward<_Args>(__args)...); }
	mov	rbx, rax	# tmp137,
	jmp	.L572	#
	.section	.gcc_except_table
.LLSDA13940:
	.byte	0xff
	.byte	0xff
	.byte	0x1
	.uleb128 .LLSDACSE13940-.LLSDACSB13940
.LLSDACSB13940:
	.uleb128 .LEHB37-.LFB13940
	.uleb128 .LEHE37-.LEHB37
	.uleb128 0
	.uleb128 0
	.uleb128 .LEHB38-.LFB13940
	.uleb128 .LEHE38-.LEHB38
	.uleb128 .L576-.LFB13940
	.uleb128 0
	.uleb128 .LEHB39-.LFB13940
	.uleb128 .LEHE39-.LEHB39
	.uleb128 0
	.uleb128 0
.LLSDACSE13940:
	.text
	.cfi_endproc
	.section	.text.unlikely
	.cfi_startproc
	.cfi_personality 0x9b,DW.ref.__gxx_personality_v0
	.cfi_lsda 0x1b,.LLSDAC13940
	.type	_ZNSt6vectorI6ButtonSaIS0_EE12emplace_backIJiiRKiS5_RA27_KcEEERS0_DpOT_.isra.0.cold, @function
_ZNSt6vectorI6ButtonSaIS0_EE12emplace_backIJiiRKiS5_RA27_KcEEERS0_DpOT_.isra.0.cold:
.LFSB13940:
.L572:
	.cfi_def_cfa_offset 128
	.cfi_offset 3, -48
	.cfi_offset 6, -40
	.cfi_offset 12, -32
	.cfi_offset 13, -24
	.cfi_offset 14, -16
	mov	rdi, rbp	#, tmp129
	call	[QWORD PTR _ZNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEED1Ev@GOTPCREL[rip]]	#
	mov	rax, QWORD PTR 72[rsp]	# tmp139, D.173723
	sub	rax, QWORD PTR fs:40	# tmp139, MEM[(<address-space-1> long unsigned int *)40B]
	jne	.L579	#,
	mov	rdi, rbx	#, tmp137
.LEHB40:
	call	[QWORD PTR _Unwind_Resume@GOTPCREL[rip]]	#
.LEHE40:
.L579:
	call	[QWORD PTR __stack_chk_fail@GOTPCREL[rip]]	#
	.cfi_endproc
.LFE13940:
	.section	.gcc_except_table
.LLSDAC13940:
	.byte	0xff
	.byte	0xff
	.byte	0x1
	.uleb128 .LLSDACSEC13940-.LLSDACSBC13940
.LLSDACSBC13940:
	.uleb128 .LEHB40-.LCOLDB21
	.uleb128 .LEHE40-.LEHB40
	.uleb128 0
	.uleb128 0
.LLSDACSEC13940:
	.section	.text.unlikely
	.text
	.size	_ZNSt6vectorI6ButtonSaIS0_EE12emplace_backIJiiRKiS5_RA27_KcEEERS0_DpOT_.isra.0, .-_ZNSt6vectorI6ButtonSaIS0_EE12emplace_backIJiiRKiS5_RA27_KcEEERS0_DpOT_.isra.0
	.section	.text.unlikely
	.size	_ZNSt6vectorI6ButtonSaIS0_EE12emplace_backIJiiRKiS5_RA27_KcEEERS0_DpOT_.isra.0.cold, .-_ZNSt6vectorI6ButtonSaIS0_EE12emplace_backIJiiRKiS5_RA27_KcEEERS0_DpOT_.isra.0.cold
.LCOLDE21:
	.text
.LHOTE21:
	.section	.text._ZNSt6vectorI6ButtonSaIS0_EE17_M_realloc_appendIJiiRKiS5_RA36_KcEEEvDpOT_,"axG",@progbits,_ZNSt6vectorI6ButtonSaIS0_EE17_M_realloc_appendIJiiRKiS5_RA36_KcEEEvDpOT_,comdat
	.align 2
	.p2align 4
	.weak	_ZNSt6vectorI6ButtonSaIS0_EE17_M_realloc_appendIJiiRKiS5_RA36_KcEEEvDpOT_
	.type	_ZNSt6vectorI6ButtonSaIS0_EE17_M_realloc_appendIJiiRKiS5_RA36_KcEEEvDpOT_, @function
_ZNSt6vectorI6ButtonSaIS0_EE17_M_realloc_appendIJiiRKiS5_RA36_KcEEEvDpOT_:
.LFB13539:
	.cfi_startproc
	.cfi_personality 0x9b,DW.ref.__gxx_personality_v0
	.cfi_lsda 0x1b,.LLSDA13539
	push	r15	#
	.cfi_def_cfa_offset 16
	.cfi_offset 15, -16
	push	r14	#
	.cfi_def_cfa_offset 24
	.cfi_offset 14, -24
	push	r13	#
	.cfi_def_cfa_offset 32
	.cfi_offset 13, -32
	push	r12	#
	.cfi_def_cfa_offset 40
	.cfi_offset 12, -40
	push	rbp	#
	.cfi_def_cfa_offset 48
	.cfi_offset 6, -48
	push	rbx	#
	.cfi_def_cfa_offset 56
	.cfi_offset 3, -56
	mov	rbx, rdi	# this, this
	sub	rsp, 168	#,
	.cfi_def_cfa_offset 224
# /usr/include/c++/15.2.1/bits/vector.tcc:557:       vector<_Tp, _Alloc>::
	mov	QWORD PTR 32[rsp], rcx	# %sfp, __args#2
	mov	QWORD PTR 56[rsp], r8	# %sfp, __args#3
	mov	QWORD PTR 48[rsp], r9	# %sfp, __args#4
	mov	QWORD PTR 16[rsp], rsi	# %sfp, __args#0
# /usr/include/c++/15.2.1/bits/vector.tcc:566:       const size_type __len = _M_check_len(1u, "vector::_M_realloc_append");
	mov	esi, 1	#,
# /usr/include/c++/15.2.1/bits/vector.tcc:557:       vector<_Tp, _Alloc>::
	mov	QWORD PTR 24[rsp], rdx	# %sfp, __args#1
# /usr/include/c++/15.2.1/bits/vector.tcc:566:       const size_type __len = _M_check_len(1u, "vector::_M_realloc_append");
	mov	rdx, QWORD PTR fs:40	#, MEM[(<address-space-1> long unsigned int *)40B]
	mov	QWORD PTR 152[rsp], rdx	# D.173732,
	lea	rdx, .LC17[rip]	#,
.LEHB41:
	call	_ZNKSt6vectorI6ButtonSaIS0_EE12_M_check_lenEmPKc	#
# /usr/include/c++/15.2.1/bits/vector.tcc:571:       const size_type __elems = end() - begin();
	mov	rdi, rbx	#, this
# /usr/include/c++/15.2.1/bits/vector.tcc:569:       pointer __old_start = this->_M_impl._M_start;
	mov	r14, QWORD PTR [rbx]	# __old_start, this_12(D)->D.155608._M_impl.D.154943._M_start
# /usr/include/c++/15.2.1/bits/vector.tcc:566:       const size_type __len = _M_check_len(1u, "vector::_M_realloc_append");
	mov	r12, rax	# _14,
# /usr/include/c++/15.2.1/bits/vector.tcc:570:       pointer __old_finish = this->_M_impl._M_finish;
	mov	rax, QWORD PTR 8[rbx]	# __old_finish, this_12(D)->D.155608._M_impl.D.154943._M_finish
	mov	QWORD PTR 8[rsp], rax	# %sfp, __old_finish
# /usr/include/c++/15.2.1/bits/vector.tcc:571:       const size_type __elems = end() - begin();
	call	_ZNSt6vectorI6ButtonSaIS0_EE5beginEv	#
# /usr/include/c++/15.2.1/bits/vector.tcc:571:       const size_type __elems = end() - begin();
	mov	rdi, rbx	#, this
# /usr/include/c++/15.2.1/bits/vector.tcc:571:       const size_type __elems = end() - begin();
	mov	rbp, rax	# D.166885,
# /usr/include/c++/15.2.1/bits/vector.tcc:571:       const size_type __elems = end() - begin();
	call	_ZNSt6vectorI6ButtonSaIS0_EE3endEv	#
# /usr/include/c++/15.2.1/bits/vector.tcc:572:       pointer __new_start(this->_M_allocate(__len));
	mov	rdi, r12	#, _14
# /usr/include/c++/15.2.1/bits/stl_iterator.h:1340:     { return __lhs.base() - __rhs.base(); }
	sub	rax, rbp	# D.166884, D.166885
	mov	r13, rax	# _19, D.166884
# /usr/include/c++/15.2.1/bits/vector.tcc:572:       pointer __new_start(this->_M_allocate(__len));
	call	_ZNSt12_Vector_baseI6ButtonSaIS0_EE11_M_allocateEm.isra.0	#
.LEHE41:
# /usr/include/c++/15.2.1/bits/vector.tcc:576: 	_Guard_alloc __guard(__new_start, __len, *this);
	mov	rdx, r12	#, _14
	lea	rdi, 80[rsp]	#,
	mov	rcx, rbx	#, this
# /usr/include/c++/15.2.1/bits/vector.tcc:572:       pointer __new_start(this->_M_allocate(__len));
	mov	rbp, rax	# _23,
# /usr/include/c++/15.2.1/bits/vector.tcc:576: 	_Guard_alloc __guard(__new_start, __len, *this);
	mov	rsi, rax	#, _23
	call	_ZNSt6vectorI6ButtonSaIS0_EE12_Guard_allocC1EPS0_mRSt12_Vector_baseIS0_S1_E	#
# /usr/include/c++/15.2.1/bits/vector.tcc:586: 	_Alloc_traits::construct(this->_M_impl,
	lea	rdi, 0[rbp+r13]	# _3,
# /usr/include/c++/15.2.1/bits/new_allocator.h:191: 	{ ::new((void *)__p) _Up(std::forward<_Args>(__args)...); }
	lea	rdx, 79[rsp]	# tmp136,
# /usr/include/c++/15.2.1/bits/new_allocator.h:191: 	{ ::new((void *)__p) _Up(std::forward<_Args>(__args)...); }
	call	_ZnwmPv.isra.0	#
# /usr/include/c++/15.2.1/bits/new_allocator.h:191: 	{ ::new((void *)__p) _Up(std::forward<_Args>(__args)...); }
	mov	rsi, QWORD PTR 48[rsp]	#, %sfp
	lea	rdi, 112[rsp]	#,
# /usr/include/c++/15.2.1/bits/new_allocator.h:191: 	{ ::new((void *)__p) _Up(std::forward<_Args>(__args)...); }
	mov	QWORD PTR 40[rsp], rax	# %sfp,
.LEHB42:
# /usr/include/c++/15.2.1/bits/new_allocator.h:191: 	{ ::new((void *)__p) _Up(std::forward<_Args>(__args)...); }
	call	_ZNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEEC1IS3_EEPKcRKS3_	#
.LEHE42:
# /usr/include/c++/15.2.1/bits/new_allocator.h:191: 	{ ::new((void *)__p) _Up(std::forward<_Args>(__args)...); }
	mov	rcx, QWORD PTR 32[rsp]	# __args#2, %sfp
	mov	rdx, QWORD PTR 24[rsp]	# __args#1, %sfp
	lea	r9, 112[rsp]	#,
	mov	r10, QWORD PTR 16[rsp]	# __args#0, %sfp
	mov	r8, QWORD PTR 56[rsp]	# __args#3, %sfp
	mov	ecx, DWORD PTR [rcx]	# *__args#2_29(D), *__args#2_29(D)
	mov	edx, DWORD PTR [rdx]	# *__args#1_31(D), *__args#1_31(D)
	mov	esi, DWORD PTR [r10]	# *__args#0_33(D), *__args#0_33(D)
	mov	r8d, DWORD PTR [r8]	#, *__args#3_27(D)
	mov	rdi, QWORD PTR 40[rsp]	#, %sfp
.LEHB43:
	call	[QWORD PTR _ZN6ButtonC1EiiiiRKNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEEE@GOTPCREL[rip]]	#
.LEHE43:
# /usr/include/c++/15.2.1/bits/vector.tcc:646:       this->_M_impl._M_end_of_storage = __new_start + __len;
	imul	r12, r12, 56	# _9, _14,
# /usr/include/c++/15.2.1/bits/new_allocator.h:191: 	{ ::new((void *)__p) _Up(std::forward<_Args>(__args)...); }
	lea	rdi, 112[rsp]	#,
	call	[QWORD PTR _ZNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEED1Ev@GOTPCREL[rip]]	#
# /usr/include/c++/15.2.1/bits/vector.tcc:599: 	    __new_finish = _S_relocate(__old_start, __old_finish,
	mov	rsi, QWORD PTR 8[rsp]	#, %sfp
	mov	rdx, rbp	#, _23
	mov	rdi, r14	#, __old_start
	call	_ZNSt6vectorI6ButtonSaIS0_EE11_S_relocateEPS0_S3_S3_RS1_.isra.0	#
# /usr/include/c++/15.2.1/bits/vector.tcc:640:       }
	lea	rdi, 80[rsp]	#,
# /usr/include/c++/15.2.1/bits/vector.tcc:638: 	__guard._M_storage = __old_start;
	mov	QWORD PTR 80[rsp], r14	# __guard._M_storage, __old_start
# /usr/include/c++/15.2.1/bits/vector.tcc:639: 	__guard._M_len = this->_M_impl._M_end_of_storage - __old_start;
	movabs	rdx, 7905747460161236407	# tmp148,
# /usr/include/c++/15.2.1/bits/vector.tcc:599: 	    __new_finish = _S_relocate(__old_start, __old_finish,
	mov	r13, rax	# __new_finish,
# /usr/include/c++/15.2.1/bits/vector.tcc:639: 	__guard._M_len = this->_M_impl._M_end_of_storage - __old_start;
	mov	rax, QWORD PTR 16[rbx]	# _6, this_12(D)->D.155608._M_impl.D.154943._M_end_of_storage
# /usr/include/c++/15.2.1/bits/vector.tcc:601: 	    ++__new_finish;
	add	r13, 56	# tmp150,
# /usr/include/c++/15.2.1/bits/vector.tcc:639: 	__guard._M_len = this->_M_impl._M_end_of_storage - __old_start;
	sub	rax, r14	# _6, __old_start
	sar	rax, 3	# tmp146,
	imul	rax, rdx	# _7, tmp148
# /usr/include/c++/15.2.1/bits/vector.tcc:639: 	__guard._M_len = this->_M_impl._M_end_of_storage - __old_start;
	mov	QWORD PTR 88[rsp], rax	# __guard._M_len, _7
# /usr/include/c++/15.2.1/bits/vector.tcc:640:       }
	call	_ZNSt6vectorI6ButtonSaIS0_EE12_Guard_allocD1Ev	#
# /usr/include/c++/15.2.1/bits/vector.tcc:644:       this->_M_impl._M_start = __new_start;
	mov	QWORD PTR [rbx], rbp	# this_12(D)->D.155608._M_impl.D.154943._M_start, _23
# /usr/include/c++/15.2.1/bits/vector.tcc:646:       this->_M_impl._M_end_of_storage = __new_start + __len;
	add	rbp, r12	# tmp152, _9
# /usr/include/c++/15.2.1/bits/vector.tcc:601: 	    ++__new_finish;
	mov	QWORD PTR 8[rbx], r13	# this_12(D)->D.155608._M_impl.D.154943._M_finish, tmp150
# /usr/include/c++/15.2.1/bits/vector.tcc:646:       this->_M_impl._M_end_of_storage = __new_start + __len;
	mov	QWORD PTR 16[rbx], rbp	# this_12(D)->D.155608._M_impl.D.154943._M_end_of_storage, tmp152
# /usr/include/c++/15.2.1/bits/vector.tcc:647:     }
	mov	rax, QWORD PTR 152[rsp]	# tmp177, D.173732
	sub	rax, QWORD PTR fs:40	# tmp177, MEM[(<address-space-1> long unsigned int *)40B]
	jne	.L587	#,
	add	rsp, 168	#,
	.cfi_remember_state
	.cfi_def_cfa_offset 56
	pop	rbx	#
	.cfi_def_cfa_offset 48
	pop	rbp	#
	.cfi_def_cfa_offset 40
	pop	r12	#
	.cfi_def_cfa_offset 32
	pop	r13	#
	.cfi_def_cfa_offset 24
	pop	r14	#
	.cfi_def_cfa_offset 16
	pop	r15	#
	.cfi_def_cfa_offset 8
	ret	
.L581:
	.cfi_restore_state
# /usr/include/c++/15.2.1/bits/new_allocator.h:191: 	{ ::new((void *)__p) _Up(std::forward<_Args>(__args)...); }
	lea	rdi, 112[rsp]	#,
	call	[QWORD PTR _ZNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEED1Ev@GOTPCREL[rip]]	#
.L582:
# /usr/include/c++/15.2.1/bits/vector.tcc:640:       }
	lea	rdi, 80[rsp]	#,
	call	_ZNSt6vectorI6ButtonSaIS0_EE12_Guard_allocD1Ev	#
	mov	rax, QWORD PTR 152[rsp]	# tmp178, D.173732
	sub	rax, QWORD PTR fs:40	# tmp178, MEM[(<address-space-1> long unsigned int *)40B]
	je	.L583	#,
.L587:
# /usr/include/c++/15.2.1/bits/vector.tcc:647:     }
	call	[QWORD PTR __stack_chk_fail@GOTPCREL[rip]]	#
.L586:
# /usr/include/c++/15.2.1/bits/new_allocator.h:191: 	{ ::new((void *)__p) _Up(std::forward<_Args>(__args)...); }
	mov	rbx, rax	# tmp175,
	jmp	.L581	#
.L585:
# /usr/include/c++/15.2.1/bits/vector.tcc:640:       }
	mov	rbx, rax	# tmp154, tmp176
	jmp	.L582	#
.L583:
	mov	rdi, rbx	#, tmp154
.LEHB44:
	call	[QWORD PTR _Unwind_Resume@GOTPCREL[rip]]	#
.LEHE44:
	.cfi_endproc
.LFE13539:
	.section	.gcc_except_table
.LLSDA13539:
	.byte	0xff
	.byte	0xff
	.byte	0x1
	.uleb128 .LLSDACSE13539-.LLSDACSB13539
.LLSDACSB13539:
	.uleb128 .LEHB41-.LFB13539
	.uleb128 .LEHE41-.LEHB41
	.uleb128 0
	.uleb128 0
	.uleb128 .LEHB42-.LFB13539
	.uleb128 .LEHE42-.LEHB42
	.uleb128 .L585-.LFB13539
	.uleb128 0
	.uleb128 .LEHB43-.LFB13539
	.uleb128 .LEHE43-.LEHB43
	.uleb128 .L586-.LFB13539
	.uleb128 0
	.uleb128 .LEHB44-.LFB13539
	.uleb128 .LEHE44-.LEHB44
	.uleb128 0
	.uleb128 0
.LLSDACSE13539:
	.section	.text._ZNSt6vectorI6ButtonSaIS0_EE17_M_realloc_appendIJiiRKiS5_RA36_KcEEEvDpOT_,"axG",@progbits,_ZNSt6vectorI6ButtonSaIS0_EE17_M_realloc_appendIJiiRKiS5_RA36_KcEEEvDpOT_,comdat
	.size	_ZNSt6vectorI6ButtonSaIS0_EE17_M_realloc_appendIJiiRKiS5_RA36_KcEEEvDpOT_, .-_ZNSt6vectorI6ButtonSaIS0_EE17_M_realloc_appendIJiiRKiS5_RA36_KcEEEvDpOT_
	.section	.text.unlikely
	.align 2
.LCOLDB22:
	.text
.LHOTB22:
	.align 2
	.p2align 4
	.type	_ZNSt6vectorI6ButtonSaIS0_EE12emplace_backIJiiRKiS5_RA36_KcEEERS0_DpOT_.isra.0, @function
_ZNSt6vectorI6ButtonSaIS0_EE12emplace_backIJiiRKiS5_RA36_KcEEERS0_DpOT_.isra.0:
.LFB13941:
	.cfi_startproc
	.cfi_personality 0x9b,DW.ref.__gxx_personality_v0
	.cfi_lsda 0x1b,.LLSDA13941
	push	r14	#
	.cfi_def_cfa_offset 16
	.cfi_offset 14, -16
	push	r13	#
	.cfi_def_cfa_offset 24
	.cfi_offset 13, -24
	push	r12	#
	.cfi_def_cfa_offset 32
	.cfi_offset 12, -32
	mov	r12, rsi	# __args#0, __args#0
	push	rbp	#
	.cfi_def_cfa_offset 40
	.cfi_offset 6, -40
	push	rbx	#
	.cfi_def_cfa_offset 48
	.cfi_offset 3, -48
	mov	rbx, rdi	# this, this
	sub	rsp, 80	#,
	.cfi_def_cfa_offset 128
# /usr/include/c++/15.2.1/bits/vector.tcc:114: 	if (this->_M_impl._M_finish != this->_M_impl._M_end_of_storage)
	mov	rdi, QWORD PTR 8[rdi]	# _2, this_1(D)->D.155608._M_impl.D.154943._M_finish
# /usr/include/c++/15.2.1/bits/vector.tcc:111:       vector<_Tp, _Alloc>::
	mov	r13, QWORD PTR fs:40	# __args#1, MEM[(<address-space-1> long unsigned int *)40B]
	mov	QWORD PTR 72[rsp], r13	# D.173749, __args#1
	mov	r13, rdx	# __args#1, __args#1
# /usr/include/c++/15.2.1/bits/vector.tcc:114: 	if (this->_M_impl._M_finish != this->_M_impl._M_end_of_storage)
	cmp	rdi, QWORD PTR 16[rbx]	# _2, this_1(D)->D.155608._M_impl.D.154943._M_end_of_storage
	je	.L590	#,
# /usr/include/c++/15.2.1/bits/new_allocator.h:191: 	{ ::new((void *)__p) _Up(std::forward<_Args>(__args)...); }
	lea	rbp, 32[rsp]	# tmp129,
	mov	QWORD PTR 8[rsp], r8	# %sfp, __args#3
	mov	rsi, r9	#, __args#4
	lea	rdx, 31[rsp]	# tmp116,
	mov	QWORD PTR [rsp], rcx	# %sfp, __args#2
# /usr/include/c++/15.2.1/bits/new_allocator.h:191: 	{ ::new((void *)__p) _Up(std::forward<_Args>(__args)...); }
	call	_ZnwmPv.isra.0	#
# /usr/include/c++/15.2.1/bits/new_allocator.h:191: 	{ ::new((void *)__p) _Up(std::forward<_Args>(__args)...); }
	mov	rdi, rbp	#, tmp129
# /usr/include/c++/15.2.1/bits/new_allocator.h:191: 	{ ::new((void *)__p) _Up(std::forward<_Args>(__args)...); }
	mov	r14, rax	# _4,
.LEHB45:
# /usr/include/c++/15.2.1/bits/new_allocator.h:191: 	{ ::new((void *)__p) _Up(std::forward<_Args>(__args)...); }
	call	_ZNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEEC1IS3_EEPKcRKS3_	#
.LEHE45:
# /usr/include/c++/15.2.1/bits/new_allocator.h:191: 	{ ::new((void *)__p) _Up(std::forward<_Args>(__args)...); }
	mov	rcx, QWORD PTR [rsp]	# __args#2, %sfp
	mov	edx, DWORD PTR 0[r13]	# *__args#1_10(D), *__args#1_10(D)
	mov	r9, rbp	#, tmp129
	mov	r8, QWORD PTR 8[rsp]	# __args#3, %sfp
	mov	esi, DWORD PTR [r12]	# *__args#0_12(D), *__args#0_12(D)
	mov	rdi, r14	#, _4
	mov	ecx, DWORD PTR [rcx]	# *__args#2_8(D), *__args#2_8(D)
	mov	r8d, DWORD PTR [r8]	#, *__args#3_6(D)
.LEHB46:
	call	[QWORD PTR _ZN6ButtonC1EiiiiRKNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEEE@GOTPCREL[rip]]	#
.LEHE46:
# /usr/include/c++/15.2.1/bits/new_allocator.h:191: 	{ ::new((void *)__p) _Up(std::forward<_Args>(__args)...); }
	mov	rdi, rbp	#, tmp129
	call	[QWORD PTR _ZNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEED1Ev@GOTPCREL[rip]]	#
# /usr/include/c++/15.2.1/bits/vector.tcc:119: 	    ++this->_M_impl._M_finish;
	add	QWORD PTR 8[rbx], 56	# this_1(D)->D.155608._M_impl.D.154943._M_finish,
# /usr/include/c++/15.2.1/bits/vector.tcc:127:       }
	mov	rax, QWORD PTR 72[rsp]	# tmp138, D.173749
	sub	rax, QWORD PTR fs:40	# tmp138, MEM[(<address-space-1> long unsigned int *)40B]
	jne	.L597	#,
	add	rsp, 80	#,
	.cfi_remember_state
	.cfi_def_cfa_offset 48
	pop	rbx	#
	.cfi_def_cfa_offset 40
	pop	rbp	#
	.cfi_def_cfa_offset 32
	pop	r12	#
	.cfi_def_cfa_offset 24
	pop	r13	#
	.cfi_def_cfa_offset 16
	pop	r14	#
	.cfi_def_cfa_offset 8
	ret	
	.p2align 4,,10
	.p2align 3
.L590:
	.cfi_restore_state
# /usr/include/c++/15.2.1/bits/vector.tcc:123: 	  _M_realloc_append(std::forward<_Args>(__args)...);
	mov	rax, QWORD PTR 72[rsp]	# tmp140, D.173749
	sub	rax, QWORD PTR fs:40	# tmp140, MEM[(<address-space-1> long unsigned int *)40B]
	jne	.L597	#,
# /usr/include/c++/15.2.1/bits/vector.tcc:127:       }
	add	rsp, 80	#,
	.cfi_remember_state
	.cfi_def_cfa_offset 48
# /usr/include/c++/15.2.1/bits/vector.tcc:123: 	  _M_realloc_append(std::forward<_Args>(__args)...);
	mov	rdx, r13	#, __args#1
	mov	rdi, rbx	#, this
# /usr/include/c++/15.2.1/bits/vector.tcc:127:       }
	pop	rbx	#
	.cfi_def_cfa_offset 40
	pop	rbp	#
	.cfi_def_cfa_offset 32
	pop	r12	#
	.cfi_def_cfa_offset 24
	pop	r13	#
	.cfi_def_cfa_offset 16
	pop	r14	#
	.cfi_def_cfa_offset 8
.LEHB47:
# /usr/include/c++/15.2.1/bits/vector.tcc:123: 	  _M_realloc_append(std::forward<_Args>(__args)...);
	jmp	_ZNSt6vectorI6ButtonSaIS0_EE17_M_realloc_appendIJiiRKiS5_RA36_KcEEEvDpOT_	#
.LEHE47:
.L597:
	.cfi_restore_state
# /usr/include/c++/15.2.1/bits/vector.tcc:127:       }
	call	[QWORD PTR __stack_chk_fail@GOTPCREL[rip]]	#
.L596:
# /usr/include/c++/15.2.1/bits/new_allocator.h:191: 	{ ::new((void *)__p) _Up(std::forward<_Args>(__args)...); }
	mov	rbx, rax	# tmp137,
	jmp	.L592	#
	.section	.gcc_except_table
.LLSDA13941:
	.byte	0xff
	.byte	0xff
	.byte	0x1
	.uleb128 .LLSDACSE13941-.LLSDACSB13941
.LLSDACSB13941:
	.uleb128 .LEHB45-.LFB13941
	.uleb128 .LEHE45-.LEHB45
	.uleb128 0
	.uleb128 0
	.uleb128 .LEHB46-.LFB13941
	.uleb128 .LEHE46-.LEHB46
	.uleb128 .L596-.LFB13941
	.uleb128 0
	.uleb128 .LEHB47-.LFB13941
	.uleb128 .LEHE47-.LEHB47
	.uleb128 0
	.uleb128 0
.LLSDACSE13941:
	.text
	.cfi_endproc
	.section	.text.unlikely
	.cfi_startproc
	.cfi_personality 0x9b,DW.ref.__gxx_personality_v0
	.cfi_lsda 0x1b,.LLSDAC13941
	.type	_ZNSt6vectorI6ButtonSaIS0_EE12emplace_backIJiiRKiS5_RA36_KcEEERS0_DpOT_.isra.0.cold, @function
_ZNSt6vectorI6ButtonSaIS0_EE12emplace_backIJiiRKiS5_RA36_KcEEERS0_DpOT_.isra.0.cold:
.LFSB13941:
.L592:
	.cfi_def_cfa_offset 128
	.cfi_offset 3, -48
	.cfi_offset 6, -40
	.cfi_offset 12, -32
	.cfi_offset 13, -24
	.cfi_offset 14, -16
	mov	rdi, rbp	#, tmp129
	call	[QWORD PTR _ZNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEED1Ev@GOTPCREL[rip]]	#
	mov	rax, QWORD PTR 72[rsp]	# tmp139, D.173749
	sub	rax, QWORD PTR fs:40	# tmp139, MEM[(<address-space-1> long unsigned int *)40B]
	jne	.L599	#,
	mov	rdi, rbx	#, tmp137
.LEHB48:
	call	[QWORD PTR _Unwind_Resume@GOTPCREL[rip]]	#
.LEHE48:
.L599:
	call	[QWORD PTR __stack_chk_fail@GOTPCREL[rip]]	#
	.cfi_endproc
.LFE13941:
	.section	.gcc_except_table
.LLSDAC13941:
	.byte	0xff
	.byte	0xff
	.byte	0x1
	.uleb128 .LLSDACSEC13941-.LLSDACSBC13941
.LLSDACSBC13941:
	.uleb128 .LEHB48-.LCOLDB22
	.uleb128 .LEHE48-.LEHB48
	.uleb128 0
	.uleb128 0
.LLSDACSEC13941:
	.section	.text.unlikely
	.text
	.size	_ZNSt6vectorI6ButtonSaIS0_EE12emplace_backIJiiRKiS5_RA36_KcEEERS0_DpOT_.isra.0, .-_ZNSt6vectorI6ButtonSaIS0_EE12emplace_backIJiiRKiS5_RA36_KcEEERS0_DpOT_.isra.0
	.section	.text.unlikely
	.size	_ZNSt6vectorI6ButtonSaIS0_EE12emplace_backIJiiRKiS5_RA36_KcEEERS0_DpOT_.isra.0.cold, .-_ZNSt6vectorI6ButtonSaIS0_EE12emplace_backIJiiRKiS5_RA36_KcEEERS0_DpOT_.isra.0.cold
.LCOLDE22:
	.text
.LHOTE22:
	.section	.text._ZNSt6vectorI6ButtonSaIS0_EE17_M_realloc_appendIJiiRKiS5_RA19_KcEEEvDpOT_,"axG",@progbits,_ZNSt6vectorI6ButtonSaIS0_EE17_M_realloc_appendIJiiRKiS5_RA19_KcEEEvDpOT_,comdat
	.align 2
	.p2align 4
	.weak	_ZNSt6vectorI6ButtonSaIS0_EE17_M_realloc_appendIJiiRKiS5_RA19_KcEEEvDpOT_
	.type	_ZNSt6vectorI6ButtonSaIS0_EE17_M_realloc_appendIJiiRKiS5_RA19_KcEEEvDpOT_, @function
_ZNSt6vectorI6ButtonSaIS0_EE17_M_realloc_appendIJiiRKiS5_RA19_KcEEEvDpOT_:
.LFB13532:
	.cfi_startproc
	.cfi_personality 0x9b,DW.ref.__gxx_personality_v0
	.cfi_lsda 0x1b,.LLSDA13532
	push	r15	#
	.cfi_def_cfa_offset 16
	.cfi_offset 15, -16
	push	r14	#
	.cfi_def_cfa_offset 24
	.cfi_offset 14, -24
	push	r13	#
	.cfi_def_cfa_offset 32
	.cfi_offset 13, -32
	push	r12	#
	.cfi_def_cfa_offset 40
	.cfi_offset 12, -40
	push	rbp	#
	.cfi_def_cfa_offset 48
	.cfi_offset 6, -48
	push	rbx	#
	.cfi_def_cfa_offset 56
	.cfi_offset 3, -56
	mov	rbx, rdi	# this, this
	sub	rsp, 168	#,
	.cfi_def_cfa_offset 224
# /usr/include/c++/15.2.1/bits/vector.tcc:557:       vector<_Tp, _Alloc>::
	mov	QWORD PTR 32[rsp], rcx	# %sfp, __args#2
	mov	QWORD PTR 56[rsp], r8	# %sfp, __args#3
	mov	QWORD PTR 48[rsp], r9	# %sfp, __args#4
	mov	QWORD PTR 16[rsp], rsi	# %sfp, __args#0
# /usr/include/c++/15.2.1/bits/vector.tcc:566:       const size_type __len = _M_check_len(1u, "vector::_M_realloc_append");
	mov	esi, 1	#,
# /usr/include/c++/15.2.1/bits/vector.tcc:557:       vector<_Tp, _Alloc>::
	mov	QWORD PTR 24[rsp], rdx	# %sfp, __args#1
# /usr/include/c++/15.2.1/bits/vector.tcc:566:       const size_type __len = _M_check_len(1u, "vector::_M_realloc_append");
	mov	rdx, QWORD PTR fs:40	#, MEM[(<address-space-1> long unsigned int *)40B]
	mov	QWORD PTR 152[rsp], rdx	# D.173758,
	lea	rdx, .LC17[rip]	#,
.LEHB49:
	call	_ZNKSt6vectorI6ButtonSaIS0_EE12_M_check_lenEmPKc	#
# /usr/include/c++/15.2.1/bits/vector.tcc:571:       const size_type __elems = end() - begin();
	mov	rdi, rbx	#, this
# /usr/include/c++/15.2.1/bits/vector.tcc:569:       pointer __old_start = this->_M_impl._M_start;
	mov	r14, QWORD PTR [rbx]	# __old_start, this_12(D)->D.155608._M_impl.D.154943._M_start
# /usr/include/c++/15.2.1/bits/vector.tcc:566:       const size_type __len = _M_check_len(1u, "vector::_M_realloc_append");
	mov	r12, rax	# _14,
# /usr/include/c++/15.2.1/bits/vector.tcc:570:       pointer __old_finish = this->_M_impl._M_finish;
	mov	rax, QWORD PTR 8[rbx]	# __old_finish, this_12(D)->D.155608._M_impl.D.154943._M_finish
	mov	QWORD PTR 8[rsp], rax	# %sfp, __old_finish
# /usr/include/c++/15.2.1/bits/vector.tcc:571:       const size_type __elems = end() - begin();
	call	_ZNSt6vectorI6ButtonSaIS0_EE5beginEv	#
# /usr/include/c++/15.2.1/bits/vector.tcc:571:       const size_type __elems = end() - begin();
	mov	rdi, rbx	#, this
# /usr/include/c++/15.2.1/bits/vector.tcc:571:       const size_type __elems = end() - begin();
	mov	rbp, rax	# D.166439,
# /usr/include/c++/15.2.1/bits/vector.tcc:571:       const size_type __elems = end() - begin();
	call	_ZNSt6vectorI6ButtonSaIS0_EE3endEv	#
# /usr/include/c++/15.2.1/bits/vector.tcc:572:       pointer __new_start(this->_M_allocate(__len));
	mov	rdi, r12	#, _14
# /usr/include/c++/15.2.1/bits/stl_iterator.h:1340:     { return __lhs.base() - __rhs.base(); }
	sub	rax, rbp	# D.166438, D.166439
	mov	r13, rax	# _19, D.166438
# /usr/include/c++/15.2.1/bits/vector.tcc:572:       pointer __new_start(this->_M_allocate(__len));
	call	_ZNSt12_Vector_baseI6ButtonSaIS0_EE11_M_allocateEm.isra.0	#
.LEHE49:
# /usr/include/c++/15.2.1/bits/vector.tcc:576: 	_Guard_alloc __guard(__new_start, __len, *this);
	mov	rdx, r12	#, _14
	lea	rdi, 80[rsp]	#,
	mov	rcx, rbx	#, this
# /usr/include/c++/15.2.1/bits/vector.tcc:572:       pointer __new_start(this->_M_allocate(__len));
	mov	rbp, rax	# _23,
# /usr/include/c++/15.2.1/bits/vector.tcc:576: 	_Guard_alloc __guard(__new_start, __len, *this);
	mov	rsi, rax	#, _23
	call	_ZNSt6vectorI6ButtonSaIS0_EE12_Guard_allocC1EPS0_mRSt12_Vector_baseIS0_S1_E	#
# /usr/include/c++/15.2.1/bits/vector.tcc:586: 	_Alloc_traits::construct(this->_M_impl,
	lea	rdi, 0[rbp+r13]	# _3,
# /usr/include/c++/15.2.1/bits/new_allocator.h:191: 	{ ::new((void *)__p) _Up(std::forward<_Args>(__args)...); }
	lea	rdx, 79[rsp]	# tmp136,
# /usr/include/c++/15.2.1/bits/new_allocator.h:191: 	{ ::new((void *)__p) _Up(std::forward<_Args>(__args)...); }
	call	_ZnwmPv.isra.0	#
# /usr/include/c++/15.2.1/bits/new_allocator.h:191: 	{ ::new((void *)__p) _Up(std::forward<_Args>(__args)...); }
	mov	rsi, QWORD PTR 48[rsp]	#, %sfp
	lea	rdi, 112[rsp]	#,
# /usr/include/c++/15.2.1/bits/new_allocator.h:191: 	{ ::new((void *)__p) _Up(std::forward<_Args>(__args)...); }
	mov	QWORD PTR 40[rsp], rax	# %sfp,
.LEHB50:
# /usr/include/c++/15.2.1/bits/new_allocator.h:191: 	{ ::new((void *)__p) _Up(std::forward<_Args>(__args)...); }
	call	_ZNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEEC1IS3_EEPKcRKS3_	#
.LEHE50:
# /usr/include/c++/15.2.1/bits/new_allocator.h:191: 	{ ::new((void *)__p) _Up(std::forward<_Args>(__args)...); }
	mov	rcx, QWORD PTR 32[rsp]	# __args#2, %sfp
	mov	rdx, QWORD PTR 24[rsp]	# __args#1, %sfp
	lea	r9, 112[rsp]	#,
	mov	r10, QWORD PTR 16[rsp]	# __args#0, %sfp
	mov	r8, QWORD PTR 56[rsp]	# __args#3, %sfp
	mov	ecx, DWORD PTR [rcx]	# *__args#2_29(D), *__args#2_29(D)
	mov	edx, DWORD PTR [rdx]	# *__args#1_31(D), *__args#1_31(D)
	mov	esi, DWORD PTR [r10]	# *__args#0_33(D), *__args#0_33(D)
	mov	r8d, DWORD PTR [r8]	#, *__args#3_27(D)
	mov	rdi, QWORD PTR 40[rsp]	#, %sfp
.LEHB51:
	call	[QWORD PTR _ZN6ButtonC1EiiiiRKNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEEE@GOTPCREL[rip]]	#
.LEHE51:
# /usr/include/c++/15.2.1/bits/vector.tcc:646:       this->_M_impl._M_end_of_storage = __new_start + __len;
	imul	r12, r12, 56	# _9, _14,
# /usr/include/c++/15.2.1/bits/new_allocator.h:191: 	{ ::new((void *)__p) _Up(std::forward<_Args>(__args)...); }
	lea	rdi, 112[rsp]	#,
	call	[QWORD PTR _ZNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEED1Ev@GOTPCREL[rip]]	#
# /usr/include/c++/15.2.1/bits/vector.tcc:599: 	    __new_finish = _S_relocate(__old_start, __old_finish,
	mov	rsi, QWORD PTR 8[rsp]	#, %sfp
	mov	rdx, rbp	#, _23
	mov	rdi, r14	#, __old_start
	call	_ZNSt6vectorI6ButtonSaIS0_EE11_S_relocateEPS0_S3_S3_RS1_.isra.0	#
# /usr/include/c++/15.2.1/bits/vector.tcc:640:       }
	lea	rdi, 80[rsp]	#,
# /usr/include/c++/15.2.1/bits/vector.tcc:638: 	__guard._M_storage = __old_start;
	mov	QWORD PTR 80[rsp], r14	# __guard._M_storage, __old_start
# /usr/include/c++/15.2.1/bits/vector.tcc:639: 	__guard._M_len = this->_M_impl._M_end_of_storage - __old_start;
	movabs	rdx, 7905747460161236407	# tmp148,
# /usr/include/c++/15.2.1/bits/vector.tcc:599: 	    __new_finish = _S_relocate(__old_start, __old_finish,
	mov	r13, rax	# __new_finish,
# /usr/include/c++/15.2.1/bits/vector.tcc:639: 	__guard._M_len = this->_M_impl._M_end_of_storage - __old_start;
	mov	rax, QWORD PTR 16[rbx]	# _6, this_12(D)->D.155608._M_impl.D.154943._M_end_of_storage
# /usr/include/c++/15.2.1/bits/vector.tcc:601: 	    ++__new_finish;
	add	r13, 56	# tmp150,
# /usr/include/c++/15.2.1/bits/vector.tcc:639: 	__guard._M_len = this->_M_impl._M_end_of_storage - __old_start;
	sub	rax, r14	# _6, __old_start
	sar	rax, 3	# tmp146,
	imul	rax, rdx	# _7, tmp148
# /usr/include/c++/15.2.1/bits/vector.tcc:639: 	__guard._M_len = this->_M_impl._M_end_of_storage - __old_start;
	mov	QWORD PTR 88[rsp], rax	# __guard._M_len, _7
# /usr/include/c++/15.2.1/bits/vector.tcc:640:       }
	call	_ZNSt6vectorI6ButtonSaIS0_EE12_Guard_allocD1Ev	#
# /usr/include/c++/15.2.1/bits/vector.tcc:644:       this->_M_impl._M_start = __new_start;
	mov	QWORD PTR [rbx], rbp	# this_12(D)->D.155608._M_impl.D.154943._M_start, _23
# /usr/include/c++/15.2.1/bits/vector.tcc:646:       this->_M_impl._M_end_of_storage = __new_start + __len;
	add	rbp, r12	# tmp152, _9
# /usr/include/c++/15.2.1/bits/vector.tcc:601: 	    ++__new_finish;
	mov	QWORD PTR 8[rbx], r13	# this_12(D)->D.155608._M_impl.D.154943._M_finish, tmp150
# /usr/include/c++/15.2.1/bits/vector.tcc:646:       this->_M_impl._M_end_of_storage = __new_start + __len;
	mov	QWORD PTR 16[rbx], rbp	# this_12(D)->D.155608._M_impl.D.154943._M_end_of_storage, tmp152
# /usr/include/c++/15.2.1/bits/vector.tcc:647:     }
	mov	rax, QWORD PTR 152[rsp]	# tmp177, D.173758
	sub	rax, QWORD PTR fs:40	# tmp177, MEM[(<address-space-1> long unsigned int *)40B]
	jne	.L607	#,
	add	rsp, 168	#,
	.cfi_remember_state
	.cfi_def_cfa_offset 56
	pop	rbx	#
	.cfi_def_cfa_offset 48
	pop	rbp	#
	.cfi_def_cfa_offset 40
	pop	r12	#
	.cfi_def_cfa_offset 32
	pop	r13	#
	.cfi_def_cfa_offset 24
	pop	r14	#
	.cfi_def_cfa_offset 16
	pop	r15	#
	.cfi_def_cfa_offset 8
	ret	
.L601:
	.cfi_restore_state
# /usr/include/c++/15.2.1/bits/new_allocator.h:191: 	{ ::new((void *)__p) _Up(std::forward<_Args>(__args)...); }
	lea	rdi, 112[rsp]	#,
	call	[QWORD PTR _ZNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEED1Ev@GOTPCREL[rip]]	#
.L602:
# /usr/include/c++/15.2.1/bits/vector.tcc:640:       }
	lea	rdi, 80[rsp]	#,
	call	_ZNSt6vectorI6ButtonSaIS0_EE12_Guard_allocD1Ev	#
	mov	rax, QWORD PTR 152[rsp]	# tmp178, D.173758
	sub	rax, QWORD PTR fs:40	# tmp178, MEM[(<address-space-1> long unsigned int *)40B]
	je	.L603	#,
.L607:
# /usr/include/c++/15.2.1/bits/vector.tcc:647:     }
	call	[QWORD PTR __stack_chk_fail@GOTPCREL[rip]]	#
.L606:
# /usr/include/c++/15.2.1/bits/new_allocator.h:191: 	{ ::new((void *)__p) _Up(std::forward<_Args>(__args)...); }
	mov	rbx, rax	# tmp175,
	jmp	.L601	#
.L605:
# /usr/include/c++/15.2.1/bits/vector.tcc:640:       }
	mov	rbx, rax	# tmp154, tmp176
	jmp	.L602	#
.L603:
	mov	rdi, rbx	#, tmp154
.LEHB52:
	call	[QWORD PTR _Unwind_Resume@GOTPCREL[rip]]	#
.LEHE52:
	.cfi_endproc
.LFE13532:
	.section	.gcc_except_table
.LLSDA13532:
	.byte	0xff
	.byte	0xff
	.byte	0x1
	.uleb128 .LLSDACSE13532-.LLSDACSB13532
.LLSDACSB13532:
	.uleb128 .LEHB49-.LFB13532
	.uleb128 .LEHE49-.LEHB49
	.uleb128 0
	.uleb128 0
	.uleb128 .LEHB50-.LFB13532
	.uleb128 .LEHE50-.LEHB50
	.uleb128 .L605-.LFB13532
	.uleb128 0
	.uleb128 .LEHB51-.LFB13532
	.uleb128 .LEHE51-.LEHB51
	.uleb128 .L606-.LFB13532
	.uleb128 0
	.uleb128 .LEHB52-.LFB13532
	.uleb128 .LEHE52-.LEHB52
	.uleb128 0
	.uleb128 0
.LLSDACSE13532:
	.section	.text._ZNSt6vectorI6ButtonSaIS0_EE17_M_realloc_appendIJiiRKiS5_RA19_KcEEEvDpOT_,"axG",@progbits,_ZNSt6vectorI6ButtonSaIS0_EE17_M_realloc_appendIJiiRKiS5_RA19_KcEEEvDpOT_,comdat
	.size	_ZNSt6vectorI6ButtonSaIS0_EE17_M_realloc_appendIJiiRKiS5_RA19_KcEEEvDpOT_, .-_ZNSt6vectorI6ButtonSaIS0_EE17_M_realloc_appendIJiiRKiS5_RA19_KcEEEvDpOT_
	.section	.text.unlikely
	.align 2
.LCOLDB23:
	.text
.LHOTB23:
	.align 2
	.p2align 4
	.type	_ZNSt6vectorI6ButtonSaIS0_EE12emplace_backIJiiRKiS5_RA19_KcEEERS0_DpOT_.isra.0, @function
_ZNSt6vectorI6ButtonSaIS0_EE12emplace_backIJiiRKiS5_RA19_KcEEERS0_DpOT_.isra.0:
.LFB13942:
	.cfi_startproc
	.cfi_personality 0x9b,DW.ref.__gxx_personality_v0
	.cfi_lsda 0x1b,.LLSDA13942
	push	r14	#
	.cfi_def_cfa_offset 16
	.cfi_offset 14, -16
	push	r13	#
	.cfi_def_cfa_offset 24
	.cfi_offset 13, -24
	push	r12	#
	.cfi_def_cfa_offset 32
	.cfi_offset 12, -32
	mov	r12, rsi	# __args#0, __args#0
	push	rbp	#
	.cfi_def_cfa_offset 40
	.cfi_offset 6, -40
	push	rbx	#
	.cfi_def_cfa_offset 48
	.cfi_offset 3, -48
	mov	rbx, rdi	# this, this
	sub	rsp, 80	#,
	.cfi_def_cfa_offset 128
# /usr/include/c++/15.2.1/bits/vector.tcc:114: 	if (this->_M_impl._M_finish != this->_M_impl._M_end_of_storage)
	mov	rdi, QWORD PTR 8[rdi]	# _2, this_1(D)->D.155608._M_impl.D.154943._M_finish
# /usr/include/c++/15.2.1/bits/vector.tcc:111:       vector<_Tp, _Alloc>::
	mov	r13, QWORD PTR fs:40	# __args#1, MEM[(<address-space-1> long unsigned int *)40B]
	mov	QWORD PTR 72[rsp], r13	# D.173775, __args#1
	mov	r13, rdx	# __args#1, __args#1
# /usr/include/c++/15.2.1/bits/vector.tcc:114: 	if (this->_M_impl._M_finish != this->_M_impl._M_end_of_storage)
	cmp	rdi, QWORD PTR 16[rbx]	# _2, this_1(D)->D.155608._M_impl.D.154943._M_end_of_storage
	je	.L610	#,
# /usr/include/c++/15.2.1/bits/new_allocator.h:191: 	{ ::new((void *)__p) _Up(std::forward<_Args>(__args)...); }
	lea	rbp, 32[rsp]	# tmp129,
	mov	QWORD PTR 8[rsp], r8	# %sfp, __args#3
	mov	rsi, r9	#, __args#4
	lea	rdx, 31[rsp]	# tmp116,
	mov	QWORD PTR [rsp], rcx	# %sfp, __args#2
# /usr/include/c++/15.2.1/bits/new_allocator.h:191: 	{ ::new((void *)__p) _Up(std::forward<_Args>(__args)...); }
	call	_ZnwmPv.isra.0	#
# /usr/include/c++/15.2.1/bits/new_allocator.h:191: 	{ ::new((void *)__p) _Up(std::forward<_Args>(__args)...); }
	mov	rdi, rbp	#, tmp129
# /usr/include/c++/15.2.1/bits/new_allocator.h:191: 	{ ::new((void *)__p) _Up(std::forward<_Args>(__args)...); }
	mov	r14, rax	# _4,
.LEHB53:
# /usr/include/c++/15.2.1/bits/new_allocator.h:191: 	{ ::new((void *)__p) _Up(std::forward<_Args>(__args)...); }
	call	_ZNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEEC1IS3_EEPKcRKS3_	#
.LEHE53:
# /usr/include/c++/15.2.1/bits/new_allocator.h:191: 	{ ::new((void *)__p) _Up(std::forward<_Args>(__args)...); }
	mov	rcx, QWORD PTR [rsp]	# __args#2, %sfp
	mov	edx, DWORD PTR 0[r13]	# *__args#1_10(D), *__args#1_10(D)
	mov	r9, rbp	#, tmp129
	mov	r8, QWORD PTR 8[rsp]	# __args#3, %sfp
	mov	esi, DWORD PTR [r12]	# *__args#0_12(D), *__args#0_12(D)
	mov	rdi, r14	#, _4
	mov	ecx, DWORD PTR [rcx]	# *__args#2_8(D), *__args#2_8(D)
	mov	r8d, DWORD PTR [r8]	#, *__args#3_6(D)
.LEHB54:
	call	[QWORD PTR _ZN6ButtonC1EiiiiRKNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEEE@GOTPCREL[rip]]	#
.LEHE54:
# /usr/include/c++/15.2.1/bits/new_allocator.h:191: 	{ ::new((void *)__p) _Up(std::forward<_Args>(__args)...); }
	mov	rdi, rbp	#, tmp129
	call	[QWORD PTR _ZNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEED1Ev@GOTPCREL[rip]]	#
# /usr/include/c++/15.2.1/bits/vector.tcc:119: 	    ++this->_M_impl._M_finish;
	add	QWORD PTR 8[rbx], 56	# this_1(D)->D.155608._M_impl.D.154943._M_finish,
# /usr/include/c++/15.2.1/bits/vector.tcc:127:       }
	mov	rax, QWORD PTR 72[rsp]	# tmp138, D.173775
	sub	rax, QWORD PTR fs:40	# tmp138, MEM[(<address-space-1> long unsigned int *)40B]
	jne	.L617	#,
	add	rsp, 80	#,
	.cfi_remember_state
	.cfi_def_cfa_offset 48
	pop	rbx	#
	.cfi_def_cfa_offset 40
	pop	rbp	#
	.cfi_def_cfa_offset 32
	pop	r12	#
	.cfi_def_cfa_offset 24
	pop	r13	#
	.cfi_def_cfa_offset 16
	pop	r14	#
	.cfi_def_cfa_offset 8
	ret	
	.p2align 4,,10
	.p2align 3
.L610:
	.cfi_restore_state
# /usr/include/c++/15.2.1/bits/vector.tcc:123: 	  _M_realloc_append(std::forward<_Args>(__args)...);
	mov	rax, QWORD PTR 72[rsp]	# tmp140, D.173775
	sub	rax, QWORD PTR fs:40	# tmp140, MEM[(<address-space-1> long unsigned int *)40B]
	jne	.L617	#,
# /usr/include/c++/15.2.1/bits/vector.tcc:127:       }
	add	rsp, 80	#,
	.cfi_remember_state
	.cfi_def_cfa_offset 48
# /usr/include/c++/15.2.1/bits/vector.tcc:123: 	  _M_realloc_append(std::forward<_Args>(__args)...);
	mov	rdx, r13	#, __args#1
	mov	rdi, rbx	#, this
# /usr/include/c++/15.2.1/bits/vector.tcc:127:       }
	pop	rbx	#
	.cfi_def_cfa_offset 40
	pop	rbp	#
	.cfi_def_cfa_offset 32
	pop	r12	#
	.cfi_def_cfa_offset 24
	pop	r13	#
	.cfi_def_cfa_offset 16
	pop	r14	#
	.cfi_def_cfa_offset 8
.LEHB55:
# /usr/include/c++/15.2.1/bits/vector.tcc:123: 	  _M_realloc_append(std::forward<_Args>(__args)...);
	jmp	_ZNSt6vectorI6ButtonSaIS0_EE17_M_realloc_appendIJiiRKiS5_RA19_KcEEEvDpOT_	#
.LEHE55:
.L617:
	.cfi_restore_state
# /usr/include/c++/15.2.1/bits/vector.tcc:127:       }
	call	[QWORD PTR __stack_chk_fail@GOTPCREL[rip]]	#
.L616:
# /usr/include/c++/15.2.1/bits/new_allocator.h:191: 	{ ::new((void *)__p) _Up(std::forward<_Args>(__args)...); }
	mov	rbx, rax	# tmp137,
	jmp	.L612	#
	.section	.gcc_except_table
.LLSDA13942:
	.byte	0xff
	.byte	0xff
	.byte	0x1
	.uleb128 .LLSDACSE13942-.LLSDACSB13942
.LLSDACSB13942:
	.uleb128 .LEHB53-.LFB13942
	.uleb128 .LEHE53-.LEHB53
	.uleb128 0
	.uleb128 0
	.uleb128 .LEHB54-.LFB13942
	.uleb128 .LEHE54-.LEHB54
	.uleb128 .L616-.LFB13942
	.uleb128 0
	.uleb128 .LEHB55-.LFB13942
	.uleb128 .LEHE55-.LEHB55
	.uleb128 0
	.uleb128 0
.LLSDACSE13942:
	.text
	.cfi_endproc
	.section	.text.unlikely
	.cfi_startproc
	.cfi_personality 0x9b,DW.ref.__gxx_personality_v0
	.cfi_lsda 0x1b,.LLSDAC13942
	.type	_ZNSt6vectorI6ButtonSaIS0_EE12emplace_backIJiiRKiS5_RA19_KcEEERS0_DpOT_.isra.0.cold, @function
_ZNSt6vectorI6ButtonSaIS0_EE12emplace_backIJiiRKiS5_RA19_KcEEERS0_DpOT_.isra.0.cold:
.LFSB13942:
.L612:
	.cfi_def_cfa_offset 128
	.cfi_offset 3, -48
	.cfi_offset 6, -40
	.cfi_offset 12, -32
	.cfi_offset 13, -24
	.cfi_offset 14, -16
	mov	rdi, rbp	#, tmp129
	call	[QWORD PTR _ZNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEED1Ev@GOTPCREL[rip]]	#
	mov	rax, QWORD PTR 72[rsp]	# tmp139, D.173775
	sub	rax, QWORD PTR fs:40	# tmp139, MEM[(<address-space-1> long unsigned int *)40B]
	jne	.L619	#,
	mov	rdi, rbx	#, tmp137
.LEHB56:
	call	[QWORD PTR _Unwind_Resume@GOTPCREL[rip]]	#
.LEHE56:
.L619:
	call	[QWORD PTR __stack_chk_fail@GOTPCREL[rip]]	#
	.cfi_endproc
.LFE13942:
	.section	.gcc_except_table
.LLSDAC13942:
	.byte	0xff
	.byte	0xff
	.byte	0x1
	.uleb128 .LLSDACSEC13942-.LLSDACSBC13942
.LLSDACSBC13942:
	.uleb128 .LEHB56-.LCOLDB23
	.uleb128 .LEHE56-.LEHB56
	.uleb128 0
	.uleb128 0
.LLSDACSEC13942:
	.section	.text.unlikely
	.text
	.size	_ZNSt6vectorI6ButtonSaIS0_EE12emplace_backIJiiRKiS5_RA19_KcEEERS0_DpOT_.isra.0, .-_ZNSt6vectorI6ButtonSaIS0_EE12emplace_backIJiiRKiS5_RA19_KcEEERS0_DpOT_.isra.0
	.section	.text.unlikely
	.size	_ZNSt6vectorI6ButtonSaIS0_EE12emplace_backIJiiRKiS5_RA19_KcEEERS0_DpOT_.isra.0.cold, .-_ZNSt6vectorI6ButtonSaIS0_EE12emplace_backIJiiRKiS5_RA19_KcEEERS0_DpOT_.isra.0.cold
.LCOLDE23:
	.text
.LHOTE23:
	.section	.rodata.str1.1
.LC24:
	.base64	"0J3QsNC30LDQtAA="
.LC26:
	.base64	"0KHQntCl0KDQkNCd0JjQotCsAA=="
.LC27:
	.base64	"0JfQkNCT0KDQo9CX0JjQotCsAA=="
	.section	.rodata.str1.8
	.align 8
.LC28:
	.base64	"0KPQlNCQ0JvQmNCi0Kwg0KHQntCl0KDQkNCd0JXQndCY0JUA"
	.section	.rodata.str1.1
.LC29:
	.base64	"0J/QldCg0JXQmNCc0JXQndCe0JLQkNCi0KwA"
	.section	.text.unlikely
	.align 2
.LCOLDB30:
	.text
.LHOTB30:
	.align 2
	.p2align 4
	.globl	_ZN10SavesSceneC2Ev
	.type	_ZN10SavesSceneC2Ev, @function
_ZN10SavesSceneC2Ev:
.LFB12862:
	.cfi_startproc
	.cfi_personality 0x9b,DW.ref.__gxx_personality_v0
	.cfi_lsda 0x1b,.LLSDA12862
	push	r15	#
	.cfi_def_cfa_offset 16
	.cfi_offset 15, -16
# saves_scene.cpp:51: SavesScene::SavesScene() {
	lea	rax, _ZTV10SavesScene[rip+16]	# tmp193,
# saves_scene.cpp:51: SavesScene::SavesScene() {
	lea	rsi, .LC24[rip]	#,
# saves_scene.cpp:51: SavesScene::SavesScene() {
	push	r14	#
	.cfi_def_cfa_offset 24
	.cfi_offset 14, -24
	push	r13	#
	.cfi_def_cfa_offset 32
	.cfi_offset 13, -32
	push	r12	#
	.cfi_def_cfa_offset 40
	.cfi_offset 12, -40
	push	rbp	#
	.cfi_def_cfa_offset 48
	.cfi_offset 6, -48
	push	rbx	#
	.cfi_def_cfa_offset 56
	.cfi_offset 3, -56
	sub	rsp, 104	#,
	.cfi_def_cfa_offset 160
# saves_scene.cpp:51: SavesScene::SavesScene() {
	mov	rbx, QWORD PTR fs:40	# this, MEM[(<address-space-1> long unsigned int *)40B]
	mov	QWORD PTR 88[rsp], rbx	# D.173812, this
	mov	rbx, rdi	# this, this
# saves_scene.cpp:51: SavesScene::SavesScene() {
	lea	rbp, 48[rsp]	# tmp175,
	lea	rdx, 44[rsp]	#,
	mov	rdi, rbp	#, tmp175
# saves_scene.cpp:51: SavesScene::SavesScene() {
	mov	QWORD PTR [rbx], rax	# *this_21(D).D.156845._vptr.Scene, tmp193
	lea	r15, 24[rbx]	# _2,
	mov	DWORD PTR 8[rbx], 7	# *this_21(D).nextScene,
	mov	QWORD PTR 16[rbx], 0	# *this_21(D).soundMgr,
	mov	QWORD PTR 8[rsp], r15	# %sfp, _2
.LEHB57:
# saves_scene.cpp:51: SavesScene::SavesScene() {
	call	_ZNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEEC1IS3_EEPKcRKS3_	#
.LEHE57:
# saves_scene.cpp:51: SavesScene::SavesScene() {
	mov	r9, rbp	#, tmp175
	mov	ecx, 100	#,
	mov	rdi, r15	#, _2
	mov	r8d, 50	#,
	mov	edx, 20	#,
	mov	esi, 20	#,
.LEHB58:
	call	[QWORD PTR _ZN6ButtonC1EiiiiRKNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEEE@GOTPCREL[rip]]	#
.LEHE58:
# saves_scene.cpp:51: SavesScene::SavesScene() {
	mov	rdi, rbp	#, tmp175
# saves_scene.cpp:51: SavesScene::SavesScene() {
	lea	r15, 152[rbx]	# _5,
# saves_scene.cpp:51: SavesScene::SavesScene() {
	lea	r12, 208[rbx]	# _6,
# saves_scene.cpp:51: SavesScene::SavesScene() {
	call	[QWORD PTR _ZNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEED1Ev@GOTPCREL[rip]]	#
# saves_scene.cpp:51: SavesScene::SavesScene() {
	lea	rax, 80[rbx]	# _3,
	mov	rdi, rax	#, _3
	mov	QWORD PTR 16[rsp], rax	# %sfp, _3
	call	_ZNSt6vectorI6ButtonSaIS0_EEC1Ev	#
# saves_scene.cpp:51: SavesScene::SavesScene() {
	lea	rax, 104[rbx]	# _4,
	mov	rdi, rax	#, _4
	mov	QWORD PTR 24[rsp], rax	# %sfp, _4
	call	_ZNSt6vectorIbSaIbEEC1Ev	#
# saves_scene.cpp:51: SavesScene::SavesScene() {
	xor	eax, eax	#
	mov	rdi, r15	#, _5
	mov	DWORD PTR 144[rbx], -1	# *this_21(D).activePlusIndex,
	mov	WORD PTR 148[rbx], ax	# MEM <vector(2) unsigned char> [(bool *)this_21(D) + 148B],
	call	[QWORD PTR _ZNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEEC1Ev@GOTPCREL[rip]]	#
# saves_scene.cpp:51: SavesScene::SavesScene() {
	movdqa	xmm0, XMMWORD PTR .LC25[rip]	# tmp134,
	mov	BYTE PTR 200[rbx], 0	# *this_21(D).isMenuVisible,
	mov	rdi, r12	#, _6
	mov	DWORD PTR 204[rbx], -1	# *this_21(D).menuTargetIndex,
	movups	XMMWORD PTR 184[rbx], xmm0	# MEM <vector(4) int> [(int *)this_21(D) + 184B], tmp134
	call	_ZNSt6vectorI6ButtonSaIS0_EEC1Ev	#
.LEHB59:
# saves_scene.cpp:52:     soundMgr = getSoundManager();
	call	[QWORD PTR _Z15getSoundManagerv@GOTPCREL[rip]]	#
# saves_scene.cpp:52:     soundMgr = getSoundManager();
	mov	QWORD PTR 16[rbx], rax	# *this_21(D).soundMgr, _45
# saves_scene.cpp:54:     const int W = Config::getWindowWidth();
	call	_ZN6Config14getWindowWidthEv	#
# saves_scene.cpp:58:     menuButtons.emplace_back(0, 0, MENU_BTN_W, MENU_BTN_H, "СОХРАНИТЬ");
	lea	r9, .LC26[rip]	#,
	lea	rdx, 44[rsp]	#,
	mov	rdi, r12	#, _6
# saves_scene.cpp:54:     const int W = Config::getWindowWidth();
	mov	ebp, eax	# W,
# saves_scene.cpp:55:     inputRect.x = (W - INPUT_W) / 2;
	lea	eax, -400[rax]	# tmp136,
# saves_scene.cpp:58:     menuButtons.emplace_back(0, 0, MENU_BTN_W, MENU_BTN_H, "СОХРАНИТЬ");
	lea	rsi, 40[rsp]	#,
# saves_scene.cpp:58:     menuButtons.emplace_back(0, 0, MENU_BTN_W, MENU_BTN_H, "СОХРАНИТЬ");
	mov	DWORD PTR 44[rsp], 0	# MEM[(int *)_17],
# saves_scene.cpp:55:     inputRect.x = (W - INPUT_W) / 2;
	shr	eax, 31	# tmp136,
# saves_scene.cpp:58:     menuButtons.emplace_back(0, 0, MENU_BTN_W, MENU_BTN_H, "СОХРАНИТЬ");
	lea	r8, _ZN10SavesScene10MENU_BTN_HE[rip]	#,
	lea	rcx, _ZN10SavesScene10MENU_BTN_WE[rip]	#,
# saves_scene.cpp:58:     menuButtons.emplace_back(0, 0, MENU_BTN_W, MENU_BTN_H, "СОХРАНИТЬ");
	mov	DWORD PTR 40[rsp], 0	# MEM[(int *)_77],
# saves_scene.cpp:55:     inputRect.x = (W - INPUT_W) / 2;
	lea	eax, -400[rax+rbp]	# tmp137,
	sar	eax	# _8
# saves_scene.cpp:55:     inputRect.x = (W - INPUT_W) / 2;
	mov	DWORD PTR 184[rbx], eax	# *this_21(D).inputRect.x, _8
# saves_scene.cpp:58:     menuButtons.emplace_back(0, 0, MENU_BTN_W, MENU_BTN_H, "СОХРАНИТЬ");
	call	_ZNSt6vectorI6ButtonSaIS0_EE12emplace_backIJiiRKiS5_RA19_KcEEERS0_DpOT_.isra.0	#
# saves_scene.cpp:59:     menuButtons.emplace_back(0, 0, MENU_BTN_W, MENU_BTN_H, "ЗАГРУЗИТЬ");
	lea	r9, .LC27[rip]	#,
	lea	r8, _ZN10SavesScene10MENU_BTN_HE[rip]	#,
	mov	rdi, r12	#, _6
# saves_scene.cpp:59:     menuButtons.emplace_back(0, 0, MENU_BTN_W, MENU_BTN_H, "ЗАГРУЗИТЬ");
	mov	DWORD PTR 44[rsp], 0	# MEM[(int *)_17],
# saves_scene.cpp:59:     menuButtons.emplace_back(0, 0, MENU_BTN_W, MENU_BTN_H, "ЗАГРУЗИТЬ");
	lea	rcx, _ZN10SavesScene10MENU_BTN_WE[rip]	#,
	lea	rdx, 44[rsp]	#,
# saves_scene.cpp:59:     menuButtons.emplace_back(0, 0, MENU_BTN_W, MENU_BTN_H, "ЗАГРУЗИТЬ");
	mov	DWORD PTR 40[rsp], 0	# MEM[(int *)_77],
# saves_scene.cpp:59:     menuButtons.emplace_back(0, 0, MENU_BTN_W, MENU_BTN_H, "ЗАГРУЗИТЬ");
	lea	rsi, 40[rsp]	#,
	call	_ZNSt6vectorI6ButtonSaIS0_EE12emplace_backIJiiRKiS5_RA19_KcEEERS0_DpOT_.isra.0	#
# saves_scene.cpp:60:     menuButtons.emplace_back(0, 0, MENU_BTN_W, MENU_BTN_H, "УДАЛИТЬ СОХРАНЕНИЕ");
	lea	r9, .LC28[rip]	#,
	lea	r8, _ZN10SavesScene10MENU_BTN_HE[rip]	#,
	mov	rdi, r12	#, _6
# saves_scene.cpp:60:     menuButtons.emplace_back(0, 0, MENU_BTN_W, MENU_BTN_H, "УДАЛИТЬ СОХРАНЕНИЕ");
	mov	DWORD PTR 44[rsp], 0	# MEM[(int *)_17],
# saves_scene.cpp:60:     menuButtons.emplace_back(0, 0, MENU_BTN_W, MENU_BTN_H, "УДАЛИТЬ СОХРАНЕНИЕ");
	lea	rcx, _ZN10SavesScene10MENU_BTN_WE[rip]	#,
	lea	rdx, 44[rsp]	#,
# saves_scene.cpp:60:     menuButtons.emplace_back(0, 0, MENU_BTN_W, MENU_BTN_H, "УДАЛИТЬ СОХРАНЕНИЕ");
	mov	DWORD PTR 40[rsp], 0	# MEM[(int *)_77],
# saves_scene.cpp:60:     menuButtons.emplace_back(0, 0, MENU_BTN_W, MENU_BTN_H, "УДАЛИТЬ СОХРАНЕНИЕ");
	lea	rsi, 40[rsp]	#,
	call	_ZNSt6vectorI6ButtonSaIS0_EE12emplace_backIJiiRKiS5_RA36_KcEEERS0_DpOT_.isra.0	#
# saves_scene.cpp:61:     menuButtons.emplace_back(0, 0, MENU_BTN_W, MENU_BTN_H, "ПЕРЕИМЕНОВАТЬ");
	lea	r9, .LC29[rip]	#,
	lea	r8, _ZN10SavesScene10MENU_BTN_HE[rip]	#,
	mov	rdi, r12	#, _6
# saves_scene.cpp:61:     menuButtons.emplace_back(0, 0, MENU_BTN_W, MENU_BTN_H, "ПЕРЕИМЕНОВАТЬ");
	mov	DWORD PTR 44[rsp], 0	# MEM[(int *)_17],
# saves_scene.cpp:61:     menuButtons.emplace_back(0, 0, MENU_BTN_W, MENU_BTN_H, "ПЕРЕИМЕНОВАТЬ");
	lea	rcx, _ZN10SavesScene10MENU_BTN_WE[rip]	#,
	lea	rdx, 44[rsp]	#,
# saves_scene.cpp:61:     menuButtons.emplace_back(0, 0, MENU_BTN_W, MENU_BTN_H, "ПЕРЕИМЕНОВАТЬ");
	mov	DWORD PTR 40[rsp], 0	# MEM[(int *)_77],
# saves_scene.cpp:61:     menuButtons.emplace_back(0, 0, MENU_BTN_W, MENU_BTN_H, "ПЕРЕИМЕНОВАТЬ");
	lea	rsi, 40[rsp]	#,
	call	_ZNSt6vectorI6ButtonSaIS0_EE12emplace_backIJiiRKiS5_RA27_KcEEERS0_DpOT_.isra.0	#
# saves_scene.cpp:63:     for (auto& btn : menuButtons) btn.centerX(W);
	mov	rdi, r12	#, _6
	call	_ZNSt6vectorI6ButtonSaIS0_EE5beginEv	#
# saves_scene.cpp:63:     for (auto& btn : menuButtons) btn.centerX(W);
	mov	rdi, r12	#, _6
# saves_scene.cpp:63:     for (auto& btn : menuButtons) btn.centerX(W);
	mov	r14, rax	# __for_begin,
# saves_scene.cpp:63:     for (auto& btn : menuButtons) btn.centerX(W);
	call	_ZNSt6vectorI6ButtonSaIS0_EE3endEv	#
	mov	r13, rax	# SR.1152,
# saves_scene.cpp:63:     for (auto& btn : menuButtons) btn.centerX(W);
	cmp	r14, rax	# __for_begin, SR.1152
	je	.L621	#,
	.p2align 4
	.p2align 3
.L622:
# saves_scene.cpp:63:     for (auto& btn : menuButtons) btn.centerX(W);
	mov	esi, ebp	#, W
	mov	rdi, r14	#, ivtmp.1168
	call	[QWORD PTR _ZN6Button7centerXEi@GOTPCREL[rip]]	#
# saves_scene.cpp:63:     for (auto& btn : menuButtons) btn.centerX(W);
	add	r14, 56	# ivtmp.1168,
	cmp	r13, r14	# SR.1152, ivtmp.1168
	jne	.L622	#,
.L621:
	mov	rdi, QWORD PTR 208[rbx]	# _101, MEM[(struct Button * *)this_21(D) + 208B]
# saves_scene.cpp:64:     for (size_t i = 0; i < menuButtons.size(); ++i)
	mov	rsi, QWORD PTR 216[rbx]	# MEM[(struct Button * *)this_21(D) + 216B], MEM[(struct Button * *)this_21(D) + 216B]
	call	_ZNKSt6vectorI6ButtonSaIS0_EE4sizeEv.isra.0	#
	mov	r8, rax	# _13,
# saves_scene.cpp:64:     for (size_t i = 0; i < menuButtons.size(); ++i)
	test	rax, rax	# _13
	je	.L623	#,
	mov	ecx, 200	# ivtmp.1162,
# saves_scene.cpp:64:     for (size_t i = 0; i < menuButtons.size(); ++i)
	xor	edx, edx	# i
	.p2align 4
	.p2align 3
.L624:
# saves_scene.cpp:65:         menuButtons[i].rect.y = MENU_START_Y + (int)i * (MENU_BTN_H + MENU_BTN_GAP);
	mov	rsi, rdx	#, i
# saves_scene.cpp:64:     for (size_t i = 0; i < menuButtons.size(); ++i)
	add	rdx, 1	# i,
# saves_scene.cpp:65:         menuButtons[i].rect.y = MENU_START_Y + (int)i * (MENU_BTN_H + MENU_BTN_GAP);
	call	_ZNSt6vectorI6ButtonSaIS0_EEixEm.isra.0	#
# saves_scene.cpp:65:         menuButtons[i].rect.y = MENU_START_Y + (int)i * (MENU_BTN_H + MENU_BTN_GAP);
	mov	DWORD PTR 4[rax], ecx	# _12->rect.y, ivtmp.1162
# saves_scene.cpp:64:     for (size_t i = 0; i < menuButtons.size(); ++i)
	add	ecx, 80	# ivtmp.1162,
	cmp	r8, rdx	# _13, i
	jne	.L624	#,
.L623:
# saves_scene.cpp:68:     SaveManager::get().loadIndex();
	call	_ZN11SaveManager3getEv	#
# saves_scene.cpp:68:     SaveManager::get().loadIndex();
	mov	rdi, rax	#, _14
	call	[QWORD PTR _ZN11SaveManager9loadIndexEv@GOTPCREL[rip]]	#
# saves_scene.cpp:69:     rebuildSlots();
	mov	rdi, rbx	#, this
	call	_ZN10SavesScene12rebuildSlotsEv	#
.LEHE59:
# saves_scene.cpp:70: }
	mov	rax, QWORD PTR 88[rsp]	# tmp191, D.173812
	sub	rax, QWORD PTR fs:40	# tmp191, MEM[(<address-space-1> long unsigned int *)40B]
	jne	.L639	#,
	add	rsp, 104	#,
	.cfi_remember_state
	.cfi_def_cfa_offset 56
	pop	rbx	#
	.cfi_def_cfa_offset 48
	pop	rbp	#
	.cfi_def_cfa_offset 40
	pop	r12	#
	.cfi_def_cfa_offset 32
	pop	r13	#
	.cfi_def_cfa_offset 24
	pop	r14	#
	.cfi_def_cfa_offset 16
	pop	r15	#
	.cfi_def_cfa_offset 8
	ret	
.L639:
	.cfi_restore_state
	call	[QWORD PTR __stack_chk_fail@GOTPCREL[rip]]	#
.L631:
	mov	rbx, rax	# tmp188,
	jmp	.L627	#
.L630:
# saves_scene.cpp:51: SavesScene::SavesScene() {
	mov	rbx, rax	# tmp187,
	jmp	.L625	#
	.section	.gcc_except_table
.LLSDA12862:
	.byte	0xff
	.byte	0xff
	.byte	0x1
	.uleb128 .LLSDACSE12862-.LLSDACSB12862
.LLSDACSB12862:
	.uleb128 .LEHB57-.LFB12862
	.uleb128 .LEHE57-.LEHB57
	.uleb128 0
	.uleb128 0
	.uleb128 .LEHB58-.LFB12862
	.uleb128 .LEHE58-.LEHB58
	.uleb128 .L630-.LFB12862
	.uleb128 0
	.uleb128 .LEHB59-.LFB12862
	.uleb128 .LEHE59-.LEHB59
	.uleb128 .L631-.LFB12862
	.uleb128 0
.LLSDACSE12862:
	.text
	.cfi_endproc
	.section	.text.unlikely
	.cfi_startproc
	.cfi_personality 0x9b,DW.ref.__gxx_personality_v0
	.cfi_lsda 0x1b,.LLSDAC12862
	.type	_ZN10SavesSceneC2Ev.cold, @function
_ZN10SavesSceneC2Ev.cold:
.LFSB12862:
.L627:
	.cfi_def_cfa_offset 160
	.cfi_offset 3, -56
	.cfi_offset 6, -48
	.cfi_offset 12, -40
	.cfi_offset 13, -32
	.cfi_offset 14, -24
	.cfi_offset 15, -16
# saves_scene.cpp:70: }
	mov	rdi, r12	#, _6
	call	_ZNSt6vectorI6ButtonSaIS0_EED1Ev	#
	mov	rdi, r15	#, _5
	call	[QWORD PTR _ZNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEED1Ev@GOTPCREL[rip]]	#
	mov	rdi, QWORD PTR 24[rsp]	#, %sfp
	call	_ZNSt6vectorIbSaIbEED1Ev	#
	mov	rdi, QWORD PTR 16[rsp]	#, %sfp
	call	_ZNSt6vectorI6ButtonSaIS0_EED1Ev	#
	mov	rdi, QWORD PTR 8[rsp]	#, %sfp
	call	_ZN6ButtonD1Ev	#
	mov	rax, QWORD PTR 88[rsp]	# tmp190, D.173812
	sub	rax, QWORD PTR fs:40	# tmp190, MEM[(<address-space-1> long unsigned int *)40B]
	jne	.L640	#,
	mov	rdi, rbx	#, tmp188
.LEHB60:
	call	[QWORD PTR _Unwind_Resume@GOTPCREL[rip]]	#
.L625:
# saves_scene.cpp:51: SavesScene::SavesScene() {
	mov	rdi, rbp	#, tmp175
	call	[QWORD PTR _ZNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEED1Ev@GOTPCREL[rip]]	#
	mov	rax, QWORD PTR 88[rsp]	# tmp189, D.173812
	sub	rax, QWORD PTR fs:40	# tmp189, MEM[(<address-space-1> long unsigned int *)40B]
	jne	.L641	#,
	mov	rdi, rbx	#, tmp187
	call	[QWORD PTR _Unwind_Resume@GOTPCREL[rip]]	#
.LEHE60:
.L640:
	call	[QWORD PTR __stack_chk_fail@GOTPCREL[rip]]	#
.L641:
	call	[QWORD PTR __stack_chk_fail@GOTPCREL[rip]]	#
	.cfi_endproc
.LFE12862:
	.section	.gcc_except_table
.LLSDAC12862:
	.byte	0xff
	.byte	0xff
	.byte	0x1
	.uleb128 .LLSDACSEC12862-.LLSDACSBC12862
.LLSDACSBC12862:
	.uleb128 .LEHB60-.LCOLDB30
	.uleb128 .LEHE60-.LEHB60
	.uleb128 0
	.uleb128 0
.LLSDACSEC12862:
	.section	.text.unlikely
	.text
	.size	_ZN10SavesSceneC2Ev, .-_ZN10SavesSceneC2Ev
	.section	.text.unlikely
	.size	_ZN10SavesSceneC2Ev.cold, .-_ZN10SavesSceneC2Ev.cold
.LCOLDE30:
	.text
.LHOTE30:
	.globl	_ZN10SavesSceneC1Ev
	.set	_ZN10SavesSceneC1Ev,_ZN10SavesSceneC2Ev
	.weak	_ZTS5Scene
	.section	.rodata._ZTS5Scene,"aG",@progbits,_ZTS5Scene,comdat
	.type	_ZTS5Scene, @object
	.size	_ZTS5Scene, 7
_ZTS5Scene:
	.string	"5Scene"
	.weak	_ZTI5Scene
	.section	.data.rel.ro._ZTI5Scene,"awG",@progbits,_ZTI5Scene,comdat
	.align 8
	.type	_ZTI5Scene, @object
	.size	_ZTI5Scene, 16
_ZTI5Scene:
# <anonymous>:
# <anonymous>:
	.quad	_ZTVN10__cxxabiv117__class_type_infoE+16
# <anonymous>:
	.quad	_ZTS5Scene
	.weak	_ZTS10SavesScene
	.section	.rodata._ZTS10SavesScene,"aG",@progbits,_ZTS10SavesScene,comdat
	.align 8
	.type	_ZTS10SavesScene, @object
	.size	_ZTS10SavesScene, 13
_ZTS10SavesScene:
	.string	"10SavesScene"
	.weak	_ZTI10SavesScene
	.section	.data.rel.ro._ZTI10SavesScene,"awG",@progbits,_ZTI10SavesScene,comdat
	.align 8
	.type	_ZTI10SavesScene, @object
	.size	_ZTI10SavesScene, 24
_ZTI10SavesScene:
# <anonymous>:
# <anonymous>:
	.quad	_ZTVN10__cxxabiv120__si_class_type_infoE+16
# <anonymous>:
	.quad	_ZTS10SavesScene
# <anonymous>:
	.quad	_ZTI5Scene
	.weak	_ZTV10SavesScene
	.section	.data.rel.ro.local._ZTV10SavesScene,"awG",@progbits,_ZTV10SavesScene,comdat
	.align 8
	.type	_ZTV10SavesScene, @object
	.size	_ZTV10SavesScene, 64
_ZTV10SavesScene:
	.quad	0
	.quad	_ZTI10SavesScene
	.quad	_ZN10SavesSceneD1Ev
	.quad	_ZN10SavesSceneD0Ev
	.quad	_ZN10SavesScene11handleInputER9SDL_Eventiibb
	.quad	_ZN10SavesScene6updateEf
	.quad	_ZN10SavesScene6renderEP12SDL_Renderer
	.quad	_ZN10SavesScene12getNextSceneEv
	.weak	_ZN10SavesScene10MENU_BTN_HE
	.section	.rodata._ZN10SavesScene10MENU_BTN_HE,"aG",@progbits,_ZN10SavesScene10MENU_BTN_HE,comdat
	.align 4
	.type	_ZN10SavesScene10MENU_BTN_HE, @gnu_unique_object
	.size	_ZN10SavesScene10MENU_BTN_HE, 4
_ZN10SavesScene10MENU_BTN_HE:
	.long	60
	.weak	_ZN10SavesScene10MENU_BTN_WE
	.section	.rodata._ZN10SavesScene10MENU_BTN_WE,"aG",@progbits,_ZN10SavesScene10MENU_BTN_WE,comdat
	.align 4
	.type	_ZN10SavesScene10MENU_BTN_WE, @gnu_unique_object
	.size	_ZN10SavesScene10MENU_BTN_WE, 4
_ZN10SavesScene10MENU_BTN_WE:
	.long	300
	.weak	_ZN10SavesScene10PLUS_BTN_YE
	.section	.rodata._ZN10SavesScene10PLUS_BTN_YE,"aG",@progbits,_ZN10SavesScene10PLUS_BTN_YE,comdat
	.align 4
	.type	_ZN10SavesScene10PLUS_BTN_YE, @gnu_unique_object
	.size	_ZN10SavesScene10PLUS_BTN_YE, 4
_ZN10SavesScene10PLUS_BTN_YE:
	.long	180
	.weak	_ZN10SavesScene10PLUS_BTN_HE
	.section	.rodata._ZN10SavesScene10PLUS_BTN_HE,"aG",@progbits,_ZN10SavesScene10PLUS_BTN_HE,comdat
	.align 4
	.type	_ZN10SavesScene10PLUS_BTN_HE, @gnu_unique_object
	.size	_ZN10SavesScene10PLUS_BTN_HE, 4
_ZN10SavesScene10PLUS_BTN_HE:
	.long	60
	.weak	_ZN10SavesScene10PLUS_BTN_WE
	.section	.rodata._ZN10SavesScene10PLUS_BTN_WE,"aG",@progbits,_ZN10SavesScene10PLUS_BTN_WE,comdat
	.align 4
	.type	_ZN10SavesScene10PLUS_BTN_WE, @gnu_unique_object
	.size	_ZN10SavesScene10PLUS_BTN_WE, 4
_ZN10SavesScene10PLUS_BTN_WE:
	.long	300
	.weak	_ZGVZN11SaveManager3getEvE8instance
	.section	.bss._ZGVZN11SaveManager3getEvE8instance,"awG",@nobits,_ZGVZN11SaveManager3getEvE8instance,comdat
	.align 8
	.type	_ZGVZN11SaveManager3getEvE8instance, @gnu_unique_object
	.size	_ZGVZN11SaveManager3getEvE8instance, 8
_ZGVZN11SaveManager3getEvE8instance:
	.zero	8
	.weak	_ZZN11SaveManager3getEvE8instance
	.section	.bss._ZZN11SaveManager3getEvE8instance,"awG",@nobits,_ZZN11SaveManager3getEvE8instance,comdat
	.align 32
	.type	_ZZN11SaveManager3getEvE8instance, @gnu_unique_object
	.size	_ZZN11SaveManager3getEvE8instance, 144
_ZZN11SaveManager3getEvE8instance:
	.zero	144
	.section	.rodata.cst16,"aM",@progbits,16
	.align 16
.LC1:
	.long	0
	.long	1
	.long	3
	.long	44
	.align 16
.LC2:
	.long	4
	.long	7
	.long	22
	.long	8
	.section	.rodata.cst8,"aM",@progbits,8
	.align 8
.LC3:
	.long	225
	.long	9
	.section	.rodata.cst16
	.align 16
.LC25:
	.long	0
	.long	300
	.long	400
	.long	50
	.hidden	DW.ref.__gxx_personality_v0
	.weak	DW.ref.__gxx_personality_v0
	.section	.data.rel.local.DW.ref.__gxx_personality_v0,"awG",@progbits,DW.ref.__gxx_personality_v0,comdat
	.align 8
	.type	DW.ref.__gxx_personality_v0, @object
	.size	DW.ref.__gxx_personality_v0, 8
DW.ref.__gxx_personality_v0:
	.quad	__gxx_personality_v0
	.hidden	__dso_handle
	.globl	__gxx_personality_v0
	.ident	"GCC: (GNU) 15.2.1 20260209"
	.section	.note.GNU-stack,"",@progbits
