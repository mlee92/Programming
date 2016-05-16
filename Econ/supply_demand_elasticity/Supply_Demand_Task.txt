OBJECTIVE:
Given a normal distribution of supply and demand, show that the distribution of profit and losses will be normal as well. 

VARIABLES:

N = 100 // Number of trades
M = 1000// Number of simulations

player_balance // All start at 0

Seller_cards // Normally distributed mu = 30 sigma = 10

Buyer_cards // Normally distributed  mu = 30 sigma = 10

TASK:

At a market for cards, there are 100 people. 50 of these N people are buyers, 50 are sellers. Buyers want to buy at the lowest possible price; Sellers want to sell at the highest possible price. The cost of the cards are constant but each time a trade is made, the seller needs to sell a new card and the buyer will buy at a new price. Buyers want to sell at or above a certain price floor and below or at a certain price ceiling. After M trades, how many people will have made a profit? 

Example

Buyer {A}
Seller {B}

Buyer_cards {30, 20, 10, 30, 30, 8}
Seller_cards {20, 30, 30, 5, 7}

A -> Buyer_card3  -> value = 10
B -> Seller_card4 -> value = 5

A trades with B; B wants to sell at 5 or higher; A wants to pay at 10 or lower;

B trades with A at 5  
B makes 5 - 5 = 0 
A makes 10 - 5 = 5

Total profit = 5 

A -> Buyer_card4
B -> Seller_card2 

etc