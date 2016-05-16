rep_str = "rwx"
def driver():
    raw_str = input()
    split_str = list(raw_str.split(','))
    split_oct = [(bin(int(i)).replace("0b", "").zfill(3) + " ") for i in split_str]
    permission = int(split_oct[0], 2)
    split_oct.pop(0)
    chmod_set = [chmod(i) for i in split_oct] 
    if(permission is 1):
        if(chmod_set[0][2] == 'x'):
            chmod_set[0] = set_str(chmod_set[0], 2, 's')
    if(permission is 2):
        if(chmod_set[1][2] == 'x'):
            chmod_set[1] = set_str(chmod_set[1], 2, 's')
    if(permission is 4):
        if(chmod_set[2][2] == 'x'):
            chmod_set[2] = set_str(chmod_set[2], 2, 't')
    print("".join(split_oct) + "and " + "".join(chmod_set))
def chmod(octal):
    ret = ""
    for i in range(0, 3):
        if(octal[i] == '1'):
            ret += rep_str[i]
        else:
            ret += '-'
    ret += " "
    return ret
def set_str(s, i, c):
    S = list(s)
    S[i] = c
    return "".join(S)
for i in range(0, 5):
    driver()
