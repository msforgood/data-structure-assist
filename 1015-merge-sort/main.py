import time
import random
from answer_official import merge_sort


def measure_time(func, arr):
    start = time.perf_counter()  # 고해상도 타이머 시작
    result = func(arr.copy())
    end = time.perf_counter()    # 타이머 종료
    elapsed_ms = (end - start) * 1000  # 초 → 밀리초 변환
    print()

    return result, elapsed_ms


# 0 ~ 100000 사이의 정수 10,000개를 무작위로 생성
sample_big = [random.randint(0, 100000) for _ in range(10000)]
sample_small = [random.randint(0, 100000) for _ in range(20)]

sample_input = input("샘플 크기 선택 (big/small): ").strip().lower()
if sample_input == 'big':
    sample = sample_big
    print("큰 샘플 (10,000개) 선택 ==========================")
elif sample_input == 'small':
    sample = sample_small
    print("작은 샘플 (20개) 선택 =============================")
else:
    print("잘못된 입력입니다. 'big' 또는 'small'을 입력하세요.")
    exit(1)

print("샘플 크기:", len(sample))
print("앞부분 20개:", sample[:20])  # 확인용 출력
print()

# Merge Sort
res, t = measure_time(merge_sort, sample)
print("Merge Sort:")
print(res[:20])
print(f"Merge Sort Time: {t:.3f} ms\n")

print("="*80)