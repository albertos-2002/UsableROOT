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
  
  //function to get data
  std::map< int, std::vector<double> >* GetData();
  std::vector<double>* GetDataColumn( int index );
  
  
  private:
  
  //function to read data
  void ReadThatShit();
  
  //function to store data
  void StoreThatShit();

  int RowToSkip;
  int Column;
  std::string FileName
  
  std::string LineToDiscard;
  std::string LineToKeep;
  std::string LineToVector;
  
  std::vector<double> PlaceHolder;
  std::map< int, std::vector<double> > MapOfData;

};

#endif 
