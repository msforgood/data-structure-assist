# Programming Tips (C++)

이 문서는 `swap_value`, `swap_ref`, `swap_pointer_deref`, `swap_pointer_var`, `increment_pointer` 다섯 가지 함수를 정리한 것입니다.  
각 함수의 정의, 역할, input/output, 주의사항을 정리했습니다.

---

## 0. 포인터 기초

- `&x` : 변수 `x`의 주소 (메모리 위치)
- `int *p` : `int` 타입 주소를 담는 포인터 변수
- `*p` : 포인터 `p`가 가리키는 주소의 실제 값 (역참조)

Tip: 원본 값을 직접 바꾸고 싶으면, 주소를 넘겨서 `*p`를 조작해야 합니다.

---

## 1. swap_value(int a, int b)

(Call by Value – 값 전달)

- 정의: 인자로 값이 복사되어 들어옴 → 원본 `x, y`는 안 바뀜
- 역할: Call by Value의 동작 확인
- input: 정수 두 개 (복사본)
- 주의: 원본 바꾸려면 참조/포인터 필요

---

## 2. swap_ref(int &a, int &b)

(Call by Reference – 참조 전달, C++ 전용)

- 정의: a, b는 원본 x, y와 같은 메모리 → 바꾸면 원본도 바뀜
- 역할: Call by Reference 예제
- input: 참조 두 개 (원본 변수)
- 주의: C에서는 불가능. 포인터로 같은 효과를 낼 수 있음.

---

## 3. swap_pointer_deref(int *a, int *b)

(Call by Address – 주소 전달 후 역참조)

- 정의: a, b는 주소를 가짐. `*a`, `*b`로 원본 값 수정 가능
- 역할: 포인터 역참조로 Call by Address 구현
- input: int\* 두 개 (`&x`, `&y` 형태로 호출)
- 주의: 널 포인터는 역참조하면 크래시

---

## 4. swap_pointer_var(int *a, int *b)

(포인터 변수 자체만 교환)

- 정의: a, b는 “포인터 변수 복사본”. 둘만 바꾸면 원본 값(x,y)은 안 바뀜
- 역할: 포인터 스왑 예시 (pdf의 swap4)
- input: int\* 두 개
- 주의: 원본 값을 바꾸려면 3번처럼 `*a`, `*b` 사용해야 함

---

## 5. increment_pointer(int \*ptr)

(포인터로 값 1 증가)

- 정의: ptr이 가리키는 정수 값을 1 증가
- 역할: 포인터 역참조로 원본 값 수정
- input: int\* (예: &x)
- 주의:
  - `(*ptr)++` : 가리키는 값 증가 (원하는 동작)
  - `*ptr++` : 포인터 자체가 다음 주소로 이동 (원치 않는 동작)

---

## 정리: 언제 어떤 걸 쓸까?

- swap_value : 내부에서만 스왑 (원본 영향 없음)
- swap_ref : 원본 변수 스왑 (C++ 전용, 참조)
- swap_pointer_deref : 원본 변수 스왑 (C 스타일, 포인터 역참조)
- swap_pointer_var : 원본 값은 안 바뀌는 포인터 스왑 예시
- increment_pointer : 주소를 받아 원본 값을 직접 증가
