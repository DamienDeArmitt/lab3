#if !defined PASSWORD_H
#define PASSWORD_H

//complete the includes

class Password
{
   private:
		ListArray<String>* viable_words;  //the list of words that can still be the password
		ListArray<String>* all_words;  //the original list of words
		int len;  //the length of the first word entered is stored to check that all subsequent words have the same length

		//a private helper method to report the number of character matches between two Strings
		int getNumMatches(String* curr_word, String* word_guess);
		int num_viable_passwords;
		int num_words;
		int max_words;

   public:
		Password();		//construcor
		~Password();	//deconstructor 
		void addWord(String* word);
		void guess(int try_password, int num_matches);
		void displayViableWords();
		int bestGuess();
		String* getOriginalWord(int index);
};

#endif


// Password() //constructor
// ~Password() //destructor (there is work to do here, delete the individual words)
// void addWord(String* word) //add a word to the list of possible passwords
// void guess(int try_password, int num_matches) //index of guessed word in the list of all words (1-based), number of matches reported by fallout 3, update viable passwords list
// void guess(int try_password, int num_matches) //returns the number of possible passwords remaining
// void displayViableWords() //display the current list of possible passwords
// int bestGuess() //the best word in the original list to guess next (done for you)
// String* getOriginalWord(int index) //get a word from the original list of all passwords, 1-based