# Write a Python program that computes the net amount of a bank account 
# based a transaction log from console input. The transaction log format is 
# shown as following: D 100 W 200 (Withdrawal is not allowed if balance is 
# going negative. Write functions for withdraw and deposit) D means deposit 
# while W means withdrawal. 
# Suppose the following input is supplied to the program: 
# D 300, D 300 , W 200, D 100 Then, the output should be: 500 

def process_transaction(transaction):
	parts = transaction.split()

	if len(parts)!=2:
		print("Invalid transaction format :",transaction)
		return 0
	action, amount_str = parts

	if not amount_str.isdigit():
		print("Ivalid amount in transaction :",transaction)
		return 0
	amount = int(amount_str)
	if action == 'D':
		return deposit(amount)
	elif action == 'W':
		return withdraw(amount)
	else:
		print("Invalid action in transaction :", transaction)
		return 0

def deposit (amount):
	global balance
	balance += amount
	return balance

def withdraw (amount):
	global balance
	if balance >= amount:
		balance-=amount

	else:
		print("Insufficient balance for withdrawal :",amount)
	
	return balance

if __name__=="__main__":
	transactions = input("Enter transaction log (e.g., D 300, D 300, W 200, D 100):").strip().split(',')

	balance = 0
	for transaction in transactions:
		balance = process_transaction(transaction.strip())
	
	print("Net amount in the account :",balance)


	
