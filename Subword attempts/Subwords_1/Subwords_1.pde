// search for subwords: a word written, in order, within another one //<>//
// the order of the letters of the subword must be respected,
// but other letters of the longer word can come in between

//String[] sourceWords;
//String[] potentialSubWords;

int sourceWordsSize = 16;
int potentialSubWordsSize = 5;

String wordTest = "abdcdd";
String subWordTest = "acd";

StringList subWords;

void setup() {
  //sourceWords = loadStrings("16-lettered words.txt");
  //potentialSubWords = loadStrings("5-lettered words.txt");

  subWords = new StringList();

  subWords = calculateResults(wordTest, subWordTest);

  printArray(subWords);
}

void draw() {
}


// this function will search for subwords recursively:
// it will start with the first letter of the subword,
// and if it finds a match, it will call itself to
// do the same work on the same word and subword
// each with that first match removed

//StringList calculateResults(String word, String subWord) {
//  StringList result = new StringList();

//  // look for a match: by definition one searches in the word
//  // only up to the length of the subword minus one letter,
//  // as one must leave space for the other letters of the
//  // subword to appear within the word

//  for (int j = 0; j < word.length() - (subWord.length()-1); j++) {
//    String tempResult = "";

//    //println("word.length = "+word.length());
//    //println("word = "+word+", j = "+j+", char at j = "+word.charAt(j));

//    // start looping through the subword 

//    for (int i = 0; i < subWord.length(); i++) {

//      //println("subword = "+subWord+", i = "+i+", char at i = "+subWord.charAt(i));

//      // if there is a match, 

//      if (word.charAt(j) == subWord.charAt(i)) {
//        //println("\nnow adding "+word.charAt(j)+"\n");

//        tempResult += word.charAt(j);

//        if (i+1 < subWord.length()) {

//          String tempWord = word.substring(j+1);
//          String tempSubWord = subWord.substring(i+1);

//          //println("j = "+j+" "+word.charAt(j));
//          //println("i = "+i+" "+subWord.charAt(i));
//          //println(calculateResults(tempWord, tempSubWord));

//          //println("\nlet's dive in\n");
//          result += calculateResults(tempWord, tempSubWord);
//          //println("\nok let's get out of here\n");
//          //break;
//        }
//        //break;
//      } else {
//        //println("i = "+i+", j = "+j+", added a space, result = "+result);
//        result += " ";
//        //break;
//      }
//      //break;
//    }
//    //break;
//  }
//  return result;
//}


StringList calculateResults(String word, String subWord) {
  StringList result = new StringList();
  String tempResult = "";

  for (int i = 0; i < subWord.length(); i++) {

    println("subword = "+subWord+", i = "+i+", char at i = "+subWord.charAt(i));

    //for (int j = i; j < word.length() - (subWord.length()-(i+1)); j++) {
    for (int j = i; j < word.length() - (subWord.length()-(i+1)); j++) {

      println("word = "+word+", j = "+j+", char at j = "+word.charAt(j));
      //println("buffer = "+str(subWord.length()-(i+1)));

      if (word.charAt(j) == subWord.charAt(i)) {

        println("\nnow adding "+word.charAt(j)+"\n");
        tempResult += word.charAt(j);
        println(tempResult);
        if (j == (word.length() - (subWord.length()-(i+1)))-1) {
          tempResult += "\n";
        }

        //if (i+1 < subWord.length()) {

        //  String tempWord = word.substring(j+1);
        //  String tempSubWord = subWord.substring(i+1);

        //  println("j = "+j+" "+word.charAt(j));
        //  println("i = "+i+" "+subWord.charAt(i));

        //  println("\nlet's dive in\n");
        //  println(calculateResults(tempWord, tempSubWord));

        //  tempResult += calculateResults(tempWord, tempSubWord);
        //  println("\nok let's get out of here\n");
        //}
      } else {
        println("i = "+i+", j = "+j+", added a space, result = "+result);

        tempResult += "X";

        if (j == (word.length() - (subWord.length()-(i+1)))-1) {
          tempResult += "\n";
        }
      }
    }
    println("tempResult:");
    println(tempResult);
  }
  return result;
}