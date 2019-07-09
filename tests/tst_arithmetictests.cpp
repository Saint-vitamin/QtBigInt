#include <QtTest>
#include <bigint.h>

// add necessary includes here

class arithmetictests : public QObject
{
    Q_OBJECT

public:
    arithmetictests();
    ~arithmetictests();

private slots:
    void operatorsTest();
    void constructorsTest();

};

arithmetictests::arithmetictests() {

}

arithmetictests::~arithmetictests() {

}

void arithmetictests::constructorsTest() {
    BigInt num1;        // should be 0 by default
    QVERIFY(num1 == 0);

    BigInt num2(0);     // 0 passed as an integer
    QVERIFY(num2 == 0);

    BigInt num3("0");   // 0 passed as a string
    QVERIFY(num3 == 0);

    BigInt num4(num3);  // object with value 0 passed to copy constructor
    QVERIFY(num4 == 0);

    BigInt num5(0.0);  // object with value 0 passed to copy constructor
    QVERIFY(num5 == 0);


    BigInt num21(1);     // 0 passed as an integer
    auto txt = num21.getString(10);
    QVERIFY(num2 != 0);

    BigInt num31("0.1");   // 0 passed as a string
    QVERIFY(num3 != 0);

    BigInt num41(num3);  // object with value 0 passed to copy constructor
    QVERIFY(num4 != 0);

    BigInt num51(0.1);  // object with value 0 passed to copy constructor
    QVERIFY(num5 != 0);

}

void arithmetictests::operatorsTest() {

}


QTEST_APPLESS_MAIN(arithmetictests)

#include "tst_arithmetictests.moc"
