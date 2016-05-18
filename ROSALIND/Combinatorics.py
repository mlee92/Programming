
#FIB: Wascally Wabbits

def getNumRabbits(N, K): # after n months, each producing k 
	pop = {0:0, 1: 1, 2:1}
	if(N in pop):
		print(pop[N])
		return pop[N]
	else:
		pop[N] = getNumRabbits(N - 1, K) + K * getNumRabbits(N - 2, K)
		return pop[N]

	

#FIBD Wabbit Season

def getNumRabbits(N, M):
	population = [] # How many rabbits are alive for a generation
	lifespan = [] # How many more months each generation has to live
	
	if(N in pop):
		print(pop[N])
		return pop[N] 
	else:
		population[N] = getNumRabbits(N - 1, K) + K * getNumRabbits(N - 2, K)