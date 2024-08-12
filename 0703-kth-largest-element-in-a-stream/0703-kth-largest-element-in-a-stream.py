import heapq

class KthLargest:

    def __init__(self, k: int, nums: List[int]):
        self.nums = []
        for num in nums:
            heapq.heappush(self.nums, num)
        self.k=k

    def add(self, val: int) -> int:
        heapq.heappush(self.nums, val)
        while len(self.nums)>self.k:
            heapq.heappop(self.nums)
        kth_element = heapq.heappop(self.nums)
        heapq.heappush(self.nums,kth_element)
        return kth_element


# Your KthLargest object will be instantiated and called as such:
# obj = KthLargest(k, nums)
# param_1 = obj.add(val)