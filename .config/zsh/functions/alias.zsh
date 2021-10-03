touchscreen() {
  xinput -set-prop "Wacom HID 481C Finger" "Device Enabled" $1
}

sleepsy() {
  (sleep $1 && systemctl poweroff) &
}

bk() {
  cp -r $1 $1.bak
}
