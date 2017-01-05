failed.out 返回 : 1
success.out 返回 : 0

./success.out && main.out
```
success!
Hello world!
```

./success.out || main.out
```
success!
```

./failed.out && main.out
```
failed!
```

./failed.out || main.out
```
failed!
Hello world!
```
可以根据短路现象来理解
&&理解为与
||理解为或

注 : 
```
echo $?
```
可以获取上一条命令执行的返回值

