#pragma once
#include <spuce/filters/iir_coeff.h>
#include <spuce/filters/fir_coeff.h>

namespace spuce {

#include "des_filter.h"

enum fil_enum {
  None,
  Butterworth,
  Chebyshev,
  Elliptic
};

class make_filter {
  enum fil_type { low, high, band };

 public:
  double elliptic_fc;
  double butterworth_fc;
  double chebyshev_fc;
  double cut_stop_db;
  double cut_fc;
  double elliptic_halfband_ripple;
  double variable_ripple;
  double elliptic_pass_edge;
  double elliptic_stop_edge;
  double elliptic_trans;
  double elliptic_stop_db;
  double elliptic_ripple;
  double chebyshev_ripple;

  int elliptic_order;
  int butterworth_order;
  int chebyshev_order;

  int pts;
  double fs;
  std::string f_type;
	
  typedef double audio_data_type;

  fil_enum shape;
  fil_enum last_shape;
  fil_type pass_type;

  double horiz_swipe(int len, bool in_passband);
  double get_fc(int len, bool in_passband);
  int get_order();
  bool is_bpf();
  double ripple();
  double stopdB();
  double fcutoff();
  void vertical_swipe(int len, bool in_passband, bool above_stop);
  double update(double *w);
  double update(double *w, double w_inc);
  double get_mag(double w);

  void sel_filter(const char *sel);
  void change_filter(fil_enum f);
  double limit(double x, double mx, double min);

  make_filter();
  ~make_filter();
  void init(int points);
  void reset();
  void clear_filters();
  void set_filter_type(int h);
  void set_fs(double f);
};
}  // namespace spuce
