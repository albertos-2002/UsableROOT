#include "IncludeAllMyClass.h"
#include "IncludeAllCPP.h"
#include "IncludeAllROOT.h"
using namespace std;

Graph::Graph() : Singleton<Graph>() {
}

Graph::~Graph(){
}

template <typename T>
void Graph::makeGraph( std::string key, std::string title, std::string xtitle, std::string ytitle, vector<T>& dataX, vector<T>& dataY ){

  checkNumberPoints( dataX, dataY );

  //retrive object by key
  auto ObjPtr = RootObject::getGraph(key);
  unsigned int NumberOfPoints = dataX.size();
  
  //setting initial parameters
  ObjPtr -> SetTitle( title.c_str() );
  ObjPtr -> GetXaxis() -> SetTitle( xtitle.c_str() );
  ObjPtr -> GetYaxis() -> SetTitle( ytitle.c_str() );
  ObjPtr -> Set(NumberOfPoints);
  ObjPtr -> SetEditable(kFalse)
  
  for (int i = 0; i < NumberOfPoints; i++ ){
    ObjPtr -> AddPoint( dataX.at(i), dataY.at(i) );
  }

}

double getCorrelation( string key){  //approfondire
  auto ObjPtr = RootObject::getGraph(key);
  if( ObjPtr -> GetN() = 0 ){
    cout << "Graph " << key << " is empty" << endl;
    return;
  }
  else{
    return ObjPtr -> GetCorrelationFactor();
  }

}

//-------------------------------------------------------------------------------------------------------------------------------------------------------------

template <typename T> 
void Graph::checkNumberPoints( vector<T>& dataX, vector<T>& dataY ){

  unsigned int SizeOfX = dataX.size();
  unsigned int SizeOfY = dataY.size();
  
  if ( SizeOfX != SizeOfY ) {  
    cout << "#points for graph ... differ in X, Y" << endl; 
    return;
  }

}
