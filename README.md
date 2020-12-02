# Files and String Processing
#
##### This program is coded in **C** Programming Language
#
## The Problem
The following index (reference: Rudolf Flesch, How to Write Plain English, Barnes & Noble Books, 1979) was invented by Rudolf Flesch as a simple tool to gauge the legibility of a document without using linguistic analysis.

## Purpose of this program
- The purpose of the index is to force authors to rewrite their text until the index is appropriately high enough. This is achieved by reducing the length of sentences and by removing long words. For example, the sentence:
-
    - The following index was invented by Flesch as a simple tool to estimate the legibility of a document without linguistic analysis.
**can be rewritten as:**
    - Flesch invented an index to check whether a document is easy to read. To compute the index, you need not look at the meaning of the words.

In order to get calculate the index number, the following is first analyzed :
1. Count all words in the file. A word is any sequence of characters delimited by white space or the end of a sentence, whether or not it is an actual English word.
2. Count all syllables in each word. To make this simple, use the following rules:
• Each group of adjacent vowels (a, e, i, o, u, y) counts as one syllable (for example, the “ea” in “real” counts as one syllable, but the “e..a” in “regal” count as two syllables). However, an “e” at the end of a word does not count as a syllable. Each word has at least one syllable even if the previous rules give a count of zero.
3. Count all sentences. A sentence is a group of words terminated by a period, colon, semicolon, question mark, or exclamation mark. Multiples of each of these characters should be treated as the end of a single sentence. For example, “Fred says so!!!” is one sentence.
4. The index is computed by:
index = 206.835 – 84.6 * ( #syllables / #words ) – 1.015 * (#words / #sentences)
rounded to the nearest integer (use the round function rather than ceiling or floor).

## Sample files
- Sample files are provided in the **samples** folder that can be used for testing, it also includes the output that is expected from running each sample.

## How to run?
- Simply clone or download the repository. Navigate to the folder in your terminal, and type ***make***, it will create the executable file.
- To execute the file, type ***./fleschIndex <fileName.txt>***
- The output will display the following 
    1. The Flesch/legibility index that have been computed
    2. The number of syllables in the input txt file
    3. The number of words in the input txt file
    4. The number of sentences in the input txt file
