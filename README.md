# 🎮 Connect 4 Game

## 📌 Overview  
This is a **console-based Connect 4 game** built using **C++**, featuring:  
- **Single-player (AI mode)** and **Two-player mode**  
- **Two difficulty levels**: Easy & Hard  
- **Sound effects** for a more interactive experience  
- **Colorful board display** using ANSI escape codes  

## 🎯 How to Play  
1. **Choose game mode**  
   - **1 Player**: Play against AI  
   - **2 Players**: Play against another player  

2. **Select difficulty (if playing vs AI)**  
   - **Easy Mode**: No time limit for moves  
   - **Hard Mode**: You must play within **5 seconds**, or a move will be selected randomly  

3. **Drop your piece**  
   - Choose a column (1-8)  
   - The piece will fall into the lowest available slot  

4. **Win Conditions**  
   - First player to align **4 pieces** in a row (horizontal, vertical, or diagonal) wins  
   - If the board fills up, the game is a draw  

## 🛠️ Technologies Used  
- **C++**  
- **Windows API (`PlaySound`)** for sound effects  
- **ANSI Escape Codes** for colored text  
- **Random AI moves** using `rand()`  
- **User input handling** using `_kbhit()` and `_getch()`  

## 🔊 Sound Effects  
- **`welcome.wav`** → Intro  
- **`drop.wav`** → When a piece is placed  
- **`win.wav`** → Winning sound  
- **`lose.wav`** → Lose/Draw sound  
- **`final.wav`** → Game over  
