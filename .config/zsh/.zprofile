browser="qutebrowser"
browser_alt="brave"
editor="emacsclient -c -e -s doom"
editor_alt="code-oss"
file_manager="thunar"
file_manager_alt="pcmanfm"
hypervisor="virt-manager"
hypervisor_alt="virtualbox"
launcher="dm_launcher"
export browser browser_alt
export editor editor_alt
export file_manager file_manager_alt
export hypervisor hypervisor_alt
export launcher

bin="$HOME/bin"
git="$HOME/git"
builds="$HOME/builds"
wallpapers="$HOME/Images/wallpapers"
export bin git builds wallpapers

dwm_config="$XDG_CONFIG_HOME/dwm"
dmenu_config="$XDG_CONFIG_HOME/dmenu"
sway_config="$XDG_CONFIG_HOME/sway"
export dwm_config sway_config

dwm_src="$dwm_config/src"
export dwm_src dmenu_src

scripts="$HOME/scripts"

dm_scripts="$scripts/dm"
py_scripts="$scripts/py"
dwm_scripts="$dwm_config/scripts"
export scripts dm_scripts py_scripts dwm_scripts

export PATH="$bin:$scripts:$dm_scripts:$py_scripts:$dwm_scripts:${PATH}"

export RANGER_LOAD_DEFAULT_RC="FALSE"
export RANGER_DEVICONS_SEPARATOR=" "
