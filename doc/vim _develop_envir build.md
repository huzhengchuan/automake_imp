##Vim 编程环境搭建

* apt-get install vim 

* apt-get install ctags  提高代码阅读能力

* taglist.vim : Source code browser 
	> 1. description:
	The "Tag List" plugin is a source code browser plugin for Vim and 
	provides an overview of the structure of source code files and allows you to efficiently browse through source code files for different programming languages. 
	> 2. install:
		> 1. down the http://vim-taglist.sourceforge.net
		> 2. unzip the files to the $HOME/.vim or the $HOME/vimfiles or the $VIM/vimfiles directory.  
		> 3. Change to the $HOME/.vim/doc or $HOME/vimfiles/doc or $VIM/vimfiles/doc directory, start Vim and run the ":helptags ." command to process the taglist help file. Without this step, you cannot jump to the taglist help  topics. 
	> 3. Usage:
		> 1. Tlist ->触发，或者直接配置vim.rc里面，默认打开
		> 2. Tlist与代码屏幕之间切换  Ctrl+w h/j/k/l  配合使用使得光标移动到上下左右的窗口
		> 3. 关闭窗口 Ctrl+z ctrl+z 连续两下，关闭当前的窗口
		> 4. :only 只保留当前光标所在的窗口
		> 