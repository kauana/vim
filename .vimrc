# Kau's Vim
execute pathogen#infect()

syntax on
set nocompatible

set expandtab
set backspace=2
set softtabstop=4
set shiftwidth=4
set autoindent
set smartindent
set number
:ab sop System.out.println(

set statusline+=%#warningmsg#
set statusline+=%{SyntasticStatuslineFlag()}
set statusline+=%*

let g:syntastic_always_populate_loc_list = 1
let g:syntastic_auto_loc_list = 1
let g:syntastic_check_on_open = 1
let g:syntastic_check_on_wq = 0

set hlsearch

let g:rehash256 = 1
colorscheme molokai

nmap <space> :noh<cr>
nmap <cr> :w<cr>
