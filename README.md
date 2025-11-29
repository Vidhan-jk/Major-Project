🕒 Universal Time Clock (UTC) — C Programming Project
CSEG1032 – Major Project (UPES)
Student: Vidhan Jyoti Kahar
📌 Project Overview

The Universal Time Clock (UTC) project is a modular C program that displays the current Coordinated Universal Time (UTC) and accurately converts between Local Time (Indian Standard Time – IST) and UTC.
It demonstrates modular programming, robust input handling, and use of the C Standard Library (time.h).

The program includes:

Display of current system UTC time

Conversion IST → UTC

Conversion UTC → IST

Safe input handling using fgets(), strtol(), and sscanf()

Error-free execution with full time validation

Clean modular structure using .c and .h files

Full documentation (flowchart, algorithm, report)

🧱 Features
✔ Show Current UTC Time

Uses time() + gmtime() from <time.h>.

✔ Convert IST → UTC

Subtracts 5 hours 30 minutes and handles previous-day transitions.

✔ Convert UTC → IST

Adds 5 hours 30 minutes and handles next-day transitions.

✔ Robust Input Validation

Ensures only correct HH MM SS formats are accepted.

✔ Safe Input System

Prevents crashes on:

Letters

Symbols

Extra characters

Out-of-range values

Empty input

✔ Modular Architecture

main.c → UI + safe input

utc.c → logic

utc.h → declarations

📂 Folder Structure
/
|-- src/
|    |-- main.c
|    |-- utc.c
|
|-- include/
|    |-- utc.h
|
|-- docs/
|    |-- ProjectReport.pdf
|    |-- flowchart.png
|    |-- algorithm.png
|
|-- assets/
|    |-- worldmap_utc.png
|    |-- sample_output.png
|
|-- sample_input.txt
|-- README.md


This matches the mandatory UPES project structure.

🛠️ How to Compile

Open terminal in the project folder and run:

gcc src/main.c src/utc.c -Iinclude -o utc_clock

▶️ How to Run
Linux / macOS:
./utc_clock

Windows (MinGW / CodeBlocks terminal):
utc_clock.exe

🧪 Example Program Run
======= UNIVERSAL TIME CLOCK (UTC) =======
1. Show Current System Time in UTC
2. Convert Local Time (IST) to UTC
3. Convert UTC to Local Time (IST)
4. Exit
-----------------------------------------
Enter your choice: 2
Enter Local Time (HH MM SS): 14 20 00
UTC Time: 08:50:00

🧪 Testing Summary

All features were tested:

✔ Valid conversions (IST ↔ UTC)

✔ Boundary testing (00:00:00, 23:59:59)

✔ Wrap-around behavior

✔ Invalid input handling

✔ No crashes, no undefined behavior

Complete testing details are inside:
📄 docs/ProjectReport.pdf

📘 Documentation

Full Report → docs/ProjectReport.pdf

Flowchart → docs/flowchart.png

Algorithm → docs/algorithm.png

🌍 Concepts Used

Modular Programming

Time Manipulation (time.h, gmtime())

Error Handling

Boundary Conditions

Input Validation

Command-Line Compilation

Pointers & Multi-file C Project

🚀 Future Enhancements

Support for multiple time zones

DST (Daylight Saving Time) support

GUI version using Qt/GTK

Realtime world map clock

Logging & file export

Mobile or Web version

👨‍💻 Author

Vidhan Jyoti Kahar
B.Tech CSE — UPES
C Programming Major Project

📜 License

This project is open for academic and educational use.
