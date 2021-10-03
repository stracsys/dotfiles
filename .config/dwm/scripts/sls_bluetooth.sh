#
# A script to display bluetooth status in slsstatus
#

icon=""
device_name=""

# Checks if bluetooth controller is powered on
power_on() {
  if bluetoothctl show | grep -q "Powered: yes"; then
    icon=""
    return 0
  else
    icon=""
    return 1
  fi
}

# Checks if a device is connected
device_connected() {
  device_info=$(bluetoothctl info "$1")
  if echo "$device_info" | grep -q "Connected: yes"; then
    device_name=" $(bluetoothctl info $1 | grep "Name" | cut -d " " -f2)"
    return 0
  else
    device_name=""
    return 1
  fi
}

# if power_on; then
#   if device_connected; then
#     output="$icon $device_name"
#   else
#     output="$icon"
#   fi
# fi

power_on
device_connected

output+="$icon$device_name"
printf "$output"
