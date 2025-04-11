# **📜 get_next_line**

Welcome to **get_next_line**! 🚀  
This project challenges you to implement a function that reads one line at a time from a file descriptor. It’s a great exercise for getting familiar with handling file input and memory management in C.

The goal is to implement **get_next_line()** — a function that reads a line from a file descriptor, one at a time, until it reaches the end of the file.

## 🎯 **Project Overview**

In this project, we focus on:
- Reading data from files in a memory-efficient way.
- Understanding the importance of buffers and handling memory correctly.
- Working with low-level file operations in C.

### **Allowed Functions:**
- `read()`
- `malloc()`
- `free()`

## 🛠️ Usage
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
#include <fcntl.h>
#include <stdio.h>

int main(void)
{
    int fd = open("test.txt", O_RDONLY);
    char *gnl = get_next_line(fd);
    printf("%s\n", gnl);
    free(gnl);
    close(fd);
}
```

