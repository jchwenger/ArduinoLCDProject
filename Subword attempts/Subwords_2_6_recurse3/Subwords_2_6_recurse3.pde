String wordTest = "abcbacee";
String subWordTest = "abce";

IntList result;

ArrayList<int[]> results;


void setup() {

  result = new IntList();
  results = new ArrayList<int[]>();

  calculatePositions(wordTest, subWordTest);

  printArray(results);
}

void draw() {
}


// if it is known that the subWord is present in the word, this function
// will return one possibility for the positions of the letters

// DOESN'T WORK, because the two loops and the recursion work on top of each other
// adding, as it were, twice as many results as needed... The beginning shows
// great promise, as four correct possibilities are stored in the ArrayList,
// then the looping function starts adding unwanted possibilities and things
// get out of control. Probable solution: use the incrementation method 
// from the other file (singleSolutionFinder).

void calculatePositions(String word, String subWord) {

  println("word: "+word);
  println("subword: "+subWord);

  // loop through the subword

  for (int i = 0; i < subWord.length(); i++) {

    // loop through the word but not until the very end, leave space for 
    // future subword letters: subWord.length()-(i+1) substracts the length
    // of the subword minus the number of letters we've been through in the subword
    // above, so that we are sure that in the eventuality of a full subowrd
    // present in the word, there will be enough letters left in the word
    // to be found. In an abstract example, when you start searching for 
    // the subword 'abce' in the word 'abcbacee', when you look 'a' up you 
    // cannot search through the last three letters 'cee' of the word, as 
    // you must have at least three letters left for the 'bce' of the subword
    // to be potentially present. 
    // You also need to start at 'i' in this loop, you only want to search for
    // common letters after ones you've already found in the subword.

    for (int j = i; j < word.length() - (subWord.length()-(i+1)); j++) {

      //println("word = "+word+", j = "+j+", char at j = "+word.charAt(j));
      //println("buffer = "+str(subWord.length()-(i+1)));

      if (word.charAt(j) == subWord.charAt(i)) {

        println("word: "+word);
        println("subword: "+subWord);
        println("i = "+i+" "+subWord.charAt(i));
        println("j = "+j+" "+word.charAt(j));

        result.append(j);
        println("result: ");
        println(result);

        //if (j == (word.length() - (subWord.length()-(i+1)))-1) {

        //  results.add(result.array());

        //  println("results array: ");
        //  for (int k = 0; k < results.size(); k++) {
        //    println("array no: " + k);
        //    println(results.get(k));
        //  }

        //  result.remove(result.size() - 1);
        //}

        // unless we reach the end of the word, activate the recursion

        if (i+1 < subWord.length()) {

          String tempWord = word.substring(j+1);
          String tempSubWord = subWord.substring(i+1);

          println("\nlet's dive in\n");
          println("subword.length: "+subWord.length());

          calculatePositions(tempWord, tempSubWord);

          print("result: ");
          printArray(result);
          println("word: "+tempWord+", subword: "+tempSubWord);

          println("\nok let's get out of here\n");

          result.remove(result.size()-1);
          println(result);
        }

        // if we are at the end of the recursion (and our subword is reduced
        // to just one letter

        if (subWord.length() == 1) {

          // if we reach the end of the recursion, add the result 
          // to the arraylist of intlists, storing one more possibility
          
          results.add(result.array());

          println("results array: ");
          for (int k = 0; k < results.size(); k++) {
            println("array no: " + k);
            println(results.get(k));
          }

          
          // if we are at the end of the line, clear result
          
          if (j == word.length()) {
            result.clear();
            
            // otherwise, erase the last element to prepare for the 
            // return to one level above (previous recursion)
            
          } else {
            result.remove(result.size() - 1);
          }          
                      
          // otherwise, if we reach the end of the line, break the loop 

        } else {
          if (j == (word.length() - (subWord.length()-(i+1)))-1) {
            break;
          }
        }
      } else {

        // if we are at the end of the recursion and j is at the end of the word
        // clear result
        
        if (subWord.length() == 1) {
          if (j == word.length()) {
            result.clear();
            
            // otherwise, if we reach the end of the line, break the loop 
            // (an unsuccessful attempt at eliminating unwanted results)
            
          } else {
            if (j == (word.length() - (subWord.length()-(i+1)))-1) {
              break;
            }
          }
        }

        //println("i = "+i+", j = "+j+", added a space, result = "+result);

        //if (j == (word.length() - (subWord.length()-(i+1)))-1) {
        //  results.add(result.array());
        //  result.clear();
        //}
      }
      //if (j == (word.length() - (subWord.length()-(i+1)))-1) {
      //  break; //<>//
      //}
    }
  }
}