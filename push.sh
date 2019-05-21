#!/bin/bash

git add -all
git status
if [ $? -eq 0 ];then
	read -p "Commit : " MSG
	git commit -m "$MSG"
	if [ $? -eq 0 ];then
		git push
		if [ $? -eq 0 ];then
			echo "\n\nSUCCESS"
		else
			echo "\n\nERROR : You can't do that\n\n"
			echo "Press Enter to continue"
			read INPUT
		fi
	else
		echo "\n\nERROR : You can't do that\n\n"
		echo "Press Enter to continue"
		read INPUT
	fi
else
	echo "\n\nERROR : You can't do that\n\n"
	echo "Press Enter to continue"
	read INPUT
fi;
clear