This repository contains all the settings and plugins I use on Vim. To install it all over again (e.g if formatting pc) then follow these instructions:

- Use git clone to copy reposity to home directory. Make sure to clone the repository into a directory named .vim instead of vim (new name is the next  command line option after url)

- Since .vimrc is inside the .vim directory now, we create a symbolic link to link this .vimrc to our home directory (ln -s ~/.vim/.vimrc .vimrc)

- Also, pathogen must be installed again so use the commands below to install Pathogen. All the settings necessary to make it work are already on the vimrc file:
mkdir -p ~/.vim/autoload ~/.vim/bundle && \
curl -LSso ~/.vim/autoload/pathogen.vim https://tpo.pe/pathogen.vim

- It may be necessary to update Vim for this to work so go ahead and install the newest Vim version with homebrew or any other package manager.
