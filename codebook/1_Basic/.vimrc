sy on
set si nu rnu cin cul et so=10 ts=4 sw=4 mouse=a
ino {<cr> {<cr>}<esc>ko
ino jk <esc> 
map <F7> :w<CR>:!g++ "%" -std=c++17 -DLOCAL -Wall -Wextra -Wshadow -Wconversion -fsanitize=address,undefined -g && ./a.out<CR>
ca Hash w !cpp -dD -P -fpreprocessed \| tr -d "[:space:]" \| md5sum \| cut -c-6
