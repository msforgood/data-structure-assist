# practice_answer.py — 4주차 실습 정답: 비정렬 리스트와 시간복잡도
#
# 실행: python3 practice_answer.py

import time

MAX_SIZE = 100


class UnsortedList:
    """배열(고정 크기)로 구현한 비정렬 리스트."""

    def __init__(self, max_size=MAX_SIZE):
        self.data = [None] * max_size   # 저장 공간 (크기 고정)
        self.length = 0                 # 지금 들어 있는 원소 개수
        self.max_size = max_size

    # ===== 관찰자 (Observer) — 값을 바꾸지 않는 연산 =====
    def size(self):
        return self.length

    def isFull(self):
        return self.length == self.max_size

    def isEmpty(self):
        return self.length == 0

    def getItem(self, pos):
        if pos < 0 or pos >= self.length:
            raise IndexError("pos out of range")
        return self.data[pos]

    def clear(self):
        self.length = 0

    def toList(self):
        return [self.data[i] for i in range(self.length)]

    # ===== 문제 1. appendItem — 맨 뒤에 추가 =====
    def appendItem(self, value):
        if self.isFull():
            raise OverflowError("List is full")
        self.data[self.length] = value
        self.length += 1

    # ===== 문제 2. insertItem — pos 자리에 끼워 넣기 (뒤를 민다) =====
    def insertItem(self, pos, value):
        if self.isFull():
            raise OverflowError("List is full")
        if pos < 0 or pos > self.length:
            raise IndexError("pos out of range")
        i = self.length
        while i > pos:
            self.data[i] = self.data[i - 1]
            i -= 1
        self.data[pos] = value
        self.length += 1

    # ===== 문제 3. improved_insertItem — 원래 값을 맨 뒤로 보내고 삽입 =====
    def improved_insertItem(self, pos, value):
        if self.isFull():
            raise OverflowError("List is full")
        if pos < 0 or pos > self.length:
            raise IndexError("pos out of range")
        self.data[self.length] = self.data[pos]
        self.data[pos] = value
        self.length += 1

    # ===== 문제 4. findItem — 선형 탐색, 위치 반환 (없으면 -1) =====
    def findItem(self, item):
        pos = 0
        while pos < self.length:
            if self.data[pos] == item:
                return pos
            pos += 1
        return -1

    # ===== 문제 5. removeItem — 찾아서 지우고 맨 뒤 값으로 메우기 =====
    def removeItem(self, value):
        pos = self.findItem(value)
        if pos == -1:
            return False
        self.data[pos] = self.data[self.length - 1]
        self.data[self.length - 1] = None
        self.length -= 1
        return True


# ===========================================================================
# 체크포인트 — 구현이 맞는지 확인한다 (수정하지 않아도 됨)
# ===========================================================================
def make(values, max_size=MAX_SIZE):
    lst = UnsortedList(max_size)
    for v in values:
        lst.appendItem(v)
    return lst


def after(lst, method, *args):
    getattr(lst, method)(*args)
    return lst.toList()


def removed(lst, value):
    return (lst.removeItem(value), lst.toList())


CASES = [
    ("appendItem 3회",           lambda: make([25, 13, 47]).toList(),                    [25, 13, 47]),
    ("insertItem(1, 7)",         lambda: after(make([25, 13, 47]), "insertItem", 1, 7),  [25, 7, 13, 47]),
    ("improved_insertItem(1, 7)", lambda: after(make([25, 13, 47]), "improved_insertItem", 1, 7), [25, 7, 47, 13]),
    ("findItem(47)",             lambda: make([25, 7, 47, 13]).findItem(47),             2),
    ("findItem(99)",             lambda: make([25, 7, 47, 13]).findItem(99),             -1),
    ("removeItem(7)",            lambda: removed(make([25, 7, 47, 13]), 7),              (True, [25, 13, 47])),
    ("removeItem(99)",           lambda: removed(make([25, 7, 47, 13]), 99),             (False, [25, 7, 47, 13])),
]


def run_checks():
    print("=== 체크포인트 ===")
    ok = True
    for name, fn, expected in CASES:
        try:
            got = fn()
        except Exception as e:
            got = f"{type(e).__name__}: {e}"
        passed = (got == expected)
        ok = ok and passed
        print(f"  [{'PASS' if passed else 'FAIL'}] {name}: {got}"
              + ("" if passed else f"  (기대: {expected})"))
    print(f"결과: {'전부 통과' if ok else '통과하지 못한 항목이 있다'}\n")
    return ok


# ===========================================================================
# 시간복잡도 체감 실험 (수정하지 않아도 됨)
# ===========================================================================
def build(n, extra=1000):
    lst = UnsortedList(n + extra)
    for i in range(n):
        lst.appendItem(i)
    return lst


def measure(n):
    """맨 앞(pos=0) 삽입을 여러 번 반복하고, 1회당 걸린 시간(마이크로초)을 잰다.

    improved 쪽은 1회가 너무 빨라서(수백 나노초) 반복 횟수를 더 늘려야
    시간 측정 오차에 묻히지 않는다.
    """
    result = []
    for method, repeat in (("insertItem", 200), ("improved_insertItem", 4000)):
        lst = build(n, repeat + 100)
        f = getattr(lst, method)
        start = time.perf_counter()
        for _ in range(repeat):
            f(0, -1)
        elapsed = time.perf_counter() - start
        result.append(elapsed / repeat * 1_000_000)
    return result


def run_experiment():
    print("=== 실험 1. insertItem vs improved_insertItem (pos=0 삽입 1회 평균) ===")
    print("       N |    insertItem |    improved |  성장 |    배율")
    print("-" * 58)
    base = None
    for n in (1000, 2000, 4000, 8000, 16000):
        shift_us, improved_us = measure(n)
        if base is None:
            base = shift_us
        print(f"{n:>8} | {shift_us:>11.1f}us | {improved_us:>9.3f}us | "
              f"{shift_us / base:>4.1f}x | {shift_us / improved_us:>6.0f}x")
    print("N이 2배가 되면 insertItem도 약 2배 -> O(N) / improved는 그대로 -> O(1)\n")

    print("=== 실험 2. findItem(없는 값) vs getItem (1회 평균) ===")
    print("       N |    findItem |   getItem")
    print("-" * 34)
    for n in (1000, 2000, 4000, 8000, 16000):
        lst = build(n)

        start = time.perf_counter()
        for _ in range(20):
            lst.findItem(-1)            # 없는 값 -> 끝까지 훑는다 (최악의 경우)
        find_us = (time.perf_counter() - start) / 20 * 1_000_000

        start = time.perf_counter()
        for _ in range(20):
            lst.getItem(n - 1)          # 위치를 이미 안다
        get_us = (time.perf_counter() - start) / 20 * 1_000_000

        print(f"{n:>8} | {find_us:>9.1f}us | {get_us:>7.2f}us")
    print("찾아야 하는 연산은 O(N), 위치를 아는 연산은 O(1)\n")


if __name__ == "__main__":
    if run_checks():
        run_experiment()
    else:
        print("체크포인트를 먼저 통과시킨 뒤 실험을 돌린다.")
