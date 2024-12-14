# // Write a Python program to store marks scored in subject “Fundamental of 
# Data Structure” by N students in the class. Write functions to compute 
# following: 
# a) The average score of class 
# b) Highest score and lowest score of class 
# c) Count of students who were absent for the test 
# d)Display mark with highest frequency 
def absentSC(listOfStud,numOfStud):
    count=0
    for i in range(numOfStud):
        if listOfStud[i]==0:
            count+=1
    return count

def maxMarks(listOfStud,numOfStud):
    max=0
    for i in range(numOfStud):
        if max < listOfStud[i]:
            max = listOfStud[i]
      
    return max

def minMarks(listOfStud,numOfStud):
    min=listOfStud[0]
    for i in range(numOfStud):
        if min > listOfStud[i]:
            min = listOfStud[i]
      
    return min

def largestMFreq(numOfStud,listOfStud):
    count=0
    check=maxMarks(listOfStud,numOfStud)
    for i in range (numOfStud):
        if check == listOfStud[i]:
            count+=1
    return count

def minMFreq(numOfStud,listOfStud):
    count=0
    check=minMarks(listOfStud,numOfStud)
    for i in range (numOfStud):
        if check == listOfStud[i]:
            count+=1
    return count
def averageOfMarks(listOfStud,numOfStud):
    sumInitialize = 0
    for i in range (numOfStud):
        sumInitialize+=listOfStud[i]

    return (sumInitialize/numOfStud)
        
#mainProg-->

loop=True
listOfStud=[]
numOfStud=int(input("Enter number of student:"))
count=1

for i in range(numOfStud):
    marks=int(input(f"Enter marks for student{count}:"))
    listOfStud.append(marks)
    count+=1

def showList():
    print("=========Select Your Choice==========\n(1) Enter 1 for Average \n(2) Enter 2 for Maximum \n(3) Enter3 for Minimum \n(4) Enter 4 for Largest Marks Frequency \n(5) Enter 5 for Minimum Marks Frrequency \n(6) Enter 6 for Count of Absent student \n(7) Enter 7 to create new list of marks \n(8) Enter 8 to exit")
    

showList()
while loop:
    choice = input("Enter your Choice:")
    if choice == "1":
        print("Average marks obtained by Student is: ",averageOfMarks(listOfStud,numOfStud))

    elif choice == '2':
        print("Maximum marks obtained by Student is: ",maxMarks(listOfStud,numOfStud))

    elif choice == '3':
        print("Minimum marks obtained by Student is: ",minMarks(listOfStud,numOfStud))

    elif choice == '4':
        print(maxMarks(listOfStud,numOfStud)," is largest marks and its frequency is: ",largestMFreq(numOfStud,listOfStud))

    elif choice == '5':
        print(minMarks(listOfStud,numOfStud),"is minimum marks and its frequency is: ",minMFreq(numOfStud,listOfStud))

    elif choice == '6':
        print("Number of Absent student are: ",absentSC(listOfStud,numOfStud))

    elif choice == '7':
        print("New List Created")
        listOfStudent=[]
        numOfStud = int(input("Enter number of Student :"))
        count=1

        for i in range(numOfStud):
            marks=int(input(f"Enter marks for student{count}:"))
            listOfStud.append(marks)
            count+=1

        print("=========Select Your Choice==========\n (1) Enter 1 for Average \n(2) Enter 2 for Maximum \n(3) Enter3 for Minimum \n(4) Enter 4 for Largest Marks Frequency \n(5) Enter 5 for Minimum Marks Frrequency \n(6) Enter 6 for Count of Absent student \n(7) Enter 7 to create new list of marks \n(8) Enter 8 to exit")
    elif choice == '8':
        loop=False

    else:
        print("You entered wrong choice try again")

        