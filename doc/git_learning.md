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
\add the description of learning
--
\*  [automake_imp_new_feature_11_01] add the branch info about git.
\*+ [master] add the description of learning</code></pre>