
#FIB: Wascally Wabbits

def getNumRabbits(N, K):
    pop = {0:0, 1: 1, 2:1}
    if(N in pop):
        return pop[N]
    else:
        pop[N] = getNumRabbits(N - 1, K) + K * getNumRabbits(N - 2, K)
        return pop[N]

print(getNumRabbits(29, 2))
    
