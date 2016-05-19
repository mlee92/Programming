
#FIB: Wascally Wabbits

def getNumRabbits(N, K): # recursive after n months, each producing k 
	pop = {0:0, 1: 1, 2:1}
	if(N in pop):
		print(pop[N])
		return pop[N]
	else:
		pop[N] = getNumRabbits(N - 1, K) + K * getNumRabbits(N - 2, K)
		return pop[N]

def getNumRabbits(N, K): # iterative
	pop = [1, 1]
	for n in range(2, N):
		temp = pop[n - 1] + K * pop[n - 2]
		pop.append(temp)
	return pop[N - 1]

#FIBD Wabbit Season

def dyingRabbits(N, M):
	rabbits = [0] * M
	rabbits[0] = 1
	for n in range(1, N):
		new_pop = 0 
		for i in range(1, M):
			new_pop += rabbits[i]
		rabbits.pop()
		rabbits.insert(0, new_pop)
	total = sum(rabbits) 
	print(total)