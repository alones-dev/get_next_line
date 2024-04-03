# get_next_line
```get_next_line()``` is a function that returns a line read from a file descriptor.

This project is made in C for 42School.

Allowed functions are ```read()```, ```malloc()``` & ```free()```.

## Usage
**1. Clone the repository**
```
git clone https://github.com/alones-dev/get_next_line.git
```
**2. Compile the project**
```
make
```
**3. Enjoy**
```c
#include "ft_printf.h"
#include <fcntl.h>
#include <stdio.h>

int main(void)
{
    int fd = open("test.txt", O_RDONLY);
    printf("%s\n", get_next_line(fd));
    close(fd);
}
```

