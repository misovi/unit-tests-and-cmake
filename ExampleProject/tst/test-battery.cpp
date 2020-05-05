#include "gtest/gtest.h"
#include "Date.h"
#include <string>

TEST(attributeTest, defaultValues)
{
    Date d;
    EXPECT_EQ (d.get_year(),  1900);
    EXPECT_EQ(d.get_day(),1);
    EXPECT_EQ(d.get_month(),1);
}

TEST(attributeTest, validValues)
{
    Date d(26,7,1993);
    EXPECT_EQ (d.get_year(),  1993);
    EXPECT_EQ(d.get_day(),26);
    EXPECT_EQ(d.get_month(),7);
}

TEST(attributeTest, invalidValues)
{
    Date d(31,2,2), d2(-133,-200,-3000);
    EXPECT_EQ (d.get_year(),  2);
    EXPECT_EQ(d.get_day(),31);
    EXPECT_EQ(d.get_month(),2);

    EXPECT_EQ (d2.get_year(),-3000);
    EXPECT_EQ(d2.get_day(),-133);
    EXPECT_EQ(d2.get_month(),-200);
}

TEST(nextDayTest, sameMonth)
{
  using namespace std;
  Date d1(1,1,2013);
  Date d2(2,2,2013);
  Date d3(3,3,2013);
  d1.next_day();
  d2.next_day();
  d3.next_day();
  EXPECT_EQ(d1.get_day(),2);
  EXPECT_EQ(d1.get_month(),1);
  EXPECT_EQ(d1.get_year(),2013);
  EXPECT_EQ(d2.get_day(),3);
  EXPECT_EQ(d2.get_month(),2);
  EXPECT_EQ(d2.get_year(),2013);
  EXPECT_EQ(d3.get_day(),4);
  EXPECT_EQ(d3.get_month(),3);
  EXPECT_EQ(d3.get_year(),2013);
}

TEST(nextDayTest, differentMonthAndLeapYear)
{
  Date d1(31,1,2000);
  Date d2(30,4,2000);
  Date d3(28,2,2000);
  Date d4(29,2,2000);
  d1.next_day();
  d2.next_day();
  d3.next_day();
  d4.next_day();
  EXPECT_EQ(d1.get_day(),1);
  EXPECT_EQ(d1.get_month(),2);
  EXPECT_EQ(d1.get_year(),2000);
  EXPECT_EQ(d2.get_day(),1);
  EXPECT_EQ(d2.get_month(),5);
  EXPECT_EQ(d2.get_year(),2000);
  EXPECT_EQ(d3.get_day(),29);
  EXPECT_EQ(d3.get_month(),2);
  EXPECT_EQ(d3.get_year(),2000);
  EXPECT_EQ(d4.get_day(),1);
  EXPECT_EQ(d4.get_month(),3);
  EXPECT_EQ(d4.get_year(),2000);
}

TEST(nextDayTest, nextYear)
{
  Date d(31,12,2008);
  d.next_day();
  EXPECT_EQ(d.get_day(),1);
  EXPECT_EQ(d.get_month(),1);
  EXPECT_EQ(d.get_year(),2009);
}

TEST(daysBetweenTest, simple)
{
  Date a(1,1,2020);
  Date b(2,1,2020);
  int result = a.days_between(b);
  EXPECT_EQ(result,1);
}

TEST(daysBetweenTest, longTime)
{
  Date a;
  Date b(5,5,2020);
  int result = a.days_between(b);
  int exp = 43954;
  EXPECT_EQ(result,exp);
}

TEST(daysBetweenTest, longTimeReverse)
{
  Date a;
  Date b(5,5,2020);
  int result = b.days_between(a);
  int exp = 43954;
  EXPECT_EQ(result,exp);
}

TEST(daysBetweenTest, sameDate)
{
  Date a;
  Date b;
  int result = b.days_between(a);
  int exp = 0;
  EXPECT_EQ(result,exp);
}

TEST(sinceNewYearTest, simple)
{
  Date d(2,1,2020);
  int result = d.days_since_newyear();
  int exp = 1;
  EXPECT_EQ(exp,result);
}

TEST(sinceNewYearTest, longer)
{
  Date d(5,5,2020);
  int result = d.days_since_newyear();
  int exp = 125;
  EXPECT_EQ(exp,result);
}
