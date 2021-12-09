<h1 align="center">Simple Shell</h1>
</div>

<p align="center">
By Diego Monfort and Guzmán Caraballo
</p>
<p align="center">
Deadline: Wednesday 8th, December 2021
</p>

### Description
This is a project made for Holberton School. It consists in a custom simple Unix shell made from scratch.  
  
The shell is the interface to the operating system. It is a command interpreter; which means that it takes an input passes it to the operating system. 
Then, it displays the results of the operation on the screen.  
  
This version of the Unix shell is quite simple, but it is very efficient in preventing any memory leak.

## Requierments

- Allowed editors: vi, vim, emacs
- All your files will be compiled on Ubuntu 20.04 LTS using gcc, using the options -Wall -Werror -Wextra -pedantic -std=gnu89
- All your files should end with a new line
- A README.md file, at the root of the folder of the project is mandatory
- Your code should use the Betty style. It will be checked using betty-style.pl and betty-doc.pl
- Your shell should not have any memory leaks
- No more than 5 functions per file
- All your header files should be include guarded
- Use system calls only when you need to

## List of allowed functions and system calls

- access
- chdir
- close
- closedir
- execve
- exit
- _exit
- fflush
- fork
- free
- getcwd
- getline
- getpid
- isatty
- kill
- malloc
- open
- opendir
- perror
- read
- readdir
- signal
- stat
- lstat
- fstat
- strtok
- wait
- waitpid
- wait3
- wait 4
- write

## Tasks

| Task | Description |   |
| --- | --- | --- |
| 1 | Write a UNIX command line interpreter |
| 2 | Handle command lines with arguments |
| 3 | Handle the PATH |
| 4 | Implement the exit built-in, that exits the shell |
| 5 | Implement the env built-in, that prints the current environment |
| 6 | Write a blog [CLICK HERE](https://www.linkedin.com/pulse/what-happens-when-we-type-ls-l-c-shell-diego-monfort/?trackingId=INZ9Kw1pQEauSncT%2BMBxtQ%3D%3D)





### Use and examples
#### To install and compile
~~~~
$ git clone https://github.com/asadoconfritas/simple_shell.git
$ cd simple_shell/
$ gcc -Wall -Werror -Wextra -pedantic -Wno-format *.c -o shell
~~~~

#### Examples
~~~~
$ ls
(lists files and directories in the current repository)
~~~~

~~~~
$ exit
(exits the shell)
~~~~
