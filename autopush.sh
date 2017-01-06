#!/bin/bash

if [ $# == 1 ]; then
	git add . && git commit -m "$1" && git push
else
	echo -e "Usage : \r\n\t$0 \"Init commit\""
fi
