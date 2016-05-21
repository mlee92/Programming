import StringAlgo

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


#MPRT Finding a Protein Motif 

def fetchProtFASTA(code):
	import urllib 
	code = code.replace('\n', '')
	sock = urllib.urlopen("http://www.uniprot.org/uniprot/" + code + ".fasta")
	htmlSource = sock.read()
	sock.close()
	#print(htmlSource)
	i = htmlSource.find('\n')
	j = htmlSource.rfind('\n')
	nsrc = htmlSource[i:j].replace('\n', '')
	#print(nsrc)
	return (nsrc)

def isProteinMotif(prot): # [] either, {} any except 
	mode = 0 # 0 Match, 1 [], 2 {} 
	motif = 'N{P}[ST]{P}' #N-glycosylation
	isMotif = True
	return(prot[0] == 'N' 
		and (prot[1] != 'P')
		and (prot[2] == 'S' or prot[2] == 'T')
		and (prot[3] != 'P'))

def searchMotif(code):
	prot = fetchProtFASTA(code)
	pos = 0
	length = 4
	location = list()
	while(pos + length != len(prot) +  1):
		check = prot[pos:pos + length]
		#print(check)
		if(isProteinMotif(check)):
			location.append(pos + 1)
		pos += 1 
	return (location)

def MPRT():
	fin = open("rosalind_mprt.txt", 'r')

	for line in fin:
		locations = searchMotif(line)
		strings = [str(l) for l in locations]
		if(len(locations) != 0):
			print(line.replace('\n', ''))
			print(' '.join(strings))