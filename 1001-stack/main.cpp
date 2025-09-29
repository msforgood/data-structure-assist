// main.cpp
#include "StackType.h"
#include <iostream>
#include <fstream>
#include <string>

// is_matched는 별도 파일에 구현했다고 가정
bool is_matched(const std::string &expr);

// 데모: LIFO 동작 확인
static void demo_stack_basic() {
    StackType st;
    st.push('A'); st.push('B'); st.push('C');
    std::cout << "[DEMO] push A, B, C -> pop (LIFO)\n";
    while (!st.isEmpty()) {
        std::cout << "pop => " << st.pop()
                  << " (size=" << st.size() << ")\n";
    }
}

static int run_judge(std::istream &in) {
    std::string line;
    while (std::getline(in, line)) {
        std::cout << (is_matched(line) ? "MATCH" : "UNMATCH") << "\n";
    }
    return 0;
}

static void print_usage(const char* prog){
    std::cerr
      << "Usage:\n"
      << "  " << prog << "                # 스택 데모\n"
      << "  " << prog << " --judge         # 표준입력에서 줄별 판정\n"
      << "  " << prog << " --judge <file>  # 파일에서 줄별 판정\n";
}

int main(int argc, char** argv) {
    if (argc >= 2 && std::string(argv[1]) == "--judge") {
        if (argc >= 3) {
            std::ifstream fin(argv[2]);
            if (fin) {
                return run_judge(fin);          // 파일이 있으면 파일 읽기
            } else {
                // 파일이 없으면 인자 자체를 문자열로 간주
                std::string argexpr = argv[2];
                std::cout << (is_matched(argexpr) ? "MATCH" : "UNMATCH") << "\n";
                return 0;
            }
        }
        // 파일 미지정 시 표준입력 사용 (리다이렉션/파이프 가능)
        return run_judge(std::cin);
    }

    if (argc == 1) {
        demo_stack_basic();
        std::cout << "\n(참고) 채점기는 --judge 사용\n";
        return 0;
    }

    print_usage(argv[0]);
    return 1;
}
