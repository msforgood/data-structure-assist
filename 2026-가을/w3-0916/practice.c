// practice.c — 3주차 실습: 비트 / 바이트 / 엔디안 / 인코딩
//
// 규칙: AI 사용 금지. 직접 채우세요.
// NEED_TO_SOLVE는 아무 동작도 하지 않는 빈 자리입니다.
// (컴파일은 되지만, 그대로 두면 결과가 틀립니다.)
//
// 빌드: gcc -Wall -o practice practice.c && ./practice

#include <stdio.h>
#include <stdint.h>
#include <string.h>

#define NEED_TO_SOLVE /* TODO: 이 부분을 직접 채우세요 */

// ===========================================================================
// 0단계. 포인터 기초 웜업 — 직접 채울 건 없습니다. 코드를 읽고 실행해서
// "포인터가 실제로 무슨 일을 하는지" 눈으로 확인하세요.
//
//   int x = 10;      : 변수 x는 메모리 어딘가에 자리를 잡는다.
//   &x               : x가 있는 그 "주소".
//   int *p = &x;     : p는 정수를 가리키는 포인터. p 안에는 x의 주소가 들어있다.
//   *p               : p가 "가리키는 곳"의 값 (역참조). 지금은 x와 같은 값.
//   *p = 20;         : p가 가리키는 곳에 20을 쓴다 -> x가 바뀐다.
// ===========================================================================
void warmup_pointer_basics(void) {
    int x = 10;
    printf("x = %d\n", x);
    printf("x가 저장된 주소(&x) = %p\n", (void *)&x);

    int *p = &x; // p는 "x의 주소"를 담은 포인터
    printf("p에 들어있는 주소   = %p\n", (void *)p);
    printf("*p (p가 가리키는 값) = %d\n", *p);

    *p = 20; // p를 통해 x의 값을 바꾼다
    printf("*p = 20; 실행 후 x = %d  (p로 x를 바꿀 수 있다)\n", x);
}

// ===========================================================================
// 문제 1. int 변수를 1바이트씩 들여다보기
//
// int는 보통 4바이트입니다. unsigned char*로 포인터의 타입을 바꾸면,
// "한 번에 4바이트로 읽기"가 아니라 "한 번에 1바이트씩 읽기"가 됩니다.
// (주소는 그대로이고, 그 주소를 얼마나 크게 잘라 읽을지만 바뀝니다.)
// ===========================================================================
void print_bytes_of_int(int value) {
    unsigned char *bytes = (unsigned char *)&value;
    for (int i = 0; i < 4; i++) {
        // TODO: bytes[i]를 "0x12 " 같은 형식(16진수, 2자리)으로 출력하세요.
        NEED_TO_SOLVE;
    }
    printf("\n");
}

// ===========================================================================
// 문제 2. 문자 하나가 '0'인지 '1'인지 보고 정수 0 또는 1로 바꾸기
// ===========================================================================
int bit_char_to_int(char c) {
    int result = 0;
    // TODO: c가 '1'이면 result에 1을 넣으세요. ('0'이면 그대로 0)
    NEED_TO_SOLVE;
    return result;
}

// ===========================================================================
// 문제 3. 32비트 정수의 바이트 순서를 뒤집는다 (little <-> big endian 상호 변환)
// (문제 1에서 이미 해본 unsigned char* 캐스팅을 그대로 사용합니다)
// ===========================================================================
uint32_t swap_endian32(uint32_t value) {
    unsigned char *bytes = (unsigned char *)&value;

    // TODO: bytes[0]<->bytes[3], bytes[1]<->bytes[2] 를 서로 교환하세요.
    NEED_TO_SOLVE;
    NEED_TO_SOLVE;

    return value;
}

// ===========================================================================
// 문제 4. 유니코드 코드포인트(예: 'A'=0x41, '가'=0xAC00)를 UTF-8 바이트로
//         인코딩한다. out에 바이트를 채우고, 사용한 바이트 개수(1~4)를 반환.
// ===========================================================================
int encode_utf8(uint32_t codepoint, unsigned char *out) {
    if (codepoint < 0x80) {
        // TODO: 1바이트 인코딩 (ASCII 범위는 그대로 1바이트)
        NEED_TO_SOLVE;
        return 1;
    } else if (codepoint < 0x800) {
        // TODO: 2바이트 인코딩
        // out[0] = 110xxxxx (앞 5비트), out[1] = 10xxxxxx (뒤 6비트)
        NEED_TO_SOLVE;
        NEED_TO_SOLVE;
        return 2;
    } else if (codepoint < 0x10000) {
        // TODO: 3바이트 인코딩
        // out[0] = 1110xxxx (앞 4비트), out[1]/out[2] = 10xxxxxx (6비트씩)
        NEED_TO_SOLVE;
        NEED_TO_SOLVE;
        NEED_TO_SOLVE;
        return 3;
    } else {
        // TODO: 4바이트 인코딩
        // out[0] = 11110xxx (앞 3비트), out[1..3] = 10xxxxxx (6비트씩)
        NEED_TO_SOLVE;
        NEED_TO_SOLVE;
        NEED_TO_SOLVE;
        NEED_TO_SOLVE;
        return 4;
    }
}

// ===========================================================================
// 아래는 실행/확인용 코드입니다. (수정하지 않아도 됩니다)
// ===========================================================================
static void print_bytes(const unsigned char *buf, int len) {
    printf("  10진수: "); for (int i = 0; i < len; i++) printf("%3u ", buf[i]);
    printf("\n  16진수: "); for (int i = 0; i < len; i++) printf("0x%02X ", buf[i]);
    printf("\n");
}

int main(void) {
    unsigned char buf[16];
    int n;

    printf("=== 0단계: 포인터 기초 웜업 ===\n");
    warmup_pointer_basics();

    printf("\n=== 문제 1: int를 바이트로 들여다보기 ===\n");
    printf("0x12345678 의 바이트: ");
    print_bytes_of_int(0x12345678);

    printf("\n=== 문제 2: 문자 하나 -> 0/1 ===\n");
    printf("bit_char_to_int('1') = %d\n", bit_char_to_int('1'));
    printf("bit_char_to_int('0') = %d\n", bit_char_to_int('0'));

    printf("\n=== 문제 3: 엔디안 변환 ===\n");
    printf("swap_endian32(0x12345678) = 0x%08X\n", swap_endian32(0x12345678));

    printf("\n=== 문제 4: 유니코드 -> UTF-8 ===\n");
    uint32_t cps[] = {0x41, 0xAC00, 0x1F600}; // 'A', '가', 'GRINNING FACE'
    for (int i = 0; i < 3; i++) {
        n = encode_utf8(cps[i], buf);
        printf("U+%04X -> %d바이트:\n", cps[i], n);
        print_bytes(buf, n);
    }

    return 0;
}
