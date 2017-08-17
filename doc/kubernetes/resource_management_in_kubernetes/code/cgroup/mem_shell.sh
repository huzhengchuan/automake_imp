#!/bin/bash

echo "mem demo, pid is $$"
x="a"

while [ True ];do
        x=$x$x
done;



##mount -t cgroup -o cpu,cpuset,memory cpu_and_mem /cgroup/cpu_and_mem 这个命令就创建一个名为cpu_and_mem的层级，这个层级上附加了cpu,cpuset,memory三个子系统，并把层级挂载到了/cgroup/cpu_and_mem.


##demo introduct
#mount -t cgroup -o memory memory /mnt/cgroup/memory
#mkdir /mnt/cgroup/memory/demo
#echo 1024 >  /mnt/cgroup/memory/demo/memory.limit_in_bytes
#echo pid > /mnt/cgroup/memory/demo/cgroup.procs
