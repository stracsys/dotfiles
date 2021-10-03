#!/bin/sh

backlight="$(light -G | cut -c1,2)"
#backlight="$(xbacklight --get)"
printf "$backlight"
