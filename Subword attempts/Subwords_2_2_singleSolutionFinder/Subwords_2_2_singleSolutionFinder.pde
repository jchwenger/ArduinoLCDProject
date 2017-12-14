String wordTest = "abcbacee"; //<>//
String subWordTest = "abce";
IntList results;


void setup() {

  results = new IntList();
  
  results = calculatePositions(wordTest, subWordTest);

  printArray(results);
   
}

void draw() {
}


// if it is known that the subWord is present in the word, this function
// will return one possibility for the positions of the letters

IntList calculatePositions(String word, String subWord) {

  println("word: "+word);
  println("subword: "+subWord);

  IntList result = new IntList();

  int subWordIndex = 0;

  for (int j = 0; j < word.length(); j++) {

    if (word.charAt(j) == subWord.charAt(subWordIndex)) {
      
      subWordIndex++;

      result.append(j);

      if (subWordIndex == subWord.length()) {
        break;
      }
    }
  }
 
  return result;
}