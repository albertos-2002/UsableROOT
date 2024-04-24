#include "IncludeAllCPP.h"
#include "IncludeAllROOT.h"
using namespace std;

//constructor: assegnazione parametri
CSVReader::CSVReader(const std::string FileName_c, int Column_c, int RowToSkip_c = 0){
  RowToSkip = RowToSkip_c;
  Column = Column_c;
  FileName = FileName_c
  
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
       /*vector name*/.push_back( stod(LineToVector) );
       LineToVector.clear();
      }
      else{
        cout << "cannot read data (sad moth stiker)" << endl; 
      }
    
    }
  
  }

}
  
  

  
  //reading of lines

  
    
      
    
    //second column
    if( getline(StringToStream, LineToVector2, ',') ){
      tmpDataStorage = 0;
      tmpDataStorage = stof(LineToVector2);
      PointPosition.push_back(tmpDataStorage);
    }
    else{
      cout << "why the fuck i can't read evend the data that i do not need " << endl;
    }
    
    //second column
    
    
  }

}
