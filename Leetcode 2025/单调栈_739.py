class Solution:
    def dailyTemperatures(self, temperatures: list[int]) -> list[int]:
        n = len(temperatures)
        answer = [0] * n
        left, right = 0, 1
        while left < n - 1:
            if temperatures[right] > temperatures[left]:
                answer[left] = right - left
                left += 1
                right = left + 1
            else:
                right += 1
                if right == n:
                    left += 1
                    right = left + 1
        return answer


class Solution:
    def dailyTemperatures(self, temperatures: list[int]) -> list[int]:
        n = len(temperatures)
        # 初始化一个长度为 n 的数组，用于存储每个位置需要等待的天数，初始值都为 0
        days_to_wait = [0] * n
        # 初始化一个单调栈，用于存储温度的下标
        mono_stack = []

        for i in range(n):
            # 当栈不为空且当前温度大于栈顶元素所代表的温度时
            while len(mono_stack) > 0:
                top_index = mono_stack[-1]
                if temperatures[i] > temperatures[top_index]:
                    # 计算等待天数，即当前下标 i 减去栈顶元素的下标
                    days_to_wait[top_index] = i - top_index
                    # 弹出栈顶元素，因为已经找到了它右边第一个比它大的温度
                    mono_stack.pop()
                else:
                    # 如果当前温度不大于栈顶元素所代表的温度，说明还没找到更大的温度，结束循环
                    break
            # 将当前温度的下标 i 压入栈中
            mono_stack.append(i)

        return days_to_wait