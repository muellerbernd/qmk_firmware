let SessionLoad = 1
let s:so_save = &g:so | let s:siso_save = &g:siso | setg so=0 siso=0 | setl so=-1 siso=-1
let v:this_session=expand("<sfile>:p")
silent only
silent tabonly
cd ~/Desktop/GithubProjects/my-mechanical-keyboard-journey/qmk_firmware
if expand('%') == '' && !&modified && line('$') <= 1 && getline(1) == ''
  let s:wipebuf = bufnr('%')
endif
let s:shortmess_save = &shortmess
if &shortmess =~ 'A'
  set shortmess=aoOA
else
  set shortmess=aoO
endif
badd +77 keyboards/muellerbernd/sweep/keymaps/bernd/keymap.c
badd +19 keyboards/muellerbernd/sweep/keymaps/bernd-kb2040/config.h
badd +54 keyboards/muellerbernd/sweep/sweep.c
badd +1 keyboards/muellerbernd/sweep/sweep.h
badd +24 keyboards/muellerbernd/sweep/keymaps/bernd-kb2040/rules.mk
badd +27 users/muellerbernd/common_conf.h
badd +28 keyboards/muellerbernd/sweep/keymaps/bernd/rules.mk
badd +36 keyboards/muellerbernd/sweep/keymaps/bernd/config.h
argglobal
%argdel
$argadd keyboards/muellerbernd/sweep/keymaps/bernd/keymap.c
edit keyboards/muellerbernd/sweep/keymaps/bernd/config.h
argglobal
balt keyboards/muellerbernd/sweep/keymaps/bernd/keymap.c
setlocal fdm=indent
setlocal fde=nvim_treesitter#foldexpr()
setlocal fmr={{{,}}}
setlocal fdi=#
setlocal fdl=5
setlocal fml=1
setlocal fdn=20
setlocal fen
let s:l = 36 - ((35 * winheight(0) + 26) / 52)
if s:l < 1 | let s:l = 1 | endif
keepjumps exe s:l
normal! zt
keepjumps 36
normal! 021|
tabnext 1
if exists('s:wipebuf') && len(win_findbuf(s:wipebuf)) == 0 && getbufvar(s:wipebuf, '&buftype') isnot# 'terminal'
  silent exe 'bwipe ' . s:wipebuf
endif
unlet! s:wipebuf
set winheight=1 winwidth=20
let &shortmess = s:shortmess_save
let s:sx = expand("<sfile>:p:r")."x.vim"
if filereadable(s:sx)
  exe "source " . fnameescape(s:sx)
endif
let &g:so = s:so_save | let &g:siso = s:siso_save
set hlsearch
let g:this_session = v:this_session
let g:this_obsession = v:this_session
doautoall SessionLoadPost
unlet SessionLoad
" vim: set ft=vim :
