# assembly examples

Assembly tutorial examples.

Requirements
---

* clang	
* otool


Examples
---

* a call stack sequence
* swap (a canonical example)
* tbd ...

Run 
---

Use the provided script `run` with a provided directory as argument to compile the corresponding c code sample and display its assembly code.

For example

```
./run callstack

```


Assembly
---


### Callstack

```

     main
     / \
    f   g
   /     \
  1       2
  
```

the order of stack ops should be 

The stack procedure is in this case: push main, push f, push 1, compute 1, pop 1, compute f, pop f, push g, push 2, compute 2, pop 2, compute g, pop g, compute main, pop main.

(ref blog post)


assembly comes out

```

(__TEXT,__text) section
_f:
0000000100000f70        pushq   %rbp
0000000100000f71        movq    %rsp, %rbp
0000000100000f74        movl    $0x1, %eax
0000000100000f79        popq    %rbp
0000000100000f7a        retq
0000000100000f7b        nopl    (%rax,%rax)
_g:
0000000100000f80        pushq   %rbp
0000000100000f81        movq    %rsp, %rbp
0000000100000f84        movl    $0x3, %eax
0000000100000f89        popq    %rbp
0000000100000f8a        retq
0000000100000f8b        nopl    (%rax,%rax)
_main:
0000000100000f90        pushq   %rbp
0000000100000f91        movq    %rsp, %rbp
0000000100000f94        subq    $0x10, %rsp
0000000100000f98        callq   _f
0000000100000f9d        movl    %eax, -0x4(%rbp)
0000000100000fa0        callq   _g
0000000100000fa5        xorl    %ecx, %ecx
0000000100000fa7        movl    %eax, -0x8(%rbp)
0000000100000faa        movl    %ecx, %eax
0000000100000fac        addq    $0x10, %rsp
0000000100000fb0        popq    %rbp
0000000100000fb1        retq

```

### Swap

classic example 

```
_swap:
0000000100000f40	pushq	%rbp
0000000100000f41	movq	%rsp, %rbp
0000000100000f44	movq	%rdi, -0x8(%rbp)
0000000100000f48	movq	%rsi, -0x10(%rbp)
0000000100000f4c	movq	-0x8(%rbp), %rsi
0000000100000f50	movq	(%rsi), %rsi
0000000100000f53	movq	%rsi, -0x18(%rbp)
0000000100000f57	movq	-0x10(%rbp), %rsi
0000000100000f5b	movq	(%rsi), %rsi
0000000100000f5e	movq	%rsi, -0x20(%rbp)
0000000100000f62	movq	-0x20(%rbp), %rsi
0000000100000f66	movq	-0x8(%rbp), %rdi
0000000100000f6a	movq	%rsi, (%rdi)
0000000100000f6d	movq	-0x18(%rbp), %rsi
0000000100000f71	movq	-0x10(%rbp), %rdi
0000000100000f75	movq	%rsi, (%rdi)
0000000100000f78	popq	%rbp
0000000100000f79	retq
0000000100000f7a	nopw	(%rax,%rax)
_main:
0000000100000f80	pushq	%rbp
0000000100000f81	movq	%rsp, %rbp
0000000100000f84	subq	$0x10, %rsp
0000000100000f88	movq	$0x7b, -0x8(%rbp)
0000000100000f90	movq	$0x1c8, -0x10(%rbp)
0000000100000f98	leaq	-0x8(%rbp), %rdi
0000000100000f9c	leaq	-0x10(%rbp), %rsi
0000000100000fa0	callq	_swap
0000000100000fa5	xorl	%eax, %eax
0000000100000fa7	addq	$0x10, %rsp
0000000100000fab	popq	%rbp
0000000100000fac	retq
```

