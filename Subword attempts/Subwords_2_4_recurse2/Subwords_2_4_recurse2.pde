String wordTest = "abcceb"; //<>//
String subWordTest = "accb";

String results;

void setup() {

  results = calculateResults(wordTest, subWordTest);

}

void draw() {
}


// this function will search for subwords recursively:
// it will start with the first letter of the subword,
// and if it finds a match, it will call itself to
// do the same work on the same word and subword
// each with that first match removed

// PROMISING BUT INCOMPLETE

String calculateResults(String word, String subWord) {
  String result = "";

  // look for a match: by definition one searches in the word
  // only up to the length of the subword minus one letter,
  // as one must leave space for the other letters of the
  // subword to appear within the word

  for (int j = 0; j < word.length() - (subWord.length()-1); j++) {

    //println("word.length = "+word.length());
    println("word = "+word+", j = "+j+", char at j = "+word.charAt(j));

    // start looping through the subword 

    for (int i = 0; i < subWord.length(); i++) {

      println("subword = "+subWord+", i = "+i+", char at i = "+subWord.charAt(i));

      // if there is a match, 

      if (word.charAt(j) == subWord.charAt(i)) {
        
        println("\nnow adding "+word.charAt(j)+"\n");

        result += word.charAt(j);
 
        if (i+1 < subWord.length()) {

          String tempWord = word.substring(j+1);
          String tempSubWord = subWord.substring(i+1);

          println("j = "+j+" "+word.charAt(j));
          println("i = "+i+" "+subWord.charAt(i));

          println("\nlet's dive in\n");
          result += calculateResults(tempWord, tempSubWord);
          println("\nok let's get out of here\n");
          break;
        }
        //break;
      } else {
        println("\ni = "+i+", j = "+j+", added a space, result = "+result);
        result += "X";
        break;
      }
      break;
    }
    //break;
  }
  return result;
}