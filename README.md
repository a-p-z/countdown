# countdown
Configurable countdown timer   
(requires curses library)

### Compilation
```sh
$ gcc -Wall -ansi -pedantic countdown.c symbols.c -o countdown -lcurses
````
### How it works
1. run ```$ ./countdown``` 
2. set the time (e.g. 90m)
3. press ENTER to start

![settings](/images/settings.png?raw=true "Settings")   
![countdown](/images/countdown.png?raw=true "Countdown")
