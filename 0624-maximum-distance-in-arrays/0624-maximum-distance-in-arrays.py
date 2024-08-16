class Solution:
    def maxDistance(self, arrays: List[List[int]]) -> int:
        min_val, max_val = float('inf'), float('-inf')
        min_index, max_index = -1, -1

        for i, arr in enumerate(arrays):
            if arr[0] < min_val:
                min_val = arr[0]
                min_index = i
            if arr[-1] > max_val:
                max_val = arr[-1]
                max_index = i

        if min_index != max_index:
            return max_val - min_val

        second_max_val, second_min_val = float('-inf'), float('inf')

        for i, arr in enumerate(arrays):
            if i != min_index:
                second_min_val = min(second_min_val, arr[0])
            if i != max_index:
                second_max_val = max(second_max_val, arr[-1])

        return max(max_val - second_min_val, second_max_val - min_val)
            