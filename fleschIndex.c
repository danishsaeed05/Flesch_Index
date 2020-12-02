#include <stdio.h>
#include <string.h>
#include <math.h>

#define BUFFER_SIZE 200

int countSentences(FILE *);
int countSyllables(char *);
int checkVowel(char);
int isPunctuation(char);
int wordlength(char *word);

//argc specifies the # of arguments(Deafault is 1 if no arguments are passed)
//argv is a pointer to array of strings (this can be the file name Ex. sample.txt)
int main(int argc, char *argv[])
{
    FILE *fp;
    int words, sentences, syllables;
    words = sentences = syllables = 0;
    double fleschIndex = 0.0;
    char singleWord[BUFFER_SIZE];

    if (argc < 2)
    {
        printf("ERROR: You need to add an input file as first parameter.\n");
        printf("Example:\n");
        printf("$ %s <filename>\n", argv[0]);
        return 0;
    }

    //argv[0] is program name
    //argv[1] is 2nd parameter/file name
    fp = fopen(argv[1], "r");

    //Will only read the first word
    //fscanf(fp, "%s", buff);

    if (fp == NULL)
    {
        printf("Unable to read file.\n");
        return 0;
    }

    //count words
    while (fscanf(fp, "%s", singleWord) != EOF)
    {
        words++;

        //count syllables
        syllables = syllables + countSyllables(singleWord);
    }

    //count sentences
    sentences = countSentences(fp);

    //calculate fleschIndex
    fleschIndex = round(206.835 - 84.6 * (syllables / words) - 1.015 * (words / sentences));

    printf("Flesch Index = %.01f\n", fleschIndex);
    printf("Syllable Count = %d\n", syllables);
    printf("Word Count = %d\n", words);
    printf("Sentence Count = %d\n", sentences);

    fclose(fp);
    return 0;
}

int countSentences(FILE *fp)
{
    char character;
    int sentences = 0;

    //go to beginning of the file
    fseek(fp, 0, SEEK_SET);

    while ((character = fgetc(fp)) != EOF)
    {
        if ((character == ':') || (character == '.') || (character == ';') || (character == '?') || (character == '!'))
            sentences++;
    }
    return sentences;
}

int countSyllables(char *word)
{
    /* variables declarations */
    int syllables = 0;
    int i = 0;
    int len = wordlength(word);

    if (len == 1)
    {
        return 1;
    }

    if (checkVowel(word[0]))
    {
        syllables++;
    }

    if (!checkVowel(word[len - 2]) && checkVowel(word[len - 1]) && word[len - 1] != 'e' && word[len - 1] != 'E')
    {
        syllables++;
    }

    for (i = 1; i < (len - 1); i++)
    {
        if (!checkVowel(word[i - 1]) && checkVowel(word[i]))
        {
            syllables++;
        }
    }
    return (syllables > 0) ? syllables : 1;
}

int checkVowel(char character)
{
    int lowecase_vowel = (character == 'a' || character == 'e' || character == 'i' || character == 'o' || character == 'u' || character == 'y');
    int uppercase_vowel = (character == 'A' || character == 'E' || character == 'I' || character == 'O' || character == 'U' || character == 'Y');

    if (lowecase_vowel || uppercase_vowel)
        return 1;

    return 0;
}

int isPunctuation(char c)
{
    return c == '.' || c == ':' || c == ';' || c == '?' || c == '!';
}

int wordlength(char *word)
{
    int len = strlen(word);

    while (isPunctuation(word[len - 1]))
    {
        len--;
    }
    return len;
}
