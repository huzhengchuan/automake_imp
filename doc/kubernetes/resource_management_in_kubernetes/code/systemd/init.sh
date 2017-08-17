[Unit]
Description=Runtime resources Slice
DefaultDependencies=no
Before=slices.target

[Slice]
MemoryLimit=500M


修改进程Unit增加字段即可
Slice=runtime.slice

