
def valid_parentheses(s: str) -> bool:
    # WRITE YOUR BRILLIANT CODE HERE
    paren_pairs = {'(': ')', '[': ']', '{': '}'}
    stack = []
    
    if len(s) % 2 != 0:
        return False

    for char in s:
        if char not in "()[]{}":
            return False

        if char in paren_pairs:
            stack.append(char)
        else:
            if char == paren_pairs[stack[-1]]:
                stack.pop()
            else:
                return False
                
    return True

# Comprehensive testing suite
if __name__ == "__main__":
    # Basic valid cases
    print(valid_parentheses("()"))  # True
    print(valid_parentheses("[]"))  # True
    print(valid_parentheses("{}"))  # True
    print("=====================")

    # Nested valid cases
    print(valid_parentheses("()[]{}"))  # True
    print(valid_parentheses("({[]})"))  # True
    print(valid_parentheses("[({})]"))  # True
    print(valid_parentheses("((()))"))  # True
    print(valid_parentheses("[()]"))  # True
    print("=====================")

    # Invalid cases - mismatched
    print(valid_parentheses("("))  # False
    print(valid_parentheses(")"))  # False
    print(valid_parentheses("(]"))  # False
    print(valid_parentheses("([)]"))  # False
    print("=====================")
    
    # Edge cases
    print(valid_parentheses(""))  # True
    print(valid_parentheses("()()"))  # True
    print(valid_parentheses("(())"))  # True
    print(valid_parentheses("(()"))  # False
    print(valid_parentheses("())"))  # False
    print("=====================")
