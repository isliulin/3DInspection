#ifndef RANDOMNUM_HPP
#define RANDOMNUM_HPP

#include <cstdlib>

namespace SSDK
{
/**
     *  @brief RandomNum
     *         随机生成区间[min - max]的整数
     *         随机生成区间(min - max)的浮点数
     *  @author bob
     *  @version 1.00 2017-12-01 bob
     *                note:create it
     */
    class NumRandom
    {
    public:
        //>>>----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
        //构造 & 析构函数
        NumRandom();

        ~NumRandom();
        //<<<----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------

        //>>>----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
        //成员函数
        /*
        *  @brief  randomInt
        *          随机生成区间[min,max]区间的整数
        *  @param  max:随机数的最大值
        *          min:随机数的最小值
        *  @return 随机生成的值
        */
        int randomInt(int max ,int min);

        /*
        *  @brief  randomInt
        *          随机生成区间(min,max)区间的浮点数
        *  @param  max:随机数的最大值
        *          min:随机数的最小值
        *  @return 随机生成的double形浮点数
        */
        double randomDouble(double max ,double min);
        //<<<----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
    };
}   //End of namespace SSDK

#endif // RANDOMNUM_HPP
