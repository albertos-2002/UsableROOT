#ifndef Graph_h
#define Graph_h

#include "IncludeAllCPP.h"
#include "IncludeAllROOT.h"

class RootObject;

class Graph : public Singleton<Graph> {

  public:
  
  template <typename T>
  void makeGraph( std::string key, std::string title, std::string xtitle, std::string ytitle, std::vector<T>& dataX, std::vector<T>& dataY );
  
  double getCorrelation( std::string key );
  
  private:
  
  //constructor
  Graph();
  
  //destructor
  ~Graph();
  
  //copy and assignment constructor
  Graph           ( const Graph& obj ) = delete;
  Graph& operator=( const Graph& obj ) = delete;
  
  template <typename T> 
  void checkNumberPoints( std::vector<T>& dataX, std::vector<T>& dataY );


};

#endif
