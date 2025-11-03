# answer_official.py

def merge_sort(arr):  # 병합 정렬 함수 정의
    """
    병합 정렬 (Merge Sort) - 비(非)제자리(Out-of-place) 버전
    - 아이디어: 배열을 절반씩 분할하여 각각 정렬한 뒤, 두 정렬 결과를 병합(merge).
    - 시간복잡도: O(n log n) (분할 log n 단계 × 각 단계에서 O(n) 병합)
    - 주의: 입력 배열을 변경하지 않고, '새로운 리스트'를 반환한다.
    """

    if len(arr) <= 1:  # 원소가 1개 이하이면 이미 정렬된 상태
        return arr

    mid = len(arr) // 2  # 중간 인덱스
    left = merge_sort(arr[:mid])  # 왼쪽 절반 재귀 정렬
    right = merge_sort(arr[mid:])  # 오른쪽 절반 재귀 정렬

    return merge(left, right)  # 병합 후 반환


def merge(left, right):  # 병합 함수 정의
    """
    병합 정렬의 병합 단계(merge)
    - 두 정렬된 리스트 left, right를 받아 하나의 정렬된 리스트로 병합하여 반환.
    - 시간복잡도: O(len(left) + len(right))
    """

    result = []  # 결과 리스트
    i = j = 0  # left와 right의 인덱스 초기화

    while i < len(left) and j < len(right):  # 두 리스트 모두 원소가 남아있는 동안

        if left[i] <= right[j]:  # left 원소가 더 작거나 같으면
            result.append(left[i])  # left 원소 추가
            i += 1  # left 인덱스 증가

        else:
            result.append(right[j])  # right 원소 추가
            j += 1  # right 인덱스 증가

    result.extend(left[i:])  # left 잔여 원소 추가
    result.extend(right[j:])  # right 잔여 원소 추가

    return result  # 병합된 리스트 반환


if __name__ == "__main__":  # 메인 실행 블록

    sample = [64, 25, 12, 22, 11]  # 테스트용 배열

    print("Original:", sample)  # 원본 배열 출력

    print("Merge Sort:", merge_sort(sample.copy()))  # 병합 정렬 결과
