# from answer_official import SortedList
from answer import SortedList

def main():
    s_list = SortedList(10)

    print("삽입"+"="*16)
    for v in [3, 5, 1, 4, 2]:
        print(f"{v} 삽입 시도")
        s_list.insertItem(v)
        print(f"결과: {[s_list.getItem(i) for i in range(s_list.size())]}\n")
    print("="*20+"\n")

    print("탐색"+"="*16)
    for v in [1, 3, 5, 0, 6]:
        idx = s_list.findItem(v)
        if idx != -1:
            print(f"{v} -> {idx} 위치에 있음")
        else:
            print(f"{v} 없음")
    print("="*20+"\n")


    print("삭제"+"="*16)
    while not s_list.isEmpty():
        remove_val = s_list.getItem(0)  # 가장 작은 값
        print(f"{remove_val} 삭제 시도")
        s_list.removeItem(remove_val)
        print(f"결과: {[s_list.getItem(i) for i in range(s_list.size())]}\n")
    print("="*20+"\n")

    print("clear")
    s_list.clear()
    
if __name__ == "__main__":
    main()