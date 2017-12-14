String wordTest = "abcb"; //<>//
String subWordTest = "ab";
StringList subWords;

void setup() {

  subWords = new StringList();

  subWords = calculateResults(wordTest, subWordTest);

  printArray(subWords);
}

void draw() {
}


//this function will search for subwords recursively:
//it will start with the first letter of the subword,
//and if it finds a match, it will call itself to
//do the same work on the same word and subword
//each with that first match removed

// DOES NOT WORK


StringList calculateResults(String word, String subWord) {

  //println("word: "+word);
  //println("subword: "+subWord);

  StringList result = new StringList();
  String tempResult = "";

  for (int i = 0; i < subWord.length(); i++) {

    //println("subword = "+subWord+", i = "+i+", char at i = "+subWord.charAt(i));

    for (int j = i; j < word.length() - (subWord.length()-(i+1)); j++) {

      //println("word = "+word+", j = "+j+", char at j = "+word.charAt(j));
      //println("buffer = "+str(subWord.length()-(i+1)));

      if (word.charAt(j) == subWord.charAt(i)) {

        println("word: "+word);
        println("subword: "+subWord);
        println("j = "+j+" "+word.charAt(j));
        println("i = "+i+" "+subWord.charAt(i));

        //println("\nnow adding "+word.charAt(j)+"\n");
        tempResult += word.charAt(j);
        //println(tempResult);

        if (j == (word.length() - (subWord.length()-(i+1)))-1) {
          result.append(tempResult);
          tempResult = "";
        }

        if (i+1 < subWord.length()) {

          String tempWord = word.substring(j+1);
          String tempSubWord = subWord.substring(i+1);

          println("\nlet's dive in\n");
          //println(calculateResults(tempWord, tempSubWord));

          //tempResult += 
          result.append(calculateResults(tempWord, tempSubWord));
          
          print("result: ");
          printArray(result);
          println("\nok let's get out of here\n");
        }
      } else {

        //println("i = "+i+", j = "+j+", added a space, result = "+result);

        tempResult += "X";

        if (j == (word.length() - (subWord.length()-(i+1)))-1) {
          result.append(tempResult);
          tempResult = "";
        }
      }
    }
  }
  //println("tempResult:");
  //println(tempResult);
  return result;
}