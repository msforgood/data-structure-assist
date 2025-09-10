from answer_official import UnsortedList 

print("===== Shift 방식 Insert =====")
lst1 = UnsortedList()
lst1.items = list(range(1, 31))  # [1, 2, 3, ..., 30]
print(f"초기 리스트 (총 {len(lst1.items)}개): {lst1.items}")
lst1.insert_shift(15, 999)  # 중간에 삽입

# ===== Shift 방식 Insert =====
# 초기 리스트 (총 30개): [1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 21, 22, 23, 24, 25, 26, 27, 28, 29, 30]

# [Shift 방식] 999 삽입 at index 15
# 이동: index 29 -> index 30
# 이동: index 28 -> index 29
# 이동: index 27 -> index 28
# 이동: index 26 -> index 27
# 이동: index 25 -> index 26
# 이동: index 24 -> index 25
# 이동: index 23 -> index 24
# 이동: index 22 -> index 23
# 이동: index 21 -> index 22
# 이동: index 20 -> index 21
# 이동: index 19 -> index 20
# 이동: index 18 -> index 19
# 이동: index 17 -> index 18
# 이동: index 16 -> index 17
# 이동: index 15 -> index 16
# 삽입 완료: [1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 999, 16, 17, 18, 19, 20, 21, 22, 23, 24, 25, 26, 27, 28, 29, 30]

print("\n===== Overwrite 방식 Insert =====")
lst2 = UnsortedList()
lst2.items = list(range(1, 31))  # 동일한 리스트
print(f"초기 리스트 (총 {len(lst2.items)}개): {lst2.items}")
lst2.insert_overwrite(15, 999)  # 중간에 삽입

# ===== Overwrite 방식 Insert =====
# 초기 리스트 (총 30개): [1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 21, 22, 23, 24, 25, 26, 27, 28, 29, 30]

# [Overwrite 방식] 999 삽입 at index 15
# 복사: index 15 값(16) -> 맨 뒤
# 삽입 완료: [1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 999, 17, 18, 19, 20, 21, 22, 23, 24, 25, 26, 27, 28, 29, 30, 16]