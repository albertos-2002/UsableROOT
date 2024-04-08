#ifndef RootObject_h
#define RootObject_h

#include "IncludeAllCPP.h"
#include "IncludeAllROOT.h"

class RootObject(){

  public:
  
  //constructor
  RootObject();
  
  //destructor
  ~RootObject();
  
  //delete copy and assigment constructor
  RootObject           ( const RootObject& obj ) = delete;
  RootObject& operator=( const RootObject& obj ) = delete;
  
  //function for the retrive of maps objects
  static TFile*       getFile( std::string key );
  
  static TGraph*      getGraph( std::string key );
  static TGraphError* getGraphError( std::string key );
  static TMultiGraph* getMultiGraph( std::string key );
  
  static TH1F*        getH1F( std::string key );
  static TH2F*        getH2F( std::string key );
//static TH1D*        getH2F( std::string key );
//static TH2D*        getH2D( std::string key );
  
  static TF1*         getF1( std::string key );
  
  
  private;
  
  static std::map<std::string, TFile>       FileMap;
  
  static std::map<std::string, TGraph>      GraphMap;
  static std::map<std::string, TGraphError> GraphErrorMap;
  static std::map<std::string, TMultiGraph> MultiGraphMap;
  
  static std::map<std::string, TH1F>        H1FMap;
  static std::map<std::string, TH2F>        H2FMap;
//static std::map<std::string, TH1D>        H1DMap;
//static std::map<std::string, TH2D>        H2DMap;
  
  static std::map<std::string, TF1>         TF1Map;
  


};


#endif RootObject_h
