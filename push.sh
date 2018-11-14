#!/bin/bash

if [ $# == 1 ]; then
	cd "$1"
	echo "Workspace : `pwd`"
	comment=`head README.md -n 3 | tail -n 1`
	echo "Comment : ${comment}"
	git add . && git commit -m "${comment}" && git push
else
	echo -e "Usage : \r\n\t$0 [ folder_name ]"
fi
