#### Target
```
双进程守护
```

#### Usage
```
SYSTEMD_PID=`pidof systemd` ./main
```

#### How to kill
```
# kill the parent is easier
# child use polling the detect the state of parent
ps aux | grep ./main | awk '{print $2}' | head -n 1 | xargs kill -9

# kill the child is harder
# parent will recv signal SIGCHLD that ensure child process will be generated quickly
ps aux | grep ./main | awk '{print $2}' | head -n 2 | tail -n 1 | xargs kill -9

# kill both child and parent
ps aux | grep ./main | awk '{print $2}' | xargs kill -9
```
