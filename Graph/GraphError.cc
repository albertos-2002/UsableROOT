#include "IncludeAllMyClass.h"
#include "IncludeAllCPP.h"
#include "IncludeAllROOT.h"
using namespace std;

GraphError::GraphError() : Singleton<GraphError>() {
}

GraphError::~GraphError(){
}

template <typename T>
void makeGraph( std::string key, std::string title, std::string xtitle, std::string ytitle, vector<T> datax, vector<T> datay ){

  //retrive object by key
  auto ObjPtr = RootObject::getGraphError(key);
  
  //setting initial parameters
  ObjPtr -> SetTitle( title.c_str() );
  ObjPtr -> GetXaxis() -> SetTitle( xtitle.c_str() );
  ObjPtr -> GetYaxis() -> SetTitle( ytitle.c_str() );
