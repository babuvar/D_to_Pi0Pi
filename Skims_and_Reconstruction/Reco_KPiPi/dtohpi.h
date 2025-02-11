// -*- C++ -*-
//

#include "belle.h"
#include <iostream>
#include <string>
#include <iomanip>
#include <cmath>
#include <cstdio>
#include <cfloat>

#include "basf/module.h"
#include "particle/Particle.h"
#include "tuple/BelleTupleManager.h"
#if defined(BELLE_NAMESPACE)
namespace Belle {
#endif

class BelleEvent;
class BasfOutput;
class BelleHistogram;

class dtohpi: public Module {

public:

  dtohpi( void );
  ~dtohpi( void ) {};
  void init( int* );
  void term( void );
  void disp_stat( const char* );
  void hist_def( void );
  void event( BelleEvent*, int* );
  void begin_run( BelleEvent*, int* );
  void end_run( BelleEvent*, int* );
  void other( int*, BelleEvent*, int* );

void FillTuple_small_D(Particle& Dst_cand, BelleTuple *nt);



  void with_imp_cut(std::vector<Particle> &list);
  HepVector param_at_ip(Particle &p);

  /// Filename for output
  char m_SkimFileName[256];

private:
    int dataType;

  //Particle Types
  static const Ptype m_ptypeDP;
  static const Ptype m_ptypeDM;
  static const Ptype m_ptypeDstarP;
  static const Ptype m_ptypeDstarM;

  static const Ptype m_ptypeDsP;
  static const Ptype m_ptypeDsM;
  static const Ptype m_ptypeDs_starP;
  static const Ptype m_ptypeDs_starM;

  BasfOutput* m_SkimFile;

  // Event histograms
    BelleTuple *nt_dpipi_small ;


};



#if defined(BELLE_NAMESPACE)
} // namespace Belle
#endif
