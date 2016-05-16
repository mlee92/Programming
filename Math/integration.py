import math

def f(x):
	return float(x+2)

def rectArea(length, width):
	return float(length*width)

def dX_norm(mean, std_dev):
	return random.normalvariate(mean, std_dev)

def RectIntegration(lower, upper, N):
	sum = 0
	dx = float(upper - lower) / N
	x_i = lower
	# print(lower, upper, dx)
	while(x_i <= upper):
		sum = sum + float(f(x_i) * dx) 
		x_i = float(x_i + dx)
	return sum

def r(theta):
	return float(1)

def sectorArea(radius, d_theta):
	return float(0.5*radius*radius*d_theta)

def PolarIntegration(lower, upper, N):
	sum = 0
	d_theta = float((upper - lower) / N)
	theta_i = lower 
	# print(lower, upper, d_theta)
	while(theta_i <= upper):
		sum += sectorArea(r(theta_i), d_theta)
		theta_i += d_theta
	return sum
