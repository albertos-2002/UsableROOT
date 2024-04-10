#ifndef GraphError_h
#define GraphError_h

#include "IncludeAllCPP.h"
#include "IncludeAllROOT.h"

class RootObject;

class GraphError : public Singleton<GraphError> {

  public:
  
  template <typename T>
  void makeGraph( std::string key, std::string title, std::string xtitle, std::string ytitle, std::vector<T> datax, std::vector<T> datay );
  
  private:

  //constructor
  GraphError();
  
  //destructor
  ~GraphError();
  
  //copy and assignment constructor
  GraphError           ( const GraphError& obj ) = delete;
  GraphError& operator=( const GraphError& obj ) = delete;

};

#endif 
