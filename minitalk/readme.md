# Minitalk Project

Minitalk is a simple project where communication between a client and a server is achieved through signals. The client sends data bit by bit, and the server decodes and prints the received characters. This project demonstrates how to use Unix signals for inter-process communication in a practical and reliable way.

## Usage

1. **Compile the project**:\
   Use the following command to compile both the client and server:

   ```bash
   make
   ```

2. **Start the server**:\
   In one terminal, run the server with the following command:

   ```bash
   ./server
   ```

   The server will now be listening for signals.

3. **Start the client**:\
   In another terminal, run the client by providing the server's PID (Process ID) and the message you want to send:

   ```bash
   ./client <server_pid> "Your message"
   ```

   The client will encode the message as bits and send it to the server.

4. **Server Output**:\
   The server will decode the received message and print it to the terminal.

## Project Overview

In this project, the client sends a string of characters to the server using signals. Each character is transmitted as a sequence of bits, with each bit represented by a signal. The server listens for these signals, decodes them into characters, and prints them.

### Key Features:

- **Signal-based communication**: Uses `SIGUSR1` and `SIGUSR2` signals to represent binary data.
- **Character encoding**: Each character is encoded into 8 bits, and sent one bit at a time.
- **Message handling**: The server decodes the received signals into meaningful characters and prints the result.

## Approach

### 1. **Signal Transmission**

The client encodes each character into its binary form and sends each bit one by one using `SIGUSR1` (for bit `0`) and `SIGUSR2` (for bit `1`). To ensure data is transmitted correctly, I used `usleep` to space out the signals and avoid collisions.

### 2. **Signal Reception and Decoding**

The server listens for the incoming signals and decodes them. Each signal corresponds to one bit. Once all 8 bits of a character are received, the server assembles them and prints the decoded character.

### 3. **Signal Collision Fix: Handshake Protocol**

One of the major challenges was preventing signal collisions. To solve this, I implemented a manual handshake protocol. This protocol ensures that signals are received without interference, preventing data loss or incorrect decoding. By synchronizing both the client and server, the handshake ensures a smooth and reliable communication process.

### 4. **Handling Multiple Messages**

The client can send multiple messages, and the server correctly handles them, ensuring that each character is decoded and displayed in sequence.

## Conclusion

This project was a great exercise in understanding Unix signals and inter-process communication. It taught me how to handle low-level details like signal handling and synchronization. The manual handshake protocol was essential in ensuring reliable communication between the client and server. Through this project, I learned to approach problem-solving methodically and to ensure that communication is robust even in a noisy environment.


