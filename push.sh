#!/bin/bash

while :
do
 clear
 echo " -----------------------------------------------------------"
 echo "| 1.Fast-Git-Push |\n
       | 2.Exit |" | column -t
 echo " -----------------------------------------------------------\n"
 read INPUT
 case $INPUT in
	1)
		git add *
		git status
		if [ $? -eq 0 ];then
			echo "Write the commit message :"
			read MSG
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
		fi;;
	2)
		break ;;
	*)
		echo "\n$INPUT is not a valid option";;
 esac
 sleep 1.5
done
clear