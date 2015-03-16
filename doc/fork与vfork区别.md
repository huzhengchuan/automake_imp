##vfork与fork的区别

1. vfork和fork一样，都是调用一次，返回两次。
2. 使用fork创建一个子进程，子进程只是完全复制父进程的资源。这样得到的子进程独立于父进程，具有良好的并发性。而使用vfork创建一个子进程时，操作系统并不将父进程的地址空间完全复制到子进程，用vfork创建的子进程共享父进程的地址空间，也就是说子进程完全运行于父进程的地址空间上。子进程对该地址空间中任何数据的修改同样为父进程所见。
3. 使用fork创建一个子进程时，哪个进程先运行取决于系统的调度算法。而vfork一个进程时，vfork保证子进程先运行，当它调用exec或exit之后，父进程才可能被调度运行。如果在调用exec或exit之前子进程要依赖父进程的某个行为，就会导致死锁。
因为fork创建一个进程时，子进程需要将父进程几乎每种资源都复制，所以fork是一个开销很大的系统调用，这些开销并不是所有情况都需要的。比如fork一个进程后，立即调用exec执行另外一个应用程序，那么fork过程中子进程对父进程地址空间的复制将是一个多余的过程。vfork不会拷贝父进程的地址空间，这大大减小了系统开销。

######注意：使用vfork时要谨慎，最好不要允许子进程修改与父进程共享的全局变量和局部变量。

####What's the difference between fork() and vfork()?


Some systems have a system call vfork(), which was originally 
designed as a lower-overhead version of fork(). Since 
fork() involved copying the entire address space of the process, 
and was therefore quite expensive, the vfork() function was 
introduced (in 3.0BSD). 



However, since vfork() was introduced, the 
implementation of fork() has improved drastically, most notably 
with the introduction of `copy-on-write', where the copying of the 
process address space is transparently faked by allowing both processes 
to refer to the same physical memory until either of them modify 
it. This largely removes the justification for vfork(); indeed, a 
large proportion of systems now lack the original functionality of 
vfork() completely. For compatibility, though, there may still be 
a vfork() call present, that simply calls fork() without 
attempting to emulate all of the vfork() semantics. 



As a result, it is very unwise to actually make use of any of the 
differences between fork() and vfork(). Indeed, it is 
probably unwise to use vfork() at all, unless you know exactly 
why you want to. 



The basic difference between the two is that when a new process is 
created with vfork(), the parent process is temporarily 
suspended, and the child process might borrow the parent's address 
space. This strange state of affairs continues until the child process 
either exits, or calls execve(), at which point the parent 
process continues. 



This means that the child process of a vfork() must be careful to 
avoid unexpectedly modifying variables of the parent process. In 
particular, the child process must not return from the function 
containing the vfork() call, and it must not call 
exit() (if it needs to exit, it should use _exit(); 
actually, this is also true for the child of a normal fork()).



