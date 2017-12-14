String word = "abcbaceea";
String subWord = "abce";
String regex = ".*";
String[] result;

void setup() {

  // generate the appropriate regex for the subword
  for (int i = 0; i < subWord.length(); i++) {
    regex += subWord.charAt(i)+".*";
  }
  println(regex);

  // checks if the subword is present within the word
  result = match(word, regex);
  printArray(result);

  // these functions locate the occurrences  of a letter  coming first, 
  // first from an index, last and last before an index
  int pos = word.indexOf('a');
  print("first position of letter 'a': ");
  println(pos);

  pos = word.indexOf('a', 3);
  print("first position of letter 'a' from index 3: ");
  println(pos);

  pos = word.lastIndexOf('a');
  print("last position of letter 'a': ");
  println(pos);

  pos = word.lastIndexOf('a', 7);
  print("last position of letter 'a' before index 7: ");
  println(pos);
}

void draw() {
}