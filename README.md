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

### tmux integration
If you use a terminal multiplexer as tmux you can associate a new bind to run the countdown   
e.g. add ```bind T send-keys '~/.local/bin/countdown' Enter``` in ```~/.tmux.conf```   
start tmux and press ```prefix T```
