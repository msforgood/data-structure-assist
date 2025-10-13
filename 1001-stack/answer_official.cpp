#include "StackType.h"                                   // 헤더에는 data[MAX_SIZE] 고정 배열이 선언됨(객체 내부 메모리).

/*==========================
  StackType 메서드 구현부
==========================*/

// 생성자: top 초기화
StackType::StackType() {                                 // 객체 생성 시 호출. data 배열은 이미 객체 내부에 자리 잡음(추가 할당 없음).
    top = -1;                                            // 논리적 크기를 -1로 설정 (비어있음을 의미). 데이터 영역은 초기화하지 않아도 됨.
}

// push
void StackType::push(ItemType value) {                   
    if (isFull()) {                                      // 경계 검사: top가 마지막 인덱스에 도달했다면 더 이상 쓸 공간 없음(오버플로 방지).
        throw std::overflow_error("Stack overflow");     // 힙/스택 메모리 직접 사용 없이 예외 객체를 임시 생성해 던짐(런타임 시 스택/힙 내부 처리).
    }
    data[++top] = value;                                 // top을 1 증가시킨 뒤, 증가된 인덱스에 value를 '직접 대입'.
                                                         // 이 순간 data 배열의 해당 슬롯(이미 객체 내부에 존재하는 메모리)에 값이 저장됨.
}

// pop
ItemType StackType::pop() {                              
    if (isEmpty()) {                                     // 경계 검사: 비어 있으면 읽을 유효 데이터가 없음(언더플로 방지).
        throw std::underflow_error("Stack underflow");   // 추가 메모리 할당 없이 오류 전파(런타임 시스템이 예외 처리).
    }
    return data[top--];                                  // 현재 top 위치의 값을 '복사'해서 반환하고, top을 1 감소.
                                                         // 메모리상 원본은 남아있지만(top만 줄임), 논리적으로는 삭제된 것으로 간주.
}

// 현재 크기
int StackType::size() const {                            // data 배열의 실제 사용량(논리적 크기)을 계산해 돌려줌.
    return top + 1;                                      // top=-1이면 0, top=0이면 1 ... (data의 물리 메모리는 그대로 유지됨).
}

// 상태 검사
bool StackType::isFull() const {                         // 배열 경계 상한 검사. MAX_SIZE는 컴파일타임 상수.
    return top >= MAX_SIZE - 1;                          // top가 마지막 슬롯에 도달했으면 true. 새로 쓸 수 있는 여유 메모리가 없음.
}

bool StackType::isEmpty() const {                        // 비어있는지 검사.
    return top < 0;                                      // top==-1이면 비어있음. 메모리를 해제하는 개념이 아니라 '참조하지 않기'로 관리.
}

/*==========================
  괄호 짝 검사 (스택 사용)
==========================*/

// 괄호 짝 검사 함수
bool is_matched(const std::string &expression) {
    StackType st;                                        // StackType 객체 st를 생성.

    for (char ch : expression) {                         
        if (ch == '(' || ch == '[' || ch == '{') {       // 열린 괄호라면
            st.push(ch);                                 // 스택에 문자 1개를 '배열 슬롯에 직접 저장'.

        } else if (ch == ')' || ch == ']' || ch == '}') {// 닫힌 괄호라면
            if (st.isEmpty()) return false;              // 닫을 대상이 없으면 불일치 → 바로 false.

            char open = st.pop();                        // 스택 최상단 문자를 복사 반환(top 감소). data 슬롯을 실제로 지우진 않음(논리 삭제).
            
            if ((open == '(' && ch != ')') ||            // 열린/닫힌 괄호 페어 검증.
                (open == '[' && ch != ']') ||
                (open == '{' && ch != '}')) {
                return false;                            // 짝이 틀리면 false.
            }
        }
        // 다른 문자는 무시                                  
    }
    return st.isEmpty();                                 // 모든 문자를 처리한 뒤, 스택이 비어 있어야 완전 매칭.
                                                         // 비어 있지 않다면 data에 남은 값이 있지만 '미닫힘' 상태 → false.
}
