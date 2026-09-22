# practice.py — 4주차 실습: 비정렬 리스트와 시간복잡도
#
# 규칙
#  - AI 사용 금지. 직접 채운다.
#  - 파이썬 list의 append / insert / remove / index / in 사용 금지.
#    self.data(고정 크기 배열)와 self.length만 직접 조작한다.
#  - NEED_TO_SOLVE는 아무 동작도 하지 않는 빈 자리다.
#    (실행은 되지만, 그대로 두면 결과가 틀린다.)
#
# 실행: python3 practice.py

import time

MAX_SIZE = 100

NEED_TO_SOLVE = None  # TODO: 이 자리를 직접 채우세요


class UnsortedList:
    """배열(고정 크기)로 구현한 비정렬 리스트."""

    def __init__(self, max_size=MAX_SIZE):
        self.data = [None] * max_size   # 저장 공간 (크기 고정)
        self.length = 0                 # 지금 들어 있는 원소 개수
        self.max_size = max_size

    # =======================================================================
    # 관찰자 (Observer) — 값을 바꾸지 않는 연산. 직접 채울 것은 없다.
    # data[0] ~ data[length-1]만 의미 있는 값이고 그 뒤는 쓰레기 값이다.
    # =======================================================================
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

    # =======================================================================
    # 문제 1. appendItem — 맨 뒤에 값을 붙인다
    #
    # 지금 원소가 length개면 다음 빈 자리는 data[length]다.
    # =======================================================================
    def appendItem(self, value):
        if self.isFull():
            raise OverflowError("List is full")

        # TODO: data의 빈 자리에 value를 저장하고, length를 1 늘린다.
        NEED_TO_SOLVE

    # =======================================================================
    # 문제 2. insertItem — pos 자리에 끼워 넣는다 (뒤 원소를 한 칸씩 민다)
    #
    #   [25, 13, 47]에 insertItem(1, 7) -> [25, 7, 13, 47]
    #   맨 뒤부터 당겨와야 값이 덮어써지지 않는다.
    # =======================================================================
    def insertItem(self, pos, value):
        if self.isFull():
            raise OverflowError("List is full")
        if pos < 0 or pos > self.length:
            raise IndexError("pos out of range")

        # TODO: i를 length에서 시작해 pos보다 클 동안,
        #       data[i]에 data[i-1]을 복사하고 i를 1씩 줄인다.
        NEED_TO_SOLVE

        # TODO: 비워진 pos 자리에 value를 넣고, length를 1 늘린다.
        NEED_TO_SOLVE

    # =======================================================================
    # 문제 3. improved_insertItem — 밀지 않고 pos 자리에 끼워 넣는다
    #
    #   비정렬 리스트는 순서에 의미가 없다. 원래 pos에 있던 값을
    #   맨 뒤로 옮기고, 그 자리에 새 값을 쓰면 끝이다.
    #   [25, 13, 47]에 improved_insertItem(1, 7) -> [25, 7, 47, 13]
    # =======================================================================
    def improved_insertItem(self, pos, value):
        if self.isFull():
            raise OverflowError("List is full")
        if pos < 0 or pos > self.length:
            raise IndexError("pos out of range")

        # TODO: data[pos]에 있던 값을 맨 뒤(data[length])로 옮긴다.
        NEED_TO_SOLVE

        # TODO: pos 자리에 value를 쓰고, length를 1 늘린다.
        NEED_TO_SOLVE

    # =======================================================================
    # 문제 4. findItem — 선형 탐색. 찾으면 그 위치, 없으면 -1을 반환한다
    #
    # 정렬되어 있지 않으므로 0번부터 하나씩 비교하는 방법밖에 없다.
    # (수업의 findItem은 True/False를 반환했지만, 여기서는 문제 5에서
    #  다시 쓸 수 있도록 위치를 반환한다.)
    # =======================================================================
    def findItem(self, item):
        pos = 0
        # TODO: pos가 length보다 작을 동안 data[pos]와 item을 비교하고,
        #       같으면 pos를 반환한다. 다르면 pos를 1 늘린다.
        NEED_TO_SOLVE
        return -1

    # =======================================================================
    # 문제 5. removeItem — 값을 찾아서 지운다. 지웠으면 True, 없으면 False
    #
    #   ① findItem으로 위치를 찾는다 (없으면 False)
    #   ② 맨 뒤 원소를 그 자리로 옮겨 빈칸을 메운다 (순서는 신경 쓰지 않는다)
    #   ③ length를 1 줄인다
    # =======================================================================
    def removeItem(self, value):
        # TODO: 위 ① ② ③을 그대로 코드로 옮긴다.
        NEED_TO_SOLVE
        return False


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
# 문제 6. 시간복잡도 체감 실험 (코드는 주어진다. 결과를 읽고 해석한다)
#
#  - 실험 1: 같은 '맨 앞 삽입'을 두 방식으로 재고, N을 2배씩 키운다.
#  - 실험 2: 값을 찾아야 하는 연산과 위치를 아는 연산을 비교한다.
#  - 볼 것: N이 2배가 될 때 시간이 어떻게 변하는가.
# ===========================================================================
def build(n):
    lst = UnsortedList(n + 1000)
    for i in range(n):
        lst.appendItem(i)
    return lst


def measure(n, repeat=200):
    """맨 앞(pos=0) 삽입을 repeat번 반복하고, 1회당 걸린 시간(마이크로초)을 잰다."""
    result = []
    for method in ("insertItem", "improved_insertItem"):
        lst = build(n)
        f = getattr(lst, method)
        start = time.perf_counter()
        for _ in range(repeat):
            f(0, -1)
        elapsed = time.perf_counter() - start
        result.append(elapsed / repeat * 1_000_000)
    return result


def run_experiment():
    print("=== 실험 1. insertItem vs improved_insertItem (pos=0 삽입 1회 평균) ===")
    print("       N |    insertItem |  improved |  배수")
    print("-" * 46)
    base = None
    for n in (1000, 2000, 4000, 8000, 16000):
        shift_us, improved_us = measure(n)
        if base is None:
            base = shift_us
        print(f"{n:>8} | {shift_us:>11.1f}us | {improved_us:>7.1f}us | {shift_us / base:>4.1f}x")
    print()

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
    print()

    print("생각해보기")
    print("  1. 실험 1에서 N이 2배가 될 때 insertItem의 시간은 몇 배가 되는가?")
    print("  2. improved_insertItem은 왜 N이 커져도 시간이 변하지 않는가?")
    print("  3. 정렬된 리스트였다면 improved_insertItem을 쓸 수 있는가?")


if __name__ == "__main__":
    if run_checks():
        run_experiment()
    else:
        print("체크포인트를 먼저 통과시킨 뒤 실험을 돌린다.")
