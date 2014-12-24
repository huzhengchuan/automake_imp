### vim实用技巧
---

* 复制与粘贴

```
	   
```

* .的魅力---重复最近修改的命令
	> 1. 重复最近修改的命令
	> 2. 从进入插入模式到Esc推出到普通的模式，之间所做的操作记录为一个操作流程，执行.的时候将会重新执行上面的操作（插入模式下中移动光标会重置修改状态）。
	> 3. 一次按键，一次执行。  
* 常用的替换模式
<pre><code> f{char} -> s{replace}ESC -> f. 反复执行
：substitue -> %s/content/copy/g  利用copy替换content
/content-> * -> cw{content} -> copy -> n -> .  利用.进行反复的操作  
</code></pre>

* 删除操作
<pre><code>
db -> x 光标位于单词的末尾，反向删除
b -> dw 正向删除，光标移动到单词的开头，dw删除整个单词
daw -> delete a word

</code></pre>

* 常用的一些功能键
<pre><code> > + G 增加当前行到末尾的缩进级别
x 删除当前光标的字符
$ 跳动到行末
A <-> j + $
a 在当前光标之后添加内容
A 在当前行的结尾添加内容
s 删除光标下的字符，并进入插入模式
f{char}/t{char} 正向查找{char}字符，;正向跳转到下一个{char}字符  , 反向调转到上一个{char}字符
F{char}/T{char} 反向查找{char}字符
cw 删除从光标位置到单词结尾间的字符并进入插入模式
$ 0 普通模式下将光标移动到行尾、行头
ctrl+a 对数字执行加法
ctrl +w 对数字执行减法
{num}ctrl+a/w 增加/减少num个数字
2dw d2w dw. ->删除两个连续的单词
 
</code></pre>

* 操作符+动作命令=操作
<pre><code>VIM常用的操作符
c ->修改
d ->删除
y ->复制到寄存器
g~ ->反转大小写
gu ->转换成小写
gU ->转换成大写
>  ->增加缩进
<  ->减小缩进
=  ->自动缩进
！ ->利用外部程序过滤所跨越的行

动作命令
l 一个字符
aw -完整的单词
ap -完整段落

当一个操作符命令被连续调用两次，表示针对该行进操作
dd >> gugu(guu)
</code></pre>


* 插入模式
<pre><code>ctrl + h 删除前一个字符
ctrl + w 删除前一个单词
ctrl + u 删除至行首
yt, [yt, {}y复制 {t,}动作命令]-> jA -> 插入模式 ctrl+r 0  利用寄存器的内容复制内容到下一行的行尾
ctrl+r  =  {插入模式下} 利用表达式寄存器 vim充当计算器的功能
* 利用替换模式替换已经有的脚本
> R 普通模式进入替换模式，直接输入将会替换光标所在的字符为新输入的字符  ESC 退出到普通模式 
</code></pre>

* 可视模式
<pre><code></code></pre>


* history log
<pre><code>init the vim 实用技巧  2014/12/20
add the first and second des  2014/12/23
add the third desc  2014/12/24
</code></pre>