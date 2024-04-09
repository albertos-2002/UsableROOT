#include "IncludeAllMyClass.h"
#include "IncludeAllCPP.h"
#include "IncludeAllROOT.h"
using namespace std;

RootObject::RootObject(){
}

RootObject::~RootObject(){
}

//map implementatio ------------------------------------------------------
map<string, TFile*>        RootObject::FileMap;
  
map<string, TGraph*>       RootObject::GraphMap;
map<string, TGraphErrors*> RootObject::GraphErrorMap;
map<string, TMultiGraph*>  RootObject::MultiGraphMap;
  
map<string, TH1F*>         RootObject::H1FMap;
map<string, TH2F*>         RootObject::H2FMap;
//map<string, TH1D*>         RootObject::H1DMap;
//map<string, TH2D*>         RootObject::H2DMap;
  
map<string, TF1*>          RootObject::TF1Map;

//------------------------------------------------------------------------

//function for the retrive of maps objects
TFile* RootObject::getFile( const string key ){
    
    if (FileMap.count(key) > 0) {
      return FileMap.at(key);
    }
    else{
      string FullFileName = key+".root";
      FileMap[key] = new TFile(FullFileName.c_str(), "CREATE");
      return FileMap.at(key);
    }
}
  
TGraph* RootObject::getGraph( const string key ){
  
  if (GraphMap.count(key) > 0) {
      return GraphMap.at(key);
    }
    else{
      GraphMap[key] = new TGraph();
      GraphMap.at(key) -> SetName( key.c_str() );
      return GraphMap.at(key);
    }  
}

TGraphErrors* RootObject::getGraphError( const string key ){
  
  if (GraphErrorMap.count(key) > 0) {
      return GraphErrorMap.at(key);
    }
    else{
      GraphErrorMap[key] = new TGraphErrors();
      GraphErrorMap.at(key) -> SetName( key.c_str() );
      return GraphErrorMap.at(key);
    }
  
}
  
TMultiGraph* RootObject::getMultiGraph( const string key ){
  
  if (MultiGraphMap.count(key) > 0) {
      return MultiGraphMap.at(key);
    }
    else{
      MultiGraphMap[key] = new TMultiGraph();
      MultiGraphMap.at(key) -> SetName(key.c_str());
      return MultiGraphMap.at(key);
    }
  
}
  
TH1F* RootObject::getH1F( string key ){
  
  if (H1FMap.count(key) > 0) {
      return H1FMap.at(key);
    }
    else{
      H1FMap[key] = new TH1F();
      H1FMap.at(key) -> SetName(key.c_str());
      return H1FMap.at(key);
    }
  
}
  
TH2F* RootObject::getH2F( string key ){
  
  if (H2FMap.count(key) > 0) {
      return H2FMap.at(key);
    }
    else{
      H2FMap[key] = new TH2F();
      H2FMap.at(key) -> SetName(key.c_str());
      return H2FMap.at(key);
    }
  
}
  
//TH1D*        RootObject::getH2F( string key ){}
//TH2D*        RootObject::getH2D( string key ){}
  
//adapt for building a function with parameter
TF1* RootObject::getF1( string key ){
  
  if (TF1Map.count(key) > 0) {
      return TF1Map.at(key);
    }
    else{
      TF1Map[key] = new TF1();
      TF1Map.at(key) -> SetName(key.c_str());
      return TF1Map.at(key);
    }
  
}
