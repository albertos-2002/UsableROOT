#include "IncludeAllCPP.h"
#include "IncludeAllROOT.h"
using namespace std;

//constructor: assegnazione parametri
CSVReader::CSVReader(const std::string FileName_c, int Column_c, int RowToSkip_c = 0){
  RowToSkip = RowToSkip_c;
  Column = Column_c;
  FileName = FileName_c
  
  //PlaceHolder.reserve();
  
  ReadThatShit();
}
  
//destructor  
CSVReader::~CSVReader() {
}

void CSVReader::ReadThatShit(){

  //file opening
  ifstream CSVFile_in (FileName);
  if ( !CSVFile_in.is_open() ) {
    cout << "the fooking file (" 
         << FileName 
         << ") is not opening !!! " 
         << endl;
  }
  
  cout << "reading file .....  " << endl;
  
  //discard of lines
  for (int i=0; i < RowToSkip; i++){
      getline( CSVFile_in, LineToDiscard );
      LineToDiscard.clear();
  
  }
  
  //reading of lines
  while ( getline( CSVFile_in, LineToKeep ) ){
    //extraction of a line
    istringstream StringToStream( LineToKeep );
    
    //extraction of values in columns
    for(int i=0; i < Column; i++ ){
    
      if( getline( StringToStream, LineToVector, ',' ) ){
       PlaceHolder.push_back( stod(LineToVector) );
       LineToVector.clear();
      }
      else{
        cout << "cannot read data (sad moth stiker)" << endl; 
      }
    
    }
  
  }
  
  StoreThatShit();
  
  return;
}
  
void CSVReader::StoreThatShit(){

  //creation of vectors in map
  for (int i=1; i <= Column; i++){
    MapOfData[i] = new vector<double>;
  }
  
  //filling of the map
  int j = 0;
  int k = 0;
  
  for (int i=1; i <= Column; i++){
  
    auto tmpVector = MapOfData.at(i);
    j=k;
    
    while( j < PlaceHolder.size(); ){
      
      tmpVector.push_back( PlaceHolder.at(j) );
      j + Columns;
      
    }
  
    ++k;
    
  }

/*
Mettiamo all'interno della mappa un numero di vettori pari a quello delle colonne
scorriamo su ognuno di questi vettori (primo for)
  e lo conserviamo su una variabile temporanea
il ciclo while scorre sul vettore grande che contiene tutti i dati ed
  estrae solo quelli appartenenti ad un specidica colonna
  il numero di colonne viene mantenuto dall'indice k
*/

  return;
}

map< int, vector<double> >* CSVReader::GetData(){
  return &MapOfData;
}

vector<double>* CSVReader::GetDataColumn( int index ){
  return MapOfData.at(index);
}
