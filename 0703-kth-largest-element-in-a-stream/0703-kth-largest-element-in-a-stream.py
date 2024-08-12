import heapq

class KthLargest:

    def __init__(self, k: int, nums: List[int]):
        self.k = k
        self.heap = nums
        heapq.heapify(self.heap) # heapify rather than push each time
        while len(self.heap) > k:
            heapq.heappop(self.heap)
        
    def add(self, val: int) -> int:
        if len(self.heap) < self.k or val > self.heap[0]:
            heapq.heappush(self.heap, val) # add to heap only when new element is bigger than smallest element at heap[0]
        if len(self.heap) > self.k:
            heapq.heappop(self.heap)
        return self.heap[0]

# Your KthLargest object will be instantiated and called as such:
# obj = KthLargest(k, nums)
# param_1 = obj.add(val)


# after heapify, the array[0] will have the smallest element and the print of whole array will be in heap format