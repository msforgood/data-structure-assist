import time

class UnsortedList:
    def __init__(self):
        self.items = []

    # ============ Shift 방식 ============
    def insert_shift(self, index, item):
        """
        index 위치부터 오른쪽으로 한 칸씩 밀고 item 삽입
        목표: self.items = [..., item, (원래 index~끝 요소들)...]
        시간복잡도: O(n)
        """
        print(f"\n[Shift 방식] {item} 삽입 at index {index}")

        # [STEP 1] 공간 확보: 맨 뒤에 빈 칸 만들기
        # TODO: self.items에 자리 하나를 만든다 (예: None 추가)

        self.items.append(None)  # 공간 확보

        # [STEP 2] 뒤에서 앞으로 한 칸씩 이동
        # TODO: range(끝-1, index-1, -1) 형태의 역방향 루프로
        #       i 위치의 값을 i+1로 복사한다. (프린트로 이동 로그도 남겨보기)

        for i in range(len(self.items) - 2, index - 1, -1):
            self.items[i + 1] = self.items[i]
            print(f"이동: index {i} -> index {i + 1}")
            time.sleep(0.1)  # 시간 지연 (optional)

        # [STEP 3] 비워둔 index 자리에 새 값 쓰기

        self.items[index] = item

        # [STEP 4] 상태 출력(확인용)
        print(f"삽입 완료: {self.items}")

    # ============ Overwrite 방식 ============
    def insert_overwrite(self, index, item):
        """
        index 위치 값을 맨 뒤로 보내고 index에 item 덮어쓰기
        목표: self.items[index] <- item, 끝에는 기존 값이 복사되어 붙음
        시간복잡도: O(1) (동적 배열 확장 제외, append는 amortized O(1))
        """
        print(f"\n[Overwrite 방식] {item} 삽입 at index {index}")

        # [STEP 1] 인덱스 유효성 처리
        # TODO: 만약 index가 범위 밖(>= len)이라면 append(item)하고 종료

        if pass:
            pass

        else:
            pass

        # [STEP 2] 기존 값 백업

        # [STEP 3] 백업 값을 맨 뒤에 붙이기

        # [STEP 4] index 자리에 새 값 덮어쓰기

        print(f"삽입 완료: {self.items}")


# ===== 간단 테스트(체크포인트) =====
def checkpoint_shift():
    lst = UnsortedList()
    lst.items = list(range(1, 6))  # [1,2,3,4,5]
    lst.insert_shift(2, 99)        # index=2에 99
    # 기대: [1,2,99,3,4,5]
    assert lst.items == [1,2,99,3,4,5], f"실패: {lst.items}"
    print("Shift PASS")

def checkpoint_overwrite():
    lst = UnsortedList()
    lst.items = list(range(1, 6))  # [1,2,3,4,5]
    lst.insert_overwrite(2, 99)    # index=2 자리에 99, 3은 뒤로 복사
    # 기대: [1,2,99,4,5,3]
    assert lst.items == [1,2,99,4,5,3], f"실패: {lst.items}"
    print("Overwrite PASS")

if __name__ == "__main__":
    checkpoint_shift()
    checkpoint_overwrite()
