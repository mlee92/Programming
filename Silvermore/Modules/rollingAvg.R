library('quantmod')

#ROLLING AVERAGE IS DEFINED AS (t = time, sum(PRICE[i], i, 0, t) / t)
#i.e. UPDATED CUMULATIVE AVERAGE
# Returns Table, DAY/PRICE/ROLLING_AVG
getRollingAveragesDF <- function(tickerData){
  
  #VARIABLES 
  aggregate_sum <- 0 
  day <- 0
  DAYS <- NULL
  PRICES <- tickerData[, 2]
  ROLLING_AVG <- NULL
  
  #CALCULATION
  for(price in PRICES){
    aggregate_sum <- aggregate_sum + price 
    day <- day + 1 
    DAYS <- c(DAYS, day)
    ROLLING_AVG <- c(ROLLING_AVG, aggregate_sum / day)
  }
  
  #RETURN
  
  df <- data.frame(DAYS, PRICES, ROLLING_AVG)
  result <- df
}

#Difference between Price and RollingAverage at a given day 
#Returns table with Day/Differential 
getAverageDifferentialDF <- function(tickerData){
  RollingAverages <- getRollingAveragesDF(tickerData)
  DAYS <- RollingAverages[, 1]
  PRICES <- RollingAverages[, 2]
  ROLLING_AVG <- RollingAverages[, 3]
  DIFFERENTIAL <- abs(PRICES - ROLLING_AVG)
  
  DIFF_DF = data.frame(DAYS, DIFFERENTIAL)
  result <- DIFF_DF 
}

dispRollingAverages <- function(tickerData, title){
  RollingAverageDF <- getRollingAveragesDF(tickerData)
  #PLOT DISPLAY
  
  DAYS <- RollingAverageDF[, 1]
  PRICES <- RollingAverageDF[, 2]
  ROLLING_AVG <- RollingAverageDF[, 3]
  
  MU_PRICES <- round(mean(PRICES), 2)
  MU_ROLLING <- round(mean(ROLLING_AVG), 2)
  
  p_label <- paste("Daily mu = ", MU_PRICES)
  r_label <- paste("Rolling mu = ", MU_ROLLING)
  
  plot(DAYS, PRICES, main = title, xlab = "DAY", ylab = "PRICE", type = "l", col = "red", sub = "Cumulative Average of Price")
  lines(DAYS, ROLLING_AVG, col = "green")
  legend('topright', legend = c(p_label, r_label), col=c("red", "green"), lty = 1:2, cex = 0.8)
}


dispAverageDifferential <- function(tickerData, title){
  DIFF_DF <- getAverageDifferentialDF(tickerData)
  DAYS <- DIFF_DF[, 1]
  DIFF <- DIFF_DF[, 2]
  
  #PLOT 
  MU_DIFF <- round(mean(DIFF), 4)
  Sub <- paste("Difference between price and rolling average, mu = ", MU_DIFF)
  plot(DAYS, DIFF, main = title, sub = Sub, xlab = "DAY", ylab = "PRICE DIFFERENCE", type = "l", col = "red")
}