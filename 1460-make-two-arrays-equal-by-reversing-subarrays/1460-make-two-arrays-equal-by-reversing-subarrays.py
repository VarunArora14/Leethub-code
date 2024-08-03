# since we can take any arr and any sub array and then reverse any part of it, it basically means
# we can do any kind of modification to arr in terms of shuffling/sorting
# what that means that if we sort both of them and compare, they should come out to be same

class Solution:
    def canBeEqual(self, target: List[int], arr: List[int]) -> bool:
        target.sort()
        arr.sort()
        return target==arr