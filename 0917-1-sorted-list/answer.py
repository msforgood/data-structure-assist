NEED_TO_SOLVE = 1

class SortedList:
    def __init__(self, max_size=100):
        self.data = [None] * max_size
        self.length = 0
        self.max_size = max_size

    # 보조 메서드
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

    # 핵심 1: 삽입 (정렬 유지)
    # 1) 들어갈 위치 탐색 (선형)
    # 2) 뒤에서부터 한 칸씩 밀기 (shift)
    # 3) 값 넣기 + length 증가
    def insertItem(self, value):
        if self.isFull():
            raise OverflowError("List is full")

        # 1) 위치 찾기: 첫 번째로 value <= data[i]가 되는 위치 i
        location = 0
        while NEED_TO_SOLVE:
            if NEED_TO_SOLVE:
                location += 1
            else:
                break

        # 2) 뒤에서부터 오른쪽으로 한 칸씩 밀기
        #    [location..length-1] 구간을 한 칸씩 뒤로
        i = self.size()
        while NEED_TO_SOLVE:
            NEED_TO_SOLVE
            i -= 1

        # 3) 삽입
        NEED_TO_SOLVE = value
        self.length += 1

    # 핵심 2: 이진 탐색 (O(log N))
    # 찾으면 인덱스, 없으면 -1
    def findItem(self, item):
        first, last = NEED_TO_SOLVE, NEED_TO_SOLVE
        while NEED_TO_SOLVE:
            mid = NEED_TO_SOLVE

            if NEED_TO_SOLVE:
                NEED_TO_SOLVE 
            elif NEED_TO_SOLVE:
                NEED_TO_SOLVE
            else:
                return mid
            
        return -1

    # 핵심 3: 삭제 (검색 후 shift로 당기기)
    def removeItem(self, value):
        if self.isEmpty():
            return False
            
        idx = self.findItem(value)
        if idx == -1:
            return False

        # idx 이후를 한 칸씩 왼쪽으로 당김
        i = idx
        while i < self.size() - 1:
            self.data[i] = self.data[i + 1]
            i += 1

        # 꼬리 정리
        self.data[self.size() - 1] = None
        self.length -= 1
        return True

    # 핵심 4: 갱신 (정렬 유지 위해 remove + insert)
    def updateItem(self, old_value, new_value):
        removed = self.removeItem(old_value)
        if not removed:
            return False
        self.insertItem(new_value)
        return True
