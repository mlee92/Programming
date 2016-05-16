
#BA10A Compute the Probability of a Hidden Path

def getProbability(path):
    init_prob = {'A' : 0.5, 'B' : 0.5}
    trans_prob = {'A' : {'A' : 0.194, 'B' : 0.806}, 'B' : {'A' : 0.273, 'B' : 0.727}}

    prob = init_prob[path[0]]
    prev = path[0]

    for i in range(1, len(path)):
        prob = prob * trans_prob[prev][path[i]]
        prev = path[i]
    return prob

path = "AABBBAABABAAAABBBBAABBABABBBAABBAAAABABAABBABABBAB"
print(getProbability(path))
