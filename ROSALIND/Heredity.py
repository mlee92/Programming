#IPRB Mendel's First Law

def getChildren(male, female, pdf):
	factors = {}
	for i in range(0, len(male)):
		for j in range(0, len(female)):
			all_m = male[i]
			all_f = female[j]
			factor  = str(male[i] + female[j])
			prob = float(pdf[all_m]) * float(pdf[all_f])
			if(factor in factors.keys()):
				factors[factor] += prob
			else:
				factors[factor] = prob
	return factors

def displaysDominant(factor, dominant):
	dom = False
	for allelle in factor:
		dom |= allelle == dominant
	return dom 

def probDominant(factors, dominant):
	dom = 0
	for child, prob in factors.items():
		if(displaysDominant(child, dominant)):
			dom += prob
	return dom

def mendelian(k, m, n):
	population = list('AA' for i in range(0, k)) + list('Aa' for i in range(0, m)) + list('aa' for i in range(0, n))
	total = len(population)
	#equal occurrence of recessive and dominant 
	pdf = {'A': float(0.5), 'a' : float(0.5)}
	dom_child = 0
	total_child = 0
	#print(population)
	#print(pdf)
	for male in range(0, total):
		for female in range(0, total):
				if(male != female):
					mfactor = (population[male])
					ffactor = (population[female])
					#print(mfactor)
					children = getChildren(mfactor, ffactor, pdf)
					prob_d = probDominant(children, "A")
					dom_child += prob_d
					total_child += 1 
	prob_dom = round(dom_child/ float(total_child), 5)
	print(prob_dom)

#IEV The Need for Averages

def expNumDom(couples):
	factors = list(['AAAA', 'AAAa', 'AAaa', 'AaAa', 'Aaaa', 'aaaa' ])
	pdf = {'A' : float(0.5), 'a' : float(0.5)}
	exp_prb = [0, 0, 0, 0, 0, 0]
	for i in range(0, 6):
		male = factors[i][0:2]
		female = factors[i][2:4]
		children = getChildren(male, female, pdf)
		prob_d = probDominant(children, "A")
		exp_prb[i] = prob_d * 2 * couples[i]
	print sum(exp_prb)
