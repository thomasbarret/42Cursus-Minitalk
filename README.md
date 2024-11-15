# 42Cursus - Minitalk

**Minitalk** is a project for the 42Cursus program where you will implement a basic communication system between a client and a server using Unix signals.

---

## Repository Structure

```plaintext
.
├── Makefile                  # Main Makefile for compiling the project
└── src
    ├── function
    │   ├── client.c          # Client program that sends messages to the server
    │   ├── client_bonus.c    # Client bonus with additional functionalities
    │   ├── server.c          # Server program that receives messages
    │   └── server_bonus.c    # Server bonus with additional functionalities
    └── header
        ├── ft_printf         # Custom printf functions
        │   ├── Makefile       # Makefile for ft_printf
        │   ├── ft_printchar.c # Print character
        │   ├── ft_printf.c   # Printf main implementation
        │   ├── ft_printf.h   # Header for ft_printf
        │   ├── ft_printhex.c # Print hexadecimal numbers
        │   ├── ft_printnbr.c # Print integer numbers
        │   ├── ft_printptr.c # Print pointers
        │   ├── ft_printstr.c # Print strings
        │   └── ft_printunbr.c# Print unsigned numbers
        ├── libft              # Custom library functions
        │   ├── Makefile       # Makefile for libft
        │   ├── ft_atoi.c      # Convert string to integer
        │   ├── ft_bzero.c     # Set memory to zero
        │   ├── ft_calloc.c    # Allocate memory and set it to zero
        │   ├── ft_isalnum.c   # Check if character is alphanumeric
        │   ├── ft_isalpha.c   # Check if character is alphabetic
        │   ├── ft_isascii.c   # Check if character is ASCII
        │   ├── ft_isdigit.c   # Check if character is a digit
        │   ├── ft_isprint.c   # Check if character is printable
        │   ├── ft_itoa.c      # Convert integer to string
        │   ├── ft_lstadd_back.c# Add element to end of linked list
        │   ├── ft_lstadd_front.c# Add element to front of linked list
        │   ├── ft_lstclear.c  # Clear linked list
        │   ├── ft_lstdelone.c # Delete one element of linked list
        │   ├── ft_lstiter.c   # Iterate over linked list
        │   ├── ft_lstlast.c   # Get last element of linked list
        │   ├── ft_lstmap.c    # Map function to elements in linked list
        │   ├── ft_lstnew.c    # Create new linked list element
        │   ├── ft_lstsize.c   # Get size of linked list
        │   ├── ft_memchr.c    # Search for byte in memory
        │   ├── ft_memcmp.c    # Compare memory areas
        │   ├── ft_memcpy.c    # Copy memory area
        │   ├── ft_memmove.c   # Move memory area
        │   ├── ft_memset.c    # Set memory to value
        │   ├── ft_putchar_fd.c# Write character to file descriptor
        │   ├── ft_putendl_fd.c# Write string with newline to file descriptor
        │   ├── ft_putnbr_fd.c# Write number to file descriptor
        │   ├── ft_putstr_fd.c# Write string to file descriptor
        │   ├── ft_split.c     # Split string into array of substrings
        │   ├── ft_strchr.c    # Find first occurrence of character in string
        │   ├── ft_strdup.c    # Duplicate string
        │   ├── ft_striteri.c  # Apply function to each character of string
        │   ├── ft_strjoin.c   # Concatenate two strings
        │   ├── ft_strlcat.c   # Concatenate strings with limit
        │   ├── ft_strlcpy.c   # Copy string with limit
        │   ├── ft_strlen.c    # Get length of string
        │   ├── ft_strmapi.c   # Apply function to each character of string and return new string
        │   ├── ft_strncmp.c   # Compare strings up to n characters
        │   ├── ft_strnstr.c   # Find substring within string
        │   ├── ft_strrchr.c   # Find last occurrence of character in string
        │   ├── ft_strtrim.c   # Trim leading and trailing spaces from string
        │   ├── ft_substr.c    # Extract substring from string
        │   ├── ft_tolower.c   # Convert character to lowercase
        │   ├── ft_toupper.c   # Convert character to uppercase
        │   └── libft.h        # Header for libft functions
        └── minitalk.h          # Header for Minitalk project
```

---

## Overview

In this project, you will create a communication system where the **client** sends messages to the **server** using **Unix signals**. The server listens for signals sent by the client and responds accordingly.

The project consists of two parts:
1. **Client**: Sends messages to the server using signals.
2. **Server**: Receives signals from the client and decodes the messages.

The **bonus part** of the project introduces additional functionalities and improvements such as handling multiple clients.

---

## How to Use

1. **Compilation**  
   To compile the project, run `make` in the main directory:
   ```bash
   make
   ```

2. **Starting the Server**  
   You can run the server by executing the following command:
   ```bash
   ./server
   ```

3. **Starting the Client**  
   To send a message to the server, run the client with the server's process ID (PID):
   ```bash
   ./client <server_pid> "message"
   ```

4. **Bonus Version**  
   If you wish to use the bonus features, run the client or server with the `bonus` flag:
   ```bash
   ./client_bonus <server_pid> "message"
   ./server_bonus
   ```

---

## Example

### Server (Running)
```bash
./server
```

### Client (Sending a Message)
```bash
./client 12345 "Hello, Server!"
```

**Output on Server Side**:
```
Received message: "Hello, Server!"
```