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
let g:syntastic_check_on_open = 0
let g:syntastic_check_on_wq = 0

" turn off syntax checker YouCompleteMe
let g:ycm_show_diagnostics_ui = 0
let g:ycm_global_ycm_extra_conf = '~/.vim/bundle/YouCompleteMe/third_party/ycmd/cpp/ycm/.ycm_extra_conf.py'
set completeopt-=preview

" adds name of the file to the vim tab
autocmd BufEnter * let &titlestring = ' ' . expand("%:t")
set title

" theme for vim-airline
let g:airline_theme='luna'
" remove utf8 from vim airline
let g:airline#parts#ffenc#skip_expected_string='utf-8[unix]'

set list          " lists white spaces in files
set listchars=tab:•\ ,trail:•,extends:»,precedes:« " uses shown symbol to show white spaces

function! ToggleErrors()
    if empty(filter(tabpagebuflist(), 'getbufvar(v:val, "&buftype") is# "quickfix"'))
         " No location/quickfix list shown, open syntastic error location panel
         Errors
    else
        lclose
    endif
endfunction

" togglelist hotkey to open/close location list
let mapleader = ","
nnoremap <silent> <leader>l :call ToggleErrors()<cr>

" manual for cpp
autocmd FileType cpp set keywordprg=cppman

