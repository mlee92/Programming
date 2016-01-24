
fib_seq = [0, 1] 

def calc_fib():
    fib_next = fib_seq[0] + fib_seq[1]
    fib_seq[0] = fib_seq[1]
    fib_seq[1]= fib_next

for i in range(0, 30):
    print fib_seq[0], ' '
    calc_fib()
