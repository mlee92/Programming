import random
import matplotlib.pyplot as plt

N = 100
M = 1000
buyer_balance = [0] * 50
buyer_card_num = [0] * 50
buyer_card_values = [0] * 50

seller_balance = [0] * 50
seller_card_num = [0] * 50
seller_card_values = [0] * 50

def init():
    for i in range(0, 50):
       buyer_card_values[i] = abs(int(random.normalvariate(30, 10)))
       seller_card_values[i] = abs(int(random.normalvariate(30, 10)))
       buyer_balance[i] = 0
       seller_balance[i] = 0 
       buyer_card_num[i] = int(random.randint(0, 49))
       seller_card_num[i] = int(random.randint(0, 49))


def trade(seller, buyer): 
    bid = 0
    sell_price = seller_card_values[seller_card_num[seller]]
    buy_price = buyer_card_values[buyer_card_num[buyer]]

    sell_profit = sell_price - buy_price
    buy_profit = buy_price - sell_price

    if(sell_profit != 0 and buy_profit != 0):
        seller_balance[seller] += sell_profit
        buyer_balance[buyer] += buy_profit
        
        resetSeller(seller)
        resetBuyer(buyer)
        
    # print "{} : {}".format(sell_price, buy_price)
    
def resetSeller(seller):
    seller_card_num[seller] = int(random.randint(0, 49))

def resetBuyer(buyer):
    buyer_card_num[buyer] = int(random.randint(0, 49))

def simulateMarket():
    init()
    for i in range(0, 100):
        buyer = int(random.randint(0, 49))
        seller = int(random.randint(0, 49))
        trade(seller, buyer)
    buy_profit = 0
    sell_profit = 0
    buy_loss = 0
    sell_loss = 0
    zero_sum = 0
    
    net_profit = 0
    net_loss = 0 
    for i in range(0, 50):
        #print "Buyer {} has {}".format(i, buyer_balance[i])
        #print "Seller {} has {}".format(i, seller_balance[i])

        if(buyer_balance[i] > 0):
            buy_profit+= 1
            net_profit += buyer_balance[i]
        elif(buyer_balance[i] < 0):
            net_loss += abs(buyer_balance[i])
            buy_loss += 1
        else:
            zero_sum += 1
            
        if(seller_balance[i] > 0):
            sell_profit += 1
            net_profit += seller_balance[i]
        elif(seller_balance[i] < 0):
            net_loss += abs(seller_balance[i])
            sell_loss += 1
        else:
            zero_sum += 1
    #print"{} buyers profited \n".format(buy_profit)
    #print "{} sellers profited \n".format(sell_profit)

    return [buy_profit, buy_loss, sell_profit, sell_loss, zero_sum, net_profit, net_loss]
  
def simulateEconomy():
    buy_profit = list()
    buy_loss = list()
    sell_profit = list()
    sell_loss= list()
    zero_sum =list()
    net_profit = list()
    net_loss = list()
    for i in range(0, M):
        sim = simulateMarket()
        buy_profit.append(sim[0])
        buy_loss.append(sim[1])
        sell_profit.append(sim[2])
        sell_loss.append(sim[3])
        zero_sum.append(sim[4])
        net_profit.append(sim[5])
        net_loss.append(sim[6])
    plt.hist(buy_profit)
    plt.show()

simulateEconomy()
