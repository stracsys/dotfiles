RET=$(echo -e "Full\nClipboard_Full" | dmenu -p "Select screenshot type:")

case $RET in
  Full)
    flameshot full -p ~/Images/Screenshots -d 5000
    ;;
  Clipboard_Full)
    flameshot full -c -p ~/Images/Screenshots
    ;;
  * );;
esac

