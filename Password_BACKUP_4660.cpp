#include "Password.h"
<<<<<<< HEAD
#include "ListArrayIterator.h"
#include "ListArray.h"
#include "Random.h"
=======

using CSC2110;

#include "ListArrayIterator.h"


>>>>>>> b35993bdb971e68834bf53a0c706800dd8d7a1b7
#include <iostream>
using namespace std;
//using CSC2110;


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
<<<<<<< HEAD
	all_words = new ListArray<String>*();
	max_words = max_size;
}

Password::~Password()
{
	delete all_words;
=======
	max_words = 2;
	for (int i = 0;i < max_words; i++)
	{
		int all_words[i] = 0 //NULL
	}
	num_words = 0;
}
/*
Password::~Password()
{
	//TODO will have to delete individual words
	for(int i = 0; i < num_words; i++)
		delete all_words[i];
}


void addWord(String* word) {
	
	WriteFile(const char* file_name);

void Password::addWord(String* word)
{
	//might be in driver

>>>>>>> b35993bdb971e68834bf53a0c706800dd8d7a1b7
	
	//~ListArray()
}


void Password::guess(int try_password, int num_matches)
{
	
	
}

int Password::getNumberOfPasswordsLeft()
{
	 
	 
}
 
void Password::displayViableWords()
 {
	 //display all words
	for (int i = 0; i < max_words; i++)
	{
		cout << all_words[i] << endl;
	}
 }
 
<<<<<<< HEAD
String* Password::getOriginalWord(int index)
{
	 return all_words[getRandomInt(1, max_words)];
}
=======

/
String* Password::getOriginalWord(int index)
{
	 
	 
 }


>>>>>>> b35993bdb971e68834bf53a0c706800dd8d7a1b7


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
