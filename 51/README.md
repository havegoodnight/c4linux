目标
```
字符串搜索 (KMP)
```
缺陷
```
由于读取文件使用了 1024 字节的缓冲区 , 而且比较的时候的单位也是这个缓冲区
因此可能会造成这样的BUG , 当需要检索的模式字符串跨越了缓冲区的时候 , 就不能正确地统计出现的次数
```