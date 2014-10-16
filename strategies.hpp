#ifndef __STRATEGIES_HPP__
#define __STRATEGIES_HPP__

#include "search.hpp"

namespace Search {
  class BF : private GeneralSearch {
  private:
    void enqueue(SearchNode*);
  };
  class DF : private GeneralSearch {
  private:
    void enqueue(SearchNode*);
  };
  class ID : private GeneralSearch {
  private:
    unsigned limit, maxLimit;
    void enqueue(SearchNode*);
  public:
    ID(unsigned _limit, unsigned _maxLimit)
      : limit(_limit), maxLimit(_maxLimit) { };
    ID() : limit(5), maxLimit(20) { };
  };
  class BFS : private GeneralSearch {
  private:
    virtual int f(State*) =0;
    void enqueue(SearchNode*);
  };
};

#endif /* end of include guard: __STRATEGIES_HPP__ */
