NEED_TO_SOLVE='stack'
def NEED_TO_SOLVE():
    a = 1

class Stack:
    def __init__(self):
        self._data = []  # list로 top은 맨 끝

    def print(self):
        print(self._data)

    def push(self, x):
        NEED_TO_SOLVE

    def pop(self):
        NEED_TO_SOLVE

    def top(self):
        NEED_TO_SOLVE

    def is_empty(self):
        return len(self._data) == 0

    def size(self):
        return len(self._data)

def is_matched(expression: str) -> bool:
    pairs = {')': '(', ']': '[', '}': '{'}
    st = Stack()  # 리스트 대신 우리가 만든 스택 사용

    for ch in expression:
        
        NEED_TO_SOLVE

        else:
            # 기타 문자는 무시
            pass
    # 모두 처리 후 비어 있어야 완전 매칭
    return st.NEED_TO_SOLVE()


if __name__ == "__main__":
    stack = Stack()
    for v in [7, 3, 6]:
        stack.push(v)
        stack.print()

    print(stack.pop())  # 6
    stack.print()

    stack.push(4)
    stack.print()
    
    while not stack.is_empty():
        print(stack.pop())
        stack.print()

    tests = [
        "()[]{}", "([{}])", "([)]", "(((())))", "([)",
        "{[()]}a+b*(c-d)", ""
    ]
    for t in tests:
        print(t, "=>", "MATCH" if is_matched(t) else "UNMATCH")


