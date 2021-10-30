#ifndef UTILITY_FUNCTIONS_HPP
#define UTILITY_FUNCTIONS_HPP
#include <array>
#include <map>
#include <ostream>
#include <utility>
#include <vector>

// returns a linearly spaced vector of n doubles from in to fin
std::vector<double> LinearRange(double in, double fin, std::size_t n) {
      std::vector<double> ret;
      if(n == 1) ret.push_back((in + fin)/2.); // midpoint if n == 1
      else if(n > 1) {
         const double step = (fin - in)/(n - 1);
         for(std::size_t k = 0; k != n; ++k) ret.push_back(in + k*step);
      }
      // empty if n == 0
      return ret;
}

// returns a vector of doubles from in up to (at most) fin spaced by step
// Warning: the final point is not guaranteed to be in the range, even if
// mathematically it would be so, because of machine error.
std::vector<double> StepRange(double in, double fin, double step) {
   std::vector<double> ret;
   if(in == fin) ret.push_back(in);
   else if(fin > in) {
      if(step > 0.) for(double x = in; x <= fin; x += step) ret.push_back(x);
   }
   else if (step < 0.)
         for (double x = in; x >= fin; x += step) ret.push_back(x);
   return ret;
}

// writes an std::array on an std::ostream
template<class T, std::size_t N> std::ostream& operator <<
   (std::ostream& o, const std::array<T,N>& a) {
      auto it = a.begin();
      o << '(';
      if(it != a.end()) {
         for(; it != a.end()-1; ++it) o << *it << ", ";
         o << *it;
      }
      return o << ')';
}

// writes an std::vector on an std::ostream
template<class T> std::ostream& operator <<
   (std::ostream& o, const std::vector<T>& v) {
      auto it = v.begin();
      o << '(';
      if(it != v.end()) {
         for(; it != v.end()-1; ++it) o << *it << ", ";
         o << *it;
      }
      return o << ')';
}

// writes an std::pair on an std::ostream
template<class T1, class T2> std::ostream& operator <<
   (std::ostream& o, const std::pair<T1,T2>& p) {
      return o << '(' << std::get<0>(p) << ", " << std::get<1>(p) << ')';
}

// writes an std::map on an std::ostream
template<class K, class T> std::ostream& operator <<
   (std::ostream& o, const std::map<K,T>& m) {
      o << "{ ";
      for(auto p : m) o << p << ' ';
      return o << '}';
}

// obtains the vector of keys from an std::map
template<class K, class V> std::vector<K> GetKeys(const std::map<K,V>& m) {
   std::vector<K> k;
   for (auto p : m) k.push_back(std::get<0>(p));
   return k;
}

// obtains the vector of values from an std::map
template<class K, class V> std::vector<V> GetValues(const std::map<K,V>& m) {
   std::vector<V> v;
   for (auto p : m) v.push_back(std::get<1>(p));
   return v;
}

#endif // UTILITY_FUNCTIONS_HPP




