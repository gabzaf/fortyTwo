# Minitalk
Welcome to Minitalk, a project that challenges to create a client-server communication system using **signals** in C. This project is an exercise in **interprocess communication** and signal handling in the Unix environment.

## Table of Contents
### 1. Introduction
### 2. Getting Started
### 3. Functionality
### 4. Usage
### 5. Testing

---

## 1. Introduction
Minitalk is a simple client-server program where the server waits for messages from the client and displays them, while the client sends messages to the server. 
The communication between the client and server is achieved using signals, allowing for lightweight and efficient message passing.

## 2. Getting Started
To get started with Minitalk, clone this repository to a local machine.

Navigate to the minitalk directory and compile the project using your preferred compiler.
This will generate two executable files named client and server.

## 3. Functionality
The server program listens for messages from the client program and displays them to the standard output. The client program sends messages to the server, which are then displayed by the server.

## 4. Usage
To use Minitalk, first start the server program in one terminal window:
Then, in another terminal window, start the client program with the server's process ID as an argument.
You can now start sending messages from the client to the server.

## 5. Testing
Testing Minitalk implementation is crucial to ensure its correctness and reliability. Verify the functionality of client-server communication system.

---

To check the requisites of this project, go to subject. Happy coding!

*Note:* On unixProcessInC directory I implemented some functions to better understand signals.
