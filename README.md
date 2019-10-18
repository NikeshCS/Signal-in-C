# Signal-in-C
Utilizing Signal in C, passing signal child - parent

This program send a signal from parent process and the child process receives this signal.
The program will execute with a SIGKILL trigger
This program utilizes the GNU Scientific Library for the random number generator

These is a child handler:
- Prints out the number of the signal received, as well as a message that the child received it.

Parent handler:
- Prints the value of the signal received, as well as a message saying that the parent received it.
- SIGKILL -> Kills the signal to the child.
- Waits for child to execute


