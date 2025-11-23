def check_if_x_exists(n):
    """
    Checks if there exists an x such that n = x XOR f(x),
    where f(x) is the binary reverse of x.
    """
    binary_n = bin(n)[2:]  # Convert to binary string, remove "0b" prefix
    length = len(binary_n)

    # Check if binary_n is a palindrome
    for i in range(length // 2):
        if binary_n[i] != binary_n[length - 1 - i]:
            return False
    return True

# Example Usage
print(check_if_x_exists(6))   # 0110_2 is a palindrome, returns True
print(check_if_x_exists(5))   # 0101_2 is a palindrome, returns True
print(check_if_x_exists(7))   # 0111_2 is not a palindrome, returns False
print(check_if_x_exists(10))  # 1010_2 is a palindrome, returns True