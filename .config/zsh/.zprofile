browser="qutebrowser"
browser_alt="brave"
editor="emacsclient -c -e -s doom"
file_manager="thunar"
export browser editor file_manager

builds="$HOME/Builds"
wallpapers="$HOME/Images/Wallpapers"
export builds wallpapers

dwm_config="$XDG_CONFIG_HOME/dwm"
dmenu_config="$XDG_CONFIG_HOME/dmenu"
sway_config="$XDG_CONFIG_HOME/sway"
export dwm_config sway_config

dwm_src="$dwm_config/src"
dmenu_src="$dmenu_src/src"
export dwm_src dmenu_src

scripts="$HOME/Scripts"
dmenu_scripts="$dmenu_config/scripts"
py_scripts="$scripts/py"
dwm_scripts="$dwm_config/scripts"
export scripts dmenu_scripts py_scripts dwm_scripts

export PATH="$scripts:$dmenu_scripts:$py_scripts:$dwm_scripts:${PATH}"
