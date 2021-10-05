# Enable Powerlevel10k instant prompt. Should stay close to the top of ~/.zshrc.
# Initialization code that may require console input (password prompts, [y/n]
# confirmations, etc.) must go above this block; everything else may go below.
if [[ -r "${XDG_CACHE_HOME:-$HOME/.cache}/p10k-instant-prompt-${(%):-%n}.zsh" ]]; then
  source "${XDG_CACHE_HOME:-$HOME/.cache}/p10k-instant-prompt-${(%):-%n}.zsh"
fi

###### Configuration ######
HISTFILE="$XDG_CACHE_HOME/.zsh_history"
HISTSIZE=1000
SAVEHIST=10000
bindkey -v
bindkey '^R' history-incremental-search-backward

# Completion
autoload -Uz compinit
compinit
zstyle :compinstall filename "$ZDOTDIR/.zshrc"
zstyle ':completion:*' menu select

# autoload -Uz promptinit
# promptinit
###########################

##### Source file ######
# Add autosuggestions and syntax-hightlighting
source '/usr/share/zsh/plugins/zsh-autosuggestions/zsh-autosuggestions.plugin.zsh'
source '/usr/share/zsh/plugins/zsh-syntax-highlighting/zsh-syntax-highlighting.zsh'

# Add key 
source "$ZDOTDIR/keys.zsh"

# Functions
source "$ZDOTDIR/functions/alias.zsh"
source "$ZDOTDIR/functions/title.zsh"

# Alias
source "$ZDOTDIR/alias/alias.zsh"
source "$ZDOTDIR/alias/common-aliases.zsh"
source "$ZDOTDIR/alias/gitaliases.zsh"

# Prompt #
source "$HOME/Git/powerlevel10k/powerlevel10k.zsh-theme"
# To customize prompt, run `p10k configure` or edit ~/.p10k.zsh.
[[ ! -f ~/.p10k.zsh ]] || source ~/.p10k.zsh
########################

###### PATH #####
export PATH="$XDG_CONFIG_HOME/doom-emacs/bin:$HOME/.cargo/bin:${PATH}"
#################

###### Execute #####
# nerdfetch.sh
pfetch.sh
colorblocks.sh
####################

# Vterm emacs
# vterm_printf(){
#     if [ -n "$TMUX" ] && ([ "${TERM%%-*}" = "tmux" ] || [ "${TERM%%-*}" = "screen" ] ); then
#         # Tell tmux to pass the escape sequences through
#         printf "\ePtmux;\e\e]%s\007\e\\" "$1"
#     elif [ "${TERM%%-*}" = "screen" ]; then
#         # GNU screen (screen, screen-256color, screen-256color-bce)
#         printf "\eP\e]%s\007\e\\" "$1"
#     else
#         printf "\e]%s\e\\" "$1"
#     fi
# }
