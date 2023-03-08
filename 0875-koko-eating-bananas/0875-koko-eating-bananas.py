class Solution:
    def minEatingSpeed(self, piles: List[int], h: int) -> int:
        """
        :type piles: List[int]
        :type h: int
        :rtype: int
        """
        # Binary search for the minimum value of k
        left, right = 1, max(piles)
        while left < right:
            mid = (left + right) // 2
            if sum((p - 1) // mid + 1 for p in piles) > h:
                left = mid + 1
            else:
                right = mid

        return left
