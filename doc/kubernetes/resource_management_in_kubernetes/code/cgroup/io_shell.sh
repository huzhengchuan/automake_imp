#!/bin/bash

echo "io demo, pid $$"
dd if=/dev/sda1 of=/dev/null

##demo introduct
#mkdir /mnt/cgroup/blkio
#mount -t cgroup -o blkio none /sys/fs/cgroup/blkio
#mkdir /sys/fs/cgroup/blkio/demo
# echo '8:0   1048576' >  /mnt/cgroup/blkio/demo/blkio.throttle.read_bps_device  #通过写 blkio.throttle.read_iops_device 来限制  U盘的每秒IO 次数
#8:0 1048576  /dev/sda1的主次设备号 lsblk |  iostat -xm sda1 10  
#echo pid >/sys/fs/cgroup/blkio/demo/cgroup.proc
