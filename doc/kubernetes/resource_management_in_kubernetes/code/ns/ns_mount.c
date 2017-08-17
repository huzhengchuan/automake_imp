#define _GNU_SOURCE
#include <sched.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <unistd.h>

static char child_stack[1048576];

static int child_fn() {
    printf("PID: %ld\n", (long)getpid());
    system(" mount -t tmpfs  none /mytmp");
    system("mount");
    int loop = 0;
    for (loop = 0; loop < 5; loop++)
    {
        system("sleep 3");
        printf("waiting...\r\n");
    }
    
    return 0;
}

int main() {
    
    system("mount");
    printf("\n\n");
    
    pid_t child_pid = clone(child_fn, child_stack+1048576, CLONE_NEWPID | CLONE_NEWNS | SIGCHLD, NULL);

    printf("parent_pid =%ld\n", (long)getpid());
    
    
    waitpid(child_pid, NULL, 0);
    return 0;
}
