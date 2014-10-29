##Git 学习总结##

###Git 基本概念 ###
1. 工作目录 暂存区 本地仓库 远端仓库
![Alt text](https://github.com/huzhengchuan/automake_imp/tree/master/image/No_1_Git_1.jpg "desc the struct in git")


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