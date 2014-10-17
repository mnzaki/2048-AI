#ifndef __STRATEGIES_HPP__
#define __STRATEGIES_HPP__

#include "search.hpp"
#include <deque>
#include <memory>

namespace Search {
  class BF : public GeneralSearch {
  private:
    void enqueue(std::shared_ptr<SearchNode>);
  };
  class DF : public GeneralSearch {
  private:
    void enqueue(std::shared_ptr<SearchNode>);
  };
  class ID : public GeneralSearch {
  private:
    unsigned limit, maxLimit;
    void enqueue(std::shared_ptr<SearchNode>);
  public:
    ID(unsigned _limit, unsigned _maxLimit)
      : limit(_limit), maxLimit(_maxLimit) { };
    ID() : limit(5), maxLimit(20) { };
  };
  class BFS : public GeneralSearch {
  public:
    std::deque<int> fvalues;
    virtual int f(SearchNode*) =0;
  private:
    void enqueue(std::shared_ptr<SearchNode>);
  };
};

#endif /* end of include guard: __STRATEGIES_HPP__ */
