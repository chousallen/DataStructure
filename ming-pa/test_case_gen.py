# Use numpy to generate random matrices and calculate the result

import numpy as np

# Generate 100 random 2x2 matrices with elements between 1 and 10
np.random.seed(0)  # For reproducibility
random_matrices_np = [np.random.randint(1, 11, (2, 2))%2147483648 for _ in range(10)]

# Function to multiply a chain of matrices using numpy
def multiply_chain_np(matrices):
    result = matrices[0]
    for matrix in matrices[1:]:
        result = np.dot(result, matrix)
    return result

# Calculate the final result for the chain of 100 matrices
final_result_np = multiply_chain_np(random_matrices_np)

# Format the input sequence as a nested parenthesized string
def format_nested_multiplication_np(matrices):
    expression = f"[{','.join(map(str, matrices[0].flatten().tolist()))}]"
    for matrix in matrices[1:]:
        matrix_flat = ','.join(map(str, matrix.flatten().tolist()))
        expression = f"({expression}*[{matrix_flat}])"
    return expression

nested_expression_np = format_nested_multiplication_np(random_matrices_np)
#print(nested_expression_np)
print(final_result_np)

