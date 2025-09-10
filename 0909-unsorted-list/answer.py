import time

class UnsortedList:
    def __init__(self):
        self.items = []

    def insert_shift(self, index, item):
        """
        Shift 방식: index 위치부터 오른쪽으로 한 칸씩 밀고 item 삽입
        시간복잡도 O(n)
        """
        print(f"\n[Shift 방식] {item} 삽입 at index {index}")
        self.items.append(None)  # 공간 확보
        # 뒤에서부터 한 칸씩 이동
        for i in range(len(self.items) - 2, index - 1, -1):
            self.items[i + 1] = self.items[i]
            print(f"이동: index {i} -> index {i + 1}")
            time.sleep(0.1)  # 시간 지연
        self.items[index] = item
        print(f"삽입 완료: {self.items}")

    def insert_overwrite(self, index, item):
        """
        Overwrite 방식: index 위치 값 맨 뒤로 보내고, index에 item 삽입
        시간복잡도 O(1) (copy 1회 + insert 1회)
        """
        print(f"\n[Overwrite 방식] {item} 삽입 at index {index}")
        if index < len(self.items):
            # 복사
            moved = self.items[index]
            self.items.append(moved)
            print(f"복사: index {index} 값({moved}) -> 맨 뒤")
            time.sleep(0.1)
            # 덮어쓰기
            self.items[index] = item
            print(f"삽입 완료: {self.items}")
        else:
            # index가 범위 밖이면 append로 처리
            self.items.append(item)
            print(f"index 범위 밖 → append: {self.items}")



print("===== Shift 방식 Insert =====")
lst1 = UnsortedList()
lst1.items = list(range(1, 31))  # [1, 2, 3, ..., 30]
print(f"초기 리스트 (총 {len(lst1.items)}개): {lst1.items}")
lst1.insert_shift(15, 999)  # 중간에 삽입

print("\n===== Overwrite 방식 Insert =====")
lst2 = UnsortedList()
lst2.items = list(range(1, 31))  # 동일한 리스트
print(f"초기 리스트 (총 {len(lst2.items)}개): {lst2.items}")
lst2.insert_overwrite(15, 999)  # 중간에 삽입