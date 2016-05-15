library("quantmod")

getSimpleMovingAvg <- function(tickerData, t_0, t_1){
  #VARIABLES
  PRICES <- NULL 
  RUNNING_SUM <- 0
  DAYS <- NULL
  AVGS <- NULL
  
  #CALCULATION
  
  for(time in t_0:t_1){
    PRICES <- c(PRICES, tickerData[time])
    RUNNING_SUM <- RUNNING_SUM + PRICES[time - t_0 + 1]
    DAYS <- c(DAYS, time) 
    AVGS <- c(AVGS, as.double(RUNNING_SUM / (time - t_0 + 1)))
  }
  
  df <- data.frame(DAYS, PRICES, AVGS)
  return(df)
}

dispSimpleMovingAvg <- function(tickerData, title, t_0, t_1){
  #VARIABLES
  DF <- getSimpleMovingAvg(tickerData, t_0, t_1)
  DAYS <- DF[, 1]
  PRICES <- DF[, 2]
  AVGS <- DF[, 3]
  
  MU_PRICES <- round(mean(PRICES))
  MU_AVGS <- round(mean(AVGS))
  
  p_label <- paste("Daily mu = ", MU_PRICES)
  r_label <- paste("Moving mu = ", MU_AVGS)

    plot(DAYS, PRICES, main = title, xlab = "DAY", ylab = "PRICE", type = "l", col = "red", sub = "Cumulative Average of Price with Equal Weight")
  lines(DAYS, AVGS, col = "green")
  legend('topright', legend = c(p_label, r_label), col=c("red", "green"), lty = 1:2, cex = 0.8)
}

library("quantmod")
"Returns a dataframe of the exponential moving average: where the moving average from t_0 to t_1 is calculated with exponential weight given to more recent quotes"

getExpMovAvg <- function(tickerData, t_0, t_1, alpha){
  #INIT VAR 
  PRICES <- NULL 
  DAYS <- NULL
  AVGS <- NULL
  
  WEIGHT <- c(alpha, 1 - alpha)
  
  #first day
  DAY <- 1 
  PRICES <- c(PRICES, tickerData[t_0])
  AVGS <- c(AVGS, PRICES[DAY])
  DAYS <- c(DAYS, t_0)
  
  for(time in (t_0 + 1):t_1){
    DAY <- DAY + 1 
    P <- tickerData[time]
    S <- P * WEIGHT[1] + AVGS[DAY - 1] * WEIGHT[2]
    
    PRICES <- c(PRICES, P)
    AVGS <- c(AVGS, S)
    DAYS <- c(DAYS, time)
  }
  
  df <- data.frame(DAYS, PRICES, AVGS)
  
  #DEBUG
  
  #print(length(DAYS))
  #print(length(PRICES))
  #print(length(AVGS))
  return(df)
}

dispExpMovingAvg <- function(tickerData, t_0, t_1, weight, title){
  EXP_DF <- getExpMovAvg(tickerData, t_0, t_1, weight)
  
  DAYS <- EXP_DF$DAYS
  PRICES <- EXP_DF$PRICES
  AVGS <- EXP_DF$AVGS
  
  MU_P <- mean(PRICES, na.RM = TRUE)
  MU_AVG <- mean(AVGS, na.RM = TRUE)
  
  
  p_label <- paste("Daily mu = ", MU_P)
  r_label <- paste("Moving mu = ", MU_AVG)
  
  plot(DAYS, PRICES, main = title, xlab = "DAY", ylab = "PRICE", type = "l", col = "red", sub = "Cumulative Average of Price with Exponential Weight")
  lines(DAYS, AVGS, col = "green")
  legend('topright', legend = c(p_label, r_label), col=c("red", "green"), lty = 1:2, cex = 0.8)
  
}

getMovAvgDiff <- function(tickerData, type, t_0, t_1, alpha){
  if(grepl(type, "simple")){
    MovAvgDF <- getSimpleMovingAvg(tickerData, t_0, t_1)
  } else if(grepl(type, "exp")){
    MovAvgDF <- getExpMovAvg(tickerData, t_0, t_1, alpha)
  }
  DAYS <- MovAvgDF$DAYS
  PRICES <- MovAvgDF$PRICES
  AVGS <- MovAvgDF$AVGS
  DIFF <- NULL
  for(time in 1:length(DAYS)){
    DIFF <- c(DIFF, AVGS[time] - PRICES[time])
  }
  
  df <- data.frame(DAYS, PRICES, AVGS, DIFF)
  return(df)
}

dispMovAvgDiff <- function(tickerData, type, t_0, t_1, weight, title){
  DiffDF <- getMovAvgDiff(tickerData, type, t_0, t_1, weight)
  
  DAYS <- DiffDF$DAYS
  PRICES <- DiffDF$PRICES
  AVGS <- DiffDF$AVGS
  DIFF <- DiffDF$DIFF
  
  MU_DIFF <- mean(DIFF, na.RM = TRUE)
  
  d_label <- paste("Differential mu = ", MU_DIFF)
  sub_label <- paste("Difference between moving", type, "avg and price")
  plot(DAYS, DIFF, main = title, xlab = "DAY", ylab = "PRICE DIFFERENCE", type = "l", col = "purple", sub = sub_label)
  legend('topright', legend = c(d_label), col=c("purple"), lty = 1:2, cex = 0.8)
}


dispAllMovAvgs <- function(tickerData, t_0, t_1, weight, title){
  DAYS <- t_0:t_1
  SMP <- getSimpleMovingAvg(tickerData, t_0, t_1)$AVGS
  EXP <- getExpMovAvg(tickerData, t_0, t_1, weight)$AVGS
  PRC <- tickerData[t_0:t_1]
  
  MU_P <- mean(PRC, na.rm = TRUE)
  MU_SMP <- mean(SMP, na.rm = TRUE)
  MU_EXP <- mean(EXP, na.rm = TRUE)
  
  p_label <- paste("Daily mu = ", MU_P)
  s_label <- paste("Simple mu = ", MU_SMP)
  e_label <- paste("Exponential mu = ", MU_EXP)
  
  plot(DAYS, PRC, main = title, xlab = "DAY", ylab = "PRICE", type = "l", col = "red", sub = "Cumulative Average of Price with Simple and Exponential Weight")
  lines(DAYS, SMP, col = "green")
  lines(DAYS, EXP, col = "purple")
  legend('topright', legend = c(p_label, s_label, e_label), col=c("red", "green", "purple"), lty = 1:2, cex = 0.8)
  
  
}