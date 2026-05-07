class Solution:
    def totalFruit(self, fruits):
        left = 0
        max_fruits = 0
        basket = {}

        for right in range(len(fruits)):
            fruit = fruits[right]

            basket[fruit] = basket.get(fruit, 0) + 1

            while len(basket) > 2:
                left_fruit = fruits[left]
                basket[left_fruit] -= 1

                if basket[left_fruit] == 0:
                    del basket[left_fruit]

                left += 1

            max_fruits = max(max_fruits, right - left + 1)

        return max_fruits