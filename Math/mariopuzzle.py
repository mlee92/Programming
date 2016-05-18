'''
May 16th, 2016
Michael Lee 

Based on Mario Solano's Plus Uno "marioqwe.qithub.io"

starting with 
1 1 1 
1 0 1 
1 1 1 

at level 1 

make every entry equal to the level by clicking 2 entries
the second entry will be incremented by the first entry
the first entry will be incremented by 1 

each entry must be less than or equal to the level 

PROB: 
Can every level N be completed? 

MATH:
The function F(v, i, j) = [v_1, v_2, ... v_i + 1, ... v_j + v_i, ..., v_n] is given for a vector v and integers i and j

A vector v is "solved" for an integer N, if by T iterations of F(v, i_t, j_t) for any given combination (i , j) at iteration t, each entry in v is equal to N

ex: 
the board 
1 1
1 0 can be solved for N = 2 in 3 iterations
[1, 1, 1, 0]
F(v, 1, 2) = [2, 2, 1, 0]
F(v, 4, 1) = [2, 2, 1, 1]
F(v, 3, 4) = [2, 2, 2, 2]

for (i, j) =[1, 2] [4, 1] [3, 4]
and 
v= [3, 1, 4, 1, 5]
F(v, 2, 3) = [3, 1 + 1, 4 + 1, 1, 5] = [3, 2, 5, 1, 5]
''' 
#init_board = [1, 1, 1, 1, 0, 1, 1, 1, 1]

#Special addition rules, v_i = v_i + 1, v_j = v_i + v_j 
def add(arr, pos1, pos2):
	buf = [term for term in arr]

	buf[pos2] += buf[pos1]
	buf[pos1] += 1

	return buf

#checks if each term is less than or equal to the level 
def validGame(board, level):
	go = True 
	for term in board:
		go &= (term <= level)
	return go 

#Checks if each term is equal to level, i.e. the game is finished
def finishedGame(board, level):
	go = True
	for term in board:
		go &= term == level
	return go 

#Creates hash string for a particular configuration
def boardToStr(board):
	buf = [term for term in board]
	buf = sorted(buf)
	S = ""
	for i in buf:
		S += str(i)
	return S

checked_boards = []
#Creates a list of all unchecked and valid possible next moves 

def generateBoards(board, level):
	boards = [] 
	for i in range(0, len(board)):
		for j in range(0, len(board)):
			if(i != j):
				dummy_board = add(board, i, j)
				valid = validGame(dummy_board, level)
				checked = boardToStr(dummy_board) in checked_boards
				if(valid and not checked):
					checked_boards.append(boardToStr(dummy_board))
					boards.append(dummy_board)
	return boards

#Play the game
def simulate(init, level):
	valid = validGame(init, level)

	#result = finishedGame(init, level) 
	result = False
	if(valid):
		won = finishedGame(init, level)
		if(won):
			result |= True
		else:
			result |= False 
			boards = generateBoards(init, level)
			for board in boards:
				result |= simulate(board, level)
	else:
		result |= False 
	return result 

def START1():
	init_board = [int(term) for term in ((str(raw_input()).split(' ')))]
	checked_boards.append(boardToStr(init_board))
	level = int(raw_input())

	print(simulate(init_board, level))

def START2():

	init_board = [int(term) for term in ((str(raw_input()).split(' ')))]
	checked_boards.append(boardToStr(init_board))
	#level = int(raw_input())
	level = 1

	while(simulate(init_board, level) == True):
		del checked_boards [1:len(checked_boards)]
		print(level)
		level += 1 

START1()
