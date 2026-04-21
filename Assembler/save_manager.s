	.file	"save_manager.cpp"
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
	.type	_ZZNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEE12_M_constructIPKcEEvT_S8_St20forward_iterator_tagEN6_GuardD2Ev.constprop.0.isra.0, @function
_ZZNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEE12_M_constructIPKcEEvT_S8_St20forward_iterator_tagEN6_GuardD2Ev.constprop.0.isra.0:
.LFB14820:
	.cfi_startproc
# /usr/include/c++/15.2.1/bits/basic_string.tcc:248: 	  ~_Guard() { if (_M_guarded) _M_guarded->_M_dispose(); }
	ret	
	.cfi_endproc
.LFE14820:
	.size	_ZZNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEE12_M_constructIPKcEEvT_S8_St20forward_iterator_tagEN6_GuardD2Ev.constprop.0.isra.0, .-_ZZNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEE12_M_constructIPKcEEvT_S8_St20forward_iterator_tagEN6_GuardD2Ev.constprop.0.isra.0
	.section	.text._ZN9SaveEntryaSEOS_.isra.0,"axG",@progbits,_ZSt14__copy_move_a2ILb1EP9SaveEntryS1_S1_ET2_T0_T1_S2_,comdat
	.align 2
	.p2align 4
	.type	_ZN9SaveEntryaSEOS_.isra.0, @function
_ZN9SaveEntryaSEOS_.isra.0:
.LFB14821:
	.cfi_startproc
	push	rbp	#
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	mov	rbp, rsi	# D.188795, D.188795
	lea	rsi, 8[rsi]	# _4,
	push	rbx	#
	.cfi_def_cfa_offset 24
	.cfi_offset 3, -24
	mov	rbx, rdi	# this, this
	lea	rdi, 8[rdi]	# _5,
	sub	rsp, 8	#,
	.cfi_def_cfa_offset 32
# save_manager.h:77: struct SaveEntry {
	mov	eax, DWORD PTR -8[rsi]	# _2, _1(D)->number
	mov	DWORD PTR -8[rdi], eax	# this_3(D)->number, _2
	call	[QWORD PTR _ZNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEEaSEOS4_@GOTPCREL[rip]]	#
	add	rsp, 8	#,
	.cfi_def_cfa_offset 24
# save_manager.h:77: struct SaveEntry {
	lea	rsi, 40[rbp]	# _6,
	lea	rdi, 40[rbx]	# _7,
# save_manager.h:77: struct SaveEntry {
	pop	rbx	#
	.cfi_def_cfa_offset 16
	pop	rbp	#
	.cfi_def_cfa_offset 8
# save_manager.h:77: struct SaveEntry {
	jmp	[QWORD PTR _ZNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEEaSEOS4_@GOTPCREL[rip]]	#
	.cfi_endproc
.LFE14821:
	.size	_ZN9SaveEntryaSEOS_.isra.0, .-_ZN9SaveEntryaSEOS_.isra.0
	.section	.text._ZSt12__niter_wrapIN9__gnu_cxx17__normal_iteratorIP9SaveEntrySt6vectorIS2_SaIS2_EEEES3_ET_S8_T0_.isra.0,"axG",@progbits,_ZNSt6vectorI9SaveEntrySaIS0_EE8_M_eraseEN9__gnu_cxx17__normal_iteratorIPS0_S2_EE,comdat
	.p2align 4
	.type	_ZSt12__niter_wrapIN9__gnu_cxx17__normal_iteratorIP9SaveEntrySt6vectorIS2_SaIS2_EEEES3_ET_S8_T0_.isra.0, @function
_ZSt12__niter_wrapIN9__gnu_cxx17__normal_iteratorIP9SaveEntrySt6vectorIS2_SaIS2_EEEES3_ET_S8_T0_.isra.0:
.LFB14822:
	.cfi_startproc
# /usr/include/c++/15.2.1/bits/stl_iterator.h:3073:     __niter_wrap(_From __from, _To __res)
	mov	rax, rdi	# __res, __res
# /usr/include/c++/15.2.1/bits/stl_iterator.h:3074:     { return __from + (std::__niter_base(__res) - std::__niter_base(__from)); }
	ret	
	.cfi_endproc
.LFE14822:
	.size	_ZSt12__niter_wrapIN9__gnu_cxx17__normal_iteratorIP9SaveEntrySt6vectorIS2_SaIS2_EEEES3_ET_S8_T0_.isra.0, .-_ZSt12__niter_wrapIN9__gnu_cxx17__normal_iteratorIP9SaveEntrySt6vectorIS2_SaIS2_EEEES3_ET_S8_T0_.isra.0
	.section	.text._ZNSt15__new_allocatorI9SaveEntryE8allocateEmPKv.isra.0,"axG",@progbits,_ZNSt6vectorI9SaveEntrySaIS0_EE17_M_realloc_appendIJRKS0_EEEvDpOT_,comdat
	.align 2
	.p2align 4
	.type	_ZNSt15__new_allocatorI9SaveEntryE8allocateEmPKv.isra.0, @function
_ZNSt15__new_allocatorI9SaveEntryE8allocateEmPKv.isra.0:
.LFB14823:
	.cfi_startproc
# /usr/include/c++/15.2.1/bits/new_allocator.h:134: 	if (__builtin_expect(__n > this->_M_max_size(), false))
	movabs	rax, 128102389400760775	# tmp101,
	cmp	rax, rdi	# tmp101, __n
	jb	.L12	#,
# /usr/include/c++/15.2.1/bits/new_allocator.h:151: 	return static_cast<_Tp*>(_GLIBCXX_OPERATOR_NEW(__n * sizeof(_Tp)));
	lea	rdi, [rdi+rdi*8]	# _5,
	sal	rdi, 3	# tmp106,
	jmp	[QWORD PTR _Znwm@GOTPCREL[rip]]	#
	.p2align 4,,10
	.p2align 3
.L12:
# /usr/include/c++/15.2.1/bits/new_allocator.h:138: 	    if (__n > (std::size_t(-1) / sizeof(_Tp)))
	movabs	rax, 256204778801521550	# tmp102,
# /usr/include/c++/15.2.1/bits/new_allocator.h:126:       allocate(size_type __n, const void* = static_cast<const void*>(0))
	sub	rsp, 8	#,
	.cfi_def_cfa_offset 16
# /usr/include/c++/15.2.1/bits/new_allocator.h:138: 	    if (__n > (std::size_t(-1) / sizeof(_Tp)))
	cmp	rax, rdi	# tmp102, __n
	jnb	.L8	#,
# /usr/include/c++/15.2.1/bits/new_allocator.h:139: 	      std::__throw_bad_array_new_length();
	call	[QWORD PTR _ZSt28__throw_bad_array_new_lengthv@GOTPCREL[rip]]	#
	.p2align 4,,10
	.p2align 3
.L8:
# /usr/include/c++/15.2.1/bits/new_allocator.h:140: 	    std::__throw_bad_alloc();
	call	[QWORD PTR _ZSt17__throw_bad_allocv@GOTPCREL[rip]]	#
	.cfi_endproc
.LFE14823:
	.size	_ZNSt15__new_allocatorI9SaveEntryE8allocateEmPKv.isra.0, .-_ZNSt15__new_allocatorI9SaveEntryE8allocateEmPKv.isra.0
	.section	.text._ZNSt15__new_allocatorI9SaveEntryE10deallocateEPS0_m.isra.0,"axG",@progbits,_ZNSt6vectorI9SaveEntrySaIS0_EE12_Guard_allocD5Ev,comdat
	.align 2
	.p2align 4
	.type	_ZNSt15__new_allocatorI9SaveEntryE10deallocateEPS0_m.isra.0, @function
_ZNSt15__new_allocatorI9SaveEntryE10deallocateEPS0_m.isra.0:
.LFB14824:
	.cfi_startproc
# /usr/include/c++/15.2.1/bits/new_allocator.h:172: 	_GLIBCXX_OPERATOR_DELETE(_GLIBCXX_SIZED_DEALLOC(__p, __n));
	lea	rsi, [rsi+rsi*8]	# _2,
	sal	rsi, 3	# tmp104,
	jmp	[QWORD PTR _ZdlPvm@GOTPCREL[rip]]	#
	.cfi_endproc
.LFE14824:
	.size	_ZNSt15__new_allocatorI9SaveEntryE10deallocateEPS0_m.isra.0, .-_ZNSt15__new_allocatorI9SaveEntryE10deallocateEPS0_m.isra.0
	.section	.text._ZNSt12_Vector_baseI9SaveEntrySaIS0_EE11_M_allocateEm.isra.0,"axG",@progbits,_ZNSt6vectorI9SaveEntrySaIS0_EE17_M_realloc_appendIJRKS0_EEEvDpOT_,comdat
	.align 2
	.p2align 4
	.type	_ZNSt12_Vector_baseI9SaveEntrySaIS0_EE11_M_allocateEm.isra.0, @function
_ZNSt12_Vector_baseI9SaveEntrySaIS0_EE11_M_allocateEm.isra.0:
.LFB14825:
	.cfi_startproc
# /usr/include/c++/15.2.1/bits/stl_vector.h:387: 	return __n != 0 ? _Tr::allocate(_M_impl, __n) : pointer();
	test	rdi, rdi	# __n
	je	.L15	#,
# /usr/include/c++/15.2.1/bits/alloc_traits.h:614:       { return __a.allocate(__n); }
	jmp	_ZNSt15__new_allocatorI9SaveEntryE8allocateEmPKv.isra.0	#
	.p2align 4,,10
	.p2align 3
.L15:
# /usr/include/c++/15.2.1/bits/stl_vector.h:388:       }
	xor	eax, eax	#
	ret	
	.cfi_endproc
.LFE14825:
	.size	_ZNSt12_Vector_baseI9SaveEntrySaIS0_EE11_M_allocateEm.isra.0, .-_ZNSt12_Vector_baseI9SaveEntrySaIS0_EE11_M_allocateEm.isra.0
	.section	.text._ZNSt12_Vector_baseI9SaveEntrySaIS0_EE13_M_deallocateEPS0_m.isra.0,"axG",@progbits,_ZNSt6vectorI9SaveEntrySaIS0_EE12_Guard_allocD5Ev,comdat
	.align 2
	.p2align 4
	.type	_ZNSt12_Vector_baseI9SaveEntrySaIS0_EE13_M_deallocateEPS0_m.isra.0, @function
_ZNSt12_Vector_baseI9SaveEntrySaIS0_EE13_M_deallocateEPS0_m.isra.0:
.LFB14826:
	.cfi_startproc
# /usr/include/c++/15.2.1/bits/stl_vector.h:395: 	if (__p)
	test	rdi, rdi	# __p
	je	.L16	#,
# /usr/include/c++/15.2.1/bits/alloc_traits.h:649:       { __a.deallocate(__p, __n); }
	jmp	_ZNSt15__new_allocatorI9SaveEntryE10deallocateEPS0_m.isra.0	#
	.p2align 4,,10
	.p2align 3
.L16:
# /usr/include/c++/15.2.1/bits/stl_vector.h:397:       }
	ret	
	.cfi_endproc
.LFE14826:
	.size	_ZNSt12_Vector_baseI9SaveEntrySaIS0_EE13_M_deallocateEPS0_m.isra.0, .-_ZNSt12_Vector_baseI9SaveEntrySaIS0_EE13_M_deallocateEPS0_m.isra.0
	.text
	.align 2
	.p2align 4
	.type	_ZNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEE12_Alloc_hiderC2EPcRKS3_.isra.0, @function
_ZNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEE12_Alloc_hiderC2EPcRKS3_.isra.0:
.LFB14827:
	.cfi_startproc
# /usr/include/c++/15.2.1/bits/basic_string.h:205: 	: allocator_type(__a), _M_p(__dat) { }
	mov	QWORD PTR [rdi], rsi	# *this_1(D)._M_p, __dat
# /usr/include/c++/15.2.1/bits/basic_string.h:205: 	: allocator_type(__a), _M_p(__dat) { }
	ret	
	.cfi_endproc
.LFE14827:
	.size	_ZNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEE12_Alloc_hiderC2EPcRKS3_.isra.0, .-_ZNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEE12_Alloc_hiderC2EPcRKS3_.isra.0
	.align 2
	.p2align 4
	.type	_ZNSt6vectorI9SaveEntrySaIS0_EEixEm.isra.0, @function
_ZNSt6vectorI9SaveEntrySaIS0_EEixEm.isra.0:
.LFB14828:
	.cfi_startproc
# /usr/include/c++/15.2.1/bits/stl_vector.h:1264: 	return *(this->_M_impl._M_start + __n);
	lea	rax, [rsi+rsi*8]	# _3,
# /usr/include/c++/15.2.1/bits/stl_vector.h:1264: 	return *(this->_M_impl._M_start + __n);
	lea	rax, [rdi+rax*8]	# _4,
# /usr/include/c++/15.2.1/bits/stl_vector.h:1265:       }
	ret	
	.cfi_endproc
.LFE14828:
	.size	_ZNSt6vectorI9SaveEntrySaIS0_EEixEm.isra.0, .-_ZNSt6vectorI9SaveEntrySaIS0_EEixEm.isra.0
	.align 2
	.p2align 4
	.type	_ZNKSt6vectorI9SaveEntrySaIS0_EE4sizeEv.isra.0, @function
_ZNKSt6vectorI9SaveEntrySaIS0_EE4sizeEv.isra.0:
.LFB14829:
	.cfi_startproc
# /usr/include/c++/15.2.1/bits/stl_vector.h:1119: 	ptrdiff_t __dif = this->_M_impl._M_finish - this->_M_impl._M_start;
	movabs	rax, -8198552921648689607	# tmp107,
# /usr/include/c++/15.2.1/bits/stl_vector.h:1119: 	ptrdiff_t __dif = this->_M_impl._M_finish - this->_M_impl._M_start;
	sub	rsi, rdi	# _3, ISRA.447
# /usr/include/c++/15.2.1/bits/stl_vector.h:1119: 	ptrdiff_t __dif = this->_M_impl._M_finish - this->_M_impl._M_start;
	sar	rsi, 3	# tmp105,
	imul	rax, rsi	# __dif_4, tmp105
# /usr/include/c++/15.2.1/bits/stl_vector.h:1123:       }
	ret	
	.cfi_endproc
.LFE14829:
	.size	_ZNKSt6vectorI9SaveEntrySaIS0_EE4sizeEv.isra.0, .-_ZNKSt6vectorI9SaveEntrySaIS0_EE4sizeEv.isra.0
	.section	.text._ZNKSt17basic_string_viewIcSt11char_traitsIcEE4sizeEv.isra.0,"axG",@progbits,_ZNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEEC5ISt17basic_string_viewIcS2_EvEERKT_RKS3_,comdat
	.align 2
	.p2align 4
	.type	_ZNKSt17basic_string_viewIcSt11char_traitsIcEE4sizeEv.isra.0, @function
_ZNKSt17basic_string_viewIcSt11char_traitsIcEE4sizeEv.isra.0:
.LFB14830:
	.cfi_startproc
# /usr/include/c++/15.2.1/string_view:233:       size() const noexcept
	mov	rax, rdi	# ISRA.452, ISRA.452
# /usr/include/c++/15.2.1/string_view:234:       { return this->_M_len; }
	ret	
	.cfi_endproc
.LFE14830:
	.size	_ZNKSt17basic_string_viewIcSt11char_traitsIcEE4sizeEv.isra.0, .-_ZNKSt17basic_string_viewIcSt11char_traitsIcEE4sizeEv.isra.0
	.text
	.align 2
	.p2align 4
	.type	_ZNKSt10error_codecvbEv.isra.0, @function
_ZNKSt10error_codecvbEv.isra.0:
.LFB14831:
	.cfi_startproc
# /usr/include/c++/15.2.1/system_error:284:     { return _M_value != 0; }
	test	edi, edi	# ISRA.456
	setne	al	#, _2
# /usr/include/c++/15.2.1/system_error:284:     { return _M_value != 0; }
	ret	
	.cfi_endproc
.LFE14831:
	.size	_ZNKSt10error_codecvbEv.isra.0, .-_ZNKSt10error_codecvbEv.isra.0
	.align 2
	.p2align 4
	.type	_ZNKSt10error_code8categoryEv.isra.0, @function
_ZNKSt10error_code8categoryEv.isra.0:
.LFB14832:
	.cfi_startproc
# /usr/include/c++/15.2.1/system_error:269:     category() const noexcept { return *_M_cat; }
	mov	rax, rdi	# ISRA.460, ISRA.460
# /usr/include/c++/15.2.1/system_error:269:     category() const noexcept { return *_M_cat; }
	ret	
	.cfi_endproc
.LFE14832:
	.size	_ZNKSt10error_code8categoryEv.isra.0, .-_ZNKSt10error_code8categoryEv.isra.0
	.align 2
	.p2align 4
	.type	_ZNKSt10error_code5valueEv.isra.0, @function
_ZNKSt10error_code5valueEv.isra.0:
.LFB14833:
	.cfi_startproc
# /usr/include/c++/15.2.1/system_error:264:     value() const noexcept { return _M_value; }
	mov	eax, edi	# ISRA.464, ISRA.464
# /usr/include/c++/15.2.1/system_error:264:     value() const noexcept { return _M_value; }
	ret	
	.cfi_endproc
.LFE14833:
	.size	_ZNKSt10error_code5valueEv.isra.0, .-_ZNKSt10error_code5valueEv.isra.0
	.align 2
	.p2align 4
	.type	_ZNKSt10error_code7messageB5cxx11Ev.isra.0, @function
_ZNKSt10error_code7messageB5cxx11Ev.isra.0:
.LFB14834:
	.cfi_startproc
	push	rbx	#
	.cfi_def_cfa_offset 16
	.cfi_offset 3, -16
	sub	rsp, 16	#,
	.cfi_def_cfa_offset 32
# /usr/include/c++/15.2.1/system_error:278:     message() const
	mov	rbx, QWORD PTR fs:40	# <retval>, MEM[(<address-space-1> long unsigned int *)40B]
	mov	QWORD PTR 8[rsp], rbx	# D.188909, <retval>
	mov	rbx, rdi	# <retval>, .result_ptr
# /usr/include/c++/15.2.1/system_error:279:     { return category().message(value()); }
	mov	rdi, rdx	#, ISRA.469
	call	_ZNKSt10error_code8categoryEv.isra.0	#
# /usr/include/c++/15.2.1/system_error:279:     { return category().message(value()); }
	mov	edi, esi	#, ISRA.468
# /usr/include/c++/15.2.1/system_error:279:     { return category().message(value()); }
	mov	rsi, rax	# _2,
# /usr/include/c++/15.2.1/system_error:279:     { return category().message(value()); }
	mov	rax, QWORD PTR [rax]	# _2->_vptr.error_category, _2->_vptr.error_category
	mov	rcx, QWORD PTR 32[rax]	# _4, MEM[(int (*) () *)_3 + 32B]
# /usr/include/c++/15.2.1/system_error:279:     { return category().message(value()); }
	call	_ZNKSt10error_code5valueEv.isra.0	#
# /usr/include/c++/15.2.1/system_error:279:     { return category().message(value()); }
	mov	edx, eax	#, _5
	mov	rdi, rbx	#, <retval>
	call	rcx	# _4
# /usr/include/c++/15.2.1/system_error:279:     { return category().message(value()); }
	mov	rax, QWORD PTR 8[rsp]	# tmp115, D.188909
	sub	rax, QWORD PTR fs:40	# tmp115, MEM[(<address-space-1> long unsigned int *)40B]
	jne	.L28	#,
	add	rsp, 16	#,
	.cfi_remember_state
	.cfi_def_cfa_offset 16
	mov	rax, rbx	#, <retval>
	pop	rbx	#
	.cfi_def_cfa_offset 8
	ret	
.L28:
	.cfi_restore_state
	call	[QWORD PTR __stack_chk_fail@GOTPCREL[rip]]	#
	.cfi_endproc
.LFE14834:
	.size	_ZNKSt10error_code7messageB5cxx11Ev.isra.0, .-_ZNKSt10error_code7messageB5cxx11Ev.isra.0
	.section	.text._ZNKSt17basic_string_viewIcSt11char_traitsIcEE4dataEv.isra.0,"axG",@progbits,_ZNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEEC5ISt17basic_string_viewIcS2_EvEERKT_RKS3_,comdat
	.align 2
	.p2align 4
	.type	_ZNKSt17basic_string_viewIcSt11char_traitsIcEE4dataEv.isra.0, @function
_ZNKSt17basic_string_viewIcSt11char_traitsIcEE4dataEv.isra.0:
.LFB14835:
	.cfi_startproc
# /usr/include/c++/15.2.1/string_view:293:       data() const noexcept
	mov	rax, rdi	# ISRA.473, ISRA.473
# /usr/include/c++/15.2.1/string_view:294:       { return this->_M_str; }
	ret	
	.cfi_endproc
.LFE14835:
	.size	_ZNKSt17basic_string_viewIcSt11char_traitsIcEE4dataEv.isra.0, .-_ZNKSt17basic_string_viewIcSt11char_traitsIcEE4dataEv.isra.0
	.text
	.p2align 4
	.type	_ZnwmPv.isra.0, @function
_ZnwmPv.isra.0:
.LFB14836:
	.cfi_startproc
# /usr/include/c++/15.2.1/new:206: void* operator new(std::size_t, void* __p)
	mov	rax, rdi	# __p, __p
# /usr/include/c++/15.2.1/new:208: { return __p; }
	ret	
	.cfi_endproc
.LFE14836:
	.size	_ZnwmPv.isra.0, .-_ZnwmPv.isra.0
	.section	.text._ZNSt11char_traitsIcE7compareEPKcS2_m,"axG",@progbits,_ZNSt11char_traitsIcE7compareEPKcS2_m,comdat
	.p2align 4
	.weak	_ZNSt11char_traitsIcE7compareEPKcS2_m
	.type	_ZNSt11char_traitsIcE7compareEPKcS2_m, @function
_ZNSt11char_traitsIcE7compareEPKcS2_m:
.LFB8400:
	.cfi_startproc
# /usr/include/c++/15.2.1/bits/char_traits.h:370: 	if (__n == 0)
	test	rdx, rdx	# __n
	je	.L32	#,
# /usr/include/c++/15.2.1/bits/char_traits.h:383: 	return __builtin_memcmp(__s1, __s2, __n);
	jmp	[QWORD PTR memcmp@GOTPCREL[rip]]	#
	.p2align 4,,10
	.p2align 3
.L32:
# /usr/include/c++/15.2.1/bits/char_traits.h:384:       }
	xor	eax, eax	#
	ret	
	.cfi_endproc
.LFE8400:
	.size	_ZNSt11char_traitsIcE7compareEPKcS2_m, .-_ZNSt11char_traitsIcE7compareEPKcS2_m
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
	.section	.text._ZNSt8__detail14__to_chars_lenIjEEjT_i,"axG",@progbits,_ZNSt8__detail14__to_chars_lenIjEEjT_i,comdat
	.p2align 4
	.weak	_ZNSt8__detail14__to_chars_lenIjEEjT_i
	.type	_ZNSt8__detail14__to_chars_lenIjEEjT_i, @function
_ZNSt8__detail14__to_chars_lenIjEEjT_i:
.LFB9069:
	.cfi_startproc
# /usr/include/c++/15.2.1/bits/charconv.h:57:     __to_chars_len(_Tp __value, int __base = 10) noexcept
	mov	r8d, esi	# __base.8_2, __base
# /usr/include/c++/15.2.1/bits/charconv.h:69: 	  if (__value < (unsigned)__base) return __n;
	cmp	edi, esi	# __value, __base.8_2
	jb	.L40	#,
# /usr/include/c++/15.2.1/bits/charconv.h:64:       const unsigned __b2 = __base  * __base;
	mov	r9d, esi	# __b2, __base.8_2
# /usr/include/c++/15.2.1/bits/charconv.h:65:       const unsigned __b3 = __b2 * __base;
	mov	r10d, esi	# __b3, __base.8_2
# /usr/include/c++/15.2.1/bits/charconv.h:66:       const unsigned long __b4 = __b3 * __base;
	mov	r11d, esi	# _3, __base.8_2
# /usr/include/c++/15.2.1/bits/charconv.h:63:       unsigned __n = 1;
	mov	ecx, 1	# <retval>,
# /usr/include/c++/15.2.1/bits/charconv.h:64:       const unsigned __b2 = __base  * __base;
	imul	r9d, esi	# __b2, __base.8_2
# /usr/include/c++/15.2.1/bits/charconv.h:65:       const unsigned __b3 = __b2 * __base;
	imul	r10d, r9d	# __b3, __b2
# /usr/include/c++/15.2.1/bits/charconv.h:66:       const unsigned long __b4 = __b3 * __base;
	imul	r11d, r10d	# _3, __b3
# /usr/include/c++/15.2.1/bits/charconv.h:66:       const unsigned long __b4 = __b3 * __base;
	mov	esi, r11d	# __b4, _3
	jmp	.L39	#
	.p2align 4,,10
	.p2align 3
.L36:
# /usr/include/c++/15.2.1/bits/charconv.h:71: 	  if (__value < __b3) return __n + 2;
	cmp	edi, r10d	# __value, __b3
	jb	.L42	#,
# /usr/include/c++/15.2.1/bits/charconv.h:72: 	  if (__value < __b4) return __n + 3;
	cmp	edi, r11d	# __value, _3
	jb	.L43	#,
# /usr/include/c++/15.2.1/bits/charconv.h:73: 	  __value /= __b4;
	mov	eax, edi	# _4, __value
	xor	edx, edx	# tmp111
# /usr/include/c++/15.2.1/bits/charconv.h:74: 	  __n += 4;
	add	ecx, 4	# <retval>,
# /usr/include/c++/15.2.1/bits/charconv.h:73: 	  __value /= __b4;
	div	rsi	# __b4
	mov	edi, eax	# __value, _5
# /usr/include/c++/15.2.1/bits/charconv.h:69: 	  if (__value < (unsigned)__base) return __n;
	cmp	eax, r8d	# _5, __base.8_2
	jb	.L34	#,
.L39:
# /usr/include/c++/15.2.1/bits/charconv.h:70: 	  if (__value < __b2) return __n + 1;
	cmp	edi, r9d	# __value, __b2
	jnb	.L36	#,
# /usr/include/c++/15.2.1/bits/charconv.h:70: 	  if (__value < __b2) return __n + 1;
	add	ecx, 1	# <retval>,
.L34:
# /usr/include/c++/15.2.1/bits/charconv.h:76:     }
	mov	eax, ecx	#, <retval>
	ret	
	.p2align 4,,10
	.p2align 3
.L42:
# /usr/include/c++/15.2.1/bits/charconv.h:71: 	  if (__value < __b3) return __n + 2;
	add	ecx, 2	# <retval>,
# /usr/include/c++/15.2.1/bits/charconv.h:76:     }
	mov	eax, ecx	#, <retval>
	ret	
	.p2align 4,,10
	.p2align 3
.L43:
# /usr/include/c++/15.2.1/bits/charconv.h:72: 	  if (__value < __b4) return __n + 3;
	add	ecx, 3	# <retval>,
# /usr/include/c++/15.2.1/bits/charconv.h:76:     }
	mov	eax, ecx	#, <retval>
	ret	
.L40:
# /usr/include/c++/15.2.1/bits/charconv.h:69: 	  if (__value < (unsigned)__base) return __n;
	mov	ecx, 1	# <retval>,
	jmp	.L34	#
	.cfi_endproc
.LFE9069:
	.size	_ZNSt8__detail14__to_chars_lenIjEEjT_i, .-_ZNSt8__detail14__to_chars_lenIjEEjT_i
	.section	.text._ZNSt10error_codeC2Ev,"axG",@progbits,_ZNSt10error_codeC5Ev,comdat
	.align 2
	.p2align 4
	.weak	_ZNSt10error_codeC2Ev
	.type	_ZNSt10error_codeC2Ev, @function
_ZNSt10error_codeC2Ev:
.LFB9421:
	.cfi_startproc
	push	rbx	#
	.cfi_def_cfa_offset 16
	.cfi_offset 3, -16
# /usr/include/c++/15.2.1/system_error:232:     error_code() noexcept
	mov	rbx, rdi	# this, this
# /usr/include/c++/15.2.1/system_error:233:     : _M_value(0), _M_cat(&system_category()) { }
	mov	DWORD PTR [rdi], 0	# *this_3(D)._M_value,
# /usr/include/c++/15.2.1/system_error:233:     : _M_value(0), _M_cat(&system_category()) { }
	call	[QWORD PTR _ZNSt3_V215system_categoryEv@GOTPCREL[rip]]	#
# /usr/include/c++/15.2.1/system_error:233:     : _M_value(0), _M_cat(&system_category()) { }
	mov	QWORD PTR 8[rbx], rax	# *this_3(D)._M_cat, _1
# /usr/include/c++/15.2.1/system_error:233:     : _M_value(0), _M_cat(&system_category()) { }
	pop	rbx	#
	.cfi_def_cfa_offset 8
	ret	
	.cfi_endproc
.LFE9421:
	.size	_ZNSt10error_codeC2Ev, .-_ZNSt10error_codeC2Ev
	.weak	_ZNSt10error_codeC1Ev
	.set	_ZNSt10error_codeC1Ev,_ZNSt10error_codeC2Ev
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
	.section	.text._ZNSt6vectorI9SaveEntrySaIS0_EE11_S_max_sizeERKS1_.isra.0,"axG",@progbits,_ZNKSt6vectorI9SaveEntrySaIS0_EE8max_sizeEv,comdat
	.p2align 4
	.type	_ZNSt6vectorI9SaveEntrySaIS0_EE11_S_max_sizeERKS1_.isra.0, @function
_ZNSt6vectorI9SaveEntrySaIS0_EE11_S_max_sizeERKS1_.isra.0:
.LFB14837:
	.cfi_startproc
	sub	rsp, 40	#,
	.cfi_def_cfa_offset 48
# /usr/include/c++/15.2.1/bits/stl_vector.h:2227: 	const size_t __diffmax
	mov	rax, QWORD PTR fs:40	# tmp111, MEM[(<address-space-1> long unsigned int *)40B]
	mov	QWORD PTR 24[rsp], rax	# D.188961, tmp111
	movabs	rax, 128102389400760775	# tmp111,
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
	mov	rdx, QWORD PTR 24[rsp]	# tmp109, D.188961
	sub	rdx, QWORD PTR fs:40	# tmp109, MEM[(<address-space-1> long unsigned int *)40B]
	jne	.L52	#,
	add	rsp, 40	#,
	.cfi_remember_state
	.cfi_def_cfa_offset 8
	ret	
.L52:
	.cfi_restore_state
	call	[QWORD PTR __stack_chk_fail@GOTPCREL[rip]]	#
	.cfi_endproc
.LFE14837:
	.size	_ZNSt6vectorI9SaveEntrySaIS0_EE11_S_max_sizeERKS1_.isra.0, .-_ZNSt6vectorI9SaveEntrySaIS0_EE11_S_max_sizeERKS1_.isra.0
	.section	.text._ZN6Config20getCurrentDifficultyEv,"axG",@progbits,_ZN6Config20getCurrentDifficultyEv,comdat
	.p2align 4
	.weak	_ZN6Config20getCurrentDifficultyEv
	.type	_ZN6Config20getCurrentDifficultyEv, @function
_ZN6Config20getCurrentDifficultyEv:
.LFB12792:
	.cfi_startproc
# ../config/config.h:62:     static int getCurrentDifficulty()      { return currentDifficulty; }
	mov	eax, DWORD PTR _ZN6Config17currentDifficultyE[rip]	#, currentDifficulty
	ret	
	.cfi_endproc
.LFE12792:
	.size	_ZN6Config20getCurrentDifficultyEv, .-_ZN6Config20getCurrentDifficultyEv
	.section	.text._ZN6Config13getLevelStarsEi,"axG",@progbits,_ZN6Config13getLevelStarsEi,comdat
	.p2align 4
	.weak	_ZN6Config13getLevelStarsEi
	.type	_ZN6Config13getLevelStarsEi, @function
_ZN6Config13getLevelStarsEi:
.LFB12793:
	.cfi_startproc
# ../config/config.h:63:     static int getLevelStars(int level)    { return levelStars[level]; }
	movsxd	rdi, edi	# level, level
# ../config/config.h:63:     static int getLevelStars(int level)    { return levelStars[level]; }
	lea	rax, _ZN6Config10levelStarsE[rip]	# tmp101,
	mov	eax, DWORD PTR [rax+rdi*4]	# levelStars[level_2(D)], levelStars[level_2(D)]
# ../config/config.h:63:     static int getLevelStars(int level)    { return levelStars[level]; }
	ret	
	.cfi_endproc
.LFE12793:
	.size	_ZN6Config13getLevelStarsEi, .-_ZN6Config13getLevelStarsEi
	.section	.text._ZN9SaveEntryC2Ev,"axG",@progbits,_ZN9SaveEntryC5Ev,comdat
	.align 2
	.p2align 4
	.weak	_ZN9SaveEntryC2Ev
	.type	_ZN9SaveEntryC2Ev, @function
_ZN9SaveEntryC2Ev:
.LFB13561:
	.cfi_startproc
	push	rbx	#
	.cfi_def_cfa_offset 16
	.cfi_offset 3, -16
# save_manager.h:77: struct SaveEntry {
	mov	rbx, rdi	# this, this
	lea	rdi, 8[rdi]	# _1,
	call	[QWORD PTR _ZNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEEC1Ev@GOTPCREL[rip]]	#
# save_manager.h:77: struct SaveEntry {
	lea	rdi, 40[rbx]	# _2,
# save_manager.h:77: struct SaveEntry {
	pop	rbx	#
	.cfi_def_cfa_offset 8
# save_manager.h:77: struct SaveEntry {
	jmp	[QWORD PTR _ZNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEEC1Ev@GOTPCREL[rip]]	#
	.cfi_endproc
.LFE13561:
	.size	_ZN9SaveEntryC2Ev, .-_ZN9SaveEntryC2Ev
	.weak	_ZN9SaveEntryC1Ev
	.set	_ZN9SaveEntryC1Ev,_ZN9SaveEntryC2Ev
	.section	.text._ZN9SaveEntryD2Ev,"axG",@progbits,_ZN9SaveEntryD5Ev,comdat
	.align 2
	.p2align 4
	.weak	_ZN9SaveEntryD2Ev
	.type	_ZN9SaveEntryD2Ev, @function
_ZN9SaveEntryD2Ev:
.LFB13564:
	.cfi_startproc
	push	rbx	#
	.cfi_def_cfa_offset 16
	.cfi_offset 3, -16
# save_manager.h:77: struct SaveEntry {
	mov	rbx, rdi	# this, this
	lea	rdi, 40[rdi]	# _1,
	call	[QWORD PTR _ZNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEED1Ev@GOTPCREL[rip]]	#
# save_manager.h:77: struct SaveEntry {
	lea	rdi, 8[rbx]	# _2,
# save_manager.h:77: struct SaveEntry {
	pop	rbx	#
	.cfi_def_cfa_offset 8
# save_manager.h:77: struct SaveEntry {
	jmp	[QWORD PTR _ZNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEED1Ev@GOTPCREL[rip]]	#
	.cfi_endproc
.LFE13564:
	.size	_ZN9SaveEntryD2Ev, .-_ZN9SaveEntryD2Ev
	.weak	_ZN9SaveEntryD1Ev
	.set	_ZN9SaveEntryD1Ev,_ZN9SaveEntryD2Ev
	.text
	.align 2
	.p2align 4
	.globl	_ZN11SaveManager22fillControlsFromConfigER13GameSaveState
	.type	_ZN11SaveManager22fillControlsFromConfigER13GameSaveState, @function
_ZN11SaveManager22fillControlsFromConfigER13GameSaveState:
.LFB13574:
	.cfi_startproc
	push	rbx	#
	.cfi_def_cfa_offset 16
	.cfi_offset 3, -16
# save_manager.cpp:360: void SaveManager::fillControlsFromConfig(GameSaveState& state) {
	mov	rbx, rdi	# state, state
# save_manager.cpp:361:     const Config::Controls& c = Config::getControls();
	call	[QWORD PTR _ZN6Config11getControlsEv@GOTPCREL[rip]]	#
	movd	xmm1, DWORD PTR 24[rax]	# tmp119, _19->interact
	movd	xmm3, DWORD PTR 28[rax]	# tmp137, _19->dash
	movd	xmm0, DWORD PTR 16[rax]	# tmp122, _19->right
	movd	xmm4, DWORD PTR 20[rax]	# tmp139, _19->crouch
	punpckldq	xmm1, xmm3	# tmp119, tmp137
# save_manager.cpp:362:     state.attackMouse  = c.attackMouseButton;
	movd	xmm2, DWORD PTR 8[rax]	# tmp126, _19->jump
	movd	xmm5, DWORD PTR 12[rax]	# tmp141, _19->left
	punpckldq	xmm0, xmm4	# tmp122, tmp139
	movd	xmm6, DWORD PTR 40[rax]	# tmp143, _19->magicMouseButton
	punpcklqdq	xmm0, xmm1	# tmp118, tmp119
	movd	xmm1, DWORD PTR 36[rax]	# tmp129, _19->attackMouseButton
	punpckldq	xmm2, xmm5	# tmp126, tmp141
# save_manager.cpp:370:     state.shieldKey    = c.shield;
	mov	eax, DWORD PTR 32[rax]	# _19->shield, _19->shield
# save_manager.cpp:362:     state.attackMouse  = c.attackMouseButton;
	movups	XMMWORD PTR 76[rbx], xmm0	# MEM <vector(4) int> [(int *)state_20(D) + 76B], tmp118
	punpckldq	xmm1, xmm6	# tmp129, tmp143
# save_manager.cpp:370:     state.shieldKey    = c.shield;
	mov	DWORD PTR 92[rbx], eax	# state_20(D)->shieldKey, _19->shield
# save_manager.cpp:362:     state.attackMouse  = c.attackMouseButton;
	punpcklqdq	xmm1, xmm2	# _31, tmp126
	movups	XMMWORD PTR 60[rbx], xmm1	# MEM <vector(4) int> [(int *)state_20(D) + 60B], _31
# save_manager.cpp:371: }
	pop	rbx	#
	.cfi_def_cfa_offset 8
	ret	
	.cfi_endproc
.LFE13574:
	.size	_ZN11SaveManager22fillControlsFromConfigER13GameSaveState, .-_ZN11SaveManager22fillControlsFromConfigER13GameSaveState
	.align 2
	.p2align 4
	.globl	_ZN11SaveManager21applyControlsToConfigERK13GameSaveState
	.type	_ZN11SaveManager21applyControlsToConfigERK13GameSaveState, @function
_ZN11SaveManager21applyControlsToConfigERK13GameSaveState:
.LFB13575:
	.cfi_startproc
	push	rbx	#
	.cfi_def_cfa_offset 16
	.cfi_offset 3, -16
# save_manager.cpp:373: void SaveManager::applyControlsToConfig(const GameSaveState& state) {
	mov	rbx, rdi	# state, state
# save_manager.cpp:374:     Config::Controls& c = Config::getControls();
	call	[QWORD PTR _ZN6Config11getControlsEv@GOTPCREL[rip]]	#
# save_manager.cpp:375:     c.attackMouseButton = state.attackMouse;
	mov	rdx, QWORD PTR 60[rbx]	# MEM <const vector(2) int> [(int *)state_20(D) + 60B], MEM <const vector(2) int> [(int *)state_20(D) + 60B]
# save_manager.cpp:375:     c.attackMouseButton = state.attackMouse;
	mov	QWORD PTR 36[rax], rdx	# MEM <vector(2) int> [(int *)_19 + 36B], MEM <const vector(2) int> [(int *)state_20(D) + 60B]
# save_manager.cpp:381:     c.interact = static_cast<SDL_Scancode>(state.interactKey);
	mov	rdx, QWORD PTR 84[rbx]	# vect__11.532_37, MEM <const vector(2) int> [(int *)state_20(D) + 84B]
# save_manager.cpp:377:     c.jump     = static_cast<SDL_Scancode>(state.jumpKey);
	movdqu	xmm0, XMMWORD PTR 68[rbx]	# vect__3.526_31, MEM <const vector(4) int> [(int *)state_20(D) + 68B]
# save_manager.cpp:381:     c.interact = static_cast<SDL_Scancode>(state.interactKey);
	mov	QWORD PTR 24[rax], rdx	# MEM <vector(2) unsigned int> [(SDL_Scancode *)_19 + 24B], vect__11.532_37
# save_manager.cpp:383:     c.shield   = static_cast<SDL_Scancode>(state.shieldKey);
	mov	edx, DWORD PTR 92[rbx]	# state_20(D)->shieldKey, state_20(D)->shieldKey
# save_manager.cpp:377:     c.jump     = static_cast<SDL_Scancode>(state.jumpKey);
	movups	XMMWORD PTR 8[rax], xmm0	# MEM <vector(4) unsigned int> [(SDL_Scancode *)_19 + 8B], vect__3.526_31
# save_manager.cpp:383:     c.shield   = static_cast<SDL_Scancode>(state.shieldKey);
	mov	DWORD PTR 32[rax], edx	# _19->shield, state_20(D)->shieldKey
# save_manager.cpp:384: }
	pop	rbx	#
	.cfi_def_cfa_offset 8
	ret	
	.cfi_endproc
.LFE13575:
	.size	_ZN11SaveManager21applyControlsToConfigERK13GameSaveState, .-_ZN11SaveManager21applyControlsToConfigERK13GameSaveState
	.align 2
	.p2align 4
	.globl	_ZN11SaveManager21applyProgressToConfigERK13GameSaveState
	.type	_ZN11SaveManager21applyProgressToConfigERK13GameSaveState, @function
_ZN11SaveManager21applyProgressToConfigERK13GameSaveState:
.LFB13576:
	.cfi_startproc
	push	rbp	#
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	mov	rbp, rdi	# state, state
	push	rbx	#
	.cfi_def_cfa_offset 24
	.cfi_offset 3, -24
	xor	ebx, ebx	# ivtmp.546
	sub	rsp, 8	#,
	.cfi_def_cfa_offset 32
.L64:
# save_manager.cpp:388:         Config::setLevelStars(i, state.bestStars[i]);
	mov	esi, DWORD PTR 48[rbp+rbx*4]	# MEM[(int *)state_7(D) + 48B + ivtmp.546_13 * 4], MEM[(int *)state_7(D) + 48B + ivtmp.546_13 * 4]
	mov	edi, ebx	# ivtmp.546, ivtmp.546
# save_manager.cpp:387:     for (int i = 0; i < 3; i++)
	add	rbx, 1	# ivtmp.546,
# save_manager.cpp:388:         Config::setLevelStars(i, state.bestStars[i]);
	call	[QWORD PTR _ZN6Config13setLevelStarsEii@GOTPCREL[rip]]	#
# save_manager.cpp:387:     for (int i = 0; i < 3; i++)
	cmp	rbx, 3	# ivtmp.546,
	jne	.L64	#,
# save_manager.cpp:389:     Config::setCurrentDifficulty(state.difficulty);
	mov	edi, DWORD PTR 96[rbp]	# state_7(D)->difficulty, state_7(D)->difficulty
	call	[QWORD PTR _ZN6Config20setCurrentDifficultyEi@GOTPCREL[rip]]	#
# save_manager.cpp:390:     Config::setSelectedLevel(state.currentLevel);
	mov	edi, DWORD PTR 40[rbp]	# state_7(D)->currentLevel, state_7(D)->currentLevel
# save_manager.cpp:391: }
	add	rsp, 8	#,
	.cfi_def_cfa_offset 24
	pop	rbx	#
	.cfi_def_cfa_offset 16
	pop	rbp	#
	.cfi_def_cfa_offset 8
# save_manager.cpp:390:     Config::setSelectedLevel(state.currentLevel);
	jmp	[QWORD PTR _ZN6Config16setSelectedLevelEi@GOTPCREL[rip]]	#
	.cfi_endproc
.LFE13576:
	.size	_ZN11SaveManager21applyProgressToConfigERK13GameSaveState, .-_ZN11SaveManager21applyProgressToConfigERK13GameSaveState
	.section	.text._ZNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEE12_Alloc_hiderD2Ev,"axG",@progbits,_ZNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEE12_Alloc_hiderD5Ev,comdat
	.align 2
	.p2align 4
	.weak	_ZNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEE12_Alloc_hiderD2Ev
	.type	_ZNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEE12_Alloc_hiderD2Ev, @function
_ZNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEE12_Alloc_hiderD2Ev:
.LFB13723:
	.cfi_startproc
# /usr/include/c++/15.2.1/bits/basic_string.h:197:       struct _Alloc_hider : allocator_type // TODO check __is_final
	ret	
	.cfi_endproc
.LFE13723:
	.size	_ZNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEE12_Alloc_hiderD2Ev, .-_ZNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEE12_Alloc_hiderD2Ev
	.weak	_ZNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEE12_Alloc_hiderD1Ev
	.set	_ZNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEE12_Alloc_hiderD1Ev,_ZNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEE12_Alloc_hiderD2Ev
	.section	.text._ZNSt8__detail18__to_chars_10_implIjEEvPcjT_,"axG",@progbits,_ZNSt8__detail18__to_chars_10_implIjEEvPcjT_,comdat
	.p2align 4
	.weak	_ZNSt8__detail18__to_chars_10_implIjEEvPcjT_
	.type	_ZNSt8__detail18__to_chars_10_implIjEEvPcjT_, @function
_ZNSt8__detail18__to_chars_10_implIjEEvPcjT_:
.LFB13730:
	.cfi_startproc
	sub	rsp, 232	#,
	.cfi_def_cfa_offset 240
# /usr/include/c++/15.2.1/bits/charconv.h:89:       constexpr char __digits[201] =
	movdqa	xmm0, XMMWORD PTR .LC0[rip]	# tmp144,
# /usr/include/c++/15.2.1/bits/charconv.h:83:     __to_chars_10_impl(char* __first, unsigned __len, _Tp __val) noexcept
	mov	rcx, QWORD PTR fs:40	# __val, MEM[(<address-space-1> long unsigned int *)40B]
	mov	QWORD PTR 216[rsp], rcx	# D.189027, __val
	mov	ecx, edx	# __val, __val
# /usr/include/c++/15.2.1/bits/charconv.h:89:       constexpr char __digits[201] =
	movaps	XMMWORD PTR [rsp], xmm0	# __digits, tmp144
	movdqa	xmm0, XMMWORD PTR .LC1[rip]	# tmp145,
	movaps	XMMWORD PTR 16[rsp], xmm0	# __digits, tmp145
	movdqa	xmm0, XMMWORD PTR .LC2[rip]	# tmp146,
	movaps	XMMWORD PTR 32[rsp], xmm0	# __digits, tmp146
	movdqa	xmm0, XMMWORD PTR .LC3[rip]	# tmp147,
	movaps	XMMWORD PTR 48[rsp], xmm0	# __digits, tmp147
	movdqa	xmm0, XMMWORD PTR .LC4[rip]	# tmp148,
	movaps	XMMWORD PTR 64[rsp], xmm0	# __digits, tmp148
	movdqa	xmm0, XMMWORD PTR .LC5[rip]	# tmp149,
	movaps	XMMWORD PTR 80[rsp], xmm0	# __digits, tmp149
	movdqa	xmm0, XMMWORD PTR .LC6[rip]	# tmp150,
	movaps	XMMWORD PTR 96[rsp], xmm0	# __digits, tmp150
	movdqa	xmm0, XMMWORD PTR .LC7[rip]	# tmp151,
	movaps	XMMWORD PTR 112[rsp], xmm0	# __digits, tmp151
	movdqa	xmm0, XMMWORD PTR .LC8[rip]	# tmp152,
	movaps	XMMWORD PTR 128[rsp], xmm0	# __digits, tmp152
	movdqa	xmm0, XMMWORD PTR .LC9[rip]	# tmp153,
	movaps	XMMWORD PTR 144[rsp], xmm0	# __digits, tmp153
	movdqa	xmm0, XMMWORD PTR .LC10[rip]	# tmp154,
	movaps	XMMWORD PTR 160[rsp], xmm0	# __digits, tmp154
	movdqa	xmm0, XMMWORD PTR .LC11[rip]	# tmp155,
	movaps	XMMWORD PTR 176[rsp], xmm0	# __digits, tmp155
	movdqa	xmm0, XMMWORD PTR .LC12[rip]	# tmp156,
	movups	XMMWORD PTR 185[rsp], xmm0	# __digits, tmp156
# /usr/include/c++/15.2.1/bits/charconv.h:96:       while (__val >= 100)
	cmp	edx, 99	# __val,
	jbe	.L69	#,
# /usr/include/c++/15.2.1/bits/charconv.h:95:       unsigned __pos = __len - 1;
	sub	esi, 1	# __pos,
	.p2align 4
	.p2align 3
.L70:
# /usr/include/c++/15.2.1/bits/charconv.h:98: 	  auto const __num = (__val % 100) * 2;
	mov	edx, ecx	# __val, __val
	mov	eax, ecx	# _1, __val
	imul	rdx, rdx, 1374389535	# tmp123, __val,
	shr	rdx, 37	# tmp121,
	imul	r8d, edx, 100	# tmp125, tmp121,
	sub	eax, r8d	# _1, tmp125
	mov	r8d, ecx	# __val, __val
# /usr/include/c++/15.2.1/bits/charconv.h:99: 	  __val /= 100;
	mov	ecx, edx	# __val, tmp121
# /usr/include/c++/15.2.1/bits/charconv.h:100: 	  __first[__pos] = __digits[__num + 1];
	mov	edx, esi	# _3, __pos
# /usr/include/c++/15.2.1/bits/charconv.h:98: 	  auto const __num = (__val % 100) * 2;
	add	eax, eax	#
# /usr/include/c++/15.2.1/bits/charconv.h:100: 	  __first[__pos] = __digits[__num + 1];
	lea	r9d, 1[rax]	# _2,
# /usr/include/c++/15.2.1/bits/charconv.h:101: 	  __first[__pos - 1] = __digits[__num];
	movzx	eax, BYTE PTR [rsp+rax]	# __digits[__num_31], __digits[__num_31]
# /usr/include/c++/15.2.1/bits/charconv.h:100: 	  __first[__pos] = __digits[__num + 1];
	movzx	r9d, BYTE PTR [rsp+r9]	# __digits[_2], __digits[_2]
	mov	BYTE PTR [rdi+rdx], r9b	# *_4, __digits[_2]
# /usr/include/c++/15.2.1/bits/charconv.h:101: 	  __first[__pos - 1] = __digits[__num];
	lea	edx, -1[rsi]	# _7,
# /usr/include/c++/15.2.1/bits/charconv.h:102: 	  __pos -= 2;
	sub	esi, 2	# __pos,
# /usr/include/c++/15.2.1/bits/charconv.h:101: 	  __first[__pos - 1] = __digits[__num];
	mov	BYTE PTR [rdi+rdx], al	# *_8, __digits[__num_31]
# /usr/include/c++/15.2.1/bits/charconv.h:96:       while (__val >= 100)
	cmp	r8d, 9999	# __val,
	ja	.L70	#,
.L69:
# /usr/include/c++/15.2.1/bits/charconv.h:111: 	__first[0] = '0' + __val;
	lea	eax, 48[rcx]	# _12,
# /usr/include/c++/15.2.1/bits/charconv.h:104:       if (__val >= 10)
	cmp	ecx, 9	# __val,
	jbe	.L72	#,
# /usr/include/c++/15.2.1/bits/charconv.h:106: 	  auto const __num = __val * 2;
	add	ecx, ecx	#
# /usr/include/c++/15.2.1/bits/charconv.h:107: 	  __first[1] = __digits[__num + 1];
	lea	eax, 1[rcx]	# _10,
# /usr/include/c++/15.2.1/bits/charconv.h:107: 	  __first[1] = __digits[__num + 1];
	movzx	eax, BYTE PTR [rsp+rax]	# __digits[_10], __digits[_10]
	mov	BYTE PTR 1[rdi], al	# MEM[(char *)__first_25(D) + 1B], __digits[_10]
# /usr/include/c++/15.2.1/bits/charconv.h:108: 	  __first[0] = __digits[__num];
	movzx	eax, BYTE PTR [rsp+rcx]	# _12, __digits[__num_27]
.L72:
	mov	BYTE PTR [rdi], al	# *__first_25(D), _12
# /usr/include/c++/15.2.1/bits/charconv.h:112:     }
	mov	rax, QWORD PTR 216[rsp]	# tmp160, D.189027
	sub	rax, QWORD PTR fs:40	# tmp160, MEM[(<address-space-1> long unsigned int *)40B]
	jne	.L76	#,
	add	rsp, 232	#,
	.cfi_remember_state
	.cfi_def_cfa_offset 8
	ret	
.L76:
	.cfi_restore_state
	call	[QWORD PTR __stack_chk_fail@GOTPCREL[rip]]	#
	.cfi_endproc
.LFE13730:
	.size	_ZNSt8__detail18__to_chars_10_implIjEEvPcjT_, .-_ZNSt8__detail18__to_chars_10_implIjEEvPcjT_
	.section	.text._ZZNSt7__cxx119to_stringEiENKUlPcmE_clES0_m,"axG",@progbits,_ZZNSt7__cxx119to_stringEiENKUlPcmE_clES0_m,comdat
	.align 2
	.p2align 4
	.weak	_ZZNSt7__cxx119to_stringEiENKUlPcmE_clES0_m
	.type	_ZZNSt7__cxx119to_stringEiENKUlPcmE_clES0_m, @function
_ZZNSt7__cxx119to_stringEiENKUlPcmE_clES0_m:
.LFB9067:
	.cfi_startproc
	push	rbx	#
	.cfi_def_cfa_offset 16
	.cfi_offset 3, -16
# /usr/include/c++/15.2.1/bits/basic_string.h:4539:     __str.__resize_and_overwrite(__neg + __len, [=](char* __p, size_t __n) {
	mov	rbx, rdx	# __n, __n
# /usr/include/c++/15.2.1/bits/basic_string.h:4540:       __p[0] = '-';
	mov	BYTE PTR [rsi], 45	# *__p_7(D),
# /usr/include/c++/15.2.1/bits/basic_string.h:4541:       __detail::__to_chars_10_impl(__p + (int)__neg, __len, __uval);
	mov	eax, DWORD PTR 4[rdi]	# __closure_9(D)->____len, __closure_9(D)->____len
# /usr/include/c++/15.2.1/bits/basic_string.h:4541:       __detail::__to_chars_10_impl(__p + (int)__neg, __len, __uval);
	movzx	ecx, BYTE PTR [rdi]	# _4, __closure_9(D)->____neg
# /usr/include/c++/15.2.1/bits/basic_string.h:4541:       __detail::__to_chars_10_impl(__p + (int)__neg, __len, __uval);
	mov	edx, DWORD PTR 8[rdi]	# __closure_9(D)->____uval, __closure_9(D)->____uval
	lea	rdi, [rsi+rcx]	# _5,
	mov	esi, eax	#, __closure_9(D)->____len
	call	_ZNSt8__detail18__to_chars_10_implIjEEvPcjT_	#
# /usr/include/c++/15.2.1/bits/basic_string.h:4543:     });
	mov	rax, rbx	#, __n
	pop	rbx	#
	.cfi_def_cfa_offset 8
	ret	
	.cfi_endproc
.LFE9067:
	.size	_ZZNSt7__cxx119to_stringEiENKUlPcmE_clES0_m, .-_ZZNSt7__cxx119to_stringEiENKUlPcmE_clES0_m
	.section	.text._ZZNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEE22__resize_and_overwriteIZNS_9to_stringEiEUlPcmE_EEvmT_EN11_TerminatorD2Ev,"axG",@progbits,_ZZNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEE22__resize_and_overwriteIZNS_9to_stringEiEUlPcmE_EEvmT_EN11_TerminatorD5Ev,comdat
	.align 2
	.p2align 4
	.weak	_ZZNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEE22__resize_and_overwriteIZNS_9to_stringEiEUlPcmE_EEvmT_EN11_TerminatorD2Ev
	.type	_ZZNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEE22__resize_and_overwriteIZNS_9to_stringEiEUlPcmE_EEvmT_EN11_TerminatorD2Ev, @function
_ZZNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEE22__resize_and_overwriteIZNS_9to_stringEiEUlPcmE_EEvmT_EN11_TerminatorD2Ev:
.LFB13733:
	.cfi_startproc
# /usr/include/c++/15.2.1/bits/basic_string.tcc:628: 	_GLIBCXX20_CONSTEXPR ~_Terminator() { _M_this->_M_set_length(_M_r); }
	mov	rsi, QWORD PTR 8[rdi]	# this_4(D)->_M_r, this_4(D)->_M_r
	mov	rdi, QWORD PTR [rdi]	# this_4(D)->_M_this, this_4(D)->_M_this
	jmp	[QWORD PTR _ZNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEE13_M_set_lengthEm@GOTPCREL[rip]]	#
	.cfi_endproc
.LFE13733:
	.size	_ZZNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEE22__resize_and_overwriteIZNS_9to_stringEiEUlPcmE_EEvmT_EN11_TerminatorD2Ev, .-_ZZNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEE22__resize_and_overwriteIZNS_9to_stringEiEUlPcmE_EEvmT_EN11_TerminatorD2Ev
	.weak	_ZZNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEE22__resize_and_overwriteIZNS_9to_stringEiEUlPcmE_EEvmT_EN11_TerminatorD1Ev
	.set	_ZZNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEE22__resize_and_overwriteIZNS_9to_stringEiEUlPcmE_EEvmT_EN11_TerminatorD1Ev,_ZZNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEE22__resize_and_overwriteIZNS_9to_stringEiEUlPcmE_EEvmT_EN11_TerminatorD2Ev
	.section	.text._ZNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEE22__resize_and_overwriteIZNS_9to_stringEiEUlPcmE_EEvmT_,"axG",@progbits,_ZNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEE22__resize_and_overwriteIZNS_9to_stringEiEUlPcmE_EEvmT_,comdat
	.align 2
	.p2align 4
	.weak	_ZNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEE22__resize_and_overwriteIZNS_9to_stringEiEUlPcmE_EEvmT_
	.type	_ZNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEE22__resize_and_overwriteIZNS_9to_stringEiEUlPcmE_EEvmT_, @function
_ZNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEE22__resize_and_overwriteIZNS_9to_stringEiEUlPcmE_EEvmT_:
.LFB13731:
	.cfi_startproc
	push	rbp	#
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	mov	rbp, rsi	# __n, __n
	push	rbx	#
	.cfi_def_cfa_offset 24
	.cfi_offset 3, -24
	mov	rbx, rdi	# this, this
	sub	rsp, 56	#,
	.cfi_def_cfa_offset 80
# /usr/include/c++/15.2.1/bits/basic_string.tcc:614:     basic_string<_CharT, _Traits, _Alloc>::
	mov	QWORD PTR [rsp], rdx	# __op, __op
	mov	DWORD PTR 8[rsp], ecx	# __op, tmp118
	mov	rax, QWORD PTR fs:40	# tmp109, MEM[(<address-space-1> long unsigned int *)40B]
	mov	QWORD PTR 40[rsp], rax	# D.189037, tmp109
	xor	eax, eax	# tmp109
# /usr/include/c++/15.2.1/bits/basic_string.tcc:621:       reserve(__n);
	call	[QWORD PTR _ZNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEE7reserveEm@GOTPCREL[rip]]	#
# /usr/include/c++/15.2.1/bits/basic_string.tcc:622:       _CharT* const __p = _M_data();
	mov	rdi, rbx	#, this
	call	[QWORD PTR _ZNKSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEE7_M_dataEv@GOTPCREL[rip]]	#
# /usr/include/c++/15.2.1/bits/basic_string.tcc:633:       auto __r = std::move(__op)(__p + 0, __n + 0);
	mov	rdi, rsp	# tmp110,
	mov	rdx, rbp	#, __n
# /usr/include/c++/15.2.1/bits/basic_string.tcc:632:       _Terminator __term{this, 0};
	mov	QWORD PTR 16[rsp], rbx	# __term._M_this, this
# /usr/include/c++/15.2.1/bits/basic_string.tcc:633:       auto __r = std::move(__op)(__p + 0, __n + 0);
	mov	rsi, rax	#, __p
	call	_ZZNSt7__cxx119to_stringEiENKUlPcmE_clES0_m	#
# /usr/include/c++/15.2.1/bits/basic_string.tcc:644:     }
	lea	rdi, 16[rsp]	# tmp111,
# /usr/include/c++/15.2.1/bits/basic_string.tcc:641:       __term._M_r = size_type(__r);
	mov	QWORD PTR 24[rsp], rax	# __term._M_r, __r
# /usr/include/c++/15.2.1/bits/basic_string.tcc:644:     }
	call	_ZZNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEE22__resize_and_overwriteIZNS_9to_stringEiEUlPcmE_EEvmT_EN11_TerminatorD1Ev	#
	mov	rax, QWORD PTR 40[rsp]	# tmp121, D.189037
	sub	rax, QWORD PTR fs:40	# tmp121, MEM[(<address-space-1> long unsigned int *)40B]
	jne	.L83	#,
	add	rsp, 56	#,
	.cfi_remember_state
	.cfi_def_cfa_offset 24
	pop	rbx	#
	.cfi_def_cfa_offset 16
	pop	rbp	#
	.cfi_def_cfa_offset 8
	ret	
.L83:
	.cfi_restore_state
	call	[QWORD PTR __stack_chk_fail@GOTPCREL[rip]]	#
	.cfi_endproc
.LFE13731:
	.size	_ZNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEE22__resize_and_overwriteIZNS_9to_stringEiEUlPcmE_EEvmT_, .-_ZNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEE22__resize_and_overwriteIZNS_9to_stringEiEUlPcmE_EEvmT_
	.section	.text._ZNSt7__cxx119to_stringEi,"axG",@progbits,_ZNSt7__cxx119to_stringEi,comdat
	.p2align 4
	.weak	_ZNSt7__cxx119to_stringEi
	.type	_ZNSt7__cxx119to_stringEi, @function
_ZNSt7__cxx119to_stringEi:
.LFB9064:
	.cfi_startproc
	.cfi_personality 0x9b,DW.ref.__gxx_personality_v0
	.cfi_lsda 0x1b,.LLSDA9064
	push	r13	#
	.cfi_def_cfa_offset 16
	.cfi_offset 13, -16
# /usr/include/c++/15.2.1/bits/basic_string.h:4535:     const bool __neg = __val < 0;
	mov	r13d, esi	# tmp106, __val
# /usr/include/c++/15.2.1/bits/basic_string.h:4534:   {
	push	r12	#
	.cfi_def_cfa_offset 24
	.cfi_offset 12, -24
# /usr/include/c++/15.2.1/bits/basic_string.h:4535:     const bool __neg = __val < 0;
	shr	r13d, 31	# tmp106,
# /usr/include/c++/15.2.1/bits/basic_string.h:4534:   {
	push	rbp	#
	.cfi_def_cfa_offset 32
	.cfi_offset 6, -32
	mov	rbp, rdi	# <retval>, .result_ptr
	push	rbx	#
	.cfi_def_cfa_offset 40
	.cfi_offset 3, -40
# /usr/include/c++/15.2.1/bits/basic_string.h:4536:     const unsigned __uval = __neg ? (unsigned)~__val + 1u : __val;
	mov	ebx, esi	# tmp117, __val
# /usr/include/c++/15.2.1/bits/basic_string.h:4534:   {
	sub	rsp, 24	#,
	.cfi_def_cfa_offset 64
# /usr/include/c++/15.2.1/bits/basic_string.h:4536:     const unsigned __uval = __neg ? (unsigned)~__val + 1u : __val;
	neg	ebx	# tmp117
	cmovs	ebx, esi	# tmp117,, _21, __val
# /usr/include/c++/15.2.1/bits/basic_string.h:4537:     const auto __len = __detail::__to_chars_len(__uval);
	mov	esi, 10	#,
	mov	edi, ebx	#, _21
# /usr/include/c++/15.2.1/bits/basic_string.h:4539:     __str.__resize_and_overwrite(__neg + __len, [=](char* __p, size_t __n) {
	mov	ebx, ebx	# D.84469, _21
# /usr/include/c++/15.2.1/bits/basic_string.h:4537:     const auto __len = __detail::__to_chars_len(__uval);
	call	_ZNSt8__detail14__to_chars_lenIjEEjT_i	#
# /usr/include/c++/15.2.1/bits/basic_string.h:4538:     string __str;
	mov	rdi, rbp	#, <retval>
# /usr/include/c++/15.2.1/bits/basic_string.h:4537:     const auto __len = __detail::__to_chars_len(__uval);
	mov	r12d, eax	# __len,
# /usr/include/c++/15.2.1/bits/basic_string.h:4538:     string __str;
	call	[QWORD PTR _ZNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEEC1Ev@GOTPCREL[rip]]	#
# /usr/include/c++/15.2.1/bits/basic_string.h:4539:     __str.__resize_and_overwrite(__neg + __len, [=](char* __p, size_t __n) {
	mov	BYTE PTR [rsp], r13b	# D.84469.____neg, tmp106
	mov	rcx, rbx	#, D.84469
	mov	rdi, rbp	#, <retval>
	mov	DWORD PTR 4[rsp], r12d	# D.84469.____len, __len
	mov	rax, QWORD PTR [rsp]	# D.84469, D.84469
	lea	esi, 0[r13+r12]	# _4,
	mov	rdx, rax	#, D.84469
	call	_ZNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEE22__resize_and_overwriteIZNS_9to_stringEiEUlPcmE_EEvmT_	#
# /usr/include/c++/15.2.1/bits/basic_string.h:4545:   }
	add	rsp, 24	#,
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
	.cfi_endproc
.LFE9064:
	.section	.gcc_except_table._ZNSt7__cxx119to_stringEi,"aG",@progbits,_ZNSt7__cxx119to_stringEi,comdat
.LLSDA9064:
	.byte	0xff
	.byte	0xff
	.byte	0x1
	.uleb128 .LLSDACSE9064-.LLSDACSB9064
.LLSDACSB9064:
.LLSDACSE9064:
	.section	.text._ZNSt7__cxx119to_stringEi,"axG",@progbits,_ZNSt7__cxx119to_stringEi,comdat
	.size	_ZNSt7__cxx119to_stringEi, .-_ZNSt7__cxx119to_stringEi
	.section	.text._ZSt3maxImERKT_S2_S2_,"axG",@progbits,_ZSt3maxImERKT_S2_S2_,comdat
	.p2align 4
	.weak	_ZSt3maxImERKT_S2_S2_
	.type	_ZSt3maxImERKT_S2_S2_, @function
_ZSt3maxImERKT_S2_S2_:
.LFB13919:
	.cfi_startproc
# /usr/include/c++/15.2.1/bits/stl_algobase.h:265:       return __a;
	mov	rax, QWORD PTR [rsi]	# tmp108, *__b_6(D)
	cmp	QWORD PTR [rdi], rax	# *__a_5(D), tmp108
	mov	rax, rdi	# __a, __a
	cmovb	rax, rsi	# __b,, __a
# /usr/include/c++/15.2.1/bits/stl_algobase.h:266:     }
	ret	
	.cfi_endproc
.LFE13919:
	.size	_ZSt3maxImERKT_S2_S2_, .-_ZSt3maxImERKT_S2_S2_
	.section	.text._ZStplIcSt11char_traitsIcESaIcEENSt7__cxx1112basic_stringIT_T0_T1_EEOS8_PKS5_,"axG",@progbits,_ZStplIcSt11char_traitsIcESaIcEENSt7__cxx1112basic_stringIT_T0_T1_EEOS8_PKS5_,comdat
	.p2align 4
	.weak	_ZStplIcSt11char_traitsIcESaIcEENSt7__cxx1112basic_stringIT_T0_T1_EEOS8_PKS5_
	.type	_ZStplIcSt11char_traitsIcESaIcEENSt7__cxx1112basic_stringIT_T0_T1_EEOS8_PKS5_, @function
_ZStplIcSt11char_traitsIcESaIcEENSt7__cxx1112basic_stringIT_T0_T1_EEOS8_PKS5_:
.LFB14042:
	.cfi_startproc
	push	rbx	#
	.cfi_def_cfa_offset 16
	.cfi_offset 3, -16
# /usr/include/c++/15.2.1/bits/basic_string.h:3975:     operator+(basic_string<_CharT, _Traits, _Alloc>&& __lhs,
	mov	rbx, rdi	# <retval>, .result_ptr
	mov	rdi, rsi	# __lhs, __lhs
# /usr/include/c++/15.2.1/bits/basic_string.h:3977:     { return std::move(__lhs.append(__rhs)); }
	mov	rsi, rdx	#, __rhs
	call	[QWORD PTR _ZNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEE6appendEPKc@GOTPCREL[rip]]	#
# /usr/include/c++/15.2.1/bits/basic_string.h:3977:     { return std::move(__lhs.append(__rhs)); }
	mov	rdi, rbx	#, <retval>
	mov	rsi, rax	#, _5
	call	[QWORD PTR _ZNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEEC1EOS4_@GOTPCREL[rip]]	#
# /usr/include/c++/15.2.1/bits/basic_string.h:3977:     { return std::move(__lhs.append(__rhs)); }
	mov	rax, rbx	#, <retval>
	pop	rbx	#
	.cfi_def_cfa_offset 8
	ret	
	.cfi_endproc
.LFE14042:
	.size	_ZStplIcSt11char_traitsIcESaIcEENSt7__cxx1112basic_stringIT_T0_T1_EEOS8_PKS5_, .-_ZStplIcSt11char_traitsIcESaIcEENSt7__cxx1112basic_stringIT_T0_T1_EEOS8_PKS5_
	.section	.text._ZStplIcSt11char_traitsIcESaIcEENSt7__cxx1112basic_stringIT_T0_T1_EEOS8_S9_,"axG",@progbits,_ZStplIcSt11char_traitsIcESaIcEENSt7__cxx1112basic_stringIT_T0_T1_EEOS8_S9_,comdat
	.p2align 4
	.weak	_ZStplIcSt11char_traitsIcESaIcEENSt7__cxx1112basic_stringIT_T0_T1_EEOS8_S9_
	.type	_ZStplIcSt11char_traitsIcESaIcEENSt7__cxx1112basic_stringIT_T0_T1_EEOS8_S9_, @function
_ZStplIcSt11char_traitsIcESaIcEENSt7__cxx1112basic_stringIT_T0_T1_EEOS8_S9_:
.LFB14043:
	.cfi_startproc
	push	r13	#
	.cfi_def_cfa_offset 16
	.cfi_offset 13, -16
	mov	r13, rdi	# <retval>, .result_ptr
# /usr/include/c++/15.2.1/bits/basic_string.h:3951: 	  const auto __size = __lhs.size() + __rhs.size();
	mov	rdi, rsi	#, __lhs
# /usr/include/c++/15.2.1/bits/basic_string.h:3938:     operator+(basic_string<_CharT, _Traits, _Alloc>&& __lhs,
	push	r12	#
	.cfi_def_cfa_offset 24
	.cfi_offset 12, -24
	mov	r12, rdx	# __rhs, __rhs
	push	rbp	#
	.cfi_def_cfa_offset 32
	.cfi_offset 6, -32
	mov	rbp, rsi	# __lhs, __lhs
	push	rbx	#
	.cfi_def_cfa_offset 40
	.cfi_offset 3, -40
	sub	rsp, 8	#,
	.cfi_def_cfa_offset 48
# /usr/include/c++/15.2.1/bits/basic_string.h:3951: 	  const auto __size = __lhs.size() + __rhs.size();
	call	[QWORD PTR _ZNKSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEE4sizeEv@GOTPCREL[rip]]	#
# /usr/include/c++/15.2.1/bits/basic_string.h:3951: 	  const auto __size = __lhs.size() + __rhs.size();
	mov	rdi, r12	#, __rhs
# /usr/include/c++/15.2.1/bits/basic_string.h:3951: 	  const auto __size = __lhs.size() + __rhs.size();
	mov	rbx, rax	# _1,
# /usr/include/c++/15.2.1/bits/basic_string.h:3951: 	  const auto __size = __lhs.size() + __rhs.size();
	call	[QWORD PTR _ZNKSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEE4sizeEv@GOTPCREL[rip]]	#
# /usr/include/c++/15.2.1/bits/basic_string.h:3952: 	  if (__size > __lhs.capacity() && __size <= __rhs.capacity())
	mov	rdi, rbp	#, __lhs
# /usr/include/c++/15.2.1/bits/basic_string.h:3951: 	  const auto __size = __lhs.size() + __rhs.size();
	add	rbx, rax	# __size, _2
# /usr/include/c++/15.2.1/bits/basic_string.h:3952: 	  if (__size > __lhs.capacity() && __size <= __rhs.capacity())
	call	[QWORD PTR _ZNKSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEE8capacityEv@GOTPCREL[rip]]	#
# /usr/include/c++/15.2.1/bits/basic_string.h:3952: 	  if (__size > __lhs.capacity() && __size <= __rhs.capacity())
	cmp	rax, rbx	# _3, __size
	jnb	.L92	#,
# /usr/include/c++/15.2.1/bits/basic_string.h:3952: 	  if (__size > __lhs.capacity() && __size <= __rhs.capacity())
	mov	rdi, r12	#, __rhs
	call	[QWORD PTR _ZNKSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEE8capacityEv@GOTPCREL[rip]]	#
# /usr/include/c++/15.2.1/bits/basic_string.h:3952: 	  if (__size > __lhs.capacity() && __size <= __rhs.capacity())
	cmp	rax, rbx	# _4, __size
	jnb	.L95	#,
.L92:
# /usr/include/c++/15.2.1/bits/basic_string.h:3955:       return std::move(__lhs.append(__rhs));
	mov	rsi, r12	#, __rhs
	mov	rdi, rbp	#, __lhs
	call	[QWORD PTR _ZNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEE6appendERKS4_@GOTPCREL[rip]]	#
# /usr/include/c++/15.2.1/bits/basic_string.h:3955:       return std::move(__lhs.append(__rhs));
	mov	rdi, r13	#, <retval>
	mov	rsi, rax	#, _15
	call	[QWORD PTR _ZNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEEC1EOS4_@GOTPCREL[rip]]	#
# /usr/include/c++/15.2.1/bits/basic_string.h:3956:     }
	add	rsp, 8	#,
	.cfi_remember_state
	.cfi_def_cfa_offset 40
	mov	rax, r13	#, <retval>
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
.L95:
	.cfi_restore_state
# /usr/include/c++/15.2.1/bits/basic_string.h:3953: 	    return std::move(__rhs.insert(0, __lhs));
	mov	rdx, rbp	#, __lhs
	mov	rdi, r12	#, __rhs
	xor	esi, esi	#
	call	[QWORD PTR _ZNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEE6insertEmRKS4_@GOTPCREL[rip]]	#
# /usr/include/c++/15.2.1/bits/basic_string.h:3953: 	    return std::move(__rhs.insert(0, __lhs));
	mov	rdi, r13	#, <retval>
	mov	rsi, rax	#, _11
	call	[QWORD PTR _ZNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEEC1EOS4_@GOTPCREL[rip]]	#
# /usr/include/c++/15.2.1/bits/basic_string.h:3956:     }
	add	rsp, 8	#,
	.cfi_def_cfa_offset 40
	mov	rax, r13	#, <retval>
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
.LFE14043:
	.size	_ZStplIcSt11char_traitsIcESaIcEENSt7__cxx1112basic_stringIT_T0_T1_EEOS8_S9_, .-_ZStplIcSt11char_traitsIcESaIcEENSt7__cxx1112basic_stringIT_T0_T1_EEOS8_S9_
	.section	.text._ZStplIcSt11char_traitsIcESaIcEENSt7__cxx1112basic_stringIT_T0_T1_EEOS8_RKS8_,"axG",@progbits,_ZStplIcSt11char_traitsIcESaIcEENSt7__cxx1112basic_stringIT_T0_T1_EEOS8_RKS8_,comdat
	.p2align 4
	.weak	_ZStplIcSt11char_traitsIcESaIcEENSt7__cxx1112basic_stringIT_T0_T1_EEOS8_RKS8_
	.type	_ZStplIcSt11char_traitsIcESaIcEENSt7__cxx1112basic_stringIT_T0_T1_EEOS8_RKS8_, @function
_ZStplIcSt11char_traitsIcESaIcEENSt7__cxx1112basic_stringIT_T0_T1_EEOS8_RKS8_:
.LFB14044:
	.cfi_startproc
	push	rbx	#
	.cfi_def_cfa_offset 16
	.cfi_offset 3, -16
# /usr/include/c++/15.2.1/bits/basic_string.h:3924:     operator+(basic_string<_CharT, _Traits, _Alloc>&& __lhs,
	mov	rbx, rdi	# <retval>, .result_ptr
	mov	rdi, rsi	# __lhs, __lhs
# /usr/include/c++/15.2.1/bits/basic_string.h:3926:     { return std::move(__lhs.append(__rhs)); }
	mov	rsi, rdx	#, __rhs
	call	[QWORD PTR _ZNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEE6appendERKS4_@GOTPCREL[rip]]	#
# /usr/include/c++/15.2.1/bits/basic_string.h:3926:     { return std::move(__lhs.append(__rhs)); }
	mov	rdi, rbx	#, <retval>
	mov	rsi, rax	#, _5
	call	[QWORD PTR _ZNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEEC1EOS4_@GOTPCREL[rip]]	#
# /usr/include/c++/15.2.1/bits/basic_string.h:3926:     { return std::move(__lhs.append(__rhs)); }
	mov	rax, rbx	#, <retval>
	pop	rbx	#
	.cfi_def_cfa_offset 8
	ret	
	.cfi_endproc
.LFE14044:
	.size	_ZStplIcSt11char_traitsIcESaIcEENSt7__cxx1112basic_stringIT_T0_T1_EEOS8_RKS8_, .-_ZStplIcSt11char_traitsIcESaIcEENSt7__cxx1112basic_stringIT_T0_T1_EEOS8_RKS8_
	.section	.rodata.str1.1,"aMS",@progbits,1
.LC13:
	.string	"autosave.txt"
	.section	.rodata.str1.8,"aMS",@progbits,1
	.align 8
.LC14:
	.base64	"W1NhdmVNYW5hZ2VyXSDQndC1INC80L7Qs9GDINC+0YLQutGA0YvRgtGMIAA="
	.section	.rodata.str1.1
.LC15:
	.string	"\n"
.LC16:
	.string	"player_x "
.LC17:
	.string	"player_y "
.LC18:
	.string	"player_facing "
.LC19:
	.string	"player_hp "
.LC20:
	.string	"boss_x "
.LC21:
	.string	"boss_y "
.LC22:
	.string	"boss_facing "
.LC23:
	.string	"boss_hp "
.LC24:
	.string	"boss_phase "
.LC25:
	.string	"level_timer "
.LC26:
	.string	"current_level "
.LC27:
	.string	"lives_left "
.LC28:
	.string	"best_stars_0 "
.LC29:
	.string	"best_stars_1 "
.LC30:
	.string	"best_stars_2 "
.LC31:
	.string	"difficulty "
	.section	.text.unlikely,"ax",@progbits
	.align 2
.LCOLDB32:
	.text
.LHOTB32:
	.align 2
	.p2align 4
	.globl	_ZN11SaveManager17writeAutosaveFileERK13GameSaveState
	.type	_ZN11SaveManager17writeAutosaveFileERK13GameSaveState, @function
_ZN11SaveManager17writeAutosaveFileERK13GameSaveState:
.LFB13552:
	.cfi_startproc
	.cfi_personality 0x9b,DW.ref.__gxx_personality_v0
	.cfi_lsda 0x1b,.LLSDA13552
	push	rbp	#
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
# save_manager.cpp:65:     std::ofstream f(AUTOSAVE_FILE);
	mov	edx, 16	#,
# save_manager.cpp:64: void SaveManager::writeAutosaveFile(const GameSaveState& state) {
	push	rbx	#
	.cfi_def_cfa_offset 24
	.cfi_offset 3, -24
	sub	rsp, 536	#,
	.cfi_def_cfa_offset 560
# save_manager.cpp:64: void SaveManager::writeAutosaveFile(const GameSaveState& state) {
	mov	rbp, QWORD PTR fs:40	# state, MEM[(<address-space-1> long unsigned int *)40B]
	mov	QWORD PTR 520[rsp], rbp	# D.189112, state
	mov	rbp, rsi	# state, state
# save_manager.cpp:65:     std::ofstream f(AUTOSAVE_FILE);
	mov	rdi, rsp	#,
	lea	rsi, .LC13[rip]	#,
.LEHB0:
	call	[QWORD PTR _ZNSt14basic_ofstreamIcSt11char_traitsIcEEC1EPKcSt13_Ios_Openmode@GOTPCREL[rip]]	#
.LEHE0:
# save_manager.cpp:66:     if (!f.is_open()) {
	mov	rdi, rsp	#,
	call	[QWORD PTR _ZNSt14basic_ofstreamIcSt11char_traitsIcEE7is_openEv@GOTPCREL[rip]]	#
# save_manager.cpp:66:     if (!f.is_open()) {
	test	al, al	# _1
	je	.L109	#,
# save_manager.cpp:72:     f << "player_x "      << state.player.x           << "\n";
	lea	rsi, .LC16[rip]	#,
	mov	rdi, rsp	#,
.LEHB1:
	call	[QWORD PTR _ZStlsISt11char_traitsIcEERSt13basic_ostreamIcT_ES5_PKc@GOTPCREL[rip]]	#
# save_manager.cpp:72:     f << "player_x "      << state.player.x           << "\n";
	movss	xmm0, DWORD PTR 0[rbp]	# state_26(D)->player.x, state_26(D)->player.x
	mov	rdi, rax	#, _25
	call	[QWORD PTR _ZNSolsEf@GOTPCREL[rip]]	#
# save_manager.cpp:72:     f << "player_x "      << state.player.x           << "\n";
	lea	rsi, .LC15[rip]	#,
	mov	rdi, rax	#, _28
	call	[QWORD PTR _ZStlsISt11char_traitsIcEERSt13basic_ostreamIcT_ES5_PKc@GOTPCREL[rip]]	#
# save_manager.cpp:73:     f << "player_y "      << state.player.y           << "\n";
	lea	rsi, .LC17[rip]	#,
	mov	rdi, rsp	#,
	call	[QWORD PTR _ZStlsISt11char_traitsIcEERSt13basic_ostreamIcT_ES5_PKc@GOTPCREL[rip]]	#
# save_manager.cpp:73:     f << "player_y "      << state.player.y           << "\n";
	movss	xmm0, DWORD PTR 4[rbp]	# state_26(D)->player.y, state_26(D)->player.y
	mov	rdi, rax	#, _31
	call	[QWORD PTR _ZNSolsEf@GOTPCREL[rip]]	#
# save_manager.cpp:73:     f << "player_y "      << state.player.y           << "\n";
	lea	rsi, .LC15[rip]	#,
	mov	rdi, rax	#, _33
	call	[QWORD PTR _ZStlsISt11char_traitsIcEERSt13basic_ostreamIcT_ES5_PKc@GOTPCREL[rip]]	#
# save_manager.cpp:74:     f << "player_facing " << (state.player.facingRight ? 1 : 0) << "\n";
	lea	rsi, .LC18[rip]	#,
	mov	rdi, rsp	#,
	call	[QWORD PTR _ZStlsISt11char_traitsIcEERSt13basic_ostreamIcT_ES5_PKc@GOTPCREL[rip]]	#
# save_manager.cpp:74:     f << "player_facing " << (state.player.facingRight ? 1 : 0) << "\n";
	movzx	esi, BYTE PTR 8[rbp]	# _116, state_26(D)->player.facingRight
# save_manager.cpp:74:     f << "player_facing " << (state.player.facingRight ? 1 : 0) << "\n";
	mov	rdi, rax	#, _36
	call	[QWORD PTR _ZNSolsEi@GOTPCREL[rip]]	#
# save_manager.cpp:74:     f << "player_facing " << (state.player.facingRight ? 1 : 0) << "\n";
	lea	rsi, .LC15[rip]	#,
	mov	rdi, rax	#, _38
	call	[QWORD PTR _ZStlsISt11char_traitsIcEERSt13basic_ostreamIcT_ES5_PKc@GOTPCREL[rip]]	#
# save_manager.cpp:75:     f << "player_hp "     << state.player.hp          << "\n";
	lea	rsi, .LC19[rip]	#,
	mov	rdi, rsp	#,
	call	[QWORD PTR _ZStlsISt11char_traitsIcEERSt13basic_ostreamIcT_ES5_PKc@GOTPCREL[rip]]	#
# save_manager.cpp:75:     f << "player_hp "     << state.player.hp          << "\n";
	movss	xmm0, DWORD PTR 12[rbp]	# state_26(D)->player.hp, state_26(D)->player.hp
	mov	rdi, rax	#, _41
	call	[QWORD PTR _ZNSolsEf@GOTPCREL[rip]]	#
# save_manager.cpp:75:     f << "player_hp "     << state.player.hp          << "\n";
	lea	rsi, .LC15[rip]	#,
	mov	rdi, rax	#, _43
	call	[QWORD PTR _ZStlsISt11char_traitsIcEERSt13basic_ostreamIcT_ES5_PKc@GOTPCREL[rip]]	#
# save_manager.cpp:76:     f << "boss_x "        << state.boss.x             << "\n";
	lea	rsi, .LC20[rip]	#,
	mov	rdi, rsp	#,
	call	[QWORD PTR _ZStlsISt11char_traitsIcEERSt13basic_ostreamIcT_ES5_PKc@GOTPCREL[rip]]	#
# save_manager.cpp:76:     f << "boss_x "        << state.boss.x             << "\n";
	movss	xmm0, DWORD PTR 16[rbp]	# state_26(D)->boss.x, state_26(D)->boss.x
	mov	rdi, rax	#, _46
	call	[QWORD PTR _ZNSolsEf@GOTPCREL[rip]]	#
# save_manager.cpp:76:     f << "boss_x "        << state.boss.x             << "\n";
	lea	rsi, .LC15[rip]	#,
	mov	rdi, rax	#, _48
	call	[QWORD PTR _ZStlsISt11char_traitsIcEERSt13basic_ostreamIcT_ES5_PKc@GOTPCREL[rip]]	#
# save_manager.cpp:77:     f << "boss_y "        << state.boss.y             << "\n";
	lea	rsi, .LC21[rip]	#,
	mov	rdi, rsp	#,
	call	[QWORD PTR _ZStlsISt11char_traitsIcEERSt13basic_ostreamIcT_ES5_PKc@GOTPCREL[rip]]	#
# save_manager.cpp:77:     f << "boss_y "        << state.boss.y             << "\n";
	movss	xmm0, DWORD PTR 20[rbp]	# state_26(D)->boss.y, state_26(D)->boss.y
	mov	rdi, rax	#, _51
	call	[QWORD PTR _ZNSolsEf@GOTPCREL[rip]]	#
# save_manager.cpp:77:     f << "boss_y "        << state.boss.y             << "\n";
	lea	rsi, .LC15[rip]	#,
	mov	rdi, rax	#, _53
	call	[QWORD PTR _ZStlsISt11char_traitsIcEERSt13basic_ostreamIcT_ES5_PKc@GOTPCREL[rip]]	#
# save_manager.cpp:78:     f << "boss_facing "   << (state.boss.facingRight ? 1 : 0) << "\n";
	lea	rsi, .LC22[rip]	#,
	mov	rdi, rsp	#,
	call	[QWORD PTR _ZStlsISt11char_traitsIcEERSt13basic_ostreamIcT_ES5_PKc@GOTPCREL[rip]]	#
# save_manager.cpp:78:     f << "boss_facing "   << (state.boss.facingRight ? 1 : 0) << "\n";
	movzx	esi, BYTE PTR 24[rbp]	# _115, state_26(D)->boss.facingRight
# save_manager.cpp:78:     f << "boss_facing "   << (state.boss.facingRight ? 1 : 0) << "\n";
	mov	rdi, rax	#, _56
	call	[QWORD PTR _ZNSolsEi@GOTPCREL[rip]]	#
# save_manager.cpp:78:     f << "boss_facing "   << (state.boss.facingRight ? 1 : 0) << "\n";
	lea	rsi, .LC15[rip]	#,
	mov	rdi, rax	#, _58
	call	[QWORD PTR _ZStlsISt11char_traitsIcEERSt13basic_ostreamIcT_ES5_PKc@GOTPCREL[rip]]	#
# save_manager.cpp:79:     f << "boss_hp "       << state.boss.hp            << "\n";
	lea	rsi, .LC23[rip]	#,
	mov	rdi, rsp	#,
	call	[QWORD PTR _ZStlsISt11char_traitsIcEERSt13basic_ostreamIcT_ES5_PKc@GOTPCREL[rip]]	#
# save_manager.cpp:79:     f << "boss_hp "       << state.boss.hp            << "\n";
	movss	xmm0, DWORD PTR 28[rbp]	# state_26(D)->boss.hp, state_26(D)->boss.hp
	mov	rdi, rax	#, _61
	call	[QWORD PTR _ZNSolsEf@GOTPCREL[rip]]	#
# save_manager.cpp:79:     f << "boss_hp "       << state.boss.hp            << "\n";
	lea	rsi, .LC15[rip]	#,
	mov	rdi, rax	#, _63
	call	[QWORD PTR _ZStlsISt11char_traitsIcEERSt13basic_ostreamIcT_ES5_PKc@GOTPCREL[rip]]	#
# save_manager.cpp:80:     f << "boss_phase "    << state.bossPhase          << "\n";
	lea	rsi, .LC24[rip]	#,
	mov	rdi, rsp	#,
	call	[QWORD PTR _ZStlsISt11char_traitsIcEERSt13basic_ostreamIcT_ES5_PKc@GOTPCREL[rip]]	#
# save_manager.cpp:80:     f << "boss_phase "    << state.bossPhase          << "\n";
	mov	esi, DWORD PTR 32[rbp]	# state_26(D)->bossPhase, state_26(D)->bossPhase
	mov	rdi, rax	#, _66
	call	[QWORD PTR _ZNSolsEi@GOTPCREL[rip]]	#
# save_manager.cpp:80:     f << "boss_phase "    << state.bossPhase          << "\n";
	lea	rsi, .LC15[rip]	#,
	mov	rdi, rax	#, _68
	call	[QWORD PTR _ZStlsISt11char_traitsIcEERSt13basic_ostreamIcT_ES5_PKc@GOTPCREL[rip]]	#
# save_manager.cpp:83:     f << "level_timer "   << state.levelTimer         << "\n";
	lea	rsi, .LC25[rip]	#,
	mov	rdi, rsp	#,
	call	[QWORD PTR _ZStlsISt11char_traitsIcEERSt13basic_ostreamIcT_ES5_PKc@GOTPCREL[rip]]	#
# save_manager.cpp:83:     f << "level_timer "   << state.levelTimer         << "\n";
	movss	xmm0, DWORD PTR 36[rbp]	# state_26(D)->levelTimer, state_26(D)->levelTimer
	mov	rdi, rax	#, _71
	call	[QWORD PTR _ZNSolsEf@GOTPCREL[rip]]	#
# save_manager.cpp:83:     f << "level_timer "   << state.levelTimer         << "\n";
	lea	rsi, .LC15[rip]	#,
	mov	rdi, rax	#, _73
	call	[QWORD PTR _ZStlsISt11char_traitsIcEERSt13basic_ostreamIcT_ES5_PKc@GOTPCREL[rip]]	#
# save_manager.cpp:84:     f << "current_level " << state.currentLevel       << "\n";
	lea	rsi, .LC26[rip]	#,
	mov	rdi, rsp	#,
	call	[QWORD PTR _ZStlsISt11char_traitsIcEERSt13basic_ostreamIcT_ES5_PKc@GOTPCREL[rip]]	#
# save_manager.cpp:84:     f << "current_level " << state.currentLevel       << "\n";
	mov	esi, DWORD PTR 40[rbp]	# state_26(D)->currentLevel, state_26(D)->currentLevel
	mov	rdi, rax	#, _76
	call	[QWORD PTR _ZNSolsEi@GOTPCREL[rip]]	#
# save_manager.cpp:84:     f << "current_level " << state.currentLevel       << "\n";
	lea	rsi, .LC15[rip]	#,
	mov	rdi, rax	#, _78
	call	[QWORD PTR _ZStlsISt11char_traitsIcEERSt13basic_ostreamIcT_ES5_PKc@GOTPCREL[rip]]	#
# save_manager.cpp:85:     f << "lives_left "    << state.livesLeft          << "\n";
	lea	rsi, .LC27[rip]	#,
	mov	rdi, rsp	#,
	call	[QWORD PTR _ZStlsISt11char_traitsIcEERSt13basic_ostreamIcT_ES5_PKc@GOTPCREL[rip]]	#
# save_manager.cpp:85:     f << "lives_left "    << state.livesLeft          << "\n";
	mov	esi, DWORD PTR 44[rbp]	# state_26(D)->livesLeft, state_26(D)->livesLeft
	mov	rdi, rax	#, _81
	call	[QWORD PTR _ZNSolsEi@GOTPCREL[rip]]	#
# save_manager.cpp:85:     f << "lives_left "    << state.livesLeft          << "\n";
	lea	rsi, .LC15[rip]	#,
	mov	rdi, rax	#, _83
	call	[QWORD PTR _ZStlsISt11char_traitsIcEERSt13basic_ostreamIcT_ES5_PKc@GOTPCREL[rip]]	#
# save_manager.cpp:86:     f << "best_stars_0 "  << state.bestStars[0]       << "\n";
	lea	rsi, .LC28[rip]	#,
	mov	rdi, rsp	#,
	call	[QWORD PTR _ZStlsISt11char_traitsIcEERSt13basic_ostreamIcT_ES5_PKc@GOTPCREL[rip]]	#
# save_manager.cpp:86:     f << "best_stars_0 "  << state.bestStars[0]       << "\n";
	mov	esi, DWORD PTR 48[rbp]	# state_26(D)->bestStars[0], state_26(D)->bestStars[0]
	mov	rdi, rax	#, _86
	call	[QWORD PTR _ZNSolsEi@GOTPCREL[rip]]	#
# save_manager.cpp:86:     f << "best_stars_0 "  << state.bestStars[0]       << "\n";
	lea	rsi, .LC15[rip]	#,
	mov	rdi, rax	#, _88
	call	[QWORD PTR _ZStlsISt11char_traitsIcEERSt13basic_ostreamIcT_ES5_PKc@GOTPCREL[rip]]	#
# save_manager.cpp:87:     f << "best_stars_1 "  << state.bestStars[1]       << "\n";
	lea	rsi, .LC29[rip]	#,
	mov	rdi, rsp	#,
	call	[QWORD PTR _ZStlsISt11char_traitsIcEERSt13basic_ostreamIcT_ES5_PKc@GOTPCREL[rip]]	#
# save_manager.cpp:87:     f << "best_stars_1 "  << state.bestStars[1]       << "\n";
	mov	esi, DWORD PTR 52[rbp]	# state_26(D)->bestStars[1], state_26(D)->bestStars[1]
	mov	rdi, rax	#, _91
	call	[QWORD PTR _ZNSolsEi@GOTPCREL[rip]]	#
# save_manager.cpp:87:     f << "best_stars_1 "  << state.bestStars[1]       << "\n";
	lea	rsi, .LC15[rip]	#,
	mov	rdi, rax	#, _93
	call	[QWORD PTR _ZStlsISt11char_traitsIcEERSt13basic_ostreamIcT_ES5_PKc@GOTPCREL[rip]]	#
# save_manager.cpp:88:     f << "best_stars_2 "  << state.bestStars[2]       << "\n";
	lea	rsi, .LC30[rip]	#,
	mov	rdi, rsp	#,
	call	[QWORD PTR _ZStlsISt11char_traitsIcEERSt13basic_ostreamIcT_ES5_PKc@GOTPCREL[rip]]	#
# save_manager.cpp:88:     f << "best_stars_2 "  << state.bestStars[2]       << "\n";
	mov	esi, DWORD PTR 56[rbp]	# state_26(D)->bestStars[2], state_26(D)->bestStars[2]
	mov	rdi, rax	#, _96
	call	[QWORD PTR _ZNSolsEi@GOTPCREL[rip]]	#
# save_manager.cpp:88:     f << "best_stars_2 "  << state.bestStars[2]       << "\n";
	lea	rsi, .LC15[rip]	#,
	mov	rdi, rax	#, _98
	call	[QWORD PTR _ZStlsISt11char_traitsIcEERSt13basic_ostreamIcT_ES5_PKc@GOTPCREL[rip]]	#
# save_manager.cpp:89:     f << "difficulty "    << state.difficulty         << "\n";
	lea	rsi, .LC31[rip]	#,
	mov	rdi, rsp	#,
	call	[QWORD PTR _ZStlsISt11char_traitsIcEERSt13basic_ostreamIcT_ES5_PKc@GOTPCREL[rip]]	#
# save_manager.cpp:89:     f << "difficulty "    << state.difficulty         << "\n";
	mov	esi, DWORD PTR 96[rbp]	# state_26(D)->difficulty, state_26(D)->difficulty
	mov	rdi, rax	#, _101
	call	[QWORD PTR _ZNSolsEi@GOTPCREL[rip]]	#
.L108:
# save_manager.cpp:67:         std::cerr << "[SaveManager] Не могу открыть " << AUTOSAVE_FILE << "\n";
	lea	rsi, .LC15[rip]	#,
	mov	rdi, rax	#, _110
	call	[QWORD PTR _ZStlsISt11char_traitsIcEERSt13basic_ostreamIcT_ES5_PKc@GOTPCREL[rip]]	#
# save_manager.cpp:90: }
	mov	rdi, rsp	#,
	call	[QWORD PTR _ZNSt14basic_ofstreamIcSt11char_traitsIcEED1Ev@GOTPCREL[rip]]	#
	mov	rax, QWORD PTR 520[rsp]	# tmp272, D.189112
	sub	rax, QWORD PTR fs:40	# tmp272, MEM[(<address-space-1> long unsigned int *)40B]
	jne	.L110	#,
	add	rsp, 536	#,
	.cfi_remember_state
	.cfi_def_cfa_offset 24
	pop	rbx	#
	.cfi_def_cfa_offset 16
	pop	rbp	#
	.cfi_def_cfa_offset 8
	ret	
	.p2align 4,,10
	.p2align 3
.L109:
	.cfi_restore_state
# save_manager.cpp:67:         std::cerr << "[SaveManager] Не могу открыть " << AUTOSAVE_FILE << "\n";
	lea	rsi, .LC14[rip]	#,
	lea	rdi, _ZSt4cerr[rip]	#,
	call	[QWORD PTR _ZStlsISt11char_traitsIcEERSt13basic_ostreamIcT_ES5_PKc@GOTPCREL[rip]]	#
# save_manager.cpp:67:         std::cerr << "[SaveManager] Не могу открыть " << AUTOSAVE_FILE << "\n";
	lea	rsi, .LC13[rip]	#,
	mov	rdi, rax	#, _108
	call	[QWORD PTR _ZStlsISt11char_traitsIcEERSt13basic_ostreamIcT_ES5_PKc@GOTPCREL[rip]]	#
.LEHE1:
	jmp	.L108	#
.L110:
# save_manager.cpp:90: }
	call	[QWORD PTR __stack_chk_fail@GOTPCREL[rip]]	#
.L104:
	mov	rbp, rax	# tmp271,
	jmp	.L101	#
	.section	.gcc_except_table,"a",@progbits
.LLSDA13552:
	.byte	0xff
	.byte	0xff
	.byte	0x1
	.uleb128 .LLSDACSE13552-.LLSDACSB13552
.LLSDACSB13552:
	.uleb128 .LEHB0-.LFB13552
	.uleb128 .LEHE0-.LEHB0
	.uleb128 0
	.uleb128 0
	.uleb128 .LEHB1-.LFB13552
	.uleb128 .LEHE1-.LEHB1
	.uleb128 .L104-.LFB13552
	.uleb128 0
.LLSDACSE13552:
	.text
	.cfi_endproc
	.section	.text.unlikely
	.cfi_startproc
	.cfi_personality 0x9b,DW.ref.__gxx_personality_v0
	.cfi_lsda 0x1b,.LLSDAC13552
	.type	_ZN11SaveManager17writeAutosaveFileERK13GameSaveState.cold, @function
_ZN11SaveManager17writeAutosaveFileERK13GameSaveState.cold:
.LFSB13552:
.L101:
	.cfi_def_cfa_offset 560
	.cfi_offset 3, -24
	.cfi_offset 6, -16
	mov	rdi, rsp	#,
	call	[QWORD PTR _ZNSt14basic_ofstreamIcSt11char_traitsIcEED1Ev@GOTPCREL[rip]]	#
	mov	rax, QWORD PTR 520[rsp]	# tmp273, D.189112
	sub	rax, QWORD PTR fs:40	# tmp273, MEM[(<address-space-1> long unsigned int *)40B]
	jne	.L111	#,
	mov	rdi, rbp	#, tmp271
.LEHB2:
	call	[QWORD PTR _Unwind_Resume@GOTPCREL[rip]]	#
.LEHE2:
.L111:
	call	[QWORD PTR __stack_chk_fail@GOTPCREL[rip]]	#
	.cfi_endproc
.LFE13552:
	.section	.gcc_except_table
.LLSDAC13552:
	.byte	0xff
	.byte	0xff
	.byte	0x1
	.uleb128 .LLSDACSEC13552-.LLSDACSBC13552
.LLSDACSBC13552:
	.uleb128 .LEHB2-.LCOLDB32
	.uleb128 .LEHE2-.LEHB2
	.uleb128 0
	.uleb128 0
.LLSDACSEC13552:
	.section	.text.unlikely
	.text
	.size	_ZN11SaveManager17writeAutosaveFileERK13GameSaveState, .-_ZN11SaveManager17writeAutosaveFileERK13GameSaveState
	.section	.text.unlikely
	.size	_ZN11SaveManager17writeAutosaveFileERK13GameSaveState.cold, .-_ZN11SaveManager17writeAutosaveFileERK13GameSaveState.cold
.LCOLDE32:
	.text
.LHOTE32:
	.align 2
	.p2align 4
	.globl	_ZN11SaveManager12tickAutosaveEfRK13GameSaveState
	.type	_ZN11SaveManager12tickAutosaveEfRK13GameSaveState, @function
_ZN11SaveManager12tickAutosaveEfRK13GameSaveState:
.LFB13555:
	.cfi_startproc
# save_manager.cpp:186:     autosaveTimer += deltaTime;
	addss	xmm0, DWORD PTR [rdi]	# _2, this_5(D)->autosaveTimer
# save_manager.cpp:187:     if (autosaveTimer >= AUTOSAVE_INTERVAL) {
	comiss	xmm0, DWORD PTR .LC33[rip]	# _2,
	jnb	.L113	#,
# save_manager.cpp:186:     autosaveTimer += deltaTime;
	movss	DWORD PTR [rdi], xmm0	# this_5(D)->autosaveTimer, _2
	ret	
	.p2align 4,,10
	.p2align 3
.L113:
# save_manager.cpp:185: void SaveManager::tickAutosave(float deltaTime, const GameSaveState& state) {
	sub	rsp, 24	#,
	.cfi_def_cfa_offset 32
# save_manager.cpp:188:         autosaveTimer = 0.0f;
	mov	DWORD PTR [rdi], 0x00000000	# this_5(D)->autosaveTimer,
# save_manager.cpp:189:         writeAutosaveFile(state);
	mov	QWORD PTR 8[rsp], rsi	# %sfp, state
	mov	QWORD PTR [rsp], rdi	# %sfp, this
	call	_ZN11SaveManager17writeAutosaveFileERK13GameSaveState	#
# save_manager.cpp:190:         lastAutosave  = state;
	mov	rsi, QWORD PTR 8[rsp]	# state, %sfp
	mov	rdi, QWORD PTR [rsp]	# this, %sfp
	movdqu	xmm0, XMMWORD PTR [rsi]	# *state_9(D), *state_9(D)
	movups	XMMWORD PTR 36[rdi], xmm0	# this_5(D)->lastAutosave, *state_9(D)
	movdqu	xmm0, XMMWORD PTR 16[rsi]	# *state_9(D), *state_9(D)
	movups	XMMWORD PTR 52[rdi], xmm0	# this_5(D)->lastAutosave, *state_9(D)
	movdqu	xmm0, XMMWORD PTR 32[rsi]	# *state_9(D), *state_9(D)
	movups	XMMWORD PTR 68[rdi], xmm0	# this_5(D)->lastAutosave, *state_9(D)
	movdqu	xmm0, XMMWORD PTR 48[rsi]	# *state_9(D), *state_9(D)
	movups	XMMWORD PTR 84[rdi], xmm0	# this_5(D)->lastAutosave, *state_9(D)
	movdqu	xmm0, XMMWORD PTR 64[rsi]	# *state_9(D), *state_9(D)
	movups	XMMWORD PTR 100[rdi], xmm0	# this_5(D)->lastAutosave, *state_9(D)
	movdqu	xmm0, XMMWORD PTR 80[rsi]	# *state_9(D), *state_9(D)
	movups	XMMWORD PTR 116[rdi], xmm0	# this_5(D)->lastAutosave, *state_9(D)
	mov	eax, DWORD PTR 96[rsi]	# *state_9(D), *state_9(D)
# save_manager.cpp:191:         hasAutosave   = true;
	mov	BYTE PTR 136[rdi], 1	# this_5(D)->hasAutosave,
# save_manager.cpp:190:         lastAutosave  = state;
	mov	DWORD PTR 132[rdi], eax	# this_5(D)->lastAutosave, *state_9(D)
# save_manager.cpp:193: }
	add	rsp, 24	#,
	.cfi_def_cfa_offset 8
	ret	
	.cfi_endproc
.LFE13555:
	.size	_ZN11SaveManager12tickAutosaveEfRK13GameSaveState, .-_ZN11SaveManager12tickAutosaveEfRK13GameSaveState
	.align 2
	.p2align 4
	.globl	_ZN11SaveManager10saveOnExitERK13GameSaveState
	.type	_ZN11SaveManager10saveOnExitERK13GameSaveState, @function
_ZN11SaveManager10saveOnExitERK13GameSaveState:
.LFB13556:
	.cfi_startproc
	push	rbp	#
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	mov	rbp, rsi	# state, state
	push	rbx	#
	.cfi_def_cfa_offset 24
	.cfi_offset 3, -24
	mov	rbx, rdi	# this, this
	sub	rsp, 8	#,
	.cfi_def_cfa_offset 32
# save_manager.cpp:196:     writeAutosaveFile(state);
	call	_ZN11SaveManager17writeAutosaveFileERK13GameSaveState	#
# save_manager.cpp:197:     lastAutosave = state;
	movdqu	xmm0, XMMWORD PTR 0[rbp]	# *state_3(D), *state_3(D)
	movups	XMMWORD PTR 36[rbx], xmm0	# this_2(D)->lastAutosave, *state_3(D)
	movdqu	xmm0, XMMWORD PTR 16[rbp]	# *state_3(D), *state_3(D)
	movups	XMMWORD PTR 52[rbx], xmm0	# this_2(D)->lastAutosave, *state_3(D)
	movdqu	xmm0, XMMWORD PTR 32[rbp]	# *state_3(D), *state_3(D)
	movups	XMMWORD PTR 68[rbx], xmm0	# this_2(D)->lastAutosave, *state_3(D)
	movdqu	xmm0, XMMWORD PTR 48[rbp]	# *state_3(D), *state_3(D)
	movups	XMMWORD PTR 84[rbx], xmm0	# this_2(D)->lastAutosave, *state_3(D)
	movdqu	xmm0, XMMWORD PTR 64[rbp]	# *state_3(D), *state_3(D)
	movups	XMMWORD PTR 100[rbx], xmm0	# this_2(D)->lastAutosave, *state_3(D)
	movdqu	xmm0, XMMWORD PTR 80[rbp]	# *state_3(D), *state_3(D)
	movups	XMMWORD PTR 116[rbx], xmm0	# this_2(D)->lastAutosave, *state_3(D)
	mov	eax, DWORD PTR 96[rbp]	# *state_3(D), *state_3(D)
# save_manager.cpp:198:     hasAutosave  = true;
	mov	BYTE PTR 136[rbx], 1	# this_2(D)->hasAutosave,
# save_manager.cpp:197:     lastAutosave = state;
	mov	DWORD PTR 132[rbx], eax	# this_2(D)->lastAutosave, *state_3(D)
# save_manager.cpp:199: }
	add	rsp, 8	#,
	.cfi_def_cfa_offset 24
	pop	rbx	#
	.cfi_def_cfa_offset 16
	pop	rbp	#
	.cfi_def_cfa_offset 8
	ret	
	.cfi_endproc
.LFE13556:
	.size	_ZN11SaveManager10saveOnExitERK13GameSaveState, .-_ZN11SaveManager10saveOnExitERK13GameSaveState
	.section	.rodata.str1.8
	.align 8
.LC35:
	.base64	"W1NhdmVNYW5hZ2VyXSDQndC1INC80L7Qs9GDINGB0L7Qt9C00LDRgtGMIAA="
	.section	.rodata.str1.1
.LC36:
	.string	"# Boss Fight Save \342\200\224 "
.LC37:
	.string	"attack_mouse "
.LC38:
	.string	"magic_mouse "
.LC39:
	.string	"jump_key "
.LC40:
	.string	"left_key "
.LC41:
	.string	"right_key "
.LC42:
	.string	"crouch_key "
.LC43:
	.string	"interact_key "
.LC44:
	.string	"dash_key "
.LC45:
	.string	"shield_key "
	.section	.text.unlikely
	.align 2
.LCOLDB46:
	.text
.LHOTB46:
	.align 2
	.p2align 4
	.globl	_ZN11SaveManager13writeSaveFileERKNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEEERK13GameSaveStateS7_
	.type	_ZN11SaveManager13writeSaveFileERKNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEEERK13GameSaveStateS7_, @function
_ZN11SaveManager13writeSaveFileERKNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEEERK13GameSaveStateS7_:
.LFB13553:
	.cfi_startproc
	.cfi_personality 0x9b,DW.ref.__gxx_personality_v0
	.cfi_lsda 0x1b,.LLSDA13553
	push	r14	#
	.cfi_def_cfa_offset 16
	.cfi_offset 14, -16
	push	r12	#
	.cfi_def_cfa_offset 24
	.cfi_offset 12, -24
	mov	r12, rsi	# path, path
	push	rbp	#
	.cfi_def_cfa_offset 32
	.cfi_offset 6, -32
	mov	rbp, rdx	# state, state
# save_manager.cpp:95:     std::ofstream f(path);
	mov	edx, 16	#,
# save_manager.cpp:94:                                 const std::string& saveName) {
	push	rbx	#
	.cfi_def_cfa_offset 40
	.cfi_offset 3, -40
	sub	rsp, 536	#,
	.cfi_def_cfa_offset 576
# save_manager.cpp:94:                                 const std::string& saveName) {
	mov	r14, QWORD PTR fs:40	# saveName, MEM[(<address-space-1> long unsigned int *)40B]
	mov	QWORD PTR 520[rsp], r14	# D.189224, saveName
	mov	r14, rcx	# saveName, saveName
# save_manager.cpp:95:     std::ofstream f(path);
	mov	rdi, rsp	#,
.LEHB3:
	call	[QWORD PTR _ZNSt14basic_ofstreamIcSt11char_traitsIcEEC1ERKNSt7__cxx1112basic_stringIcS1_SaIcEEESt13_Ios_Openmode@GOTPCREL[rip]]	#
.LEHE3:
# save_manager.cpp:96:     if (!f.is_open()) {
	mov	rdi, rsp	#,
	call	[QWORD PTR _ZNSt14basic_ofstreamIcSt11char_traitsIcEE7is_openEv@GOTPCREL[rip]]	#
# save_manager.cpp:96:     if (!f.is_open()) {
	test	al, al	# _1
	je	.L131	#,
# save_manager.cpp:102:     f << "# Boss Fight Save — " << saveName << "\n";
	lea	rsi, .LC36[rip]	#,
	mov	rdi, rsp	#,
.LEHB4:
	call	[QWORD PTR _ZStlsISt11char_traitsIcEERSt13basic_ostreamIcT_ES5_PKc@GOTPCREL[rip]]	#
# save_manager.cpp:102:     f << "# Boss Fight Save — " << saveName << "\n";
	mov	rsi, r14	#, saveName
	mov	rdi, rax	#, _35
	call	[QWORD PTR _ZStlsIcSt11char_traitsIcESaIcEERSt13basic_ostreamIT_T0_ES7_RKNSt7__cxx1112basic_stringIS4_S5_T1_EE@GOTPCREL[rip]]	#
# save_manager.cpp:102:     f << "# Boss Fight Save — " << saveName << "\n";
	lea	rsi, .LC15[rip]	#,
	mov	rdi, rax	#, _38
	call	[QWORD PTR _ZStlsISt11char_traitsIcEERSt13basic_ostreamIcT_ES5_PKc@GOTPCREL[rip]]	#
# save_manager.cpp:105:     f << "player_x "      << state.player.x           << "\n";
	lea	rsi, .LC16[rip]	#,
	mov	rdi, rsp	#,
	call	[QWORD PTR _ZStlsISt11char_traitsIcEERSt13basic_ostreamIcT_ES5_PKc@GOTPCREL[rip]]	#
# save_manager.cpp:105:     f << "player_x "      << state.player.x           << "\n";
	movss	xmm0, DWORD PTR 0[rbp]	# state_42(D)->player.x, state_42(D)->player.x
	mov	rdi, rax	#, _41
	call	[QWORD PTR _ZNSolsEf@GOTPCREL[rip]]	#
# save_manager.cpp:105:     f << "player_x "      << state.player.x           << "\n";
	lea	rsi, .LC15[rip]	#,
	mov	rdi, rax	#, _44
	call	[QWORD PTR _ZStlsISt11char_traitsIcEERSt13basic_ostreamIcT_ES5_PKc@GOTPCREL[rip]]	#
# save_manager.cpp:106:     f << "player_y "      << state.player.y           << "\n";
	lea	rsi, .LC17[rip]	#,
	mov	rdi, rsp	#,
	call	[QWORD PTR _ZStlsISt11char_traitsIcEERSt13basic_ostreamIcT_ES5_PKc@GOTPCREL[rip]]	#
# save_manager.cpp:106:     f << "player_y "      << state.player.y           << "\n";
	movss	xmm0, DWORD PTR 4[rbp]	# state_42(D)->player.y, state_42(D)->player.y
	mov	rdi, rax	#, _47
	call	[QWORD PTR _ZNSolsEf@GOTPCREL[rip]]	#
# save_manager.cpp:106:     f << "player_y "      << state.player.y           << "\n";
	lea	rsi, .LC15[rip]	#,
	mov	rdi, rax	#, _49
	call	[QWORD PTR _ZStlsISt11char_traitsIcEERSt13basic_ostreamIcT_ES5_PKc@GOTPCREL[rip]]	#
# save_manager.cpp:107:     f << "player_facing " << (state.player.facingRight ? 1 : 0) << "\n";
	lea	rsi, .LC18[rip]	#,
	mov	rdi, rsp	#,
	call	[QWORD PTR _ZStlsISt11char_traitsIcEERSt13basic_ostreamIcT_ES5_PKc@GOTPCREL[rip]]	#
# save_manager.cpp:107:     f << "player_facing " << (state.player.facingRight ? 1 : 0) << "\n";
	movzx	esi, BYTE PTR 8[rbp]	# _177, state_42(D)->player.facingRight
# save_manager.cpp:107:     f << "player_facing " << (state.player.facingRight ? 1 : 0) << "\n";
	mov	rdi, rax	#, _52
	call	[QWORD PTR _ZNSolsEi@GOTPCREL[rip]]	#
# save_manager.cpp:107:     f << "player_facing " << (state.player.facingRight ? 1 : 0) << "\n";
	lea	rsi, .LC15[rip]	#,
	mov	rdi, rax	#, _54
	call	[QWORD PTR _ZStlsISt11char_traitsIcEERSt13basic_ostreamIcT_ES5_PKc@GOTPCREL[rip]]	#
# save_manager.cpp:108:     f << "player_hp "     << state.player.hp          << "\n";
	lea	rsi, .LC19[rip]	#,
	mov	rdi, rsp	#,
	call	[QWORD PTR _ZStlsISt11char_traitsIcEERSt13basic_ostreamIcT_ES5_PKc@GOTPCREL[rip]]	#
# save_manager.cpp:108:     f << "player_hp "     << state.player.hp          << "\n";
	movss	xmm0, DWORD PTR 12[rbp]	# state_42(D)->player.hp, state_42(D)->player.hp
	mov	rdi, rax	#, _57
	call	[QWORD PTR _ZNSolsEf@GOTPCREL[rip]]	#
# save_manager.cpp:108:     f << "player_hp "     << state.player.hp          << "\n";
	lea	rsi, .LC15[rip]	#,
	mov	rdi, rax	#, _59
	call	[QWORD PTR _ZStlsISt11char_traitsIcEERSt13basic_ostreamIcT_ES5_PKc@GOTPCREL[rip]]	#
# save_manager.cpp:109:     f << "boss_x "        << state.boss.x             << "\n";
	lea	rsi, .LC20[rip]	#,
	mov	rdi, rsp	#,
	call	[QWORD PTR _ZStlsISt11char_traitsIcEERSt13basic_ostreamIcT_ES5_PKc@GOTPCREL[rip]]	#
# save_manager.cpp:109:     f << "boss_x "        << state.boss.x             << "\n";
	movss	xmm0, DWORD PTR 16[rbp]	# state_42(D)->boss.x, state_42(D)->boss.x
	mov	rdi, rax	#, _62
	call	[QWORD PTR _ZNSolsEf@GOTPCREL[rip]]	#
# save_manager.cpp:109:     f << "boss_x "        << state.boss.x             << "\n";
	lea	rsi, .LC15[rip]	#,
	mov	rdi, rax	#, _64
	call	[QWORD PTR _ZStlsISt11char_traitsIcEERSt13basic_ostreamIcT_ES5_PKc@GOTPCREL[rip]]	#
# save_manager.cpp:110:     f << "boss_y "        << state.boss.y             << "\n";
	lea	rsi, .LC21[rip]	#,
	mov	rdi, rsp	#,
	call	[QWORD PTR _ZStlsISt11char_traitsIcEERSt13basic_ostreamIcT_ES5_PKc@GOTPCREL[rip]]	#
# save_manager.cpp:110:     f << "boss_y "        << state.boss.y             << "\n";
	movss	xmm0, DWORD PTR 20[rbp]	# state_42(D)->boss.y, state_42(D)->boss.y
	mov	rdi, rax	#, _67
	call	[QWORD PTR _ZNSolsEf@GOTPCREL[rip]]	#
# save_manager.cpp:110:     f << "boss_y "        << state.boss.y             << "\n";
	lea	rsi, .LC15[rip]	#,
	mov	rdi, rax	#, _69
	call	[QWORD PTR _ZStlsISt11char_traitsIcEERSt13basic_ostreamIcT_ES5_PKc@GOTPCREL[rip]]	#
# save_manager.cpp:111:     f << "boss_facing "   << (state.boss.facingRight ? 1 : 0) << "\n";
	lea	rsi, .LC22[rip]	#,
	mov	rdi, rsp	#,
	call	[QWORD PTR _ZStlsISt11char_traitsIcEERSt13basic_ostreamIcT_ES5_PKc@GOTPCREL[rip]]	#
# save_manager.cpp:111:     f << "boss_facing "   << (state.boss.facingRight ? 1 : 0) << "\n";
	movzx	esi, BYTE PTR 24[rbp]	# _176, state_42(D)->boss.facingRight
# save_manager.cpp:111:     f << "boss_facing "   << (state.boss.facingRight ? 1 : 0) << "\n";
	mov	rdi, rax	#, _72
	call	[QWORD PTR _ZNSolsEi@GOTPCREL[rip]]	#
# save_manager.cpp:111:     f << "boss_facing "   << (state.boss.facingRight ? 1 : 0) << "\n";
	lea	rsi, .LC15[rip]	#,
	mov	rdi, rax	#, _74
	call	[QWORD PTR _ZStlsISt11char_traitsIcEERSt13basic_ostreamIcT_ES5_PKc@GOTPCREL[rip]]	#
# save_manager.cpp:112:     f << "boss_hp "       << state.boss.hp            << "\n";
	lea	rsi, .LC23[rip]	#,
	mov	rdi, rsp	#,
	call	[QWORD PTR _ZStlsISt11char_traitsIcEERSt13basic_ostreamIcT_ES5_PKc@GOTPCREL[rip]]	#
# save_manager.cpp:112:     f << "boss_hp "       << state.boss.hp            << "\n";
	movss	xmm0, DWORD PTR 28[rbp]	# state_42(D)->boss.hp, state_42(D)->boss.hp
	mov	rdi, rax	#, _77
	call	[QWORD PTR _ZNSolsEf@GOTPCREL[rip]]	#
# save_manager.cpp:112:     f << "boss_hp "       << state.boss.hp            << "\n";
	lea	rsi, .LC15[rip]	#,
	mov	rdi, rax	#, _79
	call	[QWORD PTR _ZStlsISt11char_traitsIcEERSt13basic_ostreamIcT_ES5_PKc@GOTPCREL[rip]]	#
# save_manager.cpp:113:     f << "boss_phase "    << state.bossPhase          << "\n";
	lea	rsi, .LC24[rip]	#,
	mov	rdi, rsp	#,
	call	[QWORD PTR _ZStlsISt11char_traitsIcEERSt13basic_ostreamIcT_ES5_PKc@GOTPCREL[rip]]	#
# save_manager.cpp:113:     f << "boss_phase "    << state.bossPhase          << "\n";
	mov	esi, DWORD PTR 32[rbp]	# state_42(D)->bossPhase, state_42(D)->bossPhase
	mov	rdi, rax	#, _82
	call	[QWORD PTR _ZNSolsEi@GOTPCREL[rip]]	#
# save_manager.cpp:113:     f << "boss_phase "    << state.bossPhase          << "\n";
	lea	rsi, .LC15[rip]	#,
	mov	rdi, rax	#, _84
	call	[QWORD PTR _ZStlsISt11char_traitsIcEERSt13basic_ostreamIcT_ES5_PKc@GOTPCREL[rip]]	#
# save_manager.cpp:114:     f << "level_timer "   << state.levelTimer         << "\n";
	lea	rsi, .LC25[rip]	#,
	mov	rdi, rsp	#,
	call	[QWORD PTR _ZStlsISt11char_traitsIcEERSt13basic_ostreamIcT_ES5_PKc@GOTPCREL[rip]]	#
# save_manager.cpp:114:     f << "level_timer "   << state.levelTimer         << "\n";
	movss	xmm0, DWORD PTR 36[rbp]	# state_42(D)->levelTimer, state_42(D)->levelTimer
	mov	rdi, rax	#, _87
	call	[QWORD PTR _ZNSolsEf@GOTPCREL[rip]]	#
# save_manager.cpp:114:     f << "level_timer "   << state.levelTimer         << "\n";
	lea	rsi, .LC15[rip]	#,
	mov	rdi, rax	#, _89
	call	[QWORD PTR _ZStlsISt11char_traitsIcEERSt13basic_ostreamIcT_ES5_PKc@GOTPCREL[rip]]	#
# save_manager.cpp:115:     f << "current_level " << state.currentLevel       << "\n";
	lea	rsi, .LC26[rip]	#,
	mov	rdi, rsp	#,
	call	[QWORD PTR _ZStlsISt11char_traitsIcEERSt13basic_ostreamIcT_ES5_PKc@GOTPCREL[rip]]	#
# save_manager.cpp:115:     f << "current_level " << state.currentLevel       << "\n";
	mov	esi, DWORD PTR 40[rbp]	# state_42(D)->currentLevel, state_42(D)->currentLevel
	mov	rdi, rax	#, _92
	call	[QWORD PTR _ZNSolsEi@GOTPCREL[rip]]	#
# save_manager.cpp:115:     f << "current_level " << state.currentLevel       << "\n";
	lea	rsi, .LC15[rip]	#,
	mov	rdi, rax	#, _94
	call	[QWORD PTR _ZStlsISt11char_traitsIcEERSt13basic_ostreamIcT_ES5_PKc@GOTPCREL[rip]]	#
# save_manager.cpp:116:     f << "lives_left "    << state.livesLeft          << "\n";
	lea	rsi, .LC27[rip]	#,
	mov	rdi, rsp	#,
	call	[QWORD PTR _ZStlsISt11char_traitsIcEERSt13basic_ostreamIcT_ES5_PKc@GOTPCREL[rip]]	#
# save_manager.cpp:116:     f << "lives_left "    << state.livesLeft          << "\n";
	mov	esi, DWORD PTR 44[rbp]	# state_42(D)->livesLeft, state_42(D)->livesLeft
	mov	rdi, rax	#, _97
	call	[QWORD PTR _ZNSolsEi@GOTPCREL[rip]]	#
# save_manager.cpp:116:     f << "lives_left "    << state.livesLeft          << "\n";
	lea	rsi, .LC15[rip]	#,
	mov	rdi, rax	#, _99
	call	[QWORD PTR _ZStlsISt11char_traitsIcEERSt13basic_ostreamIcT_ES5_PKc@GOTPCREL[rip]]	#
# save_manager.cpp:117:     f << "best_stars_0 "  << state.bestStars[0]       << "\n";
	lea	rsi, .LC28[rip]	#,
	mov	rdi, rsp	#,
	call	[QWORD PTR _ZStlsISt11char_traitsIcEERSt13basic_ostreamIcT_ES5_PKc@GOTPCREL[rip]]	#
# save_manager.cpp:117:     f << "best_stars_0 "  << state.bestStars[0]       << "\n";
	mov	esi, DWORD PTR 48[rbp]	# state_42(D)->bestStars[0], state_42(D)->bestStars[0]
	mov	rdi, rax	#, _102
	call	[QWORD PTR _ZNSolsEi@GOTPCREL[rip]]	#
# save_manager.cpp:117:     f << "best_stars_0 "  << state.bestStars[0]       << "\n";
	lea	rsi, .LC15[rip]	#,
	mov	rdi, rax	#, _104
	call	[QWORD PTR _ZStlsISt11char_traitsIcEERSt13basic_ostreamIcT_ES5_PKc@GOTPCREL[rip]]	#
# save_manager.cpp:118:     f << "best_stars_1 "  << state.bestStars[1]       << "\n";
	lea	rsi, .LC29[rip]	#,
	mov	rdi, rsp	#,
	call	[QWORD PTR _ZStlsISt11char_traitsIcEERSt13basic_ostreamIcT_ES5_PKc@GOTPCREL[rip]]	#
# save_manager.cpp:118:     f << "best_stars_1 "  << state.bestStars[1]       << "\n";
	mov	esi, DWORD PTR 52[rbp]	# state_42(D)->bestStars[1], state_42(D)->bestStars[1]
	mov	rdi, rax	#, _107
	call	[QWORD PTR _ZNSolsEi@GOTPCREL[rip]]	#
# save_manager.cpp:118:     f << "best_stars_1 "  << state.bestStars[1]       << "\n";
	lea	rsi, .LC15[rip]	#,
	mov	rdi, rax	#, _109
	call	[QWORD PTR _ZStlsISt11char_traitsIcEERSt13basic_ostreamIcT_ES5_PKc@GOTPCREL[rip]]	#
# save_manager.cpp:119:     f << "best_stars_2 "  << state.bestStars[2]       << "\n";
	lea	rsi, .LC30[rip]	#,
	mov	rdi, rsp	#,
	call	[QWORD PTR _ZStlsISt11char_traitsIcEERSt13basic_ostreamIcT_ES5_PKc@GOTPCREL[rip]]	#
# save_manager.cpp:119:     f << "best_stars_2 "  << state.bestStars[2]       << "\n";
	mov	esi, DWORD PTR 56[rbp]	# state_42(D)->bestStars[2], state_42(D)->bestStars[2]
	mov	rdi, rax	#, _112
	call	[QWORD PTR _ZNSolsEi@GOTPCREL[rip]]	#
# save_manager.cpp:119:     f << "best_stars_2 "  << state.bestStars[2]       << "\n";
	lea	rsi, .LC15[rip]	#,
	mov	rdi, rax	#, _114
	call	[QWORD PTR _ZStlsISt11char_traitsIcEERSt13basic_ostreamIcT_ES5_PKc@GOTPCREL[rip]]	#
# save_manager.cpp:120:     f << "difficulty "    << state.difficulty         << "\n";
	lea	rsi, .LC31[rip]	#,
	mov	rdi, rsp	#,
	call	[QWORD PTR _ZStlsISt11char_traitsIcEERSt13basic_ostreamIcT_ES5_PKc@GOTPCREL[rip]]	#
# save_manager.cpp:120:     f << "difficulty "    << state.difficulty         << "\n";
	mov	esi, DWORD PTR 96[rbp]	# state_42(D)->difficulty, state_42(D)->difficulty
	mov	rdi, rax	#, _117
	call	[QWORD PTR _ZNSolsEi@GOTPCREL[rip]]	#
# save_manager.cpp:120:     f << "difficulty "    << state.difficulty         << "\n";
	lea	rsi, .LC15[rip]	#,
	mov	rdi, rax	#, _119
	call	[QWORD PTR _ZStlsISt11char_traitsIcEERSt13basic_ostreamIcT_ES5_PKc@GOTPCREL[rip]]	#
# save_manager.cpp:123:     f << "attack_mouse "  << state.attackMouse        << "\n";
	lea	rsi, .LC37[rip]	#,
	mov	rdi, rsp	#,
	call	[QWORD PTR _ZStlsISt11char_traitsIcEERSt13basic_ostreamIcT_ES5_PKc@GOTPCREL[rip]]	#
# save_manager.cpp:123:     f << "attack_mouse "  << state.attackMouse        << "\n";
	mov	esi, DWORD PTR 60[rbp]	# state_42(D)->attackMouse, state_42(D)->attackMouse
	mov	rdi, rax	#, _122
	call	[QWORD PTR _ZNSolsEi@GOTPCREL[rip]]	#
# save_manager.cpp:123:     f << "attack_mouse "  << state.attackMouse        << "\n";
	lea	rsi, .LC15[rip]	#,
	mov	rdi, rax	#, _124
	call	[QWORD PTR _ZStlsISt11char_traitsIcEERSt13basic_ostreamIcT_ES5_PKc@GOTPCREL[rip]]	#
# save_manager.cpp:124:     f << "magic_mouse "   << state.magicMouse         << "\n";
	lea	rsi, .LC38[rip]	#,
	mov	rdi, rsp	#,
	call	[QWORD PTR _ZStlsISt11char_traitsIcEERSt13basic_ostreamIcT_ES5_PKc@GOTPCREL[rip]]	#
# save_manager.cpp:124:     f << "magic_mouse "   << state.magicMouse         << "\n";
	mov	esi, DWORD PTR 64[rbp]	# state_42(D)->magicMouse, state_42(D)->magicMouse
	mov	rdi, rax	#, _127
	call	[QWORD PTR _ZNSolsEi@GOTPCREL[rip]]	#
# save_manager.cpp:124:     f << "magic_mouse "   << state.magicMouse         << "\n";
	lea	rsi, .LC15[rip]	#,
	mov	rdi, rax	#, _129
	call	[QWORD PTR _ZStlsISt11char_traitsIcEERSt13basic_ostreamIcT_ES5_PKc@GOTPCREL[rip]]	#
# save_manager.cpp:125:     f << "jump_key "      << state.jumpKey            << "\n";
	lea	rsi, .LC39[rip]	#,
	mov	rdi, rsp	#,
	call	[QWORD PTR _ZStlsISt11char_traitsIcEERSt13basic_ostreamIcT_ES5_PKc@GOTPCREL[rip]]	#
# save_manager.cpp:125:     f << "jump_key "      << state.jumpKey            << "\n";
	mov	esi, DWORD PTR 68[rbp]	# state_42(D)->jumpKey, state_42(D)->jumpKey
	mov	rdi, rax	#, _132
	call	[QWORD PTR _ZNSolsEi@GOTPCREL[rip]]	#
# save_manager.cpp:125:     f << "jump_key "      << state.jumpKey            << "\n";
	lea	rsi, .LC15[rip]	#,
	mov	rdi, rax	#, _134
	call	[QWORD PTR _ZStlsISt11char_traitsIcEERSt13basic_ostreamIcT_ES5_PKc@GOTPCREL[rip]]	#
# save_manager.cpp:126:     f << "left_key "      << state.leftKey            << "\n";
	lea	rsi, .LC40[rip]	#,
	mov	rdi, rsp	#,
	call	[QWORD PTR _ZStlsISt11char_traitsIcEERSt13basic_ostreamIcT_ES5_PKc@GOTPCREL[rip]]	#
# save_manager.cpp:126:     f << "left_key "      << state.leftKey            << "\n";
	mov	esi, DWORD PTR 72[rbp]	# state_42(D)->leftKey, state_42(D)->leftKey
	mov	rdi, rax	#, _137
	call	[QWORD PTR _ZNSolsEi@GOTPCREL[rip]]	#
# save_manager.cpp:126:     f << "left_key "      << state.leftKey            << "\n";
	lea	rsi, .LC15[rip]	#,
	mov	rdi, rax	#, _139
	call	[QWORD PTR _ZStlsISt11char_traitsIcEERSt13basic_ostreamIcT_ES5_PKc@GOTPCREL[rip]]	#
# save_manager.cpp:127:     f << "right_key "     << state.rightKey           << "\n";
	lea	rsi, .LC41[rip]	#,
	mov	rdi, rsp	#,
	call	[QWORD PTR _ZStlsISt11char_traitsIcEERSt13basic_ostreamIcT_ES5_PKc@GOTPCREL[rip]]	#
# save_manager.cpp:127:     f << "right_key "     << state.rightKey           << "\n";
	mov	esi, DWORD PTR 76[rbp]	# state_42(D)->rightKey, state_42(D)->rightKey
	mov	rdi, rax	#, _142
	call	[QWORD PTR _ZNSolsEi@GOTPCREL[rip]]	#
# save_manager.cpp:127:     f << "right_key "     << state.rightKey           << "\n";
	lea	rsi, .LC15[rip]	#,
	mov	rdi, rax	#, _144
	call	[QWORD PTR _ZStlsISt11char_traitsIcEERSt13basic_ostreamIcT_ES5_PKc@GOTPCREL[rip]]	#
# save_manager.cpp:128:     f << "crouch_key "    << state.crouchKey          << "\n";
	lea	rsi, .LC42[rip]	#,
	mov	rdi, rsp	#,
	call	[QWORD PTR _ZStlsISt11char_traitsIcEERSt13basic_ostreamIcT_ES5_PKc@GOTPCREL[rip]]	#
# save_manager.cpp:128:     f << "crouch_key "    << state.crouchKey          << "\n";
	mov	esi, DWORD PTR 80[rbp]	# state_42(D)->crouchKey, state_42(D)->crouchKey
	mov	rdi, rax	#, _147
	call	[QWORD PTR _ZNSolsEi@GOTPCREL[rip]]	#
# save_manager.cpp:128:     f << "crouch_key "    << state.crouchKey          << "\n";
	lea	rsi, .LC15[rip]	#,
	mov	rdi, rax	#, _149
	call	[QWORD PTR _ZStlsISt11char_traitsIcEERSt13basic_ostreamIcT_ES5_PKc@GOTPCREL[rip]]	#
# save_manager.cpp:129:     f << "interact_key "  << state.interactKey        << "\n";
	lea	rsi, .LC43[rip]	#,
	mov	rdi, rsp	#,
	call	[QWORD PTR _ZStlsISt11char_traitsIcEERSt13basic_ostreamIcT_ES5_PKc@GOTPCREL[rip]]	#
# save_manager.cpp:129:     f << "interact_key "  << state.interactKey        << "\n";
	mov	esi, DWORD PTR 84[rbp]	# state_42(D)->interactKey, state_42(D)->interactKey
	mov	rdi, rax	#, _152
	call	[QWORD PTR _ZNSolsEi@GOTPCREL[rip]]	#
# save_manager.cpp:129:     f << "interact_key "  << state.interactKey        << "\n";
	lea	rsi, .LC15[rip]	#,
	mov	rdi, rax	#, _154
	call	[QWORD PTR _ZStlsISt11char_traitsIcEERSt13basic_ostreamIcT_ES5_PKc@GOTPCREL[rip]]	#
# save_manager.cpp:130:     f << "dash_key "      << state.dashKey            << "\n";
	lea	rsi, .LC44[rip]	#,
	mov	rdi, rsp	#,
	call	[QWORD PTR _ZStlsISt11char_traitsIcEERSt13basic_ostreamIcT_ES5_PKc@GOTPCREL[rip]]	#
# save_manager.cpp:130:     f << "dash_key "      << state.dashKey            << "\n";
	mov	esi, DWORD PTR 88[rbp]	# state_42(D)->dashKey, state_42(D)->dashKey
	mov	rdi, rax	#, _157
	call	[QWORD PTR _ZNSolsEi@GOTPCREL[rip]]	#
# save_manager.cpp:130:     f << "dash_key "      << state.dashKey            << "\n";
	lea	rsi, .LC15[rip]	#,
	mov	rdi, rax	#, _159
	call	[QWORD PTR _ZStlsISt11char_traitsIcEERSt13basic_ostreamIcT_ES5_PKc@GOTPCREL[rip]]	#
# save_manager.cpp:131:     f << "shield_key "    << state.shieldKey          << "\n";
	lea	rsi, .LC45[rip]	#,
	mov	rdi, rsp	#,
	call	[QWORD PTR _ZStlsISt11char_traitsIcEERSt13basic_ostreamIcT_ES5_PKc@GOTPCREL[rip]]	#
# save_manager.cpp:131:     f << "shield_key "    << state.shieldKey          << "\n";
	mov	esi, DWORD PTR 92[rbp]	# state_42(D)->shieldKey, state_42(D)->shieldKey
	mov	rdi, rax	#, _162
	call	[QWORD PTR _ZNSolsEi@GOTPCREL[rip]]	#
.L130:
# save_manager.cpp:97:         std::cerr << "[SaveManager] Не могу создать " << path << "\n";
	lea	rsi, .LC15[rip]	#,
	mov	rdi, rax	#, _171
	call	[QWORD PTR _ZStlsISt11char_traitsIcEERSt13basic_ostreamIcT_ES5_PKc@GOTPCREL[rip]]	#
# save_manager.cpp:132: }
	mov	rdi, rsp	#,
	call	[QWORD PTR _ZNSt14basic_ofstreamIcSt11char_traitsIcEED1Ev@GOTPCREL[rip]]	#
	mov	rax, QWORD PTR 520[rsp]	# tmp361, D.189224
	sub	rax, QWORD PTR fs:40	# tmp361, MEM[(<address-space-1> long unsigned int *)40B]
	jne	.L132	#,
	add	rsp, 536	#,
	.cfi_remember_state
	.cfi_def_cfa_offset 40
	pop	rbx	#
	.cfi_def_cfa_offset 32
	pop	rbp	#
	.cfi_def_cfa_offset 24
	pop	r12	#
	.cfi_def_cfa_offset 16
	pop	r14	#
	.cfi_def_cfa_offset 8
	ret	
	.p2align 4,,10
	.p2align 3
.L131:
	.cfi_restore_state
# save_manager.cpp:97:         std::cerr << "[SaveManager] Не могу создать " << path << "\n";
	lea	rsi, .LC35[rip]	#,
	lea	rdi, _ZSt4cerr[rip]	#,
	call	[QWORD PTR _ZStlsISt11char_traitsIcEERSt13basic_ostreamIcT_ES5_PKc@GOTPCREL[rip]]	#
# save_manager.cpp:97:         std::cerr << "[SaveManager] Не могу создать " << path << "\n";
	mov	rsi, r12	#, path
	mov	rdi, rax	#, _169
	call	[QWORD PTR _ZStlsIcSt11char_traitsIcESaIcEERSt13basic_ostreamIT_T0_ES7_RKNSt7__cxx1112basic_stringIS4_S5_T1_EE@GOTPCREL[rip]]	#
.LEHE4:
	jmp	.L130	#
.L132:
# save_manager.cpp:132: }
	call	[QWORD PTR __stack_chk_fail@GOTPCREL[rip]]	#
.L126:
	mov	rbp, rax	# tmp360,
	jmp	.L123	#
	.section	.gcc_except_table
.LLSDA13553:
	.byte	0xff
	.byte	0xff
	.byte	0x1
	.uleb128 .LLSDACSE13553-.LLSDACSB13553
.LLSDACSB13553:
	.uleb128 .LEHB3-.LFB13553
	.uleb128 .LEHE3-.LEHB3
	.uleb128 0
	.uleb128 0
	.uleb128 .LEHB4-.LFB13553
	.uleb128 .LEHE4-.LEHB4
	.uleb128 .L126-.LFB13553
	.uleb128 0
.LLSDACSE13553:
	.text
	.cfi_endproc
	.section	.text.unlikely
	.cfi_startproc
	.cfi_personality 0x9b,DW.ref.__gxx_personality_v0
	.cfi_lsda 0x1b,.LLSDAC13553
	.type	_ZN11SaveManager13writeSaveFileERKNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEEERK13GameSaveStateS7_.cold, @function
_ZN11SaveManager13writeSaveFileERKNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEEERK13GameSaveStateS7_.cold:
.LFSB13553:
.L123:
	.cfi_def_cfa_offset 576
	.cfi_offset 3, -40
	.cfi_offset 6, -32
	.cfi_offset 12, -24
	.cfi_offset 14, -16
	mov	rdi, rsp	#,
	call	[QWORD PTR _ZNSt14basic_ofstreamIcSt11char_traitsIcEED1Ev@GOTPCREL[rip]]	#
	mov	rax, QWORD PTR 520[rsp]	# tmp362, D.189224
	sub	rax, QWORD PTR fs:40	# tmp362, MEM[(<address-space-1> long unsigned int *)40B]
	jne	.L133	#,
	mov	rdi, rbp	#, tmp360
.LEHB5:
	call	[QWORD PTR _Unwind_Resume@GOTPCREL[rip]]	#
.LEHE5:
.L133:
	call	[QWORD PTR __stack_chk_fail@GOTPCREL[rip]]	#
	.cfi_endproc
.LFE13553:
	.section	.gcc_except_table
.LLSDAC13553:
	.byte	0xff
	.byte	0xff
	.byte	0x1
	.uleb128 .LLSDACSEC13553-.LLSDACSBC13553
.LLSDACSBC13553:
	.uleb128 .LEHB5-.LCOLDB46
	.uleb128 .LEHE5-.LEHB5
	.uleb128 0
	.uleb128 0
.LLSDACSEC13553:
	.section	.text.unlikely
	.text
	.size	_ZN11SaveManager13writeSaveFileERKNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEEERK13GameSaveStateS7_, .-_ZN11SaveManager13writeSaveFileERKNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEEERK13GameSaveStateS7_
	.section	.text.unlikely
	.size	_ZN11SaveManager13writeSaveFileERKNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEEERK13GameSaveStateS7_.cold, .-_ZN11SaveManager13writeSaveFileERKNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEEERK13GameSaveStateS7_.cold
.LCOLDE46:
	.text
.LHOTE46:
	.align 2
	.p2align 4
	.globl	_ZNK11SaveManager15hasAutosaveFileEv
	.type	_ZNK11SaveManager15hasAutosaveFileEv, @function
_ZNK11SaveManager15hasAutosaveFileEv:
.LFB13558:
	.cfi_startproc
	push	rbx	#
	.cfi_def_cfa_offset 16
	.cfi_offset 3, -16
# save_manager.cpp:206:     std::ifstream f(AUTOSAVE_FILE);
	lea	rsi, .LC13[rip]	#,
# save_manager.cpp:205: bool SaveManager::hasAutosaveFile() const {
	sub	rsp, 544	#,
	.cfi_def_cfa_offset 560
# save_manager.cpp:206:     std::ifstream f(AUTOSAVE_FILE);
	mov	rdx, QWORD PTR fs:40	#, MEM[(<address-space-1> long unsigned int *)40B]
	mov	QWORD PTR 536[rsp], rdx	# D.189239,
	mov	edx, 8	#,
	lea	rdi, 16[rsp]	#,
	call	[QWORD PTR _ZNSt14basic_ifstreamIcSt11char_traitsIcEEC1EPKcSt13_Ios_Openmode@GOTPCREL[rip]]	#
# save_manager.cpp:207:     return f.good();
	lea	rdi, 272[rsp]	# tmp105,
	call	[QWORD PTR _ZNKSt9basic_iosIcSt11char_traitsIcEE4goodEv@GOTPCREL[rip]]	#
# save_manager.cpp:208: }
	lea	rdi, 16[rsp]	#,
# save_manager.cpp:207:     return f.good();
	mov	BYTE PTR 15[rsp], al	# %sfp, <retval>
# save_manager.cpp:208: }
	call	[QWORD PTR _ZNSt14basic_ifstreamIcSt11char_traitsIcEED1Ev@GOTPCREL[rip]]	#
	movzx	eax, BYTE PTR 15[rsp]	# <retval>, %sfp
	mov	rdx, QWORD PTR 536[rsp]	# tmp110, D.189239
	sub	rdx, QWORD PTR fs:40	# tmp110, MEM[(<address-space-1> long unsigned int *)40B]
	jne	.L137	#,
	add	rsp, 544	#,
	.cfi_remember_state
	.cfi_def_cfa_offset 16
	pop	rbx	#
	.cfi_def_cfa_offset 8
	ret	
.L137:
	.cfi_restore_state
	call	[QWORD PTR __stack_chk_fail@GOTPCREL[rip]]	#
	.cfi_endproc
.LFE13558:
	.size	_ZNK11SaveManager15hasAutosaveFileEv, .-_ZNK11SaveManager15hasAutosaveFileEv
	.section	.text._ZSteqIcSt11char_traitsIcESaIcEEbRKNSt7__cxx1112basic_stringIT_T0_T1_EEPKS5_,"axG",@progbits,_ZSteqIcSt11char_traitsIcESaIcEEbRKNSt7__cxx1112basic_stringIT_T0_T1_EEPKS5_,comdat
	.p2align 4
	.weak	_ZSteqIcSt11char_traitsIcESaIcEEbRKNSt7__cxx1112basic_stringIT_T0_T1_EEPKS5_
	.type	_ZSteqIcSt11char_traitsIcESaIcEEbRKNSt7__cxx1112basic_stringIT_T0_T1_EEPKS5_, @function
_ZSteqIcSt11char_traitsIcESaIcEEbRKNSt7__cxx1112basic_stringIT_T0_T1_EEPKS5_:
.LFB14068:
	.cfi_startproc
	push	r12	#
	.cfi_def_cfa_offset 16
	.cfi_offset 12, -16
	mov	r12, rdi	# __lhs, __lhs
	push	rbp	#
	.cfi_def_cfa_offset 24
	.cfi_offset 6, -24
	push	rbx	#
	.cfi_def_cfa_offset 32
	.cfi_offset 3, -32
# /usr/include/c++/15.2.1/bits/basic_string.h:4062:     operator==(const basic_string<_CharT, _Traits, _Alloc>& __lhs,
	mov	rbx, rsi	# __rhs, __rhs
# /usr/include/c++/15.2.1/bits/basic_string.h:4065:       return __lhs.size() == _Traits::length(__rhs)
	call	[QWORD PTR _ZNKSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEE4sizeEv@GOTPCREL[rip]]	#
# /usr/include/c++/15.2.1/bits/basic_string.h:4065:       return __lhs.size() == _Traits::length(__rhs)
	mov	rdi, rbx	#, __rhs
# /usr/include/c++/15.2.1/bits/basic_string.h:4065:       return __lhs.size() == _Traits::length(__rhs)
	mov	rbp, rax	# _1,
# /usr/include/c++/15.2.1/bits/basic_string.h:4065:       return __lhs.size() == _Traits::length(__rhs)
	call	_ZNSt11char_traitsIcE6lengthEPKc	#
# /usr/include/c++/15.2.1/bits/basic_string.h:4066: 	       && !_Traits::compare(__lhs.data(), __rhs, __lhs.size());
	cmp	rbp, rax	# _1,
	je	.L143	#,
# /usr/include/c++/15.2.1/bits/basic_string.h:4067:     }
	pop	rbx	#
	.cfi_remember_state
	.cfi_def_cfa_offset 24
	xor	eax, eax	# <retval>
	pop	rbp	#
	.cfi_def_cfa_offset 16
	pop	r12	#
	.cfi_def_cfa_offset 8
	ret	
	.p2align 4,,10
	.p2align 3
.L143:
	.cfi_restore_state
# /usr/include/c++/15.2.1/bits/basic_string.h:4066: 	       && !_Traits::compare(__lhs.data(), __rhs, __lhs.size());
	mov	rdi, r12	#, __lhs
	call	[QWORD PTR _ZNKSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEE4dataEv@GOTPCREL[rip]]	#
# /usr/include/c++/15.2.1/bits/basic_string.h:4066: 	       && !_Traits::compare(__lhs.data(), __rhs, __lhs.size());
	mov	rdx, rbp	#, _1
	mov	rsi, rbx	#, __rhs
	mov	rdi, rax	#, _2
	call	_ZNSt11char_traitsIcE7compareEPKcS2_m	#
# /usr/include/c++/15.2.1/bits/basic_string.h:4067:     }
	pop	rbx	#
	.cfi_def_cfa_offset 24
	pop	rbp	#
	.cfi_def_cfa_offset 16
# /usr/include/c++/15.2.1/bits/basic_string.h:4066: 	       && !_Traits::compare(__lhs.data(), __rhs, __lhs.size());
	test	eax, eax	# _3
# /usr/include/c++/15.2.1/bits/basic_string.h:4067:     }
	pop	r12	#
	.cfi_def_cfa_offset 8
# /usr/include/c++/15.2.1/bits/basic_string.h:4066: 	       && !_Traits::compare(__lhs.data(), __rhs, __lhs.size());
	sete	al	#, <retval>
# /usr/include/c++/15.2.1/bits/basic_string.h:4067:     }
	ret	
	.cfi_endproc
.LFE14068:
	.size	_ZSteqIcSt11char_traitsIcESaIcEEbRKNSt7__cxx1112basic_stringIT_T0_T1_EEPKS5_, .-_ZSteqIcSt11char_traitsIcESaIcEEbRKNSt7__cxx1112basic_stringIT_T0_T1_EEPKS5_
	.section	.rodata.str1.8
	.align 8
.LC47:
	.base64	"W1NhdmVNYW5hZ2VyXSDQpNCw0LnQuyDQvdC1INC90LDQudC00LXQvTogAA=="
	.section	.rodata.str1.1
.LC48:
	.string	"#"
.LC49:
	.string	"player_x"
.LC50:
	.string	"player_y"
.LC51:
	.string	"player_facing"
.LC52:
	.string	"player_hp"
.LC53:
	.string	"boss_x"
.LC54:
	.string	"boss_y"
.LC55:
	.string	"boss_facing"
.LC56:
	.string	"boss_hp"
.LC57:
	.string	"boss_phase"
.LC58:
	.string	"level_timer"
.LC59:
	.string	"current_level"
.LC60:
	.string	"lives_left"
.LC61:
	.string	"best_stars_0"
.LC62:
	.string	"best_stars_1"
.LC63:
	.string	"best_stars_2"
.LC64:
	.string	"difficulty"
.LC65:
	.string	"attack_mouse"
.LC66:
	.string	"magic_mouse"
.LC67:
	.string	"jump_key"
.LC68:
	.string	"left_key"
.LC69:
	.string	"right_key"
.LC70:
	.string	"crouch_key"
.LC71:
	.string	"interact_key"
.LC72:
	.string	"dash_key"
.LC73:
	.string	"shield_key"
	.section	.text.unlikely
	.align 2
.LCOLDB74:
	.text
.LHOTB74:
	.align 2
	.p2align 4
	.globl	_ZN11SaveManager12readSaveFileERKNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEEER13GameSaveState
	.type	_ZN11SaveManager12readSaveFileERKNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEEER13GameSaveState, @function
_ZN11SaveManager12readSaveFileERKNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEEER13GameSaveState:
.LFB13554:
	.cfi_startproc
	.cfi_personality 0x9b,DW.ref.__gxx_personality_v0
	.cfi_lsda 0x1b,.LLSDA13554
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
	mov	rbx, rsi	# path, path
	sub	rsp, 608	#,
	.cfi_def_cfa_offset 656
# save_manager.cpp:134: bool SaveManager::readSaveFile(const std::string& path, GameSaveState& out) {
	mov	r12, QWORD PTR fs:40	# out, MEM[(<address-space-1> long unsigned int *)40B]
	mov	QWORD PTR 600[rsp], r12	# D.189279, out
	mov	r12, rdx	# out, out
# save_manager.cpp:135:     std::ifstream f(path);
	lea	rbp, 80[rsp]	# tmp300,
	mov	edx, 8	#,
	mov	rdi, rbp	#, tmp300
.LEHB6:
	call	[QWORD PTR _ZNSt14basic_ifstreamIcSt11char_traitsIcEEC1ERKNSt7__cxx1112basic_stringIcS1_SaIcEEESt13_Ios_Openmode@GOTPCREL[rip]]	#
.LEHE6:
# save_manager.cpp:136:     if (!f.is_open()) {
	mov	rdi, rbp	#, tmp300
	call	[QWORD PTR _ZNSt14basic_ifstreamIcSt11char_traitsIcEE7is_openEv@GOTPCREL[rip]]	#
	mov	r13d, eax	# <retval>,
# save_manager.cpp:136:     if (!f.is_open()) {
	test	al, al	# <retval>
	je	.L189	#,
# save_manager.cpp:141:     std::string key;
	lea	rbx, 16[rsp]	# tmp298,
	mov	rdi, rbx	#, tmp298
	call	[QWORD PTR _ZNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEEC1Ev@GOTPCREL[rip]]	#
	.p2align 4
	.p2align 3
.L147:
# save_manager.cpp:142:     while (f >> key) {
	mov	rsi, rbx	#, tmp298
	mov	rdi, rbp	#, tmp300
.LEHB7:
	call	[QWORD PTR _ZStrsIcSt11char_traitsIcESaIcEERSt13basic_istreamIT_T0_ES7_RNSt7__cxx1112basic_stringIS4_S5_T1_EE@GOTPCREL[rip]]	#
# save_manager.cpp:142:     while (f >> key) {
	mov	rdx, QWORD PTR [rax]	# _44->_vptr.basic_istream, _44->_vptr.basic_istream
	add	rax, QWORD PTR -24[rdx]	# _44, MEM[(long int *)_29 + -24B]
	mov	rdi, rax	# _32, _44
	call	[QWORD PTR _ZNKSt9basic_iosIcSt11char_traitsIcEEcvbEv@GOTPCREL[rip]]	#
# save_manager.cpp:142:     while (f >> key) {
	test	al, al	# _45
	je	.L190	#,
# save_manager.cpp:143:         if (key == "#") {
	lea	rsi, .LC48[rip]	#,
	mov	rdi, rbx	#, tmp298
	call	_ZSteqIcSt11char_traitsIcESaIcEEbRKNSt7__cxx1112basic_stringIT_T0_T1_EEPKS5_	#
# save_manager.cpp:143:         if (key == "#") {
	test	al, al	# _47
	jne	.L191	#,
# save_manager.cpp:151:         if      (key == "player_x")      f >> out.player.x;
	lea	rsi, .LC49[rip]	#,
	mov	rdi, rbx	#, tmp298
	call	_ZSteqIcSt11char_traitsIcESaIcEEbRKNSt7__cxx1112basic_stringIT_T0_T1_EEPKS5_	#
# save_manager.cpp:151:         if      (key == "player_x")      f >> out.player.x;
	test	al, al	# _48
	jne	.L192	#,
# save_manager.cpp:152:         else if (key == "player_y")      f >> out.player.y;
	lea	rsi, .LC50[rip]	#,
	mov	rdi, rbx	#, tmp298
	call	_ZSteqIcSt11char_traitsIcESaIcEEbRKNSt7__cxx1112basic_stringIT_T0_T1_EEPKS5_	#
# save_manager.cpp:152:         else if (key == "player_y")      f >> out.player.y;
	test	al, al	# _49
	jne	.L193	#,
# save_manager.cpp:153:         else if (key == "player_facing") { int v; f >> v; out.player.facingRight = (v == 1); }
	lea	rsi, .LC51[rip]	#,
	mov	rdi, rbx	#, tmp298
	call	_ZSteqIcSt11char_traitsIcESaIcEEbRKNSt7__cxx1112basic_stringIT_T0_T1_EEPKS5_	#
# save_manager.cpp:153:         else if (key == "player_facing") { int v; f >> v; out.player.facingRight = (v == 1); }
	test	al, al	# _50
	jne	.L194	#,
# save_manager.cpp:154:         else if (key == "player_hp")     f >> out.player.hp;
	lea	rsi, .LC52[rip]	#,
	mov	rdi, rbx	#, tmp298
	call	_ZSteqIcSt11char_traitsIcESaIcEEbRKNSt7__cxx1112basic_stringIT_T0_T1_EEPKS5_	#
# save_manager.cpp:154:         else if (key == "player_hp")     f >> out.player.hp;
	test	al, al	# _51
	jne	.L195	#,
# save_manager.cpp:155:         else if (key == "boss_x")        f >> out.boss.x;
	lea	rsi, .LC53[rip]	#,
	mov	rdi, rbx	#, tmp298
	call	_ZSteqIcSt11char_traitsIcESaIcEEbRKNSt7__cxx1112basic_stringIT_T0_T1_EEPKS5_	#
# save_manager.cpp:155:         else if (key == "boss_x")        f >> out.boss.x;
	test	al, al	# _52
	jne	.L196	#,
# save_manager.cpp:156:         else if (key == "boss_y")        f >> out.boss.y;
	lea	rsi, .LC54[rip]	#,
	mov	rdi, rbx	#, tmp298
	call	_ZSteqIcSt11char_traitsIcESaIcEEbRKNSt7__cxx1112basic_stringIT_T0_T1_EEPKS5_	#
# save_manager.cpp:156:         else if (key == "boss_y")        f >> out.boss.y;
	test	al, al	# _53
	jne	.L197	#,
# save_manager.cpp:157:         else if (key == "boss_facing")   { int v; f >> v; out.boss.facingRight = (v == 1); }
	lea	rsi, .LC55[rip]	#,
	mov	rdi, rbx	#, tmp298
	call	_ZSteqIcSt11char_traitsIcESaIcEEbRKNSt7__cxx1112basic_stringIT_T0_T1_EEPKS5_	#
# save_manager.cpp:157:         else if (key == "boss_facing")   { int v; f >> v; out.boss.facingRight = (v == 1); }
	test	al, al	# _54
	jne	.L198	#,
# save_manager.cpp:158:         else if (key == "boss_hp")       f >> out.boss.hp;
	lea	rsi, .LC56[rip]	#,
	mov	rdi, rbx	#, tmp298
	call	_ZSteqIcSt11char_traitsIcESaIcEEbRKNSt7__cxx1112basic_stringIT_T0_T1_EEPKS5_	#
# save_manager.cpp:158:         else if (key == "boss_hp")       f >> out.boss.hp;
	test	al, al	# _55
	jne	.L199	#,
# save_manager.cpp:159:         else if (key == "boss_phase")    f >> out.bossPhase;
	lea	rsi, .LC57[rip]	#,
	mov	rdi, rbx	#, tmp298
	call	_ZSteqIcSt11char_traitsIcESaIcEEbRKNSt7__cxx1112basic_stringIT_T0_T1_EEPKS5_	#
# save_manager.cpp:159:         else if (key == "boss_phase")    f >> out.bossPhase;
	test	al, al	# _56
	jne	.L200	#,
# save_manager.cpp:160:         else if (key == "level_timer")   f >> out.levelTimer;
	lea	rsi, .LC58[rip]	#,
	mov	rdi, rbx	#, tmp298
	call	_ZSteqIcSt11char_traitsIcESaIcEEbRKNSt7__cxx1112basic_stringIT_T0_T1_EEPKS5_	#
# save_manager.cpp:160:         else if (key == "level_timer")   f >> out.levelTimer;
	test	al, al	# _57
	jne	.L201	#,
# save_manager.cpp:161:         else if (key == "current_level") f >> out.currentLevel;
	lea	rsi, .LC59[rip]	#,
	mov	rdi, rbx	#, tmp298
	call	_ZSteqIcSt11char_traitsIcESaIcEEbRKNSt7__cxx1112basic_stringIT_T0_T1_EEPKS5_	#
# save_manager.cpp:161:         else if (key == "current_level") f >> out.currentLevel;
	test	al, al	# _58
	jne	.L202	#,
# save_manager.cpp:162:         else if (key == "lives_left")    f >> out.livesLeft;
	lea	rsi, .LC60[rip]	#,
	mov	rdi, rbx	#, tmp298
	call	_ZSteqIcSt11char_traitsIcESaIcEEbRKNSt7__cxx1112basic_stringIT_T0_T1_EEPKS5_	#
# save_manager.cpp:162:         else if (key == "lives_left")    f >> out.livesLeft;
	test	al, al	# _59
	jne	.L203	#,
# save_manager.cpp:163:         else if (key == "best_stars_0")  f >> out.bestStars[0];
	lea	rsi, .LC61[rip]	#,
	mov	rdi, rbx	#, tmp298
	call	_ZSteqIcSt11char_traitsIcESaIcEEbRKNSt7__cxx1112basic_stringIT_T0_T1_EEPKS5_	#
# save_manager.cpp:163:         else if (key == "best_stars_0")  f >> out.bestStars[0];
	test	al, al	# _60
	jne	.L204	#,
# save_manager.cpp:164:         else if (key == "best_stars_1")  f >> out.bestStars[1];
	lea	rsi, .LC62[rip]	#,
	mov	rdi, rbx	#, tmp298
	call	_ZSteqIcSt11char_traitsIcESaIcEEbRKNSt7__cxx1112basic_stringIT_T0_T1_EEPKS5_	#
# save_manager.cpp:164:         else if (key == "best_stars_1")  f >> out.bestStars[1];
	test	al, al	# _61
	jne	.L205	#,
# save_manager.cpp:165:         else if (key == "best_stars_2")  f >> out.bestStars[2];
	lea	rsi, .LC63[rip]	#,
	mov	rdi, rbx	#, tmp298
	call	_ZSteqIcSt11char_traitsIcESaIcEEbRKNSt7__cxx1112basic_stringIT_T0_T1_EEPKS5_	#
# save_manager.cpp:165:         else if (key == "best_stars_2")  f >> out.bestStars[2];
	test	al, al	# _62
	jne	.L206	#,
# save_manager.cpp:166:         else if (key == "difficulty")    f >> out.difficulty;
	lea	rsi, .LC64[rip]	#,
	mov	rdi, rbx	#, tmp298
	call	_ZSteqIcSt11char_traitsIcESaIcEEbRKNSt7__cxx1112basic_stringIT_T0_T1_EEPKS5_	#
# save_manager.cpp:166:         else if (key == "difficulty")    f >> out.difficulty;
	test	al, al	# _63
	jne	.L207	#,
# save_manager.cpp:167:         else if (key == "attack_mouse")  f >> out.attackMouse;
	lea	rsi, .LC65[rip]	#,
	mov	rdi, rbx	#, tmp298
	call	_ZSteqIcSt11char_traitsIcESaIcEEbRKNSt7__cxx1112basic_stringIT_T0_T1_EEPKS5_	#
# save_manager.cpp:167:         else if (key == "attack_mouse")  f >> out.attackMouse;
	test	al, al	# _64
	jne	.L208	#,
# save_manager.cpp:168:         else if (key == "magic_mouse")   f >> out.magicMouse;
	lea	rsi, .LC66[rip]	#,
	mov	rdi, rbx	#, tmp298
	call	_ZSteqIcSt11char_traitsIcESaIcEEbRKNSt7__cxx1112basic_stringIT_T0_T1_EEPKS5_	#
# save_manager.cpp:168:         else if (key == "magic_mouse")   f >> out.magicMouse;
	test	al, al	# _65
	jne	.L209	#,
# save_manager.cpp:169:         else if (key == "jump_key")      f >> out.jumpKey;
	lea	rsi, .LC67[rip]	#,
	mov	rdi, rbx	#, tmp298
	call	_ZSteqIcSt11char_traitsIcESaIcEEbRKNSt7__cxx1112basic_stringIT_T0_T1_EEPKS5_	#
# save_manager.cpp:169:         else if (key == "jump_key")      f >> out.jumpKey;
	test	al, al	# _66
	jne	.L210	#,
# save_manager.cpp:170:         else if (key == "left_key")      f >> out.leftKey;
	lea	rsi, .LC68[rip]	#,
	mov	rdi, rbx	#, tmp298
	call	_ZSteqIcSt11char_traitsIcESaIcEEbRKNSt7__cxx1112basic_stringIT_T0_T1_EEPKS5_	#
# save_manager.cpp:170:         else if (key == "left_key")      f >> out.leftKey;
	test	al, al	# _67
	jne	.L211	#,
# save_manager.cpp:171:         else if (key == "right_key")     f >> out.rightKey;
	lea	rsi, .LC69[rip]	#,
	mov	rdi, rbx	#, tmp298
	call	_ZSteqIcSt11char_traitsIcESaIcEEbRKNSt7__cxx1112basic_stringIT_T0_T1_EEPKS5_	#
# save_manager.cpp:171:         else if (key == "right_key")     f >> out.rightKey;
	test	al, al	# _68
	jne	.L212	#,
# save_manager.cpp:172:         else if (key == "crouch_key")    f >> out.crouchKey;
	lea	rsi, .LC70[rip]	#,
	mov	rdi, rbx	#, tmp298
	call	_ZSteqIcSt11char_traitsIcESaIcEEbRKNSt7__cxx1112basic_stringIT_T0_T1_EEPKS5_	#
# save_manager.cpp:172:         else if (key == "crouch_key")    f >> out.crouchKey;
	test	al, al	# _69
	jne	.L213	#,
# save_manager.cpp:173:         else if (key == "interact_key")  f >> out.interactKey;
	lea	rsi, .LC71[rip]	#,
	mov	rdi, rbx	#, tmp298
	call	_ZSteqIcSt11char_traitsIcESaIcEEbRKNSt7__cxx1112basic_stringIT_T0_T1_EEPKS5_	#
# save_manager.cpp:173:         else if (key == "interact_key")  f >> out.interactKey;
	test	al, al	# _70
	jne	.L214	#,
# save_manager.cpp:174:         else if (key == "dash_key")      f >> out.dashKey;
	lea	rsi, .LC72[rip]	#,
	mov	rdi, rbx	#, tmp298
	call	_ZSteqIcSt11char_traitsIcESaIcEEbRKNSt7__cxx1112basic_stringIT_T0_T1_EEPKS5_	#
# save_manager.cpp:174:         else if (key == "dash_key")      f >> out.dashKey;
	test	al, al	# _71
	jne	.L215	#,
# save_manager.cpp:175:         else if (key == "shield_key")    f >> out.shieldKey;
	lea	rsi, .LC73[rip]	#,
	mov	rdi, rbx	#, tmp298
	call	_ZSteqIcSt11char_traitsIcESaIcEEbRKNSt7__cxx1112basic_stringIT_T0_T1_EEPKS5_	#
# save_manager.cpp:175:         else if (key == "shield_key")    f >> out.shieldKey;
	test	al, al	# _72
	je	.L147	#,
# save_manager.cpp:175:         else if (key == "shield_key")    f >> out.shieldKey;
	lea	rsi, 92[r12]	# _28,
	mov	rdi, rbp	#, tmp300
	call	[QWORD PTR _ZNSirsERi@GOTPCREL[rip]]	#
	jmp	.L147	#
	.p2align 4,,10
	.p2align 3
.L192:
# save_manager.cpp:151:         if      (key == "player_x")      f >> out.player.x;
	mov	rsi, r12	#, out
	mov	rdi, rbp	#, tmp300
	call	[QWORD PTR _ZNSirsERf@GOTPCREL[rip]]	#
.LEHE7:
	jmp	.L147	#
	.p2align 4,,10
	.p2align 3
.L191:
# save_manager.cpp:145:             std::string line;
	lea	rdi, 48[rsp]	#,
	call	[QWORD PTR _ZNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEEC1Ev@GOTPCREL[rip]]	#
# save_manager.cpp:146:             std::getline(f, line);
	lea	rsi, 48[rsp]	#,
	mov	rdi, rbp	#, tmp300
.LEHB8:
	call	[QWORD PTR _ZSt7getlineIcSt11char_traitsIcESaIcEERSt13basic_istreamIT_T0_ES7_RNSt7__cxx1112basic_stringIS4_S5_T1_EE@GOTPCREL[rip]]	#
.LEHE8:
# save_manager.cpp:148:         }
	lea	rdi, 48[rsp]	#,
	call	[QWORD PTR _ZNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEED1Ev@GOTPCREL[rip]]	#
	jmp	.L147	#
	.p2align 4,,10
	.p2align 3
.L193:
# save_manager.cpp:152:         else if (key == "player_y")      f >> out.player.y;
	lea	rsi, 4[r12]	# _3,
	mov	rdi, rbp	#, tmp300
.LEHB9:
	call	[QWORD PTR _ZNSirsERf@GOTPCREL[rip]]	#
	jmp	.L147	#
	.p2align 4,,10
	.p2align 3
.L190:
# save_manager.cpp:179: }
	mov	rdi, rbx	#, tmp298
	call	[QWORD PTR _ZNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEED1Ev@GOTPCREL[rip]]	#
.L146:
# save_manager.cpp:179: }
	mov	rdi, rbp	#, tmp300
	call	[QWORD PTR _ZNSt14basic_ifstreamIcSt11char_traitsIcEED1Ev@GOTPCREL[rip]]	#
# save_manager.cpp:179: }
	mov	rax, QWORD PTR 600[rsp]	# tmp341, D.189279
	sub	rax, QWORD PTR fs:40	# tmp341, MEM[(<address-space-1> long unsigned int *)40B]
	jne	.L216	#,
	add	rsp, 608	#,
	.cfi_remember_state
	.cfi_def_cfa_offset 48
	mov	eax, r13d	#, <retval>
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
.L194:
	.cfi_restore_state
# save_manager.cpp:153:         else if (key == "player_facing") { int v; f >> v; out.player.facingRight = (v == 1); }
	lea	rsi, 12[rsp]	# tmp187,
	mov	rdi, rbp	#, tmp300
	call	[QWORD PTR _ZNSirsERi@GOTPCREL[rip]]	#
# save_manager.cpp:153:         else if (key == "player_facing") { int v; f >> v; out.player.facingRight = (v == 1); }
	cmp	DWORD PTR 12[rsp], 1	# MEM[(int *)_126],
# save_manager.cpp:153:         else if (key == "player_facing") { int v; f >> v; out.player.facingRight = (v == 1); }
	sete	BYTE PTR 8[r12]	#, out_73(D)->player.facingRight
	jmp	.L147	#
	.p2align 4,,10
	.p2align 3
.L195:
# save_manager.cpp:154:         else if (key == "player_hp")     f >> out.player.hp;
	lea	rsi, 12[r12]	# _6,
	mov	rdi, rbp	#, tmp300
	call	[QWORD PTR _ZNSirsERf@GOTPCREL[rip]]	#
.LEHE9:
	jmp	.L147	#
	.p2align 4,,10
	.p2align 3
.L189:
# save_manager.cpp:137:         std::cerr << "[SaveManager] Файл не найден: " << path << "\n";
	lea	rsi, .LC47[rip]	#,
	lea	rdi, _ZSt4cerr[rip]	#,
.LEHB10:
	call	[QWORD PTR _ZStlsISt11char_traitsIcEERSt13basic_ostreamIcT_ES5_PKc@GOTPCREL[rip]]	#
# save_manager.cpp:137:         std::cerr << "[SaveManager] Файл не найден: " << path << "\n";
	mov	rsi, rbx	#, path
	mov	rdi, rax	#, _113
	call	[QWORD PTR _ZStlsIcSt11char_traitsIcESaIcEERSt13basic_ostreamIT_T0_ES7_RKNSt7__cxx1112basic_stringIS4_S5_T1_EE@GOTPCREL[rip]]	#
# save_manager.cpp:137:         std::cerr << "[SaveManager] Файл не найден: " << path << "\n";
	lea	rsi, .LC15[rip]	#,
	mov	rdi, rax	#, _115
	call	[QWORD PTR _ZStlsISt11char_traitsIcEERSt13basic_ostreamIcT_ES5_PKc@GOTPCREL[rip]]	#
.LEHE10:
	jmp	.L146	#
	.p2align 4,,10
	.p2align 3
.L196:
# save_manager.cpp:155:         else if (key == "boss_x")        f >> out.boss.x;
	lea	rsi, 16[r12]	# _7,
	mov	rdi, rbp	#, tmp300
.LEHB11:
	call	[QWORD PTR _ZNSirsERf@GOTPCREL[rip]]	#
	jmp	.L147	#
	.p2align 4,,10
	.p2align 3
.L197:
# save_manager.cpp:156:         else if (key == "boss_y")        f >> out.boss.y;
	lea	rsi, 20[r12]	# _8,
	mov	rdi, rbp	#, tmp300
	call	[QWORD PTR _ZNSirsERf@GOTPCREL[rip]]	#
	jmp	.L147	#
	.p2align 4,,10
	.p2align 3
.L199:
# save_manager.cpp:158:         else if (key == "boss_hp")       f >> out.boss.hp;
	lea	rsi, 28[r12]	# _11,
	mov	rdi, rbp	#, tmp300
	call	[QWORD PTR _ZNSirsERf@GOTPCREL[rip]]	#
	jmp	.L147	#
	.p2align 4,,10
	.p2align 3
.L198:
# save_manager.cpp:157:         else if (key == "boss_facing")   { int v; f >> v; out.boss.facingRight = (v == 1); }
	lea	rsi, 12[rsp]	# tmp204,
	mov	rdi, rbp	#, tmp300
	call	[QWORD PTR _ZNSirsERi@GOTPCREL[rip]]	#
# save_manager.cpp:157:         else if (key == "boss_facing")   { int v; f >> v; out.boss.facingRight = (v == 1); }
	cmp	DWORD PTR 12[rsp], 1	# MEM[(int *)_126],
# save_manager.cpp:157:         else if (key == "boss_facing")   { int v; f >> v; out.boss.facingRight = (v == 1); }
	sete	BYTE PTR 24[r12]	#, out_73(D)->boss.facingRight
	jmp	.L147	#
.L200:
# save_manager.cpp:159:         else if (key == "boss_phase")    f >> out.bossPhase;
	lea	rsi, 32[r12]	# _12,
	mov	rdi, rbp	#, tmp300
	call	[QWORD PTR _ZNSirsERi@GOTPCREL[rip]]	#
	jmp	.L147	#
.L203:
# save_manager.cpp:162:         else if (key == "lives_left")    f >> out.livesLeft;
	lea	rsi, 44[r12]	# _15,
	mov	rdi, rbp	#, tmp300
	call	[QWORD PTR _ZNSirsERi@GOTPCREL[rip]]	#
	jmp	.L147	#
.L201:
# save_manager.cpp:160:         else if (key == "level_timer")   f >> out.levelTimer;
	lea	rsi, 36[r12]	# _13,
	mov	rdi, rbp	#, tmp300
	call	[QWORD PTR _ZNSirsERf@GOTPCREL[rip]]	#
	jmp	.L147	#
.L202:
# save_manager.cpp:161:         else if (key == "current_level") f >> out.currentLevel;
	lea	rsi, 40[r12]	# _14,
	mov	rdi, rbp	#, tmp300
	call	[QWORD PTR _ZNSirsERi@GOTPCREL[rip]]	#
	jmp	.L147	#
.L204:
# save_manager.cpp:163:         else if (key == "best_stars_0")  f >> out.bestStars[0];
	lea	rsi, 48[r12]	# _16,
	mov	rdi, rbp	#, tmp300
	call	[QWORD PTR _ZNSirsERi@GOTPCREL[rip]]	#
	jmp	.L147	#
.L205:
# save_manager.cpp:164:         else if (key == "best_stars_1")  f >> out.bestStars[1];
	lea	rsi, 52[r12]	# _17,
	mov	rdi, rbp	#, tmp300
	call	[QWORD PTR _ZNSirsERi@GOTPCREL[rip]]	#
	jmp	.L147	#
.L206:
# save_manager.cpp:165:         else if (key == "best_stars_2")  f >> out.bestStars[2];
	lea	rsi, 56[r12]	# _18,
	mov	rdi, rbp	#, tmp300
	call	[QWORD PTR _ZNSirsERi@GOTPCREL[rip]]	#
	jmp	.L147	#
.L207:
# save_manager.cpp:166:         else if (key == "difficulty")    f >> out.difficulty;
	lea	rsi, 96[r12]	# _19,
	mov	rdi, rbp	#, tmp300
	call	[QWORD PTR _ZNSirsERi@GOTPCREL[rip]]	#
	jmp	.L147	#
.L208:
# save_manager.cpp:167:         else if (key == "attack_mouse")  f >> out.attackMouse;
	lea	rsi, 60[r12]	# _20,
	mov	rdi, rbp	#, tmp300
	call	[QWORD PTR _ZNSirsERi@GOTPCREL[rip]]	#
	jmp	.L147	#
.L209:
# save_manager.cpp:168:         else if (key == "magic_mouse")   f >> out.magicMouse;
	lea	rsi, 64[r12]	# _21,
	mov	rdi, rbp	#, tmp300
	call	[QWORD PTR _ZNSirsERi@GOTPCREL[rip]]	#
	jmp	.L147	#
.L210:
# save_manager.cpp:169:         else if (key == "jump_key")      f >> out.jumpKey;
	lea	rsi, 68[r12]	# _22,
	mov	rdi, rbp	#, tmp300
	call	[QWORD PTR _ZNSirsERi@GOTPCREL[rip]]	#
	jmp	.L147	#
.L211:
# save_manager.cpp:170:         else if (key == "left_key")      f >> out.leftKey;
	lea	rsi, 72[r12]	# _23,
	mov	rdi, rbp	#, tmp300
	call	[QWORD PTR _ZNSirsERi@GOTPCREL[rip]]	#
	jmp	.L147	#
.L213:
# save_manager.cpp:172:         else if (key == "crouch_key")    f >> out.crouchKey;
	lea	rsi, 80[r12]	# _25,
	mov	rdi, rbp	#, tmp300
	call	[QWORD PTR _ZNSirsERi@GOTPCREL[rip]]	#
	jmp	.L147	#
.L212:
# save_manager.cpp:171:         else if (key == "right_key")     f >> out.rightKey;
	lea	rsi, 76[r12]	# _24,
	mov	rdi, rbp	#, tmp300
	call	[QWORD PTR _ZNSirsERi@GOTPCREL[rip]]	#
	jmp	.L147	#
.L216:
# save_manager.cpp:179: }
	call	[QWORD PTR __stack_chk_fail@GOTPCREL[rip]]	#
.L215:
# save_manager.cpp:174:         else if (key == "dash_key")      f >> out.dashKey;
	lea	rsi, 88[r12]	# _27,
	mov	rdi, rbp	#, tmp300
	call	[QWORD PTR _ZNSirsERi@GOTPCREL[rip]]	#
	jmp	.L147	#
.L214:
# save_manager.cpp:173:         else if (key == "interact_key")  f >> out.interactKey;
	lea	rsi, 84[r12]	# _26,
	mov	rdi, rbp	#, tmp300
	call	[QWORD PTR _ZNSirsERi@GOTPCREL[rip]]	#
.LEHE11:
	jmp	.L147	#
.L181:
# save_manager.cpp:179: }
	mov	r12, rax	# tmp293, tmp340
	jmp	.L178	#
.L182:
	mov	r12, rax	# tmp288, tmp339
	jmp	.L177	#
.L183:
# save_manager.cpp:148:         }
	mov	r12, rax	# tmp338,
	jmp	.L176	#
	.section	.gcc_except_table
.LLSDA13554:
	.byte	0xff
	.byte	0xff
	.byte	0x1
	.uleb128 .LLSDACSE13554-.LLSDACSB13554
.LLSDACSB13554:
	.uleb128 .LEHB6-.LFB13554
	.uleb128 .LEHE6-.LEHB6
	.uleb128 0
	.uleb128 0
	.uleb128 .LEHB7-.LFB13554
	.uleb128 .LEHE7-.LEHB7
	.uleb128 .L182-.LFB13554
	.uleb128 0
	.uleb128 .LEHB8-.LFB13554
	.uleb128 .LEHE8-.LEHB8
	.uleb128 .L183-.LFB13554
	.uleb128 0
	.uleb128 .LEHB9-.LFB13554
	.uleb128 .LEHE9-.LEHB9
	.uleb128 .L182-.LFB13554
	.uleb128 0
	.uleb128 .LEHB10-.LFB13554
	.uleb128 .LEHE10-.LEHB10
	.uleb128 .L181-.LFB13554
	.uleb128 0
	.uleb128 .LEHB11-.LFB13554
	.uleb128 .LEHE11-.LEHB11
	.uleb128 .L182-.LFB13554
	.uleb128 0
.LLSDACSE13554:
	.text
	.cfi_endproc
	.section	.text.unlikely
	.cfi_startproc
	.cfi_personality 0x9b,DW.ref.__gxx_personality_v0
	.cfi_lsda 0x1b,.LLSDAC13554
	.type	_ZN11SaveManager12readSaveFileERKNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEEER13GameSaveState.cold, @function
_ZN11SaveManager12readSaveFileERKNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEEER13GameSaveState.cold:
.LFSB13554:
.L176:
	.cfi_def_cfa_offset 656
	.cfi_offset 3, -48
	.cfi_offset 6, -40
	.cfi_offset 12, -32
	.cfi_offset 13, -24
	.cfi_offset 14, -16
	lea	rdi, 48[rsp]	#,
	call	[QWORD PTR _ZNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEED1Ev@GOTPCREL[rip]]	#
.L177:
# save_manager.cpp:179: }
	mov	rdi, rbx	#, tmp298
	call	[QWORD PTR _ZNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEED1Ev@GOTPCREL[rip]]	#
.L178:
	mov	rdi, rbp	#, tmp300
	call	[QWORD PTR _ZNSt14basic_ifstreamIcSt11char_traitsIcEED1Ev@GOTPCREL[rip]]	#
	mov	rax, QWORD PTR 600[rsp]	# tmp342, D.189279
	sub	rax, QWORD PTR fs:40	# tmp342, MEM[(<address-space-1> long unsigned int *)40B]
	jne	.L217	#,
	mov	rdi, r12	#, tmp293
.LEHB12:
	call	[QWORD PTR _Unwind_Resume@GOTPCREL[rip]]	#
.LEHE12:
.L217:
	call	[QWORD PTR __stack_chk_fail@GOTPCREL[rip]]	#
	.cfi_endproc
.LFE13554:
	.section	.gcc_except_table
.LLSDAC13554:
	.byte	0xff
	.byte	0xff
	.byte	0x1
	.uleb128 .LLSDACSEC13554-.LLSDACSBC13554
.LLSDACSBC13554:
	.uleb128 .LEHB12-.LCOLDB74
	.uleb128 .LEHE12-.LEHB12
	.uleb128 0
	.uleb128 0
.LLSDACSEC13554:
	.section	.text.unlikely
	.text
	.size	_ZN11SaveManager12readSaveFileERKNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEEER13GameSaveState, .-_ZN11SaveManager12readSaveFileERKNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEEER13GameSaveState
	.section	.text.unlikely
	.size	_ZN11SaveManager12readSaveFileERKNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEEER13GameSaveState.cold, .-_ZN11SaveManager12readSaveFileERKNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEEER13GameSaveState.cold
.LCOLDE74:
	.text
.LHOTE74:
	.align 2
	.p2align 4
	.globl	_ZN11SaveManager13loadNamedSaveEi
	.type	_ZN11SaveManager13loadNamedSaveEi, @function
_ZN11SaveManager13loadNamedSaveEi:
.LFB13567:
	.cfi_startproc
	push	r14	#
	.cfi_def_cfa_offset 16
	.cfi_offset 14, -16
	push	rbx	#
	.cfi_def_cfa_offset 24
	.cfi_offset 3, -24
	sub	rsp, 136	#,
	.cfi_def_cfa_offset 160
# save_manager.cpp:270: bool SaveManager::loadNamedSave(int entryIndex) {
	mov	rax, QWORD PTR fs:40	# tmp109, MEM[(<address-space-1> long unsigned int *)40B]
	mov	QWORD PTR 120[rsp], rax	# D.189318, tmp109
	xor	eax, eax	# tmp109
# save_manager.cpp:271:     if (entryIndex < 0 || entryIndex >= (int)entries.size()) return false;
	test	esi, esi	# entryIndex
	js	.L221	#,
	mov	rbx, rdi	# this, this
	mov	edx, esi	# entryIndex, entryIndex
	mov	rdi, QWORD PTR 8[rdi]	# _47, MEM[(struct SaveEntry * *)this_11(D) + 8B]
# save_manager.cpp:271:     if (entryIndex < 0 || entryIndex >= (int)entries.size()) return false;
	mov	rsi, QWORD PTR 16[rbx]	# MEM[(struct SaveEntry * *)this_11(D) + 16B], MEM[(struct SaveEntry * *)this_11(D) + 16B]
	call	_ZNKSt6vectorI9SaveEntrySaIS0_EE4sizeEv.isra.0	#
# save_manager.cpp:271:     if (entryIndex < 0 || entryIndex >= (int)entries.size()) return false;
	cmp	edx, eax	# entryIndex, _2
	jl	.L227	#,
.L221:
# save_manager.cpp:271:     if (entryIndex < 0 || entryIndex >= (int)entries.size()) return false;
	xor	eax, eax	# <retval>
.L218:
# save_manager.cpp:286: }
	mov	rdx, QWORD PTR 120[rsp]	# tmp139, D.189318
	sub	rdx, QWORD PTR fs:40	# tmp139, MEM[(<address-space-1> long unsigned int *)40B]
	jne	.L228	#,
	add	rsp, 136	#,
	.cfi_remember_state
	.cfi_def_cfa_offset 24
	pop	rbx	#
	.cfi_def_cfa_offset 16
	pop	r14	#
	.cfi_def_cfa_offset 8
	ret	
	.p2align 4,,10
	.p2align 3
.L227:
	.cfi_restore_state
# save_manager.cpp:273:     GameSaveState state;
	pxor	xmm0, xmm0	# tmp115
	mov	rax, QWORD PTR .LC77[rip]	# tmp118,
# save_manager.cpp:274:     if (!readSaveFile(entries[entryIndex].filename, state)) return false;
	movsxd	rsi, edx	# _4, entryIndex
# save_manager.cpp:273:     GameSaveState state;
	mov	QWORD PTR 16[rsp], 0	# MEM <vector(2) float> [(float *)&state],
	movups	XMMWORD PTR 56[rsp], xmm0	# MEM <vector(4) int> [(int *)&state + 40B], tmp115
	movdqa	xmm0, XMMWORD PTR .LC75[rip]	# tmp116,
# save_manager.cpp:274:     if (!readSaveFile(entries[entryIndex].filename, state)) return false;
	lea	rdx, 16[rsp]	#,
# save_manager.cpp:273:     GameSaveState state;
	mov	BYTE PTR 24[rsp], 1	# state.player.facingRight,
	movups	XMMWORD PTR 72[rsp], xmm0	# MEM <vector(4) int> [(int *)&state + 56B], tmp116
	movdqa	xmm0, XMMWORD PTR .LC76[rip]	# tmp117,
	mov	QWORD PTR 28[rsp], 0	# MEM <vector(2) float> [(float *)&state + 12B],
	mov	DWORD PTR 36[rsp], 0x00000000	# state.boss.y,
	mov	BYTE PTR 40[rsp], 1	# state.boss.facingRight,
	mov	DWORD PTR 44[rsp], 0x00000000	# state.boss.hp,
	mov	QWORD PTR 48[rsp], 0	# MEM <unsigned long> [(void *)&state + 32B],
	mov	QWORD PTR 104[rsp], rax	# MEM <vector(2) int> [(int *)&state + 88B], tmp118
	mov	DWORD PTR 112[rsp], 2	# state.difficulty,
	movups	XMMWORD PTR 88[rsp], xmm0	# MEM <vector(4) int> [(int *)&state + 72B], tmp117
# save_manager.cpp:274:     if (!readSaveFile(entries[entryIndex].filename, state)) return false;
	call	_ZNSt6vectorI9SaveEntrySaIS0_EEixEm.isra.0	#
# save_manager.cpp:274:     if (!readSaveFile(entries[entryIndex].filename, state)) return false;
	mov	rdi, rbx	#, this
# save_manager.cpp:274:     if (!readSaveFile(entries[entryIndex].filename, state)) return false;
	lea	rsi, 40[rax]	# _6,
# save_manager.cpp:274:     if (!readSaveFile(entries[entryIndex].filename, state)) return false;
	call	_ZN11SaveManager12readSaveFileERKNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEEER13GameSaveState	#
# save_manager.cpp:274:     if (!readSaveFile(entries[entryIndex].filename, state)) return false;
	test	al, al	# <retval>
	je	.L221	#,
# save_manager.cpp:277:     applyProgressToConfig(state);
	lea	rdi, 16[rsp]	#,
	mov	BYTE PTR 15[rsp], al	# %sfp, <retval>
	call	_ZN11SaveManager21applyProgressToConfigERK13GameSaveState	#
# save_manager.cpp:278:     applyControlsToConfig(state);
	lea	rdi, 16[rsp]	#,
	call	_ZN11SaveManager21applyControlsToConfigERK13GameSaveState	#
# save_manager.cpp:281:     writeAutosaveFile(state);
	lea	rsi, 16[rsp]	#,
	mov	rdi, rbx	#, this
	call	_ZN11SaveManager17writeAutosaveFileERK13GameSaveState	#
# save_manager.cpp:282:     lastAutosave = state;
	movdqa	xmm0, XMMWORD PTR 16[rsp]	# state, state
	mov	edx, DWORD PTR 112[rsp]	# state, state
# save_manager.cpp:283:     hasAutosave  = true;
	mov	BYTE PTR 136[rbx], 1	# this_11(D)->hasAutosave,
	movzx	eax, BYTE PTR 15[rsp]	# <retval>, %sfp
# save_manager.cpp:282:     lastAutosave = state;
	movups	XMMWORD PTR 36[rbx], xmm0	# this_11(D)->lastAutosave, state
	movdqa	xmm0, XMMWORD PTR 32[rsp]	# state, state
	mov	DWORD PTR 132[rbx], edx	# this_11(D)->lastAutosave, state
	movups	XMMWORD PTR 52[rbx], xmm0	# this_11(D)->lastAutosave, state
	movdqa	xmm0, XMMWORD PTR 48[rsp]	# state, state
	movups	XMMWORD PTR 68[rbx], xmm0	# this_11(D)->lastAutosave, state
	movdqa	xmm0, XMMWORD PTR 64[rsp]	# state, state
	movups	XMMWORD PTR 84[rbx], xmm0	# this_11(D)->lastAutosave, state
	movdqa	xmm0, XMMWORD PTR 80[rsp]	# state, state
	movups	XMMWORD PTR 100[rbx], xmm0	# this_11(D)->lastAutosave, state
	movdqa	xmm0, XMMWORD PTR 96[rsp]	# state, state
	movups	XMMWORD PTR 116[rbx], xmm0	# this_11(D)->lastAutosave, state
# save_manager.cpp:285:     return true;
	jmp	.L218	#
.L228:
# save_manager.cpp:286: }
	call	[QWORD PTR __stack_chk_fail@GOTPCREL[rip]]	#
	.cfi_endproc
.LFE13567:
	.size	_ZN11SaveManager13loadNamedSaveEi, .-_ZN11SaveManager13loadNamedSaveEi
	.section	.text._ZNSt10filesystem7__cxx114path10_S_convertISt17basic_string_viewIcSt11char_traitsIcEEEEDaT_,"axG",@progbits,_ZNSt10filesystem7__cxx114path10_S_convertISt17basic_string_viewIcSt11char_traitsIcEEEEDaT_,comdat
	.p2align 4
	.weak	_ZNSt10filesystem7__cxx114path10_S_convertISt17basic_string_viewIcSt11char_traitsIcEEEEDaT_
	.type	_ZNSt10filesystem7__cxx114path10_S_convertISt17basic_string_viewIcSt11char_traitsIcEEEEDaT_, @function
_ZNSt10filesystem7__cxx114path10_S_convertISt17basic_string_viewIcSt11char_traitsIcEEEEDaT_:
.LFB14080:
	.cfi_startproc
# /usr/include/c++/15.2.1/bits/fs_path.h:618:       _S_convert(_Tp __str)
	mov	rax, rdi	# __str, __str
	mov	rdx, rsi	# __str, __str
# /usr/include/c++/15.2.1/bits/fs_path.h:633:       }
	ret	
	.cfi_endproc
.LFE14080:
	.size	_ZNSt10filesystem7__cxx114path10_S_convertISt17basic_string_viewIcSt11char_traitsIcEEEEDaT_, .-_ZNSt10filesystem7__cxx114path10_S_convertISt17basic_string_viewIcSt11char_traitsIcEEEEDaT_
	.section	.text._ZNSt6vectorI9SaveEntrySaIS0_EE5beginEv,"axG",@progbits,_ZNSt6vectorI9SaveEntrySaIS0_EE5beginEv,comdat
	.align 2
	.p2align 4
	.weak	_ZNSt6vectorI9SaveEntrySaIS0_EE5beginEv
	.type	_ZNSt6vectorI9SaveEntrySaIS0_EE5beginEv, @function
_ZNSt6vectorI9SaveEntrySaIS0_EE5beginEv:
.LFB14083:
	.cfi_startproc
# /usr/include/c++/15.2.1/bits/stl_vector.h:999:       { return iterator(this->_M_impl._M_start); }
	mov	rax, QWORD PTR [rdi]	# D.187501, MEM[(struct SaveEntry * const &)this_1(D)]
# /usr/include/c++/15.2.1/bits/stl_vector.h:999:       { return iterator(this->_M_impl._M_start); }
	ret	
	.cfi_endproc
.LFE14083:
	.size	_ZNSt6vectorI9SaveEntrySaIS0_EE5beginEv, .-_ZNSt6vectorI9SaveEntrySaIS0_EE5beginEv
	.section	.text._ZNSt6vectorI9SaveEntrySaIS0_EE3endEv,"axG",@progbits,_ZNSt6vectorI9SaveEntrySaIS0_EE3endEv,comdat
	.align 2
	.p2align 4
	.weak	_ZNSt6vectorI9SaveEntrySaIS0_EE3endEv
	.type	_ZNSt6vectorI9SaveEntrySaIS0_EE3endEv, @function
_ZNSt6vectorI9SaveEntrySaIS0_EE3endEv:
.LFB14093:
	.cfi_startproc
# /usr/include/c++/15.2.1/bits/stl_vector.h:1019:       { return iterator(this->_M_impl._M_finish); }
	mov	rax, QWORD PTR 8[rdi]	# D.187504, MEM[(struct SaveEntry * const &)this_1(D) + 8]
# /usr/include/c++/15.2.1/bits/stl_vector.h:1019:       { return iterator(this->_M_impl._M_finish); }
	ret	
	.cfi_endproc
.LFE14093:
	.size	_ZNSt6vectorI9SaveEntrySaIS0_EE3endEv, .-_ZNSt6vectorI9SaveEntrySaIS0_EE3endEv
	.section	.rodata.str1.1
.LC79:
	.string	"saves_index.txt"
	.section	.rodata.str1.8
	.align 8
.LC80:
	.base64	"W1NhdmVNYW5hZ2VyXSDQndC1INC80L7Qs9GDINC30LDQv9C40YHQsNGC0YwgAA=="
	.section	.rodata.str1.1
.LC81:
	.string	"next_number "
.LC82:
	.string	"count "
.LC83:
	.string	"entry "
.LC84:
	.string	" "
	.section	.text.unlikely
	.align 2
.LCOLDB85:
	.text
.LHOTB85:
	.align 2
	.p2align 4
	.globl	_ZN11SaveManager9saveIndexEv
	.type	_ZN11SaveManager9saveIndexEv, @function
_ZN11SaveManager9saveIndexEv:
.LFB13570:
	.cfi_startproc
	.cfi_personality 0x9b,DW.ref.__gxx_personality_v0
	.cfi_lsda 0x1b,.LLSDA13570
	push	r12	#
	.cfi_def_cfa_offset 16
	.cfi_offset 12, -16
# save_manager.cpp:342:     std::ofstream f(INDEX_FILE);
	mov	edx, 16	#,
	lea	rsi, .LC79[rip]	#,
# save_manager.cpp:341: void SaveManager::saveIndex() {
	push	rbp	#
	.cfi_def_cfa_offset 24
	.cfi_offset 6, -24
	push	rbx	#
	.cfi_def_cfa_offset 32
	.cfi_offset 3, -32
	sub	rsp, 528	#,
	.cfi_def_cfa_offset 560
# save_manager.cpp:341: void SaveManager::saveIndex() {
	mov	rbx, QWORD PTR fs:40	# this, MEM[(<address-space-1> long unsigned int *)40B]
	mov	QWORD PTR 520[rsp], rbx	# D.189357, this
	mov	rbx, rdi	# this, this
# save_manager.cpp:342:     std::ofstream f(INDEX_FILE);
	mov	rbp, rsp	# tmp165,
	mov	rdi, rsp	#,
.LEHB13:
	call	[QWORD PTR _ZNSt14basic_ofstreamIcSt11char_traitsIcEEC1EPKcSt13_Ios_Openmode@GOTPCREL[rip]]	#
.LEHE13:
# save_manager.cpp:343:     if (!f.is_open()) {
	mov	rdi, rsp	#,
	call	[QWORD PTR _ZNSt14basic_ofstreamIcSt11char_traitsIcEE7is_openEv@GOTPCREL[rip]]	#
# save_manager.cpp:343:     if (!f.is_open()) {
	test	al, al	# _1
	je	.L244	#,
# save_manager.cpp:348:     f << "next_number " << nextSaveNumber  << "\n";
	lea	rsi, .LC81[rip]	#,
	mov	rdi, rsp	#,
.LEHB14:
	call	[QWORD PTR _ZStlsISt11char_traitsIcEERSt13basic_ostreamIcT_ES5_PKc@GOTPCREL[rip]]	#
# save_manager.cpp:348:     f << "next_number " << nextSaveNumber  << "\n";
	mov	esi, DWORD PTR 32[rbx]	# this_16(D)->nextSaveNumber, this_16(D)->nextSaveNumber
	mov	rdi, rax	#, _15
	call	[QWORD PTR _ZNSolsEi@GOTPCREL[rip]]	#
# save_manager.cpp:348:     f << "next_number " << nextSaveNumber  << "\n";
	lea	rsi, .LC15[rip]	#,
	mov	rdi, rax	#, _18
	call	[QWORD PTR _ZStlsISt11char_traitsIcEERSt13basic_ostreamIcT_ES5_PKc@GOTPCREL[rip]]	#
# save_manager.cpp:349:     f << "count "       << entries.size()  << "\n";
	lea	rsi, .LC82[rip]	#,
	mov	rdi, rsp	#,
	call	[QWORD PTR _ZStlsISt11char_traitsIcEERSt13basic_ostreamIcT_ES5_PKc@GOTPCREL[rip]]	#
# save_manager.cpp:349:     f << "count "       << entries.size()  << "\n";
	mov	rsi, QWORD PTR 16[rbx]	# MEM[(struct SaveEntry * *)this_16(D) + 16B], MEM[(struct SaveEntry * *)this_16(D) + 16B]
	mov	rdi, QWORD PTR 8[rbx]	# MEM[(struct SaveEntry * *)this_16(D) + 8B], MEM[(struct SaveEntry * *)this_16(D) + 8B]
# save_manager.cpp:349:     f << "count "       << entries.size()  << "\n";
	mov	rdx, rax	# _21,
# save_manager.cpp:349:     f << "count "       << entries.size()  << "\n";
	call	_ZNKSt6vectorI9SaveEntrySaIS0_EE4sizeEv.isra.0	#
# save_manager.cpp:349:     f << "count "       << entries.size()  << "\n";
	mov	rdi, rdx	#, _21
	mov	rsi, rax	#, _4
	call	[QWORD PTR _ZNSolsEm@GOTPCREL[rip]]	#
# save_manager.cpp:349:     f << "count "       << entries.size()  << "\n";
	lea	rsi, .LC15[rip]	#,
	mov	rdi, rax	#, _24
	call	[QWORD PTR _ZStlsISt11char_traitsIcEERSt13basic_ostreamIcT_ES5_PKc@GOTPCREL[rip]]	#
# save_manager.cpp:350:     for (const auto& e : entries) {
	lea	rdi, 8[rbx]	#,
	call	_ZNSt6vectorI9SaveEntrySaIS0_EE5beginEv	#
# save_manager.cpp:350:     for (const auto& e : entries) {
	lea	rdi, 8[rbx]	#,
# save_manager.cpp:350:     for (const auto& e : entries) {
	mov	rbx, rax	# __for_begin,
# save_manager.cpp:350:     for (const auto& e : entries) {
	call	_ZNSt6vectorI9SaveEntrySaIS0_EE3endEv	#
	mov	r12, rax	# SR.635,
# save_manager.cpp:350:     for (const auto& e : entries) {
	cmp	rbx, rax	# __for_begin, SR.635
	je	.L236	#,
	.p2align 4
	.p2align 3
.L235:
# save_manager.cpp:352:         f << "entry " << e.number << " " << e.filename << " " << e.name << "\n";
	lea	rsi, .LC83[rip]	#,
	mov	rdi, rbp	#, tmp165
	call	[QWORD PTR _ZStlsISt11char_traitsIcEERSt13basic_ostreamIcT_ES5_PKc@GOTPCREL[rip]]	#
# save_manager.cpp:352:         f << "entry " << e.number << " " << e.filename << " " << e.name << "\n";
	mov	esi, DWORD PTR [rbx]	# MEM[(int *)_69], MEM[(int *)_69]
	mov	rdi, rax	#, _32
	call	[QWORD PTR _ZNSolsEi@GOTPCREL[rip]]	#
# save_manager.cpp:352:         f << "entry " << e.number << " " << e.filename << " " << e.name << "\n";
	lea	rsi, .LC84[rip]	#,
	mov	rdi, rax	#, _34
	call	[QWORD PTR _ZStlsISt11char_traitsIcEERSt13basic_ostreamIcT_ES5_PKc@GOTPCREL[rip]]	#
# save_manager.cpp:352:         f << "entry " << e.number << " " << e.filename << " " << e.name << "\n";
	lea	rsi, 40[rbx]	# _68,
# save_manager.cpp:352:         f << "entry " << e.number << " " << e.filename << " " << e.name << "\n";
	mov	rdi, rax	#, _36
	call	[QWORD PTR _ZStlsIcSt11char_traitsIcESaIcEERSt13basic_ostreamIT_T0_ES7_RKNSt7__cxx1112basic_stringIS4_S5_T1_EE@GOTPCREL[rip]]	#
# save_manager.cpp:352:         f << "entry " << e.number << " " << e.filename << " " << e.name << "\n";
	lea	rsi, .LC84[rip]	#,
	mov	rdi, rax	#, _38
	call	[QWORD PTR _ZStlsISt11char_traitsIcEERSt13basic_ostreamIcT_ES5_PKc@GOTPCREL[rip]]	#
# save_manager.cpp:352:         f << "entry " << e.number << " " << e.filename << " " << e.name << "\n";
	lea	rsi, 8[rbx]	# _67,
# save_manager.cpp:352:         f << "entry " << e.number << " " << e.filename << " " << e.name << "\n";
	mov	rdi, rax	#, _40
	call	[QWORD PTR _ZStlsIcSt11char_traitsIcESaIcEERSt13basic_ostreamIT_T0_ES7_RKNSt7__cxx1112basic_stringIS4_S5_T1_EE@GOTPCREL[rip]]	#
# save_manager.cpp:352:         f << "entry " << e.number << " " << e.filename << " " << e.name << "\n";
	lea	rsi, .LC15[rip]	#,
	mov	rdi, rax	#, _42
	call	[QWORD PTR _ZStlsISt11char_traitsIcEERSt13basic_ostreamIcT_ES5_PKc@GOTPCREL[rip]]	#
# save_manager.cpp:350:     for (const auto& e : entries) {
	add	rbx, 72	# ivtmp.641,
	cmp	r12, rbx	# SR.635, ivtmp.641
	jne	.L235	#,
.L236:
# save_manager.cpp:354: }
	mov	rdi, rbp	#, tmp165
	call	[QWORD PTR _ZNSt14basic_ofstreamIcSt11char_traitsIcEED1Ev@GOTPCREL[rip]]	#
	mov	rax, QWORD PTR 520[rsp]	# tmp185, D.189357
	sub	rax, QWORD PTR fs:40	# tmp185, MEM[(<address-space-1> long unsigned int *)40B]
	jne	.L245	#,
	add	rsp, 528	#,
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
.L244:
	.cfi_restore_state
# save_manager.cpp:344:         std::cerr << "[SaveManager] Не могу записать " << INDEX_FILE << "\n";
	lea	rsi, .LC80[rip]	#,
	lea	rdi, _ZSt4cerr[rip]	#,
	call	[QWORD PTR _ZStlsISt11char_traitsIcEERSt13basic_ostreamIcT_ES5_PKc@GOTPCREL[rip]]	#
# save_manager.cpp:344:         std::cerr << "[SaveManager] Не могу записать " << INDEX_FILE << "\n";
	lea	rsi, .LC79[rip]	#,
	mov	rdi, rax	#, _46
	call	[QWORD PTR _ZStlsISt11char_traitsIcEERSt13basic_ostreamIcT_ES5_PKc@GOTPCREL[rip]]	#
# save_manager.cpp:344:         std::cerr << "[SaveManager] Не могу записать " << INDEX_FILE << "\n";
	lea	rsi, .LC15[rip]	#,
	mov	rdi, rax	#, _48
	call	[QWORD PTR _ZStlsISt11char_traitsIcEERSt13basic_ostreamIcT_ES5_PKc@GOTPCREL[rip]]	#
.LEHE14:
	jmp	.L236	#
.L245:
# save_manager.cpp:354: }
	call	[QWORD PTR __stack_chk_fail@GOTPCREL[rip]]	#
.L240:
	mov	rbx, rax	# tmp184,
	jmp	.L237	#
	.section	.gcc_except_table
.LLSDA13570:
	.byte	0xff
	.byte	0xff
	.byte	0x1
	.uleb128 .LLSDACSE13570-.LLSDACSB13570
.LLSDACSB13570:
	.uleb128 .LEHB13-.LFB13570
	.uleb128 .LEHE13-.LEHB13
	.uleb128 0
	.uleb128 0
	.uleb128 .LEHB14-.LFB13570
	.uleb128 .LEHE14-.LEHB14
	.uleb128 .L240-.LFB13570
	.uleb128 0
.LLSDACSE13570:
	.text
	.cfi_endproc
	.section	.text.unlikely
	.cfi_startproc
	.cfi_personality 0x9b,DW.ref.__gxx_personality_v0
	.cfi_lsda 0x1b,.LLSDAC13570
	.type	_ZN11SaveManager9saveIndexEv.cold, @function
_ZN11SaveManager9saveIndexEv.cold:
.LFSB13570:
.L237:
	.cfi_def_cfa_offset 560
	.cfi_offset 3, -32
	.cfi_offset 6, -24
	.cfi_offset 12, -16
	mov	rdi, rbp	#, tmp165
	call	[QWORD PTR _ZNSt14basic_ofstreamIcSt11char_traitsIcEED1Ev@GOTPCREL[rip]]	#
	mov	rax, QWORD PTR 520[rsp]	# tmp186, D.189357
	sub	rax, QWORD PTR fs:40	# tmp186, MEM[(<address-space-1> long unsigned int *)40B]
	jne	.L246	#,
	mov	rdi, rbx	#, tmp184
.LEHB15:
	call	[QWORD PTR _Unwind_Resume@GOTPCREL[rip]]	#
.LEHE15:
.L246:
	call	[QWORD PTR __stack_chk_fail@GOTPCREL[rip]]	#
	.cfi_endproc
.LFE13570:
	.section	.gcc_except_table
.LLSDAC13570:
	.byte	0xff
	.byte	0xff
	.byte	0x1
	.uleb128 .LLSDACSEC13570-.LLSDACSBC13570
.LLSDACSBC13570:
	.uleb128 .LEHB15-.LCOLDB85
	.uleb128 .LEHE15-.LEHB15
	.uleb128 0
	.uleb128 0
.LLSDACSEC13570:
	.section	.text.unlikely
	.text
	.size	_ZN11SaveManager9saveIndexEv, .-_ZN11SaveManager9saveIndexEv
	.section	.text.unlikely
	.size	_ZN11SaveManager9saveIndexEv.cold, .-_ZN11SaveManager9saveIndexEv.cold
.LCOLDE85:
	.text
.LHOTE85:
	.section	.text._ZNSt12_Vector_baseI9SaveEntrySaIS0_EE19_M_get_Tp_allocatorEv,"axG",@progbits,_ZNSt12_Vector_baseI9SaveEntrySaIS0_EE19_M_get_Tp_allocatorEv,comdat
	.align 2
	.p2align 4
	.weak	_ZNSt12_Vector_baseI9SaveEntrySaIS0_EE19_M_get_Tp_allocatorEv
	.type	_ZNSt12_Vector_baseI9SaveEntrySaIS0_EE19_M_get_Tp_allocatorEv, @function
_ZNSt12_Vector_baseI9SaveEntrySaIS0_EE19_M_get_Tp_allocatorEv:
.LFB14281:
	.cfi_startproc
# /usr/include/c++/15.2.1/bits/stl_vector.h:307:       _M_get_Tp_allocator() _GLIBCXX_NOEXCEPT
	mov	rax, rdi	# this, this
# /usr/include/c++/15.2.1/bits/stl_vector.h:308:       { return this->_M_impl; }
	ret	
	.cfi_endproc
.LFE14281:
	.size	_ZNSt12_Vector_baseI9SaveEntrySaIS0_EE19_M_get_Tp_allocatorEv, .-_ZNSt12_Vector_baseI9SaveEntrySaIS0_EE19_M_get_Tp_allocatorEv
	.section	.text._ZNSt10filesystem7__cxx118__detail17__effective_rangeIcSt11char_traitsIcESaIcEEESt17basic_string_viewIT_S3_IS7_EERKNSt7__cxx1112basic_stringIS7_T0_T1_EE,"axG",@progbits,_ZNSt10filesystem7__cxx118__detail17__effective_rangeIcSt11char_traitsIcESaIcEEESt17basic_string_viewIT_S3_IS7_EERKNSt7__cxx1112basic_stringIS7_T0_T1_EE,comdat
	.p2align 4
	.weak	_ZNSt10filesystem7__cxx118__detail17__effective_rangeIcSt11char_traitsIcESaIcEEESt17basic_string_viewIT_S3_IS7_EERKNSt7__cxx1112basic_stringIS7_T0_T1_EE
	.type	_ZNSt10filesystem7__cxx118__detail17__effective_rangeIcSt11char_traitsIcESaIcEEESt17basic_string_viewIT_S3_IS7_EERKNSt7__cxx1112basic_stringIS7_T0_T1_EE, @function
_ZNSt10filesystem7__cxx118__detail17__effective_rangeIcSt11char_traitsIcESaIcEEESt17basic_string_viewIT_S3_IS7_EERKNSt7__cxx1112basic_stringIS7_T0_T1_EE:
.LFB14418:
	.cfi_startproc
# /usr/include/c++/15.2.1/bits/fs_path.h:185:     { return __source; }
	jmp	[QWORD PTR _ZNKSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEEcvSt17basic_string_viewIcS2_EEv@GOTPCREL[rip]]	#
	.cfi_endproc
.LFE14418:
	.size	_ZNSt10filesystem7__cxx118__detail17__effective_rangeIcSt11char_traitsIcESaIcEEESt17basic_string_viewIT_S3_IS7_EERKNSt7__cxx1112basic_stringIS7_T0_T1_EE, .-_ZNSt10filesystem7__cxx118__detail17__effective_rangeIcSt11char_traitsIcESaIcEEESt17basic_string_viewIT_S3_IS7_EERKNSt7__cxx1112basic_stringIS7_T0_T1_EE
	.section	.text._ZNKSt6vectorI9SaveEntrySaIS0_EE6cbeginEv,"axG",@progbits,_ZNKSt6vectorI9SaveEntrySaIS0_EE6cbeginEv,comdat
	.align 2
	.p2align 4
	.weak	_ZNKSt6vectorI9SaveEntrySaIS0_EE6cbeginEv
	.type	_ZNKSt6vectorI9SaveEntrySaIS0_EE6cbeginEv, @function
_ZNKSt6vectorI9SaveEntrySaIS0_EE6cbeginEv:
.LFB14425:
	.cfi_startproc
# /usr/include/c++/15.2.1/bits/stl_vector.h:1080:       { return const_iterator(this->_M_impl._M_start); }
	mov	rax, QWORD PTR [rdi]	# D.187709, MEM[(const struct SaveEntry * const &)this_1(D)]
# /usr/include/c++/15.2.1/bits/stl_vector.h:1080:       { return const_iterator(this->_M_impl._M_start); }
	ret	
	.cfi_endproc
.LFE14425:
	.size	_ZNKSt6vectorI9SaveEntrySaIS0_EE6cbeginEv, .-_ZNKSt6vectorI9SaveEntrySaIS0_EE6cbeginEv
	.section	.text._ZNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEE13_S_copy_charsIPKcEEvPcT_S9_,"axG",@progbits,_ZNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEE13_S_copy_charsIPKcEEvPcT_S9_,comdat
	.p2align 4
	.weak	_ZNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEE13_S_copy_charsIPKcEEvPcT_S9_
	.type	_ZNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEE13_S_copy_charsIPKcEEvPcT_S9_, @function
_ZNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEE13_S_copy_charsIPKcEEvPcT_S9_:
.LFB14477:
	.cfi_startproc
# /usr/include/c++/15.2.1/bits/basic_string.h:489: 	    _S_copy(__p, std::__niter_base(__k1), __k2 - __k1);
	sub	rdx, rsi	# _1, __k1
# /usr/include/c++/15.2.1/bits/basic_string.h:489: 	    _S_copy(__p, std::__niter_base(__k1), __k2 - __k1);
	jmp	[QWORD PTR _ZNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEE7_S_copyEPcPKcm@GOTPCREL[rip]]	#
	.cfi_endproc
.LFE14477:
	.size	_ZNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEE13_S_copy_charsIPKcEEvPcT_S9_, .-_ZNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEE13_S_copy_charsIPKcEEvPcT_S9_
	.text
	.align 2
	.p2align 4
	.type	_ZNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEE12_M_constructIPKcEEvT_S8_St20forward_iterator_tag.isra.0, @function
_ZNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEE12_M_constructIPKcEEvT_S8_St20forward_iterator_tag.isra.0:
.LFB14838:
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
	mov	QWORD PTR 8[rsp], r12	# D.189388, __end
	mov	r12, rdx	# __end, __end
# /usr/include/c++/15.2.1/bits/basic_string.tcc:231: 	size_type __dnew = static_cast<size_type>(std::distance(__beg, __end));
	mov	QWORD PTR [rsp], rax	# __dnew, _4
# /usr/include/c++/15.2.1/bits/basic_string.tcc:233: 	if (__dnew > size_type(_S_local_capacity))
	cmp	rax, 15	# _4,
	ja	.L255	#,
.L252:
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
	mov	rax, QWORD PTR 8[rsp]	# tmp118, D.189388
	sub	rax, QWORD PTR fs:40	# tmp118, MEM[(<address-space-1> long unsigned int *)40B]
	jne	.L256	#,
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
.L255:
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
	jmp	.L252	#
.L256:
# /usr/include/c++/15.2.1/bits/basic_string.tcc:258:       }
	call	[QWORD PTR __stack_chk_fail@GOTPCREL[rip]]	#
	.cfi_endproc
.LFE14838:
	.size	_ZNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEE12_M_constructIPKcEEvT_S8_St20forward_iterator_tag.isra.0, .-_ZNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEE12_M_constructIPKcEEvT_S8_St20forward_iterator_tag.isra.0
	.section	.rodata._ZNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEEC2IS3_EEPKcRKS3_.str1.8,"aMS",@progbits,1
	.align 8
.LC86:
	.string	"basic_string: construction from null is not valid"
	.section	.text._ZNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEEC2IS3_EEPKcRKS3_,"axG",@progbits,_ZNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEEC5IS3_EEPKcRKS3_,comdat
	.align 2
	.p2align 4
	.weak	_ZNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEEC2IS3_EEPKcRKS3_
	.type	_ZNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEEC2IS3_EEPKcRKS3_, @function
_ZNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEEC2IS3_EEPKcRKS3_:
.LFB13904:
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
	je	.L260	#,
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
.L260:
	.cfi_restore_state
# /usr/include/c++/15.2.1/bits/basic_string.h:711: 	  std::__throw_logic_error(__N("basic_string: "
	lea	rdi, .LC86[rip]	#,
	call	[QWORD PTR _ZSt19__throw_logic_errorPKc@GOTPCREL[rip]]	#
	.cfi_endproc
.LFE13904:
	.size	_ZNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEEC2IS3_EEPKcRKS3_, .-_ZNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEEC2IS3_EEPKcRKS3_
	.weak	_ZNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEEC1IS3_EEPKcRKS3_
	.set	_ZNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEEC1IS3_EEPKcRKS3_,_ZNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEEC2IS3_EEPKcRKS3_
	.section	.text.unlikely
	.align 2
.LCOLDB87:
	.text
.LHOTB87:
	.align 2
	.p2align 4
	.globl	_ZN11SaveManager12loadAutosaveER13GameSaveState
	.type	_ZN11SaveManager12loadAutosaveER13GameSaveState, @function
_ZN11SaveManager12loadAutosaveER13GameSaveState:
.LFB13557:
	.cfi_startproc
	.cfi_personality 0x9b,DW.ref.__gxx_personality_v0
	.cfi_lsda 0x1b,.LLSDA13557
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
	sub	rsp, 64	#,
	.cfi_def_cfa_offset 96
# save_manager.cpp:201: bool SaveManager::loadAutosave(GameSaveState& outState) {
	mov	r12, QWORD PTR fs:40	# outState, MEM[(<address-space-1> long unsigned int *)40B]
	mov	QWORD PTR 56[rsp], r12	# D.189401, outState
	mov	r12, rsi	# outState, outState
# save_manager.cpp:202:     return readSaveFile(AUTOSAVE_FILE, outState);
	lea	rdx, 15[rsp]	# tmp104,
	lea	rsi, .LC13[rip]	#,
	lea	rdi, 16[rsp]	#,
.LEHB16:
	call	_ZNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEEC1IS3_EEPKcRKS3_	#
.LEHE16:
# save_manager.cpp:202:     return readSaveFile(AUTOSAVE_FILE, outState);
	lea	rsi, 16[rsp]	#,
	mov	rdi, rbp	#, this
	mov	rdx, r12	#, outState
.LEHB17:
	call	_ZN11SaveManager12readSaveFileERKNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEEER13GameSaveState	#
.LEHE17:
	mov	ebp, eax	# <retval>,
# save_manager.cpp:202:     return readSaveFile(AUTOSAVE_FILE, outState);
	lea	rdi, 16[rsp]	#,
	call	[QWORD PTR _ZNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEED1Ev@GOTPCREL[rip]]	#
# save_manager.cpp:203: }
	mov	rax, QWORD PTR 56[rsp]	# tmp119, D.189401
	sub	rax, QWORD PTR fs:40	# tmp119, MEM[(<address-space-1> long unsigned int *)40B]
	jne	.L268	#,
	add	rsp, 64	#,
	.cfi_remember_state
	.cfi_def_cfa_offset 32
	mov	eax, ebp	#, <retval>
	pop	rbx	#
	.cfi_def_cfa_offset 24
	pop	rbp	#
	.cfi_def_cfa_offset 16
	pop	r12	#
	.cfi_def_cfa_offset 8
	ret	
.L268:
	.cfi_restore_state
	call	[QWORD PTR __stack_chk_fail@GOTPCREL[rip]]	#
.L265:
# save_manager.cpp:202:     return readSaveFile(AUTOSAVE_FILE, outState);
	mov	rbp, rax	# tmp118,
	jmp	.L262	#
	.section	.gcc_except_table
.LLSDA13557:
	.byte	0xff
	.byte	0xff
	.byte	0x1
	.uleb128 .LLSDACSE13557-.LLSDACSB13557
.LLSDACSB13557:
	.uleb128 .LEHB16-.LFB13557
	.uleb128 .LEHE16-.LEHB16
	.uleb128 0
	.uleb128 0
	.uleb128 .LEHB17-.LFB13557
	.uleb128 .LEHE17-.LEHB17
	.uleb128 .L265-.LFB13557
	.uleb128 0
.LLSDACSE13557:
	.text
	.cfi_endproc
	.section	.text.unlikely
	.cfi_startproc
	.cfi_personality 0x9b,DW.ref.__gxx_personality_v0
	.cfi_lsda 0x1b,.LLSDAC13557
	.type	_ZN11SaveManager12loadAutosaveER13GameSaveState.cold, @function
_ZN11SaveManager12loadAutosaveER13GameSaveState.cold:
.LFSB13557:
.L262:
	.cfi_def_cfa_offset 96
	.cfi_offset 3, -32
	.cfi_offset 6, -24
	.cfi_offset 12, -16
	lea	rdi, 16[rsp]	#,
	call	[QWORD PTR _ZNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEED1Ev@GOTPCREL[rip]]	#
	mov	rax, QWORD PTR 56[rsp]	# tmp120, D.189401
	sub	rax, QWORD PTR fs:40	# tmp120, MEM[(<address-space-1> long unsigned int *)40B]
	jne	.L269	#,
	mov	rdi, rbp	#, tmp118
.LEHB18:
	call	[QWORD PTR _Unwind_Resume@GOTPCREL[rip]]	#
.LEHE18:
.L269:
	call	[QWORD PTR __stack_chk_fail@GOTPCREL[rip]]	#
	.cfi_endproc
.LFE13557:
	.section	.gcc_except_table
.LLSDAC13557:
	.byte	0xff
	.byte	0xff
	.byte	0x1
	.uleb128 .LLSDACSEC13557-.LLSDACSBC13557
.LLSDACSBC13557:
	.uleb128 .LEHB18-.LCOLDB87
	.uleb128 .LEHE18-.LEHB18
	.uleb128 0
	.uleb128 0
.LLSDACSEC13557:
	.section	.text.unlikely
	.text
	.size	_ZN11SaveManager12loadAutosaveER13GameSaveState, .-_ZN11SaveManager12loadAutosaveER13GameSaveState
	.section	.text.unlikely
	.size	_ZN11SaveManager12loadAutosaveER13GameSaveState.cold, .-_ZN11SaveManager12loadAutosaveER13GameSaveState.cold
.LCOLDE87:
	.text
.LHOTE87:
	.section	.rodata.str1.8
	.align 8
.LC88:
	.base64	"W1NhdmVNYW5hZ2VyXSBvdmVyd3JpdGU6IGF1dG9zYXZlINC90LUg0L3QsNC50LTQtdC9CgA="
	.section	.text.unlikely
	.align 2
.LCOLDB89:
	.text
.LHOTB89:
	.align 2
	.p2align 4
	.globl	_ZN11SaveManager18overwriteNamedSaveEi
	.type	_ZN11SaveManager18overwriteNamedSaveEi, @function
_ZN11SaveManager18overwriteNamedSaveEi:
.LFB13566:
	.cfi_startproc
	.cfi_personality 0x9b,DW.ref.__gxx_personality_v0
	.cfi_lsda 0x1b,.LLSDA13566
	push	r15	#
	.cfi_def_cfa_offset 16
	.cfi_offset 15, -16
	push	r14	#
	.cfi_def_cfa_offset 24
	.cfi_offset 14, -24
	push	r12	#
	.cfi_def_cfa_offset 32
	.cfi_offset 12, -32
	push	rbp	#
	.cfi_def_cfa_offset 40
	.cfi_offset 6, -40
	push	rbx	#
	.cfi_def_cfa_offset 48
	.cfi_offset 3, -48
	sub	rsp, 160	#,
	.cfi_def_cfa_offset 208
# save_manager.cpp:252: bool SaveManager::overwriteNamedSave(int entryIndex) {
	mov	rax, QWORD PTR fs:40	# tmp116, MEM[(<address-space-1> long unsigned int *)40B]
	mov	QWORD PTR 152[rsp], rax	# D.189416, tmp116
	xor	eax, eax	# tmp116
# save_manager.cpp:253:     if (entryIndex < 0 || entryIndex >= (int)entries.size()) return false;
	test	esi, esi	# entryIndex
	js	.L271	#,
	mov	ebx, esi	# entryIndex, entryIndex
	mov	rbp, rdi	# this, this
# save_manager.cpp:253:     if (entryIndex < 0 || entryIndex >= (int)entries.size()) return false;
	mov	rsi, QWORD PTR 16[rdi]	# MEM[(struct SaveEntry * *)this_17(D) + 16B], MEM[(struct SaveEntry * *)this_17(D) + 16B]
	mov	rdi, QWORD PTR 8[rdi]	# MEM[(struct SaveEntry * *)this_17(D) + 8B], MEM[(struct SaveEntry * *)this_17(D) + 8B]
	call	_ZNKSt6vectorI9SaveEntrySaIS0_EE4sizeEv.isra.0	#
# save_manager.cpp:253:     if (entryIndex < 0 || entryIndex >= (int)entries.size()) return false;
	cmp	ebx, eax	# entryIndex, _2
	jl	.L279	#,
.L271:
# save_manager.cpp:253:     if (entryIndex < 0 || entryIndex >= (int)entries.size()) return false;
	xor	r12d, r12d	# <retval>
.L270:
# save_manager.cpp:268: }
	mov	rax, QWORD PTR 152[rsp]	# tmp159, D.189416
	sub	rax, QWORD PTR fs:40	# tmp159, MEM[(<address-space-1> long unsigned int *)40B]
	jne	.L280	#,
	add	rsp, 160	#,
	.cfi_remember_state
	.cfi_def_cfa_offset 48
	mov	eax, r12d	#, <retval>
	pop	rbx	#
	.cfi_def_cfa_offset 40
	pop	rbp	#
	.cfi_def_cfa_offset 32
	pop	r12	#
	.cfi_def_cfa_offset 24
	pop	r14	#
	.cfi_def_cfa_offset 16
	pop	r15	#
	.cfi_def_cfa_offset 8
	ret	
	.p2align 4,,10
	.p2align 3
.L279:
	.cfi_restore_state
# save_manager.cpp:255:     GameSaveState state;
	pxor	xmm0, xmm0	# tmp123
	mov	rax, QWORD PTR .LC77[rip]	# tmp126,
# save_manager.cpp:256:     if (!readSaveFile(AUTOSAVE_FILE, state)) {
	lea	rdx, 15[rsp]	# tmp127,
	lea	rsi, .LC13[rip]	#,
# save_manager.cpp:255:     GameSaveState state;
	movups	XMMWORD PTR 88[rsp], xmm0	# MEM <vector(4) int> [(int *)&state + 40B], tmp123
	movdqa	xmm0, XMMWORD PTR .LC75[rip]	# tmp124,
# save_manager.cpp:256:     if (!readSaveFile(AUTOSAVE_FILE, state)) {
	lea	rdi, 16[rsp]	#,
# save_manager.cpp:255:     GameSaveState state;
	mov	QWORD PTR 48[rsp], 0	# MEM <vector(2) float> [(float *)&state],
	movups	XMMWORD PTR 104[rsp], xmm0	# MEM <vector(4) int> [(int *)&state + 56B], tmp124
	movdqa	xmm0, XMMWORD PTR .LC76[rip]	# tmp125,
	mov	BYTE PTR 56[rsp], 1	# state.player.facingRight,
	mov	QWORD PTR 60[rsp], 0	# MEM <vector(2) float> [(float *)&state + 12B],
	mov	DWORD PTR 68[rsp], 0x00000000	# state.boss.y,
	mov	BYTE PTR 72[rsp], 1	# state.boss.facingRight,
	mov	DWORD PTR 76[rsp], 0x00000000	# state.boss.hp,
	mov	QWORD PTR 80[rsp], 0	# MEM <unsigned long> [(void *)&state + 32B],
	mov	QWORD PTR 136[rsp], rax	# MEM <vector(2) int> [(int *)&state + 88B], tmp126
	mov	DWORD PTR 144[rsp], 2	# state.difficulty,
	movups	XMMWORD PTR 120[rsp], xmm0	# MEM <vector(4) int> [(int *)&state + 72B], tmp125
.LEHB19:
# save_manager.cpp:256:     if (!readSaveFile(AUTOSAVE_FILE, state)) {
	call	_ZNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEEC1IS3_EEPKcRKS3_	#
.LEHE19:
# save_manager.cpp:256:     if (!readSaveFile(AUTOSAVE_FILE, state)) {
	lea	rdx, 48[rsp]	#,
	lea	rsi, 16[rsp]	#,
	mov	rdi, rbp	#, this
.LEHB20:
	call	_ZN11SaveManager12readSaveFileERKNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEEER13GameSaveState	#
.LEHE20:
	mov	r12d, eax	# <retval>, <retval>
# save_manager.cpp:256:     if (!readSaveFile(AUTOSAVE_FILE, state)) {
	lea	rdi, 16[rsp]	#,
	call	[QWORD PTR _ZNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEED1Ev@GOTPCREL[rip]]	#
# save_manager.cpp:256:     if (!readSaveFile(AUTOSAVE_FILE, state)) {
	test	r12b, r12b	# <retval>
	je	.L281	#,
# save_manager.cpp:261:     fillControlsFromConfig(state);
	lea	rdi, 48[rsp]	#,
.LEHB21:
	call	_ZN11SaveManager22fillControlsFromConfigER13GameSaveState	#
# save_manager.cpp:263:         state.bestStars[i] = Config::getLevelStars(i);
	xor	edi, edi	#
	call	_ZN6Config13getLevelStarsEi	#
	mov	edi, 1	#,
# save_manager.cpp:263:         state.bestStars[i] = Config::getLevelStars(i);
	mov	DWORD PTR 96[rsp], eax	# state.bestStars[0], _65
# save_manager.cpp:263:         state.bestStars[i] = Config::getLevelStars(i);
	call	_ZN6Config13getLevelStarsEi	#
	mov	edi, 2	#,
# save_manager.cpp:263:         state.bestStars[i] = Config::getLevelStars(i);
	mov	DWORD PTR 100[rsp], eax	# state.bestStars[1], _72
# save_manager.cpp:263:         state.bestStars[i] = Config::getLevelStars(i);
	call	_ZN6Config13getLevelStarsEi	#
# save_manager.cpp:263:         state.bestStars[i] = Config::getLevelStars(i);
	mov	DWORD PTR 104[rsp], eax	# state.bestStars[2], _4
# save_manager.cpp:264:     state.difficulty = Config::getCurrentDifficulty();
	call	_ZN6Config20getCurrentDifficultyEv	#
# save_manager.cpp:266:     writeSaveFile(entries[entryIndex].filename, state, entries[entryIndex].name);
	mov	rdi, QWORD PTR 8[rbp]	# MEM[(struct SaveEntry * *)this_17(D) + 8B], MEM[(struct SaveEntry * *)this_17(D) + 8B]
	movsxd	rsi, ebx	# _7, entryIndex
# save_manager.cpp:266:     writeSaveFile(entries[entryIndex].filename, state, entries[entryIndex].name);
	lea	rdx, 48[rsp]	#,
# save_manager.cpp:264:     state.difficulty = Config::getCurrentDifficulty();
	mov	DWORD PTR 144[rsp], eax	# state.difficulty, _5
# save_manager.cpp:266:     writeSaveFile(entries[entryIndex].filename, state, entries[entryIndex].name);
	call	_ZNSt6vectorI9SaveEntrySaIS0_EEixEm.isra.0	#
# save_manager.cpp:266:     writeSaveFile(entries[entryIndex].filename, state, entries[entryIndex].name);
	mov	rdi, rbp	#, this
# save_manager.cpp:266:     writeSaveFile(entries[entryIndex].filename, state, entries[entryIndex].name);
	lea	rcx, 8[rax]	# _9,
# save_manager.cpp:266:     writeSaveFile(entries[entryIndex].filename, state, entries[entryIndex].name);
	lea	rsi, 40[rax]	# _10,
# save_manager.cpp:266:     writeSaveFile(entries[entryIndex].filename, state, entries[entryIndex].name);
	call	_ZN11SaveManager13writeSaveFileERKNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEEERK13GameSaveStateS7_	#
	jmp	.L270	#
	.p2align 4,,10
	.p2align 3
.L281:
# save_manager.cpp:257:         std::cerr << "[SaveManager] overwrite: autosave не найден\n";
	lea	rsi, .LC88[rip]	#,
	lea	rdi, _ZSt4cerr[rip]	#,
	call	[QWORD PTR _ZStlsISt11char_traitsIcEERSt13basic_ostreamIcT_ES5_PKc@GOTPCREL[rip]]	#
.LEHE21:
# save_manager.cpp:258:         return false;
	jmp	.L271	#
.L280:
# save_manager.cpp:268: }
	call	[QWORD PTR __stack_chk_fail@GOTPCREL[rip]]	#
.L277:
# save_manager.cpp:256:     if (!readSaveFile(AUTOSAVE_FILE, state)) {
	mov	rbx, rax	# tmp157,
	jmp	.L274	#
	.section	.gcc_except_table
.LLSDA13566:
	.byte	0xff
	.byte	0xff
	.byte	0x1
	.uleb128 .LLSDACSE13566-.LLSDACSB13566
.LLSDACSB13566:
	.uleb128 .LEHB19-.LFB13566
	.uleb128 .LEHE19-.LEHB19
	.uleb128 0
	.uleb128 0
	.uleb128 .LEHB20-.LFB13566
	.uleb128 .LEHE20-.LEHB20
	.uleb128 .L277-.LFB13566
	.uleb128 0
	.uleb128 .LEHB21-.LFB13566
	.uleb128 .LEHE21-.LEHB21
	.uleb128 0
	.uleb128 0
.LLSDACSE13566:
	.text
	.cfi_endproc
	.section	.text.unlikely
	.cfi_startproc
	.cfi_personality 0x9b,DW.ref.__gxx_personality_v0
	.cfi_lsda 0x1b,.LLSDAC13566
	.type	_ZN11SaveManager18overwriteNamedSaveEi.cold, @function
_ZN11SaveManager18overwriteNamedSaveEi.cold:
.LFSB13566:
.L274:
	.cfi_def_cfa_offset 208
	.cfi_offset 3, -48
	.cfi_offset 6, -40
	.cfi_offset 12, -32
	.cfi_offset 14, -24
	.cfi_offset 15, -16
	lea	rdi, 16[rsp]	#,
	call	[QWORD PTR _ZNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEED1Ev@GOTPCREL[rip]]	#
	mov	rax, QWORD PTR 152[rsp]	# tmp158, D.189416
	sub	rax, QWORD PTR fs:40	# tmp158, MEM[(<address-space-1> long unsigned int *)40B]
	jne	.L282	#,
	mov	rdi, rbx	#, tmp157
.LEHB22:
	call	[QWORD PTR _Unwind_Resume@GOTPCREL[rip]]	#
.LEHE22:
.L282:
	call	[QWORD PTR __stack_chk_fail@GOTPCREL[rip]]	#
	.cfi_endproc
.LFE13566:
	.section	.gcc_except_table
.LLSDAC13566:
	.byte	0xff
	.byte	0xff
	.byte	0x1
	.uleb128 .LLSDACSEC13566-.LLSDACSBC13566
.LLSDACSBC13566:
	.uleb128 .LEHB22-.LCOLDB89
	.uleb128 .LEHE22-.LEHB22
	.uleb128 0
	.uleb128 0
.LLSDACSEC13566:
	.section	.text.unlikely
	.text
	.size	_ZN11SaveManager18overwriteNamedSaveEi, .-_ZN11SaveManager18overwriteNamedSaveEi
	.section	.text.unlikely
	.size	_ZN11SaveManager18overwriteNamedSaveEi.cold, .-_ZN11SaveManager18overwriteNamedSaveEi.cold
.LCOLDE89:
	.text
.LHOTE89:
	.section	.rodata.str1.1
.LC90:
	.string	""
.LC91:
	.string	"save"
.LC92:
	.string	"_"
.LC93:
	.string	".txt"
	.section	.text.unlikely
	.align 2
.LCOLDB94:
	.text
.LHOTB94:
	.align 2
	.p2align 4
	.globl	_ZNK11SaveManager12makeFilenameEiRKNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEEE
	.type	_ZNK11SaveManager12makeFilenameEiRKNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEEE, @function
_ZNK11SaveManager12makeFilenameEiRKNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEEE:
.LFB13548:
	.cfi_startproc
	.cfi_personality 0x9b,DW.ref.__gxx_personality_v0
	.cfi_lsda 0x1b,.LLSDA13548
	push	r15	#
	.cfi_def_cfa_offset 16
	.cfi_offset 15, -16
# save_manager.cpp:57:     std::string safeName = name;
	mov	rsi, rcx	#, name
# save_manager.cpp:55: std::string SaveManager::makeFilename(int number, const std::string& name) const {
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
	sub	rsp, 280	#,
	.cfi_def_cfa_offset 336
# save_manager.cpp:55: std::string SaveManager::makeFilename(int number, const std::string& name) const {
	mov	QWORD PTR 8[rsp], rdi	# %sfp, .result_ptr
# save_manager.cpp:57:     std::string safeName = name;
	lea	rdi, 32[rsp]	#,
# save_manager.cpp:55: std::string SaveManager::makeFilename(int number, const std::string& name) const {
	mov	r12, QWORD PTR fs:40	# number, MEM[(<address-space-1> long unsigned int *)40B]
	mov	QWORD PTR 264[rsp], r12	# D.189438, number
	mov	r12d, edx	# number, number
.LEHB23:
# save_manager.cpp:57:     std::string safeName = name;
	call	[QWORD PTR _ZNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEEC1ERKS4_@GOTPCREL[rip]]	#
.LEHE23:
# save_manager.cpp:58:     for (char& c : safeName) {
	lea	rdi, 32[rsp]	#,
	call	[QWORD PTR _ZNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEE5beginEv@GOTPCREL[rip]]	#
# save_manager.cpp:58:     for (char& c : safeName) {
	lea	rdi, 32[rsp]	#,
# save_manager.cpp:58:     for (char& c : safeName) {
	mov	rbp, rax	# __for_begin,
# save_manager.cpp:58:     for (char& c : safeName) {
	call	[QWORD PTR _ZNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEE3endEv@GOTPCREL[rip]]	#
# save_manager.cpp:58:     for (char& c : safeName) {
	cmp	rax, rbp	# __for_end, __for_begin
	je	.L284	#,
	mov	rdx, rax	# __for_end,
	mov	rax, rbp	# ivtmp.686, __for_begin
	.p2align 5
	.p2align 4
	.p2align 3
.L286:
# save_manager.cpp:59:         if (c == ' ') c = '_';
	cmp	BYTE PTR [rax], 32	# MEM[(char &)_60],
	jne	.L285	#,
# save_manager.cpp:59:         if (c == ' ') c = '_';
	mov	BYTE PTR [rax], 95	# MEM[(char &)_60],
.L285:
# save_manager.cpp:58:     for (char& c : safeName) {
	add	rax, 1	# ivtmp.686,
	cmp	rax, rdx	# ivtmp.686, __for_end
	jne	.L286	#,
.L284:
# save_manager.cpp:61:     return std::string(SAVE_DIR) + "save" + std::to_string(number) + "_" + safeName + ".txt";
	lea	r15, 128[rsp]	# tmp168,
	mov	esi, r12d	#, number
# save_manager.cpp:61:     return std::string(SAVE_DIR) + "save" + std::to_string(number) + "_" + safeName + ".txt";
	lea	rbp, 64[rsp]	# tmp167,
# save_manager.cpp:61:     return std::string(SAVE_DIR) + "save" + std::to_string(number) + "_" + safeName + ".txt";
	mov	rdi, r15	#, tmp168
	mov	QWORD PTR [rsp], r15	# %sfp, tmp168
	call	_ZNSt7__cxx119to_stringEi	#
# save_manager.cpp:61:     return std::string(SAVE_DIR) + "save" + std::to_string(number) + "_" + safeName + ".txt";
	lea	rdx, 31[rsp]	# tmp117,
	lea	rsi, .LC90[rip]	#,
	mov	rdi, rbp	#, tmp167
.LEHB24:
	call	_ZNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEEC1IS3_EEPKcRKS3_	#
.LEHE24:
# save_manager.cpp:61:     return std::string(SAVE_DIR) + "save" + std::to_string(number) + "_" + safeName + ".txt";
	lea	rdx, .LC91[rip]	#,
	mov	rsi, rbp	#, tmp167
	lea	rdi, 96[rsp]	#,
.LEHB25:
	call	_ZStplIcSt11char_traitsIcESaIcEENSt7__cxx1112basic_stringIT_T0_T1_EEOS8_PKS5_	#
.LEHE25:
# save_manager.cpp:61:     return std::string(SAVE_DIR) + "save" + std::to_string(number) + "_" + safeName + ".txt";
	mov	rdx, r15	#, tmp168
	lea	rsi, 96[rsp]	#,
	lea	rdi, 160[rsp]	#,
	mov	QWORD PTR [rsp], r15	# %sfp, tmp168
.LEHB26:
	call	_ZStplIcSt11char_traitsIcESaIcEENSt7__cxx1112basic_stringIT_T0_T1_EEOS8_S9_	#
.LEHE26:
# save_manager.cpp:61:     return std::string(SAVE_DIR) + "save" + std::to_string(number) + "_" + safeName + ".txt";
	lea	rdx, .LC92[rip]	#,
	lea	rsi, 160[rsp]	#,
	lea	rdi, 192[rsp]	#,
.LEHB27:
	call	_ZStplIcSt11char_traitsIcESaIcEENSt7__cxx1112basic_stringIT_T0_T1_EEOS8_PKS5_	#
.LEHE27:
# save_manager.cpp:61:     return std::string(SAVE_DIR) + "save" + std::to_string(number) + "_" + safeName + ".txt";
	lea	rdx, 32[rsp]	#,
	lea	rsi, 192[rsp]	#,
	lea	rdi, 224[rsp]	#,
.LEHB28:
	call	_ZStplIcSt11char_traitsIcESaIcEENSt7__cxx1112basic_stringIT_T0_T1_EEOS8_RKS8_	#
.LEHE28:
# save_manager.cpp:61:     return std::string(SAVE_DIR) + "save" + std::to_string(number) + "_" + safeName + ".txt";
	mov	rdi, QWORD PTR 8[rsp]	#, %sfp
	lea	rdx, .LC93[rip]	#,
	lea	rsi, 224[rsp]	#,
.LEHB29:
	call	_ZStplIcSt11char_traitsIcESaIcEENSt7__cxx1112basic_stringIT_T0_T1_EEOS8_PKS5_	#
.LEHE29:
# save_manager.cpp:61:     return std::string(SAVE_DIR) + "save" + std::to_string(number) + "_" + safeName + ".txt";
	lea	rdi, 224[rsp]	#,
	call	[QWORD PTR _ZNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEED1Ev@GOTPCREL[rip]]	#
# save_manager.cpp:61:     return std::string(SAVE_DIR) + "save" + std::to_string(number) + "_" + safeName + ".txt";
	lea	rdi, 192[rsp]	#,
	call	[QWORD PTR _ZNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEED1Ev@GOTPCREL[rip]]	#
# save_manager.cpp:61:     return std::string(SAVE_DIR) + "save" + std::to_string(number) + "_" + safeName + ".txt";
	lea	rdi, 160[rsp]	#,
	call	[QWORD PTR _ZNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEED1Ev@GOTPCREL[rip]]	#
# save_manager.cpp:61:     return std::string(SAVE_DIR) + "save" + std::to_string(number) + "_" + safeName + ".txt";
	lea	rdi, 96[rsp]	#,
	call	[QWORD PTR _ZNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEED1Ev@GOTPCREL[rip]]	#
# save_manager.cpp:61:     return std::string(SAVE_DIR) + "save" + std::to_string(number) + "_" + safeName + ".txt";
	mov	rdi, rbp	#, tmp167
	call	[QWORD PTR _ZNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEED1Ev@GOTPCREL[rip]]	#
# save_manager.cpp:61:     return std::string(SAVE_DIR) + "save" + std::to_string(number) + "_" + safeName + ".txt";
	mov	rdi, QWORD PTR [rsp]	#, %sfp
	call	[QWORD PTR _ZNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEED1Ev@GOTPCREL[rip]]	#
# save_manager.cpp:62: }
	lea	rdi, 32[rsp]	#,
	call	[QWORD PTR _ZNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEED1Ev@GOTPCREL[rip]]	#
	mov	rax, QWORD PTR 264[rsp]	# tmp185, D.189438
	sub	rax, QWORD PTR fs:40	# tmp185, MEM[(<address-space-1> long unsigned int *)40B]
	jne	.L304	#,
	mov	rax, QWORD PTR 8[rsp]	#, %sfp
	add	rsp, 280	#,
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
.L304:
	.cfi_restore_state
	call	[QWORD PTR __stack_chk_fail@GOTPCREL[rip]]	#
.L300:
# save_manager.cpp:61:     return std::string(SAVE_DIR) + "save" + std::to_string(number) + "_" + safeName + ".txt";
	jmp	.L287	#
.L299:
# save_manager.cpp:61:     return std::string(SAVE_DIR) + "save" + std::to_string(number) + "_" + safeName + ".txt";
	mov	r15, rax	# tmp143, tmp179
	jmp	.L288	#
.L298:
# save_manager.cpp:61:     return std::string(SAVE_DIR) + "save" + std::to_string(number) + "_" + safeName + ".txt";
	mov	r14, rax	# tmp148, tmp180
	jmp	.L289	#
.L296:
# save_manager.cpp:61:     return std::string(SAVE_DIR) + "save" + std::to_string(number) + "_" + safeName + ".txt";
	mov	r12, rax	# tmp154, tmp182
	jmp	.L291	#
.L295:
# save_manager.cpp:61:     return std::string(SAVE_DIR) + "save" + std::to_string(number) + "_" + safeName + ".txt";
	mov	r12, rax	# tmp157, tmp183
	jmp	.L292	#
.L297:
# save_manager.cpp:61:     return std::string(SAVE_DIR) + "save" + std::to_string(number) + "_" + safeName + ".txt";
	mov	r14, rax	# tmp151, tmp181
	jmp	.L290	#
	.section	.gcc_except_table
.LLSDA13548:
	.byte	0xff
	.byte	0xff
	.byte	0x1
	.uleb128 .LLSDACSE13548-.LLSDACSB13548
.LLSDACSB13548:
	.uleb128 .LEHB23-.LFB13548
	.uleb128 .LEHE23-.LEHB23
	.uleb128 0
	.uleb128 0
	.uleb128 .LEHB24-.LFB13548
	.uleb128 .LEHE24-.LEHB24
	.uleb128 .L295-.LFB13548
	.uleb128 0
	.uleb128 .LEHB25-.LFB13548
	.uleb128 .LEHE25-.LEHB25
	.uleb128 .L296-.LFB13548
	.uleb128 0
	.uleb128 .LEHB26-.LFB13548
	.uleb128 .LEHE26-.LEHB26
	.uleb128 .L297-.LFB13548
	.uleb128 0
	.uleb128 .LEHB27-.LFB13548
	.uleb128 .LEHE27-.LEHB27
	.uleb128 .L298-.LFB13548
	.uleb128 0
	.uleb128 .LEHB28-.LFB13548
	.uleb128 .LEHE28-.LEHB28
	.uleb128 .L299-.LFB13548
	.uleb128 0
	.uleb128 .LEHB29-.LFB13548
	.uleb128 .LEHE29-.LEHB29
	.uleb128 .L300-.LFB13548
	.uleb128 0
.LLSDACSE13548:
	.text
	.cfi_endproc
	.section	.text.unlikely
	.cfi_startproc
	.cfi_personality 0x9b,DW.ref.__gxx_personality_v0
	.cfi_lsda 0x1b,.LLSDAC13548
	.type	_ZNK11SaveManager12makeFilenameEiRKNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEEE.cold, @function
_ZNK11SaveManager12makeFilenameEiRKNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEEE.cold:
.LFSB13548:
.L287:
	.cfi_def_cfa_offset 336
	.cfi_offset 3, -56
	.cfi_offset 6, -48
	.cfi_offset 12, -40
	.cfi_offset 13, -32
	.cfi_offset 14, -24
	.cfi_offset 15, -16
	mov	QWORD PTR 8[rsp], rax	# %sfp, tmp178
# save_manager.cpp:61:     return std::string(SAVE_DIR) + "save" + std::to_string(number) + "_" + safeName + ".txt";
	lea	rdi, 224[rsp]	#,
	call	[QWORD PTR _ZNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEED1Ev@GOTPCREL[rip]]	#
	mov	r15, QWORD PTR 8[rsp]	# tmp143, %sfp
.L288:
# save_manager.cpp:61:     return std::string(SAVE_DIR) + "save" + std::to_string(number) + "_" + safeName + ".txt";
	lea	rdi, 192[rsp]	#,
	mov	r14, r15	# tmp148, tmp143
	call	[QWORD PTR _ZNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEED1Ev@GOTPCREL[rip]]	#
.L289:
# save_manager.cpp:61:     return std::string(SAVE_DIR) + "save" + std::to_string(number) + "_" + safeName + ".txt";
	lea	rdi, 160[rsp]	#,
	call	[QWORD PTR _ZNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEED1Ev@GOTPCREL[rip]]	#
.L290:
# save_manager.cpp:61:     return std::string(SAVE_DIR) + "save" + std::to_string(number) + "_" + safeName + ".txt";
	lea	rdi, 96[rsp]	#,
	mov	r12, r14	# tmp154, tmp151
	call	[QWORD PTR _ZNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEED1Ev@GOTPCREL[rip]]	#
.L291:
# save_manager.cpp:61:     return std::string(SAVE_DIR) + "save" + std::to_string(number) + "_" + safeName + ".txt";
	mov	rdi, rbp	#, tmp167
	call	[QWORD PTR _ZNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEED1Ev@GOTPCREL[rip]]	#
.L292:
# save_manager.cpp:61:     return std::string(SAVE_DIR) + "save" + std::to_string(number) + "_" + safeName + ".txt";
	mov	rdi, QWORD PTR [rsp]	#, %sfp
	call	[QWORD PTR _ZNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEED1Ev@GOTPCREL[rip]]	#
# save_manager.cpp:62: }
	lea	rdi, 32[rsp]	#,
	call	[QWORD PTR _ZNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEED1Ev@GOTPCREL[rip]]	#
	mov	rax, QWORD PTR 264[rsp]	# tmp186, D.189438
	sub	rax, QWORD PTR fs:40	# tmp186, MEM[(<address-space-1> long unsigned int *)40B]
	jne	.L305	#,
	mov	rdi, r12	#, tmp157
.LEHB30:
	call	[QWORD PTR _Unwind_Resume@GOTPCREL[rip]]	#
.LEHE30:
.L305:
	call	[QWORD PTR __stack_chk_fail@GOTPCREL[rip]]	#
	.cfi_endproc
.LFE13548:
	.section	.gcc_except_table
.LLSDAC13548:
	.byte	0xff
	.byte	0xff
	.byte	0x1
	.uleb128 .LLSDACSEC13548-.LLSDACSBC13548
.LLSDACSBC13548:
	.uleb128 .LEHB30-.LCOLDB94
	.uleb128 .LEHE30-.LEHB30
	.uleb128 0
	.uleb128 0
.LLSDACSEC13548:
	.section	.text.unlikely
	.text
	.size	_ZNK11SaveManager12makeFilenameEiRKNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEEE, .-_ZNK11SaveManager12makeFilenameEiRKNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEEE
	.section	.text.unlikely
	.size	_ZNK11SaveManager12makeFilenameEiRKNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEEE.cold, .-_ZNK11SaveManager12makeFilenameEiRKNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEEE.cold
.LCOLDE94:
	.text
.LHOTE94:
	.section	.text._ZNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEEC2EPKcmRKS3_.isra.0,"axG",@progbits,_ZNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEEC5ISt17basic_string_viewIcS2_EvEERKT_RKS3_,comdat
	.align 2
	.p2align 4
	.type	_ZNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEEC2EPKcmRKS3_.isra.0, @function
_ZNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEEC2EPKcmRKS3_.isra.0:
.LFB14839:
	.cfi_startproc
	push	r12	#
	.cfi_def_cfa_offset 16
	.cfi_offset 12, -16
	mov	r12, rsi	# __s, __s
	push	rbp	#
	.cfi_def_cfa_offset 24
	.cfi_offset 6, -24
	mov	rbp, rdi	# this, this
	push	rbx	#
	.cfi_def_cfa_offset 32
	.cfi_offset 3, -32
# /usr/include/c++/15.2.1/bits/basic_string.h:684:       basic_string(const _CharT* __s, size_type __n,
	mov	rbx, rdx	# __n, __n
# /usr/include/c++/15.2.1/bits/basic_string.h:686:       : _M_dataplus(_M_local_data(), __a)
	call	[QWORD PTR _ZNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEE13_M_local_dataEv@GOTPCREL[rip]]	#
# /usr/include/c++/15.2.1/bits/basic_string.h:686:       : _M_dataplus(_M_local_data(), __a)
	mov	rdi, rbp	#, this
	mov	rsi, rax	#, _3
	call	_ZNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEE12_Alloc_hiderC2EPcRKS3_.isra.0	#
# /usr/include/c++/15.2.1/bits/basic_string.h:689: 	if (__s == 0 && __n > 0)
	test	r12, r12	# __s
	jne	.L307	#,
	test	rbx, rbx	# __n
	jne	.L315	#,
.L307:
# /usr/include/c++/15.2.1/bits/basic_string.h:692: 	_M_construct(__s, __s + __n, std::forward_iterator_tag());
	lea	rdx, [r12+rbx]	# _9,
	mov	rsi, r12	#, __s
	mov	rdi, rbp	#, this
	call	_ZNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEE12_M_constructIPKcEEvT_S8_St20forward_iterator_tag.isra.0	#
# /usr/include/c++/15.2.1/bits/basic_string.h:693:       }
	pop	rbx	#
	.cfi_remember_state
	.cfi_def_cfa_offset 24
	pop	rbp	#
	.cfi_def_cfa_offset 16
	pop	r12	#
	.cfi_def_cfa_offset 8
	ret	
.L315:
	.cfi_restore_state
# /usr/include/c++/15.2.1/bits/basic_string.h:690: 	  std::__throw_logic_error(__N("basic_string: "
	lea	rdi, .LC86[rip]	#,
	call	[QWORD PTR _ZSt19__throw_logic_errorPKc@GOTPCREL[rip]]	#
	.cfi_endproc
.LFE14839:
	.size	_ZNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEEC2EPKcmRKS3_.isra.0, .-_ZNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEEC2EPKcmRKS3_.isra.0
	.section	.text._ZNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEEC2ENS4_12__sv_wrapperERKS3_.isra.0,"axG",@progbits,_ZNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEEC5ISt17basic_string_viewIcS2_EvEERKT_RKS3_,comdat
	.align 2
	.p2align 4
	.type	_ZNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEEC2ENS4_12__sv_wrapperERKS3_.isra.0, @function
_ZNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEEC2ENS4_12__sv_wrapperERKS3_.isra.0:
.LFB14840:
	.cfi_startproc
	sub	rsp, 8	#,
	.cfi_def_cfa_offset 16
# /usr/include/c++/15.2.1/bits/basic_string.h:192:       basic_string(__sv_wrapper __svw, const _Alloc& __a)
	mov	rcx, rdi	# this, this
	mov	rdi, rsi	# __svw, __svw
# /usr/include/c++/15.2.1/bits/basic_string.h:193:       : basic_string(__svw._M_sv.data(), __svw._M_sv.size(), __a) { }
	call	_ZNKSt17basic_string_viewIcSt11char_traitsIcEE4sizeEv.isra.0	#
# /usr/include/c++/15.2.1/bits/basic_string.h:193:       : basic_string(__svw._M_sv.data(), __svw._M_sv.size(), __a) { }
	mov	rdi, rdx	#, __svw
# /usr/include/c++/15.2.1/bits/basic_string.h:193:       : basic_string(__svw._M_sv.data(), __svw._M_sv.size(), __a) { }
	mov	rdx, rax	# _2,
# /usr/include/c++/15.2.1/bits/basic_string.h:193:       : basic_string(__svw._M_sv.data(), __svw._M_sv.size(), __a) { }
	call	_ZNKSt17basic_string_viewIcSt11char_traitsIcEE4dataEv.isra.0	#
# /usr/include/c++/15.2.1/bits/basic_string.h:193:       : basic_string(__svw._M_sv.data(), __svw._M_sv.size(), __a) { }
	mov	rdi, rcx	#, this
# /usr/include/c++/15.2.1/bits/basic_string.h:193:       : basic_string(__svw._M_sv.data(), __svw._M_sv.size(), __a) { }
	add	rsp, 8	#,
	.cfi_def_cfa_offset 8
# /usr/include/c++/15.2.1/bits/basic_string.h:193:       : basic_string(__svw._M_sv.data(), __svw._M_sv.size(), __a) { }
	mov	rsi, rax	#, _3
	jmp	_ZNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEEC2EPKcmRKS3_.isra.0	#
	.cfi_endproc
.LFE14840:
	.size	_ZNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEEC2ENS4_12__sv_wrapperERKS3_.isra.0, .-_ZNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEEC2ENS4_12__sv_wrapperERKS3_.isra.0
	.section	.text._ZNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEEC2ISt17basic_string_viewIcS2_EvEERKT_RKS3_,"axG",@progbits,_ZNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEEC5ISt17basic_string_viewIcS2_EvEERKT_RKS3_,comdat
	.align 2
	.p2align 4
	.weak	_ZNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEEC2ISt17basic_string_viewIcS2_EvEERKT_RKS3_
	.type	_ZNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEEC2ISt17basic_string_viewIcS2_EvEERKT_RKS3_, @function
_ZNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEEC2ISt17basic_string_viewIcS2_EvEERKT_RKS3_:
.LFB14420:
	.cfi_startproc
	push	rbx	#
	.cfi_def_cfa_offset 16
	.cfi_offset 3, -16
	sub	rsp, 32	#,
	.cfi_def_cfa_offset 48
# /usr/include/c++/15.2.1/bits/basic_string.h:887: 	basic_string(const _Tp& __t, const _Alloc& __a = _Alloc())
	mov	rbx, QWORD PTR fs:40	# this, MEM[(<address-space-1> long unsigned int *)40B]
	mov	QWORD PTR 24[rsp], rbx	# D.189480, this
	mov	rbx, rdi	# this, this
# /usr/include/c++/15.2.1/bits/basic_string.h:888: 	: basic_string(__sv_wrapper(_S_to_string_view(__t)), __a) { }
	mov	rdi, QWORD PTR [rsi]	# *__t_4(D), *__t_4(D)
	mov	rsi, QWORD PTR 8[rsi]	# *__t_4(D), *__t_4(D)
	call	[QWORD PTR _ZNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEE17_S_to_string_viewESt17basic_string_viewIcS2_E@GOTPCREL[rip]]	#
# /usr/include/c++/15.2.1/bits/basic_string.h:888: 	: basic_string(__sv_wrapper(_S_to_string_view(__t)), __a) { }
	mov	rdi, rsp	# tmp108,
	mov	rsi, rax	#, D.187651
	call	[QWORD PTR _ZNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEE12__sv_wrapperC1ESt17basic_string_viewIcS2_E@GOTPCREL[rip]]	#
# /usr/include/c++/15.2.1/bits/basic_string.h:888: 	: basic_string(__sv_wrapper(_S_to_string_view(__t)), __a) { }
	mov	rsi, QWORD PTR [rsp]	#, D.184107
	mov	rdx, QWORD PTR 8[rsp]	#, D.184107
	mov	rdi, rbx	#, this
	call	_ZNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEEC2ENS4_12__sv_wrapperERKS3_.isra.0	#
# /usr/include/c++/15.2.1/bits/basic_string.h:888: 	: basic_string(__sv_wrapper(_S_to_string_view(__t)), __a) { }
	mov	rax, QWORD PTR 24[rsp]	# tmp118, D.189480
	sub	rax, QWORD PTR fs:40	# tmp118, MEM[(<address-space-1> long unsigned int *)40B]
	jne	.L321	#,
	add	rsp, 32	#,
	.cfi_remember_state
	.cfi_def_cfa_offset 16
	pop	rbx	#
	.cfi_def_cfa_offset 8
	ret	
.L321:
	.cfi_restore_state
	call	[QWORD PTR __stack_chk_fail@GOTPCREL[rip]]	#
	.cfi_endproc
.LFE14420:
	.size	_ZNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEEC2ISt17basic_string_viewIcS2_EvEERKT_RKS3_, .-_ZNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEEC2ISt17basic_string_viewIcS2_EvEERKT_RKS3_
	.weak	_ZNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEEC1ISt17basic_string_viewIcS2_EvEERKT_RKS3_
	.set	_ZNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEEC1ISt17basic_string_viewIcS2_EvEERKT_RKS3_,_ZNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEEC2ISt17basic_string_viewIcS2_EvEERKT_RKS3_
	.section	.text._ZN9SaveEntryC2ERKS_,"axG",@progbits,_ZN9SaveEntryC5ERKS_,comdat
	.align 2
	.p2align 4
	.weak	_ZN9SaveEntryC2ERKS_
	.type	_ZN9SaveEntryC2ERKS_, @function
_ZN9SaveEntryC2ERKS_:
.LFB14578:
	.cfi_startproc
	.cfi_personality 0x9b,DW.ref.__gxx_personality_v0
	.cfi_lsda 0x1b,.LLSDA14578
	push	r12	#
	.cfi_def_cfa_offset 16
	.cfi_offset 12, -16
	lea	r12, 8[rdi]	# _2,
	push	rbp	#
	.cfi_def_cfa_offset 24
	.cfi_offset 6, -24
	mov	rbp, rsi	# D.177159, D.177159
	lea	rsi, 8[rsi]	# _3,
	push	rbx	#
	.cfi_def_cfa_offset 32
	.cfi_offset 3, -32
# save_manager.h:77: struct SaveEntry {
	mov	eax, DWORD PTR -8[rsi]	# *_10(D).number, *_10(D).number
	mov	rbx, rdi	# this, this
	mov	DWORD PTR [rdi], eax	# *this_8(D).number, *_10(D).number
	mov	rdi, r12	#, _2
.LEHB31:
	call	[QWORD PTR _ZNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEEC1ERKS4_@GOTPCREL[rip]]	#
.LEHE31:
# save_manager.h:77: struct SaveEntry {
	lea	rsi, 40[rbp]	# _5,
	lea	rdi, 40[rbx]	# _4,
.LEHB32:
	call	[QWORD PTR _ZNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEEC1ERKS4_@GOTPCREL[rip]]	#
.LEHE32:
# save_manager.h:77: struct SaveEntry {
	pop	rbx	#
	.cfi_remember_state
	.cfi_def_cfa_offset 24
	pop	rbp	#
	.cfi_def_cfa_offset 16
	pop	r12	#
	.cfi_def_cfa_offset 8
	ret	
.L324:
	.cfi_restore_state
# save_manager.h:77: struct SaveEntry {
	mov	rbx, rax	# tmp114,
.L323:
	mov	rdi, r12	#, _2
	call	[QWORD PTR _ZNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEED1Ev@GOTPCREL[rip]]	#
	mov	rdi, rbx	#, tmp114
.LEHB33:
	call	[QWORD PTR _Unwind_Resume@GOTPCREL[rip]]	#
.LEHE33:
	.cfi_endproc
.LFE14578:
	.section	.gcc_except_table
.LLSDA14578:
	.byte	0xff
	.byte	0xff
	.byte	0x1
	.uleb128 .LLSDACSE14578-.LLSDACSB14578
.LLSDACSB14578:
	.uleb128 .LEHB31-.LFB14578
	.uleb128 .LEHE31-.LEHB31
	.uleb128 0
	.uleb128 0
	.uleb128 .LEHB32-.LFB14578
	.uleb128 .LEHE32-.LEHB32
	.uleb128 .L324-.LFB14578
	.uleb128 0
	.uleb128 .LEHB33-.LFB14578
	.uleb128 .LEHE33-.LEHB33
	.uleb128 0
	.uleb128 0
.LLSDACSE14578:
	.section	.text._ZN9SaveEntryC2ERKS_,"axG",@progbits,_ZN9SaveEntryC5ERKS_,comdat
	.size	_ZN9SaveEntryC2ERKS_, .-_ZN9SaveEntryC2ERKS_
	.weak	_ZN9SaveEntryC1ERKS_
	.set	_ZN9SaveEntryC1ERKS_,_ZN9SaveEntryC2ERKS_
	.section	.text._ZNSt6vectorI9SaveEntrySaIS0_EE12_Guard_allocC2EPS0_mRSt12_Vector_baseIS0_S1_E,"axG",@progbits,_ZNSt6vectorI9SaveEntrySaIS0_EE12_Guard_allocC5EPS0_mRSt12_Vector_baseIS0_S1_E,comdat
	.align 2
	.p2align 4
	.weak	_ZNSt6vectorI9SaveEntrySaIS0_EE12_Guard_allocC2EPS0_mRSt12_Vector_baseIS0_S1_E
	.type	_ZNSt6vectorI9SaveEntrySaIS0_EE12_Guard_allocC2EPS0_mRSt12_Vector_baseIS0_S1_E, @function
_ZNSt6vectorI9SaveEntrySaIS0_EE12_Guard_allocC2EPS0_mRSt12_Vector_baseIS0_S1_E:
.LFB14584:
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
.LFE14584:
	.size	_ZNSt6vectorI9SaveEntrySaIS0_EE12_Guard_allocC2EPS0_mRSt12_Vector_baseIS0_S1_E, .-_ZNSt6vectorI9SaveEntrySaIS0_EE12_Guard_allocC2EPS0_mRSt12_Vector_baseIS0_S1_E
	.weak	_ZNSt6vectorI9SaveEntrySaIS0_EE12_Guard_allocC1EPS0_mRSt12_Vector_baseIS0_S1_E
	.set	_ZNSt6vectorI9SaveEntrySaIS0_EE12_Guard_allocC1EPS0_mRSt12_Vector_baseIS0_S1_E,_ZNSt6vectorI9SaveEntrySaIS0_EE12_Guard_allocC2EPS0_mRSt12_Vector_baseIS0_S1_E
	.section	.text._ZNSt6vectorI9SaveEntrySaIS0_EE12_Guard_allocD2Ev,"axG",@progbits,_ZNSt6vectorI9SaveEntrySaIS0_EE12_Guard_allocD5Ev,comdat
	.align 2
	.p2align 4
	.weak	_ZNSt6vectorI9SaveEntrySaIS0_EE12_Guard_allocD2Ev
	.type	_ZNSt6vectorI9SaveEntrySaIS0_EE12_Guard_allocD2Ev, @function
_ZNSt6vectorI9SaveEntrySaIS0_EE12_Guard_allocD2Ev:
.LFB14587:
	.cfi_startproc
# /usr/include/c++/15.2.1/bits/stl_vector.h:1880: 	~_Guard_alloc()
	mov	rax, rdi	# this, this
# /usr/include/c++/15.2.1/bits/stl_vector.h:1882: 	  if (_M_storage)
	mov	rdi, QWORD PTR [rdi]	# _1, this_6(D)->_M_storage
# /usr/include/c++/15.2.1/bits/stl_vector.h:1882: 	  if (_M_storage)
	test	rdi, rdi	# _1
	je	.L328	#,
# /usr/include/c++/15.2.1/bits/stl_vector.h:1883: 	    _M_vect._M_deallocate(_M_storage, _M_len);
	mov	rsi, QWORD PTR 8[rax]	# this_6(D)->_M_len, this_6(D)->_M_len
	jmp	_ZNSt12_Vector_baseI9SaveEntrySaIS0_EE13_M_deallocateEPS0_m.isra.0	#
	.p2align 4,,10
	.p2align 3
.L328:
# /usr/include/c++/15.2.1/bits/stl_vector.h:1884: 	}
	ret	
	.cfi_endproc
.LFE14587:
	.size	_ZNSt6vectorI9SaveEntrySaIS0_EE12_Guard_allocD2Ev, .-_ZNSt6vectorI9SaveEntrySaIS0_EE12_Guard_allocD2Ev
	.weak	_ZNSt6vectorI9SaveEntrySaIS0_EE12_Guard_allocD1Ev
	.set	_ZNSt6vectorI9SaveEntrySaIS0_EE12_Guard_allocD1Ev,_ZNSt6vectorI9SaveEntrySaIS0_EE12_Guard_allocD2Ev
	.section	.text._ZSt8_DestroyI9SaveEntryEvPT_,"axG",@progbits,_ZSt8_DestroyI9SaveEntryEvPT_,comdat
	.p2align 4
	.weak	_ZSt8_DestroyI9SaveEntryEvPT_
	.type	_ZSt8_DestroyI9SaveEntryEvPT_, @function
_ZSt8_DestroyI9SaveEntryEvPT_:
.LFB14667:
	.cfi_startproc
# /usr/include/c++/15.2.1/bits/stl_construct.h:166:       __pointer->~_Tp();
	jmp	_ZN9SaveEntryD1Ev	#
	.cfi_endproc
.LFE14667:
	.size	_ZSt8_DestroyI9SaveEntryEvPT_, .-_ZSt8_DestroyI9SaveEntryEvPT_
	.section	.text._ZSt8_DestroyIP9SaveEntryEvT_S2_,"axG",@progbits,_ZSt8_DestroyIP9SaveEntryEvT_S2_,comdat
	.p2align 4
	.weak	_ZSt8_DestroyIP9SaveEntryEvT_S2_
	.type	_ZSt8_DestroyIP9SaveEntryEvT_S2_, @function
_ZSt8_DestroyIP9SaveEntryEvT_S2_:
.LFB14526:
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
.LFE14526:
	.size	_ZSt8_DestroyIP9SaveEntryEvT_S2_, .-_ZSt8_DestroyIP9SaveEntryEvT_S2_
	.section	.text._ZNSt6vectorI9SaveEntrySaIS0_EE15_M_erase_at_endEPS0_,"axG",@progbits,_ZNSt6vectorI9SaveEntrySaIS0_EE15_M_erase_at_endEPS0_,comdat
	.align 2
	.p2align 4
	.weak	_ZNSt6vectorI9SaveEntrySaIS0_EE15_M_erase_at_endEPS0_
	.type	_ZNSt6vectorI9SaveEntrySaIS0_EE15_M_erase_at_endEPS0_, @function
_ZNSt6vectorI9SaveEntrySaIS0_EE15_M_erase_at_endEPS0_:
.LFB14428:
	.cfi_startproc
# /usr/include/c++/15.2.1/bits/stl_vector.h:2241: 	if (size_type __n = this->_M_impl._M_finish - __pos)
	mov	rcx, QWORD PTR 8[rdi]	# _1, this_4(D)->D.154016._M_impl.D.153351._M_finish
# /usr/include/c++/15.2.1/bits/stl_vector.h:2241: 	if (size_type __n = this->_M_impl._M_finish - __pos)
	cmp	rcx, rsi	# _1, __pos
	je	.L342	#,
# /usr/include/c++/15.2.1/bits/stl_vector.h:2239:       _M_erase_at_end(pointer __pos) _GLIBCXX_NOEXCEPT
	sub	rsp, 24	#,
	.cfi_def_cfa_offset 32
	mov	QWORD PTR 8[rsp], rdi	# %sfp, this
# /usr/include/c++/15.2.1/bits/alloc_traits.h:1045:       std::_Destroy(__first, __last);
	mov	rdi, rsi	#, __pos
	mov	QWORD PTR [rsp], rsi	# %sfp, __pos
	mov	rsi, rcx	#, _1
	call	_ZSt8_DestroyIP9SaveEntryEvT_S2_	#
# /usr/include/c++/15.2.1/bits/stl_vector.h:2245: 	    this->_M_impl._M_finish = __pos;
	mov	rax, QWORD PTR [rsp]	# __pos, %sfp
	mov	rdx, QWORD PTR 8[rsp]	# this, %sfp
	mov	QWORD PTR 8[rdx], rax	# this_4(D)->D.154016._M_impl.D.153351._M_finish, __pos
# /usr/include/c++/15.2.1/bits/stl_vector.h:2248:       }
	add	rsp, 24	#,
	.cfi_def_cfa_offset 8
	ret	
	.p2align 4,,10
	.p2align 3
.L342:
	ret	
	.cfi_endproc
.LFE14428:
	.size	_ZNSt6vectorI9SaveEntrySaIS0_EE15_M_erase_at_endEPS0_, .-_ZNSt6vectorI9SaveEntrySaIS0_EE15_M_erase_at_endEPS0_
	.section	.text._ZNSt6vectorI9SaveEntrySaIS0_EE5clearEv,"axG",@progbits,_ZNSt6vectorI9SaveEntrySaIS0_EE5clearEv,comdat
	.align 2
	.p2align 4
	.weak	_ZNSt6vectorI9SaveEntrySaIS0_EE5clearEv
	.type	_ZNSt6vectorI9SaveEntrySaIS0_EE5clearEv, @function
_ZNSt6vectorI9SaveEntrySaIS0_EE5clearEv:
.LFB14089:
	.cfi_startproc
# /usr/include/c++/15.2.1/bits/stl_vector.h:1864:       { _M_erase_at_end(this->_M_impl._M_start); }
	mov	rsi, QWORD PTR [rdi]	# this_3(D)->D.154016._M_impl.D.153351._M_start, this_3(D)->D.154016._M_impl.D.153351._M_start
	jmp	_ZNSt6vectorI9SaveEntrySaIS0_EE15_M_erase_at_endEPS0_	#
	.cfi_endproc
.LFE14089:
	.size	_ZNSt6vectorI9SaveEntrySaIS0_EE5clearEv, .-_ZNSt6vectorI9SaveEntrySaIS0_EE5clearEv
	.section	.text._ZSt12__miter_baseIN9__gnu_cxx17__normal_iteratorIP9SaveEntrySt6vectorIS2_SaIS2_EEEEET_S8_,"axG",@progbits,_ZSt12__miter_baseIN9__gnu_cxx17__normal_iteratorIP9SaveEntrySt6vectorIS2_SaIS2_EEEEET_S8_,comdat
	.p2align 4
	.weak	_ZSt12__miter_baseIN9__gnu_cxx17__normal_iteratorIP9SaveEntrySt6vectorIS2_SaIS2_EEEEET_S8_
	.type	_ZSt12__miter_baseIN9__gnu_cxx17__normal_iteratorIP9SaveEntrySt6vectorIS2_SaIS2_EEEEET_S8_, @function
_ZSt12__miter_baseIN9__gnu_cxx17__normal_iteratorIP9SaveEntrySt6vectorIS2_SaIS2_EEEEET_S8_:
.LFB14701:
	.cfi_startproc
# /usr/include/c++/15.2.1/bits/cpp_type_traits.h:705:     __miter_base(_Iterator __it)
	mov	rax, rdi	# __it, __it
# /usr/include/c++/15.2.1/bits/cpp_type_traits.h:706:     { return __it; }
	ret	
	.cfi_endproc
.LFE14701:
	.size	_ZSt12__miter_baseIN9__gnu_cxx17__normal_iteratorIP9SaveEntrySt6vectorIS2_SaIS2_EEEEET_S8_, .-_ZSt12__miter_baseIN9__gnu_cxx17__normal_iteratorIP9SaveEntrySt6vectorIS2_SaIS2_EEEEET_S8_
	.section	.text._ZNKSt12_Vector_baseI9SaveEntrySaIS0_EE19_M_get_Tp_allocatorEv,"axG",@progbits,_ZNKSt12_Vector_baseI9SaveEntrySaIS0_EE19_M_get_Tp_allocatorEv,comdat
	.align 2
	.p2align 4
	.weak	_ZNKSt12_Vector_baseI9SaveEntrySaIS0_EE19_M_get_Tp_allocatorEv
	.type	_ZNKSt12_Vector_baseI9SaveEntrySaIS0_EE19_M_get_Tp_allocatorEv, @function
_ZNKSt12_Vector_baseI9SaveEntrySaIS0_EE19_M_get_Tp_allocatorEv:
.LFB14739:
	.cfi_startproc
# /usr/include/c++/15.2.1/bits/stl_vector.h:312:       _M_get_Tp_allocator() const _GLIBCXX_NOEXCEPT
	mov	rax, rdi	# this, this
# /usr/include/c++/15.2.1/bits/stl_vector.h:313:       { return this->_M_impl; }
	ret	
	.cfi_endproc
.LFE14739:
	.size	_ZNKSt12_Vector_baseI9SaveEntrySaIS0_EE19_M_get_Tp_allocatorEv, .-_ZNKSt12_Vector_baseI9SaveEntrySaIS0_EE19_M_get_Tp_allocatorEv
	.section	.text._ZNKSt6vectorI9SaveEntrySaIS0_EE8max_sizeEv,"axG",@progbits,_ZNKSt6vectorI9SaveEntrySaIS0_EE8max_sizeEv,comdat
	.align 2
	.p2align 4
	.weak	_ZNKSt6vectorI9SaveEntrySaIS0_EE8max_sizeEv
	.type	_ZNKSt6vectorI9SaveEntrySaIS0_EE8max_sizeEv, @function
_ZNKSt6vectorI9SaveEntrySaIS0_EE8max_sizeEv:
.LFB14698:
	.cfi_startproc
# /usr/include/c++/15.2.1/bits/stl_vector.h:1129:       { return _S_max_size(_M_get_Tp_allocator()); }
	jmp	_ZNSt6vectorI9SaveEntrySaIS0_EE11_S_max_sizeERKS1_.isra.0	#
	.cfi_endproc
.LFE14698:
	.size	_ZNKSt6vectorI9SaveEntrySaIS0_EE8max_sizeEv, .-_ZNKSt6vectorI9SaveEntrySaIS0_EE8max_sizeEv
	.section	.text._ZNKSt6vectorI9SaveEntrySaIS0_EE12_M_check_lenEmPKc,"axG",@progbits,_ZNKSt6vectorI9SaveEntrySaIS0_EE12_M_check_lenEmPKc,comdat
	.align 2
	.p2align 4
	.weak	_ZNKSt6vectorI9SaveEntrySaIS0_EE12_M_check_lenEmPKc
	.type	_ZNKSt6vectorI9SaveEntrySaIS0_EE12_M_check_lenEmPKc, @function
_ZNKSt6vectorI9SaveEntrySaIS0_EE12_M_check_lenEmPKc:
.LFB14580:
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
	mov	QWORD PTR 24[rsp], r12	# D.189525, __s
	mov	r12, rdx	# __s, __s
# /usr/include/c++/15.2.1/bits/stl_vector.h:2204: 	if (max_size() - size() < __n)
	call	_ZNKSt6vectorI9SaveEntrySaIS0_EE8max_sizeEv	#
# /usr/include/c++/15.2.1/bits/stl_vector.h:2204: 	if (max_size() - size() < __n)
	mov	rsi, QWORD PTR 8[rbp]	# MEM[(struct SaveEntry * *)this_10(D) + 8B], MEM[(struct SaveEntry * *)this_10(D) + 8B]
	mov	rdi, QWORD PTR 0[rbp]	# MEM[(struct SaveEntry * *)this_10(D)], MEM[(struct SaveEntry * *)this_10(D)]
# /usr/include/c++/15.2.1/bits/stl_vector.h:2204: 	if (max_size() - size() < __n)
	mov	rdx, rax	# _1,
# /usr/include/c++/15.2.1/bits/stl_vector.h:2204: 	if (max_size() - size() < __n)
	call	_ZNKSt6vectorI9SaveEntrySaIS0_EE4sizeEv.isra.0	#
# /usr/include/c++/15.2.1/bits/stl_vector.h:2204: 	if (max_size() - size() < __n)
	sub	rdx, rax	# _3, _2
# /usr/include/c++/15.2.1/bits/stl_vector.h:2204: 	if (max_size() - size() < __n)
	cmp	rdx, QWORD PTR 8[rsp]	# _3, __n
	jb	.L358	#,
# /usr/include/c++/15.2.1/bits/stl_vector.h:2207: 	const size_type __len = size() + (std::max)(size(), __n);
	lea	rsi, 8[rsp]	# tmp119,
	lea	rdi, 16[rsp]	# tmp120,
	mov	rbx, rax	# _2,
	xor	r12d, r12d	# _19
# /usr/include/c++/15.2.1/bits/stl_vector.h:2207: 	const size_type __len = size() + (std::max)(size(), __n);
	mov	QWORD PTR 16[rsp], rax	# D.185397, _2
# /usr/include/c++/15.2.1/bits/stl_vector.h:2207: 	const size_type __len = size() + (std::max)(size(), __n);
	call	_ZSt3maxImERKT_S2_S2_	#
# /usr/include/c++/15.2.1/bits/stl_vector.h:2208: 	return (__len < size() || __len > max_size()) ? max_size() : __len;
	mov	rdi, rbp	#, this
	add	rbx, QWORD PTR [rax]	# tmp121, *_5
	setc	r12b	#, _19
	call	_ZNKSt6vectorI9SaveEntrySaIS0_EE8max_sizeEv	#
# /usr/include/c++/15.2.1/bits/stl_vector.h:2208: 	return (__len < size() || __len > max_size()) ? max_size() : __len;
	cmp	rax, rbx	# <retval>, tmp121
	cmovbe	rbx, rax	# <retval>,, tmp125
	test	r12, r12	# _19
	cmove	rax, rbx	# tmp125,, <retval>
# /usr/include/c++/15.2.1/bits/stl_vector.h:2209:       }
	mov	rdx, QWORD PTR 24[rsp]	# tmp134, D.189525
	sub	rdx, QWORD PTR fs:40	# tmp134, MEM[(<address-space-1> long unsigned int *)40B]
	jne	.L357	#,
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
.L358:
	.cfi_restore_state
# /usr/include/c++/15.2.1/bits/stl_vector.h:2205: 	  __throw_length_error(__N(__s));
	mov	rax, QWORD PTR 24[rsp]	# tmp133, D.189525
	sub	rax, QWORD PTR fs:40	# tmp133, MEM[(<address-space-1> long unsigned int *)40B]
	je	.L351	#,
.L357:
# /usr/include/c++/15.2.1/bits/stl_vector.h:2209:       }
	call	[QWORD PTR __stack_chk_fail@GOTPCREL[rip]]	#
.L351:
# /usr/include/c++/15.2.1/bits/stl_vector.h:2205: 	  __throw_length_error(__N(__s));
	mov	rdi, r12	#, __s
	call	[QWORD PTR _ZSt20__throw_length_errorPKc@GOTPCREL[rip]]	#
	.cfi_endproc
.LFE14580:
	.size	_ZNKSt6vectorI9SaveEntrySaIS0_EE12_M_check_lenEmPKc, .-_ZNKSt6vectorI9SaveEntrySaIS0_EE12_M_check_lenEmPKc
	.section	.text._ZNSt10_Head_baseILm0EPNSt10filesystem7__cxx114path5_List5_ImplELb0EE7_M_headERS6_,"axG",@progbits,_ZNSt10_Head_baseILm0EPNSt10filesystem7__cxx114path5_List5_ImplELb0EE7_M_headERS6_,comdat
	.p2align 4
	.weak	_ZNSt10_Head_baseILm0EPNSt10filesystem7__cxx114path5_List5_ImplELb0EE7_M_headERS6_
	.type	_ZNSt10_Head_baseILm0EPNSt10filesystem7__cxx114path5_List5_ImplELb0EE7_M_headERS6_, @function
_ZNSt10_Head_baseILm0EPNSt10filesystem7__cxx114path5_List5_ImplELb0EE7_M_headERS6_:
.LFB14755:
	.cfi_startproc
# /usr/include/c++/15.2.1/tuple:246:       _M_head(_Head_base& __b) noexcept { return __b._M_head_impl; }
	mov	rax, rdi	# __b, __b
# /usr/include/c++/15.2.1/tuple:246:       _M_head(_Head_base& __b) noexcept { return __b._M_head_impl; }
	ret	
	.cfi_endproc
.LFE14755:
	.size	_ZNSt10_Head_baseILm0EPNSt10filesystem7__cxx114path5_List5_ImplELb0EE7_M_headERS6_, .-_ZNSt10_Head_baseILm0EPNSt10filesystem7__cxx114path5_List5_ImplELb0EE7_M_headERS6_
	.section	.text._ZNSt11_Tuple_implILm0EJPNSt10filesystem7__cxx114path5_List5_ImplENS3_13_Impl_deleterEEE7_M_headERS7_,"axG",@progbits,_ZNSt11_Tuple_implILm0EJPNSt10filesystem7__cxx114path5_List5_ImplENS3_13_Impl_deleterEEE7_M_headERS7_,comdat
	.p2align 4
	.weak	_ZNSt11_Tuple_implILm0EJPNSt10filesystem7__cxx114path5_List5_ImplENS3_13_Impl_deleterEEE7_M_headERS7_
	.type	_ZNSt11_Tuple_implILm0EJPNSt10filesystem7__cxx114path5_List5_ImplENS3_13_Impl_deleterEEE7_M_headERS7_, @function
_ZNSt11_Tuple_implILm0EJPNSt10filesystem7__cxx114path5_List5_ImplENS3_13_Impl_deleterEEE7_M_headERS7_:
.LFB14724:
	.cfi_startproc
# /usr/include/c++/15.2.1/tuple:291:       _M_head(_Tuple_impl& __t) noexcept { return _Base::_M_head(__t); }
	jmp	_ZNSt10_Head_baseILm0EPNSt10filesystem7__cxx114path5_List5_ImplELb0EE7_M_headERS6_	#
	.cfi_endproc
.LFE14724:
	.size	_ZNSt11_Tuple_implILm0EJPNSt10filesystem7__cxx114path5_List5_ImplENS3_13_Impl_deleterEEE7_M_headERS7_, .-_ZNSt11_Tuple_implILm0EJPNSt10filesystem7__cxx114path5_List5_ImplENS3_13_Impl_deleterEEE7_M_headERS7_
	.section	.text._ZSt12__get_helperILm0EPNSt10filesystem7__cxx114path5_List5_ImplEJNS3_13_Impl_deleterEEERT0_RSt11_Tuple_implIXT_EJS7_DpT1_EE,"axG",@progbits,_ZSt12__get_helperILm0EPNSt10filesystem7__cxx114path5_List5_ImplEJNS3_13_Impl_deleterEEERT0_RSt11_Tuple_implIXT_EJS7_DpT1_EE,comdat
	.p2align 4
	.weak	_ZSt12__get_helperILm0EPNSt10filesystem7__cxx114path5_List5_ImplEJNS3_13_Impl_deleterEEERT0_RSt11_Tuple_implIXT_EJS7_DpT1_EE
	.type	_ZSt12__get_helperILm0EPNSt10filesystem7__cxx114path5_List5_ImplEJNS3_13_Impl_deleterEEERT0_RSt11_Tuple_implIXT_EJS7_DpT1_EE, @function
_ZSt12__get_helperILm0EPNSt10filesystem7__cxx114path5_List5_ImplEJNS3_13_Impl_deleterEEERT0_RSt11_Tuple_implIXT_EJS7_DpT1_EE:
.LFB14671:
	.cfi_startproc
# /usr/include/c++/15.2.1/tuple:2429:     { return _Tuple_impl<__i, _Head, _Tail...>::_M_head(__t); }
	jmp	_ZNSt11_Tuple_implILm0EJPNSt10filesystem7__cxx114path5_List5_ImplENS3_13_Impl_deleterEEE7_M_headERS7_	#
	.cfi_endproc
.LFE14671:
	.size	_ZSt12__get_helperILm0EPNSt10filesystem7__cxx114path5_List5_ImplEJNS3_13_Impl_deleterEEERT0_RSt11_Tuple_implIXT_EJS7_DpT1_EE, .-_ZSt12__get_helperILm0EPNSt10filesystem7__cxx114path5_List5_ImplEJNS3_13_Impl_deleterEEERT0_RSt11_Tuple_implIXT_EJS7_DpT1_EE
	.section	.text._ZSt3getILm0EJPNSt10filesystem7__cxx114path5_List5_ImplENS3_13_Impl_deleterEEERNSt13tuple_elementIXT_ESt5tupleIJDpT0_EEE4typeERSB_,"axG",@progbits,_ZSt3getILm0EJPNSt10filesystem7__cxx114path5_List5_ImplENS3_13_Impl_deleterEEERNSt13tuple_elementIXT_ESt5tupleIJDpT0_EEE4typeERSB_,comdat
	.p2align 4
	.weak	_ZSt3getILm0EJPNSt10filesystem7__cxx114path5_List5_ImplENS3_13_Impl_deleterEEERNSt13tuple_elementIXT_ESt5tupleIJDpT0_EEE4typeERSB_
	.type	_ZSt3getILm0EJPNSt10filesystem7__cxx114path5_List5_ImplENS3_13_Impl_deleterEEERNSt13tuple_elementIXT_ESt5tupleIJDpT0_EEE4typeERSB_, @function
_ZSt3getILm0EJPNSt10filesystem7__cxx114path5_List5_ImplENS3_13_Impl_deleterEEERNSt13tuple_elementIXT_ESt5tupleIJDpT0_EEE4typeERSB_:
.LFB14530:
	.cfi_startproc
# /usr/include/c++/15.2.1/tuple:2445:     { return std::__get_helper<__i>(__t); }
	jmp	_ZSt12__get_helperILm0EPNSt10filesystem7__cxx114path5_List5_ImplEJNS3_13_Impl_deleterEEERT0_RSt11_Tuple_implIXT_EJS7_DpT1_EE	#
	.cfi_endproc
.LFE14530:
	.size	_ZSt3getILm0EJPNSt10filesystem7__cxx114path5_List5_ImplENS3_13_Impl_deleterEEERNSt13tuple_elementIXT_ESt5tupleIJDpT0_EEE4typeERSB_, .-_ZSt3getILm0EJPNSt10filesystem7__cxx114path5_List5_ImplENS3_13_Impl_deleterEEERNSt13tuple_elementIXT_ESt5tupleIJDpT0_EEE4typeERSB_
	.section	.text._ZNSt15__uniq_ptr_implINSt10filesystem7__cxx114path5_List5_ImplENS3_13_Impl_deleterEE6_M_ptrEv,"axG",@progbits,_ZNSt15__uniq_ptr_implINSt10filesystem7__cxx114path5_List5_ImplENS3_13_Impl_deleterEE6_M_ptrEv,comdat
	.align 2
	.p2align 4
	.weak	_ZNSt15__uniq_ptr_implINSt10filesystem7__cxx114path5_List5_ImplENS3_13_Impl_deleterEE6_M_ptrEv
	.type	_ZNSt15__uniq_ptr_implINSt10filesystem7__cxx114path5_List5_ImplENS3_13_Impl_deleterEE6_M_ptrEv, @function
_ZNSt15__uniq_ptr_implINSt10filesystem7__cxx114path5_List5_ImplENS3_13_Impl_deleterEE6_M_ptrEv:
.LFB14294:
	.cfi_startproc
# /usr/include/c++/15.2.1/bits/unique_ptr.h:190:       pointer&   _M_ptr() noexcept { return std::get<0>(_M_t); }
	jmp	_ZSt3getILm0EJPNSt10filesystem7__cxx114path5_List5_ImplENS3_13_Impl_deleterEEERNSt13tuple_elementIXT_ESt5tupleIJDpT0_EEE4typeERSB_	#
	.cfi_endproc
.LFE14294:
	.size	_ZNSt15__uniq_ptr_implINSt10filesystem7__cxx114path5_List5_ImplENS3_13_Impl_deleterEE6_M_ptrEv, .-_ZNSt15__uniq_ptr_implINSt10filesystem7__cxx114path5_List5_ImplENS3_13_Impl_deleterEE6_M_ptrEv
	.section	.text._ZNSt10_Head_baseILm1ENSt10filesystem7__cxx114path5_List13_Impl_deleterELb1EE7_M_headERS5_,"axG",@progbits,_ZNSt10_Head_baseILm1ENSt10filesystem7__cxx114path5_List13_Impl_deleterELb1EE7_M_headERS5_,comdat
	.p2align 4
	.weak	_ZNSt10_Head_baseILm1ENSt10filesystem7__cxx114path5_List13_Impl_deleterELb1EE7_M_headERS5_
	.type	_ZNSt10_Head_baseILm1ENSt10filesystem7__cxx114path5_List13_Impl_deleterELb1EE7_M_headERS5_, @function
_ZNSt10_Head_baseILm1ENSt10filesystem7__cxx114path5_List13_Impl_deleterELb1EE7_M_headERS5_:
.LFB14757:
	.cfi_startproc
# /usr/include/c++/15.2.1/tuple:137:       _M_head(_Head_base& __b) noexcept { return __b._M_head_impl; }
	mov	rax, rdi	# __b, __b
# /usr/include/c++/15.2.1/tuple:137:       _M_head(_Head_base& __b) noexcept { return __b._M_head_impl; }
	ret	
	.cfi_endproc
.LFE14757:
	.size	_ZNSt10_Head_baseILm1ENSt10filesystem7__cxx114path5_List13_Impl_deleterELb1EE7_M_headERS5_, .-_ZNSt10_Head_baseILm1ENSt10filesystem7__cxx114path5_List13_Impl_deleterELb1EE7_M_headERS5_
	.section	.text._ZNSt11_Tuple_implILm1EJNSt10filesystem7__cxx114path5_List13_Impl_deleterEEE7_M_headERS5_,"axG",@progbits,_ZNSt11_Tuple_implILm1EJNSt10filesystem7__cxx114path5_List13_Impl_deleterEEE7_M_headERS5_,comdat
	.p2align 4
	.weak	_ZNSt11_Tuple_implILm1EJNSt10filesystem7__cxx114path5_List13_Impl_deleterEEE7_M_headERS5_
	.type	_ZNSt11_Tuple_implILm1EJNSt10filesystem7__cxx114path5_List13_Impl_deleterEEE7_M_headERS5_, @function
_ZNSt11_Tuple_implILm1EJNSt10filesystem7__cxx114path5_List13_Impl_deleterEEE7_M_headERS5_:
.LFB14726:
	.cfi_startproc
# /usr/include/c++/15.2.1/tuple:554:       _M_head(_Tuple_impl& __t) noexcept { return _Base::_M_head(__t); }
	jmp	_ZNSt10_Head_baseILm1ENSt10filesystem7__cxx114path5_List13_Impl_deleterELb1EE7_M_headERS5_	#
	.cfi_endproc
.LFE14726:
	.size	_ZNSt11_Tuple_implILm1EJNSt10filesystem7__cxx114path5_List13_Impl_deleterEEE7_M_headERS5_, .-_ZNSt11_Tuple_implILm1EJNSt10filesystem7__cxx114path5_List13_Impl_deleterEEE7_M_headERS5_
	.section	.text._ZSt12__get_helperILm1ENSt10filesystem7__cxx114path5_List13_Impl_deleterEJEERT0_RSt11_Tuple_implIXT_EJS5_DpT1_EE,"axG",@progbits,_ZSt12__get_helperILm1ENSt10filesystem7__cxx114path5_List13_Impl_deleterEJEERT0_RSt11_Tuple_implIXT_EJS5_DpT1_EE,comdat
	.p2align 4
	.weak	_ZSt12__get_helperILm1ENSt10filesystem7__cxx114path5_List13_Impl_deleterEJEERT0_RSt11_Tuple_implIXT_EJS5_DpT1_EE
	.type	_ZSt12__get_helperILm1ENSt10filesystem7__cxx114path5_List13_Impl_deleterEJEERT0_RSt11_Tuple_implIXT_EJS5_DpT1_EE, @function
_ZSt12__get_helperILm1ENSt10filesystem7__cxx114path5_List13_Impl_deleterEJEERT0_RSt11_Tuple_implIXT_EJS5_DpT1_EE:
.LFB14675:
	.cfi_startproc
# /usr/include/c++/15.2.1/tuple:2429:     { return _Tuple_impl<__i, _Head, _Tail...>::_M_head(__t); }
	jmp	_ZNSt11_Tuple_implILm1EJNSt10filesystem7__cxx114path5_List13_Impl_deleterEEE7_M_headERS5_	#
	.cfi_endproc
.LFE14675:
	.size	_ZSt12__get_helperILm1ENSt10filesystem7__cxx114path5_List13_Impl_deleterEJEERT0_RSt11_Tuple_implIXT_EJS5_DpT1_EE, .-_ZSt12__get_helperILm1ENSt10filesystem7__cxx114path5_List13_Impl_deleterEJEERT0_RSt11_Tuple_implIXT_EJS5_DpT1_EE
	.section	.text._ZSt3getILm1EJPNSt10filesystem7__cxx114path5_List5_ImplENS3_13_Impl_deleterEEERNSt13tuple_elementIXT_ESt5tupleIJDpT0_EEE4typeERSB_,"axG",@progbits,_ZSt3getILm1EJPNSt10filesystem7__cxx114path5_List5_ImplENS3_13_Impl_deleterEEERNSt13tuple_elementIXT_ESt5tupleIJDpT0_EEE4typeERSB_,comdat
	.p2align 4
	.weak	_ZSt3getILm1EJPNSt10filesystem7__cxx114path5_List5_ImplENS3_13_Impl_deleterEEERNSt13tuple_elementIXT_ESt5tupleIJDpT0_EEE4typeERSB_
	.type	_ZSt3getILm1EJPNSt10filesystem7__cxx114path5_List5_ImplENS3_13_Impl_deleterEEERNSt13tuple_elementIXT_ESt5tupleIJDpT0_EEE4typeERSB_, @function
_ZSt3getILm1EJPNSt10filesystem7__cxx114path5_List5_ImplENS3_13_Impl_deleterEEERNSt13tuple_elementIXT_ESt5tupleIJDpT0_EEE4typeERSB_:
.LFB14536:
	.cfi_startproc
# /usr/include/c++/15.2.1/tuple:2445:     { return std::__get_helper<__i>(__t); }
	jmp	_ZSt12__get_helperILm1ENSt10filesystem7__cxx114path5_List13_Impl_deleterEJEERT0_RSt11_Tuple_implIXT_EJS5_DpT1_EE	#
	.cfi_endproc
.LFE14536:
	.size	_ZSt3getILm1EJPNSt10filesystem7__cxx114path5_List5_ImplENS3_13_Impl_deleterEEERNSt13tuple_elementIXT_ESt5tupleIJDpT0_EEE4typeERSB_, .-_ZSt3getILm1EJPNSt10filesystem7__cxx114path5_List5_ImplENS3_13_Impl_deleterEEERNSt13tuple_elementIXT_ESt5tupleIJDpT0_EEE4typeERSB_
	.section	.text._ZNSt15__uniq_ptr_implINSt10filesystem7__cxx114path5_List5_ImplENS3_13_Impl_deleterEE10_M_deleterEv,"axG",@progbits,_ZNSt15__uniq_ptr_implINSt10filesystem7__cxx114path5_List5_ImplENS3_13_Impl_deleterEE10_M_deleterEv,comdat
	.align 2
	.p2align 4
	.weak	_ZNSt15__uniq_ptr_implINSt10filesystem7__cxx114path5_List5_ImplENS3_13_Impl_deleterEE10_M_deleterEv
	.type	_ZNSt15__uniq_ptr_implINSt10filesystem7__cxx114path5_List5_ImplENS3_13_Impl_deleterEE10_M_deleterEv, @function
_ZNSt15__uniq_ptr_implINSt10filesystem7__cxx114path5_List5_ImplENS3_13_Impl_deleterEE10_M_deleterEv:
.LFB14315:
	.cfi_startproc
# /usr/include/c++/15.2.1/bits/unique_ptr.h:194:       _Dp&       _M_deleter() noexcept { return std::get<1>(_M_t); }
	jmp	_ZSt3getILm1EJPNSt10filesystem7__cxx114path5_List5_ImplENS3_13_Impl_deleterEEERNSt13tuple_elementIXT_ESt5tupleIJDpT0_EEE4typeERSB_	#
	.cfi_endproc
.LFE14315:
	.size	_ZNSt15__uniq_ptr_implINSt10filesystem7__cxx114path5_List5_ImplENS3_13_Impl_deleterEE10_M_deleterEv, .-_ZNSt15__uniq_ptr_implINSt10filesystem7__cxx114path5_List5_ImplENS3_13_Impl_deleterEE10_M_deleterEv
	.section	.text._ZNSt10unique_ptrINSt10filesystem7__cxx114path5_List5_ImplENS3_13_Impl_deleterEE11get_deleterEv,"axG",@progbits,_ZNSt10unique_ptrINSt10filesystem7__cxx114path5_List5_ImplENS3_13_Impl_deleterEE11get_deleterEv,comdat
	.align 2
	.p2align 4
	.weak	_ZNSt10unique_ptrINSt10filesystem7__cxx114path5_List5_ImplENS3_13_Impl_deleterEE11get_deleterEv
	.type	_ZNSt10unique_ptrINSt10filesystem7__cxx114path5_List5_ImplENS3_13_Impl_deleterEE11get_deleterEv, @function
_ZNSt10unique_ptrINSt10filesystem7__cxx114path5_List5_ImplENS3_13_Impl_deleterEE11get_deleterEv:
.LFB14295:
	.cfi_startproc
# /usr/include/c++/15.2.1/bits/unique_ptr.h:478:       { return _M_t._M_deleter(); }
	jmp	_ZNSt15__uniq_ptr_implINSt10filesystem7__cxx114path5_List5_ImplENS3_13_Impl_deleterEE10_M_deleterEv	#
	.cfi_endproc
.LFE14295:
	.size	_ZNSt10unique_ptrINSt10filesystem7__cxx114path5_List5_ImplENS3_13_Impl_deleterEE11get_deleterEv, .-_ZNSt10unique_ptrINSt10filesystem7__cxx114path5_List5_ImplENS3_13_Impl_deleterEE11get_deleterEv
	.section	.text._ZNSt10unique_ptrINSt10filesystem7__cxx114path5_List5_ImplENS3_13_Impl_deleterEED2Ev,"axG",@progbits,_ZNSt10unique_ptrINSt10filesystem7__cxx114path5_List5_ImplENS3_13_Impl_deleterEED5Ev,comdat
	.align 2
	.p2align 4
	.weak	_ZNSt10unique_ptrINSt10filesystem7__cxx114path5_List5_ImplENS3_13_Impl_deleterEED2Ev
	.type	_ZNSt10unique_ptrINSt10filesystem7__cxx114path5_List5_ImplENS3_13_Impl_deleterEED2Ev, @function
_ZNSt10unique_ptrINSt10filesystem7__cxx114path5_List5_ImplENS3_13_Impl_deleterEED2Ev:
.LFB13984:
	.cfi_startproc
	push	rbx	#
	.cfi_def_cfa_offset 16
	.cfi_offset 3, -16
	mov	rbx, rdi	# this, this
	sub	rsp, 16	#,
	.cfi_def_cfa_offset 32
# /usr/include/c++/15.2.1/bits/unique_ptr.h:396: 	auto& __ptr = _M_t._M_ptr();
	call	_ZNSt15__uniq_ptr_implINSt10filesystem7__cxx114path5_List5_ImplENS3_13_Impl_deleterEE6_M_ptrEv	#
# /usr/include/c++/15.2.1/bits/unique_ptr.h:397: 	if (__ptr != nullptr)
	mov	rsi, QWORD PTR [rax]	# _2, *__ptr_7
# /usr/include/c++/15.2.1/bits/unique_ptr.h:396: 	auto& __ptr = _M_t._M_ptr();
	mov	rdx, rax	# __ptr,
# /usr/include/c++/15.2.1/bits/unique_ptr.h:397: 	if (__ptr != nullptr)
	test	rsi, rsi	# _2
	je	.L371	#,
# /usr/include/c++/15.2.1/bits/unique_ptr.h:398: 	  get_deleter()(std::move(__ptr));
	mov	rdi, rbx	#, this
	mov	QWORD PTR 8[rsp], rsi	# %sfp, _2
	mov	QWORD PTR [rsp], rax	# %sfp, __ptr
	call	_ZNSt10unique_ptrINSt10filesystem7__cxx114path5_List5_ImplENS3_13_Impl_deleterEE11get_deleterEv	#
# /usr/include/c++/15.2.1/bits/unique_ptr.h:398: 	  get_deleter()(std::move(__ptr));
	mov	rsi, QWORD PTR 8[rsp]	# _2, %sfp
	mov	rdi, rax	#, _3
	call	[QWORD PTR _ZNKSt10filesystem7__cxx114path5_List13_Impl_deleterclEPNS2_5_ImplE@GOTPCREL[rip]]	#
	mov	rdx, QWORD PTR [rsp]	# __ptr, %sfp
.L371:
# /usr/include/c++/15.2.1/bits/unique_ptr.h:399: 	__ptr = pointer();
	mov	QWORD PTR [rdx], 0	# *__ptr_7,
# /usr/include/c++/15.2.1/bits/unique_ptr.h:400:       }
	add	rsp, 16	#,
	.cfi_def_cfa_offset 16
	pop	rbx	#
	.cfi_def_cfa_offset 8
	ret	
	.cfi_endproc
.LFE13984:
	.size	_ZNSt10unique_ptrINSt10filesystem7__cxx114path5_List5_ImplENS3_13_Impl_deleterEED2Ev, .-_ZNSt10unique_ptrINSt10filesystem7__cxx114path5_List5_ImplENS3_13_Impl_deleterEED2Ev
	.weak	_ZNSt10unique_ptrINSt10filesystem7__cxx114path5_List5_ImplENS3_13_Impl_deleterEED1Ev
	.set	_ZNSt10unique_ptrINSt10filesystem7__cxx114path5_List5_ImplENS3_13_Impl_deleterEED1Ev,_ZNSt10unique_ptrINSt10filesystem7__cxx114path5_List5_ImplENS3_13_Impl_deleterEED2Ev
	.section	.text._ZNSt10filesystem7__cxx114path5_ListD2Ev,"axG",@progbits,_ZNSt10filesystem7__cxx114path5_ListD5Ev,comdat
	.align 2
	.p2align 4
	.weak	_ZNSt10filesystem7__cxx114path5_ListD2Ev
	.type	_ZNSt10filesystem7__cxx114path5_ListD2Ev, @function
_ZNSt10filesystem7__cxx114path5_ListD2Ev:
.LFB13240:
	.cfi_startproc
# /usr/include/c++/15.2.1/bits/fs_path.h:689:       ~_List() = default;
	jmp	_ZNSt10unique_ptrINSt10filesystem7__cxx114path5_List5_ImplENS3_13_Impl_deleterEED1Ev	#
	.cfi_endproc
.LFE13240:
	.size	_ZNSt10filesystem7__cxx114path5_ListD2Ev, .-_ZNSt10filesystem7__cxx114path5_ListD2Ev
	.weak	_ZNSt10filesystem7__cxx114path5_ListD1Ev
	.set	_ZNSt10filesystem7__cxx114path5_ListD1Ev,_ZNSt10filesystem7__cxx114path5_ListD2Ev
	.section	.text._ZNSt10filesystem7__cxx114pathC2INSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEEES1_EERKT_NS1_6formatE,"axG",@progbits,_ZNSt10filesystem7__cxx114pathC5INSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEEES1_EERKT_NS1_6formatE,comdat
	.align 2
	.p2align 4
	.weak	_ZNSt10filesystem7__cxx114pathC2INSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEEES1_EERKT_NS1_6formatE
	.type	_ZNSt10filesystem7__cxx114pathC2INSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEEES1_EERKT_NS1_6formatE, @function
_ZNSt10filesystem7__cxx114pathC2INSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEEES1_EERKT_NS1_6formatE:
.LFB14081:
	.cfi_startproc
	.cfi_personality 0x9b,DW.ref.__gxx_personality_v0
	.cfi_lsda 0x1b,.LLSDA14081
	push	rbp	#
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	push	rbx	#
	.cfi_def_cfa_offset 24
	.cfi_offset 3, -24
	sub	rsp, 72	#,
	.cfi_def_cfa_offset 96
# /usr/include/c++/15.2.1/bits/fs_path.h:330:       path(_Source const& __source, format = auto_format)
	mov	rbx, QWORD PTR fs:40	# this, MEM[(<address-space-1> long unsigned int *)40B]
	mov	QWORD PTR 56[rsp], rbx	# D.189573, this
	mov	rbx, rdi	# this, this
# /usr/include/c++/15.2.1/bits/fs_path.h:331:       : _M_pathname(_S_convert(__detail::__effective_range(__source)))
	mov	rdi, rsi	#, __source
	call	_ZNSt10filesystem7__cxx118__detail17__effective_rangeIcSt11char_traitsIcESaIcEEESt17basic_string_viewIT_S3_IS7_EERKNSt7__cxx1112basic_stringIS7_T0_T1_EE	#
# /usr/include/c++/15.2.1/bits/fs_path.h:331:       : _M_pathname(_S_convert(__detail::__effective_range(__source)))
	mov	rdi, rax	#, D.187638
	mov	rsi, rdx	#, D.187638
	call	_ZNSt10filesystem7__cxx114path10_S_convertISt17basic_string_viewIcSt11char_traitsIcEEEEDaT_	#
# /usr/include/c++/15.2.1/bits/fs_path.h:331:       : _M_pathname(_S_convert(__detail::__effective_range(__source)))
	lea	rsi, 32[rsp]	# tmp113,
# /usr/include/c++/15.2.1/bits/fs_path.h:331:       : _M_pathname(_S_convert(__detail::__effective_range(__source)))
	mov	QWORD PTR 40[rsp], rdx	# D.181254,
# /usr/include/c++/15.2.1/bits/fs_path.h:331:       : _M_pathname(_S_convert(__detail::__effective_range(__source)))
	lea	rdx, 31[rsp]	# tmp112,
# /usr/include/c++/15.2.1/bits/fs_path.h:331:       : _M_pathname(_S_convert(__detail::__effective_range(__source)))
	mov	QWORD PTR 32[rsp], rax	# D.181254, tmp126
# /usr/include/c++/15.2.1/bits/fs_path.h:331:       : _M_pathname(_S_convert(__detail::__effective_range(__source)))
	mov	rdi, rbx	#, this
# /usr/include/c++/15.2.1/bits/fs_path.h:331:       : _M_pathname(_S_convert(__detail::__effective_range(__source)))
	lea	rbp, 32[rbx]	# _2,
.LEHB34:
# /usr/include/c++/15.2.1/bits/fs_path.h:331:       : _M_pathname(_S_convert(__detail::__effective_range(__source)))
	call	_ZNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEEC1ISt17basic_string_viewIcS2_EvEERKT_RKS3_	#
.LEHE34:
# /usr/include/c++/15.2.1/bits/fs_path.h:331:       : _M_pathname(_S_convert(__detail::__effective_range(__source)))
	mov	rdi, rbp	#, _2
.LEHB35:
	call	[QWORD PTR _ZNSt10filesystem7__cxx114path5_ListC1Ev@GOTPCREL[rip]]	#
.LEHE35:
# /usr/include/c++/15.2.1/bits/fs_path.h:332:       { _M_split_cmpts(); }
	mov	rdi, rbx	#, this
.LEHB36:
	call	[QWORD PTR _ZNSt10filesystem7__cxx114path14_M_split_cmptsEv@GOTPCREL[rip]]	#
.LEHE36:
# /usr/include/c++/15.2.1/bits/fs_path.h:332:       { _M_split_cmpts(); }
	mov	rax, QWORD PTR 56[rsp]	# tmp130, D.189573
	sub	rax, QWORD PTR fs:40	# tmp130, MEM[(<address-space-1> long unsigned int *)40B]
	jne	.L386	#,
	add	rsp, 72	#,
	.cfi_remember_state
	.cfi_def_cfa_offset 24
	pop	rbx	#
	.cfi_def_cfa_offset 16
	pop	rbp	#
	.cfi_def_cfa_offset 8
	ret	
.L378:
	.cfi_restore_state
# /usr/include/c++/15.2.1/bits/fs_path.h:332:       { _M_split_cmpts(); }
	mov	rdi, rbp	#, _2
	mov	QWORD PTR 8[rsp], rax	# %sfp, tmp127
	call	_ZNSt10filesystem7__cxx114path5_ListD1Ev	#
	mov	rbp, QWORD PTR 8[rsp]	# tmp114, %sfp
.L379:
# /usr/include/c++/15.2.1/bits/fs_path.h:332:       { _M_split_cmpts(); }
	mov	rdi, rbx	#, this
	call	[QWORD PTR _ZNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEED1Ev@GOTPCREL[rip]]	#
	mov	rax, QWORD PTR 56[rsp]	# tmp129, D.189573
	sub	rax, QWORD PTR fs:40	# tmp129, MEM[(<address-space-1> long unsigned int *)40B]
	je	.L380	#,
.L386:
	call	[QWORD PTR __stack_chk_fail@GOTPCREL[rip]]	#
.L383:
	jmp	.L378	#
.L382:
	mov	rbp, rax	# tmp114, tmp128
	jmp	.L379	#
.L380:
	mov	rdi, rbp	#, tmp114
.LEHB37:
	call	[QWORD PTR _Unwind_Resume@GOTPCREL[rip]]	#
.LEHE37:
	.cfi_endproc
.LFE14081:
	.section	.gcc_except_table
.LLSDA14081:
	.byte	0xff
	.byte	0xff
	.byte	0x1
	.uleb128 .LLSDACSE14081-.LLSDACSB14081
.LLSDACSB14081:
	.uleb128 .LEHB34-.LFB14081
	.uleb128 .LEHE34-.LEHB34
	.uleb128 0
	.uleb128 0
	.uleb128 .LEHB35-.LFB14081
	.uleb128 .LEHE35-.LEHB35
	.uleb128 .L382-.LFB14081
	.uleb128 0
	.uleb128 .LEHB36-.LFB14081
	.uleb128 .LEHE36-.LEHB36
	.uleb128 .L383-.LFB14081
	.uleb128 0
	.uleb128 .LEHB37-.LFB14081
	.uleb128 .LEHE37-.LEHB37
	.uleb128 0
	.uleb128 0
.LLSDACSE14081:
	.section	.text._ZNSt10filesystem7__cxx114pathC2INSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEEES1_EERKT_NS1_6formatE,"axG",@progbits,_ZNSt10filesystem7__cxx114pathC5INSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEEES1_EERKT_NS1_6formatE,comdat
	.size	_ZNSt10filesystem7__cxx114pathC2INSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEEES1_EERKT_NS1_6formatE, .-_ZNSt10filesystem7__cxx114pathC2INSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEEES1_EERKT_NS1_6formatE
	.weak	_ZNSt10filesystem7__cxx114pathC1INSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEEES1_EERKT_NS1_6formatE
	.set	_ZNSt10filesystem7__cxx114pathC1INSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEEES1_EERKT_NS1_6formatE,_ZNSt10filesystem7__cxx114pathC2INSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEEES1_EERKT_NS1_6formatE
	.section	.text._ZNSt10filesystem7__cxx114pathD2Ev,"axG",@progbits,_ZNSt10filesystem7__cxx114pathD5Ev,comdat
	.align 2
	.p2align 4
	.weak	_ZNSt10filesystem7__cxx114pathD2Ev
	.type	_ZNSt10filesystem7__cxx114pathD2Ev, @function
_ZNSt10filesystem7__cxx114pathD2Ev:
.LFB13242:
	.cfi_startproc
	push	rbx	#
	.cfi_def_cfa_offset 16
	.cfi_offset 3, -16
# /usr/include/c++/15.2.1/bits/fs_path.h:355:     ~path() = default;
	mov	rbx, rdi	# this, this
	lea	rdi, 32[rdi]	# _1,
	call	_ZNSt10filesystem7__cxx114path5_ListD1Ev	#
# /usr/include/c++/15.2.1/bits/fs_path.h:355:     ~path() = default;
	mov	rdi, rbx	#, this
# /usr/include/c++/15.2.1/bits/fs_path.h:355:     ~path() = default;
	pop	rbx	#
	.cfi_def_cfa_offset 8
# /usr/include/c++/15.2.1/bits/fs_path.h:355:     ~path() = default;
	jmp	[QWORD PTR _ZNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEED1Ev@GOTPCREL[rip]]	#
	.cfi_endproc
.LFE13242:
	.size	_ZNSt10filesystem7__cxx114pathD2Ev, .-_ZNSt10filesystem7__cxx114pathD2Ev
	.weak	_ZNSt10filesystem7__cxx114pathD1Ev
	.set	_ZNSt10filesystem7__cxx114pathD1Ev,_ZNSt10filesystem7__cxx114pathD2Ev
	.section	.text._ZSt14__copy_move_a2ILb1EP9SaveEntryS1_S1_ET2_T0_T1_S2_,"axG",@progbits,_ZSt14__copy_move_a2ILb1EP9SaveEntryS1_S1_ET2_T0_T1_S2_,comdat
	.p2align 4
	.weak	_ZSt14__copy_move_a2ILb1EP9SaveEntryS1_S1_ET2_T0_T1_S2_
	.type	_ZSt14__copy_move_a2ILb1EP9SaveEntryS1_S1_ET2_T0_T1_S2_, @function
_ZSt14__copy_move_a2ILb1EP9SaveEntryS1_S1_ET2_T0_T1_S2_:
.LFB14777:
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
# /usr/include/c++/15.2.1/bits/stl_algobase.h:461:       for (; __first != __last; ++__result, (void)++__first)
	cmp	rsi, rdi	# __last, __first
	je	.L390	#,
	mov	rbx, rdi	# __first, __first
	mov	r12, rsi	# __last, __last
	.p2align 4
	.p2align 3
.L391:
# /usr/include/c++/15.2.1/bits/stl_algobase.h:404: 	*__out = std::move(*__in);
	mov	rsi, rbx	#, __first
	mov	rdi, rbp	#, __result
# /usr/include/c++/15.2.1/bits/stl_algobase.h:461:       for (; __first != __last; ++__result, (void)++__first)
	add	rbx, 72	# __first,
# /usr/include/c++/15.2.1/bits/stl_algobase.h:461:       for (; __first != __last; ++__result, (void)++__first)
	add	rbp, 72	# __result,
# /usr/include/c++/15.2.1/bits/stl_algobase.h:404: 	*__out = std::move(*__in);
	call	_ZN9SaveEntryaSEOS_.isra.0	#
# /usr/include/c++/15.2.1/bits/stl_algobase.h:461:       for (; __first != __last; ++__result, (void)++__first)
	cmp	rbx, r12	# __first, __last
	jne	.L391	#,
.L390:
# /usr/include/c++/15.2.1/bits/stl_algobase.h:464:     }
	mov	rax, rbp	#, __result
	pop	rbx	#
	.cfi_def_cfa_offset 24
	pop	rbp	#
	.cfi_def_cfa_offset 16
	pop	r12	#
	.cfi_def_cfa_offset 8
	ret	
	.cfi_endproc
.LFE14777:
	.size	_ZSt14__copy_move_a2ILb1EP9SaveEntryS1_S1_ET2_T0_T1_S2_, .-_ZSt14__copy_move_a2ILb1EP9SaveEntryS1_S1_ET2_T0_T1_S2_
	.section	.text._ZSt4moveIN9__gnu_cxx17__normal_iteratorIP9SaveEntrySt6vectorIS2_SaIS2_EEEES7_ET0_T_S9_S8_.isra.0,"axG",@progbits,_ZNSt6vectorI9SaveEntrySaIS0_EE8_M_eraseEN9__gnu_cxx17__normal_iteratorIPS0_S2_EE,comdat
	.p2align 4
	.type	_ZSt4moveIN9__gnu_cxx17__normal_iteratorIP9SaveEntrySt6vectorIS2_SaIS2_EEEES7_ET0_T_S9_S8_.isra.0, @function
_ZSt4moveIN9__gnu_cxx17__normal_iteratorIP9SaveEntrySt6vectorIS2_SaIS2_EEEES7_ET0_T_S9_S8_.isra.0:
.LFB14841:
	.cfi_startproc
	push	rbp	#
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	mov	rbp, rdi	# __first, __first
# /usr/include/c++/15.2.1/bits/stl_algobase.h:674:       return std::__copy_move_a<true>(std::__miter_base(__first),
	mov	rdi, rsi	#, __last
# /usr/include/c++/15.2.1/bits/stl_algobase.h:666:     move(_II __first, _II __last, _OI __result)
	push	rbx	#
	.cfi_def_cfa_offset 24
	.cfi_offset 3, -24
	sub	rsp, 24	#,
	.cfi_def_cfa_offset 48
# /usr/include/c++/15.2.1/bits/stl_algobase.h:666:     move(_II __first, _II __last, _OI __result)
	mov	QWORD PTR 8[rsp], rdx	# %sfp, __result
# /usr/include/c++/15.2.1/bits/stl_algobase.h:674:       return std::__copy_move_a<true>(std::__miter_base(__first),
	call	_ZSt12__miter_baseIN9__gnu_cxx17__normal_iteratorIP9SaveEntrySt6vectorIS2_SaIS2_EEEEET_S8_	#
# /usr/include/c++/15.2.1/bits/stl_algobase.h:674:       return std::__copy_move_a<true>(std::__miter_base(__first),
	mov	rdi, rbp	#, __first
# /usr/include/c++/15.2.1/bits/stl_algobase.h:674:       return std::__copy_move_a<true>(std::__miter_base(__first),
	mov	rbx, rax	# D.189601,
# /usr/include/c++/15.2.1/bits/stl_algobase.h:674:       return std::__copy_move_a<true>(std::__miter_base(__first),
	call	_ZSt12__miter_baseIN9__gnu_cxx17__normal_iteratorIP9SaveEntrySt6vectorIS2_SaIS2_EEEEET_S8_	#
# /usr/include/c++/15.2.1/bits/stl_algobase.h:492:     { return std::__copy_move_a2<_IsMove>(__first, __last, __result); }
	mov	rdx, QWORD PTR 8[rsp]	# __result, %sfp
# /usr/include/c++/15.2.1/bits/stl_algobase.h:676:     }
	add	rsp, 24	#,
	.cfi_def_cfa_offset 24
# /usr/include/c++/15.2.1/bits/stl_algobase.h:492:     { return std::__copy_move_a2<_IsMove>(__first, __last, __result); }
	mov	rsi, rbx	#, D.189601
	mov	rdi, rax	#, D.189600
# /usr/include/c++/15.2.1/bits/stl_algobase.h:676:     }
	pop	rbx	#
	.cfi_def_cfa_offset 16
	pop	rbp	#
	.cfi_def_cfa_offset 8
# /usr/include/c++/15.2.1/bits/stl_algobase.h:492:     { return std::__copy_move_a2<_IsMove>(__first, __last, __result); }
	jmp	_ZSt14__copy_move_a2ILb1EP9SaveEntryS1_S1_ET2_T0_T1_S2_	#
	.cfi_endproc
.LFE14841:
	.size	_ZSt4moveIN9__gnu_cxx17__normal_iteratorIP9SaveEntrySt6vectorIS2_SaIS2_EEEES7_ET0_T_S9_S8_.isra.0, .-_ZSt4moveIN9__gnu_cxx17__normal_iteratorIP9SaveEntrySt6vectorIS2_SaIS2_EEEES7_ET0_T_S9_S8_.isra.0
	.section	.text._ZNSt6vectorI9SaveEntrySaIS0_EE8_M_eraseEN9__gnu_cxx17__normal_iteratorIPS0_S2_EE,"axG",@progbits,_ZNSt6vectorI9SaveEntrySaIS0_EE8_M_eraseEN9__gnu_cxx17__normal_iteratorIPS0_S2_EE,comdat
	.align 2
	.p2align 4
	.weak	_ZNSt6vectorI9SaveEntrySaIS0_EE8_M_eraseEN9__gnu_cxx17__normal_iteratorIPS0_S2_EE
	.type	_ZNSt6vectorI9SaveEntrySaIS0_EE8_M_eraseEN9__gnu_cxx17__normal_iteratorIPS0_S2_EE, @function
_ZNSt6vectorI9SaveEntrySaIS0_EE8_M_eraseEN9__gnu_cxx17__normal_iteratorIPS0_S2_EE:
.LFB14427:
	.cfi_startproc
	push	rbp	#
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	mov	rbp, rsi	# __position$_M_current, __position
	push	rbx	#
	.cfi_def_cfa_offset 24
	.cfi_offset 3, -24
	mov	rbx, rdi	# this, this
	sub	rsp, 24	#,
	.cfi_def_cfa_offset 48
# /usr/include/c++/15.2.1/bits/vector.tcc:184:       if (__position + 1 != end())
	call	_ZNSt6vectorI9SaveEntrySaIS0_EE3endEv	#
# /usr/include/c++/15.2.1/bits/stl_iterator.h:1148:       { return __normal_iterator(_M_current + __n); }
	lea	rcx, 72[rbp]	# _14,
# /usr/include/c++/15.2.1/bits/vector.tcc:184:       if (__position + 1 != end())
	cmp	rcx, rax	# _14, D.184129
	je	.L397	#,
# /usr/include/c++/15.2.1/bits/vector.tcc:185: 	_GLIBCXX_MOVE3(__position + 1, end(), __position);
	mov	rdi, rbx	#, this
	mov	QWORD PTR 8[rsp], rcx	# %sfp, _14
	call	_ZNSt6vectorI9SaveEntrySaIS0_EE3endEv	#
# /usr/include/c++/15.2.1/bits/vector.tcc:185: 	_GLIBCXX_MOVE3(__position + 1, end(), __position);
	mov	rdi, QWORD PTR 8[rsp]	#, %sfp
	mov	rdx, rbp	#, __position$_M_current
	mov	rsi, rax	#, D.187719
	call	_ZSt4moveIN9__gnu_cxx17__normal_iteratorIP9SaveEntrySt6vectorIS2_SaIS2_EEEES7_ET0_T_S9_S8_.isra.0	#
.L397:
# /usr/include/c++/15.2.1/bits/vector.tcc:186:       --this->_M_impl._M_finish;
	mov	rax, QWORD PTR 8[rbx]	# tmp117, this_5(D)->D.154016._M_impl.D.153351._M_finish
	lea	rdi, -72[rax]	# _2,
	mov	QWORD PTR 8[rbx], rdi	# this_5(D)->D.154016._M_impl.D.153351._M_finish, _2
# /usr/include/c++/15.2.1/bits/new_allocator.h:198: 	{ __p->~_Up(); }
	call	_ZN9SaveEntryD1Ev	#
# /usr/include/c++/15.2.1/bits/vector.tcc:190:     }
	add	rsp, 24	#,
	.cfi_def_cfa_offset 24
	mov	rax, rbp	#, __position$_M_current
	pop	rbx	#
	.cfi_def_cfa_offset 16
	pop	rbp	#
	.cfi_def_cfa_offset 8
	ret	
	.cfi_endproc
.LFE14427:
	.size	_ZNSt6vectorI9SaveEntrySaIS0_EE8_M_eraseEN9__gnu_cxx17__normal_iteratorIPS0_S2_EE, .-_ZNSt6vectorI9SaveEntrySaIS0_EE8_M_eraseEN9__gnu_cxx17__normal_iteratorIPS0_S2_EE
	.text
	.align 2
	.p2align 4
	.type	_ZNSt6vectorI9SaveEntrySaIS0_EE5eraseEN9__gnu_cxx17__normal_iteratorIPKS0_S2_EE.isra.0, @function
_ZNSt6vectorI9SaveEntrySaIS0_EE5eraseEN9__gnu_cxx17__normal_iteratorIPKS0_S2_EE.isra.0:
.LFB14842:
	.cfi_startproc
	push	rbp	#
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	mov	rbp, rsi	# __position, __position
	push	rbx	#
	.cfi_def_cfa_offset 24
	.cfi_offset 3, -24
	mov	rbx, rdi	# this, this
	sub	rsp, 8	#,
	.cfi_def_cfa_offset 32
# /usr/include/c++/15.2.1/bits/stl_vector.h:1793:       { return _M_erase(begin() + (__position - cbegin())); }
	call	_ZNKSt6vectorI9SaveEntrySaIS0_EE6cbeginEv	#
# /usr/include/c++/15.2.1/bits/stl_vector.h:1793:       { return _M_erase(begin() + (__position - cbegin())); }
	mov	rdi, rbx	#, this
# /usr/include/c++/15.2.1/bits/stl_iterator.h:1340:     { return __lhs.base() - __rhs.base(); }
	sub	rbp, rax	# _4, D.189616
# /usr/include/c++/15.2.1/bits/stl_vector.h:1793:       { return _M_erase(begin() + (__position - cbegin())); }
	call	_ZNSt6vectorI9SaveEntrySaIS0_EE5beginEv	#
# /usr/include/c++/15.2.1/bits/stl_vector.h:1793:       { return _M_erase(begin() + (__position - cbegin())); }
	add	rsp, 8	#,
	.cfi_def_cfa_offset 24
# /usr/include/c++/15.2.1/bits/stl_vector.h:1793:       { return _M_erase(begin() + (__position - cbegin())); }
	mov	rdi, rbx	#, this
# /usr/include/c++/15.2.1/bits/stl_iterator.h:1148:       { return __normal_iterator(_M_current + __n); }
	lea	rsi, [rax+rbp]	# _7,
# /usr/include/c++/15.2.1/bits/stl_vector.h:1793:       { return _M_erase(begin() + (__position - cbegin())); }
	pop	rbx	#
	.cfi_def_cfa_offset 16
	pop	rbp	#
	.cfi_def_cfa_offset 8
# /usr/include/c++/15.2.1/bits/stl_vector.h:1793:       { return _M_erase(begin() + (__position - cbegin())); }
	jmp	_ZNSt6vectorI9SaveEntrySaIS0_EE8_M_eraseEN9__gnu_cxx17__normal_iteratorIPS0_S2_EE	#
	.cfi_endproc
.LFE14842:
	.size	_ZNSt6vectorI9SaveEntrySaIS0_EE5eraseEN9__gnu_cxx17__normal_iteratorIPKS0_S2_EE.isra.0, .-_ZNSt6vectorI9SaveEntrySaIS0_EE5eraseEN9__gnu_cxx17__normal_iteratorIPKS0_S2_EE.isra.0
	.section	.rodata.str1.8
	.align 8
.LC95:
	.base64	"W1NhdmVNYW5hZ2VyXSDQntGI0LjQsdC60LAg0YPQtNCw0LvQtdC90LjRjyAA"
	.section	.rodata.str1.1
.LC96:
	.string	": "
	.section	.text.unlikely
	.align 2
.LCOLDB97:
	.text
.LHOTB97:
	.align 2
	.p2align 4
	.globl	_ZN11SaveManager15deleteNamedSaveEi
	.type	_ZN11SaveManager15deleteNamedSaveEi, @function
_ZN11SaveManager15deleteNamedSaveEi:
.LFB13568:
	.cfi_startproc
	.cfi_personality 0x9b,DW.ref.__gxx_personality_v0
	.cfi_lsda 0x1b,.LLSDA13568
	push	r14	#
	.cfi_def_cfa_offset 16
	.cfi_offset 14, -16
	push	r12	#
	.cfi_def_cfa_offset 24
	.cfi_offset 12, -24
	push	rbp	#
	.cfi_def_cfa_offset 32
	.cfi_offset 6, -32
	push	rbx	#
	.cfi_def_cfa_offset 40
	.cfi_offset 3, -40
	movsxd	rbx, esi	#, entryIndex
	sub	rsp, 88	#,
	.cfi_def_cfa_offset 128
# save_manager.cpp:288: bool SaveManager::deleteNamedSave(int entryIndex) {
	mov	rax, QWORD PTR fs:40	# tmp124, MEM[(<address-space-1> long unsigned int *)40B]
	mov	QWORD PTR 72[rsp], rax	# D.189630, tmp124
	xor	eax, eax	# tmp124
# save_manager.cpp:289:     if (entryIndex < 0 || entryIndex >= (int)entries.size()) return false;
	test	ebx, ebx	# entryIndex
	js	.L407	#,
	mov	rbp, rdi	# this, this
	mov	rdi, QWORD PTR 8[rdi]	# _48, MEM[(struct SaveEntry * *)this_12(D) + 8B]
# save_manager.cpp:289:     if (entryIndex < 0 || entryIndex >= (int)entries.size()) return false;
	mov	rsi, QWORD PTR 16[rbp]	# MEM[(struct SaveEntry * *)this_12(D) + 16B], MEM[(struct SaveEntry * *)this_12(D) + 16B]
	call	_ZNKSt6vectorI9SaveEntrySaIS0_EE4sizeEv.isra.0	#
# save_manager.cpp:289:     if (entryIndex < 0 || entryIndex >= (int)entries.size()) return false;
	cmp	ebx, eax	# entryIndex,
# save_manager.cpp:289:     if (entryIndex < 0 || entryIndex >= (int)entries.size()) return false;
	mov	eax, 0	# <retval>,
# save_manager.cpp:289:     if (entryIndex < 0 || entryIndex >= (int)entries.size()) return false;
	jl	.L414	#,
.L401:
# save_manager.cpp:307: }
	mov	rdx, QWORD PTR 72[rsp]	# tmp163, D.189630
	sub	rdx, QWORD PTR fs:40	# tmp163, MEM[(<address-space-1> long unsigned int *)40B]
	jne	.L415	#,
	add	rsp, 88	#,
	.cfi_remember_state
	.cfi_def_cfa_offset 40
	pop	rbx	#
	.cfi_def_cfa_offset 32
	pop	rbp	#
	.cfi_def_cfa_offset 24
	pop	r12	#
	.cfi_def_cfa_offset 16
	pop	r14	#
	.cfi_def_cfa_offset 8
	ret	
	.p2align 4,,10
	.p2align 3
.L414:
	.cfi_restore_state
# save_manager.cpp:291:     const std::string& path = entries[entryIndex].filename;
	mov	rsi, rbx	#, _4
	call	_ZNSt6vectorI9SaveEntrySaIS0_EEixEm.isra.0	#
# save_manager.cpp:291:     const std::string& path = entries[entryIndex].filename;
	lea	r14, 40[rax]	# path,
# save_manager.cpp:294:     std::error_code ec;
	lea	rax, 16[rsp]	# tmp126,
	mov	rdi, rax	#, tmp126
	mov	QWORD PTR 8[rsp], rax	# %sfp, tmp126
	call	_ZNSt10error_codeC1Ev	#
# save_manager.cpp:295:     std::filesystem::remove(path, ec);
	mov	edx, 2	#,
	mov	rsi, r14	#, path
	lea	rdi, 32[rsp]	#,
.LEHB38:
	call	_ZNSt10filesystem7__cxx114pathC1INSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEEES1_EERKT_NS1_6formatE	#
# save_manager.cpp:295:     std::filesystem::remove(path, ec);
	mov	rsi, QWORD PTR 8[rsp]	#, %sfp
	lea	rdi, 32[rsp]	#,
	call	[QWORD PTR _ZNSt10filesystem6removeERKNS_7__cxx114pathERSt10error_code@GOTPCREL[rip]]	#
# save_manager.cpp:295:     std::filesystem::remove(path, ec);
	lea	rdi, 32[rsp]	#,
	call	_ZNSt10filesystem7__cxx114pathD1Ev	#
# save_manager.cpp:296:     if (ec) {
	mov	edi, DWORD PTR 16[rsp]	#, MEM[(int *)&ec]
	call	_ZNKSt10error_codecvbEv.isra.0	#
# save_manager.cpp:296:     if (ec) {
	test	al, al	# retval.98_20
	je	.L403	#,
# save_manager.cpp:297:         std::cerr << "[SaveManager] Ошибка удаления " << path << ": " << ec.message() << "\n";
	lea	rsi, .LC95[rip]	#,
	lea	rdi, _ZSt4cerr[rip]	#,
	call	[QWORD PTR _ZStlsISt11char_traitsIcEERSt13basic_ostreamIcT_ES5_PKc@GOTPCREL[rip]]	#
# save_manager.cpp:297:         std::cerr << "[SaveManager] Ошибка удаления " << path << ": " << ec.message() << "\n";
	mov	rsi, r14	#, path
	mov	rdi, rax	#, _22
	call	[QWORD PTR _ZStlsIcSt11char_traitsIcESaIcEERSt13basic_ostreamIT_T0_ES7_RKNSt7__cxx1112basic_stringIS4_S5_T1_EE@GOTPCREL[rip]]	#
# save_manager.cpp:297:         std::cerr << "[SaveManager] Ошибка удаления " << path << ": " << ec.message() << "\n";
	lea	rsi, .LC96[rip]	#,
	mov	rdi, rax	#, _24
	call	[QWORD PTR _ZStlsISt11char_traitsIcEERSt13basic_ostreamIcT_ES5_PKc@GOTPCREL[rip]]	#
# save_manager.cpp:297:         std::cerr << "[SaveManager] Ошибка удаления " << path << ": " << ec.message() << "\n";
	mov	esi, DWORD PTR 16[rsp]	#, MEM[(int *)&ec]
	mov	rdx, QWORD PTR 24[rsp]	#, MEM[(const struct error_category * *)&ec + 8B]
	lea	rdi, 32[rsp]	#,
# save_manager.cpp:297:         std::cerr << "[SaveManager] Ошибка удаления " << path << ": " << ec.message() << "\n";
	mov	r14, rax	# _26,
# save_manager.cpp:297:         std::cerr << "[SaveManager] Ошибка удаления " << path << ": " << ec.message() << "\n";
	call	_ZNKSt10error_code7messageB5cxx11Ev.isra.0	#
.LEHE38:
# save_manager.cpp:297:         std::cerr << "[SaveManager] Ошибка удаления " << path << ": " << ec.message() << "\n";
	lea	rsi, 32[rsp]	#,
	mov	rdi, r14	#, _26
.LEHB39:
	call	[QWORD PTR _ZStlsIcSt11char_traitsIcESaIcEERSt13basic_ostreamIT_T0_ES7_RKNSt7__cxx1112basic_stringIS4_S5_T1_EE@GOTPCREL[rip]]	#
# save_manager.cpp:297:         std::cerr << "[SaveManager] Ошибка удаления " << path << ": " << ec.message() << "\n";
	lea	rsi, .LC15[rip]	#,
	mov	rdi, rax	#, _29
	call	[QWORD PTR _ZStlsISt11char_traitsIcEERSt13basic_ostreamIcT_ES5_PKc@GOTPCREL[rip]]	#
.LEHE39:
# save_manager.cpp:297:         std::cerr << "[SaveManager] Ошибка удаления " << path << ": " << ec.message() << "\n";
	lea	rdi, 32[rsp]	#,
	call	[QWORD PTR _ZNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEED1Ev@GOTPCREL[rip]]	#
.L403:
# save_manager.cpp:302:     entries.erase(entries.begin() + entryIndex);
	lea	rdi, 8[rbp]	#,
	call	_ZNSt6vectorI9SaveEntrySaIS0_EE5beginEv	#
# /usr/include/c++/15.2.1/bits/stl_iterator.h:1148:       { return __normal_iterator(_M_current + __n); }
	lea	rdx, [rbx+rbx*8]	# _40,
# save_manager.cpp:302:     entries.erase(entries.begin() + entryIndex);
	lea	rdi, 8[rbp]	#,
# /usr/include/c++/15.2.1/bits/stl_iterator.h:1148:       { return __normal_iterator(_M_current + __n); }
	lea	rsi, [rax+rdx*8]	# _41,
# save_manager.cpp:302:     entries.erase(entries.begin() + entryIndex);
	call	_ZNSt6vectorI9SaveEntrySaIS0_EE5eraseEN9__gnu_cxx17__normal_iteratorIPKS0_S2_EE.isra.0	#
# save_manager.cpp:305:     saveIndex();
	mov	rdi, rbp	#, this
.LEHB40:
	call	_ZN11SaveManager9saveIndexEv	#
.LEHE40:
# save_manager.cpp:306:     return true;
	mov	eax, 1	# <retval>,
	jmp	.L401	#
	.p2align 4,,10
	.p2align 3
.L407:
# save_manager.cpp:289:     if (entryIndex < 0 || entryIndex >= (int)entries.size()) return false;
	xor	eax, eax	# <retval>
	jmp	.L401	#
.L415:
# save_manager.cpp:307: }
	call	[QWORD PTR __stack_chk_fail@GOTPCREL[rip]]	#
.L409:
# save_manager.cpp:297:         std::cerr << "[SaveManager] Ошибка удаления " << path << ": " << ec.message() << "\n";
	mov	rbx, rax	# tmp161,
	jmp	.L404	#
	.section	.gcc_except_table
.LLSDA13568:
	.byte	0xff
	.byte	0xff
	.byte	0x1
	.uleb128 .LLSDACSE13568-.LLSDACSB13568
.LLSDACSB13568:
	.uleb128 .LEHB38-.LFB13568
	.uleb128 .LEHE38-.LEHB38
	.uleb128 0
	.uleb128 0
	.uleb128 .LEHB39-.LFB13568
	.uleb128 .LEHE39-.LEHB39
	.uleb128 .L409-.LFB13568
	.uleb128 0
	.uleb128 .LEHB40-.LFB13568
	.uleb128 .LEHE40-.LEHB40
	.uleb128 0
	.uleb128 0
.LLSDACSE13568:
	.text
	.cfi_endproc
	.section	.text.unlikely
	.cfi_startproc
	.cfi_personality 0x9b,DW.ref.__gxx_personality_v0
	.cfi_lsda 0x1b,.LLSDAC13568
	.type	_ZN11SaveManager15deleteNamedSaveEi.cold, @function
_ZN11SaveManager15deleteNamedSaveEi.cold:
.LFSB13568:
.L404:
	.cfi_def_cfa_offset 128
	.cfi_offset 3, -40
	.cfi_offset 6, -32
	.cfi_offset 12, -24
	.cfi_offset 14, -16
	lea	rdi, 32[rsp]	#,
	call	[QWORD PTR _ZNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEED1Ev@GOTPCREL[rip]]	#
	mov	rax, QWORD PTR 72[rsp]	# tmp162, D.189630
	sub	rax, QWORD PTR fs:40	# tmp162, MEM[(<address-space-1> long unsigned int *)40B]
	jne	.L416	#,
	mov	rdi, rbx	#, tmp161
.LEHB41:
	call	[QWORD PTR _Unwind_Resume@GOTPCREL[rip]]	#
.LEHE41:
.L416:
	call	[QWORD PTR __stack_chk_fail@GOTPCREL[rip]]	#
	.cfi_endproc
.LFE13568:
	.section	.gcc_except_table
.LLSDAC13568:
	.byte	0xff
	.byte	0xff
	.byte	0x1
	.uleb128 .LLSDACSEC13568-.LLSDACSBC13568
.LLSDACSBC13568:
	.uleb128 .LEHB41-.LCOLDB97
	.uleb128 .LEHE41-.LEHB41
	.uleb128 0
	.uleb128 0
.LLSDACSEC13568:
	.section	.text.unlikely
	.text
	.size	_ZN11SaveManager15deleteNamedSaveEi, .-_ZN11SaveManager15deleteNamedSaveEi
	.section	.text.unlikely
	.size	_ZN11SaveManager15deleteNamedSaveEi.cold, .-_ZN11SaveManager15deleteNamedSaveEi.cold
.LCOLDE97:
	.text
.LHOTE97:
	.section	.text._ZN9SaveEntryC2EOS_,"axG",@progbits,_ZN9SaveEntryC5EOS_,comdat
	.align 2
	.p2align 4
	.weak	_ZN9SaveEntryC2EOS_
	.type	_ZN9SaveEntryC2EOS_, @function
_ZN9SaveEntryC2EOS_:
.LFB14804:
	.cfi_startproc
	push	rbp	#
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	mov	rbp, rsi	# D.177168, D.177168
	lea	rsi, 8[rsi]	# _3,
	push	rbx	#
	.cfi_def_cfa_offset 24
	.cfi_offset 3, -24
	mov	rbx, rdi	# this, this
	lea	rdi, 8[rdi]	# _2,
	sub	rsp, 8	#,
	.cfi_def_cfa_offset 32
# save_manager.h:77: struct SaveEntry {
	mov	eax, DWORD PTR -8[rsi]	# *_11(D).number, *_11(D).number
	mov	DWORD PTR -8[rdi], eax	# *this_9(D).number, *_11(D).number
	call	[QWORD PTR _ZNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEEC1EOS4_@GOTPCREL[rip]]	#
	add	rsp, 8	#,
	.cfi_def_cfa_offset 24
# save_manager.h:77: struct SaveEntry {
	lea	rsi, 40[rbp]	# _5,
	lea	rdi, 40[rbx]	# _4,
# save_manager.h:77: struct SaveEntry {
	pop	rbx	#
	.cfi_def_cfa_offset 16
	pop	rbp	#
	.cfi_def_cfa_offset 8
# save_manager.h:77: struct SaveEntry {
	jmp	[QWORD PTR _ZNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEEC1EOS4_@GOTPCREL[rip]]	#
	.cfi_endproc
.LFE14804:
	.size	_ZN9SaveEntryC2EOS_, .-_ZN9SaveEntryC2EOS_
	.weak	_ZN9SaveEntryC1EOS_
	.set	_ZN9SaveEntryC1EOS_,_ZN9SaveEntryC2EOS_
	.section	.text._ZSt19__relocate_object_aI9SaveEntryS0_SaIS0_EEvPT_PT0_RT1_.isra.0,"axG",@progbits,_ZNSt6vectorI9SaveEntrySaIS0_EE17_M_realloc_appendIJRKS0_EEEvDpOT_,comdat
	.p2align 4
	.type	_ZSt19__relocate_object_aI9SaveEntryS0_SaIS0_EEvPT_PT0_RT1_.isra.0, @function
_ZSt19__relocate_object_aI9SaveEntryS0_SaIS0_EEvPT_PT0_RT1_.isra.0:
.LFB14843:
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
	call	_ZN9SaveEntryC1EOS_	#
# /usr/include/c++/15.2.1/bits/new_allocator.h:198: 	{ __p->~_Up(); }
	mov	rdi, rbx	#, __orig
# /usr/include/c++/15.2.1/bits/stl_uninitialized.h:1290:     }
	pop	rbx	#
	.cfi_def_cfa_offset 8
# /usr/include/c++/15.2.1/bits/new_allocator.h:198: 	{ __p->~_Up(); }
	jmp	_ZN9SaveEntryD1Ev	#
	.cfi_endproc
.LFE14843:
	.size	_ZSt19__relocate_object_aI9SaveEntryS0_SaIS0_EEvPT_PT0_RT1_.isra.0, .-_ZSt19__relocate_object_aI9SaveEntryS0_SaIS0_EEvPT_PT0_RT1_.isra.0
	.section	.text._ZSt14__relocate_a_1IP9SaveEntryS1_SaIS0_EET0_T_S4_S3_RT1_.isra.0,"axG",@progbits,_ZNSt6vectorI9SaveEntrySaIS0_EE17_M_realloc_appendIJRKS0_EEEvDpOT_,comdat
	.p2align 4
	.type	_ZSt14__relocate_a_1IP9SaveEntryS1_SaIS0_EET0_T_S4_S3_RT1_.isra.0, @function
_ZSt14__relocate_a_1IP9SaveEntryS1_SaIS0_EET0_T_S4_S3_RT1_.isra.0:
.LFB14844:
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
	je	.L422	#,
	mov	rbx, rdi	# __first, __first
	mov	r12, rsi	# __last, __last
	.p2align 4
	.p2align 3
.L423:
# /usr/include/c++/15.2.1/bits/stl_uninitialized.h:1317: 	std::__relocate_object_a(std::__addressof(*__cur),
	mov	rsi, rbx	#, __first
	mov	rdi, rbp	#, __result
# /usr/include/c++/15.2.1/bits/stl_uninitialized.h:1316:       for (; __first != __last; ++__first, (void)++__cur)
	add	rbx, 72	# __first,
# /usr/include/c++/15.2.1/bits/stl_uninitialized.h:1316:       for (; __first != __last; ++__first, (void)++__cur)
	add	rbp, 72	# __result,
# /usr/include/c++/15.2.1/bits/stl_uninitialized.h:1317: 	std::__relocate_object_a(std::__addressof(*__cur),
	call	_ZSt19__relocate_object_aI9SaveEntryS0_SaIS0_EEvPT_PT0_RT1_.isra.0	#
# /usr/include/c++/15.2.1/bits/stl_uninitialized.h:1316:       for (; __first != __last; ++__first, (void)++__cur)
	cmp	rbx, r12	# __first, __last
	jne	.L423	#,
.L422:
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
.LFE14844:
	.size	_ZSt14__relocate_a_1IP9SaveEntryS1_SaIS0_EET0_T_S4_S3_RT1_.isra.0, .-_ZSt14__relocate_a_1IP9SaveEntryS1_SaIS0_EET0_T_S4_S3_RT1_.isra.0
	.section	.text._ZSt12__relocate_aIP9SaveEntryS1_SaIS0_EET0_T_S4_S3_RT1_.isra.0,"axG",@progbits,_ZNSt6vectorI9SaveEntrySaIS0_EE17_M_realloc_appendIJRKS0_EEEvDpOT_,comdat
	.p2align 4
	.type	_ZSt12__relocate_aIP9SaveEntryS1_SaIS0_EET0_T_S4_S3_RT1_.isra.0, @function
_ZSt12__relocate_aIP9SaveEntryS1_SaIS0_EET0_T_S4_S3_RT1_.isra.0:
.LFB14845:
	.cfi_startproc
# /usr/include/c++/15.2.1/bits/stl_uninitialized.h:1359:       return std::__relocate_a_1(std::__niter_base(__first),
	jmp	_ZSt14__relocate_a_1IP9SaveEntryS1_SaIS0_EET0_T_S4_S3_RT1_.isra.0	#
	.cfi_endproc
.LFE14845:
	.size	_ZSt12__relocate_aIP9SaveEntryS1_SaIS0_EET0_T_S4_S3_RT1_.isra.0, .-_ZSt12__relocate_aIP9SaveEntryS1_SaIS0_EET0_T_S4_S3_RT1_.isra.0
	.section	.text._ZNSt6vectorI9SaveEntrySaIS0_EE11_S_relocateEPS0_S3_S3_RS1_.isra.0,"axG",@progbits,_ZNSt6vectorI9SaveEntrySaIS0_EE17_M_realloc_appendIJRKS0_EEEvDpOT_,comdat
	.p2align 4
	.type	_ZNSt6vectorI9SaveEntrySaIS0_EE11_S_relocateEPS0_S3_S3_RS1_.isra.0, @function
_ZNSt6vectorI9SaveEntrySaIS0_EE11_S_relocateEPS0_S3_S3_RS1_.isra.0:
.LFB14846:
	.cfi_startproc
# /usr/include/c++/15.2.1/bits/stl_vector.h:539: 	return std::__relocate_a(__first, __last, __result, __alloc);
	jmp	_ZSt12__relocate_aIP9SaveEntryS1_SaIS0_EET0_T_S4_S3_RT1_.isra.0	#
	.cfi_endproc
.LFE14846:
	.size	_ZNSt6vectorI9SaveEntrySaIS0_EE11_S_relocateEPS0_S3_S3_RS1_.isra.0, .-_ZNSt6vectorI9SaveEntrySaIS0_EE11_S_relocateEPS0_S3_S3_RS1_.isra.0
	.section	.rodata._ZNSt6vectorI9SaveEntrySaIS0_EE17_M_realloc_appendIJRKS0_EEEvDpOT_.str1.1,"aMS",@progbits,1
.LC98:
	.string	"vector::_M_realloc_append"
	.section	.text._ZNSt6vectorI9SaveEntrySaIS0_EE17_M_realloc_appendIJRKS0_EEEvDpOT_,"axG",@progbits,_ZNSt6vectorI9SaveEntrySaIS0_EE17_M_realloc_appendIJRKS0_EEEvDpOT_,comdat
	.align 2
	.p2align 4
	.weak	_ZNSt6vectorI9SaveEntrySaIS0_EE17_M_realloc_appendIJRKS0_EEEvDpOT_
	.type	_ZNSt6vectorI9SaveEntrySaIS0_EE17_M_realloc_appendIJRKS0_EEEvDpOT_, @function
_ZNSt6vectorI9SaveEntrySaIS0_EE17_M_realloc_appendIJRKS0_EEEvDpOT_:
.LFB14414:
	.cfi_startproc
	.cfi_personality 0x9b,DW.ref.__gxx_personality_v0
	.cfi_lsda 0x1b,.LLSDA14414
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
	sub	rsp, 56	#,
	.cfi_def_cfa_offset 112
# /usr/include/c++/15.2.1/bits/vector.tcc:557:       vector<_Tp, _Alloc>::
	mov	QWORD PTR 8[rsp], rsi	# %sfp, __args#0
# /usr/include/c++/15.2.1/bits/vector.tcc:566:       const size_type __len = _M_check_len(1u, "vector::_M_realloc_append");
	mov	esi, 1	#,
	mov	rdx, QWORD PTR fs:40	#, MEM[(<address-space-1> long unsigned int *)40B]
	mov	QWORD PTR 40[rsp], rdx	# D.189696,
	lea	rdx, .LC98[rip]	#,
.LEHB42:
	call	_ZNKSt6vectorI9SaveEntrySaIS0_EE12_M_check_lenEmPKc	#
# /usr/include/c++/15.2.1/bits/vector.tcc:571:       const size_type __elems = end() - begin();
	mov	rdi, rbx	#, this
# /usr/include/c++/15.2.1/bits/vector.tcc:569:       pointer __old_start = this->_M_impl._M_start;
	mov	r14, QWORD PTR [rbx]	# __old_start, this_12(D)->D.154016._M_impl.D.153351._M_start
# /usr/include/c++/15.2.1/bits/vector.tcc:566:       const size_type __len = _M_check_len(1u, "vector::_M_realloc_append");
	mov	r13, rax	# _14,
# /usr/include/c++/15.2.1/bits/vector.tcc:570:       pointer __old_finish = this->_M_impl._M_finish;
	mov	rax, QWORD PTR 8[rbx]	# __old_finish, this_12(D)->D.154016._M_impl.D.153351._M_finish
	mov	QWORD PTR [rsp], rax	# %sfp, __old_finish
# /usr/include/c++/15.2.1/bits/vector.tcc:571:       const size_type __elems = end() - begin();
	call	_ZNSt6vectorI9SaveEntrySaIS0_EE5beginEv	#
# /usr/include/c++/15.2.1/bits/vector.tcc:571:       const size_type __elems = end() - begin();
	mov	rdi, rbx	#, this
# /usr/include/c++/15.2.1/bits/vector.tcc:571:       const size_type __elems = end() - begin();
	mov	rbp, rax	# D.183673,
# /usr/include/c++/15.2.1/bits/vector.tcc:571:       const size_type __elems = end() - begin();
	call	_ZNSt6vectorI9SaveEntrySaIS0_EE3endEv	#
# /usr/include/c++/15.2.1/bits/vector.tcc:572:       pointer __new_start(this->_M_allocate(__len));
	mov	rdi, r13	#, _14
# /usr/include/c++/15.2.1/bits/stl_iterator.h:1340:     { return __lhs.base() - __rhs.base(); }
	sub	rax, rbp	# D.183672, D.183673
	mov	r12, rax	# _19, D.183672
# /usr/include/c++/15.2.1/bits/vector.tcc:572:       pointer __new_start(this->_M_allocate(__len));
	call	_ZNSt12_Vector_baseI9SaveEntrySaIS0_EE11_M_allocateEm.isra.0	#
.LEHE42:
# /usr/include/c++/15.2.1/bits/vector.tcc:576: 	_Guard_alloc __guard(__new_start, __len, *this);
	lea	rdi, 16[rsp]	#,
	mov	rcx, rbx	#, this
	mov	rdx, r13	#, _14
# /usr/include/c++/15.2.1/bits/vector.tcc:572:       pointer __new_start(this->_M_allocate(__len));
	mov	rbp, rax	# _23,
# /usr/include/c++/15.2.1/bits/vector.tcc:576: 	_Guard_alloc __guard(__new_start, __len, *this);
	mov	rsi, rax	#, _23
	call	_ZNSt6vectorI9SaveEntrySaIS0_EE12_Guard_allocC1EPS0_mRSt12_Vector_baseIS0_S1_E	#
# /usr/include/c++/15.2.1/bits/vector.tcc:586: 	_Alloc_traits::construct(this->_M_impl,
	lea	rdi, 0[rbp+r12]	# _3,
# /usr/include/c++/15.2.1/bits/new_allocator.h:191: 	{ ::new((void *)__p) _Up(std::forward<_Args>(__args)...); }
	call	_ZnwmPv.isra.0	#
# /usr/include/c++/15.2.1/bits/new_allocator.h:191: 	{ ::new((void *)__p) _Up(std::forward<_Args>(__args)...); }
	mov	rsi, QWORD PTR 8[rsp]	#, %sfp
	mov	rdi, rax	#, _28
.LEHB43:
	call	_ZN9SaveEntryC1ERKS_	#
.LEHE43:
# /usr/include/c++/15.2.1/bits/vector.tcc:599: 	    __new_finish = _S_relocate(__old_start, __old_finish,
	mov	rsi, QWORD PTR [rsp]	#, %sfp
	mov	rdx, rbp	#, _23
	mov	rdi, r14	#, __old_start
	call	_ZNSt6vectorI9SaveEntrySaIS0_EE11_S_relocateEPS0_S3_S3_RS1_.isra.0	#
# /usr/include/c++/15.2.1/bits/vector.tcc:640:       }
	lea	rdi, 16[rsp]	#,
# /usr/include/c++/15.2.1/bits/vector.tcc:638: 	__guard._M_storage = __old_start;
	mov	QWORD PTR 16[rsp], r14	# __guard._M_storage, __old_start
# /usr/include/c++/15.2.1/bits/vector.tcc:639: 	__guard._M_len = this->_M_impl._M_end_of_storage - __old_start;
	movabs	rdx, -8198552921648689607	# tmp132,
# /usr/include/c++/15.2.1/bits/vector.tcc:599: 	    __new_finish = _S_relocate(__old_start, __old_finish,
	mov	r12, rax	# __new_finish,
# /usr/include/c++/15.2.1/bits/vector.tcc:639: 	__guard._M_len = this->_M_impl._M_end_of_storage - __old_start;
	mov	rax, QWORD PTR 16[rbx]	# _6, this_12(D)->D.154016._M_impl.D.153351._M_end_of_storage
# /usr/include/c++/15.2.1/bits/vector.tcc:601: 	    ++__new_finish;
	add	r12, 72	# tmp134,
# /usr/include/c++/15.2.1/bits/vector.tcc:639: 	__guard._M_len = this->_M_impl._M_end_of_storage - __old_start;
	sub	rax, r14	# _6, __old_start
	sar	rax, 3	# tmp130,
	imul	rax, rdx	# _7, tmp132
# /usr/include/c++/15.2.1/bits/vector.tcc:639: 	__guard._M_len = this->_M_impl._M_end_of_storage - __old_start;
	mov	QWORD PTR 24[rsp], rax	# __guard._M_len, _7
# /usr/include/c++/15.2.1/bits/vector.tcc:640:       }
	call	_ZNSt6vectorI9SaveEntrySaIS0_EE12_Guard_allocD1Ev	#
# /usr/include/c++/15.2.1/bits/vector.tcc:646:       this->_M_impl._M_end_of_storage = __new_start + __len;
	lea	rax, 0[r13+r13*8]	# _9,
# /usr/include/c++/15.2.1/bits/vector.tcc:644:       this->_M_impl._M_start = __new_start;
	mov	QWORD PTR [rbx], rbp	# this_12(D)->D.154016._M_impl.D.153351._M_start, _23
# /usr/include/c++/15.2.1/bits/vector.tcc:646:       this->_M_impl._M_end_of_storage = __new_start + __len;
	lea	rax, 0[rbp+rax*8]	# tmp139,
# /usr/include/c++/15.2.1/bits/vector.tcc:601: 	    ++__new_finish;
	mov	QWORD PTR 8[rbx], r12	# this_12(D)->D.154016._M_impl.D.153351._M_finish, tmp134
# /usr/include/c++/15.2.1/bits/vector.tcc:646:       this->_M_impl._M_end_of_storage = __new_start + __len;
	mov	QWORD PTR 16[rbx], rax	# this_12(D)->D.154016._M_impl.D.153351._M_end_of_storage, tmp139
# /usr/include/c++/15.2.1/bits/vector.tcc:647:     }
	mov	rax, QWORD PTR 40[rsp]	# tmp154, D.189696
	sub	rax, QWORD PTR fs:40	# tmp154, MEM[(<address-space-1> long unsigned int *)40B]
	jne	.L433	#,
	add	rsp, 56	#,
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
.L429:
	.cfi_restore_state
# /usr/include/c++/15.2.1/bits/vector.tcc:640:       }
	lea	rdi, 16[rsp]	#,
	call	_ZNSt6vectorI9SaveEntrySaIS0_EE12_Guard_allocD1Ev	#
	mov	rax, QWORD PTR 40[rsp]	# tmp155, D.189696
	sub	rax, QWORD PTR fs:40	# tmp155, MEM[(<address-space-1> long unsigned int *)40B]
	je	.L430	#,
.L433:
# /usr/include/c++/15.2.1/bits/vector.tcc:647:     }
	call	[QWORD PTR __stack_chk_fail@GOTPCREL[rip]]	#
.L432:
# /usr/include/c++/15.2.1/bits/vector.tcc:640:       }
	mov	rbx, rax	# tmp153,
	jmp	.L429	#
.L430:
	mov	rdi, rbx	#, tmp153
.LEHB44:
	call	[QWORD PTR _Unwind_Resume@GOTPCREL[rip]]	#
.LEHE44:
	.cfi_endproc
.LFE14414:
	.section	.gcc_except_table
.LLSDA14414:
	.byte	0xff
	.byte	0xff
	.byte	0x1
	.uleb128 .LLSDACSE14414-.LLSDACSB14414
.LLSDACSB14414:
	.uleb128 .LEHB42-.LFB14414
	.uleb128 .LEHE42-.LEHB42
	.uleb128 0
	.uleb128 0
	.uleb128 .LEHB43-.LFB14414
	.uleb128 .LEHE43-.LEHB43
	.uleb128 .L432-.LFB14414
	.uleb128 0
	.uleb128 .LEHB44-.LFB14414
	.uleb128 .LEHE44-.LEHB44
	.uleb128 0
	.uleb128 0
.LLSDACSE14414:
	.section	.text._ZNSt6vectorI9SaveEntrySaIS0_EE17_M_realloc_appendIJRKS0_EEEvDpOT_,"axG",@progbits,_ZNSt6vectorI9SaveEntrySaIS0_EE17_M_realloc_appendIJRKS0_EEEvDpOT_,comdat
	.size	_ZNSt6vectorI9SaveEntrySaIS0_EE17_M_realloc_appendIJRKS0_EEEvDpOT_, .-_ZNSt6vectorI9SaveEntrySaIS0_EE17_M_realloc_appendIJRKS0_EEEvDpOT_
	.section	.text._ZNSt6vectorI9SaveEntrySaIS0_EE9push_backERKS0_,"axG",@progbits,_ZNSt6vectorI9SaveEntrySaIS0_EE9push_backERKS0_,comdat
	.align 2
	.p2align 4
	.weak	_ZNSt6vectorI9SaveEntrySaIS0_EE9push_backERKS0_
	.type	_ZNSt6vectorI9SaveEntrySaIS0_EE9push_backERKS0_, @function
_ZNSt6vectorI9SaveEntrySaIS0_EE9push_backERKS0_:
.LFB14076:
	.cfi_startproc
# /usr/include/c++/15.2.1/bits/stl_vector.h:1418: 	if (this->_M_impl._M_finish != this->_M_impl._M_end_of_storage)
	mov	rax, QWORD PTR 8[rdi]	# _1, this_7(D)->D.154016._M_impl.D.153351._M_finish
# /usr/include/c++/15.2.1/bits/stl_vector.h:1418: 	if (this->_M_impl._M_finish != this->_M_impl._M_end_of_storage)
	cmp	rax, QWORD PTR 16[rdi]	# _1, this_7(D)->D.154016._M_impl.D.153351._M_end_of_storage
	je	.L436	#,
# /usr/include/c++/15.2.1/bits/stl_vector.h:1416:       push_back(const value_type& __x)
	push	rbx	#
	.cfi_def_cfa_offset 16
	.cfi_offset 3, -16
	mov	rbx, rdi	# this, this
# /usr/include/c++/15.2.1/bits/new_allocator.h:191: 	{ ::new((void *)__p) _Up(std::forward<_Args>(__args)...); }
	mov	rdi, rax	#, _1
	call	_ZnwmPv.isra.0	#
# /usr/include/c++/15.2.1/bits/new_allocator.h:191: 	{ ::new((void *)__p) _Up(std::forward<_Args>(__args)...); }
	mov	rdi, rax	#, _11
	call	_ZN9SaveEntryC1ERKS_	#
# /usr/include/c++/15.2.1/bits/stl_vector.h:1423: 	    ++this->_M_impl._M_finish;
	add	QWORD PTR 8[rbx], 72	# this_7(D)->D.154016._M_impl.D.153351._M_finish,
# /usr/include/c++/15.2.1/bits/stl_vector.h:1428:       }
	pop	rbx	#
	.cfi_def_cfa_offset 8
	ret	
	.p2align 4,,10
	.p2align 3
.L436:
	.cfi_restore 3
# /usr/include/c++/15.2.1/bits/stl_vector.h:1427: 	  _M_realloc_append(__x);
	jmp	_ZNSt6vectorI9SaveEntrySaIS0_EE17_M_realloc_appendIJRKS0_EEEvDpOT_	#
	.cfi_endproc
.LFE14076:
	.size	_ZNSt6vectorI9SaveEntrySaIS0_EE9push_backERKS0_, .-_ZNSt6vectorI9SaveEntrySaIS0_EE9push_backERKS0_
	.section	.rodata.str1.8
	.align 8
.LC99:
	.base64	"W1NhdmVNYW5hZ2VyXSDQlNC+0YHRgtC40LPQvdGD0YIg0LvQuNC80LjRgiDRgdC+0YXRgNCw0L3QtdC90LjQuSAoMTIpCgA="
	.align 8
.LC100:
	.base64	"W1NhdmVNYW5hZ2VyXSBhdXRvc2F2ZSDQvdC1INC90LDQudC00LXQvSwg0YHQvtGF0YDQsNC90Y/QtdC8INC/0YPRgdGC0L7QtSDRgdC+0YHRgtC+0Y/QvdC40LUKAA=="
	.section	.text.unlikely
	.align 2
.LCOLDB101:
	.text
.LHOTB101:
	.align 2
	.p2align 4
	.globl	_ZN11SaveManager15createNamedSaveERKNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEEE
	.type	_ZN11SaveManager15createNamedSaveERKNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEEE, @function
_ZN11SaveManager15createNamedSaveERKNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEEE:
.LFB13559:
	.cfi_startproc
	.cfi_personality 0x9b,DW.ref.__gxx_personality_v0
	.cfi_lsda 0x1b,.LLSDA13559
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
	sub	rsp, 264	#,
	.cfi_def_cfa_offset 320
# save_manager.cpp:214: int SaveManager::createNamedSave(const std::string& name) {
	mov	r12, QWORD PTR fs:40	# name, MEM[(<address-space-1> long unsigned int *)40B]
	mov	QWORD PTR 248[rsp], r12	# D.189722, name
	mov	r12, rsi	# name, name
# save_manager.cpp:216:     if ((int)entries.size() >= 12) {
	mov	rsi, QWORD PTR 16[rdi]	# MEM[(struct SaveEntry * *)this_17(D) + 16B], MEM[(struct SaveEntry * *)this_17(D) + 16B]
	mov	rdi, QWORD PTR 8[rdi]	# MEM[(struct SaveEntry * *)this_17(D) + 8B], MEM[(struct SaveEntry * *)this_17(D) + 8B]
	call	_ZNKSt6vectorI9SaveEntrySaIS0_EE4sizeEv.isra.0	#
# save_manager.cpp:216:     if ((int)entries.size() >= 12) {
	cmp	eax, 11	# _2,
	jg	.L454	#,
# save_manager.cpp:222:     GameSaveState state;
	pxor	xmm0, xmm0	# tmp130
# save_manager.cpp:216:     if ((int)entries.size() >= 12) {
	lea	rax, 8[rbx]	# _1,
# save_manager.cpp:223:     if (!readSaveFile(AUTOSAVE_FILE, state)) {
	lea	rbp, 64[rsp]	# tmp168,
# save_manager.cpp:222:     GameSaveState state;
	mov	QWORD PTR 144[rsp], 0	# MEM <vector(2) float> [(float *)&state],
	movups	XMMWORD PTR 184[rsp], xmm0	# MEM <vector(4) int> [(int *)&state + 40B], tmp130
# save_manager.cpp:223:     if (!readSaveFile(AUTOSAVE_FILE, state)) {
	lea	rdx, 31[rsp]	# tmp134,
	mov	rdi, rbp	#, tmp168
# save_manager.cpp:222:     GameSaveState state;
	movdqa	xmm0, XMMWORD PTR .LC75[rip]	# tmp131,
# save_manager.cpp:216:     if ((int)entries.size() >= 12) {
	mov	QWORD PTR 8[rsp], rax	# %sfp, _1
# save_manager.cpp:222:     GameSaveState state;
	mov	rax, QWORD PTR .LC77[rip]	# tmp133,
# save_manager.cpp:223:     if (!readSaveFile(AUTOSAVE_FILE, state)) {
	lea	rsi, .LC13[rip]	#,
# save_manager.cpp:222:     GameSaveState state;
	movups	XMMWORD PTR 200[rsp], xmm0	# MEM <vector(4) int> [(int *)&state + 56B], tmp131
	movdqa	xmm0, XMMWORD PTR .LC76[rip]	# tmp132,
	mov	BYTE PTR 152[rsp], 1	# state.player.facingRight,
	mov	QWORD PTR 156[rsp], 0	# MEM <vector(2) float> [(float *)&state + 12B],
	mov	DWORD PTR 164[rsp], 0x00000000	# state.boss.y,
	mov	BYTE PTR 168[rsp], 1	# state.boss.facingRight,
	mov	DWORD PTR 172[rsp], 0x00000000	# state.boss.hp,
	mov	QWORD PTR 176[rsp], 0	# MEM <unsigned long> [(void *)&state + 32B],
	mov	QWORD PTR 232[rsp], rax	# MEM <vector(2) int> [(int *)&state + 88B], tmp133
	mov	DWORD PTR 240[rsp], 2	# state.difficulty,
	movups	XMMWORD PTR 216[rsp], xmm0	# MEM <vector(4) int> [(int *)&state + 72B], tmp132
.LEHB45:
# save_manager.cpp:223:     if (!readSaveFile(AUTOSAVE_FILE, state)) {
	call	_ZNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEEC1IS3_EEPKcRKS3_	#
.LEHE45:
# save_manager.cpp:223:     if (!readSaveFile(AUTOSAVE_FILE, state)) {
	lea	rdx, 144[rsp]	#,
	mov	rsi, rbp	#, tmp168
	mov	rdi, rbx	#, this
.LEHB46:
	call	_ZN11SaveManager12readSaveFileERKNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEEER13GameSaveState	#
.LEHE46:
	mov	r14d, eax	# _46,
# save_manager.cpp:223:     if (!readSaveFile(AUTOSAVE_FILE, state)) {
	mov	rdi, rbp	#, tmp168
	call	[QWORD PTR _ZNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEED1Ev@GOTPCREL[rip]]	#
# save_manager.cpp:223:     if (!readSaveFile(AUTOSAVE_FILE, state)) {
	test	r14b, r14b	# _46
	je	.L455	#,
.L445:
# save_manager.cpp:229:     fillControlsFromConfig(state);
	lea	rdi, 144[rsp]	#,
.LEHB47:
	call	_ZN11SaveManager22fillControlsFromConfigER13GameSaveState	#
.LEHE47:
# save_manager.cpp:233:         state.bestStars[i] = Config::getLevelStars(i);
	xor	edi, edi	#
	call	_ZN6Config13getLevelStarsEi	#
	mov	edi, 1	#,
# save_manager.cpp:233:         state.bestStars[i] = Config::getLevelStars(i);
	mov	DWORD PTR 192[rsp], eax	# state.bestStars[0], _85
# save_manager.cpp:233:         state.bestStars[i] = Config::getLevelStars(i);
	call	_ZN6Config13getLevelStarsEi	#
	mov	edi, 2	#,
# save_manager.cpp:233:         state.bestStars[i] = Config::getLevelStars(i);
	mov	DWORD PTR 196[rsp], eax	# state.bestStars[1], _92
# save_manager.cpp:233:         state.bestStars[i] = Config::getLevelStars(i);
	call	_ZN6Config13getLevelStarsEi	#
# save_manager.cpp:233:         state.bestStars[i] = Config::getLevelStars(i);
	mov	DWORD PTR 200[rsp], eax	# state.bestStars[2], _4
# save_manager.cpp:234:     state.difficulty = Config::getCurrentDifficulty();
	call	_ZN6Config20getCurrentDifficultyEv	#
# save_manager.cpp:237:     SaveEntry entry;
	mov	rdi, rbp	#, tmp168
# save_manager.cpp:234:     state.difficulty = Config::getCurrentDifficulty();
	mov	DWORD PTR 240[rsp], eax	# state.difficulty, _5
# save_manager.cpp:237:     SaveEntry entry;
	call	_ZN9SaveEntryC1Ev	#
# save_manager.cpp:238:     entry.number   = nextSaveNumber++;
	mov	eax, DWORD PTR 32[rbx]	# _6, this_17(D)->nextSaveNumber
# save_manager.cpp:239:     entry.name     = name;
	lea	rdi, 72[rsp]	# tmp146,
	mov	rsi, r12	#, name
# save_manager.cpp:238:     entry.number   = nextSaveNumber++;
	lea	edx, 1[rax]	# tmp144,
# save_manager.cpp:238:     entry.number   = nextSaveNumber++;
	mov	DWORD PTR 64[rsp], eax	# MEM[(struct SaveEntry *)_27].number, _6
# save_manager.cpp:238:     entry.number   = nextSaveNumber++;
	mov	DWORD PTR 32[rbx], edx	# this_17(D)->nextSaveNumber, tmp144
.LEHB48:
# save_manager.cpp:239:     entry.name     = name;
	call	[QWORD PTR _ZNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEEaSERKS4_@GOTPCREL[rip]]	#
# save_manager.cpp:240:     entry.filename = makeFilename(entry.number, name);
	mov	edx, DWORD PTR 64[rsp]	#, MEM[(struct SaveEntry *)_27].number
	mov	rcx, r12	#, name
	mov	rsi, rbx	#, this
	lea	rdi, 32[rsp]	#,
	call	_ZNK11SaveManager12makeFilenameEiRKNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEEE	#
# save_manager.cpp:240:     entry.filename = makeFilename(entry.number, name);
	lea	rsi, 32[rsp]	#,
	lea	rdi, 104[rsp]	#,
	call	[QWORD PTR _ZNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEEaSEOS4_@GOTPCREL[rip]]	#
# save_manager.cpp:240:     entry.filename = makeFilename(entry.number, name);
	lea	rdi, 32[rsp]	#,
	call	[QWORD PTR _ZNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEED1Ev@GOTPCREL[rip]]	#
# save_manager.cpp:241:     entries.push_back(entry);
	mov	rdi, QWORD PTR 8[rsp]	#, %sfp
	mov	rsi, rbp	#, tmp168
	call	_ZNSt6vectorI9SaveEntrySaIS0_EE9push_backERKS0_	#
# save_manager.cpp:244:     writeSaveFile(entry.filename, state, name);
	mov	rcx, r12	#, name
	lea	rdx, 144[rsp]	#,
	lea	rsi, 104[rsp]	#,
	mov	rdi, rbx	#, this
	call	_ZN11SaveManager13writeSaveFileERKNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEEERK13GameSaveStateS7_	#
# save_manager.cpp:247:     saveIndex();
	mov	rdi, rbx	#, this
	call	_ZN11SaveManager9saveIndexEv	#
.LEHE48:
# save_manager.cpp:249:     return (int)entries.size() - 1;
	mov	rdi, QWORD PTR 8[rbx]	# MEM[(struct SaveEntry * *)this_17(D) + 8B], MEM[(struct SaveEntry * *)this_17(D) + 8B]
	mov	rsi, QWORD PTR 16[rbx]	# MEM[(struct SaveEntry * *)this_17(D) + 16B], MEM[(struct SaveEntry * *)this_17(D) + 16B]
	call	_ZNKSt6vectorI9SaveEntrySaIS0_EE4sizeEv.isra.0	#
# save_manager.cpp:250: }
	mov	rdi, rbp	#, tmp168
# save_manager.cpp:249:     return (int)entries.size() - 1;
	lea	ebx, -1[rax]	# <retval>,
# save_manager.cpp:250: }
	call	_ZN9SaveEntryD1Ev	#
.L442:
	mov	rax, QWORD PTR 248[rsp]	# tmp185, D.189722
	sub	rax, QWORD PTR fs:40	# tmp185, MEM[(<address-space-1> long unsigned int *)40B]
	jne	.L456	#,
	add	rsp, 264	#,
	.cfi_remember_state
	.cfi_def_cfa_offset 56
	mov	eax, ebx	#, <retval>
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
.L455:
	.cfi_restore_state
# save_manager.cpp:225:         std::cerr << "[SaveManager] autosave не найден, сохраняем пустое состояние\n";
	lea	rsi, .LC100[rip]	#,
	lea	rdi, _ZSt4cerr[rip]	#,
.LEHB49:
	call	[QWORD PTR _ZStlsISt11char_traitsIcEERSt13basic_ostreamIcT_ES5_PKc@GOTPCREL[rip]]	#
	jmp	.L445	#
.L454:
# save_manager.cpp:217:         std::cerr << "[SaveManager] Достигнут лимит сохранений (12)\n";
	lea	rsi, .LC99[rip]	#,
	lea	rdi, _ZSt4cerr[rip]	#,
# save_manager.cpp:218:         return -1;
	mov	ebx, -1	# <retval>,
# save_manager.cpp:217:         std::cerr << "[SaveManager] Достигнут лимит сохранений (12)\n";
	call	[QWORD PTR _ZStlsISt11char_traitsIcEERSt13basic_ostreamIcT_ES5_PKc@GOTPCREL[rip]]	#
.LEHE49:
# save_manager.cpp:218:         return -1;
	jmp	.L442	#
.L456:
# save_manager.cpp:250: }
	call	[QWORD PTR __stack_chk_fail@GOTPCREL[rip]]	#
.L451:
# save_manager.cpp:223:     if (!readSaveFile(AUTOSAVE_FILE, state)) {
	mov	rbx, rax	# tmp181,
	jmp	.L446	#
.L452:
# save_manager.cpp:250: }
	mov	rbx, rax	# tmp182,
	jmp	.L448	#
	.section	.gcc_except_table
.LLSDA13559:
	.byte	0xff
	.byte	0xff
	.byte	0x1
	.uleb128 .LLSDACSE13559-.LLSDACSB13559
.LLSDACSB13559:
	.uleb128 .LEHB45-.LFB13559
	.uleb128 .LEHE45-.LEHB45
	.uleb128 0
	.uleb128 0
	.uleb128 .LEHB46-.LFB13559
	.uleb128 .LEHE46-.LEHB46
	.uleb128 .L451-.LFB13559
	.uleb128 0
	.uleb128 .LEHB47-.LFB13559
	.uleb128 .LEHE47-.LEHB47
	.uleb128 0
	.uleb128 0
	.uleb128 .LEHB48-.LFB13559
	.uleb128 .LEHE48-.LEHB48
	.uleb128 .L452-.LFB13559
	.uleb128 0
	.uleb128 .LEHB49-.LFB13559
	.uleb128 .LEHE49-.LEHB49
	.uleb128 0
	.uleb128 0
.LLSDACSE13559:
	.text
	.cfi_endproc
	.section	.text.unlikely
	.cfi_startproc
	.cfi_personality 0x9b,DW.ref.__gxx_personality_v0
	.cfi_lsda 0x1b,.LLSDAC13559
	.type	_ZN11SaveManager15createNamedSaveERKNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEEE.cold, @function
_ZN11SaveManager15createNamedSaveERKNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEEE.cold:
.LFSB13559:
.L446:
	.cfi_def_cfa_offset 320
	.cfi_offset 3, -56
	.cfi_offset 6, -48
	.cfi_offset 12, -40
	.cfi_offset 13, -32
	.cfi_offset 14, -24
	.cfi_offset 15, -16
# save_manager.cpp:223:     if (!readSaveFile(AUTOSAVE_FILE, state)) {
	mov	rdi, rbp	#, tmp168
	call	[QWORD PTR _ZNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEED1Ev@GOTPCREL[rip]]	#
	mov	rax, QWORD PTR 248[rsp]	# tmp183, D.189722
	sub	rax, QWORD PTR fs:40	# tmp183, MEM[(<address-space-1> long unsigned int *)40B]
	jne	.L457	#,
	mov	rdi, rbx	#, tmp181
.LEHB50:
	call	[QWORD PTR _Unwind_Resume@GOTPCREL[rip]]	#
.L448:
# save_manager.cpp:250: }
	mov	rdi, rbp	#, tmp168
	call	_ZN9SaveEntryD1Ev	#
	mov	rax, QWORD PTR 248[rsp]	# tmp184, D.189722
	sub	rax, QWORD PTR fs:40	# tmp184, MEM[(<address-space-1> long unsigned int *)40B]
	jne	.L458	#,
	mov	rdi, rbx	#, tmp182
	call	[QWORD PTR _Unwind_Resume@GOTPCREL[rip]]	#
.LEHE50:
.L457:
	call	[QWORD PTR __stack_chk_fail@GOTPCREL[rip]]	#
.L458:
	call	[QWORD PTR __stack_chk_fail@GOTPCREL[rip]]	#
	.cfi_endproc
.LFE13559:
	.section	.gcc_except_table
.LLSDAC13559:
	.byte	0xff
	.byte	0xff
	.byte	0x1
	.uleb128 .LLSDACSEC13559-.LLSDACSBC13559
.LLSDACSBC13559:
	.uleb128 .LEHB50-.LCOLDB101
	.uleb128 .LEHE50-.LEHB50
	.uleb128 0
	.uleb128 0
.LLSDACSEC13559:
	.section	.text.unlikely
	.text
	.size	_ZN11SaveManager15createNamedSaveERKNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEEE, .-_ZN11SaveManager15createNamedSaveERKNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEEE
	.section	.text.unlikely
	.size	_ZN11SaveManager15createNamedSaveERKNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEEE.cold, .-_ZN11SaveManager15createNamedSaveERKNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEEE.cold
.LCOLDE101:
	.text
.LHOTE101:
	.section	.rodata.str1.1
.LC102:
	.string	"next_number"
.LC103:
	.string	"count"
.LC104:
	.string	"entry"
	.section	.text.unlikely
	.align 2
.LCOLDB105:
	.text
.LHOTB105:
	.align 2
	.p2align 4
	.globl	_ZN11SaveManager9loadIndexEv
	.type	_ZN11SaveManager9loadIndexEv, @function
_ZN11SaveManager9loadIndexEv:
.LFB13569:
	.cfi_startproc
	.cfi_personality 0x9b,DW.ref.__gxx_personality_v0
	.cfi_lsda 0x1b,.LLSDA13569
	push	r15	#
	.cfi_def_cfa_offset 16
	.cfi_offset 15, -16
	push	r14	#
	.cfi_def_cfa_offset 24
	.cfi_offset 14, -24
# save_manager.cpp:314:     entries.clear();
	lea	r14, 8[rdi]	# _1,
# save_manager.cpp:313: void SaveManager::loadIndex() {
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
	sub	rsp, 664	#,
	.cfi_def_cfa_offset 720
# save_manager.cpp:313: void SaveManager::loadIndex() {
	mov	r12, QWORD PTR fs:40	# this, MEM[(<address-space-1> long unsigned int *)40B]
	mov	QWORD PTR 648[rsp], r12	# D.189739, this
	mov	r12, rdi	# this, this
# save_manager.cpp:317:     std::ifstream f(INDEX_FILE);
	lea	rbp, 128[rsp]	# tmp168,
# save_manager.cpp:314:     entries.clear();
	mov	rdi, r14	#, _1
	call	_ZNSt6vectorI9SaveEntrySaIS0_EE5clearEv	#
# save_manager.cpp:317:     std::ifstream f(INDEX_FILE);
	mov	rdi, rbp	#, tmp168
	mov	edx, 8	#,
	lea	rsi, .LC79[rip]	#,
# save_manager.cpp:315:     nextSaveNumber = 1;
	mov	DWORD PTR 32[r12], 1	# this_16(D)->nextSaveNumber,
.LEHB51:
# save_manager.cpp:317:     std::ifstream f(INDEX_FILE);
	call	[QWORD PTR _ZNSt14basic_ifstreamIcSt11char_traitsIcEEC1EPKcSt13_Ios_Openmode@GOTPCREL[rip]]	#
.LEHE51:
# save_manager.cpp:318:     if (!f.is_open()) return;  // файла нет — первый запуск
	mov	rdi, rbp	#, tmp168
	call	[QWORD PTR _ZNSt14basic_ifstreamIcSt11char_traitsIcEE7is_openEv@GOTPCREL[rip]]	#
# save_manager.cpp:318:     if (!f.is_open()) return;  // файла нет — первый запуск
	test	al, al	# _2
	je	.L482	#,
# save_manager.cpp:320:     std::string key;
	lea	rdi, 16[rsp]	#,
	call	[QWORD PTR _ZNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEEC1Ev@GOTPCREL[rip]]	#
# save_manager.cpp:321:     int count = 0;
	mov	DWORD PTR 12[rsp], 0	# count,
	.p2align 4
	.p2align 3
.L462:
# save_manager.cpp:323:     while (f >> key) {
	lea	rsi, 16[rsp]	#,
	mov	rdi, rbp	#, tmp168
.LEHB52:
	call	[QWORD PTR _ZStrsIcSt11char_traitsIcESaIcEERSt13basic_istreamIT_T0_ES7_RNSt7__cxx1112basic_stringIS4_S5_T1_EE@GOTPCREL[rip]]	#
.LEHE52:
# save_manager.cpp:323:     while (f >> key) {
	mov	rdx, QWORD PTR [rax]	# _24->_vptr.basic_istream, _24->_vptr.basic_istream
	add	rax, QWORD PTR -24[rdx]	# _24, MEM[(long int *)_6 + -24B]
	mov	rdi, rax	# _9, _24
	call	[QWORD PTR _ZNKSt9basic_iosIcSt11char_traitsIcEEcvbEv@GOTPCREL[rip]]	#
# save_manager.cpp:323:     while (f >> key) {
	test	al, al	# _25
	je	.L483	#,
# save_manager.cpp:324:         if (key == "next_number") {
	lea	rsi, .LC102[rip]	#,
	lea	rdi, 16[rsp]	#,
	call	_ZSteqIcSt11char_traitsIcESaIcEEbRKNSt7__cxx1112basic_stringIT_T0_T1_EEPKS5_	#
# save_manager.cpp:324:         if (key == "next_number") {
	test	al, al	# _31
	jne	.L484	#,
# save_manager.cpp:326:         } else if (key == "count") {
	lea	rsi, .LC103[rip]	#,
	lea	rdi, 16[rsp]	#,
	call	_ZSteqIcSt11char_traitsIcESaIcEEbRKNSt7__cxx1112basic_stringIT_T0_T1_EEPKS5_	#
# save_manager.cpp:326:         } else if (key == "count") {
	test	al, al	# _32
	jne	.L485	#,
# save_manager.cpp:328:         } else if (key == "entry") {
	lea	rsi, .LC104[rip]	#,
	lea	rdi, 16[rsp]	#,
	call	_ZSteqIcSt11char_traitsIcESaIcEEbRKNSt7__cxx1112basic_stringIT_T0_T1_EEPKS5_	#
# save_manager.cpp:328:         } else if (key == "entry") {
	test	al, al	# _33
	je	.L462	#,
# save_manager.cpp:329:             SaveEntry e;
	lea	rdi, 48[rsp]	#,
	call	_ZN9SaveEntryC1Ev	#
# save_manager.cpp:330:             f >> e.number >> e.filename;
	lea	rsi, 48[rsp]	#,
	mov	rdi, rbp	#, tmp168
.LEHB53:
	call	[QWORD PTR _ZNSirsERi@GOTPCREL[rip]]	#
# save_manager.cpp:330:             f >> e.number >> e.filename;
	lea	rsi, 88[rsp]	# tmp137,
	mov	rdi, rax	#, _36
	call	[QWORD PTR _ZStrsIcSt11char_traitsIcESaIcEERSt13basic_istreamIT_T0_ES7_RNSt7__cxx1112basic_stringIS4_S5_T1_EE@GOTPCREL[rip]]	#
# save_manager.cpp:332:             std::getline(f, e.name);
	lea	rsi, 56[rsp]	#,
	mov	rdi, rbp	#, tmp168
	call	[QWORD PTR _ZSt7getlineIcSt11char_traitsIcESaIcEERSt13basic_istreamIT_T0_ES7_RNSt7__cxx1112basic_stringIS4_S5_T1_EE@GOTPCREL[rip]]	#
# save_manager.cpp:334:             if (!e.name.empty() && e.name[0] == ' ')
	lea	rdi, 56[rsp]	#,
	call	[QWORD PTR _ZNKSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEE5emptyEv@GOTPCREL[rip]]	#
# save_manager.cpp:334:             if (!e.name.empty() && e.name[0] == ' ')
	test	al, al	# _4
	jne	.L469	#,
# save_manager.cpp:334:             if (!e.name.empty() && e.name[0] == ' ')
	xor	esi, esi	#
	lea	rdi, 56[rsp]	#,
	call	[QWORD PTR _ZNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEEixEm@GOTPCREL[rip]]	#
# save_manager.cpp:334:             if (!e.name.empty() && e.name[0] == ' ')
	cmp	BYTE PTR [rax], 32	# *_39,
	je	.L486	#,
.L469:
# save_manager.cpp:336:             entries.push_back(e);
	lea	rsi, 48[rsp]	#,
	mov	rdi, r14	#, _1
	call	_ZNSt6vectorI9SaveEntrySaIS0_EE9push_backERKS0_	#
.LEHE53:
# save_manager.cpp:337:         }
	lea	rdi, 48[rsp]	#,
	call	_ZN9SaveEntryD1Ev	#
	jmp	.L462	#
	.p2align 4,,10
	.p2align 3
.L484:
# save_manager.cpp:325:             f >> nextSaveNumber;
	lea	rsi, 32[r12]	# _3,
	mov	rdi, rbp	#, tmp168
.LEHB54:
	call	[QWORD PTR _ZNSirsERi@GOTPCREL[rip]]	#
	jmp	.L462	#
	.p2align 4,,10
	.p2align 3
.L485:
# save_manager.cpp:327:             f >> count;
	lea	rsi, 12[rsp]	# tmp129,
	mov	rdi, rbp	#, tmp168
	call	[QWORD PTR _ZNSirsERi@GOTPCREL[rip]]	#
.LEHE54:
	jmp	.L462	#
	.p2align 4,,10
	.p2align 3
.L483:
# save_manager.cpp:339: }
	lea	rdi, 16[rsp]	#,
	call	[QWORD PTR _ZNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEED1Ev@GOTPCREL[rip]]	#
.L482:
# save_manager.cpp:339: }
	mov	rdi, rbp	#, tmp168
	call	[QWORD PTR _ZNSt14basic_ifstreamIcSt11char_traitsIcEED1Ev@GOTPCREL[rip]]	#
# save_manager.cpp:339: }
	mov	rax, QWORD PTR 648[rsp]	# tmp188, D.189739
	sub	rax, QWORD PTR fs:40	# tmp188, MEM[(<address-space-1> long unsigned int *)40B]
	jne	.L487	#,
	add	rsp, 664	#,
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
.L486:
	.cfi_restore_state
# save_manager.cpp:335:                 e.name.erase(0, 1);
	mov	edx, 1	#,
	xor	esi, esi	#
	lea	rdi, 56[rsp]	#,
.LEHB55:
	call	[QWORD PTR _ZNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEE5eraseEmm@GOTPCREL[rip]]	#
.LEHE55:
	jmp	.L469	#
.L487:
# save_manager.cpp:339: }
	call	[QWORD PTR __stack_chk_fail@GOTPCREL[rip]]	#
.L476:
# save_manager.cpp:337:         }
	mov	r12, rax	# tmp185,
	jmp	.L471	#
.L475:
# save_manager.cpp:339: }
	mov	r12, rax	# tmp157, tmp186
	jmp	.L472	#
	.section	.gcc_except_table
.LLSDA13569:
	.byte	0xff
	.byte	0xff
	.byte	0x1
	.uleb128 .LLSDACSE13569-.LLSDACSB13569
.LLSDACSB13569:
	.uleb128 .LEHB51-.LFB13569
	.uleb128 .LEHE51-.LEHB51
	.uleb128 0
	.uleb128 0
	.uleb128 .LEHB52-.LFB13569
	.uleb128 .LEHE52-.LEHB52
	.uleb128 .L475-.LFB13569
	.uleb128 0
	.uleb128 .LEHB53-.LFB13569
	.uleb128 .LEHE53-.LEHB53
	.uleb128 .L476-.LFB13569
	.uleb128 0
	.uleb128 .LEHB54-.LFB13569
	.uleb128 .LEHE54-.LEHB54
	.uleb128 .L475-.LFB13569
	.uleb128 0
	.uleb128 .LEHB55-.LFB13569
	.uleb128 .LEHE55-.LEHB55
	.uleb128 .L476-.LFB13569
	.uleb128 0
.LLSDACSE13569:
	.text
	.cfi_endproc
	.section	.text.unlikely
	.cfi_startproc
	.cfi_personality 0x9b,DW.ref.__gxx_personality_v0
	.cfi_lsda 0x1b,.LLSDAC13569
	.type	_ZN11SaveManager9loadIndexEv.cold, @function
_ZN11SaveManager9loadIndexEv.cold:
.LFSB13569:
.L471:
	.cfi_def_cfa_offset 720
	.cfi_offset 3, -56
	.cfi_offset 6, -48
	.cfi_offset 12, -40
	.cfi_offset 13, -32
	.cfi_offset 14, -24
	.cfi_offset 15, -16
# save_manager.cpp:337:         }
	lea	rdi, 48[rsp]	#,
	call	_ZN9SaveEntryD1Ev	#
.L472:
# save_manager.cpp:339: }
	lea	rdi, 16[rsp]	#,
	call	[QWORD PTR _ZNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEED1Ev@GOTPCREL[rip]]	#
	mov	rdi, rbp	#, tmp168
	call	[QWORD PTR _ZNSt14basic_ifstreamIcSt11char_traitsIcEED1Ev@GOTPCREL[rip]]	#
	mov	rax, QWORD PTR 648[rsp]	# tmp187, D.189739
	sub	rax, QWORD PTR fs:40	# tmp187, MEM[(<address-space-1> long unsigned int *)40B]
	jne	.L488	#,
	mov	rdi, r12	#, tmp157
.LEHB56:
	call	[QWORD PTR _Unwind_Resume@GOTPCREL[rip]]	#
.LEHE56:
.L488:
	call	[QWORD PTR __stack_chk_fail@GOTPCREL[rip]]	#
	.cfi_endproc
.LFE13569:
	.section	.gcc_except_table
.LLSDAC13569:
	.byte	0xff
	.byte	0xff
	.byte	0x1
	.uleb128 .LLSDACSEC13569-.LLSDACSBC13569
.LLSDACSBC13569:
	.uleb128 .LEHB56-.LCOLDB105
	.uleb128 .LEHE56-.LEHB56
	.uleb128 0
	.uleb128 0
.LLSDACSEC13569:
	.section	.text.unlikely
	.text
	.size	_ZN11SaveManager9loadIndexEv, .-_ZN11SaveManager9loadIndexEv
	.section	.text.unlikely
	.size	_ZN11SaveManager9loadIndexEv.cold, .-_ZN11SaveManager9loadIndexEv.cold
.LCOLDE105:
	.text
.LHOTE105:
	.section	.rodata.cst16,"aM",@progbits,16
	.align 16
.LC0:
	.quad	3688503277381496880
	.quad	3976738051646829616
	.align 16
.LC1:
	.quad	3544667369688283184
	.quad	3832902143785906737
	.align 16
.LC2:
	.quad	4121136918051239473
	.quad	3689066235924983858
	.align 16
.LC3:
	.quad	3977301010190316594
	.quad	3545230328231770162
	.align 16
.LC4:
	.quad	3833465102329393715
	.quad	4121699876594726451
	.align 16
.LC5:
	.quad	3689629194468470836
	.quad	3977863968733803572
	.align 16
.LC6:
	.quad	3545793286775257140
	.quad	3834028060872880693
	.align 16
.LC7:
	.quad	4122262835138213429
	.quad	3690192153011957814
	.align 16
.LC8:
	.quad	3978426927277290550
	.quad	3546356245318744118
	.align 16
.LC9:
	.quad	3834591019416367671
	.quad	4122825793681700407
	.align 16
.LC10:
	.quad	3690755111555444792
	.quad	3978989885820777528
	.align 16
.LC11:
	.quad	3546919203862231096
	.quad	3835153977959854649
	.align 16
.LC12:
	.quad	4122263930388298034
	.quad	16106987313379638
	.section	.rodata.cst4,"aM",@progbits,4
	.align 4
.LC33:
	.long	1114636288
	.section	.rodata.cst16
	.align 16
.LC75:
	.long	0
	.long	1
	.long	3
	.long	44
	.align 16
.LC76:
	.long	4
	.long	7
	.long	22
	.long	8
	.section	.rodata.cst8,"aM",@progbits,8
	.align 8
.LC77:
	.long	225
	.long	9
	.hidden	DW.ref.__gxx_personality_v0
	.weak	DW.ref.__gxx_personality_v0
	.section	.data.rel.local.DW.ref.__gxx_personality_v0,"awG",@progbits,DW.ref.__gxx_personality_v0,comdat
	.align 8
	.type	DW.ref.__gxx_personality_v0, @object
	.size	DW.ref.__gxx_personality_v0, 8
DW.ref.__gxx_personality_v0:
	.quad	__gxx_personality_v0
	.globl	__gxx_personality_v0
	.ident	"GCC: (GNU) 15.2.1 20260209"
	.section	.note.GNU-stack,"",@progbits
