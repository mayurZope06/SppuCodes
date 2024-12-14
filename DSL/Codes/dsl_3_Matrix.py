# Write a Python program to compute following computation on matrix: 
# a) Addition of two matrices  
# B) Subtraction of two matrices 
# c) Multiplication of two matrices  
# d) Transpose of a matrix 

def matrix_addition(A,B):
	
	if len(A)!= len(B) or len(A[0]) != len(B[0]):
		raise ValueError("Matrices must be of the same size to add them.")

	rows = len (A)
	cols = len (A[0])
	result = [[0] * cols for _ in range (rows)]

	for i in range (rows):
		for j in range (cols):
			result [i] [j] = A [i] [j] + B [i] [j]
	
	return result

def matrix_subtraction (A,B):
	
	if len(A) != len(B) or len(A[0]) != len (B[0]):
		raise ValueError(" Matrices must be of the same size to subtract them.")

	rows = len(A)
	cols = len (A[0])
	result = [[0] * cols for _ in range (rows)]

	for i in range(rows):
		for j in range (cols):
			result [i] [j] = A [i] [j] - B [i] [j]

	return result

def matrix_multiplication(A,B):
	
	if len(A[0]) != len(B):
		raise ValueError ("Number of columns in A must be equal to number of rows  in B for multiplication")

	rows_A = len(A)
	cols_A = len(A[0])
	cols_B = len(B[0])
	result = [[0] * cols_B for _ in range (rows_A)]

	for i in range (rows_A):
		for j in range (cols_B):
			for k in range (cols_A):
				result [i][j] += A [i][k] * B [k][i]

	return result

def matrix_transpose(A):
	
	rows = len (A)
	cols = len (A[0])
	transposed = [[0] * rows for _ in range (cols)]

	for i in range (rows):
		for j in range (cols):
			transposed [j][i] = A [i][j]

	return transposed




def display_matrix (matrix):
	for row in matrix:
		print(row)

def read_matrix():
	rows = int(input("Enter the number of rows: "))
	cols=int(input("Enter the number of columns:" ))
	
	matrix = []
	print("Enter the elements row-wise: ")

	for i in range (rows):
		row = []
		for j in range (cols):
			element = int(input(f"Enter element [{i+1}][{j+1}]:"))
			row.append(element)
		matrix.append(row)

	return  matrix

while True:
	print("\n Menu:")
	print("1.Addition of two matrices")
	print("2.Subtraction of two matrices")
	print("3.Multiplication of two matrices")
	print("4.Transpose of a matrix")
	print("5.Exit")

	choice = input("Enter your choice (1-5):")

	if choice == '1':
		print("\nEnter the first matrix:")
		matrix1 = read_matrix()
		print("\nEnter the second matrix:")
		matrix2 = read_matrix()

		try:
			result = matrix_addition(matrix1, matrix2)
			print("\nResult of addition:")
			display_matrix(result)
	
		except ValueError as e:
			print("Error.",e)

	elif choice == '2':
		print("\nEnter the first matrix:")
		matrix1 = read_matrix()
		print("\nEnter the second matrix:")
		matrix2 = read_matrix()

		try:
			result = matrix_subtraction(matrix1, matrix2)
			print("\nResult of subtraction:")
			display_matrix(result)
		
		except ValueError as e:
			print("Error.",e)

	elif choice == '3':
		print("\nEnter the first matrix:")
		matrix1 = read_matrix()
		print("\nEnter the second matrix:")
		matrix2 = read_matrix()

		try:
			result = matrix_multiplication(matrix1, matrix2)
			print("\nResult of multiplition:")
			display_matrix(result)
		
		except ValueError as e:
			print("Error.",e)

	elif choice == '4':
		print("\nEnter the matrix to transpose:")
		matrix = read_matrix()
		result = matrix_transpose(matrix)
		print("\nTranspose of matrix:")
		display_matrix(result)
		
	elif choice == '5':
		print("\nExiting the program. Goodbye!")
		break
		

	else:
		print("Invalid choice. Please enter a number between 1 and 5.")

			
# OR
def matrix_addition(A, B):
    """ Function to perform matrix addition """
    if len(A) != len(B) or len(A[0]) != len(B[0]):
        raise ValueError("Matrices must be of the same size to add them.")
    
    rows = len(A)
    cols = len(A[0])
    result = [[0] * cols for _ in range(rows)]
    
    for i in range(rows):
        for j in range(cols):
            result[i][j] = A[i][j] + B[i][j]
    
    return result

def matrix_subtraction(A, B):
    """ Function to perform matrix subtraction """
    if len(A) != len(B) or len(A[0]) != len(B[0]):
        raise ValueError("Matrices must be of the same size to subtract them.")
    
    rows = len(A)
    cols = len(A[0])
    result = [[0] * cols for _ in range(rows)]
    
    for i in range(rows):
        for j in range(cols):
            result[i][j] = A[i][j] - B[i][j]
    
    return result

def matrix_multiplication(A, B):
    """ Function to perform matrix multiplication """
    if len(A[0]) != len(B):
        raise ValueError("Number of columns in A must be equal to number of rows in B for multiplication.")
    
    rows_A = len(A)
    cols_A = len(A[0])
    cols_B = len(B[0])
    
    result = [[0] * cols_B for _ in range(rows_A)]
    
    for i in range(rows_A):
        for j in range(cols_B):
            for k in range(cols_A):
                result[i][j] += A[i][k] * B[k][j]
    
    return result

def matrix_transpose(A):
    """ Function to compute transpose of a matrix """
    rows = len(A)
    cols = len(A[0])
    transposed = [[0] * rows for _ in range(cols)]
    
    for i in range(rows):
        for j in range(cols):
            transposed[j][i] = A[i][j]
    
    return transposed

# Function to display matrix
def display_matrix(matrix):
    for row in matrix:
        print(row)

# Function to read matrix from user input
def read_matrix():
    rows = int(input("Enter the number of rows: "))
    cols = int(input("Enter the number of columns: "))
    
    matrix = []
    print("Enter the elements row-wise:")
    for i in range(rows):
        row = []
        for j in range(cols):
            element = int(input(f"Enter element [{i+1}][{j+1}]: "))
            row.append(element)
        matrix.append(row)
    
    return matrix

# Main program
while True:
    print("\nMenu:")
    print("1. Addition of two matrices")
    print("2. Subtraction of two matrices")
    print("3. Multiplication of two matrices")
    print("4. Transpose of a matrix")
    print("5. Exit")
    
    choice = input("Enter your choice (1-5): ")
    
    if choice == '1':
        print("\nEnter the first matrix:")
        matrix1 = read_matrix()
        print("\nEnter the second matrix:")
        matrix2 = read_matrix()
        
        try:
            result = matrix_addition(matrix1, matrix2)
            print("\nResult of addition:")
            display_matrix(result)
        except ValueError as e:
            print("Error:", e)
    
    elif choice == '2':
        print("\nEnter the first matrix:")
        matrix1 = read_matrix()
        print("\nEnter the second matrix:")
        matrix2 = read_matrix()
        
        try:
            result = matrix_subtraction(matrix1, matrix2)
            print("\nResult of subtraction:")
            display_matrix(result)
        except ValueError as e:
            print("Error:", e)
    
    elif choice == '3':
        print("\nEnter the first matrix:")
        matrix1 = read_matrix()
        print("\nEnter the second matrix:")
        matrix2 = read_matrix()
        
        try:
            result = matrix_multiplication(matrix1, matrix2)
            print("\nResult of multiplication:")
            display_matrix(result)
        except ValueError as e:
            print("Error:", e)
    
    elif choice == '4':
        print("\nEnter the matrix to transpose:")
        matrix = read_matrix()
        
        result = matrix_transpose(matrix)
        print("\nTranspose of matrix:")
        display_matrix(result)
    
    elif choice == '5':
        print("Exiting the program. Goodbye!")
        break
    
    else:
        print("Invalid choice. Please enter a number between 1 and 5.")
