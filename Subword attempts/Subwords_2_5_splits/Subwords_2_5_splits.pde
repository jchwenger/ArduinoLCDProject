 //<>//
int sourceWordsSize = 16;
int potentialSubWordsSize = 5;

String wordTest = "abcdbe";
String subWordTest = "acd";
String regex = ".*";

ArrayList<IntList> resultPos;
String[] result1, result2, result3;

IntList results;

//StringList subWords;

void setup() {
  
  // experiments with regex and matching 

  result1 = match(wordTest, ".*a");
  result2 = match(wordTest, "a.*c");
  result3 = match(wordTest, "c.*d");

  println("print results 1, 2, 3: ");
  printArray(result1);
  printArray(result2);
  printArray(result3);

  println("\nexperimenting with splitting");

  String wordSpaced = wordTest;

  String subWordSpaced = "";

  println("split word by first subword letter:");
  result1 = split(wordTest, subWordTest.charAt(0));

  printArray(result1);

  // attempt at tackling the various possibilities -> the tree-structure
  // comes straight back to get me!
  
  //// if only one match

  //if (result1.length <= 2) {
  //  if (result1[0] == null) {
  //    subWordSpaced = "X";
  //  } else {
  //    subWordSpaced += result1[0];
  //  }

  //  // if more than one match
  //  // INCOMPLETE (where all the trouble resides)
  //} else {
  //  if (result1[0] == null) {
  //    subWordSpaced = "X";
  //  } else {
  //    subWordSpaced += result1[0];
  //  }
  //}

  println("\nsplit previous by second subword letter:");

  result2 = split(result1[1], subWordTest.charAt(1));

  printArray(result2);

  println("\nsplit previous by third subword letter:");

  result3 = split(result2[1], subWordTest.charAt(2));

  printArray(result3);

}

void draw() {
}