# 📂 fileEmbedder 📂

## 🌟 What I Learned in This Project 🌟

During this project, I learned how to:

- 🧠 Work with binary data in C programming
- 🔄 Convert raw file data to code representations
- 📊 Format binary data as hexadecimal values
- 🔀 Process standard input streams in C
- 📏 Properly format output with consistent spacing and structure
- 🔢 Handle different output formats (C arrays and Assembly)
- 📚 Create a command-line utility with argument parsing

## 📝 What This Program Does 📝

The fileEmbedder program takes any file from standard input and converts its contents into either:
- 📋 C language array declarations or
- 🏗️ Assembly language data section declarations

This is incredibly useful when you need to embed binary files, images, or other assets directly into your code!

## 🚀 How to Use fileEmbedder 🚀

### 💻 Compilation

First, compile the program:

```bash
make
```

### 🛠️ Basic Usage

The program takes data from standard input (stdin) and generates code that embeds that data:

```bash
cat yourfile.bin | ./fileEmbedder identifier_name
```

### 🔍 Usage Options

- 📌 Basic C array format:
  ```bash
  cat yourfile.bin | ./fileEmbedder my_data
  ```

- 🏷️ Assembly format:
  ```bash
  cat yourfile.bin | ./fileEmbedder -a my_data
  ```

- ❓ Help:
  ```bash
  ./fileEmbedder -h
  ```
  or
  ```bash
  ./fileEmbedder --help
  ```

### 📊 Example Output

For C format:
```c
unsigned char my_data[] = {
    0x48, 0x65, 0x6c, 0x6c, 0x6f, 0x20, 0x77, 0x6f, 0x72, 0x6c, 0x64, 0x21, 0x0a
};
```

For Assembly format:
```asm
.section .data
my_data:
    0x48, 0x65, 0x6c, 0x6c, 0x6f, 0x20, 0x77, 0x6f, 0x72, 0x6c, 0x64, 0x21, 0x0a
```

## 📋 Sample Files 📋

The project includes sample files in the `samples/` directory that you can use for testing:

- `test_small.txt`: A small text file for basic testing
- `test_larger.txt`: A larger file with various characters and line breaks

Try them out:
```bash
cat samples/test_small.txt | ./fileEmbedder small_data
cat samples/test_larger.txt | ./fileEmbedder -a large_data
```

## 📈 Use Cases 📈

- 🖼️ Embedding images in compiled programs
- 📜 Including configuration files in your binaries
- 🔐 Embedding encryption keys or certificates
- 🎵 Including sound files in your application
- 📄 Embedding HTML, CSS, or other resource files

## 🔧 Technical Details 🔧

The program reads input one byte at a time and formats each byte as a hexadecimal value. It automatically formats the output with proper line breaks (every 16 bytes) to make the generated code readable.

