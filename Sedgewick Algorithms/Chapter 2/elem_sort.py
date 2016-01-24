
example = list([4, 3, 7, 2, 1, 9, 5, 6])
# numbers = list([1, 2, 3, 4,])

def exchange(numbers, i, j):
    k = numbers[i]
    numbers[i] = numbers[j]
    numbers[j] = k
    

def compNum(i, j):
    return i < j

def isSorted(numbers):
    sorted = 1
    index = 0
    while(sorted and index < len(numbers) - 1):
        sorted &= compNum(numbers[index], numbers[index + 1])
        index += 1
    return sorted

def printArray(numbers):
    for i in range(len(numbers)):
        print numbers[i], " "
    print '\n'

def selectionSort(numbers):
    start = 0 
    index = 0 
    least_index = 0

    while(start != len(numbers)): 
        while(index < len(numbers)):
            if(numbers[index] < numbers[least_index]):
                least_index = index;
            index += 1
            
        exchange(numbers, start, least_index)
        start += 1
        index = start

def insertionSort(numbers):
    i = 1
    while(i < len(numbers)):
        j = i
        while(j > 0 and compNum(numbers[j], numbers[j - 1])):
              exchange(numbers, j, j - 1)
              j -= 1 
        i += 1 

def shellSort(numbers, subsets):
    size = len(numbers)
    h = 1
    while(h < size/subsets):
        h = subsets*h + 1
    while(h >= 1):
        i = h
        while(i < size):
            j = h
            while(j >= h and compNum(numbers[j], numbers[j - 1])):
                exchange(numbers, j, j - h)
                j -= h
            i += 1
        h = h / subsets
    insertionSort(numbers)
    

printArray(example)
