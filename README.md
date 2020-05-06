# assembly examples

callstack

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

is this correct?