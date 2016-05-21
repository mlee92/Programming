
def generateChildren(male, female):
	malleles = list(male[i: i + 2] for i in range(0, len(male), 2))
	falleles = list(female[i : i + 2] for i in range(0, len(female), 2))
	n = len(malleles) # Number of Alleles
	possibilities = list()
	for i in range(0, n):
		combinations = list()
		mpair = malleles[i]
		fpair = falleles[i]
		#print(mpair, fpair)
		for m in range(0, 2):
			for f in range(0, 2):
				gene = mpair[m] + fpair[f]
				gene = ''.join(sorted(gene))
				#print(gene)
				combinations.append(gene)
		possibilities.append(combinations)
	import itertools 
	permutations = list(itertools.product(*possibilities))
	children = [''.join(prod) for prod in permutations]
	return (children)

def isHeterogeneous(gene):
	return gene == "AaBb"

def simulateGeneration(n): #to what generation
	family = {0 : ["AaBb"]} 
	mate = "AaBb"
	totals = [1]
	hetvec = [1]
	#print(family)
	for i in range(0, n):
		ngen = list()
		het = 0 
		total = 0
		for member in family[i]:
			children = (generateChildren(member, mate))
			#print(children)
			ngen.extend(children)
			#print(family[i + 1])
			for c in children:
				if(isHeterogeneous(c)):
					het += 1
				total += 1 
		family[i + 1] = ngen
		totals.append(total)
		hetvec.append(het)
	print(hetvec)
	print(totals)

