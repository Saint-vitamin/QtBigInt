#include <QtTest>

// add necessary includes here

class arithmetictests : public QObject
{
    Q_OBJECT

public:
    arithmetictests();
    ~arithmetictests();

private slots:
    void test_case1();

};

arithmetictests::arithmetictests()
{

}

arithmetictests::~arithmetictests()
{

}

void arithmetictests::test_case1()
{

}

QTEST_APPLESS_MAIN(arithmetictests)

#include "tst_arithmetictests.moc"
