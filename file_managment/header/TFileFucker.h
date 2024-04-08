#ifndef TFileFucker_h
#define TFileFucker_h

/*
Estrazione dei dati da un file .root e trasferimento ad un vettore
*/

#include "IncludeAllCPP.h"
#include "IncludeAllROOT.h"


class TFileFucker final{

  public:
  
  //constructor
  TFileFucker();
  
  //destructor
  ~TFileFucker();

  //to delete copy and assigment constructor  

  private:

  //per decidere l'estrazione da un NTupla oppure da un TTree
  string object_to_extract;

}; 

#endif TFileFucker_h
