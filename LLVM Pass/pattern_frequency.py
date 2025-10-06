from collections import defaultdict, Counter
from typing import List, Dict, Tuple

def parse_trace_log(filename: str) -> List[Tuple[str, str]]:
    trace = []
    
    with open(filename, 'r') as f:
        for line in f:
            [user, operand] = line.split('<-')
            user = user.strip()
            operand = operand.strip()
                
            trace.append((user, operand))
    
    return trace

def count_patterns_occurences(trace: List[Tuple[str, str]], min_length: int = 1, max_length: int = 5) -> Dict[Tuple, int]:
    patterns = Counter()
    
    for pattern_length in range(min_length, max_length + 1):
        for i in range(len(trace) - pattern_length + 1):
            pattern = tuple(trace[i:i + pattern_length])
            patterns[pattern] += 1
                
    return patterns

def head_of_patterns_by_frequency(patterns: Dict[Tuple, int], top_n: int = 20) -> Tuple[Dict[int, List[Tuple]], List[Tuple]]:
    patterns_by_length = defaultdict(list)
    all_patterns = list()

    for pattern, count in patterns.items():
        pattern_length = len(pattern)
        patterns_by_length[pattern_length].append((pattern, count))
        all_patterns.append((pattern, count))
    
    for length in patterns_by_length:
        patterns_by_length[length].sort(key=lambda x: x[1], reverse=True)
        patterns_by_length[length] = patterns_by_length[length][:top_n]
    
    all_patterns.sort(key=lambda x: x[1], reverse=True)
    all_patterns = all_patterns[:top_n]
    return patterns_by_length, all_patterns

def print_detailed_statistics(patterns_by_length: Dict[int, List[Tuple]], all_patterns: List[Tuple], top_n: int = 20):
    total_patterns = sum(count for _, count in all_patterns)
    print(f"\nВсе паттерны(топ-{top_n}, всего вхождений: {total_patterns}):")
    print("-" * 60)
    for i, (pattern, count) in enumerate(all_patterns, 1):
        frequency_percent = (count / total_patterns * 100)
        print(f"{i:2d}. Частота: {count:4d} ({frequency_percent:5.1f}%)")
        for j, instruction in enumerate(pattern):
            print(f"    {j+1}. {instruction}")
        print()

    for length in sorted(patterns_by_length.keys()):
        patterns_list = patterns_by_length[length]
            
        total_patterns = sum(count for _, count in patterns_list)
        print(f"\nПаттерны длины {length} (топ-{top_n}, всего вхождений: {total_patterns}):")
        print("-" * 60)
        
        for i, (pattern, count) in enumerate(patterns_list, 1):
            frequency_percent = (count / total_patterns * 100)
            print(f"{i:2d}. Частота: {count:4d} ({frequency_percent:5.1f}%)")
            for j, instruction in enumerate(pattern):
                print(f"    {j+1}. {instruction}")
            print()

def main():
    trace = parse_trace_log("trace.txt")
    full_patterns = count_patterns_occurences(trace, min_length=1, max_length=5)
    patterns_by_length, all_patterns = head_of_patterns_by_frequency(full_patterns, top_n=10)

    print_detailed_statistics(patterns_by_length, all_patterns, top_n=10)

    print("\nСВОДНАЯ СТАТИСТИКА:")
    print("=" * 50)
    print(f"Всего пар инструкций в трассе: {len(trace)}")
    print(f"Уникальных полных паттернов: {len(full_patterns)}")
if __name__ == "__main__":
    main()