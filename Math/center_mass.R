'
This program was written for a project in Mr. Bilodeau AP Calc class
Given an object and transposed into coordinates (pos, height)
Find the center of mass via regression
and regress the center of mass
'

pos <- c(0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 18.5)
height <- c(7.9, 7.2, 5.7, 5, 5.6, 5.4, 5.2, 5.2, 5.4, 5.9, 6.3, 6.8, 7.1, 7.3, 7.4, 7.2, 6.8, 6.2, 5.4, 4.9)

projection <- function(reg, x){ # Functional representation of regression estimates
	return(predict(reg,newdata=data.frame(pos=x)))
}

integ <- function(fun, lower, upper, parts){ #Riemann sum of a given function
	sum <- 0
	dx <- abs((upper - lower) / parts)

	for(i in 0:parts){
		sum <- sum + fun(lower + i*dx) * dx
	}

	return(sum)
}


center_of_mass <- function(f, g, lower, upper, parts = 500){ #Center of mass
	area <- integ(f, lower, upper, parts) - integ(g, lower, upper, parts)

	I_x <- function(x){ # Calculates integral for the center_m's x_coordinate
		return (x*(f(x) - g(x)))
	}

	I_y <- function(x){ #Calculates integral for the center_m's y_coordinate
		return (0.5 * (f(x) * f(x) - g(x)*g(x)))
	}

	
	c_x <- 1/area * integ(I_x, lower, upper, parts)
	c_y <- 1/area * integ(I_y, lower, upper, parts)

	return ((c(c_x, c_y)))
}

xplot = seq(0, 19, length = 200 )

colors <- c("red", "green", "blue", "orange", "yellow", "purple", "black")


test <- function(){
	proj <- function(x){ 
		return(sqrt(x))
	}
	bound <- function(x){
		return(x^3)
	}
	xx = seq(0, 1, length = 500)
	yy = lapply(xx, FUN = proj)
	yy2 = lapply(xx, FUN = bound)
	
	cm <- center_of_mass(proj, bound, 0, 1, 500)
	plot(xx, yy, type = 'l', col = 'green', xlim = c(0, 1), ylim = c(0, 2))
	lines(xx, yy2, type = 'l', col = 'red')
	print(cm)
}

solve <- function(deg1, deg2){
	plot(pos, height, xlim = c(0, 20), ylim = c(0, 10))
	
	cm_x <- NULL
	cm_y <- NULL
	r2 <- NULL
	for(deg in deg1:deg2){
		curve <- lm(height ~ poly(pos, deg))
		lines(xplot, predict(curve, newdata = data.frame(pos = xplot)), col = colors[(deg / 3) + 1])
		proj <- function(x){
			return (predict(curve, newdata = data.frame(pos = x)))
		}
		bound <- function(x){
			return (0)
		}
		r2 <- rbind(r2,c(deg, summary(curve)$r.squared)) 
		cm <- center_of_mass(proj, bound, 0, 18.5, 500)
		points(x=c(cm[1]), y= c(cm[2]), col = colors[(deg / 5) + 1])
		cm_x <- c(cm_x, cm[1])
		cm_y <- c(cm_y, cm[2])
		#print("Regression for degree")
		#print(deg)
		#print(cm)
	}

	mu_x = paste("X mu ", mean(cm_x))
	mu_y = paste("Y mu ", mean(cm_y))

	print(mu_x)
	print(mu_y)
	r2[order(-r2[,2], r2[, 1]), ]
}

solve(15, 17)