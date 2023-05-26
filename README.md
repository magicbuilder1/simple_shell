# 0x16. C - Simple Shell Project

## What is this project about ?



## How does the Simple Shell work ?

0. To use the shell you execute the binary file <./simple_shell> and then,
1. The program prints a prompt, then ask and wait for the user input
2. Then reads the user input and see if the entry is a valid command. If that is the case, the command is executed otherwise, an error message is printed.
3. The prompt is then printed again and the whole cycle recommence, until the program is exited or killed using a signal.
4. Apart from the commoun inbuilt commands such as <ls> <pwd> <rm> the program is also
5. You can leave the program with the <exit> command or using the Ctrl + D key stroke


## Tools

- OS : Ubuntu 20.04.6 LTS on Windows (WLS_2)
- Code Editor : neovim v0.9.0
- Compiler : gcc v9.4.0
- Flags : -Wall -Werror -Wextra -pedantic std=gnu89
'######::'##::::'##:'########:'##:::::::'##:::::::: '##... ##: ##:::: ##: ##.....:: ##::::::: ##:::::::: ##:::..:: ##:::: ##: ##::::::: ##::::::: ##:::::::: . ######:: #########: ######::: ##::::::: ##:::::::: :..... ##: ##.... ##: ##...:::: ##::::::: ##:::::::: '##::: ##: ##:::: ##: ##::::::: ##::::::: ##:::::::: . ######:: ##:::: ##: ########: ########: ########:: :......:::..:::::..::........::........::........::: :................SIMPLE SHELL......................: :'######::::::'###::::'########:'########::'######:: '##... ##::::'## ##:::... ##..:: ##.....::'##... ##: ##:::..::::'##:. ##::::: ##:::: ##::::::: ##:::..:: ##::'####:'##:::. ##:::: ##:::: ######:::. ######:: ##::: ##:: #########:::: ##:::: ##...:::::..... ##: ##::: ##:: ##.... ##:::: ##:::: ##:::::::'##::: ##: . ######::: ##:::: ##:::: ##:::: ########:. ######:: :......::::..:::::..:::::..:::::........:::......:::
