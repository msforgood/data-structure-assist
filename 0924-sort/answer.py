# answer.py

"""
answer_official.py
자료구조 실습: 5가지 정렬 알고리즘 (Selection, Bubble, Insertion, Quick)

사용 예시:
    python answer.py
    또는
    python main.py
"""

NEED_TO_SOLVE = 'sort'  # 이 부분을 채워 넣으세요

def selection_sort(arr):  # 선택 정렬 함수 정의
    """
    선택 정렬 (Selection Sort)
    - 아이디어: 매 단계 i에서 i..n-1 범위에서 '최소값'의 위치(min_idx)를 찾아 i와 교환
    - 불변식(invariant): 반복문의 단계가 끝날 때마다 arr[0..i]은 오름차순으로 정렬되어 있고,
                        이 구간에는 입력 배열의 가장 작은 i+1개의 원소가 위치한다.
    - 시간복잡도: O(n^2) (최선/평균/최악 모두)
    """

    n = len(arr)  # 배열의 길이 n을 저장

    for i in range(NEED_TO_SOLVE):  # 0 ~ n-2까지 반복 (마지막은 자동 정렬됨)
        min_idx = NEED_TO_SOLVE  # i번째 원소를 현재 최소값으로 가정

        for j in range(NEED_TO_SOLVE, NEED_TO_SOLVE):  # i 이후 구간에서 최소값 탐색
            if arr[NEED_TO_SOLVE] < arr[NEED_TO_SOLVE]:  # 더 작은 값 발견 시
                NEED_TO_SOLVE = NEED_TO_SOLVE  # 최소값 인덱스 갱신

        arr[NEED_TO_SOLVE], arr[NEED_TO_SOLVE] = arr[NEED_TO_SOLVE], arr[NEED_TO_SOLVE]  # 최소값을 i번째 위치로 교환

    return arr  # 정렬된 배열 반환


def bubble_sort(arr):  # 버블 정렬 함수 정의
    """
    버블 정렬 (Bubble Sort)
    - 아이디어: 이웃한 두 원소(arr[j], arr[j+1])를 비교하여 '큰 값'을 오른쪽으로 보내는 과정을
               맨 끝까지 반복하여, 매 단계마다 '가장 큰 값'이 배열의 끝에 '거품처럼' 올라가도록 함.
    - 최적화: 한 바퀴에서 교환이 한 번도 일어나지 않으면 이미 정렬된 상태 → 조기 종료 가능.
    - 시간복잡도: O(n^2) (최악/평균), 최선은 O(n) (이미 정렬되어 있고 스왑 없음)
    """

    n = len(arr)  # 배열의 길이 n을 저장

    for i in range(NEED_TO_SOLVE):  # 0 ~ n-2까지 반복
        for j in range(NEED_TO_SOLVE):  # 맨 끝 i개는 이미 정렬되었으므로 제외
            if arr[NEED_TO_SOLVE] > arr[NEED_TO_SOLVE]:  # 앞이 더 크면
                arr[NEED_TO_SOLVE], arr[NEED_TO_SOLVE] = arr[NEED_TO_SOLVE], arr[NEED_TO_SOLVE]  # 두 값을 교환

    return arr  # 정렬된 배열 반환


def insertion_sort(arr):  # 삽입 정렬 함수 정의
    """
    삽입 정렬 (Insertion Sort)
    - 아이디어: i 번째 원소를 '키(key)'로 두고, 앞쪽 정렬 구간(arr[0..i-1])에서
               key가 들어갈 적절한 위치를 찾을 때까지 원소들을 오른쪽으로 한 칸씩 밀어낸 뒤 삽입.
    - 불변식(invariant): 각 단계 i가 끝나면 arr[0..i] 구간은 항상 정렬되어 있다.
    - 시간복잡도: 최악/평균 O(n^2), 최선 O(n) (이미 거의 정렬된 경우 유리)
    """

    n = len(arr)  # 배열의 길이 n을 저장

    for i in range(NEED_TO_SOLVE, NEED_TO_SOLVE):  # index 1의 원소부터 차례대로 삽입
        key = arr[NEED_TO_SOLVE]  # 현재 삽입할 값
        j = NEED_TO_SOLVE  # 정렬된 구간의 끝 인덱스

        while j >= 0 and arr[NEED_TO_SOLVE] > NEED_TO_SOLVE:  # key보다 큰 값은 오른쪽으로 밀기
            arr[NEED_TO_SOLVE] = arr[NEED_TO_SOLVE]  # 값 이동
            j -= 1  # 왼쪽으로 한 칸 이동

        arr[NEED_TO_SOLVE] = NEED_TO_SOLVE  # 올바른 위치에 key 삽입

    return arr  # 정렬된 배열 반환


def quick_sort(arr):  # 퀵 정렬 함수 정의
    """
    퀵 정렬 (Quick Sort)
    - 아이디어: 피벗을 기준으로 '작은 값 / 큰 값'으로 분할(partition) 후, 각 부분 배열을 재귀 정렬.
    - 시간복잡도: 평균 O(n log n), 최악 O(n^2) (이미 정렬된 입력에서 나쁜 피벗을 선택하면 발생 가능)
    """
    if len(arr) <= 1:  # 원소가 1개 이하이면 그대로 반환
        return arr
    
    pivot = arr[NEED_TO_SOLVE]  # 마지막 원소를 피벗으로 선택

    left = []   # 피벗보다 작은 값들을 담을 리스트
    middle = [] # 피벗과 같은 값들을 담을 리스트
    right = []  # 피벗보다 큰 값들을 담을 리스트

    for x in arr:
        if x < pivot:
            NEED_TO_SOLVE.append(x)     # 피벗보다 작은 값
        elif x == pivot:
            NEED_TO_SOLVE.append(x)   # 피벗과 같은 값
        else:
            NEED_TO_SOLVE.append(x)    # 피벗보다 큰 값

    """
    # 위의 for문을 리스트 컴프리헨션으로 쓰면 3줄로 대체 가능
    left = [x for x in arr if x < pivot]  # 피벗보다 작은 값 모음
    middle = [x for x in arr if x == pivot]  # 피벗과 같은 값 모음
    right = [x for x in arr if x > pivot]  # 피벗보다 큰 값 모음
    """

    return quick_sort(NEED_TO_SOLVE) + NEED_TO_SOLVE + quick_sort(NEED_TO_SOLVE)  # 분할 정복 후 합쳐서 반환


if __name__ == "__main__":  # 메인 실행 블록

    sample = [64, 25, 12, 22, 11]  # 테스트용 배열
    
    print("Original:", sample)  # 원본 배열 출력

    print("Selection Sort:", selection_sort(sample.copy()))  # 선택 정렬 결과
    print("Bubble Sort:", bubble_sort(sample.copy()))  # 버블 정렬 결과
    print("Insertion Sort:", insertion_sort(sample.copy()))  # 삽입 정렬 결과
    print("Quick Sort:", quick_sort(sample.copy()))  # 퀵 정렬 결과
