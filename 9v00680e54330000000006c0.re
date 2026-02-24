# So, this is my first vimgold, and originally I had no idea what I was doing,
# but through sheer persistence, I was able to get near the top of the leaderboard!

300:exe 'g/^#/d' | exe 'g/^$/d' | %s/^\(.*\)=\(.*\)$/"\1": "\2",/ | $s/,$// | 0put='{' | $put='}' | 2,$-1normal! I    
80:ddqq}2ddq5@qjddj2dd@qgg<C-V><C-D><Esc><Esc>GggqqI"<Esc>wea": "<Del><Esc>A"m<BS>,<Esc>jq99@qxggVGI    <Esc>j0<C-V><C-D>I    <Esc>ggI{ <CR><Up><End><BS><Left><BS><BS><BS><BS><Esc>GA<CR>}<Left><BS><BS><BS><BS><Esc>:wq<CR>
:g/^#/d|g/^$/d|%s/^\([^=]*\)=\(.*\)$/"\1": "\2",/|$s/,$//|0put='{'|$put='}'|2,$-1>
:g/^#/d<CR>:<Up><Left><Left><BS>$<CR>qai"<Esc>wea": "<Del><Esc>A",<Esc>k0q22n22@agg<C-V><C-D>I    <Esc>i{<CR>    <Esc>GO<Esc>uo<BS><BS><BS><BS>}<Esc>kA<BS><Esc>:wq<CR>

yoinked and improved upon
:g/^#/d<CR>:g/^$/d<CR>o}<Esc>ggi<CR><Esc>ki{<Esc>vi{:norm I    <CR>:2<CR>qai"<Esc>ea": <Del>"<Esc>$a",<Esc>j0wq22@ak$x:wq<CR>
:g/#/d<CR>:g/^$/d<CR>:%s/^\([^=]*\)=\(.*\)/    "\1": "\2",/<CR>A<BS><CR><BS><BS><BS><BS>}<Esc>ggO<BS><BS><BS><BS>{<Esc>ZZ
:g/#\|^$/d
:g/#.*\|^$/d<CR>:%s/$/",<CR>$xo}<Esc>ggO{<Esc>:%s/=/": "<CR>:2,24s/^/    "\0<CR>ZZ
:v/=/d<CR>:%s/\(.*\)=\(.*\)/    "\1": "\2",/<CR>A<BS><CR><BS>}<C-U><C-U>}<Esc>ggO<C-U>{<Esc>ZZ
:g!/=/d<CR>o}<Esc>ggO{<Esc>jqai    "<Esc>ea"<Esc>lr:a "<Esc>A",<Esc>j0q22@akA<BS><Esc>ZZ
:v/=/d<CR>o}<Esc>qa-i    "<Esc>f=a<BS>": "<Esc>A",<Esc>qx22@aO<Esc>i{<Esc>ZZ

# continue here
45:v/=/d<CR>o}<Esc>ggO{<Esc>qqjI    "<Esc>ea"<Del>: "<Esc>A",<Esc>q22@qxZZ
44:v/=/d<CR>o}<C-Home>{<CR><Esc>qmI    "<Esc>els": "<Esc>A",<Esc>jq22@mkxZZ
43:v/=/d<CR>o}<Esc>qakI    "<Esc>ns": "<Esc>A",<Esc>qx22@aO<C-U>{<Esc>ZZ
42:v/=/d<CR>o}<C-Home>{<CR><Esc>qq5I <Esc>r"f=s": "<End>",<Esc>jq22@qkxZZ
41:v/=/d<CR>o}<Esc>qq-i    "<C-Right><Del>": "<End>",<Esc>qx22@qO<C-D>{<Esc>ZZ
40:v?=?d<CR>o}<C-Home>{<CR><Esc>qqI    "<C-Right><Del>": "<End>",<Esc>nq22@qxZZ
39:v?=?d<CR>o}<C-Home>{<CR><Esc>q"ns": "<Home>    "<End>",<Esc>q22@/xZZ

