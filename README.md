# minitalk
Small data exchange program using UNIX signals.

/*
** Minitalk - A simple client-server communication program using UNIX signals
**
** The program implements a basic communication protocol where:
** - Server initializes and displays its PID
** - Client sends messages to server using SIGUSR1 and SIGUSR2 signals
** - SIGUSR1 represents binary 1
** - SIGUSR2 represents binary 0
** - Each character is sent bit by bit (8 bits)
**
** Usage:
** 1. Start server: ./server
** 2. Note server's PID
** 3. Send message: ./client <server_pid> "message"
*/