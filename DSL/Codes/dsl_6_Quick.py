# Write a python program to store first year percentage of students in array. 
# Write function for sorting array of floating point numbers in ascending order 
# using quick sort and display top five scores. 

def quick_sort(arr):
    """
    Function to perform Quick Sort on the array.
    """
    def partition(low, high):
        pivot = arr[high]
        i = low - 1
        for j in range(low, high):
            if arr[j] <= pivot:
                i += 1
                arr[i], arr[j] = arr[j], arr[i]
        arr[i + 1], arr[high] = arr[high], arr[i + 1]
        return i + 1

    def quick_sort_recursive(low, high):
        if low < high:
            pi = partition(low, high)
            quick_sort_recursive(low, pi - 1)
            quick_sort_recursive(pi + 1, high)

    quick_sort_recursive(0, len(arr) - 1)

def display_top_five(arr):
    """
    Function to sort the array and print the top five scores.
    """
    # Sort the array
    quick_sort(arr)
    
    # Display the top five scores
    top_five = arr[-5:] #if len(arr) >= 5 else arr
    print("Top Five Scores:")
    for score in top_five:
        print(f"{score:.2f}")

def main():
    # Example array of first-year percentages
    percentages = [
        85.5, 92.3, 78.6, 89.4, 90.1, 
        94.7, 81.2, 79.9, 77.3, 95.5
    ]

    print("Original Percentages:")
    for p in percentages:
        print(f"{p:.2f}")

    display_top_five(percentages)

if __name__ == "__main__":
    main()

# OR

def quickSort(arr):
    def partition(low, high):
        pivot = arr[high]

        i = low - 1
        for j in range (low, high):
            if arr[j] <= pivot:
                i += 1
                arr[i], arr[j] = arr[j], arr[i]

        arr[i + 1], arr[high] = arr[high], arr[i + 1]
        return i + 1
    
    def quickSortRecursive (low, high):
        if low < high:
            pi = partition(low, high)
            quickSortRecursive(low, pi - 1)
            quickSortRecursive(pi + 1, high)

    quickSortRecursive(0, len(arr) - 1)

def dispTopFive (arr):
    quickSort(arr)
    topFive = arr[-5: ] if len(arr) >= 5 else arr
    print("Top Five Scores:")
    for score in reversed(topFive):
        print(f"{score:.2f}")

def main():
    percentages = []
    size = int(input("ENter size of arr:"))
    for _ in range (size):
        ele = float(input("ENter Elements:"))
        percentages.append(ele)

    print("Original Percentages:")
    for p in percentages:
        print(f"{p:.2f}")

    dispTopFive(percentages)

if __name__ == "__main__":
            main()
