#include "IncludeAllMyClass.h"
#include "IncludeAllCPP.h"
#include "IncludeAllROOT.h"
using namespace std;

RootObject::RootObject(){
}

RootObject::~RootObject(){
}

//function for the retrive of maps objects
static TFile* RootObject::getFile( string key ){
    
    if (FileMap.count(key) > 0) {
      return FileMap.at(key);
    }
    else{
      FileMap[key];
      return FileMap.at(key);
    }
    
}
  
static TGraph* RootObject::getGraph( string key ){
  
  if (GraphMap.count(key) > 0) {
      return GraphMap.at(key);
    }
    else{
      GraphMap[key];
      return GraphMap.at(key);
    }
  
}

static TGraphError* RootObject::getGraphError( string key ){
  
  if (GraphErrorMap.count(key) > 0) {
      return GraphErrorMap.at(key);
    }
    else{
      GraphErrorMap[key];
      return GraphErrorMap.at(key);
    }
  
}
  
static TMultiGraph* RootObject::getMultiGraph( string key ){
  
  if (MultiGraphMap.count(key) > 0) {
      return MultiGraphMap.at(key);
    }
    else{
      MultiGraphMap[key];
      return MultiGraphMap.at(key);
    }
  
}
  
static TH1F* RootObject::getH1F( string key ){
  
  if (H1FMap.count(key) > 0) {
      return H1FMap.at(key);
    }
    else{
      H1FMap[key];
      return H1FMap.at(key);
    }
  
}
  
static TH2F* RootObject::getH2F( string key ){
  
  if (H2FMap.count(key) > 0) {
      return H2FMap.at(key);
    }
    else{
      H2FMap[key];
      return H2FMap.at(key);
    }
  
}
  
//static TH1D*        RootObject::getH2F( string key ){}
//static TH2D*        RootObject::getH2D( string key ){}
  
static TF1* RootObject::getF1( string key ){
  
  if (TF1Map.count(key) > 0) {
      return TF1Map.at(key);
    }
    else{
      TF1Map[key];
      return TF1Map.at(key);
    }
  
}

