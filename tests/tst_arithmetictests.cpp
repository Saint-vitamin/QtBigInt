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
    void arithmeticAssignmentAdditionTest();
    void arithmeticAssignmentSubtractionTest();
    void arithmeticAssignmentMultiplicationTest();
    void arithmeticAssignmentDivisionTest();
    void arithmeticAssignmentModuloTest();

    // Binary arithmetic operations on BigInts with integers, strings and BigInts
    void binaryArithmeticWithIntStrBigTest();

    // Binary arithmetic operations with zeroes
    void binaryArithmeticWith0Test();

    // Chaining addition and subtraction
    void binaryArithmeticAddSubTest();

    // Chaining multiplication, division and modulo
    void binaryArithmeticDivModTest();

    // Addition of big numbers
    void binaryArithmeticBigTest();

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

    // inversion
    BigInt num21(1.0);
    QVERIFY(num21 != 0);

    BigInt num31("1");
    QVERIFY(num31 != 0);

    BigInt num41(num31);
    QVERIFY(num41 != 0);

    BigInt num51(1.0);
    QVERIFY(num51 != 0);

}

void arithmetictests::arithmeticAssignmentAdditionTest() {
    BigInt num1, num2, num3;
    num1 = "85241964353410";
    num2 = "617705612502427";
    num3 += num1;
    QVERIFY(num3 == "85241964353410");
    num3 += num2;
    QVERIFY(num3 == "702947576855837");
    num3 += num1 + num2;
    QVERIFY(num3 == "1405895153711674");
    num3 += 0;
    QVERIFY(num3 == "1405895153711674");
    num3 += 1234567890;
    QVERIFY(num3 == "1405896388279564");
    num3 += "12345678909876543210";
    QVERIFY(num3 == "12347084806264822774");


}

void arithmetictests::arithmeticAssignmentSubtractionTest() {
    BigInt num1, num2, num3;
    num1 = "169523540030343";
    num2 = "849991085752380";
    num3 -= num1;
    QVERIFY(num3 == "-169523540030343");
    num3 -= num2;
    QVERIFY(num3 == "-1019514625782723");
    num3 -= -(num1 + num2);
    QVERIFY(num3 == 0);
    num3 -= 0;
    QVERIFY(num3 == 0);
    num3 -= 1234567890;
    QVERIFY(num3 == -1234567890);
    num3 -= "12345678909876543210";
    QVERIFY(num3 == "-12345678911111111100");
}

void arithmetictests::arithmeticAssignmentMultiplicationTest() {
    BigInt num1, num2, num3;
    num1 = "169523540030343";
    num2 = "849991085752380";
    num3 = 1;

    num3 *= num1;
    QVERIFY(num3 == "169523540030343");
    num3 *= num2;
    QVERIFY(num3 == "144093497850978300540184466340");
    num3 *= num1 * num2;
    QVERIFY(num3 == "20762936122929888116068405550279299956640101675030592995600");
    num3 *= 0;
    QVERIFY(num3 == 0);

    num3 = 1;
    num3 *= -1234567890;
    QVERIFY(num3 == -1234567890);
    num3 *= "-12345678909876543210";
    QVERIFY(num3 == "15241578762383784111263526900");
}

void arithmetictests::arithmeticAssignmentDivisionTest() {
    BigInt num1, num2, num3;
    num1 = "1695235400303";
    num2 = "-14409349785097830054018446630";
    num3 = "99609344092229394637577667754049630552571016118837570372569130682";

    num3 /= num1;
    QVERIFY(num3 == "58758414362055909808086078831411583704925762083687648");

    num3 /= num2;

    QVERIFY(num3 == "-4077797765921675738706461");
    num3 /= num2 / num1;
    QVERIFY(num3 == 479745944);
    num3 /= num1;
    QVERIFY(num3 == 0);

    num3 = "15241578762383784111263526900";
    num3 /= -1234567890;
    QVERIFY(num3 == "-12345678909876543210");
    num3 /= "-12345678909876543210";
    QVERIFY(num3 == 1);
}

void arithmetictests::arithmeticAssignmentModuloTest() {
    BigInt num1, num2, num3;
    num1 = "82548281880706855287";
    num2 = "-3093004007127403784763865131496495744552";
    num3 = "28759936859007420850030703143893813386234625466713870488148000919";

    num3 %= num2;
    QVERIFY(num3 == "2998899812449910677529571999817489505831");

    num2 %= num1;
    QVERIFY(num2 == "-23415035301048583249");
    num3 %= num1;
    QVERIFY(num3 == "66666005575090474406");
    num1 %= num3;
    QVERIFY(num1 == "15882276305616380881");
    num2 %= num1;
    QVERIFY(num2 == "-7532758995432202368");

    num3 = "459084894176556768517930341954189452458611284176831884451259";
    num3 %= -1032535817;
    QVERIFY(num3 == 192792682);

    num3 = "459084894176556768517930341954189452458611284176831884451259";
    num3 %= "7930435512290528311470664857140269665";
    QVERIFY(num3 == "4828359958287405771596693425686847994");
}

void arithmetictests::binaryArithmeticWithIntStrBigTest() {
    const long long FLOOR_SQRT_LLONG_MAX = 3037000499;

    std::random_device generator;
    // uniform distribution of numbers from -3037000499 to 3037000499:
    std::uniform_int_distribution<long long> distribution((-FLOOR_SQRT_LLONG_MAX),
                                                          (FLOOR_SQRT_LLONG_MAX));
    for (size_t i = 0; i < 200; i++) {
        BigInt integer1 = distribution(generator);
        BigInt integer2 = distribution(generator);
        if (integer1 == 0 or integer2 == 0) {   // prevent division by zero
            i--;
            continue;
        }

        BigInt big_int1 = integer1;
        BigInt big_int2 = integer2;
        std::string integer2_str = integer2.getString();

        // addition:
        BigInt sum = integer1 + integer2;
        QVERIFY(big_int1 + big_int2     == sum);
        QVERIFY(big_int1 + integer2     == sum);
        QVERIFY(big_int1 + integer2_str == sum);
        QVERIFY(big_int2     + big_int1 == sum);
        QVERIFY(integer2     + big_int1 == sum);
        QVERIFY(integer2_str + big_int1 == sum);

        // subtraction:
        BigInt difference = integer1 - integer2;
        QVERIFY(big_int1 - big_int2     == difference);
        QVERIFY(big_int1 - integer2     == difference);
        QVERIFY(big_int1 - integer2_str == difference);
        QVERIFY(big_int2     - big_int1 == -difference);
        QVERIFY(integer2     - big_int1 == -difference);
        QVERIFY(integer2_str - big_int1 == -difference);

        // multiplication:
        BigInt product = integer1 * integer2;
        QVERIFY(big_int1 * big_int2     == product);
        QVERIFY(big_int1 * integer2     == product);
        QVERIFY(big_int1 * integer2_str == product);
        QVERIFY(big_int2     * big_int1 == product);
        QVERIFY(integer2     * big_int1 == product);
        QVERIFY(integer2_str * big_int1 == product);

        // division:
        BigInt quotient = integer1 / integer2;
        BigInt quotient_reciprocal = integer2 / integer1;
        QVERIFY(big_int1 / big_int2     == quotient);
        QVERIFY(big_int1 / integer2     == quotient);
        QVERIFY(big_int1 / integer2_str == quotient);
        QVERIFY(big_int2     / big_int1 == quotient_reciprocal);
        QVERIFY(integer2     / big_int1 == quotient_reciprocal);
        QVERIFY(integer2_str / big_int1 == quotient_reciprocal);

        // modulo:
        BigInt remainder = integer1 % integer2;
        BigInt remainder_reciprocal = integer2 % integer1;
        QVERIFY(big_int1 % big_int2     == remainder);
        QVERIFY(big_int1 % integer2     == remainder);
        QVERIFY(big_int1 % integer2_str == remainder);
        QVERIFY(big_int2     % big_int1 == remainder_reciprocal);
        QVERIFY(integer2     % big_int1 == remainder_reciprocal);
        QVERIFY(integer2_str % big_int1 == remainder_reciprocal);
    }
}

void arithmetictests::binaryArithmeticWith0Test() {
    BigInt num;
    num = "1234567890123456789012345678901234567890";

    QVERIFY(num + 0 == num);
    QVERIFY(num - 0 == num);
    QVERIFY(num * 0 == 0);

    QVERIFY(0 + num ==  num);
    QVERIFY(0 - num == -num);
    QVERIFY(0 * num == 0);
    QVERIFY(0 / num == 0);
    QVERIFY(0 % num == 0);
}

void arithmetictests::binaryArithmeticAddSubTest() {
    BigInt num1 = 1234;
    BigInt num2 = 56789;
    BigInt num3 = 101112;
    BigInt num4 = 13141516;
    QVERIFY(num1 + num2 + num3 + num4 == 13300651);
    QVERIFY(num1 - num2 + num3 + num4 == 13187073);
    QVERIFY(num1 + num2 - num3 + num4 == 13098427);
    QVERIFY(num1 + num2 + num3 - num4 == -12982381);
    QVERIFY(num1 - num2 - num3 + num4 == 12984849);
    QVERIFY(num1 - num2 + num3 - num4 == -13095959);
    QVERIFY(num1 + num2 - num3 - num4 == -13184605);
    QVERIFY(num1 - num2 - num3 - num4 == -13298183);
}

void arithmetictests::binaryArithmeticDivModTest() {
    BigInt num1 = static_cast<unsigned long long>(313233343536373839);
    BigInt num2 = static_cast<unsigned long long>(212223242526272829);
    BigInt num3 = static_cast<unsigned long long>(111213141516171819);
    BigInt num4 = static_cast<unsigned long long>(12345678910);

    QVERIFY(num1 * num2 / num3 % num4 == BigInt(static_cast<unsigned long long>(9021418300)));
    QVERIFY(num1 * num2 % num3 / num4 == BigInt(static_cast<unsigned long long>(6392448)));
    QVERIFY(num1 / num2 * num3 % num4 == BigInt(static_cast<unsigned long long>(6635659579)));
    QVERIFY(num1 / num2 % num3 * num4 == BigInt(static_cast<unsigned long long>(12345678910)));
    QVERIFY(num1 % num2 * num3 / num4 == "909925710857417206643517");
    QVERIFY(num1 % num2 / num3 * num4 == 0);
}

void arithmetictests::binaryArithmeticBigTest() {
    BigInt num1, num2;
        num1 = "964793941351798875130890128898086485681241334814868066116469822595"
               "687598448053045508928021048387109439448430241206886222949385913536"
               "17836411623804682393334501579397617644828334316728238955353058394264";
        num2 = "542060529704217132357214772959828385120983424339263541090375634996"
               "368065850294867611447397165152437998796443501783597014569840671683"
               "13210331303669787440432347511637996556242776045622241233979589718916";
        QVERIFY(num1 + num2 == "15068544710560160074881049018579148708022247591541"
                "31607206845457592055664298347913120375418213539547438244873742990"
                "48323751922658521931046742927474469833766849091035614201071110362"
                "350480189332648113180");

        num1 = "-19456862453160453307638071783433388649631926064367472120354136295"
               "908610671862754051755238831363430525061125138089083649263206899106"
               "180343851589754547911836910916517013121829987691413708752682939530093";
        num2 = "816553076977620349766958416466042124954414412870431261355772588173"
               "273756816453377871361812881641294479548961786166170884010949495342"
               "27956257833623792756494659469534082561332606937935191051654689548416";
        QVERIFY(num1 + num2 == "62198445244601581669057769863170823845809515222675"
                "65401522312252141876500978258373538094245680069892289377104052753"
                "34391378880504280476124062438692448446577485530170694395026192465"
                "21482298971750018323");

        num1 = "239051672644169719606760847726448849722952349353674737803305086175"
               "964897566266679588060951437665097321115985305673099530769568871522"
               "45499107716567135414777307777041355408432721268223982670393229830408";
        num2 = "-45388635689554372889456021208799010297399750799135284700297465410"
               "290594446637518031367847208953611686547054464297776583106699748315"
               "71906644184297446268805816895836929754710634789080915280425559423001";
        QVERIFY(num1 + num2 == "19366303695461534671730482651764983942555259855453"
                "94531030076207656743031196291615566931042287114856345689308413753"
                "22947662869123206735924635322696891459714908812044256537220864791"
                "43067389967670407407");

        std::string sum;
        num1 = BigInt::bigPow10(1525);
        num2 = BigInt::bigPow10(2750);
        sum = "1" + std::string(2750 - 1525 - 1, '0') + "1" + std::string(1525, '0');
        QVERIFY(num1 + num2 == sum);

        num1 = BigInt::bigPow10(3875);
        num2 = -BigInt::bigPow10(5490);
        sum = "-" + std::string(5490 - 3875, '9') + std::string(3875, '0');
        QVERIFY(num1 + num2 == sum);

        num1 = BigInt::bigPow10(19876);
        num2 = BigInt::bigPow10(23450);
        sum = "1" + std::string(23450 - 19876 - 1, '0') + "1" + std::string(19876, '0');
        QVERIFY(num1 + num2 == sum);
}


QTEST_APPLESS_MAIN(arithmetictests)

#include "tst_arithmetictests.moc"
