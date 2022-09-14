#==========================
# Grant Gutterman
# 08-31-2022
# Project 1 Concordance
# Looks for word appearances in text, along with indexed sentences.
#==========================

# Global Variable/Text Initialization

inputtxt = open('input.txt', 'r')
txt = inputtxt.read()
inputLength = len(txt)

words = []
sentences = {}	
wordBuild = ''
sentBuild = ''

# Functions for Main

def sepWords(txt):
	'''
	This function seperates all of the words in the text, while also making them all lower
	case. This will print them all as they are the list of words you can search for.
	'''
	txtLower = txt.lower()
	txtNoPeriod = txtLower.replace('.', '')
	words = txtNoPeriod.split()
	print('Searchable words in text: ')
	for element in words:
		print(element)
	return

def sepSentences(txt):
	'''
	This function seperates all of the sentences by converting the strings into a list and
	then adding them to a dictionary. The dictionary also numbers the sentences in its 
	keys.
	'''
	sentencesList = txt.split('. ')
	sentKeyNum = 1
	for element in sentencesList:
		sentences[sentKeyNum] = element + '.'
		sentKeyNum += 1
	return sentences	
	
def wordSearch(inputTxt):
	'''
	wordSearch takes a string that is the word that the user inputs, and searches for this
	word in the dictionary 'sentences' storage. If it find an instance (upper or lower 
	case) that matches the inputted word, it will print the whole sentence and its key. 
	'''
	for key in sentences.keys():
		if sentences[key].find(inputTxt) != -1:
			print(sentences[key])
		elif sentences[key].find(inputTxt[0].upper()) != -1:
			print(sentences[key])
	return

# Main Function

def __main__():
	#Function that runs the other functions and builds the makeup of the program.
	sepWords(txt)
	sepSentences(txt)
	inputTxt = input('Enter a word you want to search for: ')
	wordSearch(inputTxt)
	return

__main__()
