from collections import Counter

# Read input
s1 = input()
s2 = input()

# Count letters only in s1
count_s1 = Counter(c for c in s1 if c.isalpha())

# Count letters only in s2
count_s2 = Counter(c for c in s2 if c.isalpha())

# Check if s1 has enough of each required letter
for ch, need in count_s2.items():
    if count_s1[ch] < need:
        print("NO")
        break
else:
    print("YES")