// practice_answer.c — 정답 (조교/강사용)
// 빌드: gcc -Wall -o practice_answer practice_answer.c && ./practice_answer

#include <stdio.h>
#include <stdint.h>
#include <string.h>

// ===========================================================================
// 0단계. 포인터 기초 웜업
// ===========================================================================
void warmup_pointer_basics(void) {
    int x = 10;
    printf("x = %d\n", x);
    printf("x가 저장된 주소(&x) = %p\n", (void *)&x);

    int *p = &x;
    printf("p에 들어있는 주소   = %p\n", (void *)p);
    printf("*p (p가 가리키는 값) = %d\n", *p);

    *p = 20;
    printf("*p = 20; 실행 후 x = %d  (p로 x를 바꿀 수 있다)\n", x);
}

// ===========================================================================
// 문제 1. int 변수를 1바이트씩 들여다보기
// ===========================================================================
void print_bytes_of_int(int value) {
    unsigned char *bytes = (unsigned char *)&value;
    for (int i = 0; i < 4; i++) {
        printf("0x%02X ", bytes[i]);
    }
    printf("\n");
}

// ===========================================================================
// 문제 2. 문자 하나 -> 0/1
// ===========================================================================
int bit_char_to_int(char c) {
    int result = 0;
    if (c == '1') result = 1;
    return result;
}

// ===========================================================================
// 문제 3. 엔디안 변환
// ===========================================================================
uint32_t swap_endian32(uint32_t value) {
    unsigned char *bytes = (unsigned char *)&value;
    unsigned char tmp;

    tmp = bytes[0]; bytes[0] = bytes[3]; bytes[3] = tmp;
    tmp = bytes[1]; bytes[1] = bytes[2]; bytes[2] = tmp;

    return value;
}

// ===========================================================================
// 문제 4. 유니코드 -> UTF-8
// ===========================================================================
int encode_utf8(uint32_t codepoint, unsigned char *out) {
    if (codepoint < 0x80) {
        out[0] = (unsigned char)codepoint;
        return 1;
    } else if (codepoint < 0x800) {
        out[0] = (unsigned char)(0xC0 | (codepoint >> 6));
        out[1] = (unsigned char)(0x80 | (codepoint & 0x3F));
        return 2;
    } else if (codepoint < 0x10000) {
        out[0] = (unsigned char)(0xE0 | (codepoint >> 12));
        out[1] = (unsigned char)(0x80 | ((codepoint >> 6) & 0x3F));
        out[2] = (unsigned char)(0x80 | (codepoint & 0x3F));
        return 3;
    } else {
        out[0] = (unsigned char)(0xF0 | (codepoint >> 18));
        out[1] = (unsigned char)(0x80 | ((codepoint >> 12) & 0x3F));
        out[2] = (unsigned char)(0x80 | ((codepoint >> 6) & 0x3F));
        out[3] = (unsigned char)(0x80 | (codepoint & 0x3F));
        return 4;
    }
}

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
    uint32_t cps[] = {0x41, 0xAC00, 0x1F600};
    for (int i = 0; i < 3; i++) {
        n = encode_utf8(cps[i], buf);
        printf("U+%04X -> %d바이트:\n", cps[i], n);
        print_bytes(buf, n);
    }

    return 0;
}
