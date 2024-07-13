<img src="zimages/cpp_logo.png" width="75" height="75" />&nbsp;&nbsp;<img src="zimages/python_logo.png" width="75" height="75" />&nbsp;&nbsp;<img src="zimages/c_logo.png" width="75" height="75" />&nbsp;&nbsp;<img src="zimages/kotlin_logo.png" width="75" height="75" />

# Library Challenge 2024

Welcome to the Library Challenge 2024! This repository contains libraries and examples for you to create unique and interesting software using supported programming languages: C, C++, Python, and Kotlin.

## DEVPOST

Join the devpost for the competition <a href="https://libcomp.devpost.com/">here</a>!

## Table of Contents

1. [Introduction](#introduction)
2. [Installation Instructions](#installation-instructions)
   - [Windows](#windows)
   - [Ubuntu](#ubuntu)
   - [macOS](#macos)
3. [Compiling Examples](#compiling-examples)
4. [Usage](#usage)
5. [Contributing](#contributing)
6. [License](#license)
7. [Additional Resources](#additional-resources)

## Introduction

The Library Challenge 2024 is designed to inspire creativity and innovation by encouraging participants to use the provided libraries in unique and interesting ways. Whether you're a beginner or an experienced developer, this challenge is an excellent opportunity to showcase your skills and learn new ones.

## Installation Instructions

### Windows

To install the required programming languages on Windows, follow the instructions in this [video tutorial](https://youtu.be/5vYDs8Cuh88).

### Ubuntu

Open your terminal and run the following commands:

- **C++:**
  ```bash
  sudo apt-get install g++
  ```
- **C:**
  ```bash
  sudo apt-get install gcc
  ```
- **Python:**
  ```bash
  sudo apt-get install python3
  ```
- **Kotlin:**
  ```bash
  sudo snap install --classic kotlin
  ```

### macOS

To install the required programming languages on macOS, follow the instructions in this [video tutorial](https://youtu.be/0z-fCNNqfEg).

## Compiling Examples

To learn how to compile the library examples provided in this repository, watch this [compilation tutorial](https://youtu.be/Kn4JIKQeOOU).  

### C/C++ Example

To compile a C or C++ example, use the following commands:

```bash
gcc -o example example.c    # For C
g++ -o example example.cpp  # For C++
./example
```

### Python Example

Python scripts do not require compilation. You can run a Python script directly using:

```bash
python3 example.py
```

### Kotlin Example

__Note__: for Kotlin, it is highly recommended to use __IntelliJ Idea (Community Edition)__ as it allows you to configure a project's build settings and run it without compiling directly. It's also developed & maintained by JetBrains, the company behind the language! See <a href="https://kotlinlang.org/docs/kotlin-ide.html#intellij-idea">this link</a> for more IDE recommendations.  

To compile and run a Kotlin example, use the following commands:

```bash
kotlinc example.kt -include-runtime -d example.jar
java -jar example.jar
```

## Usage

### C/C++ Usage

Include the necessary headers and link the provided libraries in your C/C++ projects. For example:

```c
#include "library.h"

int main() {
    // Your code here
    return 0;
}
```

### Python Usage

Import the provided modules in your Python scripts. For example:

```python
import library

# Your code here
```

### Kotlin Usage

Please see [this section](#kotlin-example) for an important note.

Include the necessary packages and use the provided classes and functions in your Kotlin projects. For example:

```kotlin
import library.*

fun main() {
    // Your code here
}
```

## License

This project is licensed under the MIT License. See the [LICENSE](LICENSE) file for more details.

## Additional Resources

- [Library Challenge Intro Presentation]()

For any questions or issues, feel free to open an issue in this repository. Enjoy the challenge and happy coding!

\- DNS
