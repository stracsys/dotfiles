OPTIONS="Shutdown"
OPTIONS+="\nHibernate"
OPTIONS+="\nSuspend"
OPTIONS+="\nLock"
OPTIONS+="\nLogout"
OPTIONS+="\nReboot"

RET=$(echo -e "$OPTIONS" | dmenu -c -l 10 -h 50 -p "Powermenu::" -npi 3)

case $RET in
   Shutdown)
     systemctl poweroff
     ;;
   Hibernate)
     systemctl hibernate
     ;;
   Suspend)
     systemctl suspend
     ;;
   Lock)
     betterlockscreen -l pixel
     ;;
   Logout)
     dwmc quit
     ;;
   Reboot)
     systemctl reboot
     ;;
  * )
    ;;
esac

