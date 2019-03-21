#/bin/bash
dir="curve$1"
file="$dir_frame"
rm $dir/*
mv $file* $dir/
convert -delay 10 -loop 0 $dir/*.png $dir.gif

