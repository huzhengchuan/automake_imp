##Git 学习总结##

###Git 基本概念 ###
1. 工作目录 暂存区 本地仓库 远端仓库


![Alt text](https://raw.githubusercontent.com/huzhengchuan/automake_imp/master/image/No_1_Git_1.jpg "The different content about workspace and so on.")


------
###Git 利用SSH key登陆###
1.  生成SSH Key
$ ssh-keygen -t rsa -C ***@***.com 生成公钥私钥文件

<pre><code>$ ssh-keygen -t rsa -C "**********@gmail.com"
Generating public/private rsa key pair.
Enter file in which to save the key (/c/Users/**********/.ssh/id_rsa):
/c/Users/huzhengchuan/.ssh/id_rsa already exists.
Overwrite (y/n)? y
Enter passphrase (empty for no passphrase):
Enter same passphrase again:
Your identification has been saved in /c/Users/**********/.ssh/id_rsa.
Your public key has been saved in /c/Users/**********/.ssh/id_rsa.pub.
The key fingerprint is:
**:**:ce:f4:f3:7c:14:73:58:48:c3:74:2c:63:**:** **********@gmail.com
The key's randomart image is:
+--[ RSA 2048]----+
|         +++.    |
|          Boo    |
|         o =     |
|        ..= E    |
|    o   S. =     |
|   + + .  .      |
|    o =  .       |
|       +  .      |
|        o.       |
+-----------------+
</code></pre>


2.在github上设置ssh key
复制ssh-key生成的公钥id_rsa.pub内容到github的account settings -> SSH Keys

3.测试配置是否成功
<pre><code>$ ssh -T git@github.com
Enter passphrase for key '/c/Users/**********/.ssh/id_rsa':
Hi **********! You've successfully authenticated, but GitHub does not provide shell access.
</code></pre>

------
###Git 基本命令###
* git init ---

* git config 
* <pre><code>git config --global user.email  "zhengchuanhu@gmail.com"
git config --global user.email  "zhengchuanhu@gmail.com"
</pre></code>

* 暂存区中添加文件
 1. add filename
 2. add dir 递归添加目录，以及目录中的文件
* 删除工程中存在的文件<pre><code>git remove file #删除文件
* git remove directory -rf #删除目录</code></pre>
* 提交到本地仓库<pre><code>git commit -m "reconstruct the directory structure of the project."</code></pre>
 


* 远端仓库操作
 1. git clone一个远端的仓库 <pre><code>$ git clone https://github.com/huzhengchuan/automake_imp.git
Cloning into 'automake_imp'...
remote: Counting objects: 6, done.
remote: Total 6 (delta 0), reused 0 (delta 0)
Unpacking objects: 100% (6/6), done.
Checking connectivity... done. </code></pre>

 2. 查询远端分支 <pre><code>$ git remote -v
origin  https://github.com/huzhengchuan/automake_imp.git (fetch)
origin  https://github.com/huzhengchuan/automake_imp.git (push)  </pre></code>


 3. 更新远端代码到本地的仓库  <pre><code>$ git fetch origin master
From https://github.com/huzhengchuan/automake_imp
 \* branch            master     -> FETCH_HEAD</pre></code>

 4. 同步本地代码到远端仓库<pre><code>$ git push origin master
Username for 'https://github.com': zhengchuanhu@gmail.com
Password for 'https://zhengchuanhu@gmail.com@github.com':
Counting objects: 8, done.
Delta compression using up to 2 threads.
Compressing objects: 100% (6/6), done.
Writing objects: 100% (7/7), 185.31 KiB | 0 bytes/s, done.
Total 7 (delta 0), reused 0 (delta 0)
To https://github.com/huzhengchuan/automake_imp.git
   d5b5913..e71b724  master -> master</code></pre>
 5. 给本地仓库添加远端仓库<pre><code>git remote add origin git@github.com:huzhengchuan/automake_imp.git  #给远端仓库添加一个站名 origin，可以有多个站点，添加完成之后将会在.git目录下的config文件中具有相关配置
    git push origin master #将当前commit提交到origin站点的master branch分支 
  </code></pre>
 
###分支管理###
1. 拉一个分支，修改合入新分支<pre><code>git branch ##列出本地库当前所有分支
git branch -r #列出所有分支，包括本地分支和远端服务器分支
git check -b branch_name  #拉一个分支，并将当前工作分支切换到该分支上
git check branch_name #切换分支
git branch -D  branch_name #删除分支，删除后，发生在该分支上所有变化无法恢复
git show-branch #查看当前分支的提交注释及信息
git show-branch --all #查看所有分支的提交注释及信息，或者通过git log 查看分支的详细信息</code></pre>

2. 如何查看分支信息<pre><code>$ git show-branch
\* [automake_imp_new_feature_11_01] add the branch info about git.
\! [master] add the description of learning 
\--
\*  [automake_imp_new_feature_11_01] add the branch info about git.
\*+ [master] add the description of learning</code></pre>
Notice:\“--”之上的两行表示有两个分支automake_imp_new_feature_11_01和master，且automake_imp_new_feature_11_01分支上最后一次提交的日志是“add the branch info about git.”，master分支上最后一次提交的日志是 “add the description of learning”。 “--”之下的几行表示了分支演化的历史，其中 automake_imp_new_feature_11_01表示发生在automake_imp_new_feature_11_01分支上的最后一次提交

3. 分支合并<pre><code>git merge -m "注释" branch_dest branch_src #将branch_src合并到branch_dest项目中,如果有冲突会有提示信息
git pull branch_dest branch_src ##将branch_src合并到branch_dest,如果有冲突，会有提示信息
git merge -m "注释" branch_dest brach_src --no-ff</code></pre>
Notice:在合并过程的提示“fast-farward merge（快速式合并）”是指直接将branch_src分支指向branch_dest分支。可通过“--no-ff“参数后，会执行正常合并，在master分支上生成一个新节点。为了保证版本演进的清晰，我们希望采用这种做法。

4. 分支回退 git reset 
如果在git commit提交情况下，需要撤销commit提交。
git reset –hard commit_id 即可撤销
git reste参数详解： 
根据–soft –mixed –hard，会对working tree和index和HEAD进行重置： 
git reset –mixed：此为默认方式，不带任何参数的git reset，即时这种方式，它回退到某个版本，只保留源码，回退commit和index信息git reset –soft：回退到某个版本，只回退了commit的信息，不会恢复到index file一级。如果还要提交，直接commit即可 
git reset –hard：彻底回退到某个版本，本地的源码也会变为上一个版本的内容

###标签管理###


###git log常用命令 ###
git log 
<pre><code>$ git log --stat
commit 987ae3bd0e9074830011bf883f842649fd4e95d6
Merge: 852c7e2 c3f5c6a
Author: PeterWang <zhengchuanhu@gmail.com>
Date:   Sun Nov 2 00:44:26 2014 +0800
merge to the master branch</code></pre>


###git 回退机制
1. git checkout -- <filename>  

假如你操作失误（当然，这最好永远不要发生），你可以使用如下命令替换掉本地改动：此命令会使用 HEAD 中的最新内容替换掉你的工作目录中的文件。已添加到暂存区的改动以及新文件都不会受到影响。

2. 假如你想丢弃你在本地的所有改动与提交，可以到服务器上获取最新的版本历史，并将你本地主分支指向它：
<pre><code>
git fetch origin
git reset --hard origin/master
</code></pre>