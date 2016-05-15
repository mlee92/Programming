library("quantmod")

#Average Rate of Change
#Returns table with DAY/PRICE CHANGE
getAvgROC <- function(tickerData){
  PRICES <- tickerData[, 2]
  DAYS <- NULL
  ROC <- NULL
  

  LEN <- length(PRICES)
  pos <- 1
  
  while(pos != LEN){
    PREV <- PRICES[pos]
    NEXT <- PRICES[pos + 1]
    CHNG <- as.double(NEXT) - as.double(PREV)
    ROC <- c(ROC, CHNG)
    DAYS <- c(DAYS, pos)
    pos <- pos + 1 
  }
  
  #DEBUG
  #print(length(DAYS))
  #print(length(ROC))
  
  roc_df <- data.frame(DAYS, ROC)
  result <- roc_df
}

dispAvgROC <- function(tickerData, title){
  #VARIABLES
  ROC_DF <- getAvgROC(tickerData)
  DAYS <- ROC_DF[, 1]
  ROC <- ROC_DF[, 2]
  
  Sub <- paste("Average Rate of Change, mu = ", round(mean(ROC), 4))
  #PLOT
  plot(DAYS, ROC, main = title, col = "blue", type = "l", sub = Sub,  ylab = "PRICE / DAY", xlab = "DAY")
}