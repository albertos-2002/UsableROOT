#ifndef CSVReader_h
#define CSVReader_h

#include "IncludeAllCPP.h"
#include "IncludeAllROOT.h"

/*
Vengono solo passati i parametri delle righe da skippare e le colonne
il separatore viene automaticamente settato sulla virgola (CSV)
se necessario passare direttamente l'intero path come argomento del FileName
di default il numero di righe da saltare è 0
*/

class CSVReader {

  public:
  
  CSVReader( const std::string FileName_c, int Column_c, int RowToSkip_c = 0);
  
  ~CSVReader();
  
  //delete copy and assigment constructor
  CSVReader           ( const CSVReader& obj ) = delete;
  CSVReader& operator=( const CSVReader& obj ) = delete;
  
  //function to read data
  void ReadThatShit();
  
  private:

  int RowToSkip;
  int Column;
  std::string FileName
  
  std::string LineToDiscard;
  std::string LineToKeep;
  std::string LineToVector;

};

#endif CSVReader_h
