# 2025-가을 자료구조 실습 코드

**❌ main branch에 push 및 merge 절대 금지**

나만의 새로운 브랜치를 만드셔서 push 하는건 상관 없으니 자유롭게 사용 하세요~

## 1. 실습 코드 다운로드

- 실습 코드 폴더 생성 원하는 곳에서 아래 명령어 실행

```bash
$ git clone https://github.com/msforgood/data-structure-assist.git
```

(깃허브 페이지에서 Code → HTTPS 주소 복사 후 사용 가능)

## 2. 기존에 clone 한 경우 업데이트

- 저번 시간에 이미 clone 했다면 main 브랜치 pull 만으로도 최신 코드 반영 가능
- 해당 폴더 터미널에서 아래 명령어 실행

```bash
$ git pull origin main
```

## 3. Python 실행 방법

- 정답 코드는 `answer.py` 파일에 작성
- 작성한 코드 확인은 `main.py` 실행

```bash
$ python {자신의 폴더 실행 경로}/main.py
```

- 오피셜 정답은 `answer_official.py` 로 제공 예정
- `main.py` 내부 import 구문을 `from answer import ...` 또는 `from answer_official import ...` 로 바꾸어 테스트 가능

## 4. C++ 실행 방법

- 정답 코드: `answer_official.cpp`
- 실습 코드: `answer.cpp`

컴파일 및 실행 예시:

```bash
$ g++ main.cpp answer_official.cpp -o main   # 정답 버전 컴파일
$ g++ main.cpp answer.cpp -o main            # 실습 버전 컴파일
$ ./main                                     # 실행
```

### g++ 설치 방법

- Linux:

  ```bash
  $ sudo apt install build-essential
  ```

- macOS:  
  기본적으로 `clang++` 이 심볼릭 링크로 제공됨  
  동작하지 않으면

  ```bash
  $ xcode-select --install
  ```

- Windows:  
  Visual Studio Code를 통한 설치 권장  
  참고: [VSCode 설치 안내](https://velog.io/@watermeloncrane/vscode%EC%97%90%EC%84%9C-CC-%EC%84%B8%ED%8C%85-%EC%89%AC%EC%9B%80)

---

작성자: 김민서 (imkmsh@khu.ac.kr)
