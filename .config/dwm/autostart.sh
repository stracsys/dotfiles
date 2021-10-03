#!/usr/bin/env bash

function run {
  if ! pgrep -f $1 ;
  then
    $@&
  fi
}
function run_null {
  if ! pgrep -f $1 ;
  then
    ($@ 2> /dev/null)&
  fi
}
function run_xob {
  if ! pgrep -f $1 ;
  then
    ($@ | xob)&
  fi
}

run_null emacs --with-profile doom --daemon=doom
run picom --config "$dwm_config/picom.conf"
run nitrogen --restore
run slstatus
run clipmenud
# run redshift-gtk
run ksuperkey -e 'Super_L=Alt_L|F1'
run_null dunst -conf "$dwm_config/dunstrc"
run_xob "$py_scripts/pulse-volume-watcher.py"
run_xob "$py_scripts/pulse-volume-mic-watcher.py"
run "$scripts/xidle.sh"
