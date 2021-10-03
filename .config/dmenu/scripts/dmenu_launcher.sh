#!/usr/bin/env bash

# j4-dmenu-desktop --dmenu=" \
#   ( \
#   cat ; \
#   (stest -flx $(echo $PATH | tr : ' ') | sort -u) \
#   ) | \
#   dmenu -c -l 10 -h 50 -n \
#   "
# j4-dmenu-desktop --dmenu="(stest -flx $(echo $PATH | tr : ' ') ; cat | sort -u) | dmenu -c -l 10 -h 50"

dmenu_run -c -l 10 -h 50
