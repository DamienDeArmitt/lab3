#include "Password.h"
#include "ListArrayIterator.h"
#include "ListArray.h"
#include "String.h"
#include "Random.h"


//#include CSC2110>
#include <iostream>
using namespace std;
using namespace CSC2110;
//using namespace random;
// using CSC2110::String;
// using CSC2110::ListArrayIterator;
// using CSC2110::ListArray;
using CSC2110::Random;


// Password() //constructor
// ~Password() //destructor (there is work to do here, delete the individual words)
// void addWord(String* word) //add a word to the list of possible passwords
// void guess(int try_password, int num_matches) //index of guessed word in the list of all words (1-based), number of matches reported by fallout 3, update viable passwords list
// int getNumberOfPasswordsLeft() //returns the number of possible passwords remaining
// void displayViableWords() //display the current list of possible passwords
// int bestGuess() //the best word in the original list to guess next (done for you)
// String* getOriginalWord(int index) //get a word from the original list of all passwords, 1-based



Password::Password()
{
	all_words = new ListArray<String>();
	viable_words = new ListArray<String>();
	len = 0;
}

Password::~Password()
{
	delete all_words;
	
	//~ListArray()
}

void Password::guess(int try_password, int num_matches)
{
	
	//input
	
	//cin >> guess;
	//convert words into char arrays
	//compare(String* other)	//compare stings
	//check matches
	//
	for(int i=0; i<num_matches; i++)
	{
		int matches = getNumMatches(try_password, viable_words[i])
		if(num_matches >= matches)
		{
			viable_words->remove(i);
		}
	}
}

int Password::getNumberOfPasswordsLeft()
{
	int words = 0;
	//count words in viable_words?
	
	//while(viable_words->hasNext())
	//{
		//words++;
		//viable_words->next();
	//}
	//return words;
	
}
 
 
 void Password::displayWords(ListArray<String>* wordList)
 {
	 ListArrayIterator<String>* iter = wordList->iterator();
	 while(iter->hasNext())
	 {
		String* word = iter->next();
		word->displayString();
		cout<<endl;
	 }
 }
 
int Password::getNumMatches(String* curr_word, String* word_guess)
{
	int matches= 0;
	for (int i = 0; i < len; i++)
	{
		char word = curr_word->charAt(i);
		char guess = word_guess->charAt(i);
		if(word == guess)
		{
			matches++;
		}
	}
	return matches;
}
 
 
void Password::displayViableWords()
{
	displayWords(viable_words);
}

String* Password::getOriginalWord(int index)
{
	//int index = getRandomInt(1, 10);
	return all_words->get(index);
	
}



void Password::addWord(String* word)
{
	if(all_words->size() == 0)
	{
		len = word->length();
	}
	
	if(word->length() == len)
	{
		all_words->add(word);
		viable_words->add(word);
	}
}


int Password::bestGuess()
{
   int best_guess_index = -1;
   int best_num_eliminated = -1;
   int num_viable_passwords = getNumberOfPasswordsLeft();

   //loop over ALL words, even if they have been eliminated as the password
   int count = 1;
   ListArrayIterator<String>* all_iter = all_words->iterator();
   while(all_iter->hasNext())
   {
      String* original_word = all_iter->next();

      //loop over only those words that could still be the password
      //count up the number of matches between a possible password and a word in the original list
      int* count_num_matches = new int[len + 1];

      for (int i = 0; i < len; i++) 
      {
         count_num_matches[i] = 0;
      }

      ListArrayIterator<String>* viable_iter = viable_words->iterator();
      while(viable_iter->hasNext())
      {
         String* viable_word = viable_iter->next();
         int num_matches = getNumMatches(viable_word, original_word);
         count_num_matches[num_matches]++;
      }
      delete viable_iter;

      //find the largest number in the count_num_matches array
      //the largest number indicates the guess that will generate the most eliminations
      int most_num_matches = 0;
      for (int j = 0; j < len; j++) 
      {
         int curr_num_matches = count_num_matches[j];
         if (curr_num_matches > most_num_matches)
         {
            most_num_matches = curr_num_matches;
         }
      }

      //compute the fewest that can possibly be eliminated by guessing the current word (original list)
      int num_eliminated = num_viable_passwords - most_num_matches;

      //select the word to guess that maximizes the minimum number of eliminations (minimax)
      if (num_eliminated > best_num_eliminated)
      {
         best_num_eliminated = num_eliminated;
         best_guess_index = count;
      }
      
      count++;
      delete[] count_num_matches;
   }

   delete all_iter;
   return best_guess_index;  //return a 1-based index into the all_words list of words (careful)
}
