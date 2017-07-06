execute pathogen#infect()
syntax on
filetype plugin indent on

" remove vi settings
set nocompatible

set expandtab       " doesnt use tab characters
set softtabstop=4   " when I press tab it puts 4 spaces instead
set backspace=indent,eol,start
set shiftwidth=4    " indenting 4 spaces

set autoindent  " indent automatically
set smartindent " automatically inserts one extra level of indentation in some cases

" adds line number
set number

" search highlights
set hlsearch

" My Vim theme: Sorcery Dark
set termguicolors
colorscheme srcery-drk

" After you search for a word with /, pressing <space> cancels search
nmap <space> :noh<cr>

" saves file when you press enter on cmd mode
nmap <cr> :w<cr>

" auto bracket {<Enter gives { cursor }
inoremap {<CR> {}<Esc>i<CR><Esc>O

" Synthastic Setting 
set statusline+=%#warningmsg#
set statusline+=%{SyntasticStatuslineFlag()}
set statusline+=%*

let g:syntastic_always_populate_loc_list = 1
let g:syntastic_auto_loc_list = 1
let g:syntastic_check_on_open = 1
let g:syntastic_check_on_wq = 0
