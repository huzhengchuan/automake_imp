#!/bin/bash


echo "cpu demo, pid is $$"
x=0

while [ True ];do
        x=$x+1
done;



###demo introduct
# top --> 1 
# mkdir /mnt/cgroups/cpu
# mount -t cgroup -o cpu,cpuacct cpu /mnt/cgroups/cpu
# mount -t cgroup -o cpuset cpuset /mnt/cgroups/cpu
# mkdir /mnt/cgroups/cpu/demo/
# mkdir /mnt/cgroups/cpuset/demo/
# echo pid >> /mnt/cgroups/cpu/demo/cgroup.procs
# echo 50000 >> /mnt/cgroups/cpu/demo/cpu.cfs_quota_us
# echo 1 > /mnt/cgroups/cpuset/demo/cpuset.cpus
# echo pid >> /mnt/cgroups/cpu/demo/cgroup.procs
