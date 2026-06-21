
import time

num = int(input("Enter a number: "))
starttime = time.perf_counter()

text = "this is a test string"
# method 1
char_ls = [0] * 26
for c in text:
    if c != " ":
        index = ord(c) - 97
        char_ls[index] += 1

print("Method 1 results:")
for i in range(97, 123):
    print(f"{chr(i)}: {char_ls[i-97]}")

# print("Method 1 results:\n", char_ls)
# method 2
char_dict = {}
for c in text:
    if c != " ":
        char_dict[c] = char_dict.get(c, 0) + 1
print("Method 2 results:\n")
for char, count in char_dict.items():
    print(f"{char}: {count}")

endtime = time.perf_counter()
print(f"Took: {(endtime-starttime)}")