
![IMG_3599](https://github.com/user-attachments/assets/2ea8a901-55b0-41d2-b5b0-b0fadb41b8fb)

# Enigma Machine Simulator

This is a command-line simulator for the historic Enigma machine used in cryptography during World War II. The simulator allows for encryption and decryption of text by simulating the exact behavior of an Enigma machine with adjustable rotor settings, ring settings, and plugboard configurations.

## Features

- **Rotor Selection**: Supports multiple rotors with customizable initial positions.
- **Ring Settings**: Adjust ring settings to offset rotor wiring.
- **Plugboard Configuration**: Swap pairs of letters to customize encryption further.
- **Reflector**: Built-in reflector for character swapping, as in real Enigma machines.
- **Encryption & Decryption**: Encrypt and decrypt text directly from the command line.

## Requirements

- C++ compiler supporting C++11 or higher.
- CMake for build automation.

## Usage

The program can be executed from the command line with options to encrypt or decrypt a message, adjust rotor positions, set ring configurations, and specify plugboard connections.

### Basic Command

```bash
./enigma <message> <operation> --rotors <rotor_positions> --ring <ring_settings> --plugboard <plug_connections>
```

### Parameters

- `<message>`: The text you want to encrypt or decrypt. Spaces will be replaced with hyphens (`-`), and all characters will be converted to uppercase.
- `<operation>`: Specify `--encrypt` to encrypt or `--decrypt` to decrypt the message.
- `--rotors <rotor_positions>`: Initial positions for the rotors in the format `0,0,0`. Each number represents the starting position of each rotor.
- `--ring <ring_settings>`: Ring settings for each rotor in the format `0,0,0`. Adjusts the internal wiring offset for each rotor.
- `--plugboard <plug_connections>`: Letter pairs for the plugboard, such as `AB,CD`. Each pair swaps those two letters before and after the rotor processing.

### Example Commands

1. **Encrypt a message**:
   ```bash
   ./enigma HELLO --encrypt --rotors 1,2,3 --ring 0,0,0 --plugboard AB,CD

2. **Decrypt a message**:
    ```bash
    ./enigma OZDQB --decrypt --rotors 1,2,3 --ring 0,0,0 --plugboard AB,CD
    ```

## Installation and Setup
### Build with CMake

1. **Clone the repository**:
    ```bash
    git clone <repository_url>
    cd enigma-machine-simulator
    ```

2. **Build the project**:
   ```bash
   mkdir build
   cd build
   cmake ..
   make
   ```
3. **Run the program**:
   ```bash
   ./enigma <message> <operation> --rotors <rotor_positions> --ring <ring_settings> --plugboard <plug_connections>
   ```

## How the Enigma Machine Works

The Enigma machine encrypts text through a series of substitutions and permutations:

1. **Plugboard**: First, each letter is swapped with a partner as configured in the plugboard.
2. **Rotors**: The letter passes through a series of rotors with internal wiring that maps each input letter to an output letter. Each rotor advances with each keystroke, changing the encryption pattern.
3. **Reflector**: The reflector maps each letter to another, sending the signal back through the rotors in the reverse order.
4. **Reverse Rotor Pass**: The signal goes back through the rotors in the opposite direction.
5. **Plugboard**: Finally, the plugboard performs another letter swap before outputting the encrypted letter.

Each setting (rotor position, ring settings, and plugboard configuration) changes the encryption, making Enigma's code highly challenging to break without knowing the machine's initial settings.

## Customization Options

- **Rotors**: The program can be extended with additional rotors by modifying the `Rotor` class in the code.
- **Reflector**: Different reflector configurations can be added for additional complexity.
- **Plugboard**: Customize letter pairs as per user preference.

## Contributing

Contributions are welcome! If you'd like to contribute, please fork the repository and submit a pull request with your changes.

## License

This project is licensed under the MIT License. See the LICENSE file for details.

## Acknowledgments

This project is inspired by the real Enigma machine used during World War II. For more information on the Enigma machine and its history, please refer to [Wikipedia](https://en.wikipedia.org/wiki/Enigma_machine).
