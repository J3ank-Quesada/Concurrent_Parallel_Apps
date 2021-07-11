#ifndef PRODCONSGOLDBACHCALCULATOR_HPP_
#define PRODCONSGOLDBACHCALCULATOR_HPP_
#include "GoldbachWork.hpp"
#include <vector>
#include "Consumer.hpp"
class GoldbachWebApp;
class ProdConsGoldbachCalculator: public Consumer<GoldbachWork>{
    DISABLE_COPY(ProdConsGoldbachCalculator);
    private:
    GoldbachWebApp *goldbachWebApp;

    public:
    ProdConsGoldbachCalculator(Queue<GoldbachWork>* consumingQueue
    , const GoldbachWork& stopCondition, GoldbachWebApp *goldbachWebApp);


    void consume(const GoldbachWork& goldbachWork) override;

    int run() override;

};

#endif // PRODCONSGOLDBACHCALCULATOR_HPP_