# Linked List 실습

## 컴파일 및 실행 방법

### Linux

1. **빌드 후 실행**
   ```bash
   g++ -std=c++17 -O2 main.cpp answer.cpp -o run && ./run
   ```

### Windows

1. **명령 프롬프트 (CMD)**

   ```cmd
   g++ -std=c++17 -O2 main.cpp answer.cpp -o run.exe
   run.exe
   ```

2. **PowerShell**
   ```powershell
   g++ -std=c++17 -O2 main.cpp answer.cpp -o run.exe; .\run.exe
   ```

### macOS

1. **Clang 컴파일러 사용**

   ```bash
   clang++ -std=c++17 -O2 main.cpp answer.cpp -o run && ./run
   ```

2. **Homebrew GCC 사용**

   ```bash
   g++-13 -std=c++17 -O2 main.cpp answer.cpp -o run && ./run
   ```

3. **Xcode Command Line Tools**
   ```bash
   xcrun clang++ -std=c++17 -O2 main.cpp answer.cpp -o run && ./run
   ```

### VSCode

1. **터미널에서 실행 (Ctrl+`)**

   - 내장 터미널에서 위 명령어 사용

2. **Task 설정 (tasks.json)**

   ```json
   {
     "version": "2.0.0",
     "tasks": [
       {
         "label": "build and run",
         "type": "shell",
         "command": "g++ -std=c++17 -O2 main.cpp answer.cpp -o run && ./run",
         "group": { "kind": "build", "isDefault": true }
       }
     ]
   }
   ```

   - `Ctrl+Shift+B`로 실행

3. **C++ 확장 기능 활용**

   - C/C++ Extension 설치
   - F5 키로 디버깅 실행

4. **Code Runner 확장**
   - Code Runner 확장 설치
   - 우클릭 → Run Code 또는 `Ctrl+Alt+N`
