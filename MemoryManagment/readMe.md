[Home](../README.md)

# Memory managment

---

## Class RootObject

La classe è costituita da elementi static

Le seguenti `std::map` per la conservazione degli oggetti

(vengono riportate solo le implementazioni)

```cpp
map<string, TFile*>        FileMap;
  
map<string, TGraph*>       GraphMap;
map<string, TGraphErrors*> GraphErrorMap;
map<string, TMultiGraph*>  MultiGraphMap;
  
map<string, TH1F*>         H1FMap;
map<string, TH2F*>         H2FMap;
  
map<string, TF1*>          TF1Map;
```

e le corrispondenti funzioni (static) per fare il retrive degli oggetti tramite key

```cpp
TFile*        getFile( std::string key );
  
TGraph*       getGraph( std::string key );
TGraphErrors* getGraphError( std::string key );
TMultiGraph*  getMultiGraph( std::string key );
  
TH1F*         getH1F( std::string key );
TH2F*         getH2F( std::string key );
  
TF1*          getF1( std::string key );
```

Esmepio di implementazione

```cpp
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
```

La funzione controlla se una key è già presente, in caso contrario crea l'oggetto con `new`, fa il set del nome ( = key) e lo ritorna

---

