#ifndef PRODCONSGOLDBACHCALCULATOR_HPP_
#define PRODCONSGOLDBACHCALCULATOR_HPP_
#include "Assembler.hpp"
#include "GoldbachWork.hpp"
#include <vector>
class GoldbachCalculator;
class GoldbachWebApp;
class ProdConsGoldbachCalculator: public Consumer<GoldbachWork>
  , public Producer<GoldbachWork> {
    DISABLE_COPY(ProdConsGoldbachCalculator);
    private:
    GoldbachCalculator *goldbachCalculator;
    GoldbachWebApp *goldbachWebApp;

    public:
    ProdConsGoldbachCalculator(Queue<GoldbachWork>* consumingQueue
    , Queue<GoldbachWork>* producingQueue
    , const GoldbachWork& stopCondition);


    void consume(const GoldbachWork& goldbachWork) override;

    int run() override;

    void setIntancePointers(GoldbachCalculator *goldbachCalculator,
                            GoldbachWebApp *goldbachWebApp);
};

#endif // PRODCONSGOLDBACHCALCULATOR_HPP_