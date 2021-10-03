OPTIONS="Tile"
OPTIONS+="\nMonocle"
OPTIONS+="\nCenteredMaster\nCenteredFloatingMaster"
OPTIONS+="\nBstack\nBstackHoriz"
OPTIONS+="\nDeckDouble"
OPTIONS+="\nSpiral\nDwindle"
OPTIONS+="\nFloating"

RET=$(echo -e "$OPTIONS" | dmenu -c -l 10 -h 50 -p "Layout::")

case $RET in
  # )
  #   dwmc setlayoutex 0
  #   ;;
  Tile)
    dwmc setlayoutex 0
    ;;
  Monocle)
    dwmc setlayoutex 1
    ;;
  CenteredMaster)
    dwmc setlayoutex 2
    ;;
  CenteredFloatingMaster)
    dwmc setlayoutex 3
    ;;
  Bstack)
    dwmc setlayoutex 4
    ;;
  BstackHoriz)
    dwmc setlayoutex 5
    ;;
  DeckDouble)
    dwmc setlayoutex 6
    ;;
  Spiral)
    dwmc setlayoutex 7
    ;;
  Dwindle)
    dwmc setlayoutex 8
    ;;
  Floating)
    dwmc setlayoutex 9
    ;;
  * )
    # dwmc setlayoutex 2
    ;;
esac

