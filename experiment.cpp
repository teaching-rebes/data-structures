#include "experiment.h"

#include <time.h>

#include <iostream>
#include <sstream>
#include <string>

using namespace std;


bool isLittleEndian()
{

  // *** aus dem Foliensatz bekannter Code-Abschnitt zum Thema "Endianness" (Erklärung siehe Folien dazu...) ***

  long long ll = 0x123456789abcdef;
  unsigned char* pc = (unsigned char*)(&ll);
  int i;

  for (i=0; i<8; i++)
    printf("%02hx ", *(pc + i));

  // Ende des aus dem Foliensatz bekannten Abschnitts

  // return true if this system uses little endian
  return (*pc == 0xef);
}



// TODO: In der nachfolgenden Methode die Code-Änderungen zum Thema Alignment einfügen
#define NR_ELEMENTS 50000
void doAlignmentExperiment()
{

  // define a data structure with multiple elements
  struct data {
    unsigned char character;
    long long     long_value;
    int           int_value;
    double        double_value;
  };

  cout << "Size of data structure: " << sizeof(data) << " Bytes" << endl;

  
  /** TODO: für eine sinnvolle Messung der Zugriffszeit im zweiten Aufgabenteil hier die Kommentarzeichen entfernen: ** 

  // create large array of elements with this structure
  data testarray [NR_ELEMENTS];
  
  // access test array by writen some values
  for (long i = 0; i < NR_ELEMENTS; i++) {
    testarray[i].long_value = i * i;
    testarray[i].double_value = 42.42 + i;
    testarray[i].character = (unsigned char) i;
    testarray[i].int_value = i + 1;
  }

  // we read some of the values to calculate a result
  double result = 0.0;
  for (int j = 0; j < 50000; j++)
    for (long i = NR_ELEMENTS; i > 0; i = i - 2) {
      result += testarray[i].double_value + testarray[i].character + testarray[i].int_value + testarray[i].long_value;
    }

  cout << "Nonsense value: " << result << endl;
  */

}



int main() {

  double startTime = clock();

  bool le = isLittleEndian();

  cout << endl << "isLittleEndian: " << (le ? "true" : "false") << endl;

  doAlignmentExperiment();

  double stopTime = clock();
  double duration = (stopTime - startTime) / CLOCKS_PER_SEC;

  // format the output to 3 digits precision
  std::stringstream output;
  output.setf(ios::fixed);
  output.precision(3);
  output << duration;

  cout << "Experiment took " << output.str() << " seconds." << endl;

  return 0;
}