# Write a Python program to store first year percentage of students in array. 
# Write function for sorting array of floating point numbers in ascending order 
# using 
# a) Selection Sort 
# b) Bubble sort and display top five scores

def selection_sort(arr):
    """
    Sorts an array of floating point numbers in ascending order using Selection Sort.
    """
    n = len(arr)
    for i in range(n):
        min_idx = i
        for j in range(i+1, n):
            if arr[j] < arr[min_idx]:
                min_idx = j
        arr[i], arr[min_idx] = arr[min_idx], arr[i]
    return arr

def bubble_sort(arr):
    """
    Sorts an array of floating point numbers in ascending order using Bubble Sort.
    """
    n = len(arr)
    for i in range(n):
        for j in range(0, n-i-1):
            if arr[j] > arr[j+1]:
                arr[j], arr[j+1] = arr[j+1], arr[j]
    return arr

def display_top_five_scores(arr):
    """
    Displays the top five scores from the sorted array.
    """
    top_five = arr[-5:] if len(arr) >= 5 else arr
    print("Top five scores:")
    for score in top_five:
        print(f"{score:.2f}")

def display_menu():
    """
    Displays the menu options to the user.
    """
    print("\nMenu:")
    print("1. Enter student percentages")
    print("2. Sort and display using Selection Sort")
    print("3. Sort and display using Bubble Sort")
    print("4. Exit")

def main():
    percentages = []
    
    while True:
        display_menu()
        choice = input("Enter your choice (1-4): ").strip()
        
        if choice == '1':
            # Enter student percentages
            try:
                num_students = int(input("Enter the number of students: "))
                percentages = []
                for i in range(num_students):
                    percentage = float(input(f"Enter percentage for student {i+1}: "))
                    percentages.append(percentage)
                print("\nPercentages entered successfully.")
            except ValueError:
                print("Invalid input. Please enter numeric values.")
        
        elif choice == '2':
            # Sort using Selection Sort and display top five scores
            if not percentages:
                print("No percentages entered yet.")
                continue
            sorted_percentages = selection_sort(percentages.copy())
            print("\nSorted percentages (Selection Sort):")
            print(sorted_percentages)
            display_top_five_scores(sorted_percentages)
        
        elif choice == '3':
            # Sort using Bubble Sort and display top five scores
            if not percentages:
                print("No percentages entered yet.")
                continue
            sorted_percentages = bubble_sort(percentages.copy())
            print("\nSorted percentages (Bubble Sort):")
            print(sorted_percentages)
            display_top_five_scores(sorted_percentages)
        
        elif choice == '4':
            # Exit
            print("Exiting program.")
            break
        
        else:
            print("Invalid choice. Please select a valid option.")

if __name__ == "__main__":
    main()

# OR

# def selection_sort(arr):
# 	""" Sorts an array of floating point numbers in asending order using Selection Sort. """
# 	n = len(arr)
# 	for i in range (n):
# 		#Find the Minimum element in remaning unsorted array
# 		min_idx = i
# 		for j in range (i+1,n):
# 			if arr[j] < arr[min_idx]:	
# 				min_idx = j
# 			#swap the found minimum element with the first element
# 			arr[i], arr[min_idx] = arr [min_idx], arr[i]
# 	return arr

# def bubble_sort (arr):
# 	""" SORTS AN ARRAY  of floating point numbers in ASending order using bubble sort. """
# 	n = len(arr)
# 	for i in range (n):
# 		for j in range(0,n-i-1):
# 			if arr[j] > arr[j+1]:
# 				# swap if the element found is greater than the next element.
# 				arr[j], arr[j+1] = arr[j+1],arr[j]
# 	return arr

# def display_top_five_scores(arr):
# 	"""Display the top five scores from the sorted array."""
	
	
# 	#Ensure the array has at least five elements
# 	top_five = arr[-5:]if len(arr)>=5 else arr
# 	print ("Top five scores.")
	
# 	for score in top_five:
# 		print(f"{score:.2f}")

# def main():
# 	#Example intput array of percentages (floating point numbers)
	
# 	percentages = [6.99, 8.55, 7.44, 9.91, 9.32, 10.00, 8.04, 4.6, 5.5]

# 	print ("Original percentages:")
# 	print (percentages)
	
# 	#Sorting and displaying top five scores usig Selection Sort
# 	sorted_percentages_selection = selection_sort(percentages.copy())
# 	print("\n Sorted percentages (Selection Sort):")
# 	print(sorted_percentages_selection)
# 	display_top_five_scores(sorted_percentages_selection)

# 	#Sorting and displaying top five scores using Bubble Sort
# 	sorted_percentages_bubble = bubble_sort(percentages.copy())
# 	print("\n Sorted percentages (Bubble Sort):")
# 	print(sorted_percentages_bubble)
# 	display_top_five_scores(sorted_percentages_bubble)

# if __name__=="__main__":
# 	main()

			
	































































