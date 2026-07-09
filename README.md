# 🎵 MP3 Tag Reader & Editor

A command-line based **MP3 Tag Reader and Editor** developed in C that allows users to view and edit MP3 metadata such as title, artist, album, year, comment, and genre. The project demonstrates strong fundamentals in file handling, structures, and binary data processing.

---

## 📋 Table of Contents

- [Overview](#overview)
- [Features](#features)
- [Technologies Used](#technologies-used)
- [Project Structure](#project-structure)
- [Getting Started](#getting-started)
- [Usage](#usage)
- [How It Works](#how-it-works)
- [Challenges & Learnings](#challenges--learnings)
- [Future Enhancements](#future-enhancements)
- [Author](#author)

---

## 📖 Overview

The **MP3 Tag Reader & Editor** is a CLI tool that reads and modifies **ID3 metadata tags** embedded within MP3 files. It supports multiple ID3 tag versions (ID3v1, ID3v1.1, ID3v2.2, ID3v2.3) and allows users to view or update fields like title, artist, album, year, comment, and genre without corrupting the underlying audio data.

---

## ✨ Features

- 📖 **View Metadata** — Display MP3 tag information (title, artist, album, year, comment, genre)
- ✏️ **Edit Metadata** — Update specific tag fields via command-line options
- 🎚️ **Multi-Version Support** — Handles ID3v1, ID3v1.1, ID3v2.2, and ID3v2.3 tag formats
- 🛡️ **Safe Editing** — Preserves audio data while modifying only the required tag frames
- ⚠️ **Error Handling** — Detects and reports invalid or corrupted MP3 files and missing tags

---

## 🛠️ Technologies Used

- **Language:** Advanced C
- **Concepts:** Data Structures & Algorithms, Structures, Command-Line Argument Parsing
- **Networking (extended scope):** Linux Kernel System Calls, Socket Programming (TCP Sockets), Network Daemons in Linux
- **File Format:** MP3 / ID3 Tag Standard

---

## 📂 Project Structure

```
MP3TagReader/
├── src/
│   ├── main.c
│   ├── id3_reader.c
│   ├── id3_editor.c
│   └── id3_tag.h
├── samples/
│   └── sample.mp3
├── Makefile
└── README.md
```

> Note: Update this structure to match your actual repository layout.

---

## 🚀 Getting Started

### Prerequisites
- GCC compiler installed
- Linux/Unix terminal (or WSL/Git Bash on Windows)

### Installation

```bash
# Clone the repository
git clone https://github.com/vibinmichael18-qq/MP3TagReader.git

# Navigate into the project directory
cd MP3TagReader

# Build the project using Make
make

# Run the executable
./mp3tagreader
```

---

## 💻 Usage

**View all tags of an MP3 file:**
```bash
./mp3tagreader -v song.mp3
```

**Edit a specific tag field:**
```bash
./mp3tagreader -e -t "New Title" song.mp3
./mp3tagreader -e -a "New Artist" song.mp3
```

**Available options:**
| Option | Description |
|--------|-------------|
| `-v` | View all metadata tags |
| `-e` | Edit mode |
| `-t` | Set/update title |
| `-a` | Set/update artist |
| `-A` | Set/update album |
| `-y` | Set/update year |
| `-c` | Set/update comment |
| `-g` | Set/update genre |

> Adjust these options to match your actual CLI argument handling.

---

## ⚙️ How It Works

1. **Reading Tags**
   - The program opens the MP3 file in binary mode and checks for the presence of ID3 headers (v1 or v2).
   - Based on the detected version, it parses fixed-size (ID3v1) or variable-length frame-based (ID3v2) tag structures.

2. **Editing Tags**
   - The relevant tag frame is located and updated with new data.
   - Care is taken to preserve the surrounding audio data and unaffected metadata frames.

---

## 🧩 Challenges & Learnings

- **Multi-Version Tag Parsing:** Understood the ID3 tag structure and implemented version-specific parsing logic for ID3v1, ID3v1.1, ID3v2.2, and ID3v2.3.
- **Binary File Handling:** Used `fread()` and `fseek()` along with careful frame-size calculations to read variable-length ID3v2 frames.
- **Safe Metadata Editing:** Modified only the required tag frames to avoid corrupting the audio data.
- **Robust Error Handling:** Implemented validation to handle invalid or corrupted MP3 files and missing ID3 tags gracefully.
- **Debugging Skills:** Strengthened binary data parsing and debugging skills by identifying and fixing logical errors throughout development.

---

## 🔮 Future Enhancements

- Add support for ID3v2.4 tag version
- Implement a GUI for easier tag viewing/editing
- Add batch processing for multiple MP3 files
- Support album art (cover image) extraction and embedding

---

## 👤 Author

**S Vibin Michael**
- 📧 Email: [vibinmichael18@gmail.com](mailto:vibinmichael18@gmail.com)
- 💼 LinkedIn: [vibin-michael](https://www.linkedin.com/in/vibin-michael-46b4b7316)
- 🐙 GitHub: [vibinmichael18-qq](https://github.com/vibinmichael18-qq)

---

<p align="center"><i>⭐ If you found this project useful, consider giving it a star!</i></p>
