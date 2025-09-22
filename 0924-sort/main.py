import time
from answer_official import selection_sort, bubble_sort, insertion_sort, quick_sort, merge_sort

sample = [64, 25, 12, 22, 11]

print("Original:", sample)

# Selection Sort
start = time.time()
print("Selection Sort:", selection_sort(sample.copy()))
end = time.time()
print(f"Selection Sort Time: {end - start:.6f} sec")

# Bubble Sort
start = time.time()
print("Bubble Sort:", bubble_sort(sample.copy()))
end = time.time()
print(f"Bubble Sort Time: {end - start:.6f} sec")

# Insertion Sort
start = time.time()
print("Insertion Sort:", insertion_sort(sample.copy()))
end = time.time()
print(f"Insertion Sort Time: {end - start:.6f} sec")

# Quick Sort
start = time.time()
print("Quick Sort:", quick_sort(sample.copy()))
end = time.time()
print(f"Quick Sort Time: {end - start:.6f} sec")

# Merge Sort
start = time.time()
print("Merge Sort:", merge_sort(sample.copy()))
end = time.time()
print(f"Merge Sort Time: {end - start:.6f} sec")
