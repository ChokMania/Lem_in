grep -r --include \*.c -H "[-&|?:%]$" $@
grep -r --include \*.c -H -e '[^/]\*$' $@
