# Elasticity of demand is a measure of how strongly consumers respond to a change in the price of a good
# Formally, % change in demand / % change in price

# Problem: Graph the histogram of average-elasticity for a linear-demand good with random coefficients (a, b)

import random
import matplotlib.pyplot as plt
import numpy as np

SIM = 1000; 
UNIT_RANGE = range(1, 50) 
AVGS = list() 
COEF = [0, 0]

def generate_coefficients():
        global COEF
        a = random.randint(1, 25)
        b = random.randint(a*50, 25*50)
        COEF = [a, b]
        
def price(unit):
        return COEF[1] - COEF[0]*unit

def graph_price():
        x = np.linspace(1,50,50)
        y = price(x)
        plt.plot(x, y)
        plt.show()
        
def elasticity(d1, d2):
        cPrice = price(d2) - price(d1)
        cDemand = d2 - d1
        pPrice = cPrice / price(d1)
        pDemand = cDemand / d1
        return abs(pDemand / pPrice)

def simulate():
        global AVGS, COEF, UNIT_RANGE
        generate_coefficients()
        elast_list = list()
        for i in UNIT_RANGE:
                for j in UNIT_RANGE:
                        if(i != j):
                                elast_list.append(elasticity(i, j))
        mu = np.mean(elast_list)
        print(COEF, mu)
        AVGS.append(mu)

def init():
        for i in range(0, SIM):
                simulate()
init()
print(SIM)
plt.hist(AVGS)
plt.show()
