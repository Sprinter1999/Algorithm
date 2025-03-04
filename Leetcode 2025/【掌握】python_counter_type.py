from collections import Counter

def count_and_sort_characters(input_string):
    # 使用 Counter 统计字符频次
    char_count = Counter(input_string)
    print(type(char_count))

    # 按照字符大小排序
    sorted_char_count = sorted(char_count.items())

    return sorted_char_count

# 测试字符串
test_string = "hello world"
result = count_and_sort_characters(test_string)

# 输出结果
for char, count in result:
    print(f"字符 '{char}' 出现的频次: {count}")


# from collections import Counter

# 示例列表，每个元素是一个单词
word_list = ["apple", "banana", "apple", "cherry", "banana", "apple"]

# 使用 Counter 统计单词出现的频次
word_count = Counter(word_list)

# 输出结果
for word, count in word_count.items():
    print(f"单词 '{word}' 出现的频次: {count}")