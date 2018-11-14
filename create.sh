#!/bin/bash

if [ "$#" != 1 ]; then
	echo -e "Usage : \r\n\t$0 \"Description\""
	exit 1
fi

get_max_number(){
	return `ls | grep '[0-9]' | sort -n | tail -n 1`
}

get_max_number
max_number=$?

echo "当前最大文件夹序号为 : $max_number"
((new_folder_name=$max_number+1))
echo "新文件夹名 : " $new_folder_name
cp -r ./template $new_folder_name
get_max_number
max_number=$?
echo "新文件夹创建成功 , 当前最大序号为 : " $max_number
sed -i "s/__DESCRIPTION__/${1}/g" ./$max_number/README.md
