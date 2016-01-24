
def merge(left, right):
	left_idx, right_idx = 0, 0
	result = []
	while(left_idx < len(left) and right_idx < len(right)):
		if(left[left_idx] <= right[right_idx]):
			result.append(left[left_idx])
			left_idx += 1
		else:
			result.append(right[right_idx])
			right_idx += 1
	if left:
		result.extend(left[left_idx:])
	if right:
		result.extend(right[right_idx:])
	return result

def mergeSort(numbers):
	if len(numbers) <= 1:
		return numbers
	middle = len(numbers) // 2
	left = numbers[:middle]
	right = numbers[middle:]

	left = mergeSort(left)
	right = mergeSort(right)

	return list(merge(left, right))


def printArray(numbers):
    for i in range(len(numbers)):
        print numbers[i], " "
    print '\n'

example = (4, 3, 7, 2, 1, 9, 5, 6)


sorts = mergeSort(example)
printArray(sorts)
