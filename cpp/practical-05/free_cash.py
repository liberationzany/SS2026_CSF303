import sys

def solve():
    # Fast I/O
    input_data = sys.stdin.read().split()
    if not input_data:
        return
    
    n = int(input_data[0])
    
    # Create 1440 buckets (one for every minute of the day)
    # This is O(1) space because 1440 is a constant, regardless of N
    time_slots = [0] * 1440
    
    idx = 1
    for _ in range(n):
        h = int(input_data[idx])
        m = int(input_data[idx+1])
        idx += 2
        
        # Convert time to a single integer representing minutes from 00:00
        total_minutes = h * 60 + m
        time_slots[total_minutes] += 1
    
    # The answer is the highest number in any single bucket
    print(max(time_slots))

if __name__ == "__main__":
    solve()
