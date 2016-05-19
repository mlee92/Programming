import string 

#DNA: Counting DNA Nucleotides

def countDNA(src):
	base = "GTAC"
	counter = [0, 0, 0, 0]
	for i in range(0, len(src)):
		counter[string.find(base, src[i])] += 1
	print(counter)

#RNA: Transcribing DNA into RNA
	
def transcribe2RNA(dna):
    DNA2RNA = {'G' : 'G', 'A' : 'A', 'T':'U', 'C' :'C'}
    rna = ""
    for i in range(0, len(dna)):
        rna = rna + DNA2RNA[dna[i]]
    return rna

#REVC: Complementing a Strand of DNA

def complementDNA(dna):
    complements = {'C' : 'G', 'A':'T', 'G':'C', 'T':'A'}
    comp = ""
    for i in range(0, len(dna)):
            comp = comp + complements[dna[i]]
    return comp

def reverse(word):
    rev = ""
    for i in range(0, len(word)):
            rev += word[len(word) - i - 1]
    return rev

#GC: Computing GC Content

def getGCPercent(dna):
    value = {'C' : 1, 'G' : 1, 'T' : 0, 'A' : 0}
    valid = 0
    for i in range(0, len(dna)):
            valid += value[dna[i]]
    if len(dna) == 0:
            return 0
    else: 
            return (float(valid) / float(len(dna)) * 100)

def processFASTA(directory):
    name = ""
    dna = ""
    FASTA = {}
    fin = open(directory, 'r')

    for line in fin:
            if(line[0] == '>'):
                    FASTA[name] = dna
                    name = line.replace('>', '')
                    name = name.replace('\n', '')
                    dna = ""
            else:
                    dna += line.replace('\n', '')
    FASTA[name] = dna
    del FASTA[""]
    return FASTA

def getMaxGC(FASTA):
    FASTA = {k : getGCPercent(v) for k, v in FASTA.items()}
    #sorted_FASTA = sorted(FASTA.values, key=FASTA.__getvalue__)
    from operator import itemgetter
    sorted_FASTA = sorted(FASTA.items(), key=itemgetter(1))
    print(sorted_FASTA[len(sorted_FASTA) - 1][0])
    print(sorted_FASTA[len(sorted_FASTA) - 1][1])

#SUBS: Finding a Motif in DNA
    
def DNASubstring(s, t):
    return [(pos + 1) for pos in range(len(s)) if s.startswith(t, pos)]

#CONS: Consensus and Profile  
def getDNAMatrix(FASTA):
    import numpy as np
    DNAstrlist = [list(s) for s in FASTA.values()]
    numrow = len(DNAstrlist)
    numcol = len(DNAstrlist[1])
    DNAmat = np.array(DNAstrlist)
    
    return DNAmat

def getProfileMatrix(FASTA):
    import numpy as np
    DNAmat = getDNAMatrix(FASTA)
    letters = ['A', 'C', 'G', 'T']
    profileMAT = np.zeros((4, DNAmat.shape[1]), dtype = np.dtype(int))
    for column in range(0, DNAmat.shape[1]):
        for row in range(0, len(letters)):
            term = sum([int(str(x) is letters[row]) for x in DNAmat[:, column]])
            profileMAT[row][column] = term
    
    return profileMAT 

def getConsensus(FASTA):
    import numpy as np

    profile = getProfileMatrix(FASTA)
    symbols = {0 : 'A', 1 : 'C', 2 : 'G' , 3 : 'T'}
    consensus = []

    for column in range(0, profile.shape[1]):
        row = np.array((profile[:, column]))
        consensus.append(symbols[np.argmax(row)])
    return consensus

def printConsensus(FASTA):
    profile = getProfileMatrix(FASTA)
    consensus = getConsensus(FASTA)
    con = "".join(consensus)
    fout = open("cons.txt", 'w')
    fout.writelines(con + '\n')
    symbols = ["A: ", "C: ", "G: ", "T: "]
    for i in range(0, 4):
        fout.writelines(symbols[i])
        fout.writelines(' '.join(map(str, profile[i, :])))
        fout.writelines('\n')

#PROT Transcribing RNA to Proteins

RNA_CODON_TABLE = {
    'UUU': 'F',     'CUU': 'L',     'AUU': 'I',     'GUU': 'V',
    'UUC': 'F',     'CUC': 'L',     'AUC': 'I',     'GUC': 'V',
    'UUA': 'L',     'CUA': 'L',     'AUA': 'I',     'GUA': 'V',
    'UUG': 'L',     'CUG': 'L',     'AUG': 'M',     'GUG': 'V',
    'UCU': 'S',     'CCU': 'P',     'ACU': 'T',     'GCU': 'A',
    'UCC': 'S',     'CCC': 'P',     'ACC': 'T',     'GCC': 'A',
    'UCA': 'S',     'CCA': 'P',     'ACA': 'T',     'GCA': 'A',
    'UCG': 'S',     'CCG': 'P',     'ACG': 'T',     'GCG': 'A',
    'UAU': 'Y',     'CAU': 'H',     'AAU': 'N',     'GAU': 'D',
    'UAC': 'Y',     'CAC': 'H',     'AAC': 'N',     'GAC': 'D',
    'UAA': '',  'CAA': 'Q',     'AAA': 'K',     'GAA': 'E',
    'UAG': '',  'CAG': 'Q',     'AAG': 'K',     'GAG': 'E',
    'UGU': 'C',     'CGU': 'R',     'AGU': 'S',     'GGU': 'G',
    'UGC': 'C',     'CGC': 'R',     'AGC': 'S',     'GGC': 'G',
    'UGA': '',  'CGA': 'R',     'AGA': 'R',     'GGA': 'G',
    'UGG': 'W',     'CGG': 'R',     'AGG': 'R',     'GGG': 'G'
}

def RNA2Protein(s):
	codon = [s[i: i+3] for i in range(0, len(s), 3)]
	prot = ''.join(RNA_CODON_TABLE[c] for c in codon)
	return prot

#LCSM Finding a Shared Motif 

def generateSubstr(dna):
	substr = {} 
	checklen = 2
	while(checklen != len(dna)):
		pos1 = 0
		pos2 = pos1 + checklen
		while(pos2 != len(dna)):
			sub = dna[pos1:pos2]
			substr[sub] = len(sub)
			pos1 += 1
			pos2 = pos1 + checklen
		checklen += 1
	return set(substr.keys())
	
def longestMotifs(dnalib):
	common = generateSubstr(dnalib[0])
	for i in range(1, len(dnalib)):
		dna = (dnalib[i])
		sub = (generateSubstr(dna))
		
		intersection = sub & common 
		common = [intersection]
	print(common)

Fas = processFASTA("rosalind_lcsm.txt")
lib = list(Fas.values())
print(lib)
