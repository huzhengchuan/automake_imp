#define _GNU_SOURCE
#include <sched.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <unistd.h>


static char child_stack[1048576];

static int child_fn() {
    printf("New `net` Namespace:\n");
    int count = 10;
    int loop = 0;
    for (loop = 0; loop < count; loop++)
    {
        printf("loop=%d\n", loop); 
        system("ip link");
        system("sleep 3");
        printf("\n\n");
    }
    return 0;
}

int main() {
    printf("Original `net` Namespace:\n");
    system("ip link");
    printf("\n\n");

    pid_t child_pid = clone(child_fn, child_stack+1048576, CLONE_NEWPID | CLONE_NEWNET | SIGCHLD, NULL);

    printf("\n\nthe child_pid=%ld in parent\n\n", (long)child_pid);
    
    waitpid(child_pid, NULL, 0);
    return 0;
}
